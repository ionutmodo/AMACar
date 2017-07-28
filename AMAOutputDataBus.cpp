#include "AMAOutputDataBus.h"

using namespace AMACar;

/*
 * Default constructor
 */
AMAOutputDataBus::AMAOutputDataBus(void)
{
    this->built = false;
    this->busSize = 0;
    this->busPins = new byte[__ARDUINO_UNO_PINS_COUNT__];
}

/*
 * Set a value (bases 2, 8, 10, 16) value on databus
 */
void AMAOutputDataBus::setValue(byte value)
{
    if(built)
    {
        for(int i = this->busSize - 1; 0 <= i; --i)
        {
            digitalWrite(busPins[i], value & 1);
            value >>= 1;
        }
    }
}

/*
 * Sets all pins to LOW
 */
void AMAOutputDataBus::setAllLow()
{
    setValue(LOW);
}

/*
 * Sets all pins to HIGH
 */
void AMAOutputDataBus::setAllHigh()
{
    setValue(HIGH);
}

/*
 * Adds pins to pin arrays
 */
AMAOutputDataBus* AMAOutputDataBus::addPin(byte pin)
{
    if(!built && busSize < __ARDUINO_UNO_PINS_COUNT__)
    {
        busPins[busSize++] = pin;
        return this;
    }
    return NULL;
}

/*
 * Allows the buffer to be used
 */
AMAOutputDataBus* AMAOutputDataBus::build()
{
    built = true;
    for(byte i = 0; i < busSize; ++i)
    {
        pinMode(busPins[i], OUTPUT);
    }
    return this;
}

#if __DEBUG__
/*
 * Prints the state of the object on the serial monitor if debug mode is activated
 */
void AMAOutputDataBus::printState()
{
    Serial.print("Built = ");
    Serial.println(built);
    Serial.print("BusSize = ");
    Serial.println(busSize);
    for(byte i = 0; i < busSize; ++i)
    {
        Serial.print("Pin#");
        Serial.print(i);
        Serial.print(" = ");
        Serial.println(busPins[i]);
    }
    Serial.println();
}
#endif
