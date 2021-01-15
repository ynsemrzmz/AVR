#ifndef F_CPU
#define F_CPU 16000000UL		//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#define BUTTON_PRESSED   (PIND & (1<<5)) //Button is connected to PD5
										//When the button is pressed BUTTON_PRESSED equals to 1 ,else 0

#include <stdint.h>				//Library for standart int usage
#include <util/delay.h>			//Library for delay
#include <avr/io.h>				//Library for general input output


int main(){
	uint8_t buttonState = 0x00;		//Button state variable,first condition button is not pressed 
									//so button state equals to 0 
	
	DDRB = 0xFF;		//PORTB is OUTPUT
	DDRD = 0x00;		//PORTD is INPUT
	
	while(1){
		
		//We control the button situation with buttonState and BUTTON_PRESSED values
		
		if((buttonState == 1) && BUTTON_PRESSED){
			buttonState = 0x00;
			_delay_ms(300); //Debouncing delay
		}
		
		if ((buttonState == 0) && BUTTON_PRESSED){
			buttonState ^= (1<<0);
			_delay_ms(300);		//Debouncing delay
		}
		
		//We control the PORTB with buttonState variable
		//When the buton is pressed ,we change the PORTB HIGH to LOW OR LOW TO HIGH
		if(buttonState & (1<<0)){
			PORTB = 0xff;
		}
		else{
			PORTB = 0x00;
		}
	}
}

