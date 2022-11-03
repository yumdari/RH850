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
* File Name    : Config_CSIG0.c
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
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

extern volatile uint32_t g_cg_sync_read;
volatile uint16_t  g_csig0_tx_num;                        /* csig0 transmit data number */
volatile uint16_t  g_csig0_rx_num;                        /* csig0 receive data number */
volatile uint16_t  g_csig0_rx_total_num;                  /* csig0 receive data total times */
volatile uint16_t * gp_csig0_tx_address;                  /* csig0 transmit buffer address */
volatile uint16_t * gp_csig0_rx_address;                  /* csig0 receive buffer address */
/***********************************************************************************************************************
* Function Name: R_Config_CSIG0_Create
* Description  : This function This function initializes the Config_CSIG0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIG0_Create(void)
{
    uint32_t tmp_port;
	
    CSIG0.CTL0 = _CSIG_OPERATION_CLOCK_STOP;
    /* Disable INTCSIG0IC operation and clear request */
    INTC1.ICCSIG0IC.BIT.MKCSIG0IC = _INT_PROCESSING_DISABLED;
    INTC1.ICCSIG0IC.BIT.RFCSIG0IC = _INT_REQUEST_NOT_OCCUR;
    /* Set CSIG0 interrupt(INTCSIG0IC) setting */
    INTC1.ICCSIG0IC.BIT.TBCSIG0IC = _INT_TABLE_VECTOR;
    INTC1.ICCSIG0IC.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set CSIG0 control setting */
    CSIG0.CTL1 = _CSIG_CLOCK_INVERTING_HIGH | _CSIG_INTERRUPT_TIMING_NORMAL | _CSIG_DATA_CONSISTENCY_CHECK_DISABLE | 
                 _CSIG_HANDSHAKE_DISABLE | _CSIG_SLAVE_SELECT_DISABLE;
    CSIG0.CTL2 = _CSIG0_SELECT_BASIC_CLOCK | _CSIG0_BAUD_RATE;
    CSIG0.BCTL0.BIT.SCE = _CSIG_NEXT_RECEPTION_DISABLE;
    /* Set CSIG0 configuration setting */
    CSIG0.CFG0 = _CSIG_PARITY_NO | _CSIG_DATA_LENGTH_16 | _CSIG_DATA_DIRECTION_MSB | _CSIG_PHASE_SELECTION_TYPE1;
    /* Synchronization processing */
    g_cg_sync_read = CSIG0.CTL1;
    __syncp();
    /* Set CSIG0SC pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT14;
    PORT.PBDC0 &= _PORT_CLEAR_BIT14;
    PORT.PM0 |= _PORT_SET_BIT14;
    PORT.PMC0 &= _PORT_CLEAR_BIT14;
    PORT.PIPC0 &= _PORT_CLEAR_BIT14;
    tmp_port = PORT.PDSC0;
    PORT.PPCMD0 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC0 = (tmp_port | _PORT_SET_BIT14);
    PORT.PDSC0 = (uint32_t) ~(tmp_port | _PORT_SET_BIT14);
    PORT.PDSC0 = (tmp_port | _PORT_SET_BIT14);
    PORT.PFC0 |= _PORT_SET_BIT14;
    PORT.PFCE0 |= _PORT_SET_BIT14;
    PORT.PFCAE0 &= _PORT_CLEAR_BIT14;
    PORT.PIPC0 |= _PORT_SET_BIT14;
    PORT.PMC0 |= _PORT_SET_BIT14;
    /* Set CSIG0SO pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT13;
    PORT.PBDC0 &= _PORT_CLEAR_BIT13;
    PORT.PM0 |= _PORT_SET_BIT13;
    PORT.PMC0 &= _PORT_CLEAR_BIT13;
    PORT.PIPC0 &= _PORT_CLEAR_BIT13;
    tmp_port = PORT.PDSC0;
    PORT.PPCMD0 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC0 = (tmp_port | _PORT_SET_BIT13);
    PORT.PDSC0 = (uint32_t) ~(tmp_port | _PORT_SET_BIT13);
    PORT.PDSC0 = (tmp_port | _PORT_SET_BIT13);
    PORT.PFC0 |= _PORT_SET_BIT13;
    PORT.PFCE0 |= _PORT_SET_BIT13;
    PORT.PFCAE0 &= _PORT_CLEAR_BIT13;
    PORT.PIPC0 |= _PORT_SET_BIT13;
    PORT.PMC0 |= _PORT_SET_BIT13;
    /* Set _CSIG0SSI pin */
    PORT.PIBC10 &= _PORT_CLEAR_BIT4;
    PORT.PBDC10 &= _PORT_CLEAR_BIT4;
    PORT.PM10 |= _PORT_SET_BIT4;
    PORT.PMC10 &= _PORT_CLEAR_BIT4;
    PORT.PIPC10 &= _PORT_CLEAR_BIT4;
    PORT.PFC10 &= _PORT_CLEAR_BIT4;
    PORT.PFCE10 &= _PORT_CLEAR_BIT4;
    PORT.PFCAE10 |= _PORT_SET_BIT4;
    PORT.PMC10 |= _PORT_SET_BIT4;

    R_Config_CSIG0_Create_UserInit();
}
/***********************************************************************************************************************
* Function Name: R_Config_CSIG0_Start
* Description  : This function This function starts the Config_CSIG0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIG0_Start(void)
{
    /* Enable CSIG0 operation */
    CSIG0.CTL0 = _CSIG_OPERATION_CLOCK_PROVIDE | _CSIG_TRANSMISSION_PERMIT | _CSIG_RECEPTION_PROHIBIT | 
                 _CSIG_DIRECTACCESS;
    /* Clear CSIG0 interrupt request and enable operation */
    INTC1.ICCSIG0IC.BIT.RFCSIG0IC = _INT_REQUEST_NOT_OCCUR;
    INTC1.ICCSIG0IC.BIT.MKCSIG0IC = _INT_PROCESSING_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_Config_CSIG0_Stop
