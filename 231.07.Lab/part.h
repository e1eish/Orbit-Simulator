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
#include "fragment.h"

using namespace std;


class Part : public Satellite
{
public:
   friend class TestPart;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Part() : Satellite()
   {
      angularVelocity = random(-M_PI / 6.0, M_PI / 6.0);
   }
   Part(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
               Satellite(pos, velocity, angle, angularVel) {}
   Part(const Part & rhs) :  Satellite(rhs) {}
   Part(const Satellite * rhs, const Angle & angle) : Satellite(*rhs)
   {
      direction = angle;
      angularVelocity = random(-M_PI / 6.0, M_PI / 6.0);;
      radius = 0.0;
   }
   ~Part() {}
   
   // generate fragments in positions that do not collide
   virtual void generateFragments(list<Satellite*> &satellites, int count)
   {
      vector<Position> positions = getDestructionPositions(count);
//      for (auto it = positions.begin(); it != positions.end(); it++)
//      {
//         /*Angle a = (*it).getAngle();
//         (*it).addMetersX(pos.getMetersX()); // add the new position difference to the beginning position to get the resultant position
//         (*it).addMetersY(pos.getMetersY());
//         
//         Velocity v;
//         v.set(a, random(0.0, 200.0)); // add a random velocity in the direction the fragmment is moving
//         v = v + velocity;
//         
//         Fragment * fragment = new Fragment(Position((*it).getMetersX(),
//                                                     (*it).getMetersY()),
//                                            v, a);*/
//         
//         Fragment * fragment = new Fragment();
//         adjustSatellite(fragment, pos, *it, velocity);
//         satellites.push_back(fragment);
//      }
      for (int i = 0; i < count; i++)
      {
         Fragment * fragment = new Fragment();
         adjustSatellite(fragment, pos, positions[i], velocity);
         satellites.push_back(fragment);
      }
   }
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
