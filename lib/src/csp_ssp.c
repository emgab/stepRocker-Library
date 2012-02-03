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
* @file name	csp_ssp.c
* @description Definitions, Macros and function declarations for SSP(SPI)
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
********************************  I N C L U D E S  *****************************
*******************************************************************************/
#include "csp.h"

/*******************************************************************************
******************************  F U N C T I O N S  *****************************
*******************************************************************************/
/**
********************************************************************************
* @brief	Pin configuration for SSP
* @return	None
* @param	ssp	[in] Pointer to SSP structure
* @todo		None
********************************************************************************
*/
/*
 * SSP0 Port                     SSP1 Port
 * SSPRX0 : P0.7 : PIN27         SSPRX1 : P1.14  : PIN75
 * SSPTX0 : P0.8 : PIN28         SSPTX1 : P1.13  : PIN74
 * SSPCLK0: P0.9 : PIN29         SSPCLK1: P1.12  : PIN73
 * SSPFSS0: P0.10: PIN30         SSPFSS1: P1.11  : PIN72
 */
void CSP_SSPPinConfiguration(CSP_SSP_T *const ssp)
{
	if(ssp==SSP0)
	{
		/*if( (CSP_PIO_SET_CEDR(GPIO0)&GPIO_CLKEN) == GPIO_CLKEN)
		{
			CSP_PIO_SET_ODR(GPIO0, GPIO_P7|GPIO_P8|GPIO_P9|GPIO_P10);
		} */

		/* SSP0 2nd function */
		CSP_IOFunctionConfigure(GROUP0,IO_Port7,IOCONF_F1);
		CSP_IOFunctionConfigure(GROUP0,IO_Port8,IOCONF_F1);
		CSP_IOFunctionConfigure(GROUP0,IO_Port9,IOCONF_F1);
		CSP_IOFunctionConfigure(GROUP0,IO_Port10,IOCONF_F1);
	}
	if(ssp==SSP1)
	{
		/*if( (CSP_GPIO_SET_CEDR(GPIO0)&GPIO_CLKEN) == GPIO_CLKEN)
		{
			CSP_PIO_SET_ODR(GPIO0, GPIO_P14|GPIO_P13|GPIO_P12|GPIO_P11);
		}  */

		/* SSP1 4th function */
		CSP_IOFunctionConfigure(GROUP1,IO_Port14,IOCONF_F3);
		CSP_IOFunctionConfigure(GROUP1,IO_Port13,IOCONF_F3);
		CSP_IOFunctionConfigure(GROUP1,IO_Port12,IOCONF_F3);
		CSP_IOFunctionConfigure(GROUP1,IO_Port11,IOCONF_F3);
	}
}
/**
********************************************************************************
* @brief	Initialize SSP
* @return	None
* @param	ssp	[in] Pointer to SSP structure
*			datasize data size
*			serialClock SCR register
*			prescaleDivisor SSPCPSR register
*			master master or slave select
* @todo		None
********************************************************************************
*/
void CSP_SSPInit(CSP_SSP_T *const ssp, U32_T datasize, U32_T serialClock,
									        U32_T prescaleDivisor, U32_T master)
{
	//CSP_SSPPinConfiguration(ssp);

	/* SSCPCR0 reset */
	CSP_SSP_SET_CR0(ssp,SSP_CR0_RST);

	/* Motorola SPI / datasize 0011:4bit ~ 1111:16bit */
	CSP_SSP_SET_CR0(ssp,SSP_FRF(0)|SSP_SPO|SSP_DSS(datasize));//SSP_SPH|

	/* bit rate = FSSPCLK / (CPSDVR * (1+SCR)) */
	/* serial clock rate */
	/* 0=< SCR <=255 */
	CSP_SSP_SET_CR0(ssp,CSP_SSP_GET_CR0(ssp)| SSP_SCR(serialClock));

	/* CPSDVR = prescale Divisor  */
	/*  2=< CPSDVR <=254 */
	CSP_SSP_SET_CPSR(SSP0, prescaleDivisor);

	/* SSCPCR1 reset */
	CSP_SSP_SET_CR1(ssp,SSP_CR1_RST);

	/* Select Master or Slave mode */
	CSP_SSP_SET_CR1(ssp,CSP_SSP_GET_CR1(ssp)|(SSP_MS&master));
}

/**
********************************************************************************
* @brief	Transmit SSP data
* @return	None
* @param	ssp	[in] Pointer to SSP structure.
* @param	sspString ssp transmit data
* @todo		None
********************************************************************************
*/
void CSP_SSPTransmit(CSP_SSP_T *const  ssp, U16_T sspString)
{
   	CSP_SSP_SET_DR(ssp,sspString);
}

/**
********************************************************************************
* @brief	Receive SSP data
* @return	SSPDR ssp receive data
* @param	ssp	[in] Pointer to SSP structure.
* @todo		None
********************************************************************************
*/	  
U16_T CSP_SSPReceive(CSP_SSP_T *const ssp)
{

	return CSP_SSP_GET_DR(ssp);
}

/**
********************************************************************************
* @brief	Enable SSP
* @return	None
* @param	ssp	[in] Pointer to SSP structure.
* @todo		nothing
********************************************************************************
*/
void CSP_SSPEnable(CSP_SSP_T *const ssp)
{
	/*  Enable SSP */
	CSP_SSP_SET_CR1(ssp, CSP_SSP_GET_CR1(ssp) | SSP_SSE);
}

/**
********************************************************************************
* @brief	Disable SSP
* @return	None
* @param	ssp	[in] Pointer to SSP structure.
* @todo		nothing
********************************************************************************
*/
void CSP_SSPDisable(CSP_SSP_T *const ssp)
{
	/* Disable SSP */
	CSP_SSP_SET_CR1(ssp, CSP_SSP_GET_CR1(ssp) & ~SSP_SSE);
}

