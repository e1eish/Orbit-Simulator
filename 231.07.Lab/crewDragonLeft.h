/***********************************************************************
 * Header File:
 *    CrewDragonLeft : The representation of the left solar array part of a crew dragon satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a left solar array part of a crew dragon satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define DRAGON_LEFT_RADIUS 6.0

using namespace std;


class CrewDragonLeft : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   CrewDragonLeft() : Part() { radius = DRAGON_LEFT_RADIUS; }
   CrewDragonLeft(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
             Part(                 pos,                  velocity,               angle,        angularVel)
             { radius = DRAGON_LEFT_RADIUS; }
   CrewDragonLeft(const CrewDragonLeft & rhs) : Part(rhs) {}
   CrewDragonLeft(const Satellite * rhs, const Angle & angle) :  Part(rhs, angle) {}
   ~CrewDragonLeft() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawCrewDragonLeft(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 2);
      
      kill();
   }
};

