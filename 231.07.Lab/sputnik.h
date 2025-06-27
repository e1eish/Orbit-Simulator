/***********************************************************************
 * Header File:
 *    Sputnik : The representation of a Sputnik satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a Sputnik satellite
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"

using namespace std;


class Sputnik : public Satellite
{
public:
   friend class TestSputnik;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Sputnik() : Satellite() {}
   Sputnik(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
               Satellite(pos, velocity, angle, angularVel, radius) {}
   Sputnik(const Sputnik & rhs) :  Satellite(rhs) {}
   ~Sputnik() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawSputnik(pos, direction.getRadians()); }
};

