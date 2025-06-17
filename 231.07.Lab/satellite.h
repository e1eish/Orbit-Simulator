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
#include "velocity.h"
#include "position.h"
#include "angle.h"
#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;


class Satellite
{
public:
   Satellite() {}
   Satellite(const Position & pos, const Velocity & velocity, const Angle & angle) : velocity(velocity), pos(pos), direction(angle) {}
   ~Satellite() {}
   
   double getRadius() const { return radius; }
   Position getPosition() const { return pos; }
   
   bool isDead() const { return dead; }
   void kill() { dead = true; }
   
   virtual void draw(ogstream* pgout) const = 0;
   virtual void destroy(list<Satellite> &satellites) {}
   virtual void input(Interface* pUI) {}
   virtual void move(double time);
   
private:
   Velocity velocity;
   Position pos;
   Angle direction;
   double angularVelocity;
   bool dead;
   double radius;
   
   Acceleration getGravity() const;
};
