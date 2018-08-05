#ifndef __AMAMotorController__
#define __AMAMotorController__

#include "AMAPWM.h"
#include "AMAOutputDataBus.h"
#include "AMADefines.h"
#include "AMATools.hpp"

namespace AMACar
{
    /*
     * DC Motor Controller to be used with L298N integrated circuit
     */
    class AMADcMotor
    {
    private:
    	/*
    	 * The pwm applied on the motor driver
    	 */
        AMAPWM *pwm;
    
    	/*
    	 * The direction of the motor
    	 */
        AMAOutputDataBus *directionBus;
    public:
        /*
         * Initializes a DC motor controller with to control a motor on specified 
         */
    	AMADcMotor(byte pwmPin, byte pwmDutyCycle, int busPinsCount, int *busPinsArray);
    
        /*
         * Sets the duty cycle to control turation
         */
    	void setDutyCycle(byte dutyCycle);

        /*
         * Sets the direction of the motor
         */
        void setMovement(byte newMotorMovement);
    };
}

#endif
