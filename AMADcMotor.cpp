#include "AMADcMotor.h"

using namespace AMACar;

/*
 * Initializes a DC motor controller with to control a motor on specified 
 */
AMADcMotor::AMADcMotor(byte pwmPin, byte dutyCycle, AMAOutputDataBus *directionBus)
{
    this->directionBus = directionBus;
    this->pwm = new AMAPWM(pwmPin, dutyCycle);
    this->pwm->generate();
}

/*
 * Sets the duty cycle to control turation
 */
void AMADcMotor::setDutyCycle(byte dutyCycle)
{
    pwm->setDutyCycle(dutyCycle);
}

/*
 * Sets the direction of the motor
 */
void AMADcMotor::setDirection(AMAMotorDirection motorDirection)
{
    directionBus->setValue(motorDirection);
}

