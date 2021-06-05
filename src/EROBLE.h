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
    PinERO *pinERO;
    int8_t data[8];
    int sizeData;
    char prevCommand = 'S';

public:
    EROBLE();
    EROBLE(PinERO *pinERO, GamePadModule *GamePadAdd);

    void begin(int baudrate);
    void write(uint8_t byte);

    virtual bool available();
    virtual int read();

    bool process();
    void processByteData();
};

#endif