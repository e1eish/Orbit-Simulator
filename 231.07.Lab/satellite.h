/***********************************************************************
 * Header File:
 *    Satellite : The representation of a satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a satellite and how it moves
 ************************************************************************/

#pragma once

#include <iostream>
#include <cmath>
#include <list>
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;


class Satellite
{
public:
   friend class TestSatellite;
   friend class Position;
   friend class Velocity;
   friend class Angle;
   
   
   Satellite() :  velocity(Velocity(0.0, 0.0)), pos(Position(0.0, 0.0)), direction(Angle(0.0)),
                  angularVelocity(0.0), dead(false), radius(0.0) {}
   Satellite(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel, double radius) :
               velocity(velocity), pos(pos), direction(angle), angularVelocity(angularVel), dead(false), radius(radius) {}
   Satellite(const Satellite & rhs) :  velocity(rhs.velocity), pos(rhs.pos), direction(rhs.direction),
                                       angularVelocity(rhs.angularVelocity), dead(rhs.dead), radius(rhs.radius) {}
   ~Satellite() {}
   
   double getRadius() const { return radius; }
   Position getPosition() const { return pos; }
   
   bool isDead() const { return dead; }
   void kill() { dead = true; }
   
   virtual void draw(ogstream* pgout) const {}
   virtual void destroy(list<Satellite*> &satellites) {}
   virtual void input(const Interface* pUI) {}
   virtual void move(double time);
   
protected:
   Position pos;
   Velocity velocity;
   Angle direction;
   double angularVelocity;
   bool dead;
   double radius;
   
   Acceleration getGravity() const;
};
