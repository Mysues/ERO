#ifndef EROLIB
#define EROLIB

#include <Arduino.h>
#include "MOTOR.h"
#include "PinEro.h"

class ERO
{
private:
    int motorPinSize;
    int signalPinSize;
    int _motorPin[6];
    int _signalPin[2];
    int _beeperPin;
    int _speedCtrlPin;
    bool beepOn = false;
    MOTOR EROmotor;
    unsigned long pMillis;

    bool sBeeper;

    void flip();

public:
    ERO();
    ERO(int *motorPin, int *signalPin, int beeperPin, int speedCtrlPin);
    void begin(PinERO myEro);
    void begin(void);

    void beeperMs(String mode, unsigned long intervalMs);

    void beeper(String mode);
    void beeper(String mode, unsigned long intervalSec);

    void leftSignal(String mode);
    void rightSignal(String mode);

    int speedCtrl(void);

    void forward(int speed);
    void backward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);

    void stop();

    void taskFinish(void);
    void buzzer();
};

#endif