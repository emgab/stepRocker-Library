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
* @file name	csp_nvic.c
* @description Definitions, Macros and function declarations for NVIC
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	  Creation
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
* @brief     Initialize each NVIC Source Vector and Source Mode to sensitive
*            level and 0 priority
* @return    None
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICInit(void)
{
	/* Local Variables */
	U8_T i = 0;

	/* Disable & CLear All Interrupts */
	CSP_NVIC_SET_ICER(NVIC0, 0, 0xFFFFFFFF);
	CSP_NVIC_SET_ICER(NVIC0, 1, 0xFFFFFFFF);
	CSP_NVIC_SET_ICPR(NVIC0, 0, 0xFFFFFFFF);
	CSP_NVIC_SET_ICPR(NVIC0, 1, 0xFFFFFFFF);

	/* Reset priorities */
	for(i = 0; i < (NB_INTERRUPT >> 2); i++)
	{
		CSP_NVIC_SET_IPR(NVIC0, i, 0x0);
	}
}

/**
*******************************************************************************
* @brief     Initialize SCB registers
*            level and 0 priority
* @return    None
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_SCBInit(void)
{
	SCB0->ICSR = 0x0A000000;
	SCB0->VTOR = 0x00000000;
	SCB0->AIRCR = SCB_VECKEY;
	SCB0->SCR = 0x00000000;
	SCB0->CCR = 0x00000000;
	SCB0->SHPR2 = 0x00000000;
	SCB0->SHPR3 = 0x00000000;
	SCB0->SHCSR = 0x00000000;
	SCB0->DFSR = 0xFFFFFFFF;
}

/**
*******************************************************************************
* @brief     NVIC_PriorityGroupConfig: pre-emption priority and subpriority.
* @return    None
* @pre       NVIC_PriorityGroup
* \n          input
* \n          brief description - specifies the priority grouping bits
*                       - NVIC_PriorityGroup_0: 0 bits for pre-emption priority
*                         4 bits for subpriority
*                       - NVIC_PriorityGroup_1: 1 bits for pre-emption priority
*                         3 bits for subpriority
*                       - NVIC_PriorityGroup_2: 2 bits for pre-emption priority
*                         2 bits for subpriority
*                       - NVIC_PriorityGroup_3: 3 bits for pre-emption priority
*                         1 bits for subpriority
*                       - NVIC_PriorityGroup_4: 4 bits for pre-emption priority
*                         0 bits for subpriority
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICPriorityGroupConfig(U32_T NVIC_PriorityGroup)
{
	/* Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value */
	SCB0->AIRCR = SCB_VECKEY | NVIC_PriorityGroup;
}

/**
*******************************************************************************
* @brief     NVIC_StructInit: Fills each NVIC_InitStruct member with its default
*            value
* @return    None
* @pre       NVIC_InitStruct
* \n          input
* \n          brief description - pointer to a NVIC_InitTypeDef structure which
*                    will be initialized.
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICStructInit(NVIC_TypeDef* NVICInitStruct)
{
	/* NVIC_InitStruct members default value */
	NVICInitStruct->NVIC_IRQChannel = 0x00;
	NVICInitStruct->NVIC_IRQChannelPreemptionPriority = 0x00;
	NVICInitStruct->NVIC_IRQChannelSubPriority = 0x00;
	NVICInitStruct->NVIC_IRQChannelCmd = DISABLE;
}

