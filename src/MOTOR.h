#ifndef _MOTOR_h
#define _MOTOR_h
#include <Arduino.h>
class MOTOR
{
public:

private:
	unsigned long prev;

	int P_LeftA;
	int P_LeftB;
	int P_LeftSpeed;
	int P_RightA;
	int P_RightB;
	int P_RightSpeed;
	int ArraySize;

	int pinList[6];

	bool DirL_A;
	bool DirL_B;
	bool DirR_A;
	bool DirR_B;
	int SpeedL;
	int SpeedR;
	bool DirL_C;
	bool DirR_C;
	float speedRatio = 1;

public:
	MOTOR(int *pin, bool DirL=true, bool DirR=true);
	MOTOR(bool DirL=true, bool DirR=true);
	void begin(void);
	void begin(int *pin);

	void forward(int speed);
	void backward(int speed);
	void turnLeft(int speed);
	void turnRight(int speed);
	void stop();

	void changeSpeedRatio(float ratio) {speedRatio = ratio;} ;

	void drive(double heading, int speed, int gain);

	void motor_left(int speed);
	void motor_right(int speed);

	void run();
	void run(int duration,bool debug=false);
private:

	void updateMotorState(){
		digitalWrite(P_LeftA, DirL_A);
		digitalWrite(P_LeftB, DirL_B);
		analogWrite(P_LeftSpeed, SpeedL * speedRatio);
		digitalWrite(P_RightA, DirR_A);
		digitalWrite(P_RightB, DirR_B);
		analogWrite(P_RightSpeed, SpeedR * speedRatio);
	}

};


#endif

