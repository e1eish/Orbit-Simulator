/***********************************************************************
 * Header File:
 *    Test Projectile : Test the Projectile class
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    All the unit tests for Projectile
 ************************************************************************/


#pragma once

#include "projectile.h"
#include "satellite.h"
#include "acceleration.h"
#include "angle.h"
#include "unitTest.h"
#include <cmath>

/*******************************
 * TEST Projectile
 * A friend class for Part which contains the Projectile unit tests
 ********************************/
class TestProjectile : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_fromDestroy();
      
      // move
      move_noVelocity();
      move_perpendicularVelocity();
      move_diagonalVelocity();
      move_kill();
      
      report("Projectile");
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
      ProjectileStub p(pS, a);
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
   
   /*********************************************
    * name:    MOVE NO VELOCITY
    * input:   pos.x=0.0, pos.y=42164000.0, v.dx=0.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0, timer=10
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    *
    *    x_t = x_0 + dx * t + 1/2 * ddx * t^2
    *    dx = dx_0 + ddx * t
    * output:  pos.x=0.0, pos.y=42163999.6634, vel.dx=0.0, vel.dy= -0.224391342075, timer=9
    *********************************************/
   void move_noVelocity()
   {
      // setup
      ProjectileStub s;
      s.pos.x = 0.0;
      s.pos.y = 42164000.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      s.timer = 10;
      
      double time = 1.0;
      
      // exercise
      s.move(time);
      // verify
      assertEquals(s.pos.x, 0.0);
      assertEquals(s.pos.y, 42163999.6634);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, -0.224391342075);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
      assertEquals(s.timer, 9);
      assertEquals(time, 1.0);
   }  // teardown
   
   /*********************************************
    * name:    MOVE PERPENDICULAR VELOCITY
    * input:   pos.x=0.0, pos.y=42164000.0, v.dx= -3100.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0, timer=10
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    *
    *    x_t = x_0 + dx * t + 1/2 * ddx * t^2
    *    dx = dx_0 + ddx * t
    * output:  pos.x= -3100.0, pos.y=42163999.6634, vel.dx= -3100.0, vel.dy= -0.224391342075, timer=9
    *********************************************/
   void move_perpendicularVelocity()
   {
      // setup
      ProjectileStub s;
      s.pos.x = 0.0;
      s.pos.y = 42164000.0;
      s.velocity.dx = -3100.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      s.timer = 10;
      
      double time = 1.0;
      
      // exercise
      s.move(time);
      // verify
      assertEquals(s.pos.x, -3100.0);
      assertEquals(s.pos.y, 42163999.6634);
      assertEquals(s.velocity.dx, -3100.0);
      assertEquals(s.velocity.dy, -0.224391342075);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
      assertEquals(s.timer, 9);
      assertEquals(time, 1.0);
   }  // teardown
   
   /*********************************************
    * name:    MOVE DIAGONAL VELOCITY
    * input:   pos.x=0.0, pos.y=42164000.0, v.dx= -3100.0, v.dy= -3100.0, dir=0.0, angularVel=0.0, radius=0.0, timer=10
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    *
    *    x_t = x_0 + dx * t + 1/2 * ddx * t^2
    *    dx = dx_0 + ddx * t
    * output:  pos.x= -3100.0, pos.y=42160899.6634, vel.dx= -3100.0, vel.dy= -3100.22439134, timer=9
    *********************************************/
   void move_diagonalVelocity()
   {
      // setup
      ProjectileStub s;
      s.pos.x = 0.0;
      s.pos.y = 42164000.0;
      s.velocity.dx = -3100.0;
      s.velocity.dy = -3100.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      s.timer = 10;
      
      double time = 1.0;
      
      // exercise
      s.move(time);
      // verify
      assertEquals(s.pos.x, -3100.0);
      assertEquals(s.pos.y, 42160899.6634);
      assertEquals(s.velocity.dx, -3100.0);
      assertEquals(s.velocity.dy, -3100.22439134);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
      assertEquals(s.timer, 9);
      assertEquals(time, 1.0);
   }  // teardown
   
   /*********************************************
    * name:    MOVE KILL
    * input:   pos.x=0.0, pos.y=42164000.0, v.dx=0.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0, timer=1, dead=false
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    *
    *    x_t = x_0 + dx * t + 1/2 * ddx * t^2
    *    dx = dx_0 + ddx * t
    * output:  pos.x=0.0, pos.y=42163999.6634, vel.dx=0.0, vel.dy= -0.224391342075, timer=0, dead=true
    *********************************************/
   void move_kill()
   {
      // setup
      ProjectileStub s;
      s.pos.x = 0.0;
      s.pos.y = 42164000.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      s.timer = 1;
      
      double time = 1.0;
      
      // exercise
      s.move(time);
      // verify
      assertEquals(s.pos.x, 0.0);
      assertEquals(s.pos.y, 42163999.6634);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, -0.224391342075);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, true);
      assertEquals(s.radius, 0.0);
      assertEquals(s.timer, 0);
      assertEquals(time, 1.0);
   }  // teardown
};
