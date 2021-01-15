/*I2C Slave Receiver Mode*/

#ifndef F_CPU 
#define F_CPU 16000000			//Definition of  F_CPU for frequency of atmega328p if not defined
#endif

#include <avr/io.h>				//Library for general input output
#include <stdint.h>				//Library for standart int usage
#include <util/delay.h>			//Library for delay functtion

void I2C_Init(unsigned char SlaveAdress);
unsigned char I2C_read_data();				//I2C dunction definitons
void I2C_match_adress_ACK();

int main(void)
{
	DDRB = 0xFF;
	I2C_Init(0x20);
	
    while (1) 
    {	
		I2C_match_adress_ACK();
		PORTB = I2C_read_data();
		
    }
}

void I2C_Init(unsigned char SlaveAdress){
	TWAR = SlaveAdress;	//Write slave adress to I2C slave adress register
}

unsigned char I2C_read_data(){
	unsigned char i2cData;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA) ; //Enable I2C interrput , enable I2C , enable I2C ACK
	while(!(TWCR & (1<<TWINT)));				//Wait I2C to finish its current job
	while((TWSR & 0xF8) != 0x80); //Wait for acknowledgment
	/*0x08 is ACK code for data has been received*/
	i2cData = TWDR; 
	return i2cData;
}

void I2C_match_adress_ACK(){
	while ((TWSR & 0xF8) != 0x60)
	{
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA) ; //Enable I2C interrput , enable I2C , enable I2C ACK
		while(!(TWCR & (1<<TWINT)));				//Wait I2C to finish its current job
	}
}





