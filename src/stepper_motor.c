#include "stepper_motor.h"


const unsigned char   Stepping_pattern[9] = {0x00, 0x90,0x80,0xA0,0x20,0x60,0x40,0x50,0x10};  /* Stepping Motor Output Pattern Table */
const unsigned char   Stepping_a_pattern[9] = {0x00, 0x2,0x0,0x1,0x1,0x1,0x0,0x2,0x2};  /* Stepping Motor Output Pattern Table */
const unsigned char   Stepping_b_pattern[9] = {0x00, 0x2,0x2,0x2,0x0,0x1,0x1,0x1,0x0};  /* Stepping Motor Output Pattern Table */
volatile unsigned char Step=1;
volatile int clock_100us ;                           /* Flag activated each mili second    */

#if 0
/*----------------------------------------------------------------------------
  Systick Interrupt Handler
  SysTick interrupt happens every 1 ms	if SysTick_Config(SystemCoreClock / 1000);     Generate interrupt each 1 ms
 *----------------------------------------------------------------------------*/
/**
*****************************************************************************************
 Function Name : SysTick_Handler()

 Description   : Systick Interrupt Handler
  		 SysTick interrupt happens every 1 ms
 		 if SysTick_Config(SystemCoreClock / 1000);

 Input         : Void

 Output        : Void

 Note          :
********************************************************************************************
*/
void SysTick_Handler (void)
{
  		clock_1ms = 1;
}

/**
*****************************************************************************************
 Function Name : SysTick_stop()

 Description   :

 Input         : Void

 Output        : Void

 Note          :
********************************************************************************************
*/
void SysTick_stop()
{
  SysTick->CTRL  = 0;
}

/**
*****************************************************************************************
 Function Name : init_motor()

 Description   :

 Input         : Void

 Output        : Void

 Note          :
********************************************************************************************
*/
void init_motor()
{
	EXCTATION_SIGNAL_PORT_DIR_PFR &= ~EXCTATION_SIGNAL_MASK;
  	EXCTATION_SIGNAL_PORT_DIR_DDR |= EXCTATION_SIGNAL_MASK;        // P3C,PCD,P3E,P3F ARE SET AS OUTPUT
}
#endif
/**
*****************************************************************************************
 Function Name : rotate_motor()

 Description   :

 Input         : unsigned char delay

 Output        : Void

 Note          :
********************************************************************************************
*/
void rotate_motor(unsigned char delay)
{
#if 0
	unsigned int maska = 0,maskb = 0;
	maska = EXCTATION_SIGNAL_A_PORT_IN_DATA & ~EXCTATION_SIGNAL_A_MASK;
	maskb = EXCTATION_SIGNAL_B_PORT_IN_DATA & ~EXCTATION_SIGNAL_B_MASK;

	EXCTATION_SIGNAL_A_PORT_DATA = (Stepping_a_pattern[Step++] << 6) | maska;
	EXCTATION_SIGNAL_B_PORT_DATA = (Stepping_b_pattern[Step++] << 4) | maskb;
#else
	EXCTATION_SIGNAL_PORT_DATA = Stepping_pattern[Step++];
#endif

	delay_100us(delay);
	if(Step == 9) //9
	{
		Step = 1;
	}
}

/**
*****************************************************************************************
 Function Name : rotate_motor_anticlk()

 Description   :

 Input         : void

 Output        : Void

 Note          :
********************************************************************************************
*/
void rotate_motor_anticlk(void)
{
	unsigned int maska = 0,maskb = 0;
	if(Step == 0)
	{
		Step = 8;
	}
#if 1
	maska = EXCTATION_SIGNAL_A_PORT_IN_DATA & ~EXCTATION_SIGNAL_A_MASK;
	maskb = EXCTATION_SIGNAL_B_PORT_IN_DATA & ~EXCTATION_SIGNAL_B_MASK;

	EXCTATION_SIGNAL_A_PORT_DATA = (Stepping_a_pattern[Step] << 6) | maska;
	EXCTATION_SIGNAL_B_PORT_DATA = (Stepping_b_pattern[Step--] << 4) | maskb;
#else
	EXCTATION_SIGNAL_PORT_DATA = Stepping_pattern[Step--];
#endif

	delay_100us(5);
}

/**
*****************************************************************************************
 Function Name : rotate_motor_mm()

 Description   :

 Input         : unsigned int mm

 Output        : Void

 Note          :
********************************************************************************************
*/
void rotate_motor_mm(unsigned int mm)
{
	unsigned int count = 0;

//	count = 4 * 8 * mm;
	count = mm << 5;

	while(count--)
	{
			rotate_motor(5);
	}
	clear_motor_signals();
}

/**
*****************************************************************************************
 Function Name : rotate_motor_mm_r()

 Description   :

 Input         : unsigned char mm

 Output        : Void

 Note          :
********************************************************************************************
*/
void rotate_motor_mm_r(unsigned char mm)
{
	unsigned int count = 0;

//	count = 4 * 8 * mm;
	count = mm << 5;

	while(count--)
	{
		rotate_motor_anticlk();
	}
	clear_motor_signals();
}

