#ifndef _Alpha_II_H_
#define _Alpha_II_H_

#include "Arduino.h"
#include "Servo.h"

//add your includes for the project Alpha_II here
#include "Motor_L298N.h"
#include "Sonar_HC_SR04.h"
//end of add your includes here


//add your function definitions for the project Alpha_II here

Motor_L298N * motor;
Sonar_HC_SR04 * sonar;

Servo * servo;

unsigned long previousMillis;

const long SPIN_TIME=2000;

const int DANGER_DISTANCE_CM = 30;

unsigned int inSightDistances[180];
const int CAR_ANGLES_LIMIT = 4;

bool servoTurningCounterclockwise;

const long INTERVALL_SERVO = 20; // SG90 Servo motor turning speed: 100 ms for 60 degrees
int currentSpaceBlockIndex; //It stores the index for each space block whose distance from the nearest object
int currentAngleDegree;
int currentFreeSpaceBlockIndex; //it stores the index of the current free block space

Motor_L298N_MovingDirection calculateDirection(int &speed);
Motor_L298N_MovingDirection currentDirection;

#endif /* _Alpha_II_H_ */