/**
*******************************************************************************
* @brief     Enable the interrupt and set the priority
* @return    None
* @param     NVICInitStruct
* \n          input
* \n          brief description - pointer to NVICInitStruct
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICConfigInterrupt(NVIC_TypeDef* NVICInitStruct)
{
	/* Local variable */
	U8_T regNumber_u8 = 0;
	U32_T priority = 0x0ul, reg = 0x0ul, mask = 0x0ul;
	U32_T pre = 0x0ul, sub = 0x0Ful;

	if (NVICInitStruct->NVIC_IRQChannelCmd != DISABLE)
	{
		/* Extract the pre-emp/sub priority from AIRCR
	     Priority info at bit[10:8] in AIRCR         */
		priority = (0x700 - (SCB0->AIRCR & (U32_T)0x700)) >> 0x08;
		/* Shift for pre-emp priority */
		pre = (0x4 - priority);
		/* mask for sub priority among 4 bits  */
		sub = sub >> priority;

		/* build the priority with pre and sub */
		priority = (U32_T)NVICInitStruct->NVIC_IRQChannelPreemptionPriority << pre;
		priority |= (U32_T)NVICInitStruct->NVIC_IRQChannelSubPriority & sub;
		priority = priority << 0x04;

		/* Find the position of priority within 32-bit */
		priority = ((U32_T)priority) << ((NVICInitStruct->NVIC_IRQChannel & (U8_T)0x03) * 0x08);

		/* Calculate and set new priority */
		regNumber_u8 = NVICInitStruct->NVIC_IRQChannel >> 0x02;
		reg = CSP_NVIC_GET_IPR(NVIC0, regNumber_u8);
		mask = (U32_T)0xFF << ((NVICInitStruct->NVIC_IRQChannel & (U8_T)0x03) * 0x08);
		reg &= ~mask;
		priority &= mask;
		reg |= priority;
		CSP_NVIC_SET_IPR(NVIC0, regNumber_u8, reg);

		/* Determine the Enable register number where the interrupt is located */
		regNumber_u8 = NVICInitStruct->NVIC_IRQChannel >> 0x05;
		/* Enable the corresponding interrupt */
		CSP_NVIC_SET_ISER(NVIC0, regNumber_u8,
				(U32_T)0x01 << (NVICInitStruct->NVIC_IRQChannel & (U8_T)0x1F));
	}
	else
	{
		regNumber_u8 = NVICInitStruct->NVIC_IRQChannel >> 0x05;
		CSP_NVIC_SET_ICER(NVIC0, regNumber_u8,
				(U32_T)0x01 << (NVICInitStruct->NVIC_IRQChannel & (U8_T)0x1F));
	}
}

/**
*******************************************************************************
* @brief     CSP_NVICGetIntrruptChannelPendingBitStatus: Checks whether the
*            specified IRQ Channel pending bit is set or not.
* @return    None
* @pre       intNum_u8
* \n          input
* \n          brief description - specifies the interrupt pending bit to check
* @post      ITStatus
* \n          output
* \n          The new state of IRQ Channel pending bit(TRUE or FALSE)
* @todo      Nothing
*******************************************************************************
*/
ITStatus CSP_NVICGetIntrruptChannelPendingBitStatus(U8_T intNum_u8)
{
	ITStatus pendingStatus = RESET;
	U32_T temp = 0x0ul, status = 0x0ul;

	/* corresponding status bit */
	temp = ((U32_T)0x01ul << (intNum_u8 & (U32_T)0x1F));
	status = (CSP_NVIC_GET_ISPR(NVIC0, (intNum_u8 >> 5)) & (temp));

	if (status == temp)
	{
		pendingStatus = SET;
	}
	else
	{
		pendingStatus = RESET;
	}

	return pendingStatus;
}

/**
*******************************************************************************
* @brief     CSP_NVICGetCurrentPendingInterruptChannel: Returns the current
*            pending IRQ channel identifier.
* @return    None
* @pre       None
* @post      U16_T
* \n          output
* \n          Pending IRQ Channel Identifier.
* @todo      Nothing
*******************************************************************************
*/
U16_T CSP_NVICGetCurrentPendingInterruptChannel(void)
{
	return ((U16_T)((SCB0->ICSR & (U32_T)0x003FF000) >> 12));
}

/**
*******************************************************************************
* @brief     CSP_NVICSetInterruptChannelPendingBit: Sets the NVIC interrupt
*            pending bit
* @return    None
* @pre       intNum_u8
* \n          input
* \n          specifies the interrupt pending bit to Set.
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICSetInterruptChannelPendingBit(U8_T intNum_u8)
{
	*(U32_T*)0xE000EF00 = (U32_T)intNum_u8;
}

/**
*******************************************************************************
* @brief     CSP_NVICClearInterruptChannelPendingBit: Clears the NVIC interrupt
*            pending bit
* @return    None
* @pre       intNum_u8
* \n          input
* \n          specifies the interrupt pending bit to clear
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICClearInterruptChannelPendingBit(U8_T intNum_u8)
{
	CSP_NVIC_SET_ICPR(NVIC0, (intNum_u8 >> 0x05),
			(U32_T)0x01 << (intNum_u8 & (U32_T)0x1F));
}

/**
*******************************************************************************
* @brief     NVIC_GetCurrentActiveHandler: Returns the current active Handler
*            (IRQ Channel and SystemHandler) identifier
* @return    None
* @pre       none
* @post      U16_T
* \n          output
* \n          activated handler
* @todo      Nothing
*******************************************************************************
*/
U16_T CSP_NVICGetCurrentActiveHandler(void)
{
	return ((U16_T)(SCB0->ICSR & (U32_T)0x3FF));
}

