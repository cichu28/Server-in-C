#include <wiringPi.h>
#include <softPwm.h>

void init(){
	wiringPiSetup();                        // Incjacja biblioteki do sterowania pinami                  
	pinMode(0, OUTPUT);                     // Inicjacja pinu numer 0, aby działał jako pin WYJŚIOWY
	softPwmCreate(0, 0, 10);                // Ustawienie pinu 0, aby działał jako PWM z zakresu 0 do 10
	digitalWrite(0, LOW);                   // Ustawienie PWM pinu numer 0 na wartość 50
}


void Led(signed char PWM_value){
  	softPwmWrite(0, PWM_value);             // ustawiam na pinie numer 0 wartość PWM jako wartość argumentu, który przyjmuje funkcja
}

int main(){
	init();                                 // wywołanie funkcji inicjalizującej
	Led(5);                                 // wywołanie funkcji ustawiającej jasność diody z argumentem rownym 5
	return 0;
}
