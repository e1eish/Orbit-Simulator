/***********************************************************************
 * Header File:
 *    Ship : The representation of a ship
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a ship
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"

#define SHIP_RADIUS 10.0

using namespace std;


class Ship : public Satellite
{
public:
   friend class TestShip;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Ship() : Satellite(), isThrusting(false) { radius = SHIP_RADIUS; }
   Ship(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Satellite(pos, velocity, angle, angularVel), isThrusting((false)) { radius = SHIP_RADIUS; }
   Ship(const Ship & rhs) :  Satellite(rhs), isThrusting(rhs.isThrusting) {}
   ~Ship() {}
   
   virtual void input(const Interface* pUI, list<Satellite*> &satellites, double time);
   virtual void draw(ogstream* pgout) const { pgout->drawShip(pos, direction.getRadians(), isThrusting); }
   
   void fireBullet(list<Satellite*> &satellites, double time);
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      vector<Position> positions = getDestructionPositions(3);
      
      Fragment * frag1 = new Fragment();
      adjustSatellite(frag1, pos, positions[0], velocity);
      satellites.push_back(frag1);
      
      Fragment * frag2 = new Fragment();
      adjustSatellite(frag2, pos, positions[1], velocity);
      satellites.push_back(frag2);
      
      Fragment * frag3 = new Fragment();
      adjustSatellite(frag3, pos, positions[2], velocity);
      satellites.push_back(frag3);

      
      kill();
   }
   
private:
   bool isThrusting;
};

