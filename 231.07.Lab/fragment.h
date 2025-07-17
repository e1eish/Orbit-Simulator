/***********************************************************************
 * Header File:
 *    Fragment : The representation of a fragment of a satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a fragment
 ************************************************************************/

#pragma once

#include "projectile.h"
#include "uiDraw.h"

#define FRAGMENT_RADIUS 2.0

using namespace std;


class Fragment : public Projectile
{
public:
   Fragment() : Projectile()
   {
      angularVelocity = random(-M_PI / 6.0, M_PI / 6.0);
      radius = FRAGMENT_RADIUS;
   }
   Fragment(const Position & pos, Velocity & velocity, const Angle & angle) :
   Projectile(pos, velocity, angle, random(-0.5, 0.5))
   {
      angularVelocity = random(-M_PI / 6.0, M_PI / 6.0);
      radius = FRAGMENT_RADIUS;
   }
   Fragment(const Fragment & rhs) :  Projectile(rhs) {}
   Fragment(const Satellite * rhs, const Angle & angle) : Projectile(rhs, angle) {}
   Fragment(const Satellite * rhs, const Position & position) : Projectile(rhs, position) { radius = FRAGMENT_RADIUS; }
   ~Fragment() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawFragment(pos, direction.getRadians()); }
};
