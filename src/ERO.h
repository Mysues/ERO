#ifndef EROLIB
#define EROLIB

#include <Arduino.h>
#include "MOTOR.h"

class ERO
{
private:
    int motorPinSize;
    int signalPinSize;
    int _motorPin[6];
    int _signalPin[2];
    int _beeperPin;
    int _speedCtrlPin;
    MOTOR EROmotor;
    
public:
    ERO(int* motorPin,int* signalPin,int beeperPin, int speedCtrlPin);
    void begin(void);

    void leftSignal(String mode);
    void rightSignal(String mode);

    int speedCtrl(void);

    void forward(int speed);

    void test();
};



#endif