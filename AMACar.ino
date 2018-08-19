/*
 * 30% - cea mai mica viteza
 * 100% - cea mai mare viteza
 * 0, 1, 2 - stanga dreapta
 */

#include "AMADefines.h"
#include "AMADcMotor.h"
#include "AMAServoMotor.h"
#include "AMABluetooth.h"

using namespace AMACar;

AMADcMotor *motor = NULL;
AMAServoMotor *servo = NULL;
AMABluetooth *bluetooth = NULL;
int cmd, dutyCycle, steeringValue, directionValue;

bool between(int a, int x, int b);

void setup()
{
    Serial.begin(9600);
    delay(10);

	motor = new AMADcMotor(DC_MOTOR_PWM_PIN, 50, 2, new int[2] { DC_MOTOR_BUS_PIN_MSB, DC_MOTOR_BUS_PIN_LSB });
	motor->setMovement(DC_MOTOR_FORWARD);
	delay(10);

	servo = new AMAServoMotor(SERVO_MOTOR_PWM_PIN);
	servo->setDirection(SERVO_MOTOR_FRONT);
	delay(10);

	bluetooth = new AMABluetooth(ARDUINO_BT_PIN_RX, ARDUINO_BT_PIN_TX);
	delay(10);

    Serial.println("running loop");
}

void loop()
{
	cmd = bluetooth->receive();
	if (cmd != NULL)
	{
		if (between(0, cmd, 10)) // speed command
		{
			//map(value, fromLow, fromHigh, toLow, toHigh)
			dutyCycle = map(cmd, CAR_SPEED_LOWEST_VALUE, CAR_SPEED_HIGHEST_VALUE, CAR_SPEED_LOWEST_PERCENT, CAR_SPEED_HIGHEST_PERCENT);
			motor->setDutyCycle(dutyCycle);
		}
		else if (between(11, cmd, 13) || between(21, cmd, 23) || between(31, cmd, 33)) // direction command
		{
			if (cmd == 22)
				motor->setMovement(DC_MOTOR_STOP);
			else
			{
				steeringValue = cmd % 10;
				if (steeringValue == 1)
					servo->setDirection(SERVO_MOTOR_LEFT);
				else if(steeringValue == 2)
					servo->setDirection(SERVO_MOTOR_FRONT);
				else if(steeringValue == 3)
					servo->setDirection(SERVO_MOTOR_RIGHT);

				directionValue = cmd / 10;
				if (directionValue == 1)
					motor->setMovement(DC_MOTOR_FORWARD);
				else if (directionValue == 2)
					motor->setMovement(DC_MOTOR_STOP);
				else if (directionValue == 3)
					motor->setMovement(DC_MOTOR_BACKWARD);
			}
		}
		else if (between(40, cmd, 41)) // front lights on/off
		{

		}
		else if (between(50, cmd, 51)) // back lights on/off
		{

		}
		else if (between(60, cmd, 61)) // horn on/off
		{

		}
	}
}

bool between(int a, int x, int b)
{
	return (a <= x && x <= b);
}