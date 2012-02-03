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
* @file name	csp_wdt.h
* @description Definitions, Macros and function declarations for WDT
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_WDT_H
#define CSP_WDT_H

/******************************************************************************
************************** WD Structure Definition ****************************
******************************************************************************/
/**
*******************************************************************************
@brief WD Structure
*******************************************************************************
*/
typedef struct
{
   CSP_REGISTER_T  IDR;             /**< ID Register	                     */
   CSP_REGISTER_T  CR;              /**< Control Register                   */
   CSP_REGISTER_T  MR;              /**< Mode Register                      */
   CSP_REGISTER_T  OMR;             /**< Overflow Mode Register             */
   CSP_REGISTER_T  SR;              /**< Status Register                    */
   CSP_REGISTER_T  IMSCR;           /**< Interrupt Set/Clear Register       */
   CSP_REGISTER_T  RISR;            /**< Raw Interrupt Status Register      */
   CSP_REGISTER_T  MISR;            /**< Masked Interrupt Status Register   */
   CSP_REGISTER_T  ICR;             /**< Clear Status Register              */
   CSP_REGISTER_T  PWR;             /**< Pending Window Register            */
   CSP_REGISTER_T  CTR;             /**< Counter Test Register              */
} CSP_WDT_T, *CSP_WDT_PTR;


/******************************************************************************
************************** WDT Registers Definition ****************************
******************************************************************************/

/******************************************************************************
* IDR: ID RegisterRegisters
******************************************************************************/
#define WDT_IPIDCODE     (0x00010000ul )       /**< WDT version number       */

/******************************************************************************
* CR : WDT Control Register
******************************************************************************/
#define WDT_RSTKEY_MASK  (0xFFFFul << 0)   /**< Restart key mask             */
#define WDT_RSTKEY       (0xC071ul << 0)   /**< Restart key                  */
#define WDT_DBGEN        (0x01ul << 31)    /**< Debug Mode Enable            */

/******************************************************************************
* MR : WDT Mode Register
******************************************************************************/
/* WDTPDIV : Clock Divider                                                    */
#define WDT_WDTPDIV_MASK    (0x07ul << 0)   /**< WDTPDIV Mask                  */
#define WDT_WDTPDIV(val)    ((0x07ul & val) << 0) /**< Writing macro          */
#define WDT_WDTPDIVCLK_2    (0x00ul)        /**< WDTPDIVCLK / 2                */
#define WDT_WDTPDIVCLK_4    (0x01ul)        /**< WDTPDIVCLK / 4                */
#define WDT_WDTPDIVCLK_8    (0x02ul)        /**< WDTPDIVCLK / 8                */
#define WDT_WDTPDIVCLK_16   (0x03ul)        /**< WDTPDIVCLK / 16               */
#define WDT_WDTPDIVCLK_32   (0x04ul)        /**< WDTPDIVCLK / 32               */
#define WDT_WDTPDIVCLK_128  (0x05ul)        /**< WDTPDIVCLK / 128              */
#define WDT_WDTPDIVCLK_256  (0x06ul)        /**< WDTPDIVCLK / 256              */
#define WDT_WDTPDIVCLK_512  (0x07ul)         /**< WDTPDIVCLK / 512              */

/* PCV : High Preload Counter Value                                          */
#define WDT_PCV_MASK       (0xFFFFul << 8) /**< Mask                         */
#define WDT_PCV(val)       (((val) & 0xFFFFul) << 8)  /**< Writing Macro     */

/* CKEY : Clock access Key                                                   */
#define WDT_CKEY_MASK      (0xFFul << 24)  /**< CKEY Mask                    */
#define WDT_CKEY           (0x37ul << 24)  /**< Write Access in MR allowed   */

/******************************************************************************
* OMR : WDT Overflow Mode Register
******************************************************************************/
#define WDT_WDTEN          (0x01ul << 0)   /**< Watchdog Enable              */
#define WDT_RSTEN          (0x01ul << 1)   /**< Reset Enable                 */
#define WDT_LOCKRSTEN      (0x01ul << 2)   /**< Lockup reset enable          */

/* OKEY : Overflow access key                                                */
#define WDT_OKEY_MASK      (0xFFFul << 4)  /**< OKEY Mask                    */
#define WDT_OKEY           (0x234ul << 4)  /**< Write Access in OMR allowed  */

/******************************************************************************
* SR : WDT Status Register
******************************************************************************/
/* SR Register Only                                                          */
#define WDT_PENDING        (0x01ul << 8)   /**< WatchDog Pending Status      */
#define WDT_CLEAR_STATUS   (0x01ul << 9)   /**< Watchdog Clear Status        */

/******************************************************************************
* IMSCR : Interrupt Mask Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Masked Interrupt Status Register
: ICR : Interrupt Clear Register
******************************************************************************/
#define WDT_WDTPEND         (0x01ul << 0)   /**< Watchdog Pending             */
#define WDT_WDTOVF          (0x01ul << 1)   /**< Watchdog Overflow            */


/******************************************************************************
* PWR : WDT Pending Window Register
******************************************************************************/
#define WDT_RSTALW         (0x01ul << 0)   /**< Restart allowed              */

/* PWL : Pending Window Length                                               */
#define WDT_PWL_MASK       (0xFFFFul << 8) /**< PWL Mask                     */
#define WDT_PWL(val)       (((val) & 0xFFFFul) << 8) /**< Writing Macro      */

/* PWKEY : Clock access key                                                  */
#define WDT_PWKEY_MASK     (0xFFul << 24)  /**< PWKEY Mask                   */
#define WDT_PWKEY          (0x91ul << 24)  /**< Write Access in PWR Allowed  */


