/***********************************************************************
 * Header File:
 *    Satellite : The representation of a satellite
 * Author:
 *    Ethan Leishman, Noah McSheehy
 * Summary:
 *    Everything we need to know about a satellite and how it moves
 ************************************************************************/

#include "satellite.h"
#include "acceleration.h"
#include <cmath>

#define EARTH_RADIUS 6378000.0
#define GRAVITY 9.80665
#define MAX_PART_RADIUS 10.0

void Satellite::move(double time)
{
   Acceleration a = getGravity();
   
   velocity.setDX(velocity.getDX() + a.getDDX() * time);
   velocity.setDY(velocity.getDY() + a.getDDY() * time);
   
   pos.setMetersX(pos.getMetersX() + velocity.getDX() * time + 0.5 * a.getDDX() * time * time);
   pos.setMetersY(pos.getMetersY() + velocity.getDY() * time + 0.5 * a.getDDY() * time * time);
   
   direction.add(angularVelocity);
}

Acceleration Satellite::getGravity() const
{
   double h;
   h = sqrt((pos.getMetersX() * pos.getMetersX()) + (pos.getMetersY() * pos.getMetersY())) - EARTH_RADIUS;
   
   double g;
   double x = (EARTH_RADIUS / (EARTH_RADIUS + h));
   g = GRAVITY * x * x;
   
   double d;
   d = atan2(-1.0 * pos.getMetersX(), -1.0 * pos.getMetersY());
   
   double ddx;
   double ddy;
   ddx = g * sin(d);
   ddy = g * cos(d);
   
   Acceleration a(ddx, ddy);
   return a;
}

vector<Position> Satellite::getDestructionPositions(int numberPositions)
{
   vector<Position> positions;
   
   double angleOffset = random(0.0, M_PI);
   
   double minDistance = ((MAX_PART_RADIUS + 10.0) * numberPositions) / M_PI;
   
   for (int i = 0; i < numberPositions; i++)
   {
      double angle = ((2 * M_PI / numberPositions) * i) + angleOffset;
      double x = pos.getPixelsX() + minDistance * sin(angle);
      double y = pos.getPixelsY() + minDistance * cos(angle);
      Position p;
      p.setPixelsX(x);
      p.setPixelsY(y);
      positions.push_back(p);
   }
   return positions;
}

void Satellite::addRandomVelocity()
{
   Velocity v;
   v.set(direction, random(2500.0, 4500.0)); // add a random velocity in the direction the fragmment is moving
   v = v + velocity;
   setVelocity(v);
}






vector<Position> SatelliteStub::getDestructionPositions(int numberPositions)
{
   vector<Position> positions;
   
   double angleOffset = 0.0; // get rid of randomness
   
   double minDistance = ((MAX_PART_RADIUS + 10.0) * numberPositions) / M_PI;
   
   for (int i = 0; i < numberPositions; i++)
   {
      double angle = ((2 * M_PI / numberPositions) * i) + angleOffset;
      double x = pos.getPixelsX() + minDistance * sin(angle);
      double y = pos.getPixelsY() + minDistance * cos(angle);
      Position p;
      p.setPixelsX(x);
      p.setPixelsY(y);
      positions.push_back(p);
   }
   return positions;
}

void SatelliteStub::addRandomVelocity()
{
   Velocity v;
   v.set(direction, 1.0); // add a random velocity in the direction the fragmment is moving but no longer random
   v = v + velocity;
   setVelocity(v);
}
