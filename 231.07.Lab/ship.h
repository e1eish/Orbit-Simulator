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
   
   virtual void input(const Interface* pUI, double time);
   virtual void draw(ogstream* pgout) const { pgout->drawShip(pos, direction.getRadians(), isThrusting); }
   
private:
   bool isThrusting;
};

