#ifndef F_CPU
#define F_CPU	16000000UL			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h>					//Library for general input output 
#include <util/delay.h>				//Library for delay function


int main(void)
{
	DDRB = 0xFF; //Set all B pins to output with data direction register
	
	while (1)
	{
		
		PORTB = (1<<PORTB0) | (1<<PORTB1); // Set B1 and B0 pin to HIGH with bit shifting-or operation
	}
}
