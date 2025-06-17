/***********************************************************************
 * Header File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    All the unit tests for Satellite
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "unitTest.h"
#include <cmath>

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_default();
      construct_nonDefault();
      construct_copy();
      
      // getters
      getRadius();
      getPosition();
      isDead();
      
      // setter
      kill();
      
      // getGravity()
      getGravity_onSurface();
      getGravity_above();
      getGravity_below();
      
      // move
      move_noVelocity();
      move_perpendicularVelocity();
      move_diagonalVelocity();
      
      
      report("Satellite");
   }
   
private:
   
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos(0.0, 0.0), velocity(0.0, 0.)), direction(0.0),
               angularVelocity(0.0), dead(false), radius(0.0)
    *********************************************/
   void construct_default()
   {
      // setup
      // exercise
      Satellite s;
      // verify
      assertEquals(s.pos.x, 0.0);
      assertEquals(s.pos.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    NON DEFAULT CONSTRUCTOR
    * input:   pos.x=1.1, pos.y=2.2, v.dx=3.3, v.dy=4.4, dir=180.0 degrees, angularVel=5.5, radius=6.6
    * output:  pos(1.1, 2.2), velocity(3.3, 4.4)), direction(M_PI),
               angularVelocity(5.5), dead(false), radius(6.6)
    *********************************************/
   void construct_nonDefault()
   {
      // setup
      Position p;
      p.x = 1.1;
      p.y = 2.2;
      Velocity v;
      v.dx = 3.3;
      v.dy = 4.4;
      Angle a;
      a.radians = M_PI;
      double angV = 5.5;
      double r = 6.6;
      // exercise
      Satellite s(p, v, a, angV, r);
      // verify
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, M_PI);
      assertEquals(s.angularVelocity, 5.5);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 6.6);
      
      assertEquals(p.x, 1.1);
      assertEquals(p.y, 2.2);
      assertEquals(v.dx, 3.3);
      assertEquals(v.dy, 4.4);
      assertEquals(a.radians, M_PI);
      assertEquals(angV, 5.5);
      assertEquals(r, 6.6);
   }  // teardown
   
};
