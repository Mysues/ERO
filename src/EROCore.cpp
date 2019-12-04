#include "EROCore.h"

ERO::ERO(int *motorPin, int *signalPin, int beeperPin, int speedCtrlPin)
{
    motorPinSize = sizeof(_motorPin) / sizeof(int);
    signalPinSize = sizeof(_signalPin) / sizeof(int);
    for (int i = 0; i < motorPinSize; i++)
        _motorPin[i] = motorPin[i];

    for (int i = 0; i < signalPinSize; i++)
        _signalPin[i] = signalPin[i];

    _beeperPin = beeperPin;
    _speedCtrlPin = speedCtrlPin;
}

void ERO::begin()
{
    for (int i = 0; i < motorPinSize; i++)
    {
        if (i == 2 || i == 5)
            pinMode(_motorPin[i], OUTPUT);
    }

    for (int i = 0; i < signalPinSize; i++)
        pinMode(_signalPin[i], OUTPUT);

    pinMode(_beeperPin, OUTPUT);
    EROmotor.begin(_motorPin);
}

void ERO::leftSignal(String mode)
{

    if (mode.compareTo("ON"))
        digitalWrite(_signalPin[0], HIGH);

    else if (mode.compareTo("OFF"))
        digitalWrite(_signalPin[0], LOW);
}

void ERO::rightSignal(String mode)
{

    if (mode.compareTo("ON"))
        digitalWrite(_signalPin[1], HIGH);

    else if (mode.compareTo("OFF"))
        digitalWrite(_signalPin[1], LOW);
}

int ERO::speedCtrl(void)
{
    int result = analogRead(_speedCtrlPin);
    result = map(result, 0, 1023, 0, 100);
    return (result);
}

void ERO::forward(int speed)
{
    double motorSpeed = 2.55 * speed;
    EROmotor.forward(motorSpeed);
}

void ERO::backward(int speed)
{
    double motorSpeed = 2.55 * speed;
    
    EROmotor.backward(motorSpeed);
}

void ERO::turnLeft(int speed)
{
    double motorSpeed = 2.55 * speed;
    EROmotor.turnLeft(motorSpeed);
}

void ERO::turnRight(int speed)
{
    double motorSpeed = 2.55 * speed;
    EROmotor.turnRight(motorSpeed);
}

void ERO::test()
{

}