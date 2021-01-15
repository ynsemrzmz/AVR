#ifndef F_CPU
#define F_CPU 16000000			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif
	
#include <avr/io.h>				//Library for general input output
#include <util/delay.h>			//Library for delay function


int main(void)
{
	DDRD &= ~(1<<PORTD6);
	PORTD |= (1<<PORTD6);    //Set D6 to INPUT PULLUP
	DDRD &= ~(1<<PORTD7);
	PORTD |= (1<<PORTD7);	 //SET D7 to INPUT PULLUP
	
	DDRB = 0xff;	//Set B PORT to OUTPUT
	
	while (1)
	{
		if(!(PIND &(1<<PORTD7))){		//If the button is pressed which is connected to D7
			for(int i = 0; i<6;i++){					
				PORTB = (1<<i);			//Blink the Leds on the B port with ascending order
				_delay_ms(1000);
			}
		}
		if(!(PIND &(1<<PORTD6))){		//If the button is pressed which is connected to D6
			for(int i = 5; i>=0;i--){
				PORTB = (1<<i);			//Blink the Leds on the B port with descending order
				_delay_ms(1000);
			}
		}
		
		
	}
}
