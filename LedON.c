#include <wiringPi.h>
#include <softPwm.h>
#include "LedON.h"

void init()
{
	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	softPwmCreate(0, 0, 10);
	softPwmCreate(1, 0, 10);
	digitalWrite(0, LOW);
	digitalWrite(1, LOW);
}

void Led(signed char PWM_value)
{
	softPwmWrite(1, 0);
	softPwmWrite(0, PWM_value);
	delay(1000);

	softPwmWrite(0, 0);
		//digitalWrite(0, HIGH);
		//digitalWrite(1, LOW);
		//delay(1000);
		//digitalWrite(0, LOW);
}

/*
int main()
{
	init();
	Led();
	return 0;
}*/
