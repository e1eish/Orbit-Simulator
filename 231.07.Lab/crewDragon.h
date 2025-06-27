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

using namespace std;


class CrewDragon : public Satellite
{
public:
   friend class TestCrewDragon;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   CrewDragon() : Satellite() {}
   CrewDragon(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
               Satellite(pos, velocity, angle, angularVel, radius) {}
   CrewDragon(const CrewDragon & rhs) :  Satellite(rhs) {}
   ~CrewDragon() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawCrewDragon(pos, direction.getRadians()); }
};

