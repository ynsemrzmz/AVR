#ifndef F_CPU
#define F_CPU 16000000UL					//Definition of  F_CPU for frequency of atmega328p if not defined
#endif
	
#include <avr/io.h>							//Library for standart int usage
#include <avr/interrupt.h>					//Library for AVR interrupts
#include <stdint.h>							//Library for general input output
	

double dutyCycle = 0;

int main(void){
	DDRD |= (1<<PORTD6);					//Set portd6 to output
	
	TCCR0A |= (1<<COM0A1);					//Set CTC FAST PWM  non-inverting mode
	TCCR0A |= (1<<WGM00) | (1<<WGM01);		//Set  waveform generation mode to fast pwm (top is 0xFF)
	
	TIMSK0 |= (1<<TOIE0);					//Enable timer over flow interrupt
	
	OCR0A = (dutyCycle / 100) * 255;        //Calculate  duty cyle as an percentage of 255 (255 is our maximum value in timer0)				
	
	sei();									//AVR function to enable interrupts (set enable interrupts)
	
	TCCR0B |= (1<<CS00) | (1<<CS02);		//Set our prescale of timer frequency to 1024
	
	while (1) {
		
		_delay_ms(1000);
		dutyCycle = dutyCycle + 30;			//In every 1 seconds , increase  dutyc cyle by 30
		
		if(dutyCycle >= 100){				//If duty cycle reaches to 100 ,reset it
			dutyCycle = 0;
		}

	}
	
	return 0;
}

ISR(TIMER0_OVF_vect){
	OCR0A = (dutyCycle / 100) * 255;		//Renew duty cycle whenever timer overflow interrupt occurs
}
