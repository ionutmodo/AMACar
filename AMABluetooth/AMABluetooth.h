#ifndef __AMABluetooth__
#define __AMABluetooth__

#include <SoftwareSerial.h>

namespace AMACar
{
    class AMABluetooth
    {
    private:
        SoftwareSerial *bluetooth;
    public:
        AMABluetooth(byte rxPin, byte txPin);
        void send(byte data);
        void send(String string);
        byte receive(void);
    };
}

#endif
