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
* File Name    : Config_TAUD0_1.c
* Version      : 1.3.1
* Device(s)    : R7F701649
* Description  : This file implements device driver for Config_TAUD0_1.
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
#include "Config_TAUD0_1.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAUD0_1_Create
* Description  : This function initializes the TAUD01 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUD0_1_Create(void)
{
    /* Disable channel 1 counter operation */
    TAUD0.TT |= _TAUD_CHANNEL1_COUNTER_STOP;
    /* Disable INTTAUD0I1 operation and clear request */
    INTC2.ICTAUD0I1.BIT.MKTAUD0I1 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUD0I1.BIT.RFTAUD0I1 = _INT_REQUEST_NOT_OCCUR;
    /* Set INTTAUD0I1 setting */
    INTC2.ICTAUD0I1.BIT.TBTAUD0I1 = _INT_TABLE_VECTOR;
    INTC2.ICTAUD0I1.UINT16 &= _INT_PRIORITY_LOWEST;
    TAUD0.TPS &= _TAUD_CK0_PRS_CLEAR;
    TAUD0.TPS |= _TAUD_CK0_PRE_PCLK_15;
    /* Set channel 1 setting */
    TAUD0.CMOR1 = _TAUD_SELECTION_CK0 | _TAUD_COUNT_CLOCK_PCLK | _TAUD_INDEPENDENT_CHANNEL | 
                  _TAUD_START_TRIGGER_SOFTWARE | _TAUD_OVERFLOW_AUTO_CLEAR | _TAUD_INTERVAL_TIMER_MODE | 
                  _TAUD_START_INT_NOT_GENERATED;
    /* Set compare match register */
    TAUD0.CMUR1 = _TAUD_INPUT_EDGE_UNUSED;
    TAUD0.CDR1 = _TAUD01_COMPARE_VALUE;
    /* Set output mode setting */
    TAUD0.TOE |= _TAUD_CHANNEL1_ENABLES_OUTPUT_MODE;
    TAUD0.TOM &= _TAUD_CHANNEL1_INDEPENDENT_OUTPUT_MODE;
    TAUD0.TOC &= _TAUD_CHANNEL1_OPERATION_MODE1;
    TAUD0.TOL &= _TAUD_CHANNEL1_POSITIVE_LOGIC;
    TAUD0.TDE &= _TAUD_CHANNEL1_DISABLE_DEAD_TIME_OPERATE;
    TAUD0.TDM &= _TAUD_CHANNEL1_DETECTING_DUTY_CYCLE;
    TAUD0.TDL &= _TAUD_CHANNEL1_NORMAL_PHASE;
    TAUD0.TRE &= _TAUD_CHANNEL1_REAL_TIME_OUTPUT_DISABLES;
    /* Synchronization processing */
    g_cg_sync_read = TAUD0.TPS;
    __syncp();
    
    /* Set TAUD0O1 pin */
    PORT.PIBC10 &= _PORT_CLEAR_BIT0;
    PORT.PBDC10 &= _PORT_CLEAR_BIT0;
    PORT.PM10 |= _PORT_SET_BIT0;
    PORT.PMC10 &= _PORT_CLEAR_BIT0;
    PORT.PIPC10 &= _PORT_CLEAR_BIT0;
    PORT.PFC10 &= _PORT_CLEAR_BIT0;
    PORT.PFCE10 &= _PORT_CLEAR_BIT0;
    PORT.PFCAE10 &= _PORT_CLEAR_BIT0;
    PORT.PMC10 |= _PORT_SET_BIT0;
    PORT.PM10 &= _PORT_CLEAR_BIT0;

    R_Config_TAUD0_1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TAUD0_1_Start
* Description  : This function starts the TAUD01 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUD0_1_Start(void)
{
    /* Clear INTTAUD0I1 request and enable operation */
    INTC2.ICTAUD0I1.BIT.RFTAUD0I1 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUD0I1.BIT.MKTAUD0I1 = _INT_PROCESSING_ENABLED;
    /* Enable channel 1 counter operation */
    TAUD0.TS |= _TAUD_CHANNEL1_COUNTER_START;
}

/***********************************************************************************************************************
* Function Name: R_Config_TAUD0_1_Stop
* Description  : This function stop the TAUD01 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUD0_1_Stop(void)
{
    /* Disable channel 1 counter operation */
    TAUD0.TT |= _TAUD_CHANNEL1_COUNTER_STOP;
    /* Disable INTTAUD0I1 operation and clear request */
    INTC2.ICTAUD0I1.BIT.MKTAUD0I1 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUD0I1.BIT.RFTAUD0I1 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = TAUD0.TT;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
