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
* @file name	csp_svc_handler.h
* @description Definitions, Macros and function declarations
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	 Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_SVC_HANDLER_H_
#define CSP_SVC_HANDLER_H_
									 
/******************************************************************************
* All includes here                                                           *
******************************************************************************/

/******************************************************************************
* All defines here                                                            *
******************************************************************************/
#define SVC_00 0x00 /**< 00: Setup Process Stack */
#define SVC_01 0x01 /**< 01: Priviledged Mode + Main Stack */
#define SVC_02 0x02 /**< 02: Priv -> User */
#define SVC_03 0x03 /**< 03: User -> Priv */

/** NVIC and SCB */
#define SVC_10 0x10 /**< 10: User -> Priv for CSP_NVICInit */
#define SVC_11 0x11 /**< 11: User -> Priv for CSP_SCBInit */
#define SVC_12 0x12 /**< 12: User -> Priv for CSP_NVICPriorityGroupConfig */
#define SVC_13 0x13 /**< 13: User -> Priv for CSP_NVICConfigInterrupt*/
#define SVC_14 0x14 /**< 14: User -> Priv for CSP_NVICGetIntrruptChannelPendingBitStatus */
#define SVC_15 0x15 /**< 15: User -> Priv for CSP_NVICSetInterruptChannelPendingBit */
#define SVC_16 0x16 /**< 16: User -> Priv for CSP_NVIGetCurrentPendingInterruptChannel */
#define SVC_17 0x17 /**< 17: User -> Priv for CSP_NVICClearInterruptChannelPendingBit */
#define SVC_18 0x18 /**< 18: User -> Priv for CSP_NVICGetCurrentActiveHandler */
#define SVC_19 0x19 /**< 19: User -> Priv for CSP_NVICGetIntrruptChannelActiveBitStatus */
#define SVC_1A 0x1A /**< 1A: User -> Priv for CSP_NVICSetVectorTable */
#define SVC_1B 0x1B /**< 1B: User -> Priv for CSP_NVICGenerateSystemReset */
#define SVC_1C 0x1C /**< 1C: User -> Priv for CSP_NVICGenerateCoreReset */
#define SVC_1D 0x1D /**< 1D: User -> Priv for CSP_NVICLowPowerConfig */
#define SVC_1E 0x1E /**< 1E: User -> Priv for CSP_NVICSystemHandlerConfig */
#define SVC_1F 0x1F /**< 1F: User -> Priv for CSP_NVICSystemHandlerPriorityConfig */
#define SVC_20 0x20 /**< 20: User -> Priv for CSP_NVICGetSystemHandlerPendingBitStatus */
#define SVC_21 0x21 /**< 21: User -> Priv for CSP_NVICSetSystemHandlerPendingBit */
#define SVC_22 0x22 /**< 22: User -> Priv for CSP_NVICClearSystemHandlerPendingBit */
#define SVC_23 0x23 /**< 23: User -> Priv for CSP_NVICGetSystemHandlerActiveBitStatus */
#define SVC_24 0x24 /**< 24: User -> Priv for CSP_NVICGetFaultHandlerSources */
#define SVC_25 0x25 /**< 25: User -> Priv for CSP_NVICGetFaultAddress */
#define SVC_26 0x26 /**< 26: User -> Priv for CSP_NVICSetSystemCtrlReg*/
#define SVC_27 0x27 /**< 27: User -> Priv for CSP_NVICClrSystemCtrlReg*/
#define SVC_28 0x28 /**< 28: User -> Priv for CSP_NVICSetConfigCtrlReg */
#define SVC_29 0x29 /**< 29: User -> Priv for CSP_NVICClrConfigCtrlReg */
#define SVC_2A 0x2A /**< 2A: User -> Priv for CSP_NVICSetAppIntRstCtrlReg */
#define SVC_2B 0x2B /**< 2B: User -> Priv for CSP_NVICClrAppIntRstCtrlReg */

/** Systic */
#define SVC_50 0x50 /**< 50: user -> priv: systic */
#define SVC_51 0x51 /**< 51: user -> priv: systic */
#define SVC_52 0x52 /**< 52: user -> priv: systic */
#define SVC_53 0x53 /**< 53: user -> priv: systic */
#define SVC_54 0x54 /**< 54: user -> priv: systic */
#define SVC_55 0x55 /**< 55: user -> priv: systic */
#define SVC_56 0x56 /**< 56: user -> priv: systic */

/******************************************************************************
* All enumerations here                                                       *
******************************************************************************/

