#include "AMAOutputDataBus.h"

using namespace AMACar;

/*
 * Default constructor
 */
AMAOutputDataBus::AMAOutputDataBus(int pinsCount, int *busPins)
{
    this->busSize = (byte)pinsCount;
    this->busPins = new byte[pinsCount];
	for (int i = 0; i < pinsCount; ++i)
		this->busPins[i] = busPins[i];
}

/*
 * Set a value (bases 2, 8, 10, 16) value on databus
 */
void AMAOutputDataBus::setValue(byte value)
{
    for(int i = this->busSize - 1; 0 <= i; --i)
    {
        digitalWrite(this->busPins[i], value & 1);
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

/*
 * Prints the state of the object on the serial monitor
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
        Serial.println(this->busPins[i]);
    }
    Serial.println();
}
