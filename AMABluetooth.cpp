 #include "AMABluetooth.h"
 
using namespace AMACar;

 AMABluetooth::AMABluetooth(byte arduinoRXPin, byte arduinoTXPin)
 {
    bluetoothSerial = new SoftwareSerial(arduinoRXPin, arduinoTXPin);
    bluetoothSerial->begin(DEFAULT_BAUD_RATE);
 }
 
void AMABluetooth::send(byte data)
{
    bluetoothSerial->write(data);
    delay(5);
}

void AMABluetooth::send(String string)
{
    for(int i = 0; i < string.length(); ++i)
        send(string[i]);
}

int AMABluetooth::receive(void)
{
	return bluetoothSerial->read();
    /*if(bluetoothSerial->available())
        return bluetoothSerial->read();
    return NULL;*/
}

