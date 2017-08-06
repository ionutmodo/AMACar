#ifndef __AMABluetooth__
#define __AMABluetooth__

#include <SoftwareSerial.h>
#include "AMADefines.h"
#include "AMATools.hpp"

namespace AMACar
{
    class AMABluetooth
    {
    private:
        SoftwareSerial *bluetoothSerial;
    public:
        AMABluetooth(byte rxPin, byte txPin);
        void send(byte data);
        void send(String string);
        byte receive(void);
    };
}

#endif
