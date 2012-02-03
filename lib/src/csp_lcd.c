/*
* Industrial Application MCU, S3FN41F,
* Developed by Microcontroller Design Team
*
* Copyright 2010 by C&M Solution Group, Samsung Electronics CO.,LTD.
* San #24 Nongseo-Dong,Giheung-Gu,
* 449-711 Youngin-City, Gyeongi-Do, Korea.
* All rights reserved.
*
* This software is the confidential and proprietary information of Samsung
* Electronics CO.,LTD. ("Confidential Information").
* You shall not disclose such Confidential Information and shall use it only
* in accordance with the terms of the license agreement you entered into
* with Samsung.
*
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, iplied or statutory. This includes without limitation
* any warranty or condition with respect to merchantability or fitness for
* any particular purpose, or against the infringements of intellectual property
* rights of others.
*/

/**
 * @file name	csp_lcd.c
 * @description Definitions, Macros and function declarations for IO Configuration
 *
 * @history	History type - NEW/MODify/ADD/DELete
 *  -------------------------------------------------------------------
 * |ver type when         who                 what
 * |---+---+------------+-------------------+--------------------------
 * |0.0 NEW 2010.07.27.   Yh JIN			  Creation
 *  -------------------------------------------------------------------
 * @see	RealView MDK-ARM Version 4.01
 */

/******************************************************************************
* Include Files
******************************************************************************/
#include "csp.h"

/******************************************************************************
****************************  F U N C T I O N S  ******************************
******************************************************************************/
/**
*******************************************************************************
* @brief     LCD Pin configuration (VLCDx, COMx, SEGx)
* @return    None
* @param
*******************************************************************************
*/
void CSP_LCDPinConfig(void)
{
	U32_T rReg = 0;				
	rReg = CSP_IOCONF_GET_MLR0(IOCONF0)& 0x00003FFF;
	CSP_IOCONF_SET_MLR0(IOCONF0,(rReg|0xAAAA8000));
#ifdef DEBUG
	CSP_IOCONF_SET_MHR0(IOCONF0,0xAAAAFAAA);  	//Except SWDIO(0.22), SWDCLK(0.23)
	//CSP_IOCONF_SET_MLR1(IOCONF0,0xAAAAA96A);	//Except UART1 TX(1.3)/RX(1.4) Comm.
	CSP_IOCONF_SET_MLR1(IOCONF0,0xAAA5AAAA);	//Except UART2 TX(1.8)/RX(1.9) Comm.
#endif
#ifndef DEBUG
	CSP_IOCONF_SET_MHR0(IOCONF0,0xAAAAAAAA);
	CSP_IOCONF_SET_MLR1(IOCONF0,0xAAAAAAAA);	
#endif
}
/**
*******************************************************************************
* @brief     LCD Input Clock Source(Fin selected by clock manager) Configuration
* @return    None
* @param
*******************************************************************************
*/
void CSP_LCDClockSrcConfig(eCM_MdCLK clksrc,U32_T Jdiv,U32_T Kdiv)
{
	U32_T rReg = 0;
	rReg = CSP_CM_GET_MR1(CM0)&(~CM_LCDCLK_MASK);
	CSP_CM_SET_MR1(CM0,CM_LCDCLK_SEL(clksrc)|rReg);
	CSP_CM_SET_LCDR(CM0, CM_KDIV(Kdiv)|CM_JDIV(Jdiv));
}

/**
*******************************************************************************
* @brief     LCD Function Enable/Disable Control
* @return    None
* @param
*******************************************************************************
*/
void CSP_LCDEnable(void)
{
	U32_T rReg = 0;
	rReg = CSP_LCDC_GET_CR(LCDC0);
	CSP_LCDC_SET_CR(LCDC0,rReg|LCDC_LCDEN);
}

/**
*******************************************************************************
* @brief     LCD Operating Clock (LCDCLK) Configuration
* @return    None
* @param
*******************************************************************************
*/
void CSP_LCDClockConfig(eClockConfig clkctr, U32_T Prescale, U32_T Cdiv)
{
	if(clkctr == Nodivider)
	{
		CSP_LCDC_SET_CDR(LCDC0, 0x00000000);
	}
	if(clkctr == Dividers)
	{
		CSP_LCDC_SET_CDR(LCDC0, LCDC_CPRE(Prescale)|LCDC_CDC|LCDC_CDIV(Cdiv));
	}
}

/**
*******************************************************************************
* @brief     LCD software reset
* @return    none
* @param     none
*******************************************************************************
*/
void CSP_LCDSoftwareReset(void)
{
	CSP_LCDC_SET_SRR(LCDC0,LCDC_SWRST);
}

/**
*******************************************************************************
* @brief     LCD En/Disable & Display Mode Control
* @return    none
* @param     none
*******************************************************************************
*/
void CSP_LCDDisplayMode(eDisplayMode whichMode,FunctionalStatus endis)
{
	U32_T rReg = 0;

	rReg = CSP_LCDC_GET_CR(LCDC0) & (~(LCDC_LCDEN|LCDC_DISC(0x3)));

	if(endis == ENABLE)
	{
		CSP_LCDC_SET_CR(LCDC0, rReg|LCDC_LCDEN|LCDC_DISC(whichMode));
	}
	if(endis == DISABLE)
	{
		CSP_LCDC_SET_CR(LCDC0, rReg|LCDC_DISC(whichMode));
	}
}

/**
*******************************************************************************
* @brief     LCD Bias Type Configuration	
* @return    None	
* @param     whichType
*******************************************************************************
*/
void CSP_LCDBiasType(eBiasType whichType)
{
	U32_T rReg = 0;
	rReg = CSP_LCDC_GET_CR(LCDC0);

	if(whichType == InternalRbias)
	{
		CSP_LCDC_SET_CR(LCDC0,rReg&(~LCDC_EBIAS));
	}
	if(whichType == ExternalRbias)
	{											   	
		CSP_LCDC_SET_CR(LCDC0,rReg|LCDC_EBIAS);
	}
}

/**
*******************************************************************************
* @brief     LCD Duty & Bias Mode Selection
* @return    None	 
* @param    
*******************************************************************************
*/			  
void CSP_LCDDutyBiasConfig(eDutyBiasMode whichMode)
{
	U32_T rReg = 0;
	rReg = CSP_LCDC_GET_CR(LCDC0)& (~LCDC_DBSEL(0x7));
    CSP_LCDC_SET_CR(LCDC0, rReg|LCDC_DBSEL(whichMode));
}

/**
*******************************************************************************
* @brief     LCD Duty & Bias Mode Selection
* @return    None	 
* @param    
*******************************************************************************
*/			  
void CSP_LCDWriteDisplayMemory(U32_T numMem, U32_T segData)
{
	CSP_LCDC_SET_DMR(LCDC0,numMem,segData);  
}