/**
*******************************************************************************
* @brief     CSP_NVICGetIntrruptChannelActiveBitStatus: Checks whether the
*            specified IRQ Channel active bit is set or not
* @return    None
* @pre       intNum_u8
* \n          input
* \n          specifies the interrupt active bit to check
* @post      none
* @todo      Nothing
*******************************************************************************
*/ 
ITStatus CSP_NVICGetIntrruptChannelActiveBitStatus(U8_T intNum_u8)
{
	ITStatus activeStatus = RESET;
	U32_T temp = 0x0ul, status = 0x0ul;

	// corresponding status bit
	temp = ((U32_T)0x01ul << (intNum_u8 & (U32_T)0x1F));
	status = (CSP_NVIC_GET_ACTIVE(NVIC0));

	if (status == temp)
	{
		activeStatus = SET;
	}
	else
	{
		activeStatus = RESET;
	}

	return activeStatus;
}

/**
*******************************************************************************
* @brief     CSP_NVICSetVectorTable: Sets the vector table location and Offset
* @return    None
* @pre       vecTab
* \n          input
* \n          specifies if the vector table is in RAM or FLASH memory
* @pre       offset
* \n          input
* \n          Vector Table base offset field This value must be a multiple
*             of 0x100
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICSetVectorTable(U32_T vecTab, U32_T offset)
{
	CSP_SCB_SET_VTOR(SCB0, (vecTab | (offset & (U32_T)0x1FFFFF80)));
}

/**
*******************************************************************************
* @brief     CSP_NVICGenerateSystemReset: Generates a system reset
* @return    None
* @pre       none
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICGenerateSystemReset(void)
{
	CSP_SCB_SET_AIRCR(SCB0, SCB_SYSRESETREQ);
}

/**
*******************************************************************************
* @brief     CSP_NVICGenerateCoreReset: Generates a Core (Core + NVIC) reset
* @return    None
* @pre       none
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICGenerateCoreReset(void)
{
	CSP_SCB_SET_AIRCR(SCB0, SCB_VECTRESET);
}

/**
*******************************************************************************
* @brief     CSP_NVICLowPowerConfig: Selects the condition for the system to
*            enter low power mode
* @return    None
* @pre       powerMode
* \n          input
* \n          Specifies the new mode for the system to enter low power mode
* @pre       newState
* \n          input
* \n          new state of LP condition (ENABLE or DISABLE)
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICLowPowerConfig(U32_T powerMode, FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		CSP_SCB_SET_SCR(SCB0, powerMode);
	}
	else
	{
		SCB0->SCR &= ~powerMode;
	}
}

/**
*******************************************************************************
* @brief     NVIC_SystemHandlerConfig: Enables or disables the specified
*            System Handlers
* @return    None
* @pre       systemHandler
* \n          input
* \n          specifies the system handler to be enabled or disabled
* \n          MemoryManage, BusFault, or UsageFault
* @pre       newState
* \n          input
* \n          new state of  specified System Handlers (ENABLE or DISABLE)
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICSystemHandlerConfig(U32_T systemHandler, FunctionalStatus newState)
{
	U32_T tmpreg = 0x00;

	tmpreg = (U32_T)0x01 << (systemHandler & (U32_T)0x1F);

	if (newState != DISABLE)
	{
		SCB0->SHCSR |= tmpreg;
	}
	else
	{
		SCB0->SHCSR &= ~tmpreg;
	}
}

/**
*******************************************************************************
* @brief     CSP_NVICSystemHandlerPriorityConfig: Configures the specified
*            System Handlers priority
* @return    None
* @pre       systemHandler
* \n          input
* \n          specifies the system handler to be enabled or disabled
* \n          MemoryManage, BusFault, UsageFault, SVCall, DebugMonitor,
* \n          PSV, SysTick
* @pre       prePrio_u8
* \n          input
* \n          new priority group of the specified system handlers
* @pre       subPrio_u8
* \n          input
* \n          new sub priority group of the specified system handlers
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICSystemHandlerPriorityConfig(U32_T systemHandler, U8_T prePrio_u8,
                                      U8_T subPrio_u8)
{
//	U32_T tmppriority = 0x00;
//	tmppriority = tmppriority << (tmp2 * 0x08);

/*	U32_T tmp1 = 0x00, tmp2 = 0xFF, handlermask = 0x00;
	U32_T tmppriority = 0x00;

	tmppriority = (0x700 - (SCB0->AIRCR & (U32_T)0x700))>> 0x08;
	tmp1 = (0x4 - tmppriority);
	tmp2 = tmp2 >> tmppriority;

	tmppriority = (U32_T)prePrio_u8 << tmp1;
	tmppriority |=  subPrio_u8 & tmp2;

	tmppriority = tmppriority << 0x04;
	tmp1 = systemHandler & (U32_T)0xC0;
	tmp1 = tmp1 >> 0x06;
	tmp2 = (systemHandler >> 0x08) & (U32_T)0x03;
	tmppriority = tmppriority << (tmp2 * 0x08);
	handlermask = (U32_T)0xFF << (tmp2 * 0x08);
*/
	//SCB0->SHPR[tmp1] &= ~handlermask;
	//SCB0->SHPR[tmp1] |= tmppriority;
}

