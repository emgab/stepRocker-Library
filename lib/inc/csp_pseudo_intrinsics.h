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
* @file name	csp_pseudo_intrinsics.h
* @description Definitions, Macros and function declarations for Pseudo functions
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef PSEUDO_INTRINSICS_H_
#define PSEUDO_INTRINSICS_H_

/* Small pieces of assembler that the compiler does not have an intrinsic for.
*
* If kept to a single 32bit instruction or 1 or 2 16bit instructions then
* the linker will be able to inline the instruction(s) in the space occupied
* by the 32bit BL that the compiler uses to call the function.
* Must turn on inlining with --inline i.e.
*
* armlink --inline ...
*/

void __WFI(void);
void __WFE(void);
void __SEV(void);
void __ISB(void);
void __DSB(void);
void __DMB(void);
void __SVC(void);
int __MRS_control(void);
void __MSR_control(int control);
int __MRS_PSP(void);
void __MSR_PSP(int psp);
int __MRS_MSP(void);
void __MSR_MSP(int msp);
void __SETPRIMASK(void);
void __RESETPRIMASK(void);
void __SETFAULTMASK(void);
void __RESETFAULTMASK(void);
void __BASEPRICONFIG(int basepri);
int __GETBASEPRI(void);
short __REVHALFWORD(short halfword);
int __REVWORD(int word);
void __NOP(void);		  

#endif /*PSEUDO_INTRINSICS_H_*/
