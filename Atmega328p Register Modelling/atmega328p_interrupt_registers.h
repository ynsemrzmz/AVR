#ifndef atmega328p_registers_h
#define atmega328p_registers_h


//INTERRUPT REGISTER ADRESSES
#define REG_ADDR_EIMSK			0x3D
#define _REG_EIMSK				(*(volatile uint8_t*)REG_ADDR_EIMSK)
#define REG_ADDR_EIFR			0x3C
#define _REG_EIFR				(*(volatile uint8_t*)REG_ADDR_EIFR)
#define REG_ADDR_EICRA			0x69
#define _REG_EICRA				(*(volatile uint8_t*)REG_ADDR_EICRA)

//INTERRUPT COMMANDS AND MODES
#define INT_ENABLE				1
#define INT_DISABLE				0
#define INT_MODE_LOW			0
#define INT_MODE_CHANGE			1
#define	INT_MODE_FALLING_EDGE	2
#define INT_MODE_RISING_EDGE	3

//EXTERNAL INTERRUPT MASK REGISTER STRUCT
typedef struct{
	uint8_t int0 : 1;
	uint8_t int1 : 1;
	uint8_t reserved : 6;
}EIMSK_T,*EIMSK_PTR_T;

#define REG_EIMSK				((EIMSK_PTR_T)REG_ADDR_EIMSK)

//EXTERNAL INTERRUPT CONTROL REGISTER STRUCT
typedef struct{
	uint8_t int0_mode : 2;
	uint8_t int1_mode : 2;
	uint8_t reserved : 4;
}EICRA_T,*EICRA_PTR_T;

#define  REG_EICRA				((EICRA_PTR_T)REG_ADDR_EICRA)


//EXTERNAL INTERRUPT FLAG REGISTER STRUCT
typedef struct{
	uint8_t intf0 : 1;
	uint8_t intf1 : 1;
	uint8_t reserved : 6;
}EIFR_T,*EIFR_PTR_T;



#endif
