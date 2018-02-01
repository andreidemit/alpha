#ifndef _Bluetooth_HC_06_H_
#define _Bluetooth_HC_06_H_

#include "Arduino.h"
#include "SoftwareSerial.h"
/*
 * Used with board V5, default RX and TX are  0 and 1
 *
 * */
class Bluetooth_HC_06
{	

	SoftwareSerial *serial;

	void configBluetooth();

public:
	//Constructor
	Bluetooth_HC_06();

	Bluetooth_HC_06(int pinRX, int pinTX);

	//Methods
	char * readStream();
	void writeStream(char * message);
};

#endif
