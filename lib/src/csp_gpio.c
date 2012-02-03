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
* @file name	csp_gpio.c
* @description Definitions, Macros and function declarations for GPIO
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  	Creation
* |0.1 MOD 2009.12.21.   Ys OH              Fix bug in CSP_GPIOInit
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
* @brief     Configure PIO
* @return    None
* @param     gpio
* \n          input
* \n          brief description - Pointer to PIO structure.
* @param     gpioMask_u32
* \n          input
* \n          brief description - Configure which pins are activated.
* @param     gpioOutput_u32
* \n          input
* \n          brief description - Configure which pins are configured as output.
* @pre       None
* @post      None
* @todo      Nothing
* @par InBodyDocs:
*******************************************************************************
*/
void CSP_GPIOInit(CSP_GPIO_T *gpio, U32_T gpioOutput_u32)
{
	   /* Enable PIO block */
	   CSP_GPIO_SET_CEDR(gpio, GPIO_CLKEN);

	    /* Set Output GPIO */
	   CSP_GPIO_SET_OER(gpio, CSP_GPIO_GET_OSR(gpio)|gpioOutput_u32);
}

/**
*******************************************************************************
* @brief     Reset and switch off the clock
* @return    None
* @param     gpio
* \n          input
* \n          brief description - Pointer to PIO structure.
* @pre       None
* @post      None
* @todo      Nothing
* @par InBodyDocs:
*******************************************************************************
*/
void CSP_GPIOClose(CSP_GPIO_T *gpio)
{
   /* PIO Software Reset */
   CSP_GPIO_SET_SRR(gpio, GPIO_SWRST);

   /* Disable PIO Clock */
   CSP_GPIO_SET_CEDR(gpio, GPIO_CLKEN);
}

/**
*******************************************************************************
* @brief     Configure the PIO Interrupts
* @return    None
* @param     gpio
* \n          input
* \n          brief description - Pointer to PIO structure.
* @param     intMask_u32
* \n          input
* \n          brief description -  Configure which interrupt bits are activated.
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
void CSP_GPIOConfigInterrupt(CSP_GPIO_T *gpio,
                             U32_T intMask_u32,
                             FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		/* Disable target interrupts */
		CSP_GPIO_SET_IMSCR(gpio, gpio->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_GPIO_SET_ICR(gpio, intMask_u32);

		/* Enable target interrupt */
		CSP_GPIO_SET_IMSCR(gpio, gpio->IMSCR|intMask_u32);
	}
	else
	{
		/* Disable target interrupts */
		CSP_GPIO_SET_IMSCR(gpio, gpio->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_GPIO_SET_ICR(gpio, intMask_u32);
	}
}

/**
*******************************************************************************
* @brief     Read the pin data status
* @return    None
* @param     gpio
* \n          input
* \n          brief description - Pointer to PIO structure.
* @pre       None
* @post      None
* @todo      Nothing
* @par InBodyDocs:
*******************************************************************************
*/
U32_T CSP_GPIOGetStatus(CSP_GPIO_T *gpio)
{
   /* Return GPIO State */
   return (CSP_GPIO_GET_PDSR(gpio));
}


/**
*******************************************************************************
* @brief     Set the PIO to low level
* @return    None
* @param     gpio
* \n          input
* \n          brief description - Pointer to PIO structure.
* @param     gpioMask_u32
* \n          input
* \n          brief description - Configure which pins are set to low level.
* @pre       None
* @post      None
* @todo      Nothing
* @par InBodyDocs:
*******************************************************************************
*/
void CSP_GPIOClear(CSP_GPIO_T *gpio, U32_T gpioMask_u32)
{
   /* Set GPIO State */
   CSP_GPIO_SET_CODR(gpio, gpioMask_u32);
}


/**
*******************************************************************************
* @brief     Set the PIO to high level
* @return    None
* @param     gpio
* \n          input
* \n          brief description - Pointer to PIO structure.
* @param     gpioMask_u32
* \n          input
* \n          brief description - Configure which pins are set to high level.
* @pre       None
* @post      None
* @todo      Nothing
* @par InBodyDocs:
*******************************************************************************
*/
void CSP_GPIOSet(CSP_GPIO_T *gpio, U32_T gpioMask_u32)
{
   /* Set GPIO State */
   CSP_GPIO_SET_SODR(gpio, gpioMask_u32);
}
