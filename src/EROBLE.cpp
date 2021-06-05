#include "EROBLE.h"

EROBLE::EROBLE()
{
}

EROBLE::EROBLE(int pinRX, int pinTX, GamePadModule *GamePadAdd)
{
    EROSerial = new SoftwareSerial(pinRX, pinTX);
    GamePadBLE = GamePadAdd;
}

void EROBLE::begin(PinERO myEro, GamePadModule *GamePadAdd, int baudrate)
{
    EROSerial = new SoftwareSerial(myEro.rx, myEro.tx);
    GamePadBLE = GamePadAdd;
    begin(baudrate);
}

void EROBLE::begin(int baudrate)
{
    EROSerial->begin(baudrate);
    sizeData = sizeof(data) / sizeof(int8_t);
}

void EROBLE::write(uint8_t byte)
{
    EROSerial->write(byte);
}

bool EROBLE::available()
{
    if (EROSerial->available() > 7)
        return true;

    return false;
}

int EROBLE::read()
{
    return EROSerial->read();
}

bool EROBLE::process()
{
    if (EROSerial->available() > 0)
    {
        char command = EROSerial->read();
        if (prevCommand != command)
        {
            switch (command)
            {
            case 'F':
                GamePadBLE->UP = 1;
                break;
            case 'B':
                GamePadBLE->DOWN = 1;
                break;
            case 'L':
                GamePadBLE->LEFT = 1;
                break;
            case 'R':
                GamePadBLE->RIGHT = 1;
                break;
            case 'G':
                GamePadBLE->UP_LEFT = 1;
                break;
            case 'I':
                GamePadBLE->UP_RIGHT = 1;
                break;
            case 'H':
                GamePadBLE->DOWN_LEFT = 1;
                break;
            case 'J':
                GamePadBLE->DOWN_RIGHT = 1;
                break;
            case 'U':
                GamePadBLE->BACK_LIGHT = 1;
                break;
            case 'u':
                GamePadBLE->BACK_LIGHT = 0;
                break;
            case 'V':
                GamePadBLE->HORN = 1;
                break;
            case 'v':
                GamePadBLE->HORN = 0;
                break;
            case 'S':
                GamePadBLE->MOTOR_STOP = 1;
                break;
            }
            switch (prevCommand)
            {
            case 'F':
                GamePadBLE->UP = 0;
                break;
            case 'B':
                GamePadBLE->DOWN = 0;
                break;
            case 'L':
                GamePadBLE->LEFT = 0;
                break;
            case 'R':
                GamePadBLE->RIGHT = 0;
                break;
            case 'G':
                GamePadBLE->UP_LEFT = 0;
                break;
            case 'I':
                GamePadBLE->UP_RIGHT = 0;
                break;
            case 'H':
                GamePadBLE->DOWN_LEFT = 0;
                break;
            case 'J':
                GamePadBLE->DOWN_RIGHT = 0;
                break;
            }
            if (command != 'S')
                GamePadBLE->MOTOR_STOP = 0;

            prevCommand = command;
            Serial.println(command);
            return true;
        }
    }
    return false;
}

void EROBLE::processByteData()
{
    for (int i = 0; i < sizeData; i++)
        data[i] = EROSerial->read();

    GamePadBLE->UP = bitRead(data[6], 0);
    GamePadBLE->DOWN = bitRead(data[6], 1);
    GamePadBLE->LEFT = bitRead(data[6], 2);
    GamePadBLE->RIGHT = bitRead(data[6], 3);

    GamePadBLE->CROSS = bitRead(data[5], 4);
    GamePadBLE->SQUARE = bitRead(data[5], 5);
    GamePadBLE->CIRCLE = bitRead(data[5], 3);
    GamePadBLE->TRIANGLE = bitRead(data[5], 2);

    GamePadBLE->SELECT = bitRead(data[5], 1);
    GamePadBLE->START = bitRead(data[5], 0);
}