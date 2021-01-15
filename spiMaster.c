#ifndef  F_CPU
#define F_CPU 16000000 			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h>            //Library for general input output
#include <util/delay.h>		  //Library for delay functtion

#define DDR_SPI DDRB      //SPI Port
#define MISO	PORTB4   //Master In Slave Out Pin
#define MOSI	PORTB3   //Master Out Slave In Pin
#define SCK		PORTB5	 //Serial CLock Pin
#define SS		PORTB2  //Slave Select Pin				

void SPI_MasterInit(void); 				//SPI Master Functions
void SPI_MasterTransmit(char spiData);

int main(void)
{	
	SPI_MasterInit();  //SPI Init as Master 

    while (1) 
    {
		
		SPI_MasterTransmit('1');   //Send '!'
		_delay_ms(2000);           //delay 2 sec
		SPI_MasterTransmit('2');   //Send '2'
		_delay_ms(2000);		   //delay 2 sec	
		
    }
}


void SPI_MasterInit(void){
	DDR_SPI = (1<<MOSI) | (1<<SCK) | (1<<SS);   //set MOSI ,SCK and SS to OUTPUT others are INPUT
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);  //enable SPI , set as MASTER , set clock rate f_osc/16;
	
}

void SPI_MasterTransmit(char spiData){
	SPDR = spiData;  //Write our data to SPI Data Register
	
	while(!(SPSR & (1<<SPIF))){
		//Wait for SPI Transimssion to complete
	} 
	
}
