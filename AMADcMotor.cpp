#include "AMADcMotor.h"

using namespace AMACar;

/*
 * Initializes a DC motor controller with to control a motor on specified 
 */
AMADcMotor::AMADcMotor(byte pwmPin, byte pwmDutyCycle, int busPinsCount, int *busPinsArray)
{
	this->directionBus = new AMAOutputDataBus(busPinsCount, busPinsArray);
    this->pwm = new AMAPWM(pwmPin, pwmDutyCycle);
    this->pwm->generate();
}

/*
 * Sets the duty cycle to control turation
 */
void AMADcMotor::setDutyCycle(byte dutyCycle)
{
    this->pwm->setDutyCycle(dutyCycle);
}

/*
 * Sets the direction of the motor
 */
void AMADcMotor::setMovement(byte newMotorMovement)
{
	this->directionBus->setValue(newMotorMovement);
}

