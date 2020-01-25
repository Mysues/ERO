#include "EROBLE.h"

EROBLE::EROBLE(){
    
}

EROBLE::EROBLE(int pinRX,int pinTX, GamePadModule *GamePadAdd){
    EROSerial = new SoftwareSerial(pinRX,pinTX);
    GamePadBLE = GamePadAdd;
}

void EROBLE::begin(PinERO myEro, GamePadModule *GamePadAdd, int baudrate){
    EROSerial = new SoftwareSerial(myEro.rx,myEro.tx);
    GamePadBLE = GamePadAdd;
    begin(baudrate);
}

void EROBLE::begin(int baudrate){
    EROSerial->begin(baudrate);
    sizeData = sizeof(data)/sizeof(int8_t);
}

void EROBLE::write(uint8_t byte){
    EROSerial->write(byte);
}

int EROBLE::available(){
    return EROSerial->available();
}

int EROBLE::read(){
    return EROSerial->read();
}

void EROBLE::process(){
    for(int i = 0; i < sizeData ;i++)
        data[i] = EROSerial->read();
    
    GamePadBLE->UP = bitRead(data[6],0);
    GamePadBLE->DOWN = bitRead(data[6],1);
    GamePadBLE->LEFT = bitRead(data[6],2);
    GamePadBLE->RIGHT = bitRead(data[6],3);

    GamePadBLE->CROSS = bitRead(data[5],4);
    GamePadBLE->SQUARE = bitRead(data[5],5);
    GamePadBLE->CIRCLE = bitRead(data[5],3);
    GamePadBLE->TRIANGLE = bitRead(data[5],2);

    GamePadBLE->SELECT = bitRead(data[5],1);
    GamePadBLE->START = bitRead(data[5],0);
}