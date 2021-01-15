#ifndef atmega328_gpio_h
#define atmega328_gpio_h


//PORT REGISTER ADRESSES 
#define REG_ADDR_PORTD			0X2B
#define REG_ADDR_DDRD			0X2A
#define REG_ADDR_PIND			0X29
#define REG_ADDR_PORTB			0X25
#define REG_ADDR_DDRB			0X24
#define REG_ADDR_PINB			0X23
#define REG_ADDR_PORTC			0X28
#define REG_ADDR_DDRC			0X27
#define REG_ADDR_PINC			0X26

#define _REG_PORTD				(*(volatile uint8_t*)REG_ADDR_PORTD)
#define _REG_DDRD				(*(volatile uint8_t*)REG_ADDR_DDRD)
#define _REG_PIND				(*(volatile uint8_t*)REG_ADDR_PIND)
#define _REG_PORTB				(*(volatile uint8_t*)REG_ADDR_PORTB)
#define _REG_DDRB				(*(volatile uint8_t*)REG_ADDR_DDRB)
#define _REG_PINB				(*(volatile uint8_t*)REG_ADDR_PINB)
#define _REG_PORTC				(*(volatile uint8_t*)REG_ADDR_PORTC)
#define _REG_DDRC				(*(volatile uint8_t*)REG_ADDR_DDRC)
#define _REG_PINC				(*(volatile uint8_t*)REG_ADDR_PINC)

//PIN STRUCTURE
typedef struct{
	uint8_t pin0 : 1;
	uint8_t pin1 : 1;
	uint8_t pin2 : 1;
	uint8_t pin3 : 1;
	uint8_t pin4 : 1;
	uint8_t pin5 : 1;
	uint8_t pin6 : 1;
	uint8_t pin7 : 1;
	
}PIN_T,*PIN_T_PTR;

//PORT UNIONS
typedef union{
	PIN_T pins;
	volatile uint8_t port;

}PORT_T,*PORT_T_PTR;

//UNIONS
#define DDRB_UNION				(*(PORT_T_PTR)REG_ADDR_DDRB)
#define PORTB_UNION				(*(PORT_T_PTR)REG_ADDR_PORTB)
#define PINB_UNION				(*(PORT_T_PTR)REG_ADDR_PINB)
#define DDRD_UNION				(*(PORT_T_PTR)REG_ADDR_DDRD)
#define PORTD_UNION				(*(PORT_T_PTR)REG_ADDR_PORTD)
#define PIND_UNION				(*(PORT_T_PTR)REG_ADDR_PIND)
#define DDRC_UNION				(*(PORT_T_PTR)REG_ADDR_DDRC)
#define PORTC_UNION				(*(PORT_T_PTR)REG_ADDR_PORTC)
#define PINC_UNION				(*(PORT_T_PTR)REG_ADDR_PINC)

//GPIO COMMANDS
#define PIN_INPUT				0
#define PIN_OUTPUT				1
#define PORT_ALL_INPUT			0x00
#define PORT_ALL_OUTPUT			0xff
#define PIN_HIGH				0
#define PIN_LOW					1
#define PORT_ALL_LOW			0x00
#define PORT_ALL_HIGH			0xff
#define PIN_PULLUP_OFF			0
#define PIN_PULLUP_ON			1
#define PORT_PULLUP_OFF			0x00
#define PORT_PULLUP_ON			0xff



#endif
