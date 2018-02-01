#ifndef _Motor_L298N_H_
#define _Motor_L298N_H_

#include "Arduino.h"

struct Motor_L298N_pinConfiguration
{
	int pinRightBackMotor;
	int pinRightFrontMotor;
	int pinLeftBackMotor;
	int pinLeftFrontMotor;

	int pinRightMotorsSpeed;
	int pinLeftMotorsSpeed;
};

enum Motor_L298N_MovingDirection{Forward, Backward, Right, Left};

class Motor_L298N
{
	Motor_L298N_pinConfiguration pinConfiguration;
	
	void configMotorsPins();

	void setSpinSpeed(int speed);

	void forwardSpinConfiguration();
	void backwardSpinConfiguration();
	void counterclockwiseSpinConfiguration();
	void clockwiseSpinConfiguration();


public:

	Motor_L298N();
	//Constructor
	Motor_L298N(Motor_L298N_pinConfiguration pinConfiguration);


	/*
	 * Simple moving, Fwd,Bwd,Rgt,Lft*/
	void moveV1(Motor_L298N_MovingDirection movingDirection, int speed);

	/*
	 * Complex movement, speed and rotation Degree needed*/
	void moveV2(int rotationDegree, int speed);

	void stop();
};

#endif
