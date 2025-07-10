/***********************************************************************
 * Header File:
 *    Ship : The representation of a Ship
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a Ship and how it moves
 ************************************************************************/

#include "ship.h"
#include "uiInteract.h"
#include "acceleration.h"

#define ROTATION_SPEED 0.1
#define THRUST 2.0

void Ship::input(const Interface* pUI, double time)
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
}
