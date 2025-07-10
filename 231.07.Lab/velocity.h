/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich, Greg Elbl, Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

#include "angle.h"

// for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;

// for add()
class Acceleration;
//class Angle;

 /*********************************************
  * Velocity
  * I feel the need, the need for speed
  *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend class TestSatellite;
   friend class TestGPS;
   friend class TestHubble;
   friend class TestStarlink;
   friend class TestCrewDragon;
   friend class TestSputnik;
   friend class TestShip;
   friend class TestPart;
   friend class TestProjectile;

   
public:
   // constructors
   Velocity()                     : dx(0.0), dy(0.0)       { }
   Velocity(double dx, double dy) : dx(dx), dy(dy)         { }
   Velocity(const Velocity & rhs) : dx(rhs.dx), dy(rhs.dy) { }
   
   Velocity operator+(const Velocity & rhs)
   {
      return Velocity(dx + rhs.dx, dy + rhs.dy);
   }

   // getters
   double getDX()       const { return dx; }
   double getDY()       const { return dy; }
   double getSpeed()    const;
   Angle  getAngle()    const;
   
   // setters
   void set(const Angle & angle, double magnitude);
   void setDX(double dx) { this->dx  = dx; }
   void setDY(double dy) { this->dy  = dy; }
   void addDX(double dx) { this->dx += dx; }
   void addDY(double dy) { this->dy += dy; }
   void add(const Acceleration & acceleration, double time);
   void add(const Velocity & rhs)
   {
      dx += rhs.dx;
      dy += rhs.dy;
   }
   void addSpeed(double speed)
   {
      speed += getSpeed();
      Angle a;
      a.setRadians(getAngle().getRadians());
      set(a, speed);
   }
   void reverse()
   {
      dx *= -1.0;
      dy *= -1.0;
   }

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};

