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

AMADcMotor *motorRight = NULL, *motorLeft = NULL;
AMAServoMotor *servo = NULL;
AMABluetooth *bluetooth = NULL;

int cmd, dutyCycle, servoIndex, motorIndex;
ulong time_last_command;

int *directionPins = new int[2]{ DC_MOTOR_BUS_PIN_MSB, DC_MOTOR_BUS_PIN_LSB };
byte *servoDirs = new int[3] { SERVO_MOTOR_LEFT, SERVO_MOTOR_FRONT, SERVO_MOTOR_RIGHT };
byte *motorDirs = new int[3] { DC_MOTOR_FORWARD, DC_MOTOR_STOP, DC_MOTOR_BACKWARD };

bool between(int a, int x, int b);
int minValue(int x, int y);
void test_servo();

void setup()
{
    Serial.begin(DEFAULT_BAUD_RATE);
    delay(10);

	motorRight = new AMADcMotor(DC_MOTOR_RIGHT_PWM_PIN, CAR_SPEED_LOWEST_PERCENT, 2, directionPins);
	delay(100);

	motorLeft = new AMADcMotor(DC_MOTOR_LEFT_PWM_PIN, CAR_SPEED_LOWEST_PERCENT, 2, directionPins);
	delay(100);

	servo = new AMAServoMotor(SERVO_MOTOR_PWM_PIN);
	delay(100);

	bluetooth = new AMABluetooth(ARDUINO_BT_PIN_RX, ARDUINO_BT_PIN_TX);
	delay(100);

	dutyCycle = map(0,
					CAR_SPEED_LOWEST_VALUE, CAR_SPEED_HIGHEST_VALUE,
					CAR_SPEED_LOWEST_PERCENT, CAR_SPEED_HIGHEST_PERCENT);

    Serial.println("loop started");
}

void setMotorsSpeed(const byte servoValue, const byte dutyCycle) // left or right
{
	int turningDutyCycle = minValue(dutyCycle + DC_MOTOR_TURN_SPEEDUP, CAR_SPEED_HIGHEST_PERCENT);

	if(servoValue == SERVO_MOTOR_LEFT)
	{
		motorRight->setDutyCycle(turningDutyCycle);
	}
	else if(servoValue == SERVO_MOTOR_FRONT)
	{
		motorLeft->setDutyCycle(dutyCycle);
		motorRight->setDutyCycle(dutyCycle);
	}
	else if(servoValue == SERVO_MOTOR_RIGHT)
	{
		motorLeft->setDutyCycle(turningDutyCycle);
	}
}

void stopCar()
{
	servo->setDirection(SERVO_MOTOR_FRONT);
	motorLeft->setMovement(DC_MOTOR_STOP);
	motorRight->setMovement(DC_MOTOR_STOP);
}

void loop()
{
	cmd = bluetooth->receive();
	if (cmd != -1)
	{
		time_last_command = millis();
		else if (between(CAR_SPEED_LOWEST_VALUE, cmd, CAR_SPEED_HIGHEST_VALUE)) // speed command
		{
			//map(value, fromLow, fromHigh, toLow, toHigh)
			dutyCycle = map(cmd,
							CAR_SPEED_LOWEST_VALUE, CAR_SPEED_HIGHEST_VALUE,
							CAR_SPEED_LOWEST_PERCENT, CAR_SPEED_HIGHEST_PERCENT);
			setMotorsSpeed(SERVO_MOTOR_FRONT, dutyCycle);
			// motorLeft->setDutyCycle(dutyCycle);
			// motorRight->setDutyCycle(dutyCycle);
		}
		else if (between(11, cmd, 13) || between(21, cmd, 23) || between(31, cmd, 33)) // direction command
		{
			if (cmd == 22) // special case when everything needs to stop
			{
				stopCar();
			}
			else
			{
				motorIndex = (cmd / 10) - 1; // tens digit encodes direction (forward/backward)
				servoIndex = (cmd % 10) - 1; // units digit encodes steering (left/right)

				servo->setDirection(servoDirs[servoIndex]);
				motorLeft->setMovement(motorDirs[motorIndex]);
				motorRight->setMovement(motorDirs[motorIndex]);

				setMotorsSpeed(servoDirs[servoIndex], dutyCycle);
			}
		}
		else if (between(40, cmd, 41)) // front lights on/off
		{
			digitalWrite(LIGHTS_FRONT_PIN, cmd % 10);
		}
		else if (between(50, cmd, 51)) // back lights on/off
		{
			digitalWrite(LIGHTS_BACK_PIN, cmd % 10);
		}
		else if (between(60, cmd, 61)) // horn on/off
		{
			if (cmd == 60)
				noTone(BUZZER_PIN);
			else if (cmd == 61)
				tone(BUZZER_PIN, BUZZER_FREQ_HZ);
		}
	}
	// stop car when time between two consecutive commands is higher than predefined threshold
	if(millis() - time_last_comand > TIMEOUT_BETWEEN_COMMANDS_MS)
	{
		stopCar();
	}
}

bool between(int a, int x, int b)
{
	return (a <= x && x <= b);
}

int minValue(int x, int y)
{
	return ((x < y) ? x : y);
}

void test_servo()
{
	cmd = bluetooth->receive();
	if (cmd != -1)
	{
		Serial.println(cmd);
		if (cmd == 21)
		{
			servo->setDirection(SERVO_MOTOR_LEFT);
		}
		else if (cmd == 23)
		{
			servo->setDirection(SERVO_MOTOR_RIGHT);
		}
		else
		{
			servo->setDirection(SERVO_MOTOR_FRONT);
		}
	}
}
