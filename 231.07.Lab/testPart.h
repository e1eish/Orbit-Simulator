/***********************************************************************
 * Header File:
 *    Test Part : Test the Part class
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    All the unit tests for Part
 ************************************************************************/


#pragma once

#include "part.h"
#include "satellite.h"
#include "acceleration.h"
#include "angle.h"
#include "unitTest.h"
#include <cmath>

/*******************************
 * TEST Part
 * A friend class for Part which contains the Part unit tests
 ********************************/
class TestPart : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_fromDestroy();      
      
      report("Part");
   }
   
private:
   
   /*********************************************
    * name:    FROM DESTROY CONSTRUCTOR
    * input:   satellite: x=1.1, y=2.2, dx=3.3, dy=4.4, angle=M_PI, angularVelocity = 0.0, dead=false, radius=0.0
    *          angle=M_PI/2.0
    * output:  part: x=1.1, y=2.2, dx=3.3, dy=4.4, angle=M_PI/2, angularVelocity=0.5, radius=0.0
    *********************************************/
   void construct_fromDestroy()
   {
      // setup
      
      Satellite s;
      s.pos.x = 1.1;
      s.pos.y = 2.2;
      s.velocity.dx = 3.3;
      s.velocity.dy = 4.4;
      s.direction.radians = M_PI;
      s.angularVelocity = 0.0;
      s.dead = false;
      s.radius = 0.0;
      
      Angle a(90.0);
      
      Satellite * pS = &s;
      
      // exercise
      PartStub p(pS, a);
      // verify
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, M_PI);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
      
      assertEquals(p.pos.x, 1.1);
      assertEquals(p.pos.y, 2.2);
      assertEquals(p.velocity.dx, 3.3);
      assertEquals(p.velocity.dy, 4.4);
      assertEquals(p.direction.radians, M_PI / 2.0);
      assertEquals(p.angularVelocity, 0.5);
      assertEquals(p.radius, 0.0);
   }  // teardown
};
