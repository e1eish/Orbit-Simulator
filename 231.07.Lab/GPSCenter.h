/***********************************************************************
 * Header File:
 *    GPSCenter : The representation of the center part of a GPS satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a center part of a GPS satellite
 ************************************************************************/

#pragma once

#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

#define GPSCENTERRADIUS 7.0

using namespace std;


class GPSCenter : public Part
{
public:
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   GPSCenter() : Part() { radius = GPSCENTERRADIUS; }
   GPSCenter(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
      Part(pos, velocity, angle, angularVel) { radius = GPSCENTERRADIUS; }
   GPSCenter(const GPSCenter & rhs) :  Part(rhs) {}
   GPSCenter(const Satellite * rhs, const Angle & angle) :  Part(const Satellite * rhs, const Angle & angle) {}
   ~GPSCenter() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawGPSCenter(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      list<Position> positions = getDestructionPositions(3, maxRadius);
      for (int i = 0; i < size(positions); i++)
      {
         Angle a = positions[i].getAngle();
         Fragment * fragment = new Fragment(Position(positions[i].addMetersX(pos.getMetersX),
                                                     positions[i].addMetersY(pos.getMetersY)),
                                            velocity, a);
         satellites.push_back(fragment);
      }
      
      kill();
   }
};

