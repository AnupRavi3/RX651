/*
 * task.c
 *
 *  Created on: 22-Aug-2023
 *      Author: Dell
 */



#include <string.h>
#include "r_smc_entry.h"
#include "rx651.h"

void RotateMotor(int8_t Dir,short PWMDelay);
int8_t mtrPos = 0;

void RotateMotor(int8_t times,short PWMDelay)
{
	unsigned char motor_data[9] = {0x00, 0x90,0x80,0xA0,0x20,0x60,0x40,0x50,0x10};  /* Stepping Motor Output Pattern Table */

	MOTOR_POWER_ENABLE_BIT = 1;

	while(times--)
	{
		for(int steps = 0 ; steps<9 ; steps++)
		{
			MOTOR_ENABLE_PORT_BYTE = motor_data[steps];
			delay_100us(PWMDelay);
			mtrPos = steps;
		}
	}

}

/**
********************************************************************************************
 Function Name : clear_strobe_signals()

 Description   : Disable Strobe Lines

 Input         : uint8_t tp

 Output        : void

 Note          :
********************************************************************************************
*/
void clear_strobe_signals(uint8_t tp)
{
	if(tp)
	{
		MCU_STROBE_1_BIT_DATA &= (uint8_t)~MCU_STROBE_1_BIT;
		MCU_STROBE_3_BIT_DATA &= ~MCU_STROBE_3_BIT;
		MCU_STROBE_2_BIT_DATA &= ~MCU_STROBE_2_BIT;
		MCU_STROBE_4_BIT_DATA &= ~MCU_STROBE_4_BIT;
		MCU_STROBE_5_BIT_DATA &= ~MCU_STROBE_5_BIT;
		MCU_STROBE_6_BIT_DATA &= ~MCU_STROBE_6_BIT;
	}
}
/**************************************************************
 * MOTOR WORKING FUNCTION
 */

void motor(void);

void motor(void)
{
	if(BUTTON_2 == 0)
	{
		PRINTER_POWER_ENABLE_BIT = ON;
		MOTOR_POWER_ENABLE_BIT = ON;
		clear_strobe_signals(1);
		RotateMotor(5,6);
		RotateMotor(1,3);
	}
	else
	{
		PRINTER_POWER_ENABLE_BIT = OFF;
		MOTOR_POWER_ENABLE_BIT = OFF;
	}

}


