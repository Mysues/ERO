#include "EROBLE.h"


EROBLE::EROBLE(int pinRX,int pinTX, GamePadModule *GamePadAdd){
    EROSerial = new SoftwareSerial(pinRX,pinTX);
    GamePadBLE = GamePadAdd;
}

void EROBLE::begin(int baudrate){
    EROSerial->begin(baudrate);
    sizeData = sizeof(data)/sizeof(int);
}

void EROBLE::write(uint8_t byte){
    EROSerial->write(byte);
}

int EROBLE::available(){
    return EROSerial->available();
}

void EROBLE::process(){
    for(int i = 0; i < sizeData ;i++)
        data[i] = EROSerial->read();

    GamePadBLE->UP = bitRead(data[6],1);
    GamePadBLE->DOWN = bitRead(data[6],1);
    GamePadBLE->LEFT = bitRead(data[6],1);
    GamePadBLE->RIGHT = bitRead(data[6],1);

    GamePadBLE->CROSS = bitRead(data[7],1);
    GamePadBLE->SQUARE = bitRead(data[7],1);
    GamePadBLE->CIRCLE = bitRead(data[7],1);
    GamePadBLE->TRIANGLE = bitRead(data[7],1);

    GamePadBLE->SELECT = bitRead(data[7],1);
    GamePadBLE->START = bitRead(data[7],1);
}