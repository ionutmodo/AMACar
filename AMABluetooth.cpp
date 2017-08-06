 #include "AMABluetooth.h"
 
using namespace AMACar;

 AMABluetooth::AMABluetooth(byte rxPin, byte txPin)
 {
    bluetoothSerial = new SoftwareSerial(rxPin, txPin);
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

byte AMABluetooth::receive(void)
{
    if(bluetoothSerial->available())
        return bluetoothSerial->read();
    return '\0';
}

