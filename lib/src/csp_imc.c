/*
* Industrial Application MCU, S3FN41F,
* Developed by Microcontroller Design Team
*
* Copyright 2009 by C&M Solution Group, Samsung Electronics CO.,LTD.
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
* kind, either express, implied or statutory. This includes without limitation
* any warranty or condition with respect to merchantability or fitness for
* any particular purpose, or against the infringements of intellectual property
* rights of others.
*/

/**
* @file name	csp_imc.c
* @description Definitions, Macros and function declarations for IMC
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

/*******************************************************************************
******************************  I N C L U D E S  *******************************
*******************************************************************************/
#include "csp.h"
/*******************************************************************************
******************************  F U N C T I O N S  *****************************
*******************************************************************************/
/**
********************************************************************************
* @brief	Enable Inverter Motor Controller
* @return	None
* @param	imc	[in] Pointer to IMC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_IMCEnable(CSP_IMC_T *const imc)
{
	/* Enable Inverter Motor Controller */
	CSP_IMC_SET_CR0(imc, CSP_IMC_GET_CR0(imc) | IMC_IMEN);
}

/**
********************************************************************************
* @brief	Disable Inverter Motor Controller
* @return	None
* @param	imc	[in] Pointer to IMC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_IMCDisable(CSP_IMC_T *const imc)
{
	/* Disable Inverter Motor Controller */
	CSP_IMC_SET_CR0(imc, CSP_IMC_GET_CR0(imc) & ~IMC_IMEN);
}

/**
********************************************************************************
* @brief	Setting for emergency of Inverter Motor Controller
* @return	None
* @param	imc	[in] Pointer to IMC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_IMCSetFaultControl( CSP_IMC_T *const imc, U8_T pwmoff1_ornot0_atfault,
                            U8_T filterclk_3bit, U8_T define_faultSigtype_2bit,
                            U8_T pwmoutoff1_ornot0, U8_T pwmout_highz1_pwmsig0)
{
	/* Setting for emergency of Inverter Motor Controller */
	CSP_IMC_SET_CR0(imc, CSP_IMC_GET_CR0(imc) & ~( IMC_PWMOFFEN
														|IMC_IMFILTER(0x7)
														|IMC_ESELPWMOFF(0x3)
														|IMC_PWMOUTOFFEN
														|IMC_PWMOUTEN));
	CSP_IMC_SET_CR0(imc,CSP_IMC_GET_CR0(imc)
			| IMC_PWMOFFEN*pwmoff1_ornot0_atfault
			| IMC_IMFILTER(filterclk_3bit)
			| IMC_ESELPWMOFF(define_faultSigtype_2bit)
			| IMC_PWMOUTOFFEN*pwmoutoff1_ornot0
			| IMC_PWMOUTEN*pwmout_highz1_pwmsig0);
}

/**
********************************************************************************
* @brief	Setting IMC pwm compare register value for pwm pulse generation
* @return	None
* @param	imc	[in] Pointer to IMC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_IMCSetPhaseCompareRegisters( CSP_IMC_T *const imc, U16_T topcmp,
U16_T pacmpr, U16_T pbcmpr, U16_T pccmpr, U16_T pacmpf, U16_T pbcmpf, U16_T pccmpf)
{
	/* Setting for emergency of Inverter Motor Controller */
	CSP_IMC_SET_PACRR(imc,pacmpr);
	CSP_IMC_SET_PBCRR(imc,pbcmpr);
	CSP_IMC_SET_PCCRR(imc,pccmpr);
	CSP_IMC_SET_TCR(imc,topcmp);
	CSP_IMC_SET_PACFR(imc,pccmpf);
	CSP_IMC_SET_PBCFR(imc,pbcmpf);
	CSP_IMC_SET_PCCFR(imc,pccmpf);
}
/**
********************************************************************************
* @brief	Setting IMC adccompare register value for pwm pulse generation
* @return	None
* @param	imc	[in] Pointer to IMC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_IMCSetADCCompareRegisters(CSP_IMC_T *const imc,
					U16_T acdcmpr0, U16_T acdcmpr1, U16_T acdcmpr2,
					U16_T acdcmpf0, U16_T acdcmpf1, U16_T acdcmpf2)
{
	/* Setting for emergency of Inverter Motor Controller */
	CSP_IMC_SET_ASCRR0(imc,acdcmpr0);
	CSP_IMC_SET_ASCRR1(imc,acdcmpr1);
	CSP_IMC_SET_ASCRR2(imc,acdcmpr2);
	CSP_IMC_SET_ASCFR0(imc,acdcmpf0);
	CSP_IMC_SET_ASCFR1(imc,acdcmpf1);
	CSP_IMC_SET_ASCFR2(imc,acdcmpf2);
}

