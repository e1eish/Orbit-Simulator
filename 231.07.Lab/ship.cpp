/***********************************************************************
 * Header File:
 *    Ship : The representation of a Ship
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a Ship and how it moves
 ************************************************************************/

#include <cmath>
#include "ship.h"
#include "uiInteract.h"
#include "acceleration.h"
#include "bullet.h"

#define ROTATION_SPEED 0.1
#define THRUST 2.0

#define SHIP_RADIUS 10.0

void Ship::input(const Interface* pUI, list<Satellite*> &satellites, double time)
{
   if (pUI->isUp())
   {
      Acceleration a;
      a.set(direction, THRUST);
      velocity.add(a, time);
      isThrusting = true;
   }
   else
      isThrusting = false;
   
   if (pUI->isLeft())
      direction.add(-ROTATION_SPEED);
   if (pUI->isRight())
      direction.add(ROTATION_SPEED);
   
   if (pUI->isSpace())
      fireBullet(satellites, time);
}

void Ship::fireBullet(list<Satellite*> &satellites, double time)
{
   Bullet * bullet = new Bullet(this, direction);

   for (int i = 0; i < 4; i++)
      bullet->move(time);
   
//   double forwardX = 10.0 * sin(direction.getRadians());
//   double forwardY = 10.0 * cos(direction.getRadians());
//
//   Position forwardPos(pos.getPixelsX() + forwardX, pos.getPixelsY() + forwardY);
//   bullet->setPosition(forwardPos);
   
   satellites.push_back(bullet);
}
