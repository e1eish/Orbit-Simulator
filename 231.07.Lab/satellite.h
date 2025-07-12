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
   friend class TestPart;
   friend class TestProjectile;
   friend class TestShip;
   
   
   Satellite() : velocity(Velocity(0.0, 0.0)), pos(Position(0.0, 0.0)), direction(Angle(0.0)),
                  angularVelocity(0.0), dead(false), radius(0.0) {}
   Satellite(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
               velocity(velocity), pos(pos), direction(angle), angularVelocity(angularVel), dead(false), radius(0.0) {}
   Satellite(const Satellite & rhs) : velocity(rhs.velocity), pos(rhs.pos), direction(rhs.direction),
                                       angularVelocity(rhs.angularVelocity), dead(rhs.dead), radius(rhs.radius) {}
   /*Satellite(const Satellite * rhs) : velocity(rhs->velocity), pos(rhs->pos), direction(rhs->direction),
                                       angularVelocity(rhs->angularVelocity), dead(rhs->dead), radius(rhs->radius) {}*/
   ~Satellite() {}
   
   void setPosition(const Position & rhs) { pos = rhs;       }
   void setVelocity(const Velocity & rhs) { velocity = rhs;  }
   void setDirection(const Angle & rhs)   { direction = rhs; }
   
   double getRadius() const { return radius; }
   Position getPosition() const { return pos; }
   
   bool isDead() const { return dead; }
   void kill() { dead = true; }
   
   virtual void draw(ogstream* pgout) const {}
   virtual void destroy(list<Satellite*> &satellites) { kill(); }
   virtual void input(const Interface* pUI, list<Satellite*> &satellites, double time) {}
   virtual void move(double time);
   
   Velocity getVelocity() const { return velocity; }
   
protected:
   Position pos;
   Velocity velocity;
   Angle direction;
   double angularVelocity;
   bool dead;
   double radius;
   
   Acceleration getGravity() const;
   
   vector<Position> getDestructionPositions(int numberPositions);
   void adjustSatellite(Satellite * satellite, Position & startPos, Position & adjustPos, Velocity & startVelocity);
};
