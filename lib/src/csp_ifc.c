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
* @file name	csp_ifc.c
* @description Definitions, Macros and function declarations for Flash Controller
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+---------+------------------------------------
* |0.0 NEW 2009.12.01.   Yh JIN	   Creation
* |0.1 MOD 2009.12.12.   Ys OH     Add new APIs
* |0.1                             change MACROs in CR
* |0.2 ADD 2009.12.17.   YS OH     Add CSP_IFCGetFlagStatus, CSP_IFCGetRawITStatus
* |0.2                             CSP_IFCClearITFlag, CSP_IFCUnlockFlash
* |0.2                             IFC_CMD_MASK, CSP_IFCGetMaskedITStatus
* |0.3 MOD 2010.01.07.   Ys OH     Fix IFC_IDCODE, CEDR reset value
* |0.4 MOD 2010.01.13.   Ys OH     No NP_MASK for CSP_IFCCommand
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

/******************************************************************************
 * Include Files
 ******************************************************************************/
#include "csp.h"

/******************************************************************************
* All local #define here                                                      
******************************************************************************/
#define FLASH_TIMEOUT  0x100000

/******************************************************************************
 * Global CSP Driver
 ******************************************************************************/
CSP_IFC_STATUS_T  CSP_IFCStatus_t;

/*******************************************************************************
*****************************  F U N C T I O N S  ******************************
*******************************************************************************/
/**
********************************************************************************
* @description	Configure IFC Ip & CSP Driver
* @return	None
* @param    mode_u32	[in] Setup IFC Mode register field
* @pre		None
* @post	    None
* @todo     Nothing
********************************************************************************
*/
void CSP_IFCInit(CSP_IFC_T *const ifc, U32_T mode_u32)
{
	/* enable clock */
	ifc->CEDR |= IFC_CLKEN;

   	/* CSP Driver Initialization */
   	CSP_IFCStatus_t.status_e = CSP_IFC_NOT_BUSY;
}

/**
*******************************************************************************
* @brief     Configure IFC Interrupts
* @return    none
* @param     intMode_u32
* \n          input
* \n          brief description - Configure the priority level and source type.
* @param     intMask_u32
* \n          input
* \n          brief description - Configure which interrupt bits are activated.
* @param     callback_u32
* \n          input
* \n          brief description -  Function called through the assembler
*                                  interrupt handler.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_IFCConfigInterrupt(CSP_IFC_T *const ifc, U32_T intMask_u32,
								FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		/* Disable all interrupt */
		CSP_IFC_SET_IMSCR(ifc, ifc->IMSCR & ~intMask_u32);

		/* Clear all interrupt */
		CSP_IFCClearITFlag(ifc, intMask_u32);

		/* Disable all interrupt */
		CSP_IFC_SET_IMSCR(ifc, ifc->IMSCR | intMask_u32);
	}
	else
	{
		/* Disable all interrupt */
		CSP_IFC_SET_IMSCR(ifc, ifc->IMSCR & ~intMask_u32);

		/* Clear all interrupt */
		CSP_IFCClearITFlag(ifc, intMask_u32);
	}
}

