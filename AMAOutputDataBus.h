#ifndef __AMAbus__
#define __AMAbus__

#include <stdio.h>
#include <Arduino.h>
#include "AMADefines.h"
#include "AMATools.hpp"

namespace AMACar
{
    /*
     * Represents a data bus
     */
    class AMAOutputDataBus
    {        
        /*
         * Holds bus pins
         */
        byte *busPins;
    
        /*
         * Number of pins in bus
         */
         byte busSize;
    public:
        
        /*
         * Default constructor
         */
        AMAOutputDataBus(int n, ...);
    
        /*
         * Set a value (bases 2, 8, 10, 16) value on databus
         */
        void setValue(byte value);
    
        /*
         * Sets all pins to LOW
         */
        void setAllLow();
        
        /*
         * Sets all pins to HIGH
         */
        void setAllHigh();
    
         #if __DEBUG__
         /*
          * Prints the state of the object on the serial monitor if debug mode is activated
          */
         void printState();
         #endif
    };
}

#endif
