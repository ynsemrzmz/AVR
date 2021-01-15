#ifndef atmega328p_pinchange_interrupts
#define atmega328p_pinchange_interrupts

#include <stdint.h>


//REGISTER ADRESSES
#define  REG_ADDR_PCICR		  0X68
#define	 REG_ADDR_PCIMSKR2    0x6D
#define	 REG_ADDR_PCIMSKR1    0x6C
#define	 REG_ADDR_PCIMSKR0    0x6B

#define  REG_PCICR			  ((PCICR_PTR_T)REG_ADDR_PCICR)
#define  REG_PCIMSKR0	      ((PCIMSK0_PTR_T)REG_ADDR_PCIMSKR0)
#define  REG_PCIMSKR1	      ((PCIMSK1_PTR_T)REG_ADDR_PCIMSKR1)
#define  REG_PCIMSKR2	      ((PCIMSK2_PTR_T)REG_ADDR_PCIMSKR2)

#define  REG_PCIMSK			  ((PCIMSK0_PTR_T)REG_ADDR_PCIMSKR0)	

//PIN CHANGE INTERRUPT CONTROL REGISTER STRUCT
typedef struct{
	uint8_t pcie0 : 1;
	uint8_t pcie1 : 1;
	uint8_t pcie2 : 1;
	uint8_t reserved : 5;

}PCICR_T,*PCICR_PTR_T;
	

//PIN CHANGE INTERRUPT MASK REGISTER 0 STRUCT
typedef struct{
	uint8_t pcint0 : 1;	
	uint8_t pcint1 : 1;	
	uint8_t pcint2 : 1;	
	uint8_t pcint3 : 1;
	uint8_t pcint4 : 1;	
	uint8_t pcint5 : 1;	
	uint8_t pcint6 : 1;	
	uint8_t pcint7 : 1;		

}PCIMSK0_T,*PCIMSK0_PTR_T;

//PIN CHANGE INTERRUPT MASK REGISTER 1 STRUCT
typedef struct{
	uint8_t pcint8 : 1;
	uint8_t pcint9 : 1;
	uint8_t pcint10 : 1;
	uint8_t pcint11 : 1;
	uint8_t pcint12 : 1;
	uint8_t pcint13 : 1;
	uint8_t pcint14 : 1;
	uint8_t reserved : 1;

}PCIMSK1_T,*PCIMSK1_PTR_T;

//PIN CHANGE INTERRUPT MASK REGISTER 2 STRUCT
typedef struct{
	uint8_t pcint16 : 1;
	uint8_t pcint17 : 1;
	uint8_t pcint18 : 1;
	uint8_t pcint19 : 1;
	uint8_t pcint20 : 1;
	uint8_t pcint21 : 1;
	uint8_t pcint22 : 1;
	uint8_t pcint23 : 1;

}PCIMSK2_T,*PCIMSK2_PTR_T;

//PIN CHANGE INTERRUPT MASK REGISTER  STRUCT (PCIMSK0 , PCIMSK1 , PCIMSK2)
typedef struct{
	uint8_t pcint0 : 1;
	uint8_t pcint1 : 1;
	uint8_t pcint2 : 1;
	uint8_t pcint3 : 1;
	uint8_t pcint4 : 1;
	uint8_t pcint5 : 1;
	uint8_t reserved0 :2;
	uint8_t pcint8 : 1;
	uint8_t pcint9 : 1;
	uint8_t pcint10 : 1;
	uint8_t pcint11 : 1;
	uint8_t pcint12 : 1;
	uint8_t pcint13 : 1;
	uint8_t pcint14 : 1;
	uint8_t reserved1 :1;
	uint8_t pcint16 : 1;
	uint8_t pcint17 : 1;
	uint8_t pcint18 : 1;
	uint8_t pcint19 : 1;
	uint8_t pcint20 : 1;
	uint8_t pcint21 : 1;
	uint8_t pcint22 : 1;
	uint8_t pcint23 : 1;
}PCIMSK_T,*PCIMSK_PTR_T;


#endif
