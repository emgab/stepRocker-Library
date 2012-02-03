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
* @file name	csp_nvic.h
* @description Definitions, Macros and function declarations for NVIC
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_NVIC_H
#define CSP_NVIC_H

/******************************************************************************
************************** NVIC Structure Definition **************************
******************************************************************************/
/******************************************************************************
@brief NVIC/SCB Structure
******************************************************************************/
typedef struct
{
    CSP_REGISTER_T  ISER[32];     	/**< Set enable register                  */
    CSP_REGISTER_T  ICER[32];    	/**< Clear enable register                */
    CSP_REGISTER_T  ISPR[32];    	/**< Set pending register                 */
    CSP_REGISTER_T  ICPR[32];      	/**< Clear pending register               */
    CSP_REGISTER_T  ACTIVE;         /**< Active bit register                  */
    CSP_REGISTER_T 	ReservedA[63];
    CSP_REGISTER_T  IPR[8];   		/**< Priority register 4x8 = 32           */
} CSP_NVIC_T, *CSP_NVIC_PTR;

typedef struct
{
    CSP_REGISTER_T  CPUID;	/**< CPU ID base register: 0xE000ED00             */
    CSP_REGISTER_T  ICSR;   /**< Interrupt Control State Register: 0xE000ED04 */
    CSP_REGISTER_T  VTOR;   /**< Vector Table Offset Register: 0xE000ED08     */
    CSP_REGISTER_T  AIRCR;  /**< Application Interrupt/Reset Control Register
								 : 0xE000ED0C	 							  */
    CSP_REGISTER_T  SCR;    /**< System Control Register: 0xE000ED10          */
    CSP_REGISTER_T  CCR;    /**< Configuration Control Register: 0xE000ED14   */
    CSP_REGISTER_T  ReservedA;
    CSP_REGISTER_T  SHPR2;  /**< System Handlers Priority Register: 0xE000ED1C*/
    CSP_REGISTER_T  SHPR3;  /**< System Handlers Priority Register: 0xE000ED20*/
    CSP_REGISTER_T  SHCSR;  /**< System Handler Control and State Register
								: 0xE000ED24  */
    CSP_REGISTER_T  ReservedB[2];
    CSP_REGISTER_T  DFSR;	/**< Debug Fault Status Register: 0xE000ED30	*/
 } CSP_SCB_T, *CSP_SCB_PTR;

typedef struct
{
  U8_T NVIC_IRQChannel;
  U8_T NVIC_IRQChannelPreemptionPriority;
  U8_T NVIC_IRQChannelSubPriority;
  FunctionalStatus NVIC_IRQChannelCmd;
} NVIC_TypeDef;

/******************************************************************************
****************************** NVIC Registers Definition **********************
******************************************************************************/
/******************************************************************************
* System Handlers
******************************************************************************/
#define SystemHandler_HardFault    ((U32_T)0x000000) /* Hard Fault Handler   */
#define SystemHandler_SVCall       ((U32_T)0x01FF40) /* SVCall Handler       */
#define SystemHandler_PSV          ((U32_T)0x02829C) /* PSV Handler          */
#define SystemHandler_SysTick      ((U32_T)0x02C39A) /* SysTick Handler      */

/******************************************************************************
* Vector Table Base
******************************************************************************/
#define NVIC_VECTAB_RAM             ((U32_T)0x00300000)
#define NVIC_VECTAB_FLASH           ((U32_T)0x00000000)

