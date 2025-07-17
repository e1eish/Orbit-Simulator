/***********************************************************************
 * Header File:
 *    Starlink : The representation of a Starlink satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a Starlink satellite
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "uiDraw.h"
#include "starlinkBody.h"
#include "starlinkArray.h"
#include "fragment.h"

#define STARLINK_RADIUS 6.0

using namespace std;


class Starlink : public Satellite
{
public:
   friend class TestStarlink;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Starlink() : Satellite() { radius = STARLINK_RADIUS; }
   Starlink(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
      Satellite(pos, velocity, angle, angularVel) { radius = STARLINK_RADIUS; }
   Starlink(const Starlink & rhs) :  Satellite(rhs) {}
   ~Starlink() {}
   
   virtual void draw(ogstream* pgout) const { pgout->drawStarlink(pos, direction.getRadians()); }
   
   virtual void destroy(list<Satellite*> &satellites)
   {
      vector<Position> positions = getDestructionPositions(4);
      
      satellites.push_back(new StarlinkBody (this, positions[0]));
      satellites.push_back(new Fragment     (this, positions[1]));
      satellites.push_back(new StarlinkArray(this, positions[2]));
      satellites.push_back(new Fragment     (this, positions[3]));
      
      kill();
   }
};

