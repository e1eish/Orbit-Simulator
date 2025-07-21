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
#include <cassert>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
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
   Satellite(const Satellite * rhs, const Position & position) : pos(rhs->pos), velocity(rhs->velocity), dead(false)
   {
      direction = (position - pos).getAngle();
      pos = position;
      angularVelocity = random(-M_PI / 6.0, M_PI / 6.0);
      radius = 0.0;
      addRandomVelocity();
   }
   ~Satellite() {}
   
   void setPosition(const Position & rhs) { pos = rhs;       }
   void setVelocity(const Velocity & rhs) { velocity = rhs;  }
   void setDirection(const Angle & rhs)   { direction = rhs; }
   
   double getRadius() const { return radius; }
   Position & getPosition() { return pos; }
   
   bool isDead() const { return dead; }
   void kill() { dead = true; }
   
   virtual void draw(ogstream* pgout) const {}
   virtual void destroy(list<Satellite*> &satellites) { kill(); }
   virtual void input(const Interface* pUI, list<Satellite*> &satellites, double time) {}
   virtual void move(double time);
   
   Velocity & getVelocity() { return velocity; }
   
protected:
   Position pos;
   Velocity velocity;
   Angle direction;
   double angularVelocity;
   bool dead;
   double radius;
   
   Acceleration getGravity() const;
   
   vector<Position> getDestructionPositions(int numberPositions);
   void addRandomVelocity();
};


class SatelliteDummy : public Satellite
{
public:
   friend class TestSatellite;
   
   SatelliteDummy() : Satellite() {}
   SatelliteDummy(const Position & pos, const Velocity & velocity, const Angle & angle, double angularVel) :
               Satellite(pos, velocity, angle, angularVel) {}
   SatelliteDummy(const Satellite & rhs) : Satellite(rhs) {}
   SatelliteDummy(const Satellite * rhs, const Position & position) : Satellite() {}
   ~SatelliteDummy() {}
   
   void setPosition(const Position & rhs) { assert(false); }
   void setVelocity(const Velocity & rhs) { assert(false); }
   void setDirection(const Angle & rhs)   { assert(false); }
   
   double getRadius() const { assert(false); }
   Position & getPosition() const { assert(false); }
   
   bool isDead() const { assert(false); }
   void kill() { assert(false); }
   
   virtual void draw(ogstream* pgout) const { assert(false); }
   virtual void destroy(list<Satellite*> &satellites) { assert(false); }
   virtual void input(const Interface* pUI, list<Satellite*> &satellites, double time) { assert(false); }
   virtual void move(double time) { assert(false); }
   
   Velocity getVelocity() const { assert(false); }
   
protected:
   Acceleration getGravity() const { assert(false); }
   
   vector<Position> getDestructionPositions(int numberPositions) { assert(false); }
};

class SatelliteStub : SatelliteDummy
{
public:
   friend class TestSatellite;
   
   SatelliteStub() : SatelliteDummy() {}
   SatelliteStub(const Satellite * rhs, const Position & position) : SatelliteDummy(rhs, position)
   {
      Position p(position);
      p = p - pos;
      direction = p.getAngle();
      pos = position;
      angularVelocity = M_PI / 2.0;
      radius = 0.0;
      addRandomVelocity();
   }
   
   void setVelocity(const Velocity & rhs) { velocity = rhs; }
   
protected:
   vector<Position> getDestructionPositions(int numberPositions);
   void addRandomVelocity();
};