/******************************************************************************
* ENABLE, DISABLE, SET, CLEAR, ACTIVE: NVIC Interrupt Registers
******************************************************************************/
#define NVIC_INT0      (0x01ul << 0)       /**< Peripheral Interrupt 0        */
#define NVIC_INT1      (0x01ul << 1)       /**< Peripheral Interrupt 1        */
#define NVIC_INT2      (0x01ul << 2)       /**< Peripheral Interrupt 2        */
#define NVIC_INT3      (0x01ul << 3)       /**< Peripheral Interrupt 3        */
#define NVIC_INT4      (0x01ul << 4)       /**< Peripheral Interrupt 4        */
#define NVIC_INT5      (0x01ul << 5)       /**< Peripheral Interrupt 5        */
#define NVIC_INT6      (0x01ul << 6)       /**< Peripheral Interrupt 6        */
#define NVIC_INT7      (0x01ul << 7)       /**< Peripheral Interrupt 7        */
#define NVIC_INT8      (0x01ul << 8)       /**< Peripheral Interrupt 8        */
#define NVIC_INT9      (0x01ul << 9)       /**< Peripheral Interrupt 9        */
#define NVIC_INT10     (0x01ul << 10)      /**< Peripheral Interrupt 10       */
#define NVIC_INT11     (0x01ul << 11)      /**< Peripheral Interrupt 11       */
#define NVIC_INT12     (0x01ul << 12)      /**< Peripheral Interrupt 12       */
#define NVIC_INT13     (0x01ul << 13)      /**< Peripheral Interrupt 13       */
#define NVIC_INT14     (0x01ul << 14)      /**< Peripheral Interrupt 14       */
#define NVIC_INT15     (0x01ul << 15)      /**< Peripheral Interrupt 15       */
#define NVIC_INT16     (0x01ul << 16)      /**< Peripheral Interrupt 16       */
#define NVIC_INT17     (0x01ul << 17)      /**< Peripheral Interrupt 17       */
#define NVIC_INT18     (0x01ul << 18)      /**< Peripheral Interrupt 18       */
#define NVIC_INT19     (0x01ul << 19)      /**< Peripheral Interrupt 19       */
#define NVIC_INT20     (0x01ul << 20)      /**< Peripheral Interrupt 20       */
#define NVIC_INT21     (0x01ul << 21)      /**< Peripheral Interrupt 21       */
#define NVIC_INT22     (0x01ul << 22)      /**< Peripheral Interrupt 22       */
#define NVIC_INT23     (0x01ul << 23)      /**< Peripheral Interrupt 23       */
#define NVIC_INT24     (0x01ul << 24)      /**< Peripheral Interrupt 24       */
#define NVIC_INT25     (0x01ul << 25)      /**< Peripheral Interrupt 25       */
#define NVIC_INT26     (0x01ul << 26)      /**< Peripheral Interrupt 26       */
#define NVIC_INT27     (0x01ul << 27)      /**< Peripheral Interrupt 27       */
#define NVIC_INT28     (0x01ul << 28)      /**< Peripheral Interrupt 28       */
#define NVIC_INT29     (0x01ul << 29)      /**< Peripheral Interrupt 29       */
#define NVIC_INT30     (0x01ul << 30)      /**< Peripheral Interrupt 30       */
#define NVIC_INT31     (0x01ul << 31)      /**< Peripheral Interrupt 31       */

#define CSP_NVIC_GET_ISER(nvic, interrupt)    ((nvic)->ISER[(interrupt)])
#define CSP_NVIC_SET_ISER(nvic, interrupt, val)                             \
                                        ((nvic)->ISER[(interrupt)] = (val))

#define CSP_NVIC_GET_ICER(nvic, interrupt)   ((nvic)-> ICER[(interrupt)])
#define CSP_NVIC_SET_ICER(nvic, interrupt, val)                            \
                                        ((nvic)->ICER[(interrupt)] = (val))

#define CSP_NVIC_GET_ISPR(nvic, interrupt)    ((nvic)->ISPR[(interrupt)])
#define CSP_NVIC_SET_ISPR(nvic, interrupt, val)                                \
                                        ((nvic)->ISPR[(interrupt)] = (val))

#define CSP_NVIC_GET_ICPR(nvic, interrupt)    ((nvic)->ICPR[(interrupt)])
#define CSP_NVIC_SET_ICPR(nvic, interrupt, val)                              \
                                        ((nvic)->ICPR[(interrupt)] = (val))

#define CSP_NVIC_GET_ACTIVE(nvic)    ((nvic)->ACTIVE)

/******************************************************************************
* Priority register: NVIC Interrupt Registers
******************************************************************************/
#define NVIC_PRIORITY_0     (0x00ul)
#define NVIC_PRIORITY_1     (0x01ul)
#define NVIC_PRIORITY_2     (0x02ul)
#define NVIC_PRIORITY_3     (0x03ul)

#define CSP_NVIC_GET_IPR(nvic,interrupt)  ((nvic)->IPR[(interrupt)])
#define CSP_NVIC_SET_IPR(nvic, interrupt, val)                           \
                                        ((nvic)->IPR[(interrupt)] = (val))

