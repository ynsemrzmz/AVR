#ifndef F_CPU
#define F_CPU	16000000UL			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif


#include <util/delay.h>				//Library for delay function
#include <stdint.h>					//Library for standart integer usage
#include <avr/interrupt.h>			//Library for avr interrupts

#include "atmega328_gpio.h"				//Register modelling headers for atmega328p
#include "atmega328p_timer_registers.h"

static void init_gpio();		//Initialization function definitions
static void init_timer1();

uint16_t overflow;	//Overflow variable for timer counter value

int main(){
	
	init_gpio();		//Function calls
	init_timer1();
	sei();				//AVR interrupt function (set-enable interupts)

	while(1){
		
		
	}
	return 0;
}


static void init_gpio(){
	DDRB_UNION.port = PORT_ALL_OUTPUT;	//B port set to OUTPUT

}

static void init_timer1(){								
	TIMER1_MODE = TIMER1_MODE_CTC_OCR1A;			 //TIMER1 MODE CTC (Clear timer on compare match)					
	TIMER1_CLOCK_SELECTION = TIMER1_PRESCALE_256;	 //TIMER PRESCALE 256 (16MHz / 256)
	TIMER1_INTERRUPT_OUT_COMP_A = INTERRUPT_ENABLE;	 //OUTPUT COMPARE INTERRUPT A enabled
	OCR1A = 62499;	//Output compare value,when the timer count reaches this value timer overflow flag is set then timer reset itself									
	sei(); //AVR interrupt function (set-enable interupts)
}

ISR(TIMER1_OVF_vect){ //When the overflow occurs , change the situation of B port with exor operation (HIGH to LOW , LOW to HIGH) 
	PORTB_UNION.port ^= PORT_ALL_HIGH;
}
