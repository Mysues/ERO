#ifndef EROBLELIB
#define EROBLELIB

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Module.h"


class EROBLE
{
private:

    SoftwareSerial *EROSerial;
    GamePadModule *GamePadBLE;
    int8_t data[8];
    int sizeData;

public:
    EROBLE(int pinRX,int pinTX,GamePadModule *GamePadAdd);

    void begin(int baudrate);
    void write(uint8_t byte);

    virtual int available();

    void process();

};

#endif