/*
 * 30% - cea mai mica viteza
 * 100% - cea mai mare viteza
 * 0, 1, 2 - stanga dreapta
 */

#include "AMADefines.h"
#include "AMADcMotor.h"
#include "AMAServoMotor.h"

using namespace AMACar;

AMADcMotor *motor = NULL;
AMAServoMotor *servo = NULL;
int speed = 0;

void setup()
{
    Serial.begin(9600);
    delay(10);
	motor = new AMADcMotor(DC_MOTOR_PWM_PIN, 50, 2, new int[2] { DC_MOTOR_BUS_PIN_MSB, DC_MOTOR_BUS_PIN_LSB });
	motor->setMovement(DC_MOTOR_FORWARD);

	servo = new AMAServoMotor(SERVO_MOTOR_PWM_PIN);
	servo->setDirection(SERVO_MOTOR_FRONT);

    Serial.println("running loop");
}

void loop()
{
    if(Serial.available() > 0)
    {
      speed = (Serial.read() - '0');
      if(speed < 3)
      {
        Serial.print("dir=");
        Serial.println(speed * 90);
        servo->setDirection(speed * 90);
      }
      else
      {
        speed = (speed + 1) * 10;
		motor->setDutyCycle(speed);

        Serial.print("spd=");
        Serial.println(speed);
      }
    }
}
