/*
 * led.c
 *
 *  Created on: 22-Aug-2023
 *      Author: Dell
 */

#include <string.h>
#include "r_smc_entry.h"
#include "rx651.h"

void led (void);

void led(void)
{
 if(BUTTON_1 == 0)
	 {
      RED_LED = 1;
      delay_100us(500);
      RED_LED = 0;
      delay_100us(1000);
      GREEN_LED = 1;
      delay_100us(1000);
      GREEN_LED = 0;
      delay_100us(2500);
	   }

	 else {
		 GREEN_LED = 0;
		 RED_LED = 0;
	 }
}
