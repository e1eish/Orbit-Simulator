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
#include "crewDragonCenter.h"
#include "crewDragonLeft.h"
#include "crewDragonRight.h"
#include "fragment.h"

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
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      vector<Position> positions = getDestructionPositions(5);
      
      satellites.push_back(new CrewDragonCenter(this, positions[0]));
      satellites.push_back(new Fragment        (this, positions[1]));
      satellites.push_back(new CrewDragonLeft  (this, positions[2]));
      satellites.push_back(new Fragment        (this, positions[3]));
      satellites.push_back(new CrewDragonRight (this, positions[4]));
      
      kill();
   }
};

