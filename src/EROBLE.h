#ifndef EROBLELIB
#define EROBLELIB

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Module.h"
#include "PinEro.h"

class EROBLE
{
private:
    SoftwareSerial *EROSerial;
    GamePadModule *GamePadBLE;
    int8_t data[8];
    int sizeData;
    char prevCommand = 'S';

public:
    EROBLE();
    EROBLE(int pinRX, int pinTX, GamePadModule *GamePadAdd);

    void begin(PinERO myEro, GamePadModule *GamePadAdd, int baudrate);
    void begin(int baudrate);
    void write(uint8_t byte);

    virtual bool available();
    virtual int read();

    bool process();
    void processByteData();
};

#endif