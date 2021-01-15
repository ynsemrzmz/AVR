#ifndef F_CPU
#define F_CPU	16000000UL					//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <util/delay.h>						//Library for delay function
#include <stdint.h>							//Library for standart integer usage
#include <avr/interrupt.h>					//Library for avr interrupts

#include "atmega328_gpio.h"						//Register modelling headers for atmega328p
#include "atmega328p_pinchange_interrupts.h"	


uint8_t count = 0;		//Counter variable

int main(){
	DDRD_UNION.port = PORT_ALL_OUTPUT;	//D port set to OUTPUT
	
	REG_PCICR->pcie0 = 1;		//Pin change interrupt0 is enabled
	REG_PCIMSKR0->pcint1 = 1;	//External pin interrupts are enabled
	sei();		//AVR interrupt function (set-enable interrupts)
	
	while(1){
		
	}
	
	return 0;
}
										
ISR (PCINT0_vect){							//Interrupt Service Routine,when the interrupt occurs this code block runs
 	for(count = 0; count<10;count++){		//When the interrupt occurs , we use PD4 for visual reaction with HIGH to LOW 10 times
		PORTD_UNION.pins.pin4 = 1;
		_delay_ms(500);
		PORTD_UNION.pins.pin4 = 0;
		_delay_ms(500);
	}
}