/**
*****************************************************************************************
 Function Name : rotate_motor_mm_speed()

 Description   :

 Input         : unsigned int mm, unsigned char delay

 Output        : Void

 Note          :
********************************************************************************************
*/
void rotate_motor_mm_speed(unsigned int mm, unsigned char delay)
{
	unsigned int count = 0;

//	count = 4 * 8 * mm;
	count = mm << 5;

	while(count--)
	{
			rotate_motor(delay << 1);
	}
	clear_motor_signals();
}


/**
*****************************************************************************************
 Function Name : update_excitation()

 Description   :

 Input         : Void

 Output        : Void

 Note          :
********************************************************************************************
*/
void update_excitation(void)
{
#if 0
	unsigned int maska = 0,maskb = 0;
	maska = EXCTATION_SIGNAL_A_PORT_IN_DATA & ~EXCTATION_SIGNAL_A_MASK;
	maskb = EXCTATION_SIGNAL_B_PORT_IN_DATA & ~EXCTATION_SIGNAL_B_MASK;

	EXCTATION_SIGNAL_A_PORT_DATA = (Stepping_a_pattern[Step] << 6) | maska;
	EXCTATION_SIGNAL_B_PORT_DATA = (Stepping_b_pattern[Step++] << 4) | maskb;
#else
	EXCTATION_SIGNAL_PORT_DATA = Stepping_pattern[Step++];
#endif
	if(Step == 9)
	{
		Step = 1;
	}
}


/**
*****************************************************************************************
 Function Name : clear_motor_signals()

 Description   :

 Input         : Void

 Output        : Void

 Note          :
********************************************************************************************
*/
void clear_motor_signals()
{
	unsigned int maska = 0,maskb = 0;
	maska = EXCTATION_SIGNAL_A_PORT_IN_DATA & ~EXCTATION_SIGNAL_A_MASK;
	maskb = EXCTATION_SIGNAL_B_PORT_IN_DATA & ~EXCTATION_SIGNAL_B_MASK;

#if 0
	EXCTATION_SIGNAL_A_PORT_DATA = (Stepping_a_pattern[0] << 6) | maska;
	EXCTATION_SIGNAL_B_PORT_DATA = (Stepping_b_pattern[0] << 4) | maskb;
#else
	EXCTATION_SIGNAL_PORT_DATA = Stepping_pattern[0];
#endif
}

#if 0
/**
*****************************************************************************************
 Function Name : delay_ms()

 Description   :

 Input         : unsigned short val

 Output        : Void

 Note          :
********************************************************************************************
*/
void delay_ms(unsigned short val)
{
	unsigned short i = 0;

	SysTick_Config(SystemCoreClock / 1000); 	/* Generate interrupt each 1 ms */
	for(i = 0; i < val; i++)
	{
		while (!clock_1ms);
		{
		  clock_1ms = 0;
		}
	}
	SysTick_stop();
}
#endif
/**
*****************************************************************************************
 Function Name : delay_100us()

 Description   :

 Input         : unsigned short val

 Output        : Void

 Note          :
********************************************************************************************
*/
void delay_100us(unsigned short val)
{
	unsigned short i = 0;

	R_Config_CMT0_Start(); 	// Generate interrupt each 1 ms
	for(i = 0; i < val; i++)
	{
		while (!clock_100us);
		{
		  clock_100us = 0;
		}
	}
	R_Config_CMT0_Stop();
}

#if 0
/**
*****************************************************************************************
 Function Name : delay_10us()

 Description   :

 Input         : unsigned short val

 Output        : Void

 Note          :
********************************************************************************************
*/
void delay_10us(unsigned short val)
{
	unsigned short i = 0;

	SysTick_Config(SystemCoreClock / 100000); 	/* Generate interrupt each 1 ms */
	for(i = 0; i < val; i++)
	{
		while (!clock_1ms);
		{
		  clock_1ms = 0;
		}
	}
	SysTick_stop();
}

/**
*****************************************************************************************
 Function Name : delay_us()

 Description   :

 Input         : unsigned short val

 Output        : Void

 Note          :
********************************************************************************************
*/
void delay_us(unsigned short val)
{
	unsigned short i = 0;

	SysTick_Config(SystemCoreClock / 1000000); 	/* Generate interrupt each 1 ms */
	for(i = 0; i < val; i++)
	{
		while (!clock_1ms);
		{
		  clock_1ms = 0;
		}
	}
	SysTick_stop();
}
#endif


/**
*****************************************************************************************
 Function Name : test_motor()

 Description   :

 Input         : Void

 Output        : Void

 Note          :
********************************************************************************************
*/
void test_motor(void)
{
	while(1)
		{
	EXCTATION_SIGNAL_A_PORT_DATA = 1<<6;
	EXCTATION_SIGNAL_A_PORT_DATA = 1<<7;
	EXCTATION_SIGNAL_B_PORT_DATA = 1<<4;
	EXCTATION_SIGNAL_B_PORT_DATA = 1<<5;
		}
}

