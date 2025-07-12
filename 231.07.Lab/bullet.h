/***********************************************************************
 * Header File:
 *    Bullet : The representation of a bullet from the ship
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a bullet
 ************************************************************************/

#pragma once

#include "projectile.h"
#include "uiDraw.h"

#define BULLET_RADIUS 1.0
#define BULLET_SPEED 9000.0

using namespace std;


class Bullet : public Projectile
{
public:
   Bullet() : Projectile() { radius = BULLET_RADIUS; }
   Bullet(const Position & pos, Velocity & velocity, const Angle & angle) :
   Projectile(pos, velocity, angle, 0.0)
   {
      angularVelocity = 0.0;
      Velocity v;
      v.set(angle, BULLET_SPEED);
      velocity.add(v);
      radius = BULLET_RADIUS;
   }
   Bullet(const Bullet & rhs) :  Projectile(rhs) {}
   Bullet(const Satellite * rhs, const Angle & angle) : Projectile(rhs, angle)
   {
      angularVelocity = 0.0;
      Velocity v;
      v.set(angle, BULLET_SPEED);
      velocity.add(v);
      radius = BULLET_RADIUS;
   }
   ~Bullet() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawProjectile(pos); }
};
