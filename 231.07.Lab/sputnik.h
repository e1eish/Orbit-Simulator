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
#include "fragment.h"

#define SPUTNIK_RADIUS 4.0

using namespace std;


class Sputnik : public Satellite
{
public:
   friend class TestSputnik;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Sputnik() : Satellite() { radius = SPUTNIK_RADIUS; }
   Sputnik(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Satellite(pos, velocity, angle, angularVel) { radius = SPUTNIK_RADIUS; }
   Sputnik(const Sputnik & rhs) :  Satellite(rhs) {}
   ~Sputnik() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawSputnik(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      vector<Position> positions = getDestructionPositions(4);
      for (int i = 0; i < 4; i++)
      {
         Fragment * frag = new Fragment();
         adjustSatellite(frag, pos, positions[i], velocity);
         satellites.push_back(frag);
      }
      
      kill();
   }
};

