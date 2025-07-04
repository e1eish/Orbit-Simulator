/***********************************************************************
 * Header File:
 *    Starlink : The representation of a Starlink satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a Starlink satellite
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"

using namespace std;


class Starlink : public Satellite
{
public:
   friend class TestStarlink;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Starlink() : Satellite() {}
   Starlink(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
               Satellite(pos, velocity, angle, angularVel, radius) {}
   Starlink(const Starlink & rhs) :  Satellite(rhs) {}
   ~Starlink() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawStarlink(pos, direction.getRadians()); }
};