/******************************************************************************
*************************** SCB Registers Definition **************************
******************************************************************************/
/******************************************************************************
* CPUID : CPU ID register
******************************************************************************/
#define SCB_REVISION_MASK     	((0x0Ful) << 0)
#define SCB_PARTNO_MASK       	((0xFFFul) << 4)
#define SCB_VARIANT_MASK      	((0x0Ful) << 20)
#define SCB_IMPLEMENTER_MASK	((0xFFul) << 24)

/* Cortex M0 - ID */
#define SCB_CPUID 			 	(0x410CC200)
#define CSP_SCB_GET_CPUID(scb)	((scb)->CPUID)

/******************************************************************************
* ICSR : Interrupt Control State Register
******************************************************************************/
#define SCB_RETTOBASE    (0x01ul << 11)     /**< */
#define SCB_ISRPENDING   (0x01ul << 22)     /**< Interrupt pending flag      */
#define SCB_ISRPREEMPT   (0x01ul << 23)     /**< Pending flag active         */
#define SCB_PENDSTCLR    (0x01ul << 25)     /**< Clear pending SysTick bit   */
#define SCB_PENDSTSET    (0x01ul << 26)     /**< Set SysTick pending bit     */
#define SCB_PENDSVCLR    (0x01ul << 27)     /**< Clear pending pendSV bit    */
#define SCB_PENDSVSET    (0x01ul << 28)     /**< Set pendSV pending bit      */
#define SCB_NMIPENDSET   (0x01ul << 31)     /**< Set NMI pending pit         */
#define SCB_VECTACTIVE_MASK   ((0x1FFul) << 0)  /**< Active ISR number       */
#define SCB_VECTPENDING_MASK  ((0x3FFul) << 12) /**< Pending ISR number      */

#define CSP_SCB_GET_ICSR(scb)         ((scb)->ICSR)
#define CSP_SCB_SET_ICSR(scb, val)    ((scb)->ICSR = (val))
/******************************************************************************
* VTOR : Vector Table Offset Register
******************************************************************************/
#define SCB_TBLBASE     (0x01ul << 29)     /**< Vector Table Location    	*/
#define SCB_TBLOFF_MASK	((0x3FFFFFul) << 7)  /**< Vector Table Base Offset 	*/

#define CSP_SCB_GET_VTOR(scb)         ((scb)->VTOR)
#define CSP_SCB_SET_VTOR(scb, val)    ((scb)->VTOR = (val))

/******************************************************************************
* AIRCR : Application Interrupt and Reset Control Register
******************************************************************************/
#define SCB_VECKEY_MASK   (0xFFFFul << 16)  /**< AIRCR key mask              */
#define SCB_VECKEY        (0x5FAul << 16)   /**< AIRCR key                   */
#define SCB_VECTRESET     (0x01ul << 0)     /**< System Reset (except Debug) */
#define SCB_VECTCLRACTIVE (0x01ul << 1)     /**< Clear active vector bit     */
#define SCB_SYSRESETREQ   (0x01ul << 2)     /**< Reset signal asserted to
                                                                outer system */
#define SCB_PRIGROUP_MASK ((0x07ul) << 8) /**< Interrupt Priority Group mask */
#define SCB_ENDIANESS     (0x01ul << 15)    /**< Data endianness bit         */

/* Preemption Priority Group ------------------------------------------------*/
#define NVIC_PRIOGRP_7     ((U32_T)0x7ul)   /**< 0 bits (pre), 4 bits (sub)  */
#define NVIC_PRIOGRP_6     ((U32_T)0x6ul)   /**< 1 bits (pre), 3 bits (sub)  */
#define NVIC_PRIOGRP_5     ((U32_T)0x5ul)   /**< 2 bits (pre), 2 bits (sub)  */
#define NVIC_PRIOGRP_4     ((U32_T)0x4ul)   /**< 3 bits (pre), 1 bits (sub)  */
#define NVIC_PRIOGRP_3     ((U32_T)0x3ul)   /**< 4 bits (pre), 0 bits (sub)  */

#define CSP_SCB_GET_AIRCR(scb)         ((scb)->AIRCR)
#define CSP_SCB_SET_AIRCR(scb, val)    ((scb)->AIRCR = (val | SCB_VECKEY))

