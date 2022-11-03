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
* File Name    : Config_PORT.c
* Version      : 1.0.0
* Device(s)    : R7F701649
* Description  : This file implements device driver for Config_PORT.
* Creation Date: 2019-11-08
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
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

extern volatile uint32_t g_cg_sync_read;
/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the PORT
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_Create(void)
{
    PORT.PIBC1 = _PORT_PIBC_INIT;
    PORT.PBDC1 = _PORT_PBDC_INIT;
    PORT.PM1 = _PORT_PM_INIT;
    PORT.PMC1 = _PORT_PMC_INIT;
    /* PORT1 setting */
    PORT.PPCMD1 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC1 = _PORT_PDSCn14_SLOW_MODE_SELECT | _PORT_PDSCn15_SLOW_MODE_SELECT;
    PORT.PDSC1 = (uint32_t) ~( _PORT_PDSCn14_SLOW_MODE_SELECT | _PORT_PDSCn15_SLOW_MODE_SELECT);
    PORT.PDSC1 = _PORT_PDSCn14_SLOW_MODE_SELECT | _PORT_PDSCn15_SLOW_MODE_SELECT;
    PORT.PPCMD1 = _WRITE_PROTECT_COMMAND;
    PORT.PODC1 = _PORT_PODCn14_PUSH_PULL | _PORT_PODCn15_PUSH_PULL;
    PORT.PODC1 = (uint32_t) ~( _PORT_PODCn14_PUSH_PULL | _PORT_PODCn15_PUSH_PULL);
    PORT.PODC1 = _PORT_PODCn14_PUSH_PULL | _PORT_PODCn15_PUSH_PULL;
    PORT.PBDC1 = _PORT_PBDCn14_MODE_DISABLED | _PORT_PBDCn15_MODE_DISABLED;
    PORT.P1 = _PORT_Pn14_OUTPUT_LOW | _PORT_Pn15_OUTPUT_LOW;
    PORT.PM1 = _PORT_PM1_DEFAULT_VALUE | _PORT_PMn0_MODE_UNUSED | _PORT_PMn1_MODE_UNUSED | _PORT_PMn2_MODE_UNUSED | 
               _PORT_PMn3_MODE_UNUSED | _PORT_PMn4_MODE_UNUSED | _PORT_PMn5_MODE_UNUSED | _PORT_PMn8_MODE_UNUSED | 
               _PORT_PMn9_MODE_UNUSED | _PORT_PMn10_MODE_UNUSED | _PORT_PMn11_MODE_UNUSED | _PORT_PMn12_MODE_UNUSED | 
               _PORT_PMn13_MODE_UNUSED | _PORT_PMn14_MODE_OUTPUT | _PORT_PMn15_MODE_OUTPUT;
    /* Synchronization processing */
    g_cg_sync_read = PORT.PM1;
    __syncp();
	
    R_Config_PORT_Create_UserInit();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
