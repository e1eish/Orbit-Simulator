/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich, Greg Elbl, Ethan Leishman
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
 * ANGLE : NORMALIZE
 *   Ensure that a given angle is between 0 and 2pi radians and still equivalent by adding or subtracting 2pi (360 degrees).
 * Input:
 *   radians : double
 * Output:
 *   radians : double
 ************************************/
double Angle::normalize(double radians) const
{
  while (radians > 2 * M_PI || radians < 0.0)
  {
     if (radians > 2 * M_PI)
        radians -= 2 * M_PI;
     else if (radians < 0.0)
        radians += 2 * M_PI;
  }
   
   assert(radians >= 0 && radians <= 2 * M_PI); // assert radians is within 0 and 2pi
     
  return radians;
}



