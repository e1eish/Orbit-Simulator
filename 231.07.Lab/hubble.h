/***********************************************************************
 * Header File:
 *    Hubble : The representation of a Hubble satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a Hubble satellite
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"
#include "hubbleTelescope.h"
#include "hubbleComputer.h"
#include "hubbleLeft.h"
#include "hubbleRight.h"

#define HUBBLE_RADIUS 10.0

using namespace std;


class Hubble : public Satellite
{
public:
   friend class TestHubble;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Hubble() : Satellite() { radius = HUBBLE_RADIUS; }
   Hubble(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Satellite(pos, velocity, angle, angularVel) { radius = HUBBLE_RADIUS; }
   Hubble(const Hubble & rhs) :  Satellite(rhs) {}
   ~Hubble() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawHubble(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      vector<Position> positions = getDestructionPositions(4);
      
      HubbleTelescope * tele = new HubbleTelescope();
      adjustSatellite(tele, pos, positions[0], velocity);
      satellites.push_back(tele);
      
      HubbleComputer * comp = new HubbleComputer();
      adjustSatellite(comp, pos, positions[1], velocity);
      satellites.push_back(comp);
      
      HubbleLeft * left = new HubbleLeft();
      adjustSatellite(left, pos, positions[2], velocity);
      satellites.push_back(left);
      
      HubbleRight * right = new HubbleRight();
      adjustSatellite(right, pos, positions[3], velocity);
      satellites.push_back(right);
      
      kill();
   }
};

