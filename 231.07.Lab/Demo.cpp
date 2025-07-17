/*************************************************************
 * Header File:
 *      Demo
 * Author:
 *      Br. Helfrich, Ethan Leishman, Noah McSheehy
 * Summary:
 *      Where main is and what connects everything to run the simulation.
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "test.h"
#include "star.h"
#include "satellite.h"
#include "GPS.h"
#include "hubble.h"
#include "starlink.h"
#include "crewDragon.h"
#include "sputnik.h"
#include "ship.h"
using namespace std;

#define STARCOUNT 250
#define EARTH_RADIUS 6378000.0
#define GRAVITY 9.80665
#define FRAMERATE 30.0
#define TIME (24.0 * 60.0) / FRAMERATE

#define ROTATION -0.00701141736517  // Rotation of GPS satellites to more or less stay facing the earth

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
      angleEarth = 0.0;
      phaseStar = 0;
      
      Position shipPos;
      shipPos.setPixelsX(-450.0);
      shipPos.setPixelsY(450.0);
      satellites.push_back(new Ship(                               shipPos, Velocity(    0.0, -2000.0),  Angle(90.0), 0.0));
      satellites.push_back(new Hubble(Position(        0.0,   -42164000.0), Velocity( 3100.0,     0.0),  Angle(90.0), 0.0));
      satellites.push_back(new GPS(Position(           0.0,    26560000.0), Velocity(-3880.0,     0.0),  Angle(90.0), ROTATION));
      satellites.push_back(new GPS(Position(    23001634.72,   13280000.0), Velocity(-1940.0,  3360.18),Angle(150.0), ROTATION));
      satellites.push_back(new GPS(Position(    23001634.72,  -13280000.0), Velocity( 1940.0,  3360.18), Angle(30.0), ROTATION));
      satellites.push_back(new GPS(Position(           0.0,   -26560000.0), Velocity( 3880.0,     0.0), Angle(270.0), ROTATION));
      satellites.push_back(new GPS(Position(    -23001634.72, -13280000.0), Velocity( 1940.0, -3360.18),Angle(330.0), ROTATION));
      satellites.push_back(new GPS(Position(    -23001634.72,  13280000.0), Velocity(-1940.0, -3360.18),Angle(210.0), ROTATION));
      satellites.push_back(new Sputnik(Position(-36515095.13,  21082000.0), Velocity( 2050.0,  2684.68), Angle(90.0), 0.0));
      satellites.push_back(new CrewDragon(Position(     0.0,    8000000.0), Velocity(-7900.0,     0.0),  Angle(90.0), 0.0));
      satellites.push_back(new Starlink(Position(       0.0,  -13020000.0), Velocity( 5800.0,     0.0),  Angle(90.0), 0.0));
   }

   
   double computeDistance(Position pos1, Position pos2)
   {
      double x = pos1.getPixelsX() - pos2.getPixelsX();
      double y = pos1.getPixelsY() - pos2.getPixelsY();
      double c = sqrt((x * x) + (y * y));
      return c;
   }
   
   void move()
   {
      for (auto it = satellites.begin(); it != satellites.end(); it++)
         (*it)->move(TIME);
      
      for (auto it1 = satellites.begin(); it1 != satellites.end(); it1++)
      {
         // check collision with the earth
         double distance = computeDistance((*it1)->getPosition(), Position(0.0, 0.0));
         if (distance < ((*it1)->getRadius() + 50))
            (*it1)->kill();
         
         // check collision with other satellites
         for (auto it2 = next(it1); it2 != satellites.end(); it2++)
            if ((*it1)->isDead() == false && (*it2)->isDead() == false)
            {
               distance = computeDistance((*it1)->getPosition(), (*it2)->getPosition());
               if (distance < ((*it1)->getRadius() + (*it2)->getRadius()))
               {
                  (*it1)->kill();
                  (*it2)->kill();
               }
            }
      }
      
      // clean up zombies
      for (auto it = satellites.begin(); it != satellites.end(); it++)
         if ((*it)->isDead())
         {
            (*it)->destroy(satellites);
            delete (*it);
            it = satellites.erase(it);
         }
   }
   
   Position ptUpperRight;
   
   list<Satellite*> satellites;

   unsigned char phaseStar;
   Star stars[STARCOUNT];

   double angleEarth;
};





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
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth -= ((2.0 * M_PI) / FRAMERATE) * ((24.0 * 60.0) / 86400.0);
   
   pDemo->phaseStar++;

   Position pt;
   ogstream gout(pt);
   
   // draw stars
   for (int i = 0; i < STARCOUNT; i++)
   {
      pDemo->stars[i].phase++;
      gout.drawStar(pDemo->stars[i].pos, pDemo->stars[i].phase);
   }
   
   // give input to satellites
   for (auto it = pDemo->satellites.begin(); it != pDemo->satellites.end(); ++it)
      (*it)->input(pUI, pDemo->satellites, TIME);
   
   // move everything
   pDemo->move();
   
   // draw satellites
   for (auto it = pDemo->satellites.begin(); it != pDemo->satellites.end(); ++it)
      (*it)->draw(&gout);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

#include <thread> // For std::this_thread
#include <chrono> // For std::chrono::milliseconds, etc.

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
   std::this_thread::sleep_for(std::chrono::seconds(1));

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
