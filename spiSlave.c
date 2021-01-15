#ifndef  F_CPU 
#define F_CPU 16000000 		//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h>         //Library for general input output
#include <util/delay.h>     //Library for delay functtion

#define DDR_SPI DDRB		//SPI Port
#define MISO	PORTB4     //Master In Slave Out Pin
#define MOSI	PORTB3     //Master Out Slave In Pin
#define SCK		PORTB5	  //Serial CLock Pin
#define SS		PORTB2   //Slave Select Pin				

void SPI_SlaveInit(void);			//SPI Slave Functions
char SPI_SlaveReceive(void);

char incomingData;    //Data variable for SPI Communication

int main(void)
{	
	
	SPI_SlaveInit();      //SPI Init as Slave
	
	DDRD |= (1<<PORTD4);
	
    while (1) 
    {
		incomingData = SPI_SlaveReceive();   //incomingData euals to SPI received data
		
		if(incomingData == '1'){   //If data equals to '1' set PORTD4 to HIGH
		}
		if(incomingData == '2'){   //If data equals to '2' set PORTD4 to HIG  
			PORTD &= ~(1<<PORTD4);
		}
		
    }

}

void SPI_SlaveInit(void){
	DDR_SPI = (1<<MISO); //set MISO output , others are input
	SPCR = (1<<SPE); //enable SPI
}

char SPI_SlaveReceive(void){
	while(!(SPSR & (1<<SPIF))){
		//Wait for SPI Transimssion to complete
	}
	
	return SPDR; //return SPI Data Register
}
