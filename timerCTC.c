#ifndef F_CPU
#define F_CPU 16000000UL				//Definition of  F_CPU for frequency of atmega328p if not defined
#endif
	
#include <avr/io.h>						//Library for general input output	
#include <stdint.h>						//Library for standart int usage
#include <avr/interrupt.h>				//Library for AVR interrupts

void init_timer1();				//Initalization functions
void init_gpio();

int main(void){
	
	init_timer1();				//Initialization function calls
	init_gpio();
	
	while (1) {
		
		
	}
	
	return 0;
}


void init_timer1(){
	TCCR1B |= (1<<CS12) | (1<<CS10);
	TIMSK1 |= (1<<OCIE1A);			//Enable timer1 output compare interrupt
	TCCR1B |= (1<<WGM12);			//Waweform generation mode CTC
	OCR1A = 49911;					//Output Compare Value 	
	sei();							//AVR function to enable interrupts (set enable interrupts)																	
}

void init_gpio(){
	DDRB |= (1<<PORTB1);			//Set B1 to output
}

ISR(TIMER1_COMPA_vect){				//Whenever timer1 overflow occurs on compare match
	PORTB ^= (1<<PORTB1);			//Change the B1 situation with exor (HIGH to LOW , LOW to HIGH)
}
