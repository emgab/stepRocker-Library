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
* @file name	csp_stt.h
* @description Definitions, Macros and function declarations for STT
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.21.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_STT_H
#define CSP_STT_H

/******************************************************************************
************************* STT Structure Definition ****************************
******************************************************************************/

/******************************************************************************
@brief STT Structure
******************************************************************************/
 typedef struct
 {
	CSP_REGISTER_T	IDR;		/**< ID Register	   				        */
	CSP_REGISTER_T  CEDR;       /**< Clock Enable/Disable Register  		*/
	CSP_REGISTER_T  SRR;        /**< Software Reset Register        		*/
    CSP_REGISTER_T  CR;			/**< Control Register                   	*/
    CSP_REGISTER_T  MR;         /**< Mode Register                      	*/
	CSP_REGISTER_T  IMSCR;      /**< Interrupt Mask Set/Clear Register      */
	CSP_REGISTER_T  RISR;       /**< Raw Interrupt Status Register         	*/
	CSP_REGISTER_T  MISR;       /**< Masked Interrupt Status Register       */
	CSP_REGISTER_T  ICR;        /**< Interrupt Clear Register               */
	CSP_REGISTER_T  SR;         /**< Status Register                    	*/
    CSP_REGISTER_T  CNTR;       /**< Counter Register                   	*/
    CSP_REGISTER_T  ALR;        /**< Alarm Register                     	*/
 } CSP_STT_T, *CSP_STT_PTR;

/******************************************************************************
************************** STT Registers Definition ***************************
******************************************************************************/
/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define STT_IPIDCODE_MASK  	(0x03FFFFFFul << 0)    /**< STT IPIDCODE mask    */
#define STT_IPIDCODE  	   	(0x03FFFFFFul << 0)    /**< STT IPIDCODE mask    */

/** Get IDR register                                                         */
#define CSP_STT_GET_IDR(stt)        ((stt)->IDR)
/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define STT_CLKEN          (0x01ul << 0)         /**< STT Clock              */
#define STT_DBGEN          (0x01ul << 31)        /**< Debug Mode Enable      */

/** Set CEDR register 		                                                 */
#define CSP_STT_SET_CEDR(stt, val)    ((stt)->CEDR = (val))
/** Get CEDR register                                              			 */
#define CSP_STT_GET_CEDR(stt)        ((stt)->CEDR)
/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define STT_SWRST          (0x01ul << 0)         /**< Software Reset         */

/** Set SRR register 		                                            	 */
#define CSP_STT_SET_SRR(stt, val)    ((stt)->SRR = (val))

/******************************************************************************
* CR : Control Register
******************************************************************************/
#define STT_CNTEN        (0x01ul << 1)  /**< Counter Enable                 */
#define STT_CNTDIS       (0x01ul << 2)  /**< Counter Disable                */
#define STT_ALARMEN      (0x01ul << 3)  /**< Alarm Enable                   */
#define STT_ALARMDIS     (0x01ul << 4)  /**< Alarm Disable                  */

/** CR : STT Control Register                                               */
#define CSP_STT_SET_CR(stt, val)         ((stt)->CR = (val))
/******************************************************************************
* MR : Mode Register
******************************************************************************/
#define STT_CNTRST       (0x01ul << 0)  /**< Counter Reset Mask             */
#define STT_CNTRST_A8B   (0x00ul << 0)  /**< Counter Reset after 0xA8BFFFFF */
#define STT_CNTRST_FFF   (0x01ul << 0)  /**< Counter Reset after 0xFFFFFFFF */

/* MR : STT Mode Register                                                    */
/** Get MR register (Mode Register)                                          */
#define CSP_STT_GET_MR(stt)              ((stt)->MR)
/** Set MR register (Mode Register)                                          */
#define CSP_STT_SET_MR(stt, mode)        ((stt)->MR = (mode))
/******************************************************************************
* SR : Status Register
******************************************************************************/
#define STT_WSEC         (0x01ul << 5)  /**< Write Counter                  */
#define STT_CNTENS       (0x01ul << 8)  /**< Counter Enable Status          */
#define STT_ALARMENS     (0x01ul << 9)  /**< Alarm Enable Status            */

/** Get SR register (Status Register)                                        */
#define CSP_STT_GET_SR(stt)              ((stt)->SR)

/******************************************************************************
* IMSCR: Interrupt Mask Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Interrupt Status Register
* ICR  : Interrupt Clear Register
******************************************************************************/
/* Share the same bits in CR register
#define STT_CNTEN        (0x01ul << 1)
#define STT_CNTDIS       (0x01ul << 2)
#define STT_ALARMEN      (0x01ul << 3)
#define STT_ALARMDIS     (0x01ul << 4)
*/

