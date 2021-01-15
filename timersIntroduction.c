#include <avr/io.h>				//Library for general input output
#include <stdint.h>				//Library for standart int usage
#include <avr/interrupt.h>		//Library for AVR interrupts

void init_gpio();				
void toggle_led();
uint16_t timer1_count();

uint16_t timerCounterValue;
uint16_t desiredValue = 15624


int main(void){
	
	init_gpio();
	
	while (1) {
		timerCounterValue = timer1_count();	      //Timer counter value 
		
		if(timerCounterValue >= desiredValue){	  //If timer counter value reaches desired value 
			timerCounterValue = 0;				  //Reset timerCounterValue variable
			TCNT1 = 0;							  //Reset timer counter
			toggle_led();						  //Toggle led	
		}
		
	}
	
	return 0;
}

uint16_t timer1_count(){
	TCCR1B |= (1<<CS12) | (1<<CS10);	//Timer1 prescale 1024 
	return TCNT1;						//Return timer1 counter value	
}

void init_gpio(){
	DDRB |= (1<<PORTB1);				//Set B1 to input
}

void toggle_led(){
	PORTB ^= (1<<PORTB1);				//Toggle B1 with exor (HIGH to LOW - LOW to HIGH)
}
