/***********************************************************************
 * Header File:
 *    Part : The representation of a part of a satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a satellite part
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"

using namespace std;


class Part : public Satellite
{
public:
   friend class TestPart;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Part() : Satellite() {}
   Part(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
               Satellite(pos, velocity, angle, angularVel) {}
   Part(const Part & rhs) :  Satellite(rhs) {}
   Part(const Satellite * rhs, const Angle & angle) : Satellite(rhs)
   {
      direction = angle;
      angularVelocity = random(-0.5, 0.5);
      radius = 0.0;
   }
   ~Part() {}
   
};

class PartStub : public Part
{
public:
   PartStub() : Part() {}
   PartStub(const Satellite * rhs, const Angle & angle) : Part(rhs, angle)
   {
      angularVelocity = 0.5;
   }
};
