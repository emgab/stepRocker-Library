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
* @file name	csp_cm.c
* @description Definitions, Macros and function declarations for clock manager
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

/******************************************************************************
* Include Files
******************************************************************************/
#include "csp.h"
//#include "..\BSP\inc\bsp.h"

/******************************************************************************
* Definitions
******************************************************************************/
sCM_Frequency n41f; 

/******************************************************************************
****************************  F U N C T I O N S  ******************************
******************************************************************************/
/******************************************************************************
* @brief     Chip reset by CM's software reset
******************************************************************************/
void CSP_CMSoftwareReset(void)
{
	CSP_CM_SET_SRR(CM0,CM_SWRST);
}
/******************************************************************************
* @brief     Enable/Disable the clock source 
* 			 cmd = ENABLE or DISABLE
******************************************************************************/
void CSP_CMEMCLKCmd(ClockStatus cmd)
{
	if (cmd != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_EMCLK);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_EMCLK);
	}
}

void CSP_CMIMCLKCmd(ClockStatus cmd)
{
	if (cmd != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_IMCLK);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_IMCLK);
	}
}
void CSP_CMESCLKCmd(ClockStatus cmd)
{
	if (cmd != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_ESCLK);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_ESCLK);
	}
}

void CSP_CMISCLKCmd(ClockStatus cmd)
{
	if (cmd != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_ISCLK);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_ISCLK);
	}
}

void CSP_CMPLLCmd(ClockStatus cmd)
{
	if (cmd != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_PLL);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_PLL);
	}
}
void CSP_CMUSBPLLCmd(ClockStatus cmd)
{
	if (cmd != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_USBPLL);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_USBPLL);
	}
}
/******************************************************************************
* @brief     Configure the Peripheral SFR Access Clock Control
******************************************************************************/
void CSP_CMPclkCmd(U32_T Pclk,ClockStatus endis)
{
	if(endis == ENABLE)
	{
		CSP_CM_SET_PCSR(CM0,Pclk);
	}
	else
	{
	  CSP_CM_SET_PCCR(CM0,Pclk);
	}
}
/******************************************************************************
* @brief    STCLK, PCLK gating in idle mode
* @param	-input: ENABLE or DISABLE 
******************************************************************************/
void CSP_CMIdleClkCmd(ClockStatus stclk, ClockStatus pclk)
{
	if (stclk != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_STCLK);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_STCLK);
	}
	if (pclk != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_PCLK);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_PCLK);
	}
}
/******************************************************************************
* @brief     Enable/Disable fast wake-up function
*			 ENABLE or DISABLE
******************************************************************************/
void CSP_CMFastWakeupCmd(FunctionalStatus cmd)
{
	if (cmd != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_FWAKE);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_FWAKE);
	}
}
/******************************************************************************
* @brief    Configure the PLL (System, USB)clock
* @param	-input: PLL P/M/S value
******************************************************************************/
void CSP_CMPLLConfig(U32_T PMS_value)
{
	CSP_CM_SET_PDPR(CM0, PMS_value) ;
}

void CSP_CMUSBPLLConfig(U32_T PMS_value)
{
	CSP_CM_SET_UPDPR(CM0, PMS_value) ;
}
/******************************************************************************
* @brief 	External Main Clock Monitor Configuration
* @param	-input: ENABLE or DISABLE 
******************************************************************************/
void CSP_CMEMClkMonitorConfig(FunctionalStatus cmMonitor,FunctionalStatus cmReset)
{
	if (cmMonitor != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_EMCM);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_EMCM);
	}
	if (cmReset != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_EMCMRST);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_EMCMRST);
	}
}
/******************************************************************************
* @brief     External Main Clock Monitor Configuration
* @param     input - ENABLE or DISABLE
******************************************************************************/
void CSP_CMESClkMonitorConfig(FunctionalStatus cmMonitor,FunctionalStatus cmReset)
{
	if (cmMonitor != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_ESCM);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_ESCM);
	}
	if (cmReset != ENABLE)
	{
		CSP_CM_SET_CCR(CM0, CM_ESCMRST);
	}
	else
	{
		CSP_CM_SET_CSR(CM0, CM_ESCMRST);
	}
}
/******************************************************************************
* @brief     Configure the SYSCLK,PCLK divider
* @return    none
* @param     SCLKDiv
* \n          input
* \n          brief description - SCLK Divider (1,2,4, ...,)
*            - CM_SYSCLK_Div1 ~ CM_SYSCLK_Div256
*             brief description - PCLK Divider (1,2,4, ...,)
*            - CM_PCLK_Div1 ~ CM_PCLK_Div
******************************************************************************/
void CSP_CMSysclkDivConfig(U32_T SClkDiv)
{
	CSP_CM_SET_SCDR(CM0, CM_SDIV(SClkDiv));
}

