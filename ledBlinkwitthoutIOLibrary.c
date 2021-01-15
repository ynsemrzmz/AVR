#ifndef F_CPU
#define F_CPU 16000000UL			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#define ORIGIN 0x26					//Sample register adress definiton
#define MY_DDRB *myDDRBPtr			//DDRB pointer definiton
#define MY_PORTB *(myDDRBPtr+1)     //PORTB pointer definiton (Adress of PORTB is 1 more than adress of DDRB in datasheet)
#define ON 0xFF						//Definiton for set all the pins of one port to HIGH
#define OFF 0x00					//Definiton for set all the pins of one port to LOW

#include <stdint.h>					//Library for stanadrt int usage						
#include <util/delay.h>				//Library for delay


uint8_t* myDDRBPtr = (uint8_t*) (ORIGIN-2);  //Set the adress of DDRB

int main(){
	MY_DDRB = ON;		//Set all the pins of PORTB to OUTPUT 
	MY_PORTB = OFF;		//Set all the pins of PORTB to LOW
	
	while(1){
		MY_PORTB = ON;	 //Set all the pins of PORTB to HIGH 
		_delay_ms(1000);
		MY_PORTB = OFF;  //Set all the pins of PORTB to LOW 
		_delay_ms(1000);
	}
}
