/***********************************************************************
*
*  FILE        : rx651.c
*  DATE        : 2023-07-07
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "rx651.h"

#include "r_smc_entry.h"

#include <string.h>
#include "stepper_motor.h"

void main(void);


void main(void)
{
	while(1)
	{
		led();
		motor();
	}
}