void CSP_CMPclkDivConfig(U32_T PClkDiv)
{
	CSP_CM_SET_PCDR(CM0, CM_PDIV(PClkDiv));
}

/******************************************************************************
* @brief     Configure the SYSCLK source
******************************************************************************/
void CSP_CMSysclkChange(eCM_SysCLK clkSrc)
{
	U32_T temp_u32;
	CSP_CM_SET_ICR(CM0, CM_STABLE);
	temp_u32 = CSP_CM_GET_MR1(CM0) & ~CM_SYSCLK_MASK;
	CSP_CM_SET_MR1(CM0, temp_u32|CM_SYSCLK_SEL(clkSrc));

#ifdef POLLING
 	while((CSP_CM_GET_RISR(CM0)&CM_STABLE)!= CM_STABLE);
	CSP_CM_SET_ICR(CM0, CM_STABLE);
#endif
}

/******************************************************************************
* @brief     Configure the Watchdog timer source
******************************************************************************/
void CSP_CMWDTClkConfig(eCM_MdCLK clkSrc)
{
	U32_T temp_u32;
	temp_u32 = CSP_CM_GET_MR1(CM0) & ~CM_WDTCLK_MASK;
	CSP_CM_SET_MR1(CM0, temp_u32 | CM_WDTCLK_SEL(clkSrc));
}

/******************************************************************************
* @brief     Configure the  FRT source
******************************************************************************/
void CSP_CMFRTClkConfig(eCM_MdCLK clkSrc,U32_T Mdiv, U32_T Ndiv)
{
	U32_T temp_u32;
	temp_u32 = CSP_CM_GET_MR1(CM0) & ~CM_FRTCLK_MASK;
	CSP_CM_SET_MR1(CM0, temp_u32 | CM_FRTCLK_SEL(clkSrc));
	CSP_CM_SET_FCDR(CM0,CM_MDIV(Mdiv)|CM_NDIV(Ndiv));
}

/******************************************************************************
* @brief     Configure the  STT source
******************************************************************************/
void CSP_CMSTTClkConfig(eCM_MdCLK clkSrc,U32_T Cdiv, U32_T Ddiv)
{
	U32_T temp_u32;
	temp_u32 = CSP_CM_GET_MR1(CM0) & ~CM_STTCLK_MASK;
	CSP_CM_SET_MR1(CM0, temp_u32 | CM_STTCLK_SEL(clkSrc));
	CSP_CM_SET_STCDR(CM0,CM_CDIV(Cdiv)|CM_DDIV(Ddiv));
}

/******************************************************************************
* @brief     Configure the  LCD source
******************************************************************************/
void CSP_CMLCDClkConfig(eCM_MdCLK clkSrc,U32_T Jdiv, U32_T Kdiv)
{
	U32_T temp_u32;
	temp_u32 = CSP_CM_GET_MR1(CM0) & ~CM_LCDCLK_MASK;
	CSP_CM_SET_MR1(CM0, temp_u32 | CM_LCDCLK_SEL(clkSrc));
	CSP_CM_SET_LCDR(CM0,CM_JDIV(Jdiv)|CM_KDIV(Kdiv));
}

