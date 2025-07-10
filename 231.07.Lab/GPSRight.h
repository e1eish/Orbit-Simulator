/***********************************************************************
 * Header File:
 *    GPSRight : The representation of the right part of a GPS satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a right part of a GPS satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

using namespace std;


class GPSRight : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   GPSRight() : Part() {}
   GPSRight(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
               Part(pos, velocity, angle, angularVel, radius) {}
   GPSRight(const GPSRight & rhs) :  part(rhs) {}
   GPSRight(const Satellite * rhs, const Angle & angle) :  Part(const Satellite * rhs, const Angle & angle) {}
   ~GPSRight() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawGPSRight(pos, direction.getRadians()); }
};

