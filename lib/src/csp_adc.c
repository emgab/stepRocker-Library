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
* @file name	csp_adc.c
* @description Definitions, Macros and function declarations for ADC
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*
*/

/******************************************************************************
* Include Files
******************************************************************************/
#include "csp.h"

/******************************************************************************
****************************  F U N C T I O N S  ******************************
*******************************************************************************/			
/**
*******************************************************************************
* @brief     ADC input pin (AINx) configuration
* @return    none 
* @param     adc
* \n          input
* \n          brief description - Pointer to ADC structure.
* @param     ch
* \n          input
* \n          brief description - adc channel number (from 1 to 10) 
*******************************************************************************
*/
void CSP_ADCPinConfiguration(CSP_ADC_T *adc, U8_T ch)
{
	CSP_IOFunctionConfigure(GROUP1, 9+ch, IOCONF_F1);  //*** Bug fixed by Trinamic (OK)
}

void CSP_ADCTriggerPinConfiguration(CSP_ADC_T *adc)
{
	CSP_IOFunctionConfigure(GROUP0, 6, IOCONF_F3); 
}
/**
*******************************************************************************
* @brief     ADC Software Reset
* @return    none  
* @param     adc
* \n          input
* \n          brief description - Pointer to ADC structure.
*******************************************************************************
*/
void CSP_ADCSoftwareReset(CSP_ADC_T *adc)
{
   /* ADC Software Reset */
   CSP_ADC_SET_SRR(adc, ADC_SWRST);
}
/**
*******************************************************************************
* @brief     ADC Clock Enable, Clock configuration, ADC Macro Engine Enable
*            the ADC module mode and the LDMA RX line 
* @return    none 
* @param     adc
* \n          input
* \n          brief description - Pointer to ADC structure.
* @param     mode_u32
* \n          input
* \n          brief description - Configure the ADC mode. 
*******************************************************************************
*/
void CSP_ADCOpen(CSP_ADC_T *adc, U8_T clockdiv)
{
   /* ADC Clock Enable */
   CSP_ADC_SET_CEDR(adc, ADC_CLKEN);

   /* ADC Software Reset */
   CSP_ADC_SET_SRR(adc, ADC_SWRST);

   /* ADC clock divider */
   CSP_ADC_SET_CDR(adc, ADC_CDIV(clockdiv));

   /* ADC Macro Engine Enable */
   CSP_ADC_SET_CSR(adc, ADC_ADCEN);	   
}

/**
*******************************************************************************
* @brief     Switch on the clock, reset the registers and configure
*            the ADC module mode and the LDMA RX line 
* @return    none 
* @param     adc
* \n          input
* \n          brief description - Pointer to ADC structure.
* @param     mode_u32
* \n          input
* \n          brief description - Configure the ADC mode. 
*******************************************************************************
*/
void CSP_ADCInit(CSP_ADC_T *adc, U8_T clockdiv, U8_T ch, U8_T trig)
{
	/* AINx Pin configuration */


   /* ADC Clock Enable */
   CSP_ADC_SET_CEDR(adc, ADC_CLKEN);

   /* ADC Software Reset */
   CSP_ADC_SET_SRR(adc, ADC_SWRST);

   /* ADC clock divider */
   CSP_ADC_SET_CDR(adc, ADC_CDIV(clockdiv));

   /* ADC Macro Engine Enable */
   CSP_ADC_SET_CSR(adc, ADC_ADCEN);

   /* ADC  */
   CSP_ADC_SET_MR(adc, ADC_TRIG(trig)|ADC_CCSEL(ch));
}
/**
*******************************************************************************
* @brief     ADC Channel & Trigger Configuration
* @return    none  
* @param     adc
* \n         input
* \n         brief description - Pointer to ADC structure.
*******************************************************************************
*/		
void CSP_ADCChannelTrigger(CSP_ADC_T *adc, U8_T ch, U8_T trig)
{
   CSP_ADC_SET_MR(adc, ADC_TRIG(trig)|ADC_CCSEL(ch));
}
/**
*******************************************************************************
* @brief     STart ADC
* @return    none  
* @param     adc
* \n         input
* \n         brief description - Pointer to ADC structure.
*******************************************************************************
*/
void CSP_ADCStartConversion(CSP_ADC_T *adc)
{
   /* Start ADC - Software Trigger */
   CSP_ADC_SET_CSR(adc, ADC_START);
}

/**
*******************************************************************************
* @brief     Read Conversion Data 
* @return    none 
* @param     adc
* \n          input
* \n          brief description - Pointer to ADC structure.
*******************************************************************************
*/
U16_T CSP_ADCReadConversionData(CSP_ADC_T *adc)
{
    return (CSP_ADC_GET_CRR(adc));
}  

/**
*******************************************************************************
* @brief     Configure ADC Interrupts 
* @return    none	   
* @param     adc
* \n          input
* \n          brief description - Pointer to ADC structure.
* @param     intMask_u32
* \n          input
* \n          brief description - Configure which interrupt bits are activated.		 
* @param     prePrio_u8
* \n          input
* \n          brief description - preemption priority 
* @param     subPrio_u8
* \n          input
* \n          brief description - sub priority
*******************************************************************************
*/
void CSP_ADCConfigInterrupt(CSP_ADC_T *adc, U32_T intMask_u32,\
                              FunctionalStatus newState)
{
	if (newState != DISABLE)  /* Enable */
	{
		/* Disable target interrupts */
		CSP_ADC_SET_IMSCR(adc, adc->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_ADC_SET_ICR(adc, intMask_u32);

		/* Enable target interrupt */
		CSP_ADC_SET_IMSCR(adc, adc->IMSCR | intMask_u32);
	}
	else /* Disable */
	{
		/* Disable target interrupts */
		CSP_ADC_SET_IMSCR(adc, adc->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_ADC_SET_ICR(adc, intMask_u32);
	}
}
/**
*******************************************************************************
* @brief     Reset and switch off the clock	
* @return    none  
* @param     adc
* \n          input
* \n          brief description - Pointer to ADC structure.
*******************************************************************************
*/
void CSP_ADCClose(CSP_ADC_T *adc)
{
   /* ADC Software Reset */
   CSP_ADC_SET_SRR(adc, ADC_SWRST);

   /* Disable ADC Clock */
   CSP_ADC_SET_CEDR(adc, CSP_ADC_GET_CEDR(adc) & ~ADC_CLKEN);
}

