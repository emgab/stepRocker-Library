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
* @file name	csp_i2c.c
* @description Definitions, Macros and function declarations for I2C
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
********************************************************************************
* @brief	Pin configuration for SSP
* @return	None
* @param	ssp	[in] Pointer to SSP structure
* @todo		None
********************************************************************************
*/
/*
 * I2C0 Port                     I2C1 Port
 * SCL0 : P0.17 : PIN37         SCL1 : P1.3  : PIN61
 * SDA0 : P0.18 : PIN38         SDA1 : P1.4  : PIN62
 */
void CSP_I2CPinConfiguration(CSP_I2C_T *const i2c)
{
	if(i2c==I2C0)
	{
		if( (CSP_GPIO_GET_CEDR(GPIO0)&GPIO_CLKEN) == GPIO_CLKEN)
		{
			CSP_GPIO_SET_ODR(GPIO0, GPIO_P17|GPIO_P18);
		}

		/* I2C0 2nd function */
		CSP_IOFunctionConfigure(GROUP0,IO_Port17,IOCONF_F1);
		CSP_IOFunctionConfigure(GROUP0,IO_Port18,IOCONF_F1);
	}
	if(i2c==I2C1)
	{
		if( (CSP_GPIO_GET_CEDR(GPIO1)&GPIO_CLKEN) == GPIO_CLKEN)
		{
			CSP_GPIO_SET_ODR(GPIO1, GPIO_P4|GPIO_P3);
		}

		/* I2C1 4th function */
		CSP_IOFunctionConfigure(GROUP1,IO_Port4,IOCONF_F3);
		CSP_IOFunctionConfigure(GROUP1,IO_Port3,IOCONF_F3);
	}
}
/**
*******************************************************************************
* @brief     Switch on the clock, reset the registers and configure the
*            I2C module mode.
* @retval    none
* @param     i2c
* \n          input
* \n          brief description - Pointer to I2C structure.
* @param     mode_u32
* \n          input
* \n          brief description - Configure the I2C mode
* @param     thold_u32
* \n          input
* \n          brief description - Configure the Hold/Setup Delay
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_I2CInit(CSP_I2C_T *i2c, U32_T mode_u32, U32_T thold_u32)
{
	/* I2C Pin configure */
	CSP_I2CPinConfiguration(i2c);

   /* Enable I2C Clock */
   CSP_I2C_SET_CEDR(i2c, I2C_CLKEN);

   /* I2C Software Reset */
   CSP_I2C_SET_SRR(i2c, I2C_SWRST);


   /* Configure I2C Mode */
   CSP_I2C_SET_MR(i2c, mode_u32);

   /* Configure Hold/Setup Delay */
   CSP_I2C_SET_HSDR(i2c, thold_u32);
}

/**
*******************************************************************************
* @brief     Switch on the clock, reset the registers and configure the
*            I2C module mode.
* @retval    none
* @param     i2c
* \n          input
* \n          brief description - Pointer to I2C structure.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_I2CClose(CSP_I2C_T *i2c)
{
   /* I2C Software Reset */
   CSP_I2C_SET_SRR(i2c, I2C_SWRST);

   /* Disable I2C Clock */
   CSP_I2C_SET_CEDR(i2c, ~0x0);
}

/**
*******************************************************************************
* @brief     Configure I2C Interrupts
* @retval    none
* @param     i2c
* \n          input
* \n          brief description - Pointer to I2C structure.
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
* @todo      nothing
*******************************************************************************
*/
void CSP_I2CConfigInterrupt(CSP_I2C_T *i2c,
                            U32_T intMask_u32,
                            FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		/* Disable target interrupts */
		CSP_I2C_SET_IMSCR(i2c, i2c->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_I2C_SET_ICR(i2c, intMask_u32);

		/* Enable target interrupt */
		CSP_I2C_SET_IMSCR(i2c, i2c->IMSCR|intMask_u32);
	}
	else
	{
		/* Disable target interrupts */
		CSP_I2C_SET_IMSCR(i2c, i2c->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_I2C_SET_ICR(i2c, intMask_u32);
	}
}

/**
*******************************************************************************
* @brief     Configure I2C in Master or Slave mode and specify Slave Response
*            address with General Call detection.
* @retval    none
* @param     i2c
* \n          input
* \n          brief description - Pointer to I2C structure.
* @param     cr_u16
* \n          input
* \n          brief description - Configure the I2C Slave or Master mode
* @param     add_u8
* \n          input
* \n          brief description - Configure address for Slave Response
*                                 and general call detection
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_I2CModeConfig(CSP_I2C_T *i2c, U16_T cr_u16, U8_T add_u8)
{
   /* Configure I2C Control Register */
   CSP_I2C_SET_CR(i2c, cr_u16);

   /* Configure ADR Field and GC bit */
   CSP_I2C_SET_SSAR(i2c, add_u8);

}
