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
* @file name	csp_pwm.c
* @description Definitions, Macros and function declarations for PWM
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

/* Duty Generation -----------------------------------------------------------*/
#define PERIOD(p)		p
#define PULSE(s)		s
#define IDLE(x)			x
#define START(y)		y
#define Mdiv(m)			m
#define Ndiv(n)			n 

/******************************************************************************
****************************  F U N C T I O N S  ******************************
******************************************************************************/
void CSP_PWMClockEnable(CSP_PWM_T *pwm)
{
	/* Enable PWM Clock */
	CSP_PWM_SET_CEDR(pwm, CSP_PWM_GET_CEDR(pwm)|PWM_CLKEN);
}
void CSP_PWMClockDisable(CSP_PWM_T *pwm)
{
	U32_T temp_u32 =0;
	temp_u32 = CSP_PWM_GET_CEDR(pwm)& (~PWM_CLKEN);
	CSP_PWM_SET_CEDR(pwm,temp_u32);
}

void CSP_PWMDbgenCmd(CSP_PWM_T *pwm, FunctionalStatus cmd)
{
	U32_T temp_u32 = 0;

	if(cmd == ENABLE)
	{
		 /* Enable PWM Clock */
		 CSP_PWM_SET_CEDR(pwm, CSP_PWM_GET_CEDR(pwm)|PWM_DBGEN);
	}
	else
	{
		temp_u32 = CSP_PWM_GET_CEDR(pwm)& (~PWM_DBGEN);
		CSP_PWM_SET_CEDR(pwm,temp_u32);
	}
}
/**
*******************************************************************************
* @brief     Switch on the clock, reset the registers
* @return    None
* @param     pwm
* \n          input
* \n          brief description - Pointer to PWM structure.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_PWMInit(CSP_PWM_T *pwm)
{
   /* Enable PWM Clock */
   CSP_PWM_SET_CEDR(pwm, PWM_CLKEN);

   /* PWM Software Reset */
   CSP_PWM_SET_SRR(pwm, PWM_SWRST);

}

/**
*******************************************************************************
* @brief     Reset and switch off the clock
* @return    None
* @param     pwm
* \n          input
* \n          brief description - Pointer to PWM structure.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_PWMClose(CSP_PWM_T *pwm)
{
   /* PWM Software Reset */
   CSP_PWM_SET_SRR(pwm, PWM_SWRST);

   /* Disable PWM Clock */
   CSP_PWM_SET_CEDR(pwm, CSP_PWM_GET_CEDR(pwm)& ~PWM_CLKEN);
}


/**
*******************************************************************************
* @brief     Reset and switch off the clock
* @return    None
* @param     pwm
* \n          input
* \n          brief description - Pointer to PWM structure.
* @param     channel_u8
* \n          input
* \n          brief description - Channel [0-3] to be configured.
* @param     prescaler_u8
* \n          input
* \n          brief description -  Configure the PWM Prescalar
* @param     mode_u32
* \n          input
* \n          brief description -  Configure the PWM mode (Prescalar + PL).
* @param     period_u16
* \n          input
* \n          brief description - Configure the PWM delay. Number of cycles
*                                 during which the output is inactive.
* @param     pulse_u16
* \n          input
* \n          brief description - Configure the PWM pulse. Number of cycles
* \n                              during which the output is active.
* @param     feedback_u32
* \n          input
* \n          brief description - Configure feedback option for each channel
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_PWMConfigure(CSP_PWM_T *pwm,U8_T idlelevel, U8_T startlevel,
                               U16_T period_u16, U16_T pulse_u16)
{
	if(idlelevel == 0 )
	{
		CSP_PWM_SET_CCR(pwm, PWM_IDLESL);
	}
	else
	{
		CSP_PWM_SET_CSR(pwm, PWM_IDLESL);
	}
	if(startlevel == 0)
	{
		CSP_PWM_SET_CCR(pwm, PWM_OUTSL);
	}
	else
	{
		CSP_PWM_SET_CSR(pwm, PWM_OUTSL);
	}

	/* Configure PWM Signal */
   CSP_PWM_SET_PRDR(pwm, period_u16);
   CSP_PWM_SET_PULR(pwm, pulse_u16);
}

