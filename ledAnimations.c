#ifndef F_CPU
#define F_CPU 16000000UL				//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#define DDRB	*((uint8_t*)0x24)		//Definiton of DDRB 
#define PORTB   *((uint8_t*)0x25)		//Definiton of PORTB

#include <stdint.h>						//Library for stanadrt int usage
#include <util/delay.h>					//Library for delay

void animation_1();						//Definiton of animation functions
void animation_2();

int main(){
	DDRB = 0xFF;		//Set PORTB to OUTPUT
	
	while(1){
		animation_1();
		animation_2();
	}
}

void animation_1(){				//led shifting animatiom
	int counter = 0;
	int counter1 = 5;
	
	for(counter = 0; counter<=5;counter++){
		PORTB |= (1<<counter);
		_delay_ms(100);
	}
	
	for(counter1 = 5 ; counter1 >= 0;counter1--){
		PORTB &= ~(1<<counter1);
		_delay_ms(100);
	}
	counter = 0;
	counter1 = 5;
}

void animation_2(){						//Set all the leds to HIGH after delay set all the leds to LOW 
	for(int i = 3; i >0 ; i--){			
		PORTB = 0xff;
		_delay_ms(100);
		PORTB = 0x00;
		_delay_ms(100);
	}
}
