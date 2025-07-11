/***********************************************************************
 * Header File:
 *    GPSCenter : The representation of the center part of a GPS satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a center part of a GPS satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

#define GPS_CENTER_RADIUS 7.0

using namespace std;


class GPSCenter : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   GPSCenter() : Part() { radius = GPS_CENTER_RADIUS; }
   GPSCenter(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
      Part(pos, velocity, angle, angularVel) { radius = GPS_CENTER_RADIUS; }
   GPSCenter(const GPSCenter & rhs) :  Part(rhs) {}
   GPSCenter(const Satellite * rhs, const Angle & angle) :  Part(rhs, angle) {}
   ~GPSCenter() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawGPSCenter(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 3);
      
      kill();
   }
};

