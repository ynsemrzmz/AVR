#ifndef F_CPU
#define F_CPU	16000000UL			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h>					//Library for general input output 
#include <util/delay.h>				//Library for delay function


int main(void)
{
	DDRB = 0xFF; 	//Set all B pins to output with data direction register
	
	uint8_t counter = 0; 	//Counter variable to for loop
	
	while (1)
	{												
		for(counter = 0;counter<5;counter++){
			PORTB = (1<<counter);  //Set HIGH each B pin with order as usage of for loop
			_delay_ms(5000);	   //Delay 5 sec	 
		}
	}
}





