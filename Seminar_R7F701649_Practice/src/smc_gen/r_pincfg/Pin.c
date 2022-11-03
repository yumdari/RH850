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
* Copyright (C) . All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Pin.c
* Version      : 1.0.0.0
* Device(s)    : R7F701649
* Description  : This file implements SMC pin code generation.
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
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Pins_Create
* Description  : This function initializes Smart Configurator pins
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Pins_Create(void)
{
	/* Set CSIG0SC(P0_14) pin */
	PORT.PIBC0 &= _PORT_CLEAR_BIT14;
	PORT.PBDC0 &= _PORT_CLEAR_BIT14;
	PORT.PM0 |= _PORT_SET_BIT14;
	PORT.PMC0 &= _PORT_CLEAR_BIT14;
	PORT.PIPC0 &= _PORT_CLEAR_BIT14;
	PORT.PFC0 |= _PORT_SET_BIT14;
	PORT.PFCE0 |= _PORT_SET_BIT14;
	PORT.PFCAE0 &= _PORT_CLEAR_BIT14;
	PORT.PIPC0 |= _PORT_SET_BIT14;
	PORT.PMC0 |= _PORT_SET_BIT14;

	/* Set CSIG0SO(P0_13) pin */
	PORT.PIBC0 &= _PORT_CLEAR_BIT13;
	PORT.PBDC0 &= _PORT_CLEAR_BIT13;
	PORT.PM0 |= _PORT_SET_BIT13;
	PORT.PMC0 &= _PORT_CLEAR_BIT13;
	PORT.PIPC0 &= _PORT_CLEAR_BIT13;
	PORT.PFC0 |= _PORT_SET_BIT13;
	PORT.PFCE0 |= _PORT_SET_BIT13;
	PORT.PFCAE0 &= _PORT_CLEAR_BIT13;
	PORT.PIPC0 |= _PORT_SET_BIT13;
	PORT.PMC0 |= _PORT_SET_BIT13;

	/* Set _CSIG0SSI(P10_4) pin */
	PORT.PIBC10 &= _PORT_CLEAR_BIT4;
	PORT.PBDC10 &= _PORT_CLEAR_BIT4;
	PORT.PM10 |= _PORT_SET_BIT4;
	PORT.PMC10 &= _PORT_CLEAR_BIT4;
	PORT.PIPC10 &= _PORT_CLEAR_BIT4;
	PORT.PFC10 &= _PORT_CLEAR_BIT4;
	PORT.PFCE10 &= _PORT_CLEAR_BIT4;
	PORT.PFCAE10 |= _PORT_SET_BIT4;
	PORT.PMC10 |= _PORT_SET_BIT4;

}
