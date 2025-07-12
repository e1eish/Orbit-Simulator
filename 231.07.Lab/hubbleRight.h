/***********************************************************************
 * Header File:
 *    HubbleRight : The representation of the right solar array part of a Hubble satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a right solar array part of a Hubble satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define HUBBLE_RIGHT_RADIUS 8.0

using namespace std;


class HubbleRight : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   HubbleRight() : Part() { radius = HUBBLE_RIGHT_RADIUS; }
   HubbleRight(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Part(pos, velocity, angle, angularVel) { radius = HUBBLE_RIGHT_RADIUS; }
   HubbleRight(const GPSCenter & rhs) :  Part(rhs) {}
   HubbleRight(const Satellite * rhs, const Angle & angle) :  Part(rhs, angle) {}
   ~HubbleRight() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawHubbleRight(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 2);
      
      kill();
   }
};

