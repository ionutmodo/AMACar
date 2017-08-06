#include "AMAOutputDataBus.h"

using namespace AMACar;

/*
 * Default constructor
 */
AMAOutputDataBus::AMAOutputDataBus(int n, ...)
{
    this->busSize = (byte) n;
    busPins = new byte[n];
    va_list list;
    va_start(list, n);
    int x;
    for(int i = 0; i < n; ++i)
    {
        x = va_arg(list, int);
        busPins[i] = (byte) x;
    }
    va_end(list);
}

/*
 * Set a value (bases 2, 8, 10, 16) value on databus
 */
void AMAOutputDataBus::setValue(byte value)
{
    for(int i = this->busSize - 1; 0 <= i; --i)
    {
        digitalWrite(busPins[i], value & 1);
        value >>= 1;
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

#if __DEBUG__
/*
 * Prints the state of the object on the serial monitor if debug mode is activated
 */
void AMAOutputDataBus::printState()
{
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
