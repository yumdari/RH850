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
* Copyright (C) 2016, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_CSIG0_user.c
* Version      : 1.0.0
* Device(s)    : R7F701649
* Description  : This file implements device driver for Config_CSIG0.
* Creation Date: 2019-10-28
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
#include "r_cg_userdefine.h"
#include "Config_CSIG0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint16_t  g_csig0_tx_num;                        /* csig0 transmit data number */
extern volatile uint16_t  g_csig0_rx_num;                        /* csig0 receive data number */
extern volatile uint16_t  g_csig0_rx_total_num;                  /* csig0 receive data total times */
extern volatile uint16_t * gp_csig0_tx_address;                   /* csig0 transmit buffer address */
extern volatile uint16_t * gp_csig0_rx_address;                   /* csig0 receive buffer address */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSIG0_Create_UserInit
* Description  : This function adds user code after initializing CSIG module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIG0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_Config_CSIG0_interrupt_send
* Description  : This function is CSIG0 send interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma ghs interrupt
void r_Config_CSIG0_interrupt_send(void)
{
    uint32_t regValue = CSIG0.TX0W & _CSIG_SETTING_INIT;
    if (g_csig0_tx_num > 0U)
    {
        regValue =  *gp_csig0_tx_address | regValue;
        CSIG0.TX0W = regValue;
        gp_csig0_tx_address++;
        g_csig0_tx_num--;
    }
    else
    {
    	r_Config_CSIG0_callback_sendend();
    }
}
/***********************************************************************************************************************
* Function Name: r_Config_CSIG0_callback_sendend
* Description  : This function is CSIG0 sendend callback service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_Config_CSIG0_callback_sendend(void)
{
    /* Start user code for r_Config_CSIG0_callback_sendend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

