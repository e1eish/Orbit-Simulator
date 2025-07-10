/***********************************************************************
 * Header File:
 *    GPSLeft : The representation of the left part of a GPS satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a left part of a GPS satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define GPS_LEFT_RADIUS 8.0

using namespace std;


class GPSLeft : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   GPSLeft() : Part() { radius = GPS_LEFT_RADIUS; }
   GPSLeft(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Part(pos, velocity, angle, angularVel) { radius = GPS_LEFT_RADIUS; }
   GPSLeft(const GPSLeft & rhs) :  Part(rhs) {}
   GPSLeft(const Satellite * rhs, const Angle & angle) :  Part(const Satellite * rhs, const Angle & angle) {}
   ~GPSLeft() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawGPSLeft(pos, direction.getRadians()); }
};

