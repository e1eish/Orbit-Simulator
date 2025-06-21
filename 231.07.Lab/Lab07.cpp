/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was making sure that the formulas were input and used correctly.
 * 5. How long did it take for you to complete the assignment?
 *      2 hours
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "test.h"
#include "star.h"
#include "satellite.h"
#include "GPS.h"
using namespace std;

#define STARCOUNT 250
#define EARTH_RADIUS 6378000.0
#define GRAVITY 9.80665
#define FRAMERATE 30.0
#define TIME (24.0 * 60.0) / FRAMERATE

//class GPS
//{
//public:
//   Position p;
//   Position v;
//   Position a;
//   Position prevPos;
//   double angle;
//   
//   GPS() {}
//   GPS(Position & p, Position & v, Position & a, double angle) : p(p), v(v), a(a), angle(angle) {}
//   
//   Position getGravity()
//   {
//      double h;
//      h = sqrt((p.getMetersX() * p.getMetersX()) + (p.getMetersY() * p.getMetersY())) - EARTH_RADIUS;
//      
//      double g;
//      double x = (EARTH_RADIUS / (EARTH_RADIUS + h));
//      g = GRAVITY * x * x;
//      
//      double d;
//      d = atan2(-1.0 * p.getMetersX(), -1.0 * p.getMetersY());
//      
//      double ddx;
//      double ddy;
//      ddx = g * sin(d);
//      ddy = g * cos(d);
//      
//      return Position(ddx, ddy);
//   }
//   
//   void updatePosition()
//   {
//      prevPos = p;
//      
//      double tpf = (24.0 * 60.0) / FRAMERATE;
//      a = getGravity();
//      
//      v.setMetersX(v.getMetersX() + a.getMetersX() * tpf);
//      v.setMetersY(v.getMetersY() + a.getMetersY() * tpf);
//      
//      p.setMetersX(p.getMetersX() + v.getMetersX() * tpf + 0.5 * a.getMetersX() * tpf * tpf);
//      p.setMetersY(p.getMetersY() + v.getMetersY() * tpf + 0.5 * a.getMetersY() * tpf * tpf);
//      
//      angle += getAngle(p) - getAngle(prevPos);
//   }
//
//   double getAngle(Position & pos)
//   {
//      double a = atan2(pos.getMetersX(), pos.getMetersY());
//      return a;
//   }
//};



/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptGPS.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptGPS.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      angleShip = 0.5 * M_PI;
      angleEarth = 0.0;
      phaseStar = 0;
      
      ptGPS = Position(0.0,     42164000.0);
      vGPS  = Position(-3100.0, 0.0);
      aGPS  = Position(0.0,     0.0);
      
//      gps[0].p = Position(    0.0, 26560000.0);
//      gps[0].v = Position(-3880.0,        0.0);
//      gps[0].angle = 0.5 * M_PI;
//      
//      gps[1].p = Position(23001634.72, 13280000.0);
//      gps[1].v = Position(   -1940.0,      3360.18);
//      gps[1].angle = 5.0 * M_PI / 6.0;
//      
//      gps[2].p = Position(23001634.72, -13280000.0);
//      gps[2].v = Position(    1940.0,       3360.18);
//      gps[2].angle = M_PI / 6.0;
//      
//      gps[3].p = Position(   0.0, -26560000.0);
//      gps[3].v = Position(3880.0,         0.0);
//      gps[3].angle = 1.5 * M_PI;
//      
//      gps[4].p = Position(-23001634.72, -13280000.0);
//      gps[4].v = Position(     1940.0,      -3360.18);
//      gps[4].angle = 11.0 * M_PI / 6.0;
//      
//      gps[5].p = Position(-23001634.72, 13280000.0);
//      gps[5].v = Position(    -1940.0,     -3360.18);
//      gps[5].angle = 7.0 * M_PI / 6.0;
      
      GPS * gps = new GPS(Position(0.0, 42164000.0), Velocity(-3100.0, 0.0), 0.5 * M_PI, -0.000073522436656, 1.0);
      satellites.push_back(gps);
   }

   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;
   
   Position vGPS;
   Position aGPS;
   Position prevPos;
   
   //GPS gps[6];
   
   list<Satellite*> satellites;

   unsigned char phaseStar;
   Star stars[STARCOUNT];

   double angleShip;
   double angleEarth;
};


/*************************************************************************
 * Get Gravity
 * Compute the accelertion due to gravity from a given position.
 *************************************************************************/
Position getGravity(Position & pos)
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
   
   return Position(ddx, ddy);
}

/*************************************************************************
 * Update Position
 * Update the position given a velocity and acceleration according to kinematics.
 *************************************************************************/
void updatePosition(Position & pos, Position & v, Position & a)
{
   double tpf = (24.0 * 60.0) / FRAMERATE;
   a = getGravity(pos);
   
   v.setMetersX(v.getMetersX() + a.getMetersX() * tpf);
   v.setMetersY(v.getMetersY() + a.getMetersY() * tpf);
   
   pos.setMetersX(pos.getMetersX() + v.getMetersX() * tpf + 0.5 * a.getMetersX() * tpf * tpf);
   pos.setMetersY(pos.getMetersY() + v.getMetersY() * tpf + 0.5 * a.getMetersY() * tpf * tpf);
}

double getAngle(Position & pos)
{
   double a = atan2(pos.getMetersX(),pos.getMetersY());
   return a;
}



/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //
   

   // rotate the earth
   //pDemo->angleEarth += 0.01;
   pDemo->angleEarth -= ((2.0 * M_PI) / FRAMERATE) * ((24.0 * 60.0) / 86400.0);
   
   
   
   
   pDemo->phaseStar++;

   //
   // draw everything
   //
   
   //pDemo->prevPos = pDemo->ptGPS;

   Position pt;
   ogstream gout(pt);
   
   for (auto it = pDemo->satellites.begin(); it != pDemo->satellites.end(); ++it)
   {
      (*it)->move(TIME);
      (*it)->draw(&gout);
   }
   
   //updatePosition(pDemo->ptGPS, pDemo->vGPS, pDemo->aGPS);
//   for (int i = 0; i < 6; i++)
//   {
//      pDemo->gps[i].updatePosition();
//      gout.drawGPS(pDemo->gps[i].p, pDemo->gps[i].angle);
//   }
   
   //pDemo->angleShip += getAngle(pDemo->ptGPS) - getAngle(pDemo->prevPos);

   // draw satellites
   //gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   //gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   //gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   //gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   //gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   //gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // draw parts
   /*pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set*/

   // draw fragments
   /*pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);
   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);*/

   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);
   for (int i = 0; i < STARCOUNT; i++)
   {
      pDemo->stars[i].phase++;
      gout.drawStar(pDemo->stars[i].pos, pDemo->stars[i].phase);
   }

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);
   
   ui.setFramesPerSecond(FRAMERATE);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