/******************************************************************************
* SCR : System Control Register
******************************************************************************/
#define SCB_SLEEPONEXIT          (0x01ul << 1)  /**< WFE wakeup with interrupt */
#define SCB_SLEEPDEEP            (0x01ul << 2)  /**< Sleep Deep              */
#define SCB_SEVONPEND            (0x01ul << 4)  /**< Sleep on exit when
                                       returning from Handler to Thread mode */

#define CSP_SCB_GET_SCR(scb)         ((scb)->SCR)
#define CSP_SCB_SET_SCR(scb, val)    ((scb)->SCR = (val))

/******************************************************************************
* CCR : Configuration Control Register
******************************************************************************/
#define SCB_NONEBASETHRDENA (0x01ul << 0) /**< Thread mode from last exception */
#define SCB_USERSETMPEND    (0x01ul << 1) /**< Enable Software trigger Interrupt */
#define SCB_UNALIGN_TRP     (0x01ul << 3) /**< Trap for unaligned access     */
#define SCB_DIV_0_TRP       (0x01ul << 4) /**< Trap on Divide by 0           */
#define SCB_BFHFNMIGN       (0x01ul << 8) /**< Handlers at priority -1, -2   */
#define SCB_STKALIGN        (0x01ul << 9) /**< SP alignment in 8bytes        */

#define CSP_SCB_GET_CCR(scb)         ((scb)->CCR)
#define CSP_SCB_SET_CCR(scb, val)    (scb->CCR = (val))

/******************************************************************************
* SHPR : System Handler Priority Registers
******************************************************************************/
#define SCB_PRIORITY_0     (0x00ul)
#define SCB_PRIORITY_1     (0x01ul)
#define SCB_PRIORITY_2     (0x02ul)
#define SCB_PRIORITY_3     (0x03ul)

#define CSP_SCB_GET_SHPR2(scb)  	((scb)->SHPR2)
#define CSP_SCB_SET_SHPR2(scb,val) 	((scb)->SHPR2 = (val))
#define CSP_SCB_GET_SHPR3(scb)  	((scb)->SHPR3)
#define CSP_SCB_SET_SHPR3(scb,val) 	((scb)->SHPR3 = (val))
/******************************************************************************
* SHCSR : System Handler Control and State Register
******************************************************************************/
#define SCB_SVCALLPENDED   (0x01ul << 15)  /**< SVCall pended                */

#define CSP_SCB_GET_SHCSR(scb)         ((scb)->SHCSR)
#define CSP_SCB_SET_SHCSR(scb, val)    ((scb)->SHCSR = (val))


