//
//  star.h
//  Lab07
//
//  Created by Ethan Leishman on 6/3/25.
//

#pragma once

#include <iostream>
#include <cmath>
#include "uiDraw.h"
#include "position.h"

class Star
{
public:
   Position pos;
   unsigned char phase;
   
   Star()
   {
      pos.setPixelsX(random(-500.0, 500.0));
      pos.setPixelsY(random(-500.0, 500.0));
      phase = random(0, 255);
   }
};
