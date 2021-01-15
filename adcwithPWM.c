#include <avr/io.h>					//Library for general input output
#include <avr/interrupt.h>			//Library for avr interrupts
#include <stdint.h>					//Library for standart int usage


double dutyCycle = 0;				//Duty Cycle variable for pwm signal generation

void init_adc();					//Function definitions for adc operations
uint16_t read_adc(uint8_t adcChannel);

volatile uint16_t adcValue = 0;		//Variable for  analog digital conversion result

int main(void){
	DDRD |= (1<<PORTD6);					//Set D6 to output
	DDRC |= (1<<PORTC0);					//Clear analog input pin C0
	DDRC &= ~(1<<PORTC0);					//Set C0 to input
	
	TCCR0A |= (1<<COM0A1);					//CTC FAST PWM  non-inverting mode
	TCCR0A |= (1<<WGM00) | (1<<WGM01);		//Waveform generation mode to fast pwm (top is 0xFF)
	
	OCR0A = (adcValue / 100) * 255;        //Calculate duty cyle as an percentage of 255 (255 is  maximum value in timer0)
	
	init_adc();	//init_adc() function call 
	
	TCCR0B |= (1<<CS00) | (1<<CS02);		//Set prescale of timer frequency to 1024				
	
	while (1) {
	adcValue = read_adc(PORTC0);	//Read adc 
	adcValue = adcValue / 4 ;		//Convert adc result form 0-1023 to 0-255
	OCR0A = adcValue;				//Use adc result generate pwm signal
	}
	
	return 0;
	}

	void init_adc(){
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2) ;  //ADC frequency prescaler 128 125kHz
	ADMUX |= (1<<REFS0); 							  //Voltage reference selection AVCC
	ADCSRA |= (1<<ADEN); 							  //ADC enable
	ADCSRA |= (1<<ADSC); 							  //Make first conversion
	}

	uint16_t read_adc(uint8_t adcChannel){
	ADMUX &= 0xf0;                          //Reset last four bit of admux to set new adc channel
	ADMUX |= adcChannel;                    //Set our adc channel
	ADCSRA |= (1<<ADSC);                    //Make first conversion
	
	while(ADCSRA & (1<<ADSC)){}             //Wait until first conversion done
	
	return ADCW;						    //Return adc result 
	}
