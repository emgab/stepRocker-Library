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
* @file name	csp_debug.h
* @description Definitions, Macros and function declarations for debug module
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_DEBUG_H
#define CSP_DEBUG_H	 

/******************************************************************************
**************************  Structure Definition     **************************
******************************************************************************/
/******************************************************************************
@brief Debug Structure - Core Debug Register
******************************************************************************/
typedef struct
{
   CSP_REGISTER_T  DHCSR;	/**< Debug Halting Control/Status Reg.:0xE000EDF0*/
   CSP_REGISTER_T  DCRSR;   /**< Debug Core Register Selector Reg.:0xE000EDF4*/
   CSP_REGISTER_T  DCRDR;   /**< Debug Core Register Data Register:0xE000EDF8*/
   CSP_REGISTER_T  DEMCR;   /**< Debug Exception/Monitor Control  :0xE000EDFC */
} CSP_DEBUG_T, *CSP_DEBUG_PTR;

/******************************************************************************
@brief DWT Structure
******************************************************************************/

typedef struct
{
   CSP_REGISTER_T  COMP;	/**< Debug Halting Control/Status Reg.:0xE000EDF0*/
   CSP_REGISTER_T  MASK;   	/**< Debug Core Register Selector Reg.:0xE000EDF4*/
   CSP_REGISTER_T  FUNCTION;/**< Debug Core Register Data Register:0xE000EDF8*/
} CSP_DWT_PART_T, *CSP_DWT_PART_PTR;


typedef struct
{
   CSP_REGISTER_T  CTRL;        /**< Control Register 			*/
   CSP_REGISTER_T  PCSR;        /**< PC sampling Register  	 	*/
   CSP_DWT_PART_T  CMF[15];		/**< DWT Comparator Register    */
} CSP_DWT_T, *CSP_DWT_PTR;

/******************************************************************************
@brief BPU Structure
******************************************************************************/
#define NB_BPU_COMP_CHANNEL	15

typedef struct
{
   CSP_REGISTER_T  CTRL;           /**< Breakpoint Control Register         */
   CSP_REGISTER_T  ReservedA;
   CSP_REGISTER_T  COMP[NB_BPU_COMP_CHANNEL]; /**< Breakpoint Comparator Registerx */
} CSP_BPU_T, *CSP_BPU_PTR;

/******************************************************************************
************************** DWT Registers Definition ***************************
******************************************************************************/
/******************************************************************************
* CTRL : Control Register
******************************************************************************/
/** Number of comparators available */
#define DWT_NUMCOMP_MASK    (0x0Ful << 28)    	 
#define CSP_DWT_GET_CR(dwt)   (dwt->CR)	

/******************************************************************************
* PCSR : PC Sample Register
******************************************************************************/
#define DWT_EIASAMPLE_MASK    (0xFFFFFFFFul << 0)  
#define CSP_DWT_GET_PCSR(dwt)   (dwt->PCSR)

/******************************************************************************
* COMPx : Comparator x Register
******************************************************************************/
#define DWT_COMP_MASK    (0xFFFFFFFFul << 0)   
#define DWT_COMP(val)    ((val & 0xFFFFFFFFul) <<0)

#define CSP_DWT_SET_COMP0(dwt, val)   (dwt->COMP0 = (val))
#define CSP_DWT_GET_COMP0(dwt) 		  (dwt->COMP0)

/******************************************************************************
* MASKx : Mask x Register
******************************************************************************/
#define DWT_MASK_MASK    (0x1Ful << 0)    
#define DWT_MASK(val)    ((val & 0x1Ful) <<0)

#define CSP_DWT_SET_MASK0(dwt, val)	(dwt->MASK0 = (val))
#define CSP_DWT_GET_MASK0(dwt)		(dwt->MASK0)


/******************************************************************************
* FUNCTIONx : Function x Register
******************************************************************************/
#define DWT_MATCHED    		(0x01ul << 24)    
#define DWT_FUNCTION_MASK	(0xFul << 0)    
#define DWT_FUNCTION(val)  	((val & 0x0Ful) <<0)

#define CSP_DWT_SET_FUNCTION0(dwt, val)	(dwt->FUNCTION0 = (val))
#define CSP_DWT_GET_FUNCTION0(dwt)   	(dwt->FUNCTION0)

/******************************************************************************
************************** BPU Registers Definition ***************************
******************************************************************************/
/******************************************************************************
* CR : Control Register
******************************************************************************/
/**< Number of breakpoint comparators Comparators: BP_COMP[NUM_CODE-1:0]
	NUM_CODE == 0: no comparator support */
#define BPU_NUMCODE_MASK    (0x0Ful << 4)
/**< RAZ on reads, SBO (should-be-one) for writes. If zero written,
	the write to the register can be ignored. */    
#define BPU_KEY          (0x01ul << 1)  
/**< Enable the breakpoint unit when set. This bit is cleared on a
									power-up reset.          */
#define BPU_ENABLE    (0x01ul << 0)   

/** Set CR register                                                       */
#define CSP_BPU_SET_CR(bpu, val)   (bpu->CR = (val))
#define CSP_BPU_GET_CR(bpu)   (bpu->CR)

/******************************************************************************
* COMPx : Comparator Register
******************************************************************************/
#define BPU_MATCH_MASK    (0x3ul << 30)  
/**< BP_MATCH defines the behavior when the COMP address is matched:
00: no breakpoint matching
01: breakpoint on lower half-word, upper is unaffected
10: breakpoint on upper half-word, lower is unaffected
11: breakpoint on both lower and upper half-words.
The field is UNKNOWN on reset.   */

#define BPU_MATCH(val)    ((val & 0x3) <<30)  
/**<Address for breakpoint comparison is ¡®000¡¯:COMP:¡¯00¡¯ The field is UNKNOWN on reset.*/
#define BPU_COMP_MASK    (0x7FFFFFFFul <<2)    
#define BPU_COMP(val)    ((val & 0x7FFFFFFul) << 2)  
/**< Comparator is enabled when this bit is set. This bit is cleared on a power-up reset. */
#define BPU_ENABLE   	 (0x01ul << 0) 		 

#define CSP_DMA_SET_COMP(bpu, channel, val) (bpu->COMP[channel] = val)
#define CSP_DMA_GET_COMP(bpu, channel) (bpu->COMP[channel])

#endif   /* CSP_DEBUG_H */
