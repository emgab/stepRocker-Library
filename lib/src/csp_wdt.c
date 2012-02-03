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
* @file name	csp_wdt.c
* @description Definitions, Macros and function declarations for WDT
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	 Creation
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
* @brief     Configure the WDT module mode
* @return    none
* @param     wdt
* \n          input
* \n          brief description - Pointer to WDT structure
* @param     mode_u32
* \n          input
* \n          brief description - Configure the mode of running and especially
*                                 the clock selection.
* @param     overflowMode_u32
* \n          input
* \n          brief description - Configure the WatchDog Overflow Mode.
* @param     pendingMode_u32
* \n          input
* \n          brief description -  Configure the WatchDog Pending Window Mode.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_WDTInit(CSP_WDT_T *wdt, U32_T mode_u32, 
					U32_T overflowMode_u32, U32_T pendingMode_u32)
{
   /* Define Clock and WDT Pending Window */
   CSP_WDT_SET_MR(wdt, (mode_u32));
   CSP_WDT_SET_PWR(wdt, (pendingMode_u32));

   /* Set Overflow Mode */
   CSP_WDT_SET_OMR(wdt, (overflowMode_u32));
}


/**
*******************************************************************************
* @brief     Configure WDT Interrupts
* @return    None
* @param     wdt
* \n          input
* \n          brief description - Pointer to WDT structure
* @param     intMask_u32
* \n          input
* \n          brief description - Configure which interrupt bits are activated.
* @param     prePrio_u8
* \n          input
* \n          brief description - preemption priority
* @param     subPrio_u8
* \n          input
* \n          brief description - sub priority
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_WDTConfigInterrupt(CSP_WDT_T *wdt, U32_T intMask_u32,
                           FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		/* Disable target interrupts */
		CSP_WDT_SET_IMSCR(wdt,wdt->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_WDT_SET_ICR(wdt, intMask_u32);

		/* Enable target interrupts */
		CSP_WDT_SET_IMSCR(wdt, wdt->IMSCR|intMask_u32);
	}
	else
	{
		/* Disable target interrupts */
		CSP_WDT_SET_IMSCR(wdt,wdt->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_WDT_SET_ICR(wdt, intMask_u32);
	}
}


/**
*******************************************************************************
* @brief     Enable WatchDog
* @return    None
* @param     wdt
* \n          input
* \n          brief description - Pointer to WDT structure
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_WDTEnable(CSP_WDT_T *wdt)
{
   /* Enable WatchDog */
   CSP_WDT_SET_OMR(wdt, (CSP_WDT_GET_OMR(wdt) | WDT_WDTEN));
}

/**
*******************************************************************************
* @brief     Disable WatchDog
* @return    None
* @param     wdt
* \n          input
* \n          brief description - Pointer to WDT structure
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_WDTDisable(CSP_WDT_T *wdt)
{
   /* Disable WatchDog */
   CSP_WDT_SET_OMR(wdt, (CSP_WDT_GET_OMR(wdt) & (~WDT_WDTEN)));

}

/**
*******************************************************************************
* @brief     Restart Watchdog Counter
* @return    None
* @param     wdt
* \n          input
* \n          brief description - Pointer to WDT structure
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_WDTCounterRestart(CSP_WDT_T *wdt)
{
	U32_T rReg = 0;

	rReg = CSP_WDT_GET_SR(wdt)& WDT_DBGEN;

   /* Restart Key */
   CSP_WDT_SET_CR(wdt, rReg|WDT_RSTKEY);
}