/**
********************************************************************************
* @brief	Setting ADC Start Trigger Sources among TOPCMPSEL, 0SEL,
* @			ADCCMPR0SEL,ADCCMPF0SEL,ADCCMPR1SEL,ADCCMPF1SEL,
* @			ADCCMPR2SEL and ADCCMPF2SEL
* @return	None
* @param	imc	[in] Pointer to IMC structure.
* @param	select_compr [in] Select adc start signal
* @todo		nothing
********************************************************************************
*/
void CSP_IMCSetADCStartTriggerSrc(CSP_IMC_T *const imc, U8_T select_compr)
{
	/* Setting for emergency of Inverter Motor Controller */
	CSP_IMC_SET_ASTSR(imc,select_compr);
}

/**
********************************************************************************
* @brief	Setting IMC adccompare register value for pwm pulse generation
* @return	None
* @param	imc	[in] Pointer to IMC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_IMCOutSignalSetting( CSP_IMC_T *const imc, U8_T mode_Tri0_Saw1,
	    	U8_T swap1_ornot0, U8_T pwmup_start_1or0 , U8_T pwndown_start_1or0)
{
	/* Setting for emergency of Inverter Motor Controller */
	CSP_IMC_SET_CR0( imc,  CSP_IMC_GET_CR0(imc) &
			            (~(IMC_IMMODE |IMC_PWMSWAP|IMC_PWMPOLU|IMC_PWMPOLD)));

	CSP_IMC_SET_CR0(imc, CSP_IMC_GET_CR0(imc)
			|(IMC_IMMODE*mode_Tri0_Saw1)
			|(IMC_PWMSWAP*swap1_ornot0)
			|(IMC_PWMPOLU*pwmup_start_1or0)
			|(IMC_PWMPOLD*pwndown_start_1or0));
}

/**
********************************************************************************
* @brief	Setting IMC adccompare register value for pwm pulse generation
* @return	None
* @param	imc	[in] Pointer to IMC structure.
* @todo		nothing
********************************************************************************
*/	  
void CSP_IMCControlPWNOutGateSwitch( CSP_IMC_T *const imc,
					U8_T pwmxu0_on0_off1,U8_T pwmxd0_on0_off1,
					U8_T pwmxu1_on0_off1, U8_T pwmxd1_on0_off1,
					U8_T pwmxu2_on0_off1, U8_T pwmxd2_on0_off1)
{
	CSP_IMC_SET_CR1(imc,CSP_IMC_GET_CR1(imc) & (~(IMC_PWMxU0EN
	        |IMC_PWMxD0EN|IMC_PWMxU1EN|IMC_PWMxD1EN|IMC_PWMxU2EN|IMC_PWMxD2EN)));

	CSP_IMC_SET_CR1( imc, CSP_IMC_GET_CR1(imc)
			|IMC_PWMxU0EN * pwmxu0_on0_off1
			|IMC_PWMxD0EN * pwmxd0_on0_off1
			|IMC_PWMxU1EN * pwmxu1_on0_off1
			|IMC_PWMxD1EN * pwmxd1_on0_off1
			|IMC_PWMxU2EN * pwmxu2_on0_off1
			|IMC_PWMxD2EN * pwmxd2_on0_off1);
}







