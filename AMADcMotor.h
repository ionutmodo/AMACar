#ifndef __AMAMotorController__
#define __AMAMotorController__

#include "AMAPWM.h"
#include "AMAOutputDataBus.h"

#define MOTOR_FORWARD  B10
#define MOTOR_BACKWARD B01

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
    	AMADcMotor(byte pwmPin, byte dutyCycle, AMAOutputDataBus *directionBus);
    
        /*
         * Sets the duty cycle to control turation
         */
    	void setDutyCycle(byte dutyCycle);

        /*
         * Sets the direction of the motor
         */
        void setDirection(AMAMotorDirection motorDirection);
    };
}

#endif
