/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich, Ethan Leishman, Noah McSheehy
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testAcceleration.h"
#include "testAngle.h"
#include "testSatellite.h"
#include "testGPS.h"
#include "testHubble.h"
#include "testStarlink.h"
#include "testCrewDragon.h"
#include "testSputnik.h"
#include "testShip.h"
#include "testPart.h"
#include "testProjectile.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   TestPosition().run();
   TestVelocity().run();
   TestAcceleration().run();
   TestAngle().run();
   TestSatellite().run();
   TestGPS().run();
   TestHubble().run();
   TestStarlink().run();
   TestCrewDragon().run();
   TestSputnik().run();
   TestShip().run();
   TestPart().run();
   TestProjectile().run();
}
