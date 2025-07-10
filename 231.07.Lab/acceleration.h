/***********************************************************************
 * Header File:
 *    ACCELERATION 
 * Author:
 *    Br. Helfrich, Greg Elbl, Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

//class TestAcceleration;
class TestVelocity;
class TestPosition;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{

public:
   friend TestPosition;
   friend TestVelocity;
   friend class TestAcceleration;
   friend class TestSatellite;
   friend class TestGPS;
   friend class TestHubble;
   friend class TestStarlink;
   friend class TestCrewDragon;
   friend class TestSputnik;
   friend class TestShip;
   friend class TestPart;
   friend class TestProjectile;
   
   // constructors
   Acceleration()                         : ddx(0.0), ddy(0.0)         {}
   Acceleration(const Acceleration & rhs) : ddx(rhs.ddx), ddy(rhs.ddy) {}
   Acceleration(double ddx, double ddy)   : ddx(ddx), ddy(ddy)         {}

   // getters
   double getDDX() const { return ddx; }
   double getDDY() const { return ddy; }

   // setters                        
   void setDDX(double ddx) { this->ddx = ddx; }
   void setDDY(double ddy) { this->ddy = ddy; }
   void set(const Angle & a, double magnitude);
   
   void addDDX(double ddx) { this->ddx += ddx; }
   void addDDY(double ddy) { this->ddy += ddy; }
   void add(const Acceleration& rhs)
   {
      ddx += rhs.getDDX();
      ddy += rhs.getDDY();
   }

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};
