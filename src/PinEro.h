#ifndef PERO
#define PERO
#include <Arduino.h>

typedef struct _Pin{
    int L_In1 = 3;
    int L_In2 = 4;
    int L_Speed = 5;
    int R_In1 = 7;
    int R_In2 = 2;
    int R_Speed = 6;

    int L_Signal = 11;
    int R_Signal = 12;

    int beeper = 13;

    int speedCtrl = A0;
    
    int tx = 9;
    int rx = 8;

    void setLeftMotor(int LEFT_IN1,int LEFT_IN2,int LEFT_SPEED){
        L_In1 = LEFT_IN1;
        L_In2 = LEFT_IN2;
        L_Speed = LEFT_SPEED;
    };

    void setRightMotor(int RIGHT_IN1,int RIGHT_IN2,int RIGHT_SPEED){
        R_In1 = RIGHT_IN1;
        R_In2 = RIGHT_IN2;
        R_Speed = RIGHT_SPEED;
    };

    void setSignal(int LEFT_SIGNAL, int RIGHT_SIGNAL){
        L_Signal = LEFT_SIGNAL;
        R_Signal = RIGHT_SIGNAL;
    };

    void setBeeper(int BEEPER){
        beeper = BEEPER;
    };

    void setPotentiometer(int SPEED_CTRL){
        speedCtrl = SPEED_CTRL;        
    };

    void setSoftwareSerial(int TX_PIN, int RX_PIN){
        tx = TX_PIN;
        rx = RX_PIN;
    };


} PinERO;

#endif