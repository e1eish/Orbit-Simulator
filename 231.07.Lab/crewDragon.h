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
      
      CrewDragonCenter * center = new CrewDragonCenter();
      adjustSatellite(center, pos, positions[0], velocity);
      satellites.push_back(center);
      
      Fragment * frag1 = new Fragment();
      adjustSatellite(frag1, pos, positions[1], velocity);
      satellites.push_back(frag1);
      
      CrewDragonLeft * left = new CrewDragonLeft();
      adjustSatellite(left, pos, positions[2], velocity);
      satellites.push_back(left);
      
      Fragment * frag2 = new Fragment();
      adjustSatellite(frag2, pos, positions[3], velocity);
      satellites.push_back(frag2);
      
      CrewDragonRight * right = new CrewDragonRight();
      adjustSatellite(right, pos, positions[4], velocity);
      satellites.push_back(right);
      
      kill();
   }
};

