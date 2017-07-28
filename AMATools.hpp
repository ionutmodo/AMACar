#ifndef __AMATools__
#define __AMATools__

#include <Arduino.h>
#include "AMADefines.h"

namespace AMACar
{
    /*
     * Class with static methods to be used anywhere in program
     */
    class AMATools
    {
    public:
        static bool isValidPWMPin(byte pin)
        {
            #ifdef __ARDUINO_UNO__ == true
                const byte count = 6;
                byte pins[] = {3, 5, 6, 9, 10, 11};
                for(byte i = 0; i < count; ++i)
                {
                    if(pin == pins[i])
                    {
                        return true;
                    }
                }
                return false;
            #endif
            return false;
        }
    };
}

#endif