/******************************************************************************
* All typedefs here                                                           *
******************************************************************************/

/******************************************************************************
* All constants here                                                          *
******************************************************************************/

/******************************************************************************
* All variables here                                                          *
******************************************************************************/

/******************************************************************************
* All functions here                                                          *
******************************************************************************/
__svc(SVC_00) extern void CSP_SVC_SETUP_PSP(U32_T);
__svc(SVC_01) extern void CSP_SVC_PSPUSER(void);
__svc(SVC_02) extern void CSP_SVC_PRIV_TO_USER(void);
__svc(SVC_03) extern void CSP_SVC_USER_TO_PRIV(void);

__svc(SVC_10) extern void CSP_SVC_NVICInit(void);
__svc(SVC_11) extern void CSP_SVC_SCBInit(void);
__svc(SVC_12) extern void CSP_SVC_NVICPriorityGroupConfig(U32_T);
__svc(SVC_13) extern void CSP_SVC_NVICConfigInterrupt(NVIC_TypeDef*);
__svc(SVC_14) extern ITStatus CSP_SVC_NVICGetIntrruptChannelPendingBitStatus(U8_T);
__svc(SVC_15) extern void CSP_SVC_NVICSetInterruptChannelPendingBit(U8_T);
__svc(SVC_16) extern U16_T CSP_SVC_NVICGetCurrentPendingInterruptChannel(void);
__svc(SVC_17) extern void CSP_SVC_NVICClearInterruptChannelPendingBit(U8_T);
__svc(SVC_18) extern U16_T CSP_SVC_NVICGetCurrentActiveHandler(void);
__svc(SVC_19) extern ITStatus CSP_SVC_NVICGetIntrruptChannelActiveBitStatus(U8_T);
__svc(SVC_1A) extern void CSP_SVC_NVICSetVectorTable(U32_T, U32_T);
__svc(SVC_1B) extern void CSP_SVC_NVICGenerateSystemReset(void);
__svc(SVC_1C) extern void CSP_SVC_NVICGenerateCoreReset(void);
__svc(SVC_1D) extern void CSP_SVC_NVICLowPowerConfig(U32_T, B_T);
__svc(SVC_1E) extern void CSP_SVC_NVICSystemHandlerConfig(U32_T, B_T);
__svc(SVC_1F) extern void CSP_SVC_NVICSystemHandlerPriorityConfig(U32_T, U8_T, U8_T);
__svc(SVC_20) extern ITStatus CSP_SVC_NVICGetSystemHandlerPendingBitStatus(U32_T);
__svc(SVC_21) extern void CSP_SVC_NVICSetSystemHandlerPendingBit(U32_T);
__svc(SVC_22) extern void CSP_SVC_NVICClearSystemHandlerPendingBit(U32_T);
__svc(SVC_23) extern ITStatus CSP_SVC_NVICGetSystemHandlerActiveBitStatus(U32_T);
__svc(SVC_24) extern U32_T CSP_SVC_NVICGetFaultHandlerSources(U32_T);
__svc(SVC_25) extern U32_T CSP_SVC_NVICGetFaultAddress(U32_T);
__svc(SVC_26) extern void CSP_SVC_SetSystemCtrlReg(U32_T);
__svc(SVC_27) extern void CSP_SVC_ClrSystemCtrlReg(U32_T);
__svc(SVC_28) extern void CSP_SVC_SetConfigCtrlReg(U32_T);
__svc(SVC_29) extern void CSP_SVC_ClrConfigCtrlReg(U32_T);
__svc(SVC_2A) extern void CSP_SVC_SetAppIntRstCtrlReg(U32_T);
__svc(SVC_2B) extern void CSP_SVC_ClrAppIntRstCtrlReg(U32_T);

__svc(SVC_50) extern void CSP_SVC_SysTickClkConfig(SYSTICK_CLKTypeDef) ;
__svc(SVC_51) extern void CSP_SVC_SysTickReload(U32_T);
__svc(SVC_52) extern void CSP_SVC_SysTickConfigInterrupt(U8_T, U8_T, \
		FunctionalStatus);
__svc(SVC_53) extern void CSP_SVC_SysTickEnable(void);
__svc(SVC_54) extern void CSP_SVC_SysTickDisable(void);
__svc(SVC_55) extern U32_T CSP_SVC_SysTickGetCounter(void);
__svc(SVC_56) extern U32_T CSP_SVC_SysTickGetFlag(void);


#endif /**< CSP_SVC_HANDLER_H_ */
