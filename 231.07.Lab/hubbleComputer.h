/***********************************************************************
 * Header File:
 *    HubbleComputer : The representation of the computer part of a Hubble satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a computer part of a Hubble satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define COMPUTER_RADIUS 7.0

using namespace std;


class HubbleComputer : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   HubbleComputer() : Part() { radius = COMPUTER_RADIUS; }
   HubbleComputer(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Part(pos, velocity, angle, angularVel) { radius = COMPUTER_RADIUS; }
   HubbleComputer(const GPSCenter & rhs) :  Part(rhs) {}
   HubbleComputer(const Satellite * rhs, const Angle & angle) :  Part(rhs, angle) {}
   ~HubbleComputer() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawHubbleComputer(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 2);
      
      kill();
   }
};

