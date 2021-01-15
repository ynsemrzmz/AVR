#ifndef F_CPU
#define F_CPU 16000000						//Definition of  F_CPU for frequency of atmega328p if not defined
#endif


#include <avr/io.h>							//Library for general input output 

int main(void)
{
	DDRB |= (1<<PORTB0);    	//Set B0 to OUTPUT
	DDRD &= ~(1<<PORTB1);  		
	PORTB |= (1<<PORTB1); 		//Set B1 to INPUT PULLUP UT
	
	while (1)
	{
		//When the button is pressed PINB & (1<<PORTB1) equals to zero 
		
		if(!(PINB & (1<<PORTB1))){	//While button is pressed set B0 to HIGH
			PORTB |= (1<<PORTB0);					 
		}
		else{						//Else set B0 to LOW
			PORTB &= ~(1<<PORTB0);	
		}
		
	}
}
