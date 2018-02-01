/*
	Author: Andrei Demit
	Company: AIST (di Demit Andrei)
	Header:Implementation of class Bluetooth_HC_06.
*/

#include "Bluetooth_HC_06.h"


/*
 * Constructor with default parameters for V5 board
 * */
Bluetooth_HC_06::Bluetooth_HC_06():Bluetooth_HC_06(0, 1)
{

}

/*
	Constructor
*/
Bluetooth_HC_06::Bluetooth_HC_06(int pinRX, int pinTX)
{
	serial = new SoftwareSerial(pinRX, pinTX);
	serial->begin(9600);
}


/*char * readStream()
{
	char * data;
	while (this.available())
	{
		message += char(this.read());
	}

	if(!this.available())
	{
		if(message!="")
		{
			data = message;
		}
	}

	return data;
}*/
