#ifndef F_CPU
#define F_CPU 16000000			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif
	
#include <avr/io.h>				//Library for general input output
#include <util/delay.h>			//Library for general input output 


int main(void)
{
	DDRB = 0xFF; 	//Set all B pins to output with data direction register
	
	while (1)															
	{
		PORTB = 0xFF; 			//Set all the B pins to HIGH
		_delay_ms(1000);		//Delay 1 sec
		PORTB = 0x00; 			//Set all the B pins to LOW
		_delay_ms(1000); 		//Delay 1sec
	}
}
