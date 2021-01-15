/*I2C Master Transmitter Mode*/

#ifndef F_CPU 
#define F_CPU 16000000		//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h>			//Library for general input output
#include <stdint.h>			//Library for standart int usage
#include <util/delay.h>     //Library for delay functtion

void I2C_Init();
void I2C_start();
void I2C_write_address(unsigned char Address);			//I2C function definitons
void I2C_write_data(unsigned char Data);
void I2C_stop();

int main(void)
{
	I2C_init();
    while (1) 
    {
		I2C_start();
		_delay_ms(10);
		I2C_write_address(0x20);
		_delay_ms(10);
		I2C_write_data(0xff);
		_delay_ms(10000);
		I2C_stop();	
		
		I2C_start();
		_delay_ms(10);
		I2C_write_address(0x20);
		_delay_ms(10);
		I2C_write_data(0x00);
		_delay_ms(10000);
		I2C_stop();	
	
	
    }
}


void I2C_Init(){
	TWSR  =0x00; //Clear I2C status register
	TWBR = (1<<TWBR3) | (1<<TWBR2); //Set bit rate to 12
}

void I2C_start(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA) ; //Enable I2C interrput , enable I2C , enable master mode
	while(!(TWCR & (1<<TWINT))); //Wait I2C to finish its current job
	while((TWSR & 0xF8) != 0x08); //Wait for acknowledgment  
	/*0x08 is ACK code for start condition has been transmitted*/
}

void I2C_write_address(unsigned char Address){
	TWDR = Address; //Write addres to I2C data register
	TWCR = (1<<TWINT) | (1<<TWEN); ////Enable I2C interrput , enable I2C
	while(!(TWCR & (1<<TWINT))); //Wait I2C to finish its current job
	while((TWSR & 0xF8) != 0x18); //Wait for acknowledgment
	/*0x08 is ACK code for SLA+W  has been transmitted*/
}

void I2C_write_data(unsigned char Data){
	TWDR = Data;
	TWCR = (1<<TWINT) | (1<<TWEN); ////Enable I2C interrput , enable I2C
	while(!(TWCR & (1<<TWINT))); //Wait I2C to finish its current job
	while((TWSR & 0xF8) != 0x28); //Wait for acknowledgment
	/*0x08 is ACK code for data byte has been transmitted*/
}

void I2C_stop(){
	TWCR = (1 << TWSTO) | (1<<TWINT) | (1<<TWEN) ; //Enable I2C stop condition , enable I2C interrupt , enable I2C 
	while(!(TWCR & (1<<TWINT))); //Wait I2C to finish its current job
	while((TWSR & 0xF8) != 0x28); //Wait for acknowledgment
	/*0x08 is ACK code for data byte has been transmitted*/	
}
