#include "EROCore.h"
ERO::ERO()
{
}

ERO::ERO(PinERO *pinERO)
{
    this->pinERO = pinERO;
}

void ERO::setPin(int *motorPin, int *signalPin, int beeperPin, int speedCtrlPin)
{
    for (int i = 0; i < motorPinSize; i++)
        _motorPin[i] = motorPin[i];

    for (int i = 0; i < signalPinSize; i++)
        _signalPin[i] = signalPin[i];

    _beeperPin = beeperPin;
    _speedCtrlPin = speedCtrlPin;
}

void ERO::begin()
{
    setPin(pinERO->motorPin, pinERO->signalPin, pinERO->beeperPin, pinERO->speed_ctrlPin);

    for (int i = 0; i < motorPinSize; i++)
    {
        if (i == 2 || i == 5)
            pinMode(_motorPin[i], OUTPUT);
    }

    for (int i = 0; i < signalPinSize; i++)
        pinMode(_signalPin[i], OUTPUT);

    pinMode(_beeperPin, OUTPUT);
    EROmotor.begin(_motorPin);
    EROmotor.changeSpeedRatio(1);
}

void ERO::beeper(String mode)
{
    if (mode.equals("ON"))
    {
        beepOn = true;
    }
    else
    {
        beepOn = false;
        digitalWrite(_beeperPin, LOW);
    }
}

void ERO::buzzer()
{
    if (beepOn)
    {
        unsigned long cMillis = millis();
        unsigned long iFlip = cMillis - pMillis;
        if (iFlip > 0)
        {
            flip();
            pMillis = cMillis;
        }
    }
}

void ERO::beeper(String mode, unsigned long intervalSec)
{
    unsigned long interValMs = intervalSec * 1000;
    beeperMs(mode, interValMs);
}

void ERO::beeperMs(String mode, unsigned long intervalMs)
{
    unsigned long iWhile = 0;
    unsigned long pMillis = 0;
    unsigned long pFlipMillis = 0;
    pMillis = millis();
    bool loopState = 1;
    if (mode.equals("ON"))
    {
        Serial.println("Buzzer On");
        while (loopState)
        {
            unsigned long cMillis = millis();
            unsigned long iFlip = cMillis - pFlipMillis;
            if (iFlip > 0)
            {
                flip();
                pFlipMillis = cMillis;
            }

            if (cMillis - pMillis > intervalMs)
                loopState = false;
        }
        digitalWrite(_beeperPin, LOW);
    }
    else if (mode.equals("OFF"))
    {
        digitalWrite(_beeperPin, LOW);
        while (loopState)
        {
            unsigned long cMillis = millis();

            if (cMillis - pMillis > intervalMs)
                loopState = false;
        }
    }
}

void ERO::flip()
{
    sBeeper = !sBeeper;
    digitalWrite(_beeperPin, sBeeper);
}

void ERO::leftSignal(String mode)
{

    if (mode.compareTo("OFF"))
        digitalWrite(_signalPin[0], HIGH);

    else if (mode.compareTo("ON"))
        digitalWrite(_signalPin[0], LOW);
}

void ERO::rightSignal(String mode)
{

    if (mode.compareTo("OFF"))
        digitalWrite(_signalPin[1], HIGH);

    else if (mode.compareTo("ON"))
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

void ERO::stop()
{
    EROmotor.stop();
}

void ERO::forward()
{
    EROmotor.forward(255);
}

void ERO::backward()
{
    EROmotor.backward(255);
}

void ERO::turnLeft()
{
    EROmotor.turnLeft(255);
}

void ERO::turnRight()
{
    EROmotor.turnRight(255);
}

void ERO::taskFinish()
{
    EROmotor.stop();
    beeper("ON", 1);
    leftSignal("OFF");
    rightSignal("OFF");
    while (1)
        ;
}