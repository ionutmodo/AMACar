#pragma once

#include <Servo.h>
#include "AMADefines.h"

namespace AMACar
{
	/*
	 * Servo motor controller	
	 */
	class AMAServoMotor
	{
	private:
		/*
		 * Pin number to be used to control the motor through
		 */
		byte controlPin;

		/*
		 * Servo motor object
		 */
		Servo *servo;
	public:
		/*
		 * Initializes a servo motor to be controlled through a specific pin
		 */
		AMAServoMotor(byte controlPin);

		/*
		 * Sets the direction of the motor
		 */
		void setDirection(byte newDirection);
	};
}