/******************************************************************************
* @brief     Returns the frequencies of different on chip clocks
******************************************************************************/
#ifdef FREQUENCY
void CSP_CMGetFrequency(sCM_Frequency* CMClk)
{
	U32_T temp_u32 = 0;
	U32_T sysClk_u32 = 0, get_sdiv = 0, get_pdiv=0, get_pdiv_order = 0;
	U32_T pms = 0, pllpre = 0, pllmul = 0, pllpost = 0;

	/* get the SYSCLK field value */
	sysClk_u32 = CSP_CM_GET_MR1(CM0)& CM_SYSCLK_MASK;

	//SYSCLK
	switch(sysClk_u32)
	{
	case 0x0:// ESCLK
			CMClk->SYSCLK_Frequency = ESCLK_Value;
			break;
	case 0x1:// EMCLK
			CMClk->SYSCLK_Frequency = EMCLK_Value;	
			break;
	case 0x2:// ISCLK
			CMClk->SYSCLK_Frequency = ISCLK_Value;
			break;
	case 0x3:// IMCLK
			CMClk->SYSCLK_Frequency = IMCLK_Value;
			break;
	case 0x4:
			pms = CSP_CM_GET_PDPR(CM0);
			pllpre = (pms & CM_PLLPRE_MASK) >> 8;
			pllmul = (pms & CM_PLLMUL_MASK);
			pllpost = (pms & CM_PLLPOST_MASK) >> 16;
			CMClk->SYSCLK_Frequency = ((EMCLK_Value * pllmul / pllpre) >> pllpost); 
			break;
	default:CMClk->SYSCLK_Frequency = IMCLK_Value;
			break;
	}

	/* ROOTCLK */
	/* get the number of shift to calculate the actual SDIV ratio */
	get_sdiv = CSP_CM_GET_SCDR(CM0) & CM_SDIV_MASK;
	CMClk->MAINCLK_Frequency = CMClk->SYSCLK_Frequency /(get_sdiv+1);

	/* PCLK */
	get_pdiv = CSP_CM_GET_PCDR(CM0) & CM_PDIV_MASK;

	if((get_pdiv& 0x1000)== 0x1000) get_pdiv_order = 16;
	if((get_pdiv& 0x1100)== 0x100) get_pdiv_order = 8;
	if((get_pdiv& 0x1110)== 0x10) get_pdiv_order = 4;
	if(get_pdiv == 0x1) get_pdiv_order = 2;
	if(get_pdiv == 0x0) get_pdiv_order = 1;

	CMClk->PCLK_Frequency = CMClk->MAINCLK_Frequency / get_pdiv_order ;
	/* STCLK */
	if((SYSTICK0->CSR & SYSTICK_CLKSOURCE_CORECLK)==0)  /* external reference clock */
	{
		CMClk->STCLK_Frequency = CMClk->MAINCLK_Frequency >>3; /* Root_clock/8 */
	}
	else
	{
		CMClk->STCLK_Frequency = CMClk->MAINCLK_Frequency; /* Core clock= Root_clock*/
	}
}
#endif

/*******************************************************************************
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
******************************************************************************/
FlagStatus CSP_CMGetFlagStatus(U32_T Flag)
{
	U32_T temp_u32 = 0;

	/* get status from SR register */
	temp_u32 = CSP_CM_GET_SR(CM0) & CM_SR_MASK;

	if ((temp_u32 & Flag) != Flag)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}

/*******************************************************************************
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
******************************************************************************/
FlagStatus CSP_CMGetRawITStatus(U32_T Flag)
{
	U32_T temp_u32 = 0;

	/* get status from SR register */
	temp_u32 = CSP_CM_GET_RISR(CM0) & CM_RISR_MASK;

	if ((temp_u32 & Flag) != Flag)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}

/*******************************************************************************
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
* @par InBodyDocs:
*******************************************************************************/
FlagStatus CSP_CMGetMaskedITStatus(U32_T Flag)
{
	U32_T tmp_u32 = 0;

	/* get status from SR register */
	tmp_u32 = CSP_CM_GET_MISR(CM0) & CM_MISR_MASK;

	if ((tmp_u32 & Flag) != Flag)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}

/******************************************************************************
* @brief     Clear status by writing '1' to ICR register
* @return    none
* @param     FLAG
* \n          input
* \n          brief description - Flag to be cleared
* @pre       None
* @post      None
* @Too      nothing
******************************************************************************/
void CSP_CMClearITFlag(U32_T Flag)
{
	CSP_CM_SET_ICR(CM0, Flag);
}

/*******************************************************************************
* @brief     Config Interrupt
* @return    None
* @param     pwm
* \n          input
* \n          brief description - Pointer to PWM structure.
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
******************************************************************************/
void CSP_CMConfigInterrupt(U32_T intMask_u32,FunctionalStatus newState)
{
	U32_T temp_u32 = 0;

	if (newState != DISABLE)
	{
		temp_u32 = CSP_CM_GET_IMSCR(CM0);
		CSP_CM_SET_IMSCR(CM0, temp_u32|intMask_u32);
	}
	else
	{
		temp_u32 = CSP_CM_GET_IMSCR(CM0)& (~intMask_u32);
		CSP_CM_SET_IMSCR(CM0, temp_u32);
	}
}

/******************************************************************************
* @brief     Send 'STOP' commnd using WFI or WFE
******************************************************************************/
void CSP_CMStopCmd(eWaitingForType type)
{
	CSP_NVICLowPowerConfig(SCB_SLEEPDEEP, ENABLE);
	if(type == eWFI)
	{
		__WFI();
	}
	else
	{
		__WFE();
	}
}

/******************************************************************************
* @brief     Send 'IDLE' commnd using WFI or WFE
******************************************************************************/
void CSP_CMIdleCmd(eWaitingForType type)
{
	if(type == eWFI)
	{
		__WFI();
	}
	else
	{
		__WFE();
	}
}

