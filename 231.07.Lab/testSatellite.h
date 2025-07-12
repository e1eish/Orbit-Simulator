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
#include "acceleration.h"
#include "unitTest.h"
#include <cmath>

#define EARTH_RADIUS 6378000.0
#define GRAVITY 9.80665

/*******************************
 * TEST Satellite
 * A friend class for Position which contains the Satellite unit tests
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
      
      // destroy
      destroy();
      
      // getGravity()
      getGravity_onSurface();
      getGravity_above();
      getGravity_below();
      getGravity_diagonal();
      
      // move
      move_noVelocity();
      move_perpendicularVelocity();
      move_diagonalVelocity();
      
      adjustSatellite_simple();
      
      getDestructionPositions_3();
      getDestructionPositions_4();
      
      
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
      Satellite s(p, v, a, angV);
      // verify
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, M_PI);
      assertEquals(s.angularVelocity, 5.5);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
      
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
      Satellite rhs;
      rhs.pos.x = 1.1;
      rhs.pos.y = 2.2;
      rhs.velocity.dx = 3.3;
      rhs.velocity.dy = 4.4;
      rhs.direction.radians = M_PI;
      rhs.angularVelocity = 5.5;
      rhs.radius = 6.6;
      
      // exercise
      Satellite s(rhs);
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
      Satellite s;
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
      Satellite s;
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
      Satellite s;
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
      Satellite s;
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
    * name:    DESTROY
    * input:   pos.x=1.1, pos.y=2.2, v.dx=3.3, v.dy=4.4, dir=180.0 degrees, dead=false, angularVel=5.5, radius=6.6
    * output:  isDead=true
    *********************************************/
   void destroy()
   {
      // setup
      Satellite s;
      s.pos.x = 1.1;
      s.pos.y = 2.2;
      s.velocity.dx = 3.3;
      s.velocity.dy = 4.4;
      s.direction.radians = M_PI;
      s.dead = false;
      s.angularVelocity = 5.5;
      s.radius = 6.6;
      
      list<Satellite*> satellites;
      
      // exercise
      s.destroy(satellites);
      
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
      Satellite s;
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
      Satellite s;
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
      Satellite s;
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
      Satellite s;
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
      Satellite s;
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
      Satellite s;
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
      Satellite s;
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
   
   /*********************************************
    * name:    ADJUST SATELLITE SIMPLE
    * input:   startPos(100, 200), adjustPos(10, 20), startVelocity(5, 7)
    * output:  pos(10, 20), direction(0.463647609001),
    *          velocity(5.4472135955, 7.894427191)
    *********************************************/
   void adjustSatellite_simple()
   {
      // setup
      SatelliteStub s;
      s.pos.x = 100.0;
      s.pos.y = 200.0;
      s.velocity.dx = 5.0;
      s.velocity.dy = 7.0;
      
      Position adjustPos;
      adjustPos.x = 10.0;
      adjustPos.y = 20.0;

      // exercise
      s.adjustSatellite(&s, s.pos, adjustPos, s.velocity);

      // verify
      assertEquals(s.pos.x, 10.0);
      assertEquals(s.pos.y, 20.0);
      assertEquals(s.velocity.dx, 5.4472135955);
      assertEquals(s.velocity.dy, 7.894427191);
      assertEquals(s.direction.radians, 0.463647609001);
   }
   
   
   /*********************************************
    * name:    GET DESTRUCTION POSITIONS 3
    * input:   pos.x=1.1, pos.y=2.2, v.dx= 3.3, v.dy= 4.4, dir=0.0, angularVel=0.0, radius=0.0, n=3, metersFromPixels=40.0
    *    minDist = ((maxRadius + 10) * n) / pi
    *    theta = (2pi / n) * i
    *    x_2 = x_1 + 2 * minDist * sin(theta)
    *    y_2 = y_1 + 2 * minDist * cos(theta)
    *
    *    meters to pixels -> m / metersFromPixels
    *    pixels to meters -> p * metersFromPixels
    * output:  1: (x=1.1, y=766.143726841), 2: (x=662.694674506, y= -379.771863421), 3: (x= -660.494674506, -379.771863421)
    *********************************************/
   void getDestructionPositions_3()
   {
      // setup
      double metersPixels = Position::metersFromPixels;
      Position::metersFromPixels = 40.0;
      
      SatelliteStub s;
      s.pos.x = 1.1;
      s.pos.y = 2.2;
      s.velocity.dx = 3.3;
      s.velocity.dy = 4.4;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
      int n = 3;
      
      vector<Position> positions;
      
      // exercise
      positions = s.getDestructionPositions(n);
      // verify
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
      
      assertEquals(positions[0].x, 1.1);
      assertEquals(positions[0].y, 766.143726841);
      assertEquals(positions[1].x, 662.694674506);
      assertEquals(positions[1].y, -379.771863421);
      assertEquals(positions[2].x, -660.494674506);
      assertEquals(positions[2].y, -379.771863421);
      
      // teardown
      Position::metersFromPixels = metersPixels;
   }
   
   /*********************************************
    * name:    GET DESTRUCTION POSITIONS 4
    * input:   pos.x=1.1, pos.y=2.2, v.dx= 3.3, v.dy= 4.4, dir=0.0, angularVel=0.0, radius=0.0, n=3, metersFromPixels=40.0
    *    minDist = ((maxRadius + 10) * n) / pi
    *    theta = (2pi / n) * i
    *    x_2 = x_1 + minDist * sin(theta)
    *    y_2 = y_1 + minDist * cos(theta)
    *
    *    meters to pixels -> m / metersFromPixels
    *    pixels to meters -> p * metersFromPixels
    * output:  1: (x=1.1, y=  1020.79163579), 2: (x=  1019.69163579, y=2.2),
    *          3: (x=1.1, y= -1016.39163579), 4: (x= -1017.49163579, y=2.2)
    *********************************************/
   void getDestructionPositions_4()
   {
      // setup
      double metersPixels = Position::metersFromPixels;
      Position::metersFromPixels = 40.0;
      
      SatelliteStub s;
      s.pos.x = 1.1;
      s.pos.y = 2.2;
      s.velocity.dx = 3.3;
      s.velocity.dy = 4.4;
      s.direction.radians = 0.0;
      s.dead = false;
      s.angularVelocity = 0.0;
      s.radius = 0.0;
      
      int n = 4;
      
      vector<Position> positions;
      
      // exercise
      positions = s.getDestructionPositions(n);
      // verify
      assertEquals(s.pos.x, 1.1);
      assertEquals(s.pos.y, 2.2);
      assertEquals(s.velocity.dx, 3.3);
      assertEquals(s.velocity.dy, 4.4);
      assertEquals(s.direction.radians, 0.0);
      assertEquals(s.angularVelocity, 0.0);
      assertEquals(s.dead, false);
      assertEquals(s.radius, 0.0);
      
      assertEquals(positions[0].x,     1.1);
      assertEquals(positions[0].y,  1020.79163579);
      assertEquals(positions[1].x,  1019.69163579);
      assertEquals(positions[1].y,     2.2);
      assertEquals(positions[2].x,     1.1);
      assertEquals(positions[2].y, -1016.39163579);
      assertEquals(positions[3].x, -1017.49163579);
      assertEquals(positions[3].y,     2.2);
      
      // teardown
      Position::metersFromPixels = metersPixels;
   }
};
