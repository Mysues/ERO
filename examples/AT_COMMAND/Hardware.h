#define LEFT_IN1        3
#define LEFT_IN2        4
#define LEFT_SPEED      5

#define RIGHT_IN1       7
#define RIGHT_IN2       2
#define RIGHT_SPEED     6

#define LEFT_SIGNAL     11
#define RIGHT_SIGNAL    12

#define BEEPER          13

#define SPEED_CTRL       A0
#define TX_PIN          9
#define RX_PIN          8

int motorPin[] = {
    LEFT_IN1,
    LEFT_IN2,
    LEFT_SPEED,
    RIGHT_IN1,
    RIGHT_IN2,
    RIGHT_SPEED
};

int signalPin[] = {
    LEFT_SIGNAL,
    RIGHT_SIGNAL
};
