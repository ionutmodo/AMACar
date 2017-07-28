#include "AMAOutputDataBus.h"
#include "AMADefines.h"
#include "AMADcMotor.h"
#include "AMAPWM.h"

using namespace AMACar;

AMADcMotor *dcMotor = NULL;
byte dutyCycle;

//AMAPWM *pwm = new AMAPWM(9, 25);

void setup()
{
    dutyCycle = 0;
    dcMotor = new AMADcMotor(9, 50, (new AMAOutputDataBus())->addPin(8)->addPin(7)->build());
    dcMotor->setDirection(MOTOR_FORWARD);
    Serial.begin(9600);
    //pwm->generate();
}

void loop()
{
    if(Serial.available())
    {
        char c = Serial.read();
        dcMotor->setDutyCycle((c - '0') * 10);
    }
}
