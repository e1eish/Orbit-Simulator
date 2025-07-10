/***********************************************************************
 * Header File:
 *    Test Hubble : Test the Hubble class
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    All the unit tests for Hubble
 ************************************************************************/


#pragma once

#include "hubble.h"
#include "acceleration.h"
#include "unitTest.h"
#include <cmath>

#define EARTH_RADIUS 6378000.0
#define GRAVITY 9.80665

/*******************************
 * TEST Hubble
 * A friend class for Hubble which contains the Hubble unit tests
 ********************************/
class TestHubble : public UnitTest
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
      getGravity_diagonal();
      
      // move
      move_noVelocity();
      move_perpendicularVelocity();
      move_diagonalVelocity();
      
      
      report("Hubble");
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
      Hubble s;
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
      Hubble s(p, v, a, angV);
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
   
   /*********************************************
    * name:    COPY CONSTRUCTOR
    * input:   pos.x=1.1, pos.y=2.2, v.dx=3.3, v.dy=4.4, dir=180.0 degrees, angularVel=5.5, radius=6.6
    * output:  pos(1.1, 2.2), velocity(3.3, 4.4)), direction(M_PI),
               angularVelocity(5.5), dead(false), radius(6.6)
    *********************************************/
   void construct_copy()
   {
      // setup
      Hubble rhs;
      rhs.pos.x = 1.1;
      rhs.pos.y = 2.2;
      rhs.velocity.dx = 3.3;
      rhs.velocity.dy = 4.4;
      rhs.direction.radians = M_PI;
      rhs.angularVelocity = 5.5;
      rhs.radius = 6.6;
      
      // exercise
      Hubble s(rhs);
      // verify
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, M_PI);
      assertEquals(s.angularVelocity, 5.5);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 6.6);
      
      assertEquals(rhs.pos.x, 1.1);
      assertEquals(rhs.pos.y, 2.2);
      assertEquals(rhs.velocity.dx, 3.3);
      assertEquals(rhs.velocity.dy, 4.4);
      assertEquals(rhs.direction.radians, M_PI);
      assertEquals(rhs.angularVelocity, 5.5);
      assertEquals(rhs.radius, 6.6);
   }  // teardown
   
   /*********************************************
    * name:    GET RADIUS
    * input:   pos.x=1.1, pos.y=2.2, v.dx=3.3, v.dy=4.4, dir=180.0 degrees, angularVel=5.5, radius=6.6
    * output:  r = 6.6
    *********************************************/
   void getRadius()
   {
      // setup
      Hubble s;
      s.pos.x = 1.1;
      s.pos.y = 2.2;
      s.velocity.dx = 3.3;
      s.velocity.dy = 4.4;
      s.direction.radians = M_PI;
      s.dead = false;
      s.angularVelocity = 5.5;
      s.radius = 6.6;
      
      double r;
      r = 99.99;
      
      // exercise
      r = s.getRadius();
      // verify
      assertEquals(r, 6.6);
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, M_PI);
      assertEquals(s.angularVelocity, 5.5);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 6.6);
   }  // teardown
   
   /*********************************************
    * name:    GET POSITION
    * input:   pos.x=1.1, pos.y=2.2, v.dx=3.3, v.dy=4.4, dir=180.0 degrees, angularVel=5.5, radius=6.6
    * output:  p.x=1.1, p.y=2.2
    *********************************************/
   void getPosition()
   {
      // setup
      Hubble s;
      s.pos.x = 1.1;
      s.pos.y = 2.2;
      s.velocity.dx = 3.3;
      s.velocity.dy = 4.4;
      s.direction.radians = M_PI;
      s.dead = false;
      s.angularVelocity = 5.5;
      s.radius = 6.6;
      
      Position p;
      p.x = 99.99;
      p.y = 99.99;
      
      // exercise
      p = s.getPosition();
      // verify
      assertEquals(p.x, 1.1);
      assertEquals(p.y, 2.2);
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, M_PI);
      assertEquals(s.angularVelocity, 5.5);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 6.6);
   }  // teardown
   
   /*********************************************
    * name:    IS DEAD
    * input:   pos.x=1.1, pos.y=2.2, v.dx=3.3, v.dy=4.4, dir=180.0 degrees, dead = true, angularVel=5.5, radius=6.6
    * output:  isDead=true
    *********************************************/
   void isDead()
   {
      // setup
      Hubble s;
      s.pos.x = 1.1;
      s.pos.y = 2.2;
      s.velocity.dx = 3.3;
      s.velocity.dy = 4.4;
      s.direction.radians = M_PI;
      s.dead = true;
      s.angularVelocity = 5.5;
      s.radius = 6.6;
      
      bool isDead = false;
      
      // exercise
      isDead = s.isDead();
      // verify
      assertEquals(isDead, true);
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, M_PI);
      assertEquals(s.angularVelocity, 5.5);
      assertEquals(s.dead, true);
      assertEquals(s.radius, 6.6);
   }  // teardown
   
   /*********************************************
    * name:    KILL
    * input:   pos.x=1.1, pos.y=2.2, v.dx=3.3, v.dy=4.4, dir=180.0 degrees, dead=false, angularVel=5.5, radius=6.6
    * output:  isDead=true
    *********************************************/
   void kill()
   {
      // setup
      Hubble s;
      s.pos.x = 1.1;
      s.pos.y = 2.2;
      s.velocity.dx = 3.3;
      s.velocity.dy = 4.4;
      s.direction.radians = M_PI;
      s.dead = false;
      s.angularVelocity = 5.5;
      s.radius = 6.6;
      
      // exercise
      s.kill();
      
      // verify
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, M_PI);
      assertEquals(s.angularVelocity, 5.5);
      assertEquals(s.dead, true);
      assertEquals(s.radius, 6.6);
   }  // teardown
   
   /*********************************************
    * name:    GET GRAVITY ON SURFACE
    * input:   pos.x=0.0, pos.y=EARTH_SURFACE, v.dx=0.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    * output:  a.ddx=0.0, a.ddy = -9.80665
    *********************************************/
   void getGravity_onSurface()
   {
      // setup
      Hubble s;
      s.pos.x = 0.0;
      s.pos.y = EARTH_RADIUS;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
      Acceleration a;
      a.ddx = 99.99;
      a.ddy = 99.99;
      
      // exercise
      a = s.getGravity();
      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, -GRAVITY);
      assertEquals(s.pos.x, 0.0);
      assertEquals(s.pos.y, EARTH_RADIUS);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    GET GRAVITY ABOVE
    * input:   pos.x=0.0, pos.y=42164000.0, v.dx=0.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    * output:  a.ddx= 0.0, a.ddy= -0.224391342075
    *********************************************/
   void getGravity_above()
   {
      // setup
      Hubble s;
      s.pos.x = 0.0;
      s.pos.y = 42164000.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
      Acceleration a;
      a.ddx = 99.99;
      a.ddy = 99.99;
      
      // exercise
      a = s.getGravity();
      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, -0.224391342075);
      assertEquals(s.pos.x, 0.0);
      assertEquals(s.pos.y, 42164000.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    GET GRAVITY BELOW
    * input:   pos.x=0.0, pos.y= -42164000.0, v.dx=0.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    * output:  a.ddx= 0.0, a.ddy=0.224391342075
    *********************************************/
   void getGravity_below()
   {
      // setup
      Hubble s;
      s.pos.x = 0.0;
      s.pos.y = -42164000.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
      Acceleration a;
      a.ddx = 99.99;
      a.ddy = 99.99;
      
      // exercise
      a = s.getGravity();
      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.224391342075);
      assertEquals(s.pos.x, 0.0);
      assertEquals(s.pos.y, -42164000.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    GET GRAVITY DIAGONAL
    * input:   pos.x=29814450.3219, pos.y=29814450.3219, v.dx=0.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    * output:  a.ddx= -0.158668639621, a.ddy= -0.158668639621
    *********************************************/
   void getGravity_diagonal()
   {
      // setup
      Hubble s;
      s.pos.x = 29814450.3219;
      s.pos.y = 29814450.3219;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
      Acceleration a;
      a.ddx = 99.99;
      a.ddy = 99.99;
      
      // exercise
      a = s.getGravity();
      // verify
      assertEquals(a.ddx, -0.158668639621);
      assertEquals(a.ddy, -0.158668639621);
      assertEquals(s.pos.x, 29814450.3219);
      assertEquals(s.pos.y, 29814450.3219);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    MOVE NO VELOCITY
    * input:   pos.x=0.0, pos.y=42164000.0, v.dx=0.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    *
    *    x_t = x_0 + dx * t + 1/2 * ddx * t^2
    *    dx = dx_0 + ddx * t
    * output:  pos.x=0.0, pos.y=42163999.6634, vel.dx=0.0, vel.dy= -0.224391342075
    *********************************************/
   void move_noVelocity()
   {
      // setup
      Hubble s;
      s.pos.x = 0.0;
      s.pos.y = 42164000.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
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
      assertEquals(time, 1.0);
   }  // teardown
   
   /*********************************************
    * name:    MOVE PERPENDICULAR VELOCITY
    * input:   pos.x=0.0, pos.y=42164000.0, v.dx= -3100.0, v.dy=0.0, dir=0.0, angularVel=0.0, radius=0.0
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    *
    *    x_t = x_0 + dx * t + 1/2 * ddx * t^2
    *    dx = dx_0 + ddx * t
    * output:  pos.x= -3100.0, pos.y=42163999.6634, vel.dx= -3100.0, vel.dy= -0.224391342075
    *********************************************/
   void move_perpendicularVelocity()
   {
      // setup
      Hubble s;
      s.pos.x = 0.0;
      s.pos.y = 42164000.0;
      s.velocity.dx = -3100.0;
      s.velocity.dy = 0.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
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
      assertEquals(time, 1.0);
   }  // teardown
   
   /*********************************************
    * name:    MOVE DIAGONAL VELOCITY
    * input:   pos.x=0.0, pos.y=42164000.0, v.dx= -3100.0, v.dy= -3100.0, dir=0.0, angularVel=0.0, radius=0.0
    *    grav = g * (r / (r + h)) ^ 2
    *    dir = atan((x_e - x_s) / y_e - y_s)
    *
    *    x_t = x_0 + dx * t + 1/2 * ddx * t^2
    *    dx = dx_0 + ddx * t
    * output:  pos.x= -3100.0, pos.y=42160899.6634, vel.dx= -3100.0, vel.dy= -3100.22439134
    *********************************************/
   void move_diagonalVelocity()
   {
      // setup
      Hubble s;
      s.pos.x = 0.0;
      s.pos.y = 42164000.0;
      s.velocity.dx = -3100.0;
      s.velocity.dy = -3100.0;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
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
      assertEquals(time, 1.0);
   }  // teardown
};
