/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_RSPI0_user.c
* Component Version: 1.12.0
* Device(s)        : R5F56519FxFM
* Description      : This file implements device driver for Config_RSPI0.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_RSPI0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_RSPI0_Create_UserInit
* Description  : This function adds user code after initializing RSPI0
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RSPI0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_transmit_interrupt
* Description  : This function is SPTI0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_RSPI0_SPTI0
#pragma interrupt r_Config_RSPI0_transmit_interrupt(vect=VECT(RSPI0,SPTI0),fint)
#else
#pragma interrupt r_Config_RSPI0_transmit_interrupt(vect=VECT(RSPI0,SPTI0))
#endif
static void r_Config_RSPI0_transmit_interrupt(void)
{
    r_Config_RSPI0_callback_transmitend();
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_receive_interrupt
* Description  : This function is SPRI0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_RSPI0_SPRI0
#pragma interrupt r_Config_RSPI0_receive_interrupt(vect=VECT(RSPI0,SPRI0),fint)
#else
#pragma interrupt r_Config_RSPI0_receive_interrupt(vect=VECT(RSPI0,SPRI0))
#endif
static void r_Config_RSPI0_receive_interrupt(void)
{
    r_Config_RSPI0_callback_receiveend();
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_error_interrupt
* Description  : This function is SPEI0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_Config_RSPI0_error_interrupt(void)
{
    uint8_t err_type;

    /* Disable RSPI function */
    RSPI0.SPCR.BIT.SPE = 0U;


    /* Clear error sources */
    err_type = RSPI0.SPSR.BYTE;
    RSPI0.SPSR.BYTE = 0xA0U;

    if (0U != err_type)
    {
        r_Config_RSPI0_callback_error(err_type);
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_callback_transmitend
* Description  : This function is a callback function when RSPI0 finishes transmission
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_RSPI0_callback_transmitend(void)
{
    /* Start user code for r_Config_RSPI0_callback_transmitend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_callback_receiveend
* Description  : This function is a callback function when RSPI0 finishes reception
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_RSPI0_callback_receiveend(void)
{
    /* Start user code for r_Config_RSPI0_callback_receiveend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_callback_error
* Description  : This function is a callback function when RSPI0 error occurs
* Arguments    : err_type -
*                    error type value
* Return Value : None
***********************************************************************************************************************/

static void r_Config_RSPI0_callback_error(uint8_t err_type)
{
    /* Start user code for r_Config_RSPI0_callback_error. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
