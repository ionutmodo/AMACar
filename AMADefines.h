#ifndef __AMADefines__
#define __AMADefines__

#include <Arduino.h>

typedef unsigned char byte;
typedef unsigned long ulong;

#define DEBUG 0

#define SECOND_HALF_MS 500
#define SECOND_FULL_MS 1000

#define TIMEOUT_BETWEEN_COMMANDS_MS 5000

#define DC_MOTOR_FORWARD  B10
#define DC_MOTOR_BACKWARD B01
#define DC_MOTOR_STOP B11

#define DC_MOTOR_BUS_PIN_LSB 2
#define DC_MOTOR_BUS_PIN_MSB 4

#define DC_MOTOR_RIGHT_PWM_PIN 3
#define DC_MOTOR_LEFT_PWM_PIN 5

// if car turns left, then increase right motors pwm with this value
// if car turns right, then increase left motors pwm with this value
#define DC_MOTOR_TURN_SPEEDUP 10 // percent

#define SERVO_MOTOR_LEFT 135
#define SERVO_MOTOR_FRONT 95
#define SERVO_MOTOR_RIGHT 55

#define SERVO_MOTOR_PWM_PIN 9

#define ARDUINO_BT_PIN_TX 11
#define ARDUINO_BT_PIN_RX 12

#define DEFAULT_BAUD_RATE 9600

// arduino duty cycle min/max percents
#define CAR_SPEED_LOWEST_PERCENT 40
#define CAR_SPEED_HIGHEST_PERCENT 100

// android seek bar min/max values
#define CAR_SPEED_LOWEST_VALUE 0
#define CAR_SPEED_HIGHEST_VALUE 10

#define LIGHTS_FRONT_PIN 6
#define LIGHTS_BACK_PIN 7

#define BUZZER_PIN 8
#define BUZZER_FREQ_HZ 1000

#endif

/*
+-------+
|   ^   |
|<     >|
|   v	|
+-------+


+--------+
|11 12 13|
|21 22 23|
|31 32 33|
+--------+
*/