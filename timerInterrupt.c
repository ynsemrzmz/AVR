#include <avr/io.h>						//Library for general input output 
#include <stdint.h>						//Library for standart int usage
#include <avr/interrupt.h>				//Library for AVR interrupts

void init_timer1();				//Initalization functions
void init_gpio();

int main(void){
	
	init_timer1();				//Initalization functions calls
	init_gpio();
	
	while (1) {

	}
	
	return 0;																						
}


void init_timer1(){
	TCCR1B |= (1<<CS12) | (1<<CS10);		//Timer prescale 1024
	TIMSK1 |= (1<<TOIE1);					//Enable timer interrupt
	sei();									//AVR function to enable interrupts (set enable interrupts)	
}

void init_gpio(){
	DDRB |= (1<<PORTB1);					//Set B1 to output
}

ISR(TIMER1_OVF_vect){						//Whenever timer1 overflow occurs (interrupt occurs)
	PORTB ^= (1<<PORTB1);					//Change the B1 situation with exor (HIGH to LOW , LOW to HIGH)
}

