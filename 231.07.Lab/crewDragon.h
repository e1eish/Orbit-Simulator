/***********************************************************************
 * Header File:
 *    CrewDragon : The representation of a Crew Dragon satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a Crew Dragon satellite
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"

#define DRAGON_RADIUS 7.0

using namespace std;


class CrewDragon : public Satellite
{
public:
   friend class TestCrewDragon;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   CrewDragon() : Satellite() { radius = DRAGON_RADIUS; }
   CrewDragon(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Satellite(pos, velocity, angle, angularVel) { radius = DRAGON_RADIUS; }
   CrewDragon(const CrewDragon & rhs) :  Satellite(rhs) {}
   ~CrewDragon() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawCrewDragon(pos, direction.getRadians()); }
};

