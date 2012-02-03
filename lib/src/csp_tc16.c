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
* @file name	csp_tc16.c
* @description Definitions, Macros and function declarations for TCx
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part    Creation
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
 * @brief     Switch on the clock and reset the registers
 * @return    None
 * @param     st
 * \n          input
 * \n          brief description - Pointer to TC16 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC16Init(CSP_TC16_T *const tc16)
{
	/* Enable TC16 Clock */
	tc16->CEDR |= TC16_CLKEN;

	/* TC16 Software Reset */
	tc16->SRR = TC16_SWRST;
}
/**
 *******************************************************************************
 * @brief     Reset and switch off the clock
 * @return    None
 * @param     st
 * \n          input
 * \n          brief description - Pointer to TC16 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC16Close(CSP_TC16_T *const tc16)
{
	/* TC16 Software Reset */
	tc16->SRR = TC16_SWRST;

	/* Disable TC16 Clock */
	tc16->CEDR &= ~TC16_CLKEN;
}

/**
 *******************************************************************************
 * @brief     Configure the TC16
 * @return    None
 * @param     tc16
 * \n          input
 * \n          brief description - Pointer to ST structure.
 * @param     cdiv_u16
 * \n          input
 * \n          brief description - Configure the prescalar
 * @param     tc16size_u32
 * \n          input
 * \n          brief description - Configure the TC16 size
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC16Configure(CSP_TC16_T *const tc16, U32_T csiz_u32, U16_T cdiv_u16,
						U32_T mode_32, U32_T prdr_u32)
{
	/* 16-bit counter */
	CSP_TC16_SET_CSMR(tc16, csiz_u32);

	/* Configure Counter Value */
	CSP_TC16_SET_CSR(tc16, mode_32);	// mode, pwm_state, stop_state
	CSP_TC16_SET_CDR(tc16, cdiv_u16);	// clock divider

	/* Configure Data */ 
	CSP_TC16_SET_PRDR(tc16, prdr_u32);	// interval
}	  
/**
 *******************************************************************************
 * @brief     Configure the TC16 pulse
 * @return    None
 * @param     tc16
 * \n          input
 * \n          brief description - Pointer to ST structure.
 * @param     cdiv_u16
 * \n          input
 * \n          brief description - Configure the prescalar
 * @param     tc16size_u32
 * \n          input
 * \n          brief description - Configure the TC16 size
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC16ConfigPulse(CSP_TC16_T *const tc16,
						 U32_T pwmstate_u32,
						 U32_T pulse_u32)
{
	/* Configure PWM mode */
	CSP_TC16_SET_CSR(tc16, pwmstate_u32);	/* pwm_state */

	CSP_TC16_SET_PULR(tc16, pulse_u32);		/* interval */
}

/**
 *******************************************************************************
 * @brief     Configure TC16 Interrupts
 * @return    None
 * @param     tc16
 * \n          input
 * \n          brief description - Pointer to TC16 structure.
 * @param     intMask_u32
 * \n          input
 * \n          brief description - Configure which interrupt bits are activated.
 * @param     newState
 * \n          input
 * \n          brief description - Enable or disable
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC16ConfigInterrupt(CSP_TC16_T *const tc16,
							 U32_T intMask_u32, 
 							 FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		/* Disable target interrupts */
		CSP_TC16_SET_IMSCR(tc16, tc16->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_TC16_SET_ICR(tc16, intMask_u32);

		/* Enable target interrupts */
		CSP_TC16_SET_IMSCR(tc16, tc16->IMSCR|intMask_u32);
	}
	else
	{
		/* Disable target interrupts */
		CSP_TC16_SET_IMSCR(tc16, tc16->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_TC16_SET_ICR(tc16, intMask_u32);
	}
}

/**
 *******************************************************************************
 * @brief     Enable TC16 Channel
 * @return    None
 * @param     tc16
 * \n          input
 * \n          brief description - Pointer to TC16 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC16Enable(CSP_TC16_T *const tc16)
{
	/* Enable ST Channel */
	tc16->CSR = TC16_START;
}		 

/**
 *******************************************************************************
 * @brief     Update TC16 Control Register
 * @return    None
 * @param     tc16
 * \n          input
 * \n          brief description - Pointer to TC16 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC16Update(CSP_TC16_T *const tc16)
{
	/* Enable TC */
	tc16->CSR = TC16_UPDATE;
}
/**
 *******************************************************************************
 * @brief     Disable TC16 Channel
 * @return    None
 * @param     tc16
 * \n          input
 * \n          brief description - Pointer to TC16 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC16Disable(CSP_TC16_T *const tc16)
{
	/* Disable TC */
	tc16->CCR = TC16_START;
}

/**
*******************************************************************************
* @brief     Get flag status from SR register
* @return    none
* @param     Flag
* \n          input
* \n          brief description - Flags in SR register
* @param     FlagStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Flag is set
*           - RESET: Flag is reset
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
FlagStatus CSP_TC16GetFlagStatus(CSP_TC16_T *const tc16, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_TC16_GET_SR(tc16) & TC16_SR_MASK;

	if ((tmp & Flag) != Flag)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}
/**
*******************************************************************************
* @brief     Get flag status from RISR
* @return    none
* @param     Flag
* \n          input
* \n          brief description - Flags in SR register
* @param     FlagStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Flag is set
*           - RESET: Flag is reset
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
FlagStatus CSP_TC16GetRawITStatus(CSP_TC16_T *const tc16, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_TC16_GET_RISR(tc16) & TC16_RISR_MASK;

	if ((tmp & Flag) != Flag)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}
/**
*******************************************************************************
* @brief     Get flag status from MISR
* @return    none
* @param     Flag
* \n          input
* \n          brief description - Flags in SR register
* @param     FlagStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Flag is set
*           - RESET: Flag is reset
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
FlagStatus CSP_TC16GetMaskedITStatus(CSP_TC16_T *const tc16, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_TC16_GET_MISR(tc16) & TC16_MISR_MASK;

	if ((tmp & Flag) != Flag)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}
/**
*******************************************************************************
* @brief     Clear status by writing '1' to ICR register
* @return    none
* @param     Flag
* \n          input
* \n          brief description - Flag to be cleared
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_TC16ClearITFlag(CSP_TC16_T *const tc16, U32_T Flag)
{
	CSP_TC16_SET_ICR(tc16, Flag);
}


