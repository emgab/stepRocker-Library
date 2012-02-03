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
* @file name	csp_pseudo_intrinsics.c
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

/* Small pieces of assembler that the compiler does not have an intrinsic for.
*
* If kept to a single 32bit instruction or 1 or 2 16bit instructions then
* the linker will be able to inline the instruction(s) in the space occupied
* by the 32bit BL that the compiler uses to call the function.
* Must turn on inlining with --inline i.e.
*
* armlink --inline ...
*
*/
/******************************************************************************
* Include Files
******************************************************************************/
#include "csp.h"

void __attribute__ ((naked)) __WFI(void)
{
  asm volatile("wfi\n\t"
               "bx r14\n\t");
}

void __attribute__ ((naked)) __WFE(void)
{
  asm volatile("wfe\n\t"
               "bx r14\n\t");
}

void __attribute__ ((naked)) __SEV(void)
{
  asm volatile("sev\n\t"
               "BX r14\n\t");
}

void __attribute__ ((naked)) __ISB(void)
{
    asm volatile("isb\n\t"
                 "bx r14\n\t");
}

void __attribute__ ((naked)) __DSB(void)
{
    asm volatile("dsb\n\t"
                 "bx r14\n\t");
}

void __attribute__ ((naked)) __DMB(void)
{
    asm volatile("dmb\n\t"
                 "bx r14\n\t");
}

void __attribute__ ((naked)) __SVC(void)
{
    asm volatile("svc 0x01\n\t"
                 "bx r14\n\t");
}

int __attribute__ ((naked)) __MRS_control(void)
{
    asm volatile("mrs r0,control\n\t"
                 "bx lr\n\t");
}

void __attribute__ ((naked)) __MSR_control(int control)
{
    asm volatile("msr control,r0\n\t"
                 "bx lr\n\t");
}

int __attribute__ ((naked)) __MRS_PSP(void)
{
    asm volatile("mrs r0,psp\n\t"
                 "bx lr\n\t");
}

void __attribute__ ((naked)) __MSR_PSP(int psp)
{
    asm volatile("msr psp,r0\n\t"
                 "bx lr\n\t");
}

int __attribute__ ((naked)) __MRS_MSP(void)
{
    asm volatile("mrs r0,msp\n\t"
                 "bx lr\n\t");
}

void __attribute__ ((naked)) __MSR_MSP(int msp)
{
    asm volatile("msr msp,r0\n\t"
                 "bx lr\n\t");
}

void __attribute__ ((naked)) __SETPRIMASK(void)
{
    asm volatile("cpsid i\n\t"
                 "bx r14\n\t");
}

void __attribute__ ((naked)) __RESETPRIMASK(void)
{
    asm volatile("cpsie i\n\t"
                 "bx r14\n\t");
}  

short __attribute__ ((naked)) __REVHALFWORD(short halfword)
{
    asm volatile("rev16 r0,r0\n\t"
                 "bx lr\n\t");
}

int __attribute__ ((naked)) __REVWORD(int word)
{
    asm volatile("rev r0,r0\n\t"
                 "bx lr\n\t");
}

void __attribute__ ((naked)) __NOP(void)
{
	asm volatile("nop\n\t"
	             "bx r14\n\t");
}



/*
__asm void __SETFAULTMASK(void)
{
    //CPSID f
    BX r14
}

__asm void __RESETFAULTMASK(void)
{
    //CPSIE f
    BX r14
}

__asm void __BASEPRICONFIG(int basepri)
{
    //MSR BASEPRI,r0
    BX lr
}

__asm int __GETBASEPRI(void)
{
    //MRS r0,BASEPRI_MAX
    BX lr
}
*/