#include "AMAPWM.h"

using namespace AMACar;

/*
 * Generates a PWM with a specified duty cycle on a specified pin
 */
AMAPWM::AMAPWM(byte pin, byte dutyCycle)
{
    this->pin = pin;
    this->dutyCycle = dutyCycle;
    pinMode(pin, OUTPUT);
}

/*
 * Sets a new pin for PWM
 */
void AMAPWM::setPin(byte pin)
{
    if(this->pin != pin)
    {
        digitalWrite(this->pin, LOW);
        this->pin = pin;
        pinMode(pin, OUTPUT);
        generate();
    }
}

/*
 * Sets a new duty cycle
 */
void AMAPWM::setDutyCycle(byte dutyCycle)
{
    if(this->dutyCycle != dutyCycle)
    {
        this->dutyCycle = dutyCycle;
        generate();
    }
}

/*
 * Generates the PWM 
 */
void AMAPWM::generate()
{
    analogWrite(pin, LOW);
    delay(5);
    byte byteValue = (byte) (2.55f * dutyCycle);
    analogWrite(pin, byteValue);
}

