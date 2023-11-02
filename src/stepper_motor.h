#ifndef __STEPPER_MOTOR_H
#define __STEPPER_MOTOR_H

#include "r_cg_macrodriver.h"


#define EXCTATION_SIGNAL_PORT_DATA			PORTD.PODR.BYTE
#define EXCTATION_SIGNAL_A_PORT_DATA		PORTD.PODR.BYTE
#define EXCTATION_SIGNAL_B_PORT_DATA		PORTD.PODR.BYTE

#define EXCTATION_SIGNAL_A_PORT_IN_DATA		PORTD.PIDR.BYTE
#define EXCTATION_SIGNAL_B_PORT_IN_DATA		PORTD.PIDR.BYTE

//#define EXCTATION_SIGNAL_PORT_CLR	FM3_GPIO->PDOR3

#define EXCTATION_SIGNAL_1_BIT		(1 << 4)	   //	MOTOR A
#define EXCTATION_SIGNAL_2_BIT		(1 << 6)	   //	MOTOR /A
#define EXCTATION_SIGNAL_3_BIT		(1 << 5)	   //	MOTOR B
#define EXCTATION_SIGNAL_4_BIT		(1 << 7)	   //	MOTOR /B

#define DELAY_BTN_EXCITATION_WITHOUT_PALTTEN	10
#define EXCTATION_SIGNAL_A_MASK		(0xC0)//(EXCTATION_SIGNAL_1_BIT | EXCTATION_SIGNAL_2_BIT | EXCTATION_SIGNAL_3_BIT | EXCTATION_SIGNAL_4_BIT)
#define EXCTATION_SIGNAL_B_MASK		(0x30)//(EXCTATION_SIGNAL_1_BIT | EXCTATION_SIGNAL_2_BIT | EXCTATION_SIGNAL_3_BIT | EXCTATION_SIGNAL_4_BIT)


void init_motor(void);

void rotate_motor(unsigned char delay);
void update_excitation(void);
void clear_motor_signals(void);

void delay_ms(unsigned short val);
void delay_100us(unsigned short val);
void delay_10us(unsigned short val);
void delay_us(unsigned short val);
void rotate_motor_mm(unsigned int mm);
void rotate_motor_mm_r(unsigned char mm);
void rotate_motor_mm_speed(unsigned int mm, unsigned char delay);


#endif

