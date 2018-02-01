/*
	Author: Andrei Demit
	Company: AIST (di Demit Andrei)
	Header:Implementation of class Sonar_HC_SR04.
*/

#include "Sonar_HC_SR04.h"


/*
 * Constructor with default parameters
 * */
Sonar_HC_SR04::Sonar_HC_SR04():Sonar_HC_SR04(A5, A4)
{

}

/*
	Constructor
*/
Sonar_HC_SR04::Sonar_HC_SR04(int pinTrigger, int pinEcho)
{
	this->pinTrigger = pinTrigger;
	this->pinEcho = pinEcho;

	configSonarPins();
}

/*
 * Sonar pin mode configuration.
 * */
void Sonar_HC_SR04::configSonarPins()
{
	pinMode(this->pinTrigger, OUTPUT);
	pinMode(this->pinEcho, INPUT);
	Serial.println("Sonar pin config complete");
}

/*
  Test distance with sonar
  Applied speed physics formula
  speed = distance / time
  distance = speed * time
  speed of sound = 340 m/s = 0,034 cm/uS
  distance = 0,034 * time
  
  The sonar return the time the sound wave traveled back and forth from the nearest object.
  Thus, the real distance is given by half the traveled time.
*/
int Sonar_HC_SR04::testDistance(){
  
  //Cleans the trigger
  digitalWrite(this->pinTrigger, LOW);
  delayMicroseconds(2);
  
  //Activate the trigger by setting it HIGH got 10 microseconds
  digitalWrite(this->pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->pinTrigger, LOW);

  //time in microseconds of the sound wave traveled to a back from the nearest object
  float soundWaveTimeTravelled = pulseIn(this->pinEcho, HIGH);

  Serial.println(soundWaveTimeTravelled);

  //applying physics distance formula when we have speed and time
  //it is divided by 2 because gives the distance covered by the sound wave to and back from the nearest object
  int distance = SOUND_SPEED_CM_MICROSECONDS * soundWaveTimeTravelled / 2;



  return distance;
}
