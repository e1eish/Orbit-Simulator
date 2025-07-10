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

#define FRAGMENTRADIUS 2.0

using namespace std;


class Fragment : public Projectile
{
public:
   Fragment() : Projectile() { radius = FRAGMENTRADIUS; }
   Fragment(const Position & pos, const Velocity & velocity, const Angle & angle) :
   Projectile(pos, velocity, angle, random(-0.5, 0.5))
   {
      velocity.addSpeed(random(0.0, 500.0));
      radius = FRAGMENTRADIUS;
   }
   Fragment(const Fragment & rhs) :  Projectile(rhs) {}
   Fragment(const Satellite * rhs, const Angle & angle) : Projectile(rhs, angle) {}
   ~Fragment() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawFragment(pos, direction.getRadians()); }
};
