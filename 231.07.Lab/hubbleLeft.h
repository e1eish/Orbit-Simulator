/***********************************************************************
 * Header File:
 *    HubbleLeft : The representation of the left solar array part of a Hubble satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a left solar array part of a Hubble satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define HUBBLE_LEFT_RADIUS 8.0

using namespace std;


class HubbleLeft : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   HubbleLeft() : Part() { radius = HUBBLE_LEFT_RADIUS; }
   HubbleLeft(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Part(pos, velocity, angle, angularVel) { radius = HUBBLE_LEFT_RADIUS; }
   HubbleLeft(const GPSCenter & rhs) :  Part(rhs) {}
   HubbleLeft(const Satellite * rhs, const Angle & angle) :  Part(rhs, angle) {}
   ~HubbleLeft() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawHubbleLeft(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 2);
      
      kill();
   }
};

