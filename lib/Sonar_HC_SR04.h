#ifndef _Sonar_HC_SR04_H_
#define _Sonar_HC_SR04_H_

#include "Arduino.h"

class Sonar_HC_SR04
{	
	const float SOUND_SPEED_CM_MICROSECONDS = 0.034;

	int pinTrigger; //pin sending the sound wave
	int pinEcho; //pin receiving the sound wave return (echo)

	void configSonarPins();

public:
	//Constructor
	Sonar_HC_SR04();

	Sonar_HC_SR04(int pinTrigger, int pinEcho);

	//Methods
	int testDistance();
};

#endif
