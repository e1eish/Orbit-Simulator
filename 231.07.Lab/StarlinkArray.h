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

using namespace std;


class StarlinkArray : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   StarlinkArray() : Part() {}
   StarlinkArray(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
               Part(pos, velocity, angle, angularVel, radius) {}
   StarlinkArray(const StarlinkArray & rhs) :  Part(rhs) {}
   StarlinkArray(const Satellite * rhs, const Angle & angle) :  Part(const Satellite * rhs, const Angle & angle) {}
   ~StarlinkArray() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawStarlinkArray(pos, direction.getRadians()); }
};

