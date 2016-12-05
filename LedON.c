#include <wiringPi.h>
#include <softPwm.h>
#include "LedON.h"

void init()
{
	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	softPwmCreate(0, 0, 10);
	softPwmCreate(1, 0, 10);
	softPwmCreate(2, 0, 10);
	softPwmCreate(3, 0, 10);
	digitalWrite(0, LOW);
	digitalWrite(1, LOW);
	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
}

void Led(signed char PWM_value, signed char PWM_value2)
{
	softPwmWrite(0, 0);
	softPwmWrite(1, PWM_value);
	softPwmWrite(2, 0);
	softPwmWrite(3, PWM_value2);
	//delay(100);

	//softPwmWrite(0, 0);
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
