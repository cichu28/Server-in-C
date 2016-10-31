#include <wiringPi.h>
//#include <softPwm.h>
#include "LedON.h"

void init()
{
	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
}

void Led()
{
		digitalWrite(0, HIGH);
		digitalWrite(1, LOW);
		delay(1000);
		
		digitalWrite(0, LOW);
}

/*
int main()
{
	init();
	Led();
	return 0;
}
*/
