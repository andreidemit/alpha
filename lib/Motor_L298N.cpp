/*
 * Author: Andrei Demit
 * Company: AIST (di Demit Andrei)
 * Header: Implementation of class Motor_L298N
 * */

#include "Motor_L298N.h"

Motor_L298N::Motor_L298N()
{

}

/*
 * Constructor
 * */
Motor_L298N::Motor_L298N(Motor_L298N_pinConfiguration pinConfiguration)
{
	this->pinConfiguration = pinConfiguration;
	configMotorsPins();
}

/*
 * Motor driver pin mode configuration.
 * */
void Motor_L298N::configMotorsPins()
{
  //Set the defined pins to the output
  pinMode(pinConfiguration.pinLeftBackMotor, OUTPUT);  
  pinMode(pinConfiguration.pinLeftFrontMotor, OUTPUT);
  pinMode(pinConfiguration.pinRightBackMotor, OUTPUT);
  pinMode(pinConfiguration.pinRightFrontMotor, OUTPUT);

  pinMode(pinConfiguration.pinLeftMotorsSpeed, OUTPUT);
  pinMode(pinConfiguration.pinRightMotorsSpeed, OUTPUT);
}

/* Sets the spinning speed of right and left motors.
 * */
void Motor_L298N::setSpinSpeed(int speed)
{
	analogWrite(pinConfiguration.pinRightMotorsSpeed, speed);
	analogWrite(pinConfiguration.pinLeftMotorsSpeed, speed);

	//Serial.println("Spinning speed set to: " + String(speed));
}

/*
 * Sets the way the motors will spin, to make it move forward.
 * */
void Motor_L298N::forwardSpinConfiguration()
{
	digitalWrite(pinConfiguration.pinRightBackMotor, HIGH);
	digitalWrite(pinConfiguration.pinRightFrontMotor, LOW);
	digitalWrite(pinConfiguration.pinLeftBackMotor, LOW);
	digitalWrite(pinConfiguration.pinLeftFrontMotor, HIGH);
  
	//Serial.println("Forward direction spin configuration.");
}

/*
 * Sets the way the motors will spin, to make it move backward.
 * */
void Motor_L298N::backwardSpinConfiguration()
{
	digitalWrite(pinConfiguration.pinRightBackMotor, LOW);
	digitalWrite(pinConfiguration.pinRightFrontMotor, HIGH);
	digitalWrite(pinConfiguration.pinLeftBackMotor, HIGH);
	digitalWrite(pinConfiguration.pinLeftFrontMotor, LOW);
  
	//Serial.println("Backward direction spin configuration.");
}

/*
 * Sets the way the motors will spin, to make it turn counterclockwise.
 * */
void Motor_L298N::counterclockwiseSpinConfiguration()
{
	digitalWrite(pinConfiguration.pinRightBackMotor, HIGH);
	digitalWrite(pinConfiguration.pinRightFrontMotor, LOW);
	digitalWrite(pinConfiguration.pinLeftBackMotor, HIGH);
	digitalWrite(pinConfiguration.pinLeftFrontMotor, LOW);
  
	//Serial.println("Counterclockwise direction spin configuration.");
}

/*
 * Sets the way the motors will spin, to make it turn clockwise.
 * */
void Motor_L298N::clockwiseSpinConfiguration()
{
	digitalWrite(pinConfiguration.pinRightBackMotor, LOW);
	digitalWrite(pinConfiguration.pinRightFrontMotor, HIGH);
	digitalWrite(pinConfiguration.pinLeftBackMotor, LOW);
	digitalWrite(pinConfiguration.pinLeftFrontMotor, HIGH);

	//Serial.println("Clockwise spin configuration.");
}

/*
 * Moves the engine in the specified direction.
 * Speed must be a value between 1 and 255.
 * */
void Motor_L298N::moveV1(Motor_L298N_MovingDirection movingDirection, int speed)
{
	setSpinSpeed(speed);

	switch (movingDirection)
	{
		case Forward: forwardSpinConfiguration();
		break;
		case Backward: backwardSpinConfiguration();
		break;
		case Right: clockwiseSpinConfiguration();
		break;
		case Left: counterclockwiseSpinConfiguration();
		break;
	}
}

/*
 * Moves the engines in the specified direction
 * */
void Motor_L298N::moveV2(int rotationDegree, int speed)
{

	if(rotationDegree>0)
	{ //Move clockwise for rotationDegree degrees

	}
	else if(rotationDegree<0)
	{ //Move clockwise for rotationDegree degrees

	}
	else if(rotationDegree==0)
	{

	}


}

/*
 * Stops the engines
 * */
void Motor_L298N::stop()
{
	setSpinSpeed(0);
}
