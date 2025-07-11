/***********************************************************************
 * Header File:
 *    CrewDragonRight : The representation of the right solar array part of a crew dragon satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a right solar array part of a crew dragon satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "uiDraw.h"

#define DRAGON_RIGHT_RADIUS 6.0

using namespace std;


class CrewDragonRight : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   CrewDragonRight() : Part() { radius = DRAGON_RIGHT_RADIUS; }
   CrewDragonRight(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
             Part(                 pos,                  velocity,               angle,        angularVel)
             { radius = DRAGON_RIGHT_RADIUS; }
   CrewDragonRight(const CrewDragonRight & rhs) : Part(rhs) {}
   CrewDragonRight(const Satellite * rhs, const Angle & angle) :  Part(const Satellite * rhs, const Angle & angle) {}
   ~CrewDragonRight() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawCrewDragonRight(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      generateFragments(satellites, 2);
      
      kill();
   }
};

