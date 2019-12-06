# ERO
This repo is dedicated for ERO library. ERO is stand for Easy Robotic, as the name show serve the purpose of this library.  Hopefully ERO library will help those who would like to getting started in basic mobile robot. Those who would like to use this as a template for mobile robot library for your team / institution / school are welcome.

# EROCore CLASS (ERO.h)
## Constructor
ERO::ERO(int* motorPin,int* signalPin,int beeperPin, int speedCtrlPin)
Method
void begin(void) // to setup pin of ERO Shield
void beeperMs(String mode, unsigned long intervalMs) // produce beeping sound for interval of milliseconds
void beeper(String mode, unsigned long intervalSec)  // produce beeping sound for interval of second

void leftSignal(String mode); // control the LED of leftSignal. “ON” to turn on the led and “OFF” to turn off the led
void rightSignal(String mode);// control the LED of rightSignal. “ON” to turn on the led and “OFF” to turn off the led

int speedCtrl(void) //get the return value of the potentiometer MAX 100 and Min 0. This function use map to convert 0-1023 to 0 – 100.

void forward(int speed); // to move the robot forward
void backward(int speed); // to move the robot backward
void turnLeft(int speed); // turn the robot to the left
void turnRight(int speed); // turn the robot to the right

void stop(); //stop left and right motor


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
