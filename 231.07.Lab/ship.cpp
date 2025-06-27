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

#define ROTATION_SPEED 0.05

void Ship::input(const Interface* pUI)
{
   if (pUI->isUp())
      ;
   if (pUI->isDown())
      ;
   if (pUI->isLeft())
      direction.add(-ROTATION_SPEED);
   if (pUI->isRight())
      direction.add(ROTATION_SPEED);
}
