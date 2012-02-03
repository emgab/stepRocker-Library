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
* @file name	csp_frt.h
* @description Definitions, Macros and function declarations for FRT
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_FRT_H
#define CSP_FRT_H

/******************************************************************************
************************ FRT Structure Definition *****************************
******************************************************************************/

/******************************************************************************
@brief FRT Structure
******************************************************************************/
typedef struct
{
	CSP_REGISTER_T     	IDR;		    /**< ID Register	              	  */
	CSP_REGISTER_T     	CEDR;        	/**< Clock Enable/Disable Register    */
	CSP_REGISTER_T     	SRR;         	/**< Software Reset Register          */
	CSP_REGISTER_T      CR;             /**< Control Register                 */
	CSP_REGISTER_T      SR;             /**< Status Register                  */
	CSP_REGISTER_T     	IMSCR;       	/**< Interrupt Mask Set/Clear Register*/
	CSP_REGISTER_T     	RISR;        	/**< Raw Interrupt Status Register    */
	CSP_REGISTER_T     	MISR;        	/**< Masked Interrupt Status Register */
	CSP_REGISTER_T    	ICR;        	/**< Interrupt Clear Register         */
	CSP_REGISTER_T      DR;             /**< Data Register        		      */
	CSP_REGISTER_T      DBR;			/**< Data Buffer Register     	      */
	CSP_REGISTER_T      CVR;            /**< Counter Value Register           */
} CSP_FRT_T, *CSP_FRT_PTR;

typedef struct
{
	U16_T ClockDivider;
	U32_T FRT_Frequency;
	U8_T Size;
	U32_T Data;
	FunctionalStatus FRT_Cmd;
} sFRT_TypeDef;

/******************************************************************************
************************* FRT Registers Definition ****************************
******************************************************************************/
/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define FRT_IPIDCODE_MASK  (0x03FFFFFFul << 0)    	/**<  IPIDCODE mask     */
#define FRT_IPIDCODE  	   (0x0001001F << 0)    	/**<  IPIDCODE value    */

/** Set IDR register 		                                             	*/
#define CSP_FRT_SET_IDR(frt, val)    ((frt)->IDR = (val))

/** Get IDR register                                                        */
#define CSP_FRT_GET_IDR(frt)        ((frt)->IDR)

/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define FRT_CLKEN          (0x01ul << 0)         /**< IP Clock            	*/
#define FRT_DBGEN          (0x01ul << 31)        /**< Debug Mode Enable     */

/** Set CEDR register 		                                                */
#define CSP_FRT_SET_CEDR(frt, val)    ((frt)->CEDR = (val))

/** Get CEDR register                                               */
#define CSP_FRT_GET_CEDR(frt)        ((frt)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define FRT_SWRST          (0x01ul << 0)         /**< Software Reset         */

/** Set SRR register 		                                             */
#define CSP_FRT_SET_SRR(frt, val)    ((frt)->SRR = (val))

/******************************************************************************
* CR : Control Register
******************************************************************************/
#define FRT_START     		(0x01ul << 0)	 /**< FRT Timer Start(enable)    */
#define FRT_FRTSIZE(val)	(((val) & 0x1Ful) << 8)  /**< Writing Macro      */
#define FRT_CDIV(val)  		(((val) & 0xFFFFul) << 16)  /**< Writing Macro   */

/** Set CR register                                                          */
#define CSP_FRT_SET_CR(frt, val)     ((frt)->CR = (val))

/** Get CR register                                               	     	 */
#define CSP_FRT_GET_CR(frt)        ((frt)->CR)

/******************************************************************************
* SR : Status Register
******************************************************************************/
#define FRT_SWRST     (0x01ul << 0)	 /**< FRT SWRST Status */

/** Get SR register                                               	     */
#define CSP_FRT_GET_SR(frt)        ((frt)->SR)
/******************************************************************************
 * IMSCR : Interrupt MASK Set/Clear Register
 * RISR : Raw Interrupt Status Register
 * MISR : Interrupt Status Register
 * ICR : Interrupt Clear Register
 ******************************************************************************/
#define FRT_OVF		(0x01ul << 0)      /**< Overflow Interrupt     */
#define FRT_MATCH   (0x01ul << 2)      /**< Match Interrupt            */

/** Set IMSCR register                                                      */
#define CSP_FRT_SET_IMSCR(frt, val)    ((frt)->IMSCR = (val))
/** Get IMSCR register                                                      */
#define CSP_FRT_GET_IMSCR(frt)          ((frt)->IMSCR)

/** Set RISR register                                                       */
#define CSP_FRT_SET_RISR(frt, val)    ((frt)->RISR = (val))
/** Get RISR register (Status)                                              */
#define CSP_FRT_GET_RISR(frt)          ((frt)->RISR)

/** Set MISR register                                                       */
#define CSP_FRT_SET_MISR(frt, val)    ((frt)->MISR = (val))
/** Get MISR register (Status)                                              */
#define CSP_FRT_GET_MISR(frt)          ((frt)->MISR)

/** Set ICR register                                                       */
#define CSP_FRT_SET_ICR(frt, val)     ((frt)->ICR = (val))
/** Get ICR register (Status)                                              */
#define CSP_FRT_GET_ICR(frt)          ((frt)->ICR)

