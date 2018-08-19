#ifndef __AMABluetooth__
#define __AMABluetooth__

#include <SoftwareSerial.h>
#include "AMADefines.h"
#include <Arduino.h>

namespace AMACar
{
    class AMABluetooth
    {
    private:
        SoftwareSerial *bluetoothSerial;
    public:
        AMABluetooth(byte arduinoRXPin, byte arduinoTXPin);
        void send(byte data);
        void send(String string);
        int receive(void);
    };
}

#endif
