/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include "position.h"
#include "unitTest.h"

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_default();
      construct_nonDefault();
      construct_copy();
      assign();
 
      // Setters
      setMetersX();
      setMetersY();
      
      // Getters
      getMetersX();
      getMetersY();
      
      setZoom_member();
      setZoom_anotherVariable();
      getZoom_member();
      getZoom_anotherVariable();
      setPixelsX_noZoom();
      setPixelsX_zoom();
      setPixelsY_noZoom();
      setPixelsY_zoom();
      getPixelsX_noZoom();
      getPixelsX_zoom();
      getPixelsY_noZoom();
      getPixelsY_zoom();
      
      addMetersX();
      addMetersY();
      addPixelsX_noZoom();
      addPixelsX_zoom();
      addPixelsY_noZoom();
      addPixelsY_zoom();

      report("Position");
   }
   
private:

   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(0, 0))
    *********************************************/
   void construct_default()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      // exercise
      Position pos;
      // verify
      assertEquals(pos.x, 0.0);
      assertEquals(pos.y, 0.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   x=120.0, y=360.0
    * output:  pos=(120.0, 360.0)
    *********************************************/
   void construct_nonDefault()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      double x = 120.0;
      double y = 360.0;
      // exercise
      Position pos(x, y);
      // verify
      assertEquals(pos.x, 120.0);
      assertEquals(pos.y, 360.0);
      assertEquals(pos.metersFromPixels, 99.9);
      assertEquals(x, 120.0);
      assertEquals(y, 360.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    COPY CONSTRUCTOR
    * input:   posRHS = (1234.5, 6789.0)
    * output:  pos = (1234.5, 6789.0)
    *********************************************/
   void construct_copy()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position posRHS;
      posRHS.x = 1234.5;
      posRHS.y = 6789.0;
      // exercise
      Position pos(posRHS);
      // verify
      assertEquals(posRHS.x, 1234.5);
      assertEquals(posRHS.y, 6789.0);
      assertEquals(posRHS.metersFromPixels, 99.9);
      assertEquals(pos.x, 1234.5);
      assertEquals(pos.y, 6789.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ASSIGNMENT OPERATOR
    * input:   posLHS=(-99.9, -88.8)  posRHS=(24.68, -13,57)
    * output:  posLHS=(24.68, -13,57)
    *********************************************/
   void assign()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position posLHS;
      posLHS.x = -99.9;
      posLHS.y = -88.8;
      Position posRHS;
      posRHS.x = 24.68;
      posRHS.y = -13.57;
      // exercise
      posLHS = posRHS;
      // verify
      assertEquals(posRHS.x, 24.68);
      assertEquals(posRHS.y, -13.57);
      assertEquals(posRHS.metersFromPixels, 99.9);
      assertEquals(posLHS.x, 24.68);
      assertEquals(posLHS.y, -13.57);
      assertEquals(posLHS.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   /*********************************************
    * name:    GET METERS X
    * input:   pos=(4500.0, 2500.0)
    * output:  x=4500.0
    *********************************************/
   void getMetersX()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double x = pos.getMetersX();
      // verify
      assertEquals(x, 4500.0);
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2500.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET METERS Y
    * input:   pos=(4500.0, 2500.0)
    * output:  y=4500.0
    *********************************************/
   void getMetersY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double y = pos.getMetersY();
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2500.0);
      assertEquals(pos.metersFromPixels, 99.9);
      assertEquals(y, 2500.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    SET METERS Y
    * input:   pos=(999.9, 888.8) x = 123.4
    * output:  pos=(123.4, 888.8)
    *********************************************/
   void setMetersX()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      // exercise
      pos.setMetersX(123.4);
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 888.8);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET METERS Y ZOOM
    * input:   pos=(999.9, 888.8) y = 123.4
    * output:  pos=(999.9, 123.4)
    *********************************************/
   void setMetersY()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      // exercise
      pos.setMetersY(123.4);
      // verify
      assertEquals(pos.x, 999.9);
      assertEquals(pos.y, 123.4);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   
   /*********************************************
    * name:    GET ZOOM : member variable
    * input:   pos.metersFromPixels=123.4
    * output:  zoom=123.4
    *          Position::metersFromPixels=123.4
    *********************************************/
   void getZoom_member()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position pos;
      pos.metersFromPixels = 123.4;
      double zoom = 0.0;
      
      // exercise
      zoom = pos.getZoom();
      
      // verify
      assertEquals(pos.metersFromPixels, 123.4);
      assertEquals(zoom, 123.4);
      assertEquals(Position::metersFromPixels, 123.4);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   /*********************************************
    * name:    GET ZOOM : another variable
    * input:   pos1.metersFromPixels=99.9  (set this first)
    *          pos2.metersFromPixels=123.4 (set this second)
    * output:  zoom=123.4
    *          pos1.metersFromPixels=123.4 (last assignment sticks)
    *          pos2.metersFromPixels=123.4
    *********************************************/
   void getZoom_anotherVariable()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position pos1;
      Position pos2;
      pos1.metersFromPixels = 99.9;
      pos2.metersFromPixels = 123.4;
      double zoom = 0.0;
      
      // exercise
      zoom = pos1.getZoom();
      
      // verify
      assertEquals(pos1.metersFromPixels, 123.4);
      assertEquals(pos2.metersFromPixels, 123.4);
      assertEquals(zoom, 123.4);
      assertEquals(Position::metersFromPixels, 123.4);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET METERS X NO ZOOM
    * input:   pos=(123.4, 567.8) metersFromPixels=1
    * output:  x=123.4
    *********************************************/
   void getPixelsX_noZoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 1.0;
      Position pos;
      pos.x = 123.4;
      pos.y = 567.8;
      double x = 0.0;
      
      // exercise
      x = pos.getPixelsX();
      
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 567.8);
      assertEquals(x, 123.4);
      assertEquals(pos.metersFromPixels, 1.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   /*********************************************
    * name:    GET PIXELS X ZOOM
    *          pixels = meters / metersFromPixels
    * input:   pos=(123.4, 567.8) metersFromPixels=100
    * output:  x=1.234
    *********************************************/
   void getPixelsX_zoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 100.0;
      Position pos;
      pos.x = 123.4;
      pos.y = 567.8;
      double x = 0.0;
      
      // exercise
      x = pos.getPixelsX();
      
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 567.8);
      assertEquals(x, 1.234);
      assertEquals(pos.metersFromPixels, 100.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET PIXELS Y NO ZOOM
    * input:   pos=(123.4, 567.8) metersFromPixels=1
    * output:  y=567.8
    *********************************************/
   void getPixelsY_noZoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 1.0;
      Position pos;
      pos.x = 123.4;
      pos.y = 567.8;
      double y = 0.0;
      
      // exercise
      y = pos.getPixelsY();
      
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 567.8);
      assertEquals(y, 567.8);
      assertEquals(pos.metersFromPixels, 1.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET PIXELS Y ZOOM
    * input:   pos=(123.4, 567.8) metersFromPixels=100
    * output:  y=5.678
    *********************************************/
   void getPixelsY_zoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 100.0;
      Position pos;
      pos.x = 123.4;
      pos.y = 567.8;
      double y = 0.0;
      
      // exercise
      y = pos.getPixelsY();
      
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 567.8);
      assertEquals(y, 5.678);
      assertEquals(pos.metersFromPixels, 100.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   /*********************************************
    * name:    SET PIXELS X NO ZOOM
    *          When meterFromPixels == 1, pixels and meters are the same
    * input:   pos=(999.9, 888.8) x=123.4 meterFromPixels=1
    * output:  pos=(123.4, 888.8)
    *********************************************/
   void setPixelsX_noZoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 1.0;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      double x = 123.4;
      
      // exercise
      pos.setPixelsX(x);
      
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 888.8);
      assertEquals(x, 123.4);
      assertEquals(pos.metersFromPixels, 1.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    SET PIXELS X ZOOM
    *          meters = pixels * metersFromPixels
    * input:   pos=(999.9, 888.8) x=123.4 meterFromPixels=100
    * output:  pos=(12340.0, 888.8)
    *********************************************/
   void setPixelsX_zoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 100.0;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      double x = 123.4;
      
      // exercise
      pos.setPixelsX(x);
      
      // verify
      assertEquals(pos.x, 12340.0);
      assertEquals(pos.y, 888.8);
      assertEquals(x, 123.4);
      assertEquals(pos.metersFromPixels, 100.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   /*********************************************
    * name:    SET PIXELS Y NO ZOOM
    * input:   pos=(999.9, 888.8) y=123.4 meterFromPixels=1
    * output:  pos=(999.9, 123.4)
    *********************************************/
   void setPixelsY_noZoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 1.0;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      double y = 123.4;
      
      // exercise
      pos.setPixelsY(y);
      
      // verify
      assertEquals(pos.x, 999.9);
      assertEquals(pos.y, 123.4);
      assertEquals(y, 123.4);
      assertEquals(pos.metersFromPixels, 1.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    SET PIXELS Y ZOOM
    * input:   pos=(999.9, 888.8) y=123.4 meterFromPixels=100
    * output:  pos=(999.9, 12340.0)
    *********************************************/
   void setPixelsY_zoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 100.0;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      double y = 123.4;
      
      // exercise
      pos.setPixelsY(y);
      
      // verify
      assertEquals(pos.x, 999.9);
      assertEquals(pos.y, 12340.0);
      assertEquals(y, 123.4);
      assertEquals(pos.metersFromPixels, 100.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   /*********************************************
    * name:    ADD METERS X
    * input:   pos=(4500,2500) x=123.4
    * output:  pos=(4623.4,2500)
    *********************************************/
   void addMetersX()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      double x = 123.4;
      
      // exercise
      pos.addMetersX(x);
      
      // verify
      assertEquals(pos.x, 4623.4);
      assertEquals(pos.y, 2500.0);
      assertEquals(x, 123.4);
      assertEquals(pos.metersFromPixels, 99.9);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ADD METERS Y
    * input:   pos=(4500,2500) y=123.4
    * output:  pos=(4500,2623.4)
    *********************************************/
   void addMetersY()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      double y = 123.4;
      
      // exercise
      pos.addMetersY(y);
      
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2623.4);
      assertEquals(y, 123.4);
      assertEquals(pos.metersFromPixels, 99.9);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ADD PIXELS X ZERO ZOOM
    * input:   pos=(4500,2500) x=3pixels meterFromPixels=1.0
    * output:  pos=(4503,2500)
    *********************************************/
   void addPixelsX_noZoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 1.0;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      double x = 3.0;
      
      // exercise
      pos.addPixelsX(x);
      
      // verify
      assertEquals(pos.x, 4503.0);
      assertEquals(pos.y, 2500.0);
      assertEquals(x, 3.0);
      assertEquals(pos.metersFromPixels, 1.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ADD PIXELS X ZOOM
    * input:   pos=(4500,2500) x=3pixels meterFromPixels=50.0
    * output:  pos=(4650,2500)
    *********************************************/
   void addPixelsX_zoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 50.0;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      double x = 3.0;
      
      // exercise
      pos.addPixelsX(x);
      
      // verify
      assertEquals(pos.x, 4650.0);
      assertEquals(pos.y, 2500.0);
      assertEquals(x, 3.0);
      assertEquals(pos.metersFromPixels, 50.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ADD PIXELS Y ZERO ZOOM
    * input:   pos=(4500,2500) y=3pixels meterFromPixels=1.0
    * output:  pos=(4500,2503)
    *********************************************/
   void addPixelsY_noZoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 1.0;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      double y = 3.0;
      
      // exercise
      pos.addPixelsY(y);
      
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2503.0);
      assertEquals(y, 3.0);
      assertEquals(pos.metersFromPixels, 1.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ADD PIXELS Y ZOOM
    * input:   pos=(4500,2500) y=3pixels meterFromPixels=50.0
    * output:  pos=(4500,2650)
    *********************************************/
   void addPixelsY_zoom()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 50.0;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      double y = 3.0;
      
      // exercise
      pos.addPixelsY(y);
      
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2650.0);
      assertEquals(y, 3.0);
      assertEquals(pos.metersFromPixels, 50.0);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   /*********************************************
    * name:    SET ZOOM : member variable
    * input:   pos.metersFromPixels = 99.9, setZoom(123.4)
    * output:  pos.metersFromPixels=123.4
    *          Position::metersFromPixels=123.4
    *********************************************/
   void setZoom_member()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.metersFromPixels = 99.9;
      
      // exercise
      pos.setZoom(123.4);
      
      // verify
      assertEquals(pos.metersFromPixels, 123.4);
      assertEquals(Position::metersFromPixels, 123.4);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    SET ZOOM : another variable
    * input:   pos1.metersFromPixels=99.9
    *          pos2.metersFromPixels=88.9
    *          pos2.setZoom(123.4)
    * output:  pos1.metersFromPixels=123.4
    *          pos2.metersFromPixels=123.4
    *          Position::metersFromPixels=123.4
    *********************************************/
   void setZoom_anotherVariable()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position pos1;
      Position pos2;
      pos1.metersFromPixels = 99.9;
      pos2.metersFromPixels = 88.9;
      
      // exercise
      pos2.setZoom(123.4);
      
      // verify
      assertEquals(pos1.metersFromPixels, 123.4);
      assertEquals(pos2.metersFromPixels, 123.4);
      assertEquals(Position::metersFromPixels, 123.4);
      
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

};
