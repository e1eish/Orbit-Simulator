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
      
      GPSCenter * center = new GPSCenter();
      adjustSatellite(center, pos, positions[0], velocity);
      satellites.push_back(center);
      
      Fragment * frag1 = new Fragment();
      adjustSatellite(frag1, pos, positions[1], velocity);
      satellites.push_back(frag1);
      
      GPSLeft * left = new GPSLeft();
      adjustSatellite(left, pos, positions[2], velocity);
      satellites.push_back(left);
      
      Fragment * frag2 = new Fragment();
      adjustSatellite(frag2, pos, positions[3], velocity);
      satellites.push_back(frag2);
      
      GPSRight * right = new GPSRight();
      adjustSatellite(right, pos, positions[4], velocity);
      satellites.push_back(right);
      
      kill();
   }
};

