# ERO
This repo is dedicated for ERO library. ERO is stand for Easy Robotic, as the name show serve the purpose of this library.  Hopefully ERO library will help those who would like to getting started in basic mobile robot. Those who would like to use this as a template for mobile robot library for your team / institution / school are welcome.

# EROCore CLASS (ERO.h)
## Constructor
ERO::ERO(int* motorPin,int* signalPin,int beeperPin, int speedCtrlPin)

## Method
void begin(void)
void beeperMs(String mode, unsigned long intervalMs)
void beeper(String mode, unsigned long intervalSec)

void leftSignal(String mode)
void rightSignal(String mode)

int speedCtrl(void)

void forward(int speed); 
void backward(int speed);
void turnLeft(int speed); 
void turnRight(int speed); 

void stop(); 


# Module Structure (ERO.h →  Common.h → Module.h)
## Struct GamePad (GamePadModule)
bool UP
bool DOWN
bool LEFT
bool RIGHT

bool CROSS
bool SQUARE
bool CIRCLE
bool TRIANGLE

bool SELECT
bool START