#define STT_ALARM        (0x01ul << 0)  /**< Alarm Interrupt                */

/** Set IMSCR register                                                      */
#define CSP_STT_SET_IMSCR(stt, val)    ((stt)->IMSCR = (val))
/** Get IMSCR register                                                      */
#define CSP_STT_GET_IMSCR(stt)          ((stt)->IMSCR)

/** Get RISR register (Status)                                              */
#define CSP_STT_GET_RISR(stt)          ((stt)->RISR)

/** Get MISR register (Status)                                              */
#define CSP_STT_GET_MISR(stt)          ((stt)->MISR)

/** Set ICR register                                                        */
#define CSP_STT_SET_ICR(stt, val)     ((stt)->ICR = (val))

/******************************************************************************
* CNTR : STT Count Register
******************************************************************************/
/* CNTR : STT Counter Register                                               */
#define CSP_STT_GET_CNTR(stt)            ((stt)->CNTR)
#define CSP_STT_SET_CNTR(stt, count)     ((stt)->CNTR = (count))

/******************************************************************************
* ALR : Alarm Register
******************************************************************************/
/* ALR : STT Alarm Register                                                  */
#define CSP_STT_GET_ALR(stt)             ((stt)->ALR)
#define CSP_STT_SET_ALR(stt, val)        ((stt)->ALR = (val))

/******************************************************************************
***************************** STT Registers mask ******************************
******************************************************************************/
#define STT_IDR_MASK	(0x03FFFFFFul)  /**< ECR mask                  */
#define STT_CEDR_MASK   (0x80000001ul)  /**< DCR mask                  */
#define STT_SRR_MASK    (0x00000001ul)  /**< PMSR mask                 */
#define STT_CR_MASK     (0x0000001Eul)  /**< CR mask                   */
#define STT_MR_MASK     (0x00000001ul)  /**< MR mask                   */
#define STT_SR_MASK     (0x00000320ul)  /**< SR mask                   */
#define STT_IMSCR_MASK  (0x0000001Ful)  /**< IMSCR mask                */
#define STT_RISR_MASK   (0x0000001Ful)  /**< RISR mask                 */
#define STT_MISR_MASK   (0x0000001Ful)  /**< MISR mask                 */
#define STT_ICR_MASK    (0x0000001Ful)  /**< ICR mask                  */
#define STT_CNTR_MASK   (0xFFFFFFFFul)  /**< CTNR mask                 */
#define STT_ALR_MASK    (0xFFFFFFFFul)  /**< ALR mask                  */

/******************************************************************************
*************************** STT Registers reset value *************************
******************************************************************************/
#define STT_IDR_RST		(0x03FFFFFFul)  /**< ECR reset value                 */
#define STT_CEDR_RST    (0x00000000ul)  /**< DCR reset value                 */
#define STT_SRR_RST    	(0x00000000ul)  /**< PMSR reset value                */
#define STT_CR_RST     	(0x00000000ul)  /**< CR reset value                  */
#define STT_MR_RST     	(0x00000000ul)  /**< MR reset value                  */
#define STT_SR_RST     	(0x00000000ul)  /**< SR reset value                  */
#define STT_IMSCR_RST  	(0x00000000ul)  /**< IMSCR reset value               */
#define STT_RISR_RST   	(0x00000000ul)  /**< RISR reset value                */
#define STT_MISR_RST   	(0x00000000ul)  /**< MISR reset value                */
#define STT_ICR_RST    	(0x00000000ul)  /**< ICR reset value                 */
#define STT_CNTR_RST   	(0x00000000ul)  /**< CTNR reset value                */
#define STT_ALR_RST    	(0x00000000ul)  /**< ALR reset value                 */

/******************************************************************************
********************** STT External Functions Declaration *********************
******************************************************************************/
extern void  CSP_STTInit(CSP_STT_T *const stt, U32_T mode_u32);
extern void  CSP_STTConfigInterrupt(CSP_STT_T *const stt,
                                    U32_T intMask_u32,
                                    FunctionalStatus newState);
extern U32_T CSP_STTGetTime (CSP_STT_T *const stt);
extern void  CSP_STTSetTime (CSP_STT_T *const stt, U32_T time_u32);
extern U32_T CSP_STTGetAlarm(CSP_STT_T *const stt);
extern void  CSP_STTSetAlarm (CSP_STT_T *const stt, U32_T alarm_u32);
extern void  CSP_STTEnable(CSP_STT_T *const stt, U8_T enableMask_u8);
extern void  CSP_STTDisable(CSP_STT_T *const stt, U8_T disableMask_u8);


#endif   /* CSP_STT_H */