* Description  : This function This function stops the CSIG0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIG0_Stop(void)
{
    /* Disable CSIG0 interrupt operation */
    INTC1.ICCSIG0IC.BIT.MKCSIG0IC = _INT_PROCESSING_DISABLED;
    /* Disable CSIG0 operation */
    CSIG0.CTL0 &= (uint8_t) ~_CSIG_TRANSMISSION_PERMIT;
    CSIG0.CTL0 &= (uint8_t) ~_CSIG_OPERATION_CLOCK_PROVIDE;
    /* Synchronization processing */
    g_cg_sync_read = CSIG0.CTL0;
    __syncp();
    /* Clear CSIG0 interrupt operation */
    INTC1.ICCSIG0IC.BIT.RFCSIG0IC = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC1.ICCSIG0IC.UINT16;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_Config_CSIG0_Send
* Description  : This function This function sends CSIG0 data.
* Arguments    : tx_buf -
*                    send buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
***********************************************************************************************************************/
MD_STATUS R_Config_CSIG0_Send(const uint16_t* tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;
    uint32_t regValue = _CSIG_SETTING_INIT;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        /* Set transmit setting */
        gp_csig0_tx_address = (uint16_t*)tx_buf;
        g_csig0_tx_num = tx_num;
        regValue |= *gp_csig0_tx_address;
        /* Disable CSIG0 interrupt operation */
        INTC1.ICCSIG0IC.BIT.MKCSIG0IC = _INT_PROCESSING_DISABLED;
        /* Synchronization processing */
        g_cg_sync_read = INTC1.ICCSIG0IC.UINT16;
        __syncp();
        /* Set transmit data */
        CSIG0.TX0W = regValue;
        gp_csig0_tx_address++;
        g_csig0_tx_num--;
        /* Synchronization processing */
        g_cg_sync_read = CSIG0.CTL1;
        __syncp();
        /* Enable CSIG0 interrupt operation */
        INTC1.ICCSIG0IC.BIT.MKCSIG0IC = _INT_PROCESSING_ENABLED;
        /* Synchronization processing */
        g_cg_sync_read = INTC1.ICCSIG0IC.UINT16;
        __syncp();
    }

    return status;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
