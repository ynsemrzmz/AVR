#ifndef F_CPU
#define F_CPU 16000000UL			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h>							//Library for general input output
#include <stdint.h>							//Library for standart int usage
#include <avr/interrupt.h>					//Library for AVR interrupts

void init_uart(uint32_t baudRate);
void send_char(unsigned char uartData);
unsigned char read_char();
void send_stringln(char *c);					//UART Function prototypes
void send_string(char *c);



volatile char comingData;

int main(void){
	DDRB |= (1<<PORTB1) | (1<<PORTB2);			//B1 , B2  output
	
	sei();										//AVR function to enable interrupts (set enable interrupts)
	init_uart(9600);							//Init uart (baud rate 9600)
	
	while (1) {
		
		if(comingData == 'a'){		//If the comingData equals to a set B1 to HIGH 
			PORTB |= (1<<PORTB1);
		}
		if(comingData == 'b'){		//If the comingData equals to b set B1 to LOW 
			PORTB &= ~(1<<PORTB1);
		}
		if(comingData == 'c'){		//If the comingData equals to c set B1 to HIGH 
			PORTB |= (1<<PORTB2);
		}
		if(comingData == 'd'){		//If the comingData equals to d set B1 to LOW 
			PORTB &= ~(1<<PORTB2);
		}

		
	}
	return 0;
}


void init_uart(uint32_t baudRate){
	uint32_t baudRatePrescaler = ((F_CPU/baudRate/16) - 1 );  //Calculate baud rate for register as shown in the datasheet
	UBRR0L = baudRatePrescaler;								  //Write last 8 bit of the baudRatePrescalar to uart baud rate low register
	UBRR0H = (baudRatePrescaler>>8);						  //Write first 8 bit of the baudRatePrescalar to uart baud rate high register
	UCSR0C |= ((1<<UCSZ00) |(1<<UCSZ01));			          //Set data frame to 8 bit
	UCSR0B |= ((1<<RXEN0) | (1<<TXEN0));			          //Enable receiver and transmitter
	UCSR0B |= (1<<RXCIE0) | (1<<TXCIE0);					  //Enable receiver and transmitter interrupt
	
}

void send_char(unsigned char uartData){
	while(!(UCSR0A & (1<<UDRE0))){}		//Wait until uart data register is enable for writing data
	UDR0 = uartData;					//Write our data to uart data register
}

unsigned char read_char(){
	while(!(UCSR0A & (1<<RXC0))){}		//Wait until new data to come
	return UDR0;						//Return data from uart data register
}

void send_stringln(char *c){
	uint8_t counter = 0;					//Use character array to send string with newline (\n)
	while(c[counter] != '\0'){
		send_char(c[counter]);
		counter++;
	}
	send_char('\n');
}

void send_string(char *c){
	uint8_t counter = 0;				//Use character array to send string without newline
	while(c[counter] != '\0'){
		send_char(c[counter]);
		counter++;
	}
}
				
ISR(USART_RX_vect){						//Read data whenever usart receive interrupt occurs
	comingData = read_char();
}
