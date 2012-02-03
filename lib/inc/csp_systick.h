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
* @file name	csp_systick.h
* @description Definitions, Macros and function declarations for CMx systick
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_SYSTICK_H
#define CSP_SYSTICK_H

/*******************************************************************************
*********************** SYSTICK Structure Definition ***************************
*******************************************************************************/
/*******************************************************************************
@brief SYSTICK Structure
*******************************************************************************/

typedef struct
{
    CSP_REGISTER_T  CSR;			/* Control and Status Register            */
    CSP_REGISTER_T  RVR;           	/* Reload Register                        */
    CSP_REGISTER_T  CVR;          	/* Current value Register                 */
    CSP_REGISTER_T  CALIBR;         /* Calibration value Register             */
} CSP_SYSTICK_T, *CSP_SYSTICK_PTR;

typedef enum
{
	SYSTICK_STCLK = 0x0,
	SYSTICK_HCLK = 0x1
}SYSTICK_CLKTypeDef;

/******************************************************************************
*************************** SYSTICK Registers Definition **********************
******************************************************************************/

/******************************************************************************
* CR : Control register
******************************************************************************/
#define SYSTICK_COUNTFLAG   (0x01ul << 16)     /**< Systick Counter expires  */
#define SYSTICK_CLKSOURCE   (0x01ul << 2)      /**< Systick Clock source     */
#define SYSTICK_TICKINT     (0x01ul << 1)      /**< Systick Interrupt en/dis */
#define SYSTICK_ENABLE      (0x01ul << 0)      /**< Systick counter en/dis   */

#define SYSTICK_CLKSOURCE_CORECLK       (0x01ul << 2)
#define SYSTICK_CLKSOURCE_CORECLK_DIV8 ~(0x01ul << 2)

#define SYSTICK_COUNTER_ENABLE          (0x01ul << 0)
#define SYSTICK_COUNTER_DISABLE        ~(0x01ul << 0)
#define SYSTICK_COUNTER_CLEAR           (0x00000000ul)

/******************************************************************************
* LDR : Reload value register
******************************************************************************/
#define SYSTICK_RELOAD_MASK (0xFFFFFFul << 0)  /**< reload value mask        */
#define SYSTICK_RELOAD(val) ((val & 0xFFFFFFul) << 0) /**< reload value macro*/

/******************************************************************************
* VALR : Current value register
******************************************************************************/
#define SYSTICK_CURRENT_MASK (0xFFFFFFul << 0)       /**< current value mask */
#define SYSTICK_CURRENT(val) ((val & 0xFFFFFFul) << 0)
                                                    /**< current value macro */

/******************************************************************************
* CALIBR : Calibration value register
******************************************************************************/
#define SYSTICK_NOREF      (0x01ul << 31)   /**< Systick Ref clock provision */
#define SYSTICK_SKEW       (0x01ul << 30) /**< Systick Cal value suitability */
#define SYSTICK_TENMS_MASK  (0xFFFFFFul << 0)       /**< ten ms value mask   */
#define SYSTICK_TENMS(val) ((val & 0xFFFFFFul) << 0)/**< ten ms value macro  */

/******************************************************************************
*************************** SYSTICK Registers mask ****************************
******************************************************************************/
#define SYSTICK_CSR_MASK    (0x00010007ul)     /**< CSR mask                 */
#define SYSTICK_RVR_MASK    (0x00FFFFFFul)     /**< RVR mask                 */
#define SYSTICK_CVR_MASK   	(0x00FFFFFFul)     /**< CVR mask                 */
#define SYSTICK_CALIBR_MASK	(0xC0FFFFFFul)     /**< CALIB mask               */

/******************************************************************************
********************** SYSTICK Registers reset value **************************
******************************************************************************/
#define SYSTICK_CSR_RST     (0x00000000ul)        /**< CSR reset value       */
#define SYSTICK_RVR_RST     (0x00000000ul)        /**< RVR reset value       */
#define SYSTICK_CVR_RST    	(0x00000000ul)        /**< CVR reset value       */
#define SYSTICK_CALIBR_RST  (0x400186A0ul)        /**< CALIB reset value     */

/******************************************************************************
*************************** Systick Macros Definition *************************
******************************************************************************/
/* CSR :  Systick Control/Status register                                     */
/** Set CSR register                         ;                                */
#define CSP_SYSTICK_SET_CSR(systick, val)  (systick->CSR = (val))
/** Get CSR register                                                          */
#define CSP_SYSTICK_GET_CSR(systick)       (systick->CSR)

/* RVR: Systick reload register                                              */
/** Set LDR register                                                         */
#define CSP_SYSTICK_SET_RVR(systick, val) (systick->RVR = (val))
/** Get LDR register                                                         */
#define CSP_SYSTICK_GET_RVR(systick)      (systick->RVR)

/* CVR: Systick current value register                                      */
/** Set CVR register                                                        */
#define CSP_SYSTICK_SET_CVR(systick, val) (systick->CVR = (val))
/** Get CVR register                                                        */
#define CSP_SYSTICK_GET_CVR(systick)      (systick->CVR)

/* CALIBR: Systick calibration value register                                  */
/** Set CALIBR register                                                        */
#define CSP_SYSTICK_SET_CALIBR(systick, val) (systick->CALIBR = (val))
/** Get CALIBR register                                                        */
#define CSP_SYSTICK_GET_CALIBR(systick)      (systick->CALIBR)

/******************************************************************************
****************** SysTick External Functions Declaration ***************
******************************************************************************/
extern void CSP_SysTickClkConfig(SYSTICK_CLKTypeDef SysTick_ClkSource);
extern void CSP_SysTickReload(U32_T reload_u32);
extern void CSP_SysTickConfigInterrupt(U8_T prePrio_u8,
        U8_T subPrio_u8,
        FunctionalStatus newState);
extern void CSP_SysTickEnable(void);
extern void CSP_SysTickDisable(void);
extern U32_T CSP_SysTickGetCounter(void);
extern U32_T CSP_SysTickGetFlag(void);

#endif /* CSP_SYSTICK_H */
