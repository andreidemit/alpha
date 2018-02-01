// Do not remove the include below
#include "Alpha_I.h"


//The setup function is called once at startup of the sketch
void setup()
{
	// initialize serial communication at 9600 bits per second:
	Serial.begin(9600);

	//Servo setup
	servo = new Servo();
	servo->attach(3);
	servoTurningCounterclockwise = true; //start by turning counterclockwise
	
	servo->write(90); //neutral position, pointing directly in front of the car.

	//Motor Driver setup
	Motor_L298N_pinConfiguration pinConfiguration;
	//Motor spinning direction control pins
	pinConfiguration.pinRightBackMotor = 6;
	pinConfiguration.pinRightFrontMotor = 7;
	pinConfiguration.pinLeftBackMotor = 8;
	pinConfiguration.pinLeftFrontMotor = 9;
	//Motor spinning speed control pins
	pinConfiguration.pinRightMotorsSpeed = 5;
	pinConfiguration.pinLeftMotorsSpeed = 11;	
	motor = new Motor_L298N(pinConfiguration);

	//Sonar setup	
	sonar = new Sonar_HC_SR04();

	//General setup
	previousMillis = 0;
	currentSpaceBlockIndex = 8;
	currentAngleDegree = 0;
	//Initialize the array to a distance of 99 cm
	for(int i = 0; i<180; i++)
		inSightDistances[i] = 99;
}

// The loop function is called in an endless loop
void loop()
{
	//Turn the Servo every INTERVALL_SERVO (20 milliseconds)

	if(millis()-previousMillis>INTERVALL_SERVO)
	{
		if(servoTurningCounterclockwise)
		{
			if(currentSpaceBlockIndex < 170)
			{
				currentSpaceBlockIndex ++;
			}
			else
			{	//if the servo was turning left change the turing direction to right
				//when it reaches the maximum left degree point
				servoTurningCounterclockwise = false;
			}
		}
		else //clockwise turning
		{
			if(currentSpaceBlockIndex > 1)
			{
				currentSpaceBlockIndex --;
			}
			else
			{	//if the servo was turning right change the turing direction to left
				//when it reaches the maximum right degree point
				servoTurningCounterclockwise = true;
			}

		}

		currentAngleDegree = currentSpaceBlockIndex;

		inSightDistances[currentSpaceBlockIndex] = sonar->testDistance();

		servo->write(currentAngleDegree);
		//Serial.print("Angle: " + String(currentAngleDegree) +" degrees. ");
		//Serial.println("Distance: " + String(inSightDistances[currentSpaceBlockIndex]) +" cm. Index: " + String(currentSpaceBlockIndex));
		Serial.print(currentAngleDegree);
		Serial.print(",");
		Serial.print(inSightDistances[currentSpaceBlockIndex]);
		Serial.print(".");
		previousMillis = millis();
	}

	int speed=0;
	currentDirection = calculateDirection(speed);

	motor->moveV1(currentDirection, speed);

}

Motor_L298N_MovingDirection calculateDirection(int &speed)
{
	int freeSpaceBlockIndex = -1;
	int max = 0;
	int direction = Forward;

	speed = 100;

	if(inSightDistances[6] > DANGER_DISTANCE_CM &&
		inSightDistances[7] > DANGER_DISTANCE_CM &&
		inSightDistances[8] > DANGER_DISTANCE_CM &&
		inSightDistances[9] > DANGER_DISTANCE_CM &&
		inSightDistances[10] > DANGER_DISTANCE_CM &&
		inSightDistances[11] > DANGER_DISTANCE_CM)
	{//if the middle (front car) distances are higher than 20
		//prefer to move forward whether there are higher distances on the right or left side
		direction = Forward;
		//Serial.print("Forward");
		speed = 100;
	}
	else
	{
		speed = 180;

		//Find the angle with the highest distance
		for(int i=1; i<17; i++)
		{
			if(max<inSightDistances[i])
			{
				max = inSightDistances[i];
				freeSpaceBlockIndex = i;
			}
		}

		if(max>20)
		{
			if(freeSpaceBlockIndex<6)
			{//completely right
				direction = Right;
				//Serial.print("Completely Right");
			}
			else if(freeSpaceBlockIndex>11)
			{//completely left
				direction = Left;
				//Serial.print("Completely Left");
			}
			else
			{
				if(freeSpaceBlockIndex>=6 && freeSpaceBlockIndex<=8 )
				{//slight right
					direction = Right;
					//Serial.print("Slight Right");
				}
				else if(freeSpaceBlockIndex>=9 && freeSpaceBlockIndex<=11)
				{//slight left
					direction = Left;
					//Serial.print("Slight Left");
				}
			}
		}
		else //both, front, right and left distances are lower than 20 cm, go back
		{
			direction = Backward;
			//Serial.print("Backward");
		}
	}

	return direction;
}

/*
useful links
https://learn.adafruit.com/multi-tasking-the-arduino-part-1/a-clean-sweep
http://howtomechatronics.com/
*/
