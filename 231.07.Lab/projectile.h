/***********************************************************************
 * Header File:
 *    Projectile : The representation of a projectile, or a satellite that despawns
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"

using namespace std;


class Projectile : public Satellite
{
public:
   friend class TestProjectile;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Projectile() : Satellite(), timer(0) {}
   Projectile(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
               Satellite(pos, velocity, angle, angularVel), timer(random(50,100)) {}
   Projectile(const Projectile & rhs) :  Satellite(rhs), timer(random(50,100)) {}
   Projectile(const Satellite * rhs, const Angle & angle) : Satellite(*rhs), timer(random(50,100))
   {
      direction = angle;
      angularVelocity = random(-0.5, 0.5);
      radius = 0.0;
   }
   ~Projectile() {}
   
   virtual void move(double time)
   {
      Satellite::move(time);
      
      --timer;
      if (timer <= 0)
         this->kill();
   }

private:
   short timer;
};

class ProjectileStub : public Projectile
{
public:
   ProjectileStub() : Projectile() {}
   ProjectileStub(const Satellite * rhs, const Angle & angle) : Projectile(rhs, angle)
   {
      angularVelocity = 0.5;
   }
};
