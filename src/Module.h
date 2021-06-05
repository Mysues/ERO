#ifndef Module
#define Module

typedef struct GamePadModule
{
    int data;

    bool UP = 0;
    bool DOWN = 0;
    bool LEFT = 0;
    bool RIGHT = 0;

    bool UP_LEFT = 0;
    bool UP_RIGHT = 0;
    bool DOWN_LEFT = 0;
    bool DOWN_RIGHT = 0;

    bool MOTOR_STOP = 0;

    bool BACK_LIGHT = 0;
    bool HORN = 0;

    //Extra Button for new joystick
    bool CROSS = 0;
    bool SQUARE = 0;
    bool CIRCLE = 0;
    bool TRIANGLE = 0;

    bool SELECT = 0;
    bool START = 0;
};

#endif