#ifndef F_CPU
#define F_CPU 16000000			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h> 			//Library for general input output 


int main(void)
{
	DDRB = 0xFF; 	//Set all B pins to output with data direction register
	
	while (1)															
	{
		PORTB = 0xFF; //Set all the B pins to HIGH
	}
}
