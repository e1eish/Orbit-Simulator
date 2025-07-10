/***********************************************************************
 * Header File:
 *    HubbleTelescope : The representation of the telescope part of a Hubble satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a telescope part of a Hubble satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define TELESCOPERADIUS 10.0

using namespace std;


class HubbleTelescope : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   HubbleTelescope() : Part() { radius = TELESCOPERADIUS; }
   HubbleTelescope(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
      Part(pos, velocity, angle, angularVel) { radius = TELESCOPERADIUS; }
   HubbleTelescope(const GPSCenter & rhs) :  Part(rhs) {}
   HubbleTelescope(const Satellite * rhs, const Angle & angle) :  Part(const Satellite * rhs, const Angle & angle) {}
   ~HubbleTelescope() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawHubbleTelescope(pos, direction.getRadians()); }
};

