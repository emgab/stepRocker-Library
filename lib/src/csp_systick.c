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
* @file name  csp_systick.c
* @description Definitions, Macros and function declarations for CMx systick
*
* @history  History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part    Creation
*  -------------------------------------------------------------------
* @see  RealView MDK-ARM Version 4.01
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
* @brief     SysTick Input Clock Configuration (HCLK or STCLK)
* @retval    None
* @param     SysTickClkSource
* \n          input
* \n          brief description - Clk source for SysTick
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_SysTickClkConfig(SYSTICK_CLKTypeDef SysTick_ClkSource)
{
   if (SysTick_ClkSource == 0x0)
   {
     SYSTICK0->CSR &= SYSTICK_CLKSOURCE_CORECLK_DIV8;
   }
   else if (SysTick_ClkSource == 0x1)
   {
     SYSTICK0->CSR |= SYSTICK_CLKSOURCE_CORECLK;
   }
}

/**
*******************************************************************************
* @brief     Reload counter value
* @retval    None
* @param     reload_u32
* \n          input
* \n          brief description - Reload value
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_SysTickReload(U32_T reload_u32)
{
  SYSTICK0->RVR = reload_u32;
}

/**
*******************************************************************************
* @brief     Configure SysTick Interrupt
* @retval    None
* @param     prePrio_u8
* \n          input
* \n          brief description - preemption priority
* @param     subPrio_u8
* \n          input
* \n          brief description - sub priority
* @param     newState
* \n          input
* \n          brief description - DISABLE or ENABLE
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_SysTickConfigInterrupt(U8_T prePrio_u8,
                             U8_T subPrio_u8,
                             FunctionalStatus newState)
{
  if (newState != DISABLE)
  {
    /* Disable interrupt */
    SYSTICK0->CSR &= ~SYSTICK_TICKINT;

    /* Clear all interrupts */
    SYSTICK0->CSR;
    SCB0->ICSR = SCB_PENDSTCLR;

    /* Interrupt Enable */
    SYSTICK0->CSR |= SYSTICK_TICKINT;
  }
  else
  {
    /* Clear all interrupt */
    SYSTICK0->CSR &= ~SYSTICK_TICKINT;
    SCB0->ICSR = SCB_PENDSTCLR;
  }

  /* Configure Priority */
  CSP_NVICSystemHandlerPriorityConfig(SystemHandler_SysTick, prePrio_u8, subPrio_u8);  //*** Bug fixed by Trinamic (OK)
}

/**
*******************************************************************************
* @brief     Enable Systick
* @retval    None
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_SysTickEnable(void)
{
  SYSTICK0->CSR |= SYSTICK_COUNTER_ENABLE;
}

/**
*******************************************************************************
* @brief     Disable Systick
* @retval    None
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_SysTickDisable(void)
{
  SYSTICK0->CSR = 0;
  SYSTICK0->RVR = 0;
  SYSTICK0->CVR = 0;
  SCB0->ICSR = SCB_PENDSTCLR;
}

/**
*******************************************************************************
* @brief     Get current Systick counter
* @retval    U32_T
* \n         brief description - Current counter value obtained from SysTick
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
U32_T CSP_SysTickGetCounter(void)
{
  return (SYSTICK0->CVR);
}

/**
*******************************************************************************
* @brief     Get counter flag
* @retval    U32_T
* \n         brief description - Current counter flag
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
U32_T CSP_SysTickGetFlag(void)
{
  return (SYSTICK0->CSR & SYSTICK_COUNTFLAG);
}
