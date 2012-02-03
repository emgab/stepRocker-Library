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
* @file name	csp_resethandler.c
* @description Function declarations for Startup and Vector
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#include "..\CSP\inc\csp.h"	   
extern int __main(void);
extern void CSP_CInit(void);  
/**********************************************************************************************************
 * RESET Handler :call __rt_entry()
**********************************************************************************************************/

void Reset_Handler(void) {

#ifdef 	USER_Startup
	 /* If required, do SRAM check here before ZI is initialized */
	CSP_CInit();
	C_Entry();		
#endif

	__main();  		
}
