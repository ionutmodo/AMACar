#ifndef __AMAPWM__
#define __AMAPWM__

#include "AMADefines.h"

namespace AMACar
{
    /*
     * Represents a PWM generator
     */
    class AMAPWM
    {
    private:
        /*
         * The pin which generates the pwm
         */
        byte pin;
    
        /*
         * The duty cycle of pwm
         */
        byte dutyCycle;
        
    public:
    
        /*
         * Initializes a PWM with a specified duty cycle on a specified pin
         */
        AMAPWM(byte pin, byte dutyCycle);
    
        /*
         * Sets a new pin for PWM
         */
        void setPin(byte pin);
    
        /*
         * Sets a new duty cycle
         */
        void setDutyCycle(byte dutyCycle);
        
        /*
         * Generates the PWM 
         */
        void generate();
    };
}

#endif

