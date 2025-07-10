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

#define GPSRADIUS 12.0

using namespace std;


class GPS : public Satellite
{
public:
   friend class TestGPS;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   GPS() : Satellite() { radius = GPSRADIUS; }
   GPS(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Satellite(pos, velocity, angle, angularVel) { radius = GPSRADIUS; }
   GPS(const GPS & rhs) :  Satellite(rhs) {}
   ~GPS() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawGPS(pos, direction.getRadians()); }
};

