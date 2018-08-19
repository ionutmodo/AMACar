#ifndef __AMADefines__
#define __AMADefines__

#include <Arduino.h>

typedef unsigned char byte;

#define HALF_SECOND 500
#define ONE_SECOND 1000

#define DC_MOTOR_FORWARD  B10
#define DC_MOTOR_BACKWARD B01
#define DC_MOTOR_STOP B11
#define DC_MOTOR_PWM_PIN 3
#define DC_MOTOR_BUS_PIN_MSB 4
#define DC_MOTOR_BUS_PIN_LSB 2

#define SERVO_MOTOR_LEFT 180
#define SERVO_MOTOR_FRONT 90
#define SERVO_MOTOR_RIGHT 0
#define SERVO_MOTOR_PWM_PIN 9

#define ARDUINO_BT_PIN_TX 11
#define ARDUINO_BT_PIN_RX 12

#define DEFAULT_BAUD_RATE 19200

// arduino duty cycle min/max percents
#define CAR_SPEED_LOWEST_PERCENT 30
#define CAR_SPEED_HIGHEST_PERCENT 100

// android seek bar min/max values
#define CAR_SPEED_LOWEST_VALUE 0
#define CAR_SPEED_HIGHEST_VALUE 10

#endif