/**
*******************************************************************************
* @brief     Erase chip / sector / page / smart option
* @return    none
* @param     mode_e
* \n          input
* \n          brief description - The mode to wait the end of erase.
* @param     sector_u8
* \n          input
* \n          brief description - the sector number to be erased.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*******************************************************************************
*/
eCSP_IFC_ERROR_E CSP_IFCErase(CSP_IFC_T *const ifc, eCSP_IFCMode mode_e,
										U32_T addr, U32_T command)
{
	U32_T timeout_count;

	/* check flash not busy */
	if( (CSP_IFCGetFlagStatus(ifc, IFC_BUSY)) ||
			(CSP_IFCStatus_t.status_e != CSP_IFC_NOT_BUSY) )
	{
		return( CSP_IFC_BUSY );
	}

	/* Polling on IFC busy bit */
	if( mode_e == CSP_IFC_POLLING_ON_BUSY )
	{
		CSP_IFCStatus_t.status_e = CSP_IFC_Erasing;
		CSP_IFCUnlockFlash(ifc);
		CSP_IFCConfigInterrupt(ifc, IFC_END, DISABLE);
		CSP_IFCClearITFlag(ifc, IFC_END);
		CSP_IFC_SET_AR(ifc, addr);
		CSP_IFC_SET_CR(ifc, command);
		CSP_IFC_SET_CR(ifc, ifc->CR | IFC_START);
		timeout_count = FLASH_TIMEOUT;
		while ((CSP_IFCGetFlagStatus(ifc, IFC_BUSY)) && (timeout_count--));
		if (!CSP_IFCGetFlagStatus(ifc, IFC_BUSY))
		{
			CSP_IFCStatus_t.status_e = CSP_IFC_NOT_BUSY;
			return(CSP_IFC_OK);
		}
		else
		{
			CSP_IFCStatus_t.status_e = CSP_IFC_TIMEOUT;
			return(CSP_IFC_ERR2);
		}
	}
	/* Polling on IFC ENDERASE bit */
	else if( mode_e == CSP_IFC_POLLING )
	{
		CSP_IFCStatus_t.status_e = CSP_IFC_Erasing;
		CSP_IFCUnlockFlash(ifc);
		CSP_IFCConfigInterrupt(ifc, IFC_END, DISABLE);
		CSP_IFCClearITFlag(ifc, IFC_END);
		CSP_IFC_SET_AR(ifc, addr);
		CSP_IFC_SET_CR(ifc, command);
		CSP_IFC_SET_CR(ifc, ifc->CR | IFC_START);
		timeout_count = FLASH_TIMEOUT;
		while ((CSP_IFCGetFlagStatus(ifc, IFC_BUSY)) && (timeout_count--));
		if (!CSP_IFCGetFlagStatus(ifc, IFC_BUSY))
		{
			CSP_IFCStatus_t.status_e = CSP_IFC_NOT_BUSY;
			return(CSP_IFC_OK);
		}
		else
		{
			CSP_IFCStatus_t.status_e = CSP_IFC_TIMEOUT;
			return(CSP_IFC_ERR2);
		}
	}
	/* Interrupt Mode  */
	else if( mode_e == CSP_IFC_INTERRUPT )
	{
		CSP_IFCStatus_t.status_e = CSP_IFC_Erasing;
		CSP_IFCUnlockFlash(ifc);
		CSP_IFCClearITFlag(ifc, IFC_END);
		CSP_IFCConfigInterrupt(ifc, IFC_END, ENABLE);
		CSP_IFC_SET_AR(ifc, addr);
		CSP_IFC_SET_CR(ifc, command);
		CSP_IFC_SET_CR(ifc, ifc->CR | IFC_START);
		return(CSP_IFC_OK);
	}
	else
	{
		/* Invalid Parameter*/
		return( CSP_IFC_INVALID_PARAMETER);
	}
}

