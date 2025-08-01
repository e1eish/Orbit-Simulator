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

#define GPS_RIGHT_RADIUS 8.0

using namespace std;


class GPSRight : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   GPSRight() : Part() { radius = GPS_RIGHT_RADIUS; }
   GPSRight(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Part(pos, velocity, angle, angularVel) { radius = GPS_RIGHT_RADIUS; }
   GPSRight(const GPSRight & rhs) :  Part(rhs) {}
   GPSRight(const Satellite * rhs, const Position & position) :  Part(rhs, position) { radius = GPS_RIGHT_RADIUS; }
   ~GPSRight() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawGPSRight(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 3);
      
      kill();
   }
};

