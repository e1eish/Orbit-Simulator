/***********************************************************************
 * Header File:
 *    CrewDragonCenter : The representation of the center part of a crew dragon satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a center part of a crew dragon satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define DRAGON_CENTER_RADIUS 6.0

using namespace std;


class CrewDragonCenter : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   CrewDragonCenter() : Part() { radius = DRAGON_CENTER_RADIUS; }
   CrewDragonCenter(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
               Part(                 pos,                  velocity,               angle,        angularVel)
               { radius = DRAGON_CENTER_RADIUS; }
   CrewDragonCenter(const CrewDragonCenter & rhs) : Part(rhs) {}
   CrewDragonCenter(const Satellite * rhs, const Angle & angle) :  Part(rhs, angle) {}
   CrewDragonCenter(const Satellite * rhs, const Position & position) :  Part(rhs, position) { radius = DRAGON_CENTER_RADIUS; }
   ~CrewDragonCenter() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawCrewDragonCenter(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 4);
      
      kill();
   }
};