/**
*******************************************************************************
* @brief     Write data into flash
* @return    none
* @param     mode_e
* \n          input
* \n          brief description - The mode to wait the end of write.
* @param     dest_ptr_u32
* \n          input
* \n          brief description - Pointer to the destination address.
* @param     src_ptr_u32
* \n          input
* \n          brief description - Pointer to the source address.
* @param     nb_data_u32
* \n          input
* \n          brief description - Number of data to be written.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
eCSP_IFC_ERROR_E CSP_IFCWrite(CSP_IFC_T *const ifc, eCSP_IFCMode mode_e,
		U32_T *dest_ptr_u32,U32_T *src_ptr_u32, U32_T nb_data_u32, U32_T command)
{
	/* Local variable */
	U32_T i_u32, error_u32 = 0, timeout_count;

	/* check flash not busy */
	if( (CSP_IFCGetFlagStatus(ifc, IFC_BUSY)) ||
			(CSP_IFCStatus_t.status_e != CSP_IFC_NOT_BUSY) )
	{
		return(CSP_IFC_BUSY);
	}

	/* initialize pointer */
	CSP_IFCStatus_t.source_ptr_u32      = src_ptr_u32;
	CSP_IFCStatus_t.destination_ptr_u32 = dest_ptr_u32;
	CSP_IFCStatus_t.nb_data_u32         = nb_data_u32;

	/* Polling on IFC busy bit */
	if( mode_e == CSP_IFC_POLLING_ON_BUSY )
	{
		CSP_IFCStatus_t.status_e = CSP_IFC_Programming;
		for(i_u32=0; i_u32<CSP_IFCStatus_t.nb_data_u32; i_u32++)
		{
			CSP_IFCUnlockFlash(ifc);
			CSP_IFCConfigInterrupt(ifc, IFC_END, DISABLE);
			CSP_IFCClearITFlag(ifc, IFC_END);
			CSP_IFC_SET_DR(ifc, *(CSP_IFCStatus_t.source_ptr_u32));
			CSP_IFC_SET_AR(ifc, (U32_T) CSP_IFCStatus_t.destination_ptr_u32);
			CSP_IFC_SET_CR(ifc, command);
			CSP_IFC_SET_CR(ifc, ifc->CR | IFC_START);
			CSP_IFCStatus_t.destination_ptr_u32++;
			CSP_IFCStatus_t.source_ptr_u32++;
			timeout_count = FLASH_TIMEOUT;
			while ((CSP_IFCGetFlagStatus(ifc, IFC_BUSY)) && (timeout_count--));
			if (CSP_IFCGetFlagStatus(ifc, IFC_BUSY))
			{
				error_u32++;
			}
		}
		if (error_u32 != 0)
		{
			CSP_IFCStatus_t.status_e = CSP_IFC_TIMEOUT;
			return(CSP_IFC_ERR2);
		}
		else
		{
			CSP_IFCStatus_t.status_e = CSP_IFC_NOT_BUSY;
			return(CSP_IFC_OK);
		}
	}
	/* Polling on IFC END bit */
	else if( mode_e == CSP_IFC_POLLING )
	{
		CSP_IFCStatus_t.status_e = CSP_IFC_Programming;
		CSP_IFC_SET_IMSCR(ifc, CSP_IFC_GET_IMSCR(ifc) & (~IFC_END));
		for(i_u32=0; i_u32<nb_data_u32; i_u32++)
		{
			CSP_IFCUnlockFlash(ifc);
			CSP_IFCConfigInterrupt(ifc, IFC_END, DISABLE);
			CSP_IFCClearITFlag(ifc, IFC_END);
			CSP_IFC_SET_DR(ifc, *(CSP_IFCStatus_t.source_ptr_u32));
			CSP_IFC_SET_AR(ifc, (U32_T) CSP_IFCStatus_t.destination_ptr_u32);
			CSP_IFC_SET_CR(ifc, command);
			CSP_IFC_SET_CR(ifc, ifc->CR | IFC_START);
			CSP_IFCStatus_t.destination_ptr_u32++;
			CSP_IFCStatus_t.source_ptr_u32++;
			timeout_count = FLASH_TIMEOUT;
			while ((CSP_IFCGetFlagStatus(ifc, IFC_BUSY)) && (timeout_count--));
			if (CSP_IFCGetFlagStatus(ifc, IFC_BUSY))
			{
				error_u32++;
			}
		}
		if (error_u32 != 0)
		{
			CSP_IFCStatus_t.status_e = CSP_IFC_TIMEOUT;
			return(CSP_IFC_ERR2);
		}
		else
		{
			CSP_IFCStatus_t.status_e = CSP_IFC_NOT_BUSY;
			return(CSP_IFC_OK);
		}
	}
	/* Interrupt Mode -> ENDERASE bit */
	else if( mode_e == CSP_IFC_INTERRUPT )
	{
		CSP_IFCStatus_t.status_e = CSP_IFC_Programming;
		CSP_IFCUnlockFlash(ifc);
		CSP_IFCClearITFlag(ifc, IFC_END);
		CSP_IFCConfigInterrupt(ifc, IFC_END, DISABLE);
		CSP_IFC_SET_DR(ifc, *(CSP_IFCStatus_t.source_ptr_u32));
		CSP_IFC_SET_AR(ifc, (U32_T) CSP_IFCStatus_t.destination_ptr_u32);
		CSP_IFC_SET_CR(ifc, command);
		CSP_IFC_SET_CR(ifc, ifc->CR | IFC_START);
		CSP_IFCStatus_t.destination_ptr_u32++;
		CSP_IFCStatus_t.source_ptr_u32++;
		CSP_IFCStatus_t.nb_data_u32--;
		return(CSP_IFC_OK);
	}
	else
	{
		/* Invalid Parameter*/
		return( CSP_IFC_INVALID_PARAMETER);
	}
}