/******************************************************************************
*************************** NVIC Registers mask ****************************
******************************************************************************/
#define NVIC_ISER_MASK    	(0xFFFFFFFFul)    /**< Enable[0] mask           */
#define NVIC_ICER_MASK   	(0xFFFFFFFFul)    /**< Disable[0] mask          */
#define NVIC_ISPR_MASK      (0xFFFFFFFFul)    /**< Set[0] mask              */
#define NVIC_ICPR_MASK    	(0xFFFFFFFFul)    /**< Clear[0] mask            */
#define NVIC_IPR_MASK 		(0xC0C0C0C0ul) 	  /**< Priority[0~13] mask      */
/******************************************************************************
************************* NVIC Registers reset value **************************
******************************************************************************/
#define NVIC_ISER_RST   	(0x00000000ul)       /**< Enable reset value    */
#define NVIC_ICER_RST   	(0x00000000ul)       /**< Disable reset value   */
#define NVIC_ISPR_RST   	(0x00000000ul)       /**< Set reset value       */
#define NVIC_ICPR_RST		(0x00000000ul)       /**< Clear reset value     */
#define NVIC_IPR_RST    	(0x00000000ul)       /**< Priority reset value  */
/******************************************************************************
*************************** SCB Registers mask ****************************
******************************************************************************/
#define SCB_CPUID_MASK       (0xFFFFFFFFul)    /**< CPU ID mask              */
#define SCB_ICSR_MASK        (0x9EFFF9FFul)    /**< ICSR mask                */
#define SCB_VTOR_MASK        (0x3FFFFF80ul)    /**< VTOR mask                */
#define SCB_AIRCR_MASK       (0xFFFF8707ul)    /**< AIRCR mask               */
#define SCB_SCR_MASK         (0x00000016ul)    /**< SCR mask                 */
#define SCB_CCR_MASK         (0x0000031Bul)    /**< CCR mask                 */
#define SCB_SHPR_MASK        (0xFFFFFFFFul)    /**< SHPR mask                */
#define SCB_SHCSR_MASK       (0x0007FD8Bul)    /**< SHCSR mask               */
#define SCB_DFSR_MASK        (0x030F9F9Bul)    /**< DFSR mask                */
/******************************************************************************
************************* SCB Registers reset value ***************************
******************************************************************************/
#define SCB_CPUID_RST        (0x412FC230ul)       /**< CPUID reset value     */
#define SCB_ICSR_RST         (0x00000000ul)       /**< ICSR reset value      */
#define SCB_VTOR_RST         (0x00000000ul)       /**< VTOR reset value      */
#define SCB_AIRCR_RST        (0x00000000ul)       /**< AIRCR reset value     */
#define SCB_SCR_RST          (0x00000000ul)       /**< SCR reset value       */
#define SCB_CCR_RST          (0x00000000ul)       /**< CCR reset value       */
#define SCB_SHPR_RST         (0x00000000ul)       /**< SHPR reset value      */
#define SCB_SHCSR_RST        (0x00000000ul)       /**< SHCSR reset value     */
#define SCB_DFSR_RST         (0x00000000ul)       /**< DFSR reset value      */
/******************************************************************************
****************** Clock Manager External Functions Declaration ***************
******************************************************************************/
extern void CSP_NVICInit(void);
extern void CSP_SCBInit(void);
extern void CSP_NVICPriorityGroupConfig(U32_T NVIC_PriorityGroup);
extern void CSP_NVICStructInit(NVIC_TypeDef* NVICInitStruct);
extern void CSP_NVICConfigInterrupt(NVIC_TypeDef* NVICInitStruct);
extern ITStatus CSP_NVICGetIntrruptChannelPendingBitStatus(U8_T intNum_u8);
extern void CSP_NVICSetInterruptChannelPendingBit(U8_T intNum_u8);
extern U16_T CSP_NVICGetCurrentPendingInterruptChannel(void);
extern void CSP_NVICClearInterruptChannelPendingBit(U8_T intNum_u8);
extern U16_T CSP_NVICGetCurrentActiveHandler(void);
extern ITStatus CSP_NVICGetIntrruptChannelActiveBitStatus(U8_T intNum_u8);
extern void CSP_NVICSetVectorTable(U32_T vecTab, U32_T offset);
extern void CSP_NVICGenerateSystemReset(void);
extern void CSP_NVICGenerateCoreReset(void);
extern void CSP_NVICLowPowerConfig(U32_T powerMode, B_T newState);
extern void CSP_NVICSystemHandlerConfig(U32_T systemHandler, B_T newState);
extern void CSP_NVICSystemHandlerPriorityConfig(U32_T systemHandler, U8_T prePrio_u8,
        U8_T subPrio_u8);
extern ITStatus CSP_NVICGetSystemHandlerPendingBitStatus(U32_T SystemHandler);
extern void CSP_NVICSetSystemHandlerPendingBit(U32_T SystemHandler);
extern void CSP_NVICClearSystemHandlerPendingBit(U32_T SystemHandler);
extern ITStatus CSP_NVICGetSystemHandlerActiveBitStatus(U32_T SystemHandler);
extern U32_T CSP_NVICGetFaultHandlerSources(U32_T SystemHandler);
extern U32_T CSP_NVICGetFaultAddress(U32_T SystemHandler);
extern void CSP_NVICSetSystemCtrlReg(U32_T configuration);
extern void CSP_NVICClrSystemCtrlReg(U32_T configuration);
extern void CSP_NVICSetConfigCtrlReg(U32_T configuration);
extern void CSP_NVICClrConfigCtrlReg(U32_T configuration);
extern void CSP_NVICSetAppIntRstCtrlReg(U32_T configuration);
extern void CSP_NVICClrAppIntRstCtrlReg(U32_T configuration);

#endif /* CSP_NVIC_H */
