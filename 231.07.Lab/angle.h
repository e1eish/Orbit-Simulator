/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich, Greg Elbl, Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

 // for the unit tests
class TestAngle;
class TestPosition;
class TestVelocity;
class TestAcceleration;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
public:
   // for the unit tests
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend class TestSatellite;
   friend class TestGPS;
   friend class TestHubble;
   friend class TestStarlink;
   friend class TestCrewDragon;
   friend class TestSputnik;
   friend class TestShip;
   friend class TestPart;
   friend class TestProjectile;

   // Constructors
   Angle()                  : radians(0.0)         {}
   Angle(const Angle& rhs)  : radians(rhs.radians)         {}
   Angle(double degrees)    { setDegrees(degrees); }
   // Getters
   double getDegrees() const { return (radians * 180.0) / M_PI; }
   double getRadians() const { return radians; }

   //         dx
   //    +-------/
   //    |      /
   // dy |     /
   //    |    / 1.0
   //    | a /
   //    |  /
   //    | /
   // dy = cos a
   // dx = sin a
   double getDx() const { return sin(radians); }
   double getDy() const { return cos(radians); }
   bool   isRight()          const { return 0.0 < radians && M_PI > radians; }
   bool   isLeft()           const { return M_PI < radians && (2 * M_PI) > radians; }


   // Setters
   void setDegrees(double degrees) { radians = normalize((degrees * M_PI) / 180.0); }
   void setRadians(double radians) { this->radians = normalize(radians); }
   void setUp()                    { radians = 0.0; }
   void setDown()                  { radians = M_PI; }
   void setRight()                 { radians = M_PI / 2.0; }
   void setLeft()                  { radians = (3 * M_PI) / 2.0; }
   void reverse()
   {
      // To ensure the angle is normalized, add or subtract pi (180 degrees) so that it stays within 0 and 2pi radians.
      if (radians <= M_PI)
         radians += M_PI;
      else
         radians -= M_PI;
      
      radians = normalize(radians);
   }
   Angle& add(double delta)
   {
      radians += delta;
      radians = normalize(radians);
      return *this;
   }

   // set based on the components
   //         dx
   //     +-------/
   //     |      /
   //  dy |     /
   //     |    /
   //     | a /
   //     |  /
   //     | /
   void setDxDy(double dx, double dy)  { radians = normalize(atan(dx / dy));}
   Angle operator+(double degrees) const { return Angle(); }

private:

   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};

#include <iostream>

/*******************************************************
 * OUTPUT ANGLE
 * place output on the screen in degrees
 *******************************************************/
inline std::ostream& operator << (std::ostream& out, const Angle& rhs)
{
   out << rhs.getDegrees() << "degree";
   return out;
}
