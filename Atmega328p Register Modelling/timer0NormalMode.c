#include <stdint.h>									//Library for standart integer usage
#include <avr/interrupt.h>							//Library for avr interrupts

#include "atmega328_gpio.h"							//Register modelling headers for atmega328p
#include "atmega328p_timer_registers.h"

#define RESET_TIMER_COUNTER		6

static void init_gpio();		//Initializaton function prototypes
static void init_timer0();


uint16_t overflow;		
uint8_t ledNo;

int main(){
	init_gpio();					//Init function calls
	init_timer0();

	while(1){
		
		
	}
	return 0;
}


static void init_gpio(){
	DDRB_UNION.port = PORT_ALL_OUTPUT;							//B port OUTPUT
}

static void init_timer0(){
	TIMER0_CLOCK_SELECTION = TIMER0_PRESCALE_1024;				//Prescale 1024
	TIMER0_MODE_SELECTION = TIMER0_MODE_NORMAL;					//Timer mode NORMAL
	TIMER0_INTERRUPT_OVERFLOW = TIMER0_INTERRUPT_ENABLE;		//Timer interrupt enable
	TIMER0_COUNTER = RESET_TIMER_COUNTER;						//Reset timer counter
	sei();														//AVR function to enable interrupts (set enable interrupts)
}

ISR(TIMER0_OVF_vect){	//Whenever timer overflow intterrupt occurs
		
	ledNo = ledNo + 1;							//Make led animation 
	PORTB_UNION.port ^= (1<<ledNo);				
	
	if(ledNo >= 7){
		ledNo = 0;
	}
	
	TIMER0_COUNTER = RESET_TIMER_COUNTER;	//Reset timer counter
}
