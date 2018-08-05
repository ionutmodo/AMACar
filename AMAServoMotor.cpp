#include "AMAServoMotor.h"

/*
 * Initializes a servo motor to be controlled through a specific pin
 */
AMAServoMotor::AMAServoMotor(byte controlPin)
{
	this->controlPin = controlPin;
	this->servo = new Servo();
	this->servo->attach(controlPin);
}

/*
 * Sets the direction of the motor
 */
void AMAServoMotor::setDirection(byte newDirection)
{
	this->servo->write(newDirection);
}
