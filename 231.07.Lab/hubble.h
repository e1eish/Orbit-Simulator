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

using namespace std;


class Hubble : public Satellite
{
public:
   friend class TestHubble;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Hubble() : Satellite() {}
   Hubble(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
               Satellite(pos, velocity, angle, angularVel, radius) {}
   Hubble(const Hubble & rhs) :  Satellite(rhs) {}
   ~Hubble() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawHubble(pos, direction.getRadians()); }
};

