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
* @file name	csp_stt.c
* @description Definitions, Macros and function declarations for STT
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.21.   MCU Solution Part   Creation
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
* @brief     Switch on the clock, reset the registers and configure
*            the STT module mode
* @return    None
* @param     stt
* \n          input
* \n          brief description - Pointer to STT structure.
* @param     mode_u32
* \n          input
* \n          brief description - Configure when the counter should be reset.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_STTInit(CSP_STT_T *const stt, U32_T mode_u32)
{
	U32_T delay = 1000;

	/*STT Enable Clock */
	CSP_STT_SET_CEDR(stt, STT_CLKEN);

   /* STT Software Reset */
   CSP_STT_SET_SRR(stt, STT_SWRST);
   while(delay--);

   /* Configure the mode */
   CSP_STT_SET_MR(stt, mode_u32);
}


/**
*******************************************************************************
* @brief     Configure STT Interrupts
* @return    None
* @param     stt
* \n          input
* \n          brief description - Pointer to STT structure.
* @param     intMask_u32
* \n          input
* \n          brief description - Configure which interrupt bits are activated.
* @param     prePrio_u8
* \n          input
* @param     subPrio_u8
* \n          input
* \n          brief description - sub priority
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_STTConfigInterrupt(CSP_STT_T *const stt, U32_T intMask_u32,
							FunctionalStatus newState)
{
	/* Local Variables */
	NVIC_TypeDef *NVICConfig;

	if (newState != DISABLE)
	{
		/* Disable target interrupts */
		CSP_STT_SET_IMSCR(stt, stt->IMSCR & (~intMask_u32));

		/* Clear target interrupt */
		CSP_STT_SET_ICR(stt, intMask_u32);

		/* Enable target interrupts */
		CSP_STT_SET_IMSCR(stt, stt->IMSCR|intMask_u32);
	}
	else
	{
		/* Disable target interrupts */
		CSP_STT_SET_IMSCR(stt, stt->IMSCR & (~intMask_u32));

		/* Clear target interrupt */
		CSP_STT_SET_ICR(stt, intMask_u32);
	}
}

/**
*******************************************************************************
* @brief     Enable STT Seconds Counter and/or Alarm
* @return    None
* @param     stt
* \n          input
* \n          brief description - Pointer to STT structure.
* @param     enableMask_u8
* \n          input
* \n          brief description - Configure which functions (Seconds Counter
*                                 and/or Alarm) are enabled.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_STTEnable(CSP_STT_T *const stt, U8_T enableMask_u8)
{
   /* Enable STT Seconds Counter and/or Alarm */
   CSP_STT_SET_CR(stt, enableMask_u8);
}


/**
*******************************************************************************
* @brief     Disable STT Seconds Counter and/or Alarm
* @return    None
* @param     stt
* \n          input
* \n          brief description - Pointer to STT structure.
* @param     disableMask_u8
* \n          input
* \n          brief description - Configure which functions (Seconds Counter
*                                 and/or Alarm) are disabled.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_STTDisable(CSP_STT_T *const stt, U8_T disableMask_u8)
{
   /* Disable STT Seconds Counter and/or Alarm */
   CSP_STT_SET_CR(stt, disableMask_u8);
}

/**
*******************************************************************************
* @brief     Read the time passed since the last counter reset
* @return    32-bit value of the seconds counter
* @param     stt
* \n          input
* \n          brief description - Pointer to STT structure.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
U32_T CSP_STTGetTime(CSP_STT_T *const stt)
{
   /* Get time in seconds counter */
   return (CSP_STT_GET_CNTR(stt));
}
 
/**
*******************************************************************************
* @brief     Configure the seconds counter time
* @return    None
* @param     stt
* \n          input
* \n          brief description - Pointer to STT structure.
* @param     time_u32
* \n          input
* \n          brief description - Configure the time value.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_STTSetTime(CSP_STT_T *const stt, U32_T time_u32)
{
   /* Set time in seconds counter */
   CSP_STT_SET_CNTR(stt, time_u32);
}

/**
*******************************************************************************
* @brief     Read the Alarm time
* @return    32-bit value of the alarm time
* @param     stt
* \n          input
* \n          brief description - Pointer to STT structure.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
U32_T CSP_STTGetAlarm(CSP_STT_T *const stt)
{
   /* Get Alarm time */
   return(CSP_STT_GET_ALR(stt));
}

/**
*******************************************************************************
* @brief     Configure the Alarm time. An interrupt can be generated
*            when the seconds register reaches this value.
* @return    None
* @param     stt
* \n          input
* \n          brief description - Pointer to STT structure.
* @param     alarm_u32
* \n          input
* \n          brief description - Configure the alarm time.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_STTSetAlarm(CSP_STT_T *const stt, U32_T alarm_u32)
{
   /* Set Alarm time */
   CSP_STT_SET_ALR(stt, alarm_u32);
}
