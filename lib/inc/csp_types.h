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
* @file name	csp_types.h
* @description Definitions, Macros and Structure declarations
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_TYPES_H
#define CSP_TYPES_H

/******************************************************************************
*********************************** TYPES *************************************
******************************************************************************/

/******************************************************************************
* Data Types
******************************************************************************/
/* Signed Types                                                              */
typedef signed char     	S8_T;
typedef short          	 	S16_T;
typedef long           		S32_T;

/* Unsigned Types                                                            */
typedef unsigned char   	U8_T;
typedef unsigned short  	U16_T;
typedef unsigned long   	U32_T;
typedef unsigned long long 	U64_T;

/* Float Types                                                               */
typedef float	F32_T;
typedef double	F64_T;

/* Boolean types declared as U8_T, as enums are generated as 16 bit          */
typedef U8_T	B_T;

/* Definitions for the two members of the Boolean type                       */
#ifndef FALSE
#define FALSE	((B_T) 0)
#endif

#ifndef TRUE
#define TRUE	((B_T) 1)
#endif

/* UNUSED Definition for unused Interrupt numbers * and unused PDC channels  */
/* in the CHIP structure. (cf. CSP.C file)                                   */
#ifndef UNUSED
#define UNUSED	((U8_T) 0xFF)
#endif

/* NULL definition */
#ifndef NULL
#define NULL  0
#endif

typedef enum {ENABLE = 1, DISABLE = !ENABLE} ClockStatus, FunctionalStatus;
typedef enum {ON = 1, OFF = !ON} PowerStatus, SwitchStatus;
typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;
typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {HIGH = 1, LOW = !HIGH} LevelStatus;
typedef enum {UP = 1, DOWN = !UP} DirectionStatus;
/******************************************************************************
* Peripherals Type
******************************************************************************/
typedef volatile U32_T CSP_REGISTER_T;
typedef volatile U16_T CSP_REGISTER16_T;
typedef volatile U8_T  CSP_REGISTER8_T;

#endif   /* CSP_TYPE_H */
