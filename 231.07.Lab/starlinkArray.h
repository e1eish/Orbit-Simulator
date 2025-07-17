/***********************************************************************
 * Header File:
 *    StarlinkArray : The representation of an array of a starlink satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about an array of a starlink satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define STARLINK_ARRAY_RADIUS 4.0

using namespace std;


class StarlinkArray : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   StarlinkArray() : Part() { radius = STARLINK_ARRAY_RADIUS; }
   StarlinkArray(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Part(pos, velocity, angle, angularVel) { radius = STARLINK_ARRAY_RADIUS; }
   StarlinkArray(const StarlinkArray & rhs) :  Part(rhs) {}
   StarlinkArray(const Satellite * rhs, const Angle & angle) :  Part(rhs, angle) {}
   StarlinkArray(const Satellite * rhs, const Position & position) :  Part(rhs, position) { radius = STARLINK_ARRAY_RADIUS; }
   ~StarlinkArray() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawStarlinkArray(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 3);
      
      kill();
   }
};