/******************************************************************************
* CTR : WDT Counter Test Register
******************************************************************************/
#define WDT_COUNT_MASK     (0xFFFFul << 0) /**< Counter Mask                 */

/******************************************************************************
****************************** WD Registers mask ******************************
******************************************************************************/
#define WDT_ID_MASK			(0x03FFFFFFul)    /**< ECR mask                 */
#define WDT_CR_MASK         (0x8000FFFFul)    /**< CR mask                  */
#define WDT_MR_MASK         (0xFFFFFF07ul)    /**< MR mask                  */
#define WDT_OMR_MASK        (0x0000FFF7ul)    /**< OMR mask                 */
#define WDT_CSR_MASK        (0x00000003ul)    /**< CSR mask                 */
#define WDT_SR_MASK         (0x00000300ul)    /**< SR mask                  */
#define WDT_IMSCR_MASK      (0x00000003ul)    /**< IER mask                 */
#define WDT_RISR_MASK       (0x00000003ul)    /**< IDR mask                 */
#define WDT_MISR_MASK       (0x00000003ul)    /**< IMR mask                 */
#define WDT_ICR_MASK	    (0x00000003ul)    /**< IMR mask                 */
#define WDT_PWR_MASK        (0xFFFFFF01ul)    /**< PWR mask                 */
#define WDT_CTR_MASK        (0x0000FFFFul)    /**< CTR mask                 */

/******************************************************************************
************************** WDT Registers reset value* **************************
******************************************************************************/
#define WDT_IDR_RST			(WDT_IPIDCODE)    /**< PMSR reset value         */
#define WDT_MR_RST          (0x00FFFF07ul)    /**< MR reset value           */
#define WDT_OMR_RST         (0x00000003ul)    /**< OMR reset value          */ 
#define WDT_SR_RST          (0x80000100ul)    /**< SR reset value           */
#define WDT_IMSCR_RST       (0x00000000ul)	  /**< IMSCR reset value        */ 
#define WDT_RISR_RST        (0x00000001ul)    /**< RISR reset value         */
#define WDT_MISR_RST        (0x00000000ul)    /**< MISR reset value         */
#define WDT_ICR_RST	      	(0x00000000ul)    /**< IMR reset value          */
#define WDT_PWR_RST         (0x00FFFF00ul)    /**< PWR reset value          */
#define WDT_CTR_RST         (0x0000FFFFul)    /**< CTR reset value          */

/******************************************************************************
**************************** WDT Macros Definition *****************************
******************************************************************************/
/* IDR : ID CODE Register 													*/
/** Get IDR register (Status)                                               */
#define CSP_WDT_GET_IDR(wd)         ((wd)->PMSR)

/* CR : WDT Control Register                                                */
/** Set CR register                                                         */
#define CSP_WDT_SET_CR(wd, val)           ((wd)->CR = val)

/* MR : WD Mode Register                                                    */
/** Get MR register                                                         */
#define CSP_WDT_GET_MR(wd)           ((wd)->MR)
/** Set MR register                                                         */
#define CSP_WDT_SET_MR(wd, mode)     ((wd)->MR = (mode | WDT_CKEY))

/* OMR : WDT Overflow Mode Register                                         */
/** Get OMR register                                                        */
#define CSP_WDT_GET_OMR(wd)          ((wd)->OMR)
/** Set OMR register                                                        */
#define CSP_WDT_SET_OMR(wd, val)     ((wd)->OMR = (val | WDT_OKEY))

/* SR : WDT Status Registers                                                */
/** Get SR register (Status)                                                */
#define CSP_WDT_GET_SR(wd)           ((wd)->SR)
																	   
/* IMSCR, RISR, MISR, ICR : WDT Interrupt Registers                         */
/** Set IMSCR register 		                                                */
#define CSP_WDT_SET_IMSCR(wd, val)     ((wd)->IMSCR = (val))

/** Get IMSCR register (Status)                                             */
#define CSP_WDT_GET_IMSCR(wd)          ((wd)->IMSCR)
																	   
/** Get RISR register (Status)                                              */
#define CSP_WDT_GET_RISR(wd)          ((wd)->RISR)

/** Get MISR register (Status)                                              */
#define CSP_WDT_GET_MISR(wd)          ((wd)->MISR)

/** Set ICR register 		                                             	*/
#define CSP_WDT_SET_ICR(wd, val)     ((wd)->ICR = (val))


/* PWR : WDT Pending Window Register                                        */
/** Get PWR register                                                        */
#define CSP_WDT_GET_PWR(wd)          ((wd)->PWR)
/** Set PWR register                                                        */
#define CSP_WDT_SET_PWR(wd, mode)    ((wd)->PWR = (mode | WDT_PWKEY))

/* CTR : WDT Counter Test Register                                          */
/** Get CTR register                                                        */
#define CSP_WDT_GET_CTR(wd)          ((wd)->CTR)


/******************************************************************************
********************** WD External Functions Declaration **********************
******************************************************************************/
extern void CSP_WDTInit(CSP_WDT_T *wd,
                       U32_T mode_u32,
                       U32_T overflowMode_u32,
                       U32_T pendingMode_u32);
extern void CSP_WDTConfigInterrupt(CSP_WDT_T *wd,
		                          U32_T intMask_u32,
		                          FunctionalStatus newState);
extern void CSP_WDTEnable(CSP_WDT_T *wd);
extern void CSP_WDTDisable(CSP_WDT_T *wd);
extern void CSP_WDTCounterRestart(CSP_WDT_T *wd);


#endif   /* CSP_WD_H */
