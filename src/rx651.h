/*
 * rx651.h
 *
 *  Created on: 08-Jul-2023
 *      Author: Dell
 */

#ifndef RX651_H_
#define RX651_H_

#define GREEN_LED            PORTC.PODR.BIT.B0
#define RED_LED              PORTC.PODR.BIT.B1
#define BUTTON_1             PORTB.PIDR.BIT.B7
#define BUTTON_2             PORTB.PIDR.BIT.B6

#define  ON                   				1
#define  OFF                  				0

#define RS485_RTS_BIT			(PORT3.PODR.BIT.B1)

#define PRINTER_POWER_ENABLE_BIT        PORT0.PODR.BIT.B5
#define MOTOR_POWER_ENABLE_BIT          PORT4.PODR.BIT.B2
#define MOTOR_ENABLE_PORT_BYTE 			PORTD.PODR.BYTE
#define MOTOR_DRIVE_ENABLE_BIT 		    (PORT4.PODR.BIT.B2)


#define MCU_STROBE_1_BIT_DATA				PORT5.PODR.BYTE
#define MCU_STROBE_1_BIT					0x08		//0x02 //(1<<1)

#define MCU_STROBE_2_BIT_DATA				PORT1.PODR.BYTE
#define MCU_STROBE_2_BIT					0x04		//0x80 // (1<< 0)

#define MCU_STROBE_3_BIT_DATA				PORT1.PODR.BYTE
#define MCU_STROBE_3_BIT					0x08		//0x40 //(1<<5)

#define MCU_STROBE_4_BIT_DATA				PORT4.PODR.BYTE
#define MCU_STROBE_4_BIT					0x01		//0x20 //(1<<7)

#define MCU_STROBE_5_BIT_DATA				PORT1.PODR.BYTE
#define MCU_STROBE_5_BIT					0x80		//0x10 //(1<<6)

#define MCU_STROBE_6_BIT_DATA				PORT2.PODR.BYTE
#define MCU_STROBE_6_BIT					0x80		//0x04 //(1<<6)

#define MCU_STROBE_7_BIT_DATA				PORT2.PODR.BYTE
#define MCU_STROBE_7_BIT					0x80		//0x08 //(1<<6)



#endif /* RX651_H_ */
