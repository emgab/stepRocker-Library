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
* @file name	csp_ioconf.c
* @description Definitions, Macros and function declarations for IO Configuration
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
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
*******************************************************************************
*/
void CSP_IOFunctionConfigure(eGROUPy iogroup,U8_T port, U8_T function)
{
	U32_T temp = 0;
	U8_T new_port =0;

		if(iogroup == GROUP0 )
		{
			if(port <16)
			{
				temp = CSP_IOCONF_GET_MLR0(IOCONF0) & (~(IOCONF_FSEL_MASK <<(2*port)));
				CSP_IOCONF_SET_MLR0(IOCONF0, temp|(function << (2*port )));
			}
			else
			{
				new_port= port-16;
				temp = CSP_IOCONF_GET_MHR0(IOCONF0) & (~(IOCONF_FSEL_MASK <<(2*new_port)));
				CSP_IOCONF_SET_MHR0(IOCONF0, temp|(function << (2* new_port )));
			}
		}
		if(iogroup == GROUP1 )
		{
			if(port <16)
			{
				temp = CSP_IOCONF_GET_MLR1(IOCONF0) & (~(IOCONF_FSEL_MASK <<(2*port)));
				CSP_IOCONF_SET_MLR1(IOCONF0, temp|(function << (2*port )));
			}
			else
			{
				new_port= port-16;
				temp = CSP_IOCONF_GET_MHR1(IOCONF0) & (~(IOCONF_FSEL_MASK <<(2*new_port)));
				CSP_IOCONF_SET_MHR1(IOCONF0, temp|(function << (2* new_port )));
			}
		}
}

/**
*******************************************************************************
* @brief     IO Pull-up Enable	  					
* @return    None				 
* @param     group,port
* \n          input
* \n          brief description - Pointer to PIO structure.
*******************************************************************************
*/
void CSP_IOPullupEnable(eGROUPy group, U8_T port)
{
	U32_T temp = 0;
	if(group == GROUP0)
	{
		temp = CSP_IOCONF_GET_PUCR0(IOCONF0);
		CSP_IOCONF_SET_PUCR0(IOCONF0,temp|IOCONF_PUEN(port));
	}
	if(group == GROUP1)
	{
		temp = CSP_IOCONF_GET_PUCR1(IOCONF0);
		CSP_IOCONF_SET_PUCR1(IOCONF0,temp|IOCONF_PUEN(port));
	}
}

/**
*******************************************************************************
* @brief     IO Pull-up Disable	   
* @return    None				   
* @param     group,port
* \n          input
* \n          brief description - Pointer to PIO structure.
*******************************************************************************
*/
void CSP_IOPullupDisable(eGROUPy group, U8_T port)
{
	U32_T temp = 0;
	if(group == GROUP0)
	{
		temp = CSP_IOCONF_GET_PUCR0(IOCONF0) & (~IOCONF_PUEN(port));
		CSP_IOCONF_SET_PUCR0(IOCONF0,temp);
	}
	if(group == GROUP1)
	{
		temp = CSP_IOCONF_GET_PUCR1(IOCONF0) & (~IOCONF_PUEN(port));
		CSP_IOCONF_SET_PUCR1(IOCONF0,temp);
	}
}

/**
*******************************************************************************
* @brief     IO Open-drain Enable	
* @return    None					
* @param     group,port
* \n          input
* \n          brief description - Pointer to PIO structure.
*******************************************************************************
*/
void CSP_IOOpendrainEnable(eGROUPy group, U8_T port)
{
	U32_T temp = 0;
	if(group == GROUP0)
	{
		temp = CSP_IOCONF_GET_ODCR0(IOCONF0);
		CSP_IOCONF_SET_ODCR0(IOCONF0,temp|IOCONF_ODEN(port));
	}
	if(group == GROUP1)
	{
		temp = CSP_IOCONF_GET_ODCR1(IOCONF0);
		CSP_IOCONF_SET_ODCR1(IOCONF0,temp|IOCONF_ODEN(port));
	}
}

/**
*******************************************************************************
* @brief     IO Open-drain Disable	  
* @return    None	
* @param     group,port
* \n          input
* \n          brief description - Pointer to PIO structure.
*******************************************************************************
*/
void CSP_IOOpendrainDisable(eGROUPy group, U8_T port)
{
	U32_T temp = 0;
	if(group == GROUP0)
	{
		temp = CSP_IOCONF_GET_ODCR0(IOCONF0) & (~IOCONF_ODEN(port));
		CSP_IOCONF_SET_ODCR0(IOCONF0,temp);
	}
	if(group == GROUP1)
	{
		temp = CSP_IOCONF_GET_ODCR1(IOCONF0) & (~IOCONF_ODEN(port));
		CSP_IOCONF_SET_ODCR1(IOCONF0,temp);
	}
}