/******************************************************************************
* @brief     Selection the clock source to check through COPx pin
******************************************************************************/
void CSP_CMClockOutCmd(eCM_MdCLK clksrc)
{
	U32_T temp_u32 = 0;
	temp_u32 = CSP_CM_GET_MR0(CM0)&(~CM_CLKOUT_MASK);
	CSP_CM_SET_MR0(CM0, temp_u32|CM_CLKOUT(clksrc));
}

/******************************************************************************
* @brief     Selection LVD interrupt level (ENABLE or DISABLE, level)
******************************************************************************/
void CSP_CMLvdInterruptCmd(FunctionalStatus cmd,U32_T level)
{
	U32_T temp_u32 = 0;

	if(cmd == ENABLE)
	{
		temp_u32 = CSP_CM_GET_MR0(CM0);
		CSP_CM_SET_MR0(CM0, temp_u32|CM_LVDINTEN|CM_LVDIL(level));
	}
	else
	{
		temp_u32 = CSP_CM_GET_MR0(CM0)& ~CM_LVDINTEN;
		CSP_CM_SET_MR0(CM0, temp_u32|CM_LVDIL(level));
	}
}

/******************************************************************************
* @brief     Selection LVR level (ENABLE or DISABLE, level)
******************************************************************************/
void CSP_CMLVDRCmd(FunctionalStatus cmd,U32_T level)
{
	U32_T temp_u32 = 0;

	if(cmd == ENABLE)
	{
		temp_u32 = CSP_CM_GET_MR0(CM0);
		CSP_CM_SET_MR0(CM0, temp_u32|CM_LVDRSTEN|CM_LVDRL(level));
	}
	else
	{
		temp_u32 = CSP_CM_GET_MR0(CM0)& ~CM_LVDRSTEN;
		CSP_CM_SET_MR0(CM0, temp_u32|CM_LVDRL(level));
	}
}

/******************************************************************************
* @brief     COP pin configuration  (ENABLE or DISABLE)
******************************************************************************/
void CSP_CMClockOutPinConfig(FunctionalStatus cmd)
{
	if(cmd == ENABLE)
	{	/* COP - P0.14, P1.21, P1.18, P1.19 */
		CSP_IOFunctionConfigure(GROUP0, 14, IOCONF_F1);	/* COP  */
		CSP_IOFunctionConfigure(GROUP1, 21, IOCONF_F1);	/* COP  */
	}
	else
	{	/* COP - P0.14, P1.21, P1.18, P1.19 */
		CSP_IOFunctionConfigure(GROUP0, 14, IOCONF_F0);	/* COP  */
		CSP_IOFunctionConfigure(GROUP1, 21, IOCONF_F0);	/* COP  */
	}
}

/******************************************************************************
* @brief     COP4 pin configuration  (ENABLE or DISABLE)
******************************************************************************/
void CSP_CMClockOutPinConfig4(FunctionalStatus cmd)
{
	if(cmd == ENABLE)
	{	/* COP4 - P1.19 */
		CSP_IOFunctionConfigure(GROUP1, 19, IOCONF_F2);	/* COP4  */
	}
	else
	{	/* COP4 - P1.19 */
		CSP_IOFunctionConfigure(GROUP1, 19, IOCONF_F0);	/* COP4  */
	}
}	

/******************************************************************************
* @brief     COP8 pin configuration  (ENABLE or DISABLE)
******************************************************************************/
void CSP_CMClockOutPinConfig8(FunctionalStatus cmd)
{
	if(cmd == ENABLE)
	{ 	/* COP8 - P1.18 */
		CSP_IOFunctionConfigure(GROUP1, 18, IOCONF_F2);	/* COP8  */
	}
	else
	{ 	/* COP8 - P1.18*/
		CSP_IOFunctionConfigure(GROUP1, 18, IOCONF_F0);	/* COP8  */
	}
}

/******************************************************************************
* @brief     Configuration of wakeup source
******************************************************************************/
void CSP_CMWakeupSrcConfig(U32_T num, U32_T src, 
							eWakeupEdgeType edge, FunctionalStatus cmd)
{
	U32_T temp_u32 = 0;
	U32_T prevalue = 0;

	if(num <4)
	{
		prevalue = CSP_CM_GET_WCR0(CM0);
		temp_u32 =(cmd << 0x7)|(edge << 0x6)|CM_WSRC(src);
		CSP_CM_SET_WCR0(CM0,prevalue|(temp_u32 << (num *8)));
	}
	else
	{
		num = num-4;
		prevalue = CSP_CM_GET_WCR1(CM0);
		temp_u32 =(cmd << 0x7)|(edge << 0x6)|CM_WSRC(src);
		CSP_CM_SET_WCR1(CM0,prevalue|temp_u32 << (num *8));
	}
}
