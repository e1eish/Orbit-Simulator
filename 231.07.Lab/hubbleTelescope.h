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

#define TELESCOPE_RADIUS 10.0

using namespace std;


class HubbleTelescope : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   HubbleTelescope() : Part() { radius = TELESCOPE_RADIUS; }
   HubbleTelescope(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Part(pos, velocity, angle, angularVel) { radius = TELESCOPE_RADIUS; }
   HubbleTelescope(const GPSCenter & rhs) :  Part(rhs) {}
   HubbleTelescope(const Satellite * rhs, const Angle & angle) :  Part(rhs, angle) {}
   ~HubbleTelescope() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawHubbleTelescope(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 3);
      
      kill();
   }
};

