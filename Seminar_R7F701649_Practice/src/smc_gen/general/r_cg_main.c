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
* File Name    : r_cg_main.c
* Version      : 1.0.0
* Device(s)    : R7F701649
* Description  : This function implements main function.
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
#include "Config_CSIG0.h"
#include "Config_PORT.h"
#include "r_cg_cgc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
unsigned short send_data[19] = {0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 
								0x8000, 0x4000, 0x2000, 0x1000, 0x0800, 0x0400, 0x0200 ,0x0100, 
								0x0000, 0xFFFF, 0x0000};
unsigned int i=0, j, k;
/* End user code. Do not edit comment generated here */

void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_Config_CSIG0_Create();
    /* Start user code for main. Do not edit comment generated here */
    R_Config_CSIG0_Start();	/* Call start API */
    while (1U)
    {
	for(j=0; j<8333; j++)
	{
	    for(k=0; k<1000; k++);
	}
	{};          // Delay

        R_Config_CSIG0_Send(&send_data[i++], 1);   // Call send API
        if(i > 19){i = 0;}
        while(CSIG0.STR0&0x80U);            //  Transfer Status Flag
        PORT.P1 |= 0x4000U;	     			//  LE High Level
        //for(j=0; j<5000; j++){};            //  Delay
        PORT.P1 &= ~0x4000U;	     		//  LE Low Level
	
		
    }
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    DI();
    /* Start user code for R_MAIN_UserInit. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    R_Systeminit();
    EI();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
