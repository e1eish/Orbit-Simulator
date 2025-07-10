/***********************************************************************
 * Header File:
 *    StarlinkBody : The representation of a body of a starlink satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a body of a starlink satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

using namespace std;


class StarlinkBody : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   StarlinkBody() : Part() {}
   StarlinkBody(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
               Part(pos, velocity, angle, angularVel, radius) {}
   StarlinkBody(const StarlinkBody & rhs) :  Part(rhs) {}
   StarlinkBody(const Satellite * rhs, const Angle & angle) :  Part(const Satellite * rhs, const Angle & angle) {}
   ~StarlinkBody() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawStarlinkBody(pos, direction.getRadians()); }
};

