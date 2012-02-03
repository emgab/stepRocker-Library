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
* @file name	csp_tc32.c
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
 * @param     tc32
 * \n          input
 * \n          brief description - Pointer to TC32 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC32Init(CSP_TC32_T *const tc32)
{
	/* Enable TC32 Clock */
	tc32->CEDR |= TC32_CLKEN;

	/* TC32 Software Reset */
	tc32->SRR = TC32_SWRST;
}
/**
 *******************************************************************************
 * @brief     Reset and switch off the clock
 * @return    None
 * @param     tc32
 * \n          input
 * \n          brief description - Pointer to TC32 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC32Close(CSP_TC32_T *const tc32)
{
	/* TC32 Software Reset */
	tc32->SRR = TC32_SWRST;

	/* Disable TC32 Clock */
	tc32->CEDR &= ~TC32_CLKEN;
}


/**
 *******************************************************************************
 * @brief     Configure the TC32
 * @return    None
 * @param     tc32
 * \n          input
 * \n          brief description - Pointer to ST structure.
 * @param     cdiv_u16
 * \n          input
 * \n          brief description - Configure the prescalar
 * @param     tc32size_u32
 * \n          input
 * \n          brief description - Configure the TC32 size
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC32Configure(CSP_TC32_T *const tc32, U32_T csiz_u32, 
					   U16_T cdiv_u16, U32_T mode_32, U32_T prdr_u32)
{
	/* 16-bit counter */
	//CSP_TC32_SET_CSMR(tc32, TC_CNTSIZE16-1);
	CSP_TC32_SET_CSMR(tc32, csiz_u32);

	/* Configure Counter Value */
	CSP_TC32_SET_CSR(tc32, mode_32);	// mode, pwm_state, stop_state
	CSP_TC32_SET_CDR(tc32, cdiv_u16);	// clock divider

	/* Configure Data */ 
	CSP_TC32_SET_PRDR(tc32, prdr_u32);	// interval
}
	  
/**
 *******************************************************************************
 * @brief     Configure the TC32 pulse
 * @return    None
 * @param     tc32
 * \n          input
 * \n          brief description - Pointer to ST structure.
 * @param     cdiv_u16
 * \n          input
 * \n          brief description - Configure the prescalar
 * @param     tc32size_u32
 * \n          input
 * \n          brief description - Configure the TC32 size
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC32ConfigPulse(CSP_TC32_T *const tc32, 
						 U32_T pwmstate_u32, U32_T pulse_u32)
{
	/* Configure PWM mode */
	CSP_TC32_SET_CSR(tc32, pwmstate_u32);	// pwm_state

	CSP_TC32_SET_PULR(tc32, pulse_u32);	// interval
}
/**
 *******************************************************************************
 * @brief     Configure TC32 Interrupts
 * @return    None
 * @param     st
 * \n          input
 * \n          brief description - Pointer to TC32 structure.
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
void CSP_TC32ConfigInterrupt(CSP_TC32_T *const tc32,
							U32_T intMask_u32,
							FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		/* Disable target interrupts */
		CSP_TC32_SET_IMSCR(tc32, tc32->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_TC32_SET_ICR(tc32, intMask_u32);

		/* Enable target interrupts */
		CSP_TC32_SET_IMSCR(tc32, tc32->IMSCR|intMask_u32);
	}
	else
	{
		/* Disable target interrupts */
		CSP_TC32_SET_IMSCR(tc32, tc32->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_TC32_SET_ICR(tc32, intMask_u32);
	}
}

/**
 *******************************************************************************
 * @brief     Enable TC32 Channel
 * @return    None
 * @param     tc32
 * \n          input
 * \n          brief description - Pointer to TC32 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC32Enable(CSP_TC32_T *const tc32)
{
	/* Enable TC */
	tc32->CSR = TC32_START;
}		 

/**
 *******************************************************************************
 * @brief     Update TC32 Control Register
 * @return    None
 * @param     tc32
 * \n          input
 * \n          brief description - Pointer to TC32 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC32Update(CSP_TC32_T *const tc32)
{
	/* Enable TC Channel */
	tc32->CSR = TC32_UPDATE;
}
/**
 *******************************************************************************
 * @brief     Disable TC32 Channel
 * @return    None
 * @param     tc32 
 * \n          input
 * \n          brief description - Pointer to TC32 structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 *******************************************************************************
 */
void CSP_TC32Disable(CSP_TC32_T *const tc32)
{
	/* Disable TC */
	tc32->CCR = TC32_START;
}

#ifdef TC32_DEBUG
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
FlagStatus CSP_TC32GetFlagStatus(CSP_TC32_T *const tc32, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_TC32_GET_SR(tc32) & TC32_SR_MASK;

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
FlagStatus CSP_TC32GetRawITStatus(CSP_TC32_T *const tc32, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_TC32_GET_RISR(tc32) & TC32_RISR_MASK;

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
FlagStatus CSP_TC32GetMaskedITStatus(CSP_TC32_T *const tc32, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_TC32_GET_MISR(tc32) & TC32_MISR_MASK;

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
* @param     FLAG
* \n          input
* \n          brief description - Flag to be cleared
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_TC32ClearITFlag(CSP_TC32_T *const tc32, U32_T Flag)
{
	CSP_TC32_SET_ICR(tc32, Flag);
}

/**
*******************************************************************************
* @brief     Fills each member of sTC32_TypeDef structure with default value
* @return    none
* @param     TC32InitStruct
* \n          input
* \n          brief description - pointer to a sTC32_TypeDef
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_TC32StructInit(sTC32_TypeDef* TC32InitStruct)
{
	TC32InitStruct->TC32_Cmd = DISABLE;
	TC32InitStruct->Size = 0xFul; // 16-bit by default
	TC32InitStruct->Data = 0x0ul;
	TC32InitStruct->ClockDivider = 0x0ul;
	TC32InitStruct->TC32_Frequency = 0x0ul;
}

/**
*******************************************************************************
* @brief     TC32 initialize with sTC32_TypeDef structure
* @return    none
* @param     tc32
* \n          input
* \n          brief description - pointer to a CSP_TC32_T
* @param     TC32InitStruct
* \n          input
* \n          brief description - pointer to a sTC32_TypeDef which has init
*                                 values for TC32 pointer
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_TC32ConfigInit(CSP_TC32_T *const tc32, sTC32_TypeDef* TC32InitStruct,
		U32_T pclk_freq_u32)
{
	/* TC32 init */
	CSP_TC32Init(tc32);

	/* Config clock divider, size, data */
	CSP_TC32Configure(tc32, TC32InitStruct->ClockDivider,
			TC32InitStruct->Size, TC32InitStruct->Data);

	/* Update TC32 frequency */
	TC32InitStruct->TC32_Frequency = pclk_freq_u32 / (TC32InitStruct->ClockDivider + 1);

	/* for safety clear interrupt */
	tc32->MISR &= ~TC32_MATCH | TC32_OVF;
	tc32->ICR = TC32_MATCH | TC32_OVF;

	/* enable/disable */
	if (TC32InitStruct->TC32_Cmd == ENABLE)
	{
		tc32->CR |= TC32_START;
	}
	else
	{
		tc32->CR &= ~TC32_START;
		tc32->SRR = TC32_SWRST;
	}
}
#endif
