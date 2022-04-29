#ifndef MOVENEOPIXEL_H
#define MOVENEOPIXEL_H

#pragma once
#include <Eigen.h>  // Calls main Eigen matrix class library
#include <Eigen/LU>  // Calls inverse, determinant, LU decomp., etc.
#include <FastLED.h>

using namespace Eigen;  // Eigen related statement; simplifies syntax for
                        // declaration of matrices


class MoveNeopixel
{
private:
CRGB (&m_A_ledStrip)[134];
Vector2d location;
Vector2d velocity;
Vector2d acceleration;
elapsedMillis msc;
int width = 30;
float topspeed;

public:
int red   = 100;
int green = 100;
int blue  = 100;
int intervall = 50;


public:

    MoveNeopixel(CRGB (&ledStrip)[134]):
    m_A_ledStrip(ledStrip),
    location(0,0),
    velocity(1,0),
    acceleration(0.01,0)
 

    {}

    void loop()
    {
        if (msc > intervall)
        {
            msc = 0; // resert imer to 0;
            
            velocity = velocity + acceleration;
            location = location + velocity;
           // int a = location.x();
           // Serial.println(a);
            if (location.x() > width)
            {
                location.x() = 0;
            }
            else if (location.x() < 0)
            {
                location.x() = width;
            }
          
        }
        int xP = location.x() ;
       
       

          // loop over the LED array:
        for (int thisLed = 0; thisLed < width; thisLed++)
        {
            // if the array element's index is less than ledLevel,
            // turn the pin for this element on:
            if (thisLed < xP)
            {
                m_A_ledStrip[thisLed].setRGB(red,green,blue);
                //m_A_ledStrip[thisLed].nscale8(255);
               
            }
            // turn off all pins higher than the ledLevel:
            else
            {
                 m_A_ledStrip[thisLed].setRGB(0,0,0);
               // m_A_ledStrip[thisLed].nscale8(0);
                  
            }
           
        }
         FastLED.show();
    }
};

#endif