ErrorStatus CSP_PWMIntervalMode(CSP_PWM_T *pwm)
{
   	CSP_PWM_SET_CSR(pwm, PWM_PWMIM);
   	if(CSP_PWM_GET_SR(pwm)& PWM_PWMIM != PWM_PWMIM)
   	{
   		return (ERROR);
   	}
   	return (SUCCESS);
}

ErrorStatus CSP_PWMNormalMode(CSP_PWM_T *pwm)
{
   	CSP_PWM_SET_CCR(pwm, PWM_PWMIM);
   	if(CSP_PWM_GET_SR(pwm)& PWM_PWMIM != 0x0)
   	{
   		return (ERROR);
   	}
   	return (SUCCESS);
}
ErrorStatus CSP_PWMStopLevelKeep(CSP_PWM_T *pwm)
{
   	CSP_PWM_SET_CCR(pwm, PWM_KEEP);
   	if(CSP_PWM_GET_SR(pwm)& PWM_KEEP != PWM_KEEP)
   	{
   		return (ERROR);
   	}
   	return (SUCCESS);
}

/**
*******************************************************************************
* @brief     Configuration interrupt
*******************************************************************************
*/
void CSP_PWMConfigInterrupt(CSP_PWM_T *pwm,
                              U32_T intMask_u32,
                              FunctionalStatus newState)
{
	U32_T temp_u32 = 0;
	if (newState != DISABLE)
	{
		/* Disable all interrupt */
		CSP_PWM_SET_IMSCR(pwm, CSP_PWM_GET_IMSCR(pwm)|intMask_u32);

		/* Clear all interrupt */
		CSP_PWM_SET_ICR(pwm, 0xFFFFFFFF);
	}
	else
	{
		temp_u32 = CSP_PWM_GET_IMSCR(pwm) & (~intMask_u32);
		/* Disable all interrupt */
		CSP_PWM_SET_IMSCR(pwm, temp_u32);

		/* Clear all interrupt */
		CSP_PWM_SET_ICR(pwm, 0xFFFFFFFF);
	}
}


/**
*******************************************************************************
* @brief     Start PWM
* @return    None
* @param     pwm
* \n          input
* \n          brief description - Pointer to PWM structure.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_PWMStart(CSP_PWM_T *pwm )
{
   /* Enable PWM Channel */
   CSP_PWM_SET_CSR(pwm, PWM_START);
}

/**
*******************************************************************************
* @brief     Stop PWM
* @return    None
* @param     pwm
* \n          input
* \n          brief description - Pointer to PWM structure.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_PWMStop(CSP_PWM_T *pwm)
{
   /* Disable PWM Channel */
   CSP_PWM_SET_CCR(pwm, PWM_START);
}


/**
*******************************************************************************
* @brief     PWM Clock Configuration
*******************************************************************************
*/
void CSP_PWMClockConfiguration(CSP_PWM_T *pwm,U16_T clkdiv_m,U8_T clkdiv_n)
{
   CSP_PWM_SET_CDR(pwm, PWM_DIVM(clkdiv_m)|PWM_DIVN(clkdiv_n));
}

/**
*******************************************************************************
* @brief     Update command for parameter value update
* @return    None
* @param     pwm
* \n          input
* \n          brief description - Pointer to PWM structure.
* @pre       None
* @post      None
* @todo      Nothing
*******************************************************************************
*/
void CSP_PWMUpdate(CSP_PWM_T *pwm)
{
   /* Update PWM parameter */
   CSP_PWM_SET_CSR(pwm, PWM_UPDATE);
}