/**
*******************************************************************************
* @brief     CSP_NVICGetSystemHandlerPendingBitStatus: Checks whether the
*            specified System handlers pending bit is set or not
* @return    None
* @pre       SystemHandler
* \n          input
* \n          specifies the system handler pending bit to check
* \n          MemoryManage, BusFault, SVCall
* @post      none
* @todo      Nothing
*******************************************************************************
*/
ITStatus CSP_NVICGetSystemHandlerPendingBitStatus(U32_T SystemHandler)
{
	ITStatus bitstatus  = RESET;
	U32_T tmp = 0x00, tmppos = 0x00;

	tmppos = (SystemHandler >> 0x0A);
	tmppos &= (U32_T)0x0F;

	tmppos = (U32_T)0x01 << tmppos;

	tmp = SCB0->SHCSR & tmppos;

	if (tmp == tmppos)
	{
		bitstatus = SET;
	}
	else
	{
		bitstatus = RESET;
	}
	return bitstatus;
}

/**
*******************************************************************************
* @brief     CSP_NVICSetSystemHandlerPendingBit: Sets System Handler pending bit
* @return    None
* @pre       SystemHandler
* \n          input
* \n          specifies the system handler pending bit to be set
* \n          NMI, PSV, SysTick
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICSetSystemHandlerPendingBit(U32_T SystemHandler)
{
	U32_T tmp = 0x00;

	/* Get the System Handler pending bit position */
	tmp = SystemHandler & (U32_T)0x1F;
	/* Set the corresponding System Handler pending bit */
	SCB0->ICSR |= ((U32_T)0x01 << tmp);
}

/**
*******************************************************************************
* @brief     CSP_NVICClearSystemHandlerPendingBit: Clears System Handler
*            pending bit
* @return    None
* @pre       SystemHandler
* \n          input
* \n          specifies the system handler pending bit to be set
* \n          NMI, PSV, SysTick
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICClearSystemHandlerPendingBit(U32_T SystemHandler)
{
	U32_T tmp = 0x00;

	/* Get the System Handler pending bit position */
	tmp = SystemHandler & (U32_T)0x1F;
	/* Clear the corresponding System Handler pending bit */
	SCB0->ICSR |= ((U32_T)0x01 << (tmp - 0x01));
}

