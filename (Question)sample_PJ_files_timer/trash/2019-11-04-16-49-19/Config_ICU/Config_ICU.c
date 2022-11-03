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
* File Name    : Config_ICU.c
* Version      : 1.0.0
* Device(s)    : R7F701649
* Description  : This file implements device driver for Config_ICU.
* Creation Date: 2019-11-01
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
#include "Config_ICU.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ICU_Create
* Description  : This function initializes the ICU module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ICU_Create(void)
{
    /* Disable INTP12 operation and clear request */
    INTC2.ICP12.BIT.MKP12 = _INT_PROCESSING_DISABLED;
    INTC2.ICP12.BIT.RFP12 = _INT_REQUEST_NOT_OCCUR;
    /* Set INTP12 setting */
    INTC2.ICP12.BIT.TBP12 = _INT_TABLE_VECTOR;
    INTC2.ICP12.UINT16 &= _INT_PRIORITY_LOWEST;
    FCLA0.CTL4_INTPH = _INTC_EDGE_FALLING;
    /* Synchronization processing */
    g_cg_sync_read = FCLA0.CTL4_INTPH;
    __syncp();
    /* Set INTP12 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT9;
    PORT.PBDC0 &= _PORT_CLEAR_BIT9;
    PORT.PM0 |= _PORT_SET_BIT9;
    PORT.PMC0 &= _PORT_CLEAR_BIT9;
    PORT.PFC0 &= _PORT_CLEAR_BIT9;
    PORT.PFCE0 &= _PORT_CLEAR_BIT9;
    PORT.PFCAE0 &= _PORT_CLEAR_BIT9;
    PORT.PMC0 |= _PORT_SET_BIT9;

    R_Config_ICU_Create_UserInit();
}
/***********************************************************************************************************************
* Function Name: R_Config_ICU_INTP12_Start
* Description  : This function enables INTP12 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ICU_INTP12_Start(void)
{
    /* Clear INTP12 request and enable operation */
    INTC2.ICP12.BIT.RFP12 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP12.BIT.MKP12 = _INT_PROCESSING_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_Config_ICU_INTP12_Stop
* Description  : This function disables INTP12 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ICU_INTP12_Stop(void)
{
    /* Disable INTP12 operation and clear request */
    INTC2.ICP12.BIT.MKP12 = _INT_PROCESSING_DISABLED;
    INTC2.ICP12.BIT.RFP12 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP12.UINT16;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
