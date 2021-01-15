#ifndef F_CPU
#define F_CPU	16000000UL			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h>					//Library for general input output 
#include <util/delay.h>				//Library for delay function


int main(void)
{
	DDRD = 0xFF; 	//Set all D pins to output with data direction register
	
	while (1)															
	{
		PORTD = 0b00000000;  	//Set all D port pins to LOW with port register (all bits refer to one pin)
		_delay_ms(1000);		//Delay 1 sec
		PORTD = 0b10000000;		//Set first D port pin to HIGH
		_delay_ms(1000);		//Delay 1 sec
		
	}
} 