/******************************************************************************
 * DR : Data Register
 ******************************************************************************/
#define FRT_DATA_MASK	 (0xFFFFFFFFul << 0)  /**< FRT data buffer Mask     */
#define FRT_DATA(val)  (((val) & 0xFFFFFFFFul) << 0)  /**< Writing Macro      */

/** Set DR register                                                          */
#define CSP_FRT_SET_DR(frt, val)     ((frt)->DR = (val))
/** Get SR register                                               	     */
#define CSP_FRT_GET_DR(frt)        ((frt)->DR)

/******************************************************************************
 * DBR : Data Buffer Register
 ******************************************************************************/
//#define FRT_DATA_MASK	 (0xFFFFFFFFul << 0)  /**< FRT data buffer Mask     */

/** Get SR register                                               	     */
#define CSP_FRT_GET_DBR(frt)        ((frt)->DBR)
/******************************************************************************
 * CVR : Counter Value Register
 ******************************************************************************/
#define FRT_COUNT(val)  (((val) & 0xFFFFFFFFul) << 0)  /**< Writing Macro      */

/** Set CVR register                                                          */
#define CSP_FRT_SET_CVR(frt, val)     ((frt)->CVR = (val))
/** Get SR register                                               	     */
#define CSP_FRT_GET_CVR(frt)        ((frt)->CVR)


/******************************************************************************
 ***************************** FRT Registers mask *****************************
 ******************************************************************************/
#define FRT_IDR_MASK           (0x03FFFFFFul)    /**< IDR mask         */
#define FRT_CEDR_MASK	       (0x80000001ul)    /**< CEDR mask       */
#define FRT_SRR_MASK           (0x00000001ul)    /**< SRR mask         */
#define FRT_CR_MASK            (0xFFFF1F01ul)    /**< CR mask          */
#define FRT_SR_MASK            (0xFFFF1F07ul)    /**< SR mask          */
#define FRT_IMSCR_MASK         (0x00000003ul)    /**< IMSCR mask       */
#define FRT_RISR_MASK          (0x00000003ul)    /**< RISR mask        */
#define FRT_MISR_MASK          (0x00000003ul)    /**< MIS Rmask        */
#define FRT_ICR_MASK           (0x00000003ul)    /**< ICR mask         */
#define FRT_DR_MASK            (0xFFFFFFFFul)    /**< DR mask          */
#define FRT_DBR_MASK           (0xFFFFFFFFul)    /**< DR mask          */
#define FRT_CVR_MASK           (0xFFFFFFFFul)    /**< CVR mask         */ 
/******************************************************************************
 ***************************** FRT Registers Reset Value ***********************
 ******************************************************************************/
#define FRT_IDR_RST           (0x00010018ul)    /**< IDR reset value         */
#define FRT_CEDR_RST	      (0x00000001ul)    /**< CEDR reset value        */
#define FRT_SRR_RST           (0x00000000ul)    /**< SRR reset value         */
#define FRT_CR_RST            (0x00001F01ul)    /**< CR reset value          */
#define FRT_SR_RST            (0x00000000ul)    /**< SR reset value          */
#define FRT_IMSCR_RST         (0x00000001ul)    /**< IMSCR reset value       */
#define FRT_RISR_RST          (0x00000000ul)    /**< RISR reset value        */
#define FRT_MISR_RST          (0x00000000ul)    /**< MIS Rreset value        */
#define FRT_ICR_RST           (0x00000000ul)    /**< ICR reset value         */
#define FRT_DR_RST            (0x00000000ul)    /**< DR reset value          */
#define FRT_DBR_RST           (0x00000000ul)    /**< DBR reset value         */
#define FRT_CVR_RST           (0x00000000ul)    /**< CVR reset value         */		 
/******************************************************************************
 ********************** FRT External Functions Declaration **********************
 ******************************************************************************/
extern void CSP_FRTInit(CSP_FRT_T *frt);
extern void CSP_FRTClose(CSP_FRT_T *frt);
extern void CSP_FRTConfigure(CSP_FRT_T *const frt,
		U16_T cdiv_u16, U8_T frtsize_u8, U32_T data_u32);
extern void CSP_FRTConfigInterrupt(CSP_FRT_T *frt,
		U32_T intMask_u32,
		FunctionalStatus newState);
extern void CSP_FRTEnable(CSP_FRT_T *frt);
extern void CSP_FRTDisable(CSP_FRT_T *frt);
extern FlagStatus CSP_FRTGetFlagStatus(CSP_FRT_T *const frt, U32_T Flag);
extern FlagStatus CSP_FRTGetRawITStatus(CSP_FRT_T *const frt, U32_T Flag);
extern FlagStatus CSP_FRTGetMaskedITStatus(CSP_FRT_T *const frt, U32_T Flag);
extern void CSP_FRTClearITFlag(CSP_FRT_T *const frt, U32_T Flag);
extern void CSP_FRTStructInit(sFRT_TypeDef* FRTInitStruct);
extern void CSP_FRTConfigInit(CSP_FRT_T *const frt, sFRT_TypeDef* FRTInitStruct,
		U32_T pclk_freq_u32);

#endif   /* CSP_FRT_H */
