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
* @file name	csp_frt.c
* @description Definitions, Macros and function declarations for FRT
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			     Creation
* |0.1 MOD 2009.12.21.   Ys OH               Fix CSP_FRTConfigure
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
 * @retval    None
 * @param     st
 * \n          input
 * \n          brief description - Pointer to FRT structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 * @par InBodyDocs:
 *******************************************************************************
 */
void CSP_FRTInit(CSP_FRT_T *const frt)
{
	/* Enable FRT Clock */
	frt->CEDR |= FRT_CLKEN;

	/* FRT Software Reset */
	frt->SRR = FRT_SWRST;
}

/**
 *******************************************************************************
 * @brief     Reset and switch off the clock
 * @retval    None
 * @param     st
 * \n          input
 * \n          brief description - Pointer to FRT structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 * @par InBodyDocs:
 *******************************************************************************
 */
void CSP_FRTClose(CSP_FRT_T *const frt)
{
	/* FRT Software Reset */
	frt->SRR = FRT_SWRST;

	/* Disable FRT Clock */
	frt->CEDR &= ~FRT_CLKEN;
}

/**
 *******************************************************************************
 * @brief     Configure the FRT
 * @retval    None
 * @param     frt
 * \n          input
 * \n          brief description - Pointer to ST structure.
 * @param     cdiv_u16
 * \n          input
 * \n          brief description - Configure the prescalar
 * @param     frtsize_u32
 * \n          input
 * \n          brief description - Configure the FRT size
 * @pre       None
 * @post      None
 * @todo      Nothing
 * @par InBodyDocs:
 *******************************************************************************
 */
void CSP_FRTConfigure(CSP_FRT_T *const frt,
		U16_T cdiv_u16, U8_T frtsize_u8, U32_T data_u32)
{
	/* Configure Counter Value */
	CSP_FRT_SET_CR(frt, FRT_FRTSIZE(frtsize_u8) | FRT_CDIV(cdiv_u16));

	/* Configure Data */
	CSP_FRT_SET_DR(frt, data_u32);
}

/**
 *******************************************************************************
 * @brief     Configure FRT Interrupts
 * @retval    None
 * @param     st
 * \n          input
 * \n          brief description - Pointer to FRT structure.
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
 * @par InBodyDocs:
 *******************************************************************************
 */
void CSP_FRTConfigInterrupt(CSP_FRT_T *const frt, U32_T intMask_u32,
							FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		/* Disable target interrupts */
		CSP_FRT_SET_IMSCR(frt, frt->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_FRT_SET_ICR(frt, intMask_u32);

		/* Enable target interrupt */
		CSP_FRT_SET_IMSCR(frt, frt->IMSCR|intMask_u32);
	}
	else /* Disable */
	{
		/* Disable target interrupts */
		CSP_FRT_SET_IMSCR(frt, frt->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_FRT_SET_ICR(frt, intMask_u32);
	}
}
/**
 *******************************************************************************
 * @brief     Enable FRT Channel
 * @retval    None
 * @param     st
 * \n          input
 * \n          brief description - Pointer to FRT structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 * @par InBodyDocs:
 *******************************************************************************
 */
void CSP_FRTEnable(CSP_FRT_T *const frt)
{
	/* Enable ST Channel */
	frt->CR |= FRT_START;
}

/**
 *******************************************************************************
 * @brief     Disable FRT Channel
 * @retval    None
 * @param     st
 * \n          input
 * \n          brief description - Pointer to FRT structure.
 * @pre       None
 * @post      None
 * @todo      Nothing
 * @par InBodyDocs:
 *******************************************************************************
 */
void CSP_FRTDisable(CSP_FRT_T *const frt)
{
	/* Disable ST Channel */
	frt->CR &= ~FRT_START;
}

/**
*******************************************************************************
* @brief     Get flag status from SR register
* @retval    none
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
* @par InBodyDocs:
*******************************************************************************
*/
FlagStatus CSP_FRTGetFlagStatus(CSP_FRT_T *const frt, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_FRT_GET_SR(frt) & FRT_SR_MASK;

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
* @retval    none
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
* @par InBodyDocs:
*******************************************************************************
*/
FlagStatus CSP_FRTGetRawITStatus(CSP_FRT_T *const frt, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_FRT_GET_RISR(frt) & FRT_RISR_MASK;

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
* @retval    none
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
* @par InBodyDocs:
*******************************************************************************
*/
FlagStatus CSP_FRTGetMaskedITStatus(CSP_FRT_T *const frt, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_FRT_GET_MISR(frt) & FRT_MISR_MASK;

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
* @retval    none
* @param     FLAG
* \n          input
* \n          brief description - Flag to be cleared
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*******************************************************************************
*/
void CSP_FRTClearITFlag(CSP_FRT_T *const frt, U32_T Flag)
{
	CSP_FRT_SET_ICR(frt, Flag);
}

/**
*******************************************************************************
* @brief     Fills each member of sFRT_TypeDef structure with default value
* @retval    none
* @param     FRTInitStruct
* \n          input
* \n          brief description - pointer to a sFRT_TypeDef
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*******************************************************************************
*/
void CSP_FRTStructInit(sFRT_TypeDef* FRTInitStruct)
{
	FRTInitStruct->FRT_Cmd = DISABLE;
	FRTInitStruct->Size = 0xFul; // 16-bit by default
	FRTInitStruct->Data = 0x0ul;
	FRTInitStruct->ClockDivider = 0x0ul;
	FRTInitStruct->FRT_Frequency = 0x0ul;
}

/**
*******************************************************************************
* @brief     FRT initialize with sFRT_TypeDef structure
* @retval    none
* @param     frt
* \n          input
* \n          brief description - pointer to a CSP_FRT_T
* @param     FRTInitStruct
* \n          input
* \n          brief description - pointer to a sFRT_TypeDef which has init
*                                 values for FRT pointer
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*******************************************************************************
*/
void CSP_FRTConfigInit(CSP_FRT_T *const frt, sFRT_TypeDef* FRTInitStruct,
		U32_T pclk_freq_u32)
{
	/* FRT init */
	CSP_FRTInit(frt);

	/* Config clock divider, size, data */
	CSP_FRTConfigure(frt, FRTInitStruct->ClockDivider,
			FRTInitStruct->Size, FRTInitStruct->Data);

	/* Update FRT frequency */
	FRTInitStruct->FRT_Frequency = pclk_freq_u32 / (FRTInitStruct->ClockDivider + 1);

	/* for safety clear interrupt */
	frt->MISR &= ~FRT_MATCH | FRT_OVF;
	frt->ICR = FRT_MATCH | FRT_OVF;

	/* enable/disable */
	if (FRTInitStruct->FRT_Cmd == ENABLE)
	{
		frt->CR |= FRT_START;
	}
	else
	{
		frt->CR &= ~FRT_START;
		frt->SRR = FRT_SWRST;
	}
}
