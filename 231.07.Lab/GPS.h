/***********************************************************************
 * Header File:
 *    GPS : The representation of a GPS satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a GPS satellite
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"
#include "GPSCenter.h"
#include "GPSLeft.h"
#include "GPSRight.h"
#include "fragment.h"

#define GPS_RADIUS 12.0

using namespace std;


class GPS : public Satellite
{
public:
   friend class TestGPS;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   GPS() : Satellite() { radius = GPS_RADIUS; }
   GPS(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Satellite(pos, velocity, angle, angularVel) { radius = GPS_RADIUS; }
   GPS(const GPS & rhs) :  Satellite(rhs) {}
   ~GPS() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawGPS(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      vector<Position> positions = getDestructionPositions(5);
      
      satellites.push_back(new GPSCenter(this, positions[0]));
      satellites.push_back(new Fragment (this, positions[1]));
      satellites.push_back(new GPSLeft  (this, positions[2]));
      satellites.push_back(new Fragment (this, positions[3]));
      satellites.push_back(new GPSRight (this, positions[4]));
      
      kill();
   }
};