/**
*******************************************************************************
* @brief     Get flag status from SR register
* @return    none
* @param     Flag
* \n          input
* \n          brief description - Flags in RISR register
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
FlagStatus CSP_IFCGetFlagStatus(CSP_IFC_T *const ifc, U32_T Flag)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_IFC_GET_SR(IFC0) & IFC_SR_MASK;

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
void CSP_IFCClearITFlag(CSP_IFC_T *const ifc, U32_T Flag)
{
	CSP_IFC_SET_ICR(ifc, Flag);
}

/**
*******************************************************************************
* @brief     Unlock flash
* @return    none
* @param     ifc
* \n          input
* \n          brief description - ifc structure
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*******************************************************************************
*/
void CSP_IFCUnlockFlash(CSP_IFC_T *const ifc)
{
	ifc->KR = IFC_KEY;;
}

/**
*******************************************************************************
* @brief     Configure boot sector protection
* @return    none
* @param     ifc
* \n          input
* \n          brief description - ifc structure
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_IFCConfigBootSectorProtect(CSP_IFC_T *const ifc, FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		ifc->MR |= IFC_BACEN;  // protected
	}
	else
	{
		ifc->MR &= ~IFC_BACEN; // disabled
	}
}

/**
*******************************************************************************
* @brief     Do SWRST
* @return    none
* @param     ifc
* \n          input
* \n          brief description - ifc structure
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_IFCReset(CSP_IFC_T *const ifc)
{
	ifc->SRR = IFC_SWRST;
}

/**
*******************************************************************************
* @brief     Get Protection Smart Option
* @return    smart option value
* @param     ifc
* \n          input
* \n          brief description - IFC structure
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
U32_T CSP_IFCGetSmartOptionProtect(CSP_IFC_T *const ifc)
{
	return (ifc->SOPSR);
}

/**
*******************************************************************************
* @brief     Get Configuration Smart Option
* @return    smart option value
* @param     ifc
* \n          input
* \n          brief description - IFC structure
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
U32_T CSP_IFCGetSmartOptionConfig(CSP_IFC_T *const ifc)
{
	return (ifc->SOCSR);
}

/**
*******************************************************************************
* @brief     Configure interleave mode
* @return    none
* @param     ifc
* \n          input
* \n          brief description - ifc structure
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_IFCConfigInterleave(CSP_IFC_T *const ifc, FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		ifc->MR |= IFC_FSMODE;  /* protected */
	}
	else
	{
		ifc->MR &= ~IFC_FSMODE; /* disabled */
	}
}

/**
*******************************************************************************
* @brief     Get Raw Interrupt Status from RISR register
* @return    none
* @param     InterruptStatus
* \n          input
* \n          brief description - mask status in RISR register
* @param     ITStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Interrupt is enabled
*           - RESET: interrupt is disabled
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
ITStatus CSP_IFCGetRawITStatus(CSP_IFC_T *const ifc, U32_T InterruptStatus)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_CM_GET_RISR(ifc) & IFC_RISR_MASK;

	if ((tmp & InterruptStatus) != InterruptStatus)
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
* @brief     Get Masked Interrupt Status from MISR register
* @return    none
* @param     InterruptStatus
* \n          input
* \n          brief description - mask status in MISR register
* @param     ITStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Interrupt is enabled
*           - RESET: interrupt is disabled
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
ITStatus CSP_IFCGetMaskedITStatus(CSP_IFC_T *const ifc, U32_T InterruptStatus)
{
	U32_T tmp = 0;

	/* get status from SR register */
	tmp = CSP_CM_GET_MISR(ifc) & IFC_MISR_MASK;

	if ((tmp & InterruptStatus) != InterruptStatus)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}