/**
*******************************************************************************
* @brief     CSP_NVICGetSystemHandlerActiveBitStatus: Checks whether the
*            specified System handlers active bit is set or not
* @return    None
* @pre       SystemHandler
* \n          input
* \n          specifies the system handler active bit to check
* \n          MemoryManage, BusFault, UsageFault, SVCall, DebugMonitor,
* \n          PSV, SysTick
* @post      none
* @todo      Nothing
*******************************************************************************
*/
ITStatus CSP_NVICGetSystemHandlerActiveBitStatus(U32_T SystemHandler)
{
	ITStatus bitstatus  = RESET;

	U32_T tmp = 0x00, tmppos = 0x00;

	tmppos = (SystemHandler >> 0x0E) & (U32_T)0x0F;

	tmppos = (U32_T)0x01 << tmppos;

	tmp = SCB0->SHCSR & tmppos;

	if (tmp == tmppos)
	{
		bitstatus = SET;
	}
	else
	{
		bitstatus = RESET;
	}
	return bitstatus;
}

/**
*******************************************************************************
* @brief     CSP_NVICGetFaultHandlerSources: Returns the system fault handlers
*            sources
* @return    None
* @pre       SystemHandler
* \n          input
* \n          specifies the system handler to get its fault sources
* \n          MemoryManage, BusFault, UsageFault, SVCall, DebugMonitor
* @post      none
* @todo      Nothing
*******************************************************************************
*/
U32_T CSP_NVICGetFaultHandlerSources(U32_T SystemHandler)
{
	U32_T faultsources = 0x00;	
	faultsources = SCB0->DFSR;
	return faultsources;
}

/**
*******************************************************************************
* @brief     CSP_NVICGetFaultAddress: Returns the address of the location that
*            generated a fault handler
* @return    None
* @pre       SystemHandler
* \n          input
* \n          specifies the system handler to get its fault address
* \n          MemoryManage, BusFault
* @post      none
* @todo      Nothing
*******************************************************************************
*/
U32_T CSP_NVICGetFaultAddress(U32_T SystemHandler)
{
	U32_T faultaddress = 0x00;
	U32_T tmp = 0x00;

	tmp = (SystemHandler >> 0x16) & (U32_T)0x01;

	if (tmp == 0x00)
	{
		//faultaddress = SCB0->MMAR;
	}
	else
	{
		//faultaddress = SCB0->BFAR;
	}
	return faultaddress;
}

/**
*******************************************************************************
* @brief     CSP_NVICSetSystemCtrlReg: Set SCB System Control Register
* @return    None
* @pre       configuration
* \n          input
* \n          new configuration
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICSetSystemCtrlReg(U32_T configuration)
{
	SCB0->SCR |= configuration;
}

/**
*******************************************************************************
* @brief     CSP_NVICSetSystemCtrlReg: clear SCB System Control Register
* @return    None
* @pre       configuration
* \n          input
* \n          new configuration
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICClrSystemCtrlReg(U32_T configuration)
{
	SCB0->SCR &= ~configuration;
}

/**
*******************************************************************************
* @brief     CSP_NVICSetSystemCtrlReg: Set SCB config control reigster
* @return    None
* @pre       configuration
* \n          input
* \n          new configuration
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICSetConfigCtrlReg(U32_T configuration)
{
	SCB0->CCR |= configuration ;
}

/**
*******************************************************************************
* @brief     CSP_NVICSetSystemCtrlReg: clear SCB Config control register
* @return    None
* @pre       configuration
* \n          input
* \n          new configuration
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICClrConfigCtrlReg(U32_T configuration)
{
	SCB0->CCR &= ~configuration ;
}

/**
*******************************************************************************
* @brief     CSP_NVICSetSystemCtrlReg: Set SCB SCB Application Interrupt Reset
*            Control Register
* @return    None
* @pre       configuration
* \n          input
* \n          new configuration
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICSetAppIntRstCtrlReg(U32_T configuration)
{
	SCB0->AIRCR |= configuration ;
}

/**
*******************************************************************************
* @brief     CSP_NVICClrAppIntRstCtrlReg: clear SCB Application Interrupt Reset
*            Control Register
* @return    None
* @pre       configuration
* \n          input
* \n          new configuration
* @post      none
* @todo      Nothing
*******************************************************************************
*/
void CSP_NVICClrAppIntRstCtrlReg(U32_T configuration)
{
	SCB0->AIRCR &= ~configuration ;
}
