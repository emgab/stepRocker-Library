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
* @file name	csp_enc.h
* @description Definitions, Macros and function declarations for ENC
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
* |0.1 MOD 2010.04.10.   JI KIM              CR0, CR1 are changed
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef _CSP_ENC_H_
#define _CSP_ENC_H_

/**********************************************************************
***********************   ENC STRUCTURE DEFINITION   ******************
**********************************************************************/
typedef struct
{
	CSP_REGISTER_T  IDR;	/**< Encoder Control Register 0 		*/
	CSP_REGISTER_T  CEDR;	/**< Encoder Control Register 1 		*/
	CSP_REGISTER_T  SRR;	/**< Encoder Control Register 0 		*/
	CSP_REGISTER_T  CR0;	/**< Encoder Control Register 0 		*/
	CSP_REGISTER_T  CR1;	/**< Encoder Control Register 1 		*/
	CSP_REGISTER_T  SR;		/**< Encoder Status Register 			*/
	CSP_REGISTER_T  IMSCR;  /**< Interrupt Mask Set/Clear Register 	*/
	CSP_REGISTER_T  RISR;   /**< Raw Interrupt Status Register     	*/
	CSP_REGISTER_T  MISR;   /**< Masked Interrupt Status Register  	*/
	CSP_REGISTER_T  ICR;    /**< Interrupt Clear Register          	*/
	/** PCNT, PREF, SCNT, SREF is signed type 						*/
	CSP_REGISTER_T  PCR;	/**< 16bit Position Counter Register 	*/
	CSP_REGISTER_T  PRR;	/**< 16bit Position Reference Register 	*/
	CSP_REGISTER_T  SPCR;	/**< 16bit Speed Counter Register 		*/
	CSP_REGISTER_T  SPRR;	/**< 16bit Speed Reference Register     */
	CSP_REGISTER_T  PACCR;	/**< 16bit Phase A Capture Counter Reg. */
	CSP_REGISTER_T  PACDR;	/**< 16bit Phase A Capture Data Reg.	*/
	CSP_REGISTER_T  PBCCR;	/**< 16bit Phase B Capture Counter Reg.	*/
	CSP_REGISTER_T  PBCDR;	/**< 16bit Phase B Capture Data Reg.	*/
} CSP_ENC_T, *CSP_ENC_PTR;

/*****************************************************************************
*********************  ENC REGISTERS DEFINITION   ****************************
*****************************************************************************/
/*****************************************************************************
* IDR : Clock Manager ID Register
*****************************************************************************/
#define ENC_IDCODE				(0x00010011 << 0)	 /**< ID Code 		    */	  
#define CSP_ENC_GET_IDR(enc)    (enc->IDR)

/*****************************************************************************
* CEDR : Clock En/disable Register
*****************************************************************************/
#define ENC_CLKEN	   	  (0x01ul << 0) 	/**< Clock Enable      */
#define ENC_DBGEN	   	  (0x01ul << 31)	/**< Debug Enable      */

#define CSP_ENC_SET_CEDR(enc, val)     (enc->CEDR = (val))
#define CSP_ENC_GET_CEDR(enc)          (enc->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define ENC_SWRST	   	  			(0x01ul << 0) 	/**< Software Reset     */
#define CSP_ENC_SET_SRR(enc, val)  	(enc->SRR = (val))

/******************************************************************************
* CR0 : Control Register 0
******************************************************************************/
#define ENC_PCRCL	(0x01ul << 0)  		/**< Position Counter(PCR) Clear 	*/
#define ENC_SPCRCL	(0x01ul << 1)  		/**< Speed Counter(SPCR) Clear 		*/
#define ENC_ENCEN  	(0x01ul << 2)		/**< Encoder Blcok Enable Bit 		*/
#define ENC_ESELZ	(0x01ul << 3)	 	/**< Phase Z Edge Selection 		*/

/** Filter Clock Selection of Encoder */
#define ENC_ENCFILTER(val)	(((val) & 0x07ul) << 4)

/** PCNT clear enable by phase Z */									
#define ENC_PZCLEN			(0x01ul << 7)

/** Encoder Clcok Selection */
#define ENC_ENCCLKSEL(val)	(((val) & 0x07ul) << 8)
											
/** Set ENCCR0 register */
#define CSP_ENC_SET_CR0(enc, val)	((enc)->CR0 = (val))

/** Get ENCCR0 register */
#define CSP_ENC_GET_CR0(enc)	((enc)->CR0)

/******************************************************************************
* CR1 : Control Register 1
******************************************************************************/
/** Phase B(PBCCR) Counter Clear Bit */
#define ENC_PBCCRCL		(0x01ul << 0) 
#define ENC_PBEN		(0x01ul << 1)  	 /**< Phase B Enable */

/** Phase B Capture Operating Mdoe Selection */
#define ENC_ESELB(val)	(((val) & 0x03ul) << 2)	 
						
/** Phase B Prescale Bits */
#define ENC_PRESCALEB(val)	(((val) & 0x0Ful) << 4)	  															 
#define ENC_PACCRCL		(0x01ul << 8)  /** Phase A(PACCR) Counter Clear */	
#define ENC_PAEN		(0x01ul << 9)  /**< Phase A Enable */

/** Phase A Capture Operating Mdoe Selection */
#define ENC_ESELA(val)	(((val) & 0x03ul) << 10)
						
#define ENC_PRESCALEA(val)	(((val) & 0x0Ful) << 12) /**< Phase A Prescale Bits */
								
/** Set ENCCR1 register */
#define CSP_ENC_SET_CR1(enc, val)	((enc)->CR1 = (val))

/** Get ENCCR1 register */
#define CSP_ENC_GET_CR1(enc)		((enc)->CR1)

/******************************************************************************
* SR : Status Register
******************************************************************************/
#define ENC_DIRECTION	(0x01ul << 0)  /**< Direction of Motor Rotation 	*/
#define ENC_GLITCH		(0x01ul << 1)  /**< Glitch Detection of PHASE A/B/Z */
#define ENC_PBSTAT		(0x01ul << 2)  /**< Phase B status bit 				*/
#define ENC_PASTAT		(0x01ul << 3)  /**< Phase A status bit 				*/
#define ENC_OFPCNT		(0x01ul << 4)  /**< Overflow of PCNT 				*/
#define ENC_UFPCNT		(0x01ul << 5)  /**< Underflow of PCNT 				*/
#define ENC_OFSCNT		(0x01ul << 6)  /**< Overflow of SCNT 				*/
#define ENC_UFSCNT		(0x01ul << 7)  /**< Underflow of SCNT 				*/

/** Set SR register */
#define CSP_ENC_SET_SR(enc, val)	((enc)->SR = (val))

/** Get SR register */
#define CSP_ENC_GET_SR(enc)		((enc)->SR)

/******************************************************************************
* IMSCR, RISR, MISR, ICR: Interrupt Register
******************************************************************************/
/** Set IMSCR register                                                       */
#define CSP_ENC_SET_IMSCR(enc, val)       (enc->IMSCR = (val))

/** Get IMSCR register                                                       */
#define CSP_ENC_GET_IMSCR(enc)            (enc->IMSCR)

/** Get RISR register                                                        */
#define CSP_ENC_GET_RISR(enc)            (enc->RISR)

/** Get MISR register                                                        */
#define CSP_ENC_GET_MISR(enc)            (enc->MISR)

/** Set ICR register                                                         */
#define CSP_ENC_SET_ICR(enc, val)            (enc->ICR = (val))

/******************************************************************************
* PCR : 16bit Position Counter Register
******************************************************************************/
#define ENC_PCV(val)			(((val) & 0x0FFFF) << 0)	/**< Count value */

/** Set PCR register */
#define CSP_ENC_SET_PCR(enc, val)			((enc)->PCR = (val))

/** Get PCR register */
#define CSP_ENC_GET_PCR(enc)				((enc)->PCR)

/******************************************************************************
* PRR : 16bit Position Reference Register
******************************************************************************/
#define ENC_PREFDAT(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set PRR register */
#define CSP_ENC_SET_PRR(enc, val)			((enc)->PRR = (val))

/** Get PREF register */
#define CSP_ENC_GET_PRR(enc)				((enc)->PRR)

/******************************************************************************
* SPCR : 16bit Speed Counter Register
******************************************************************************/
#define ENC_SCV(val)			(((val) & 0x0FFFF) << 0)	/**< Count value */

/** Set SPCR register */
#define CSP_ENC_SET_SPCR(enc, val)			((enc)->SPCR = (val))

/** Get SPCR register */
#define CSP_ENC_GET_SPCR(enc)				((enc)->SPCR)

/******************************************************************************
* SPRR : 16bit Speed Reference Register
******************************************************************************/
#define ENC_SREFDAT(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set SPRR register */
#define CSP_ENC_SET_SPRR(enc, val)			((enc)->SPRR = (val))

/** Get SPRR register */
#define CSP_ENC_GET_SPRR(enc)				((enc)->SPRR)

/******************************************************************************
* PACCR : 16bit Phase A Counter Register
******************************************************************************/
#define ENC_PACCV(val)		(((val) & 0x0FFFF) << 0)	/**< Count value */

/** Set PACCR register */
#define CSP_ENC_SET_PACCR(enc, val)			((enc)->PACCR = (val))

/** Get PACCR register */
#define CSP_ENC_GET_PACCR(enc)				((enc)->PACCR)

/******************************************************************************
* PACDR : 16bit Phase A Capture Data Register
******************************************************************************/
#define ENC_PACDAT(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set PACDR register */
#define CSP_ENC_SET_PACDR(enc, val)			((enc)->PACDR = (val))

/** Get PACAP register */
#define CSP_ENC_GET_PACDR(enc)				((enc)->PACDR)

/******************************************************************************
* PBCCR : 16bit Phase B Counter Register
******************************************************************************/
#define ENC_PBCCV(val)		(((val) & 0x0FFFF) << 0)	/**< Count value */

/** Set PBCCR register */
#define CSP_ENC_SET_PBCCR(enc, val)			((enc)->PBCCR = (val))

/** Get PBCNT register */
#define CSP_ENC_GET_PBCCR(enc)				((enc)->PBCCR)

/******************************************************************************
* PBCDR : 16bit Phase B Capture Data Register
******************************************************************************/
#define ENC_PBCDAT(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set PBCDR register */
#define CSP_ENC_SET_PBCDR(enc, val)			((enc)->PBCDR = (val))

/** Get PBCDR register */
#define CSP_ENC_GET_PBCDR(enc)				((enc)->PBCDR)

/******************************************************************************
**************************** ENC REGISTER MASK  *******************************
******************************************************************************/
#define ENC_IDR_MASK		(0x03FFFFFFul)    	/**< IDR mask 	*/
#define ENC_CEDR_MASK		(0x80000001ul)    	/**< CEDR mask 	*/
#define ENC_SRR_MASK		(0x00000001ul)    	/**< SRR mask 	*/
#define ENC_CR0_MASK		(0x000007FFul)    	/**< CR0 mask 	*/
#define ENC_CR1_MASK		(0x0000FFFFul)    	/**< CR1 mask 	*/
#define ENC_SR_MASK			(0x000000FFul)    	/**< SR mask 	*/
#define ENC_IMSCR_MASK		(0x000000BFul)    	/**< SR mask 	*/
#define ENC_RISR_MASK		(0x000000BFul)    	/**< SR mask 	*/
#define ENC_MISR_MASK		(0x000000BFul)    	/**< SR mask 	*/
#define ENC_ICR_MASK		(0x000000BFul)    	/**< SR mask 	*/
#define ENC_PCR_MASK		(0x0000FFFFul)    	/**< PCR  mask */
#define ENC_PRR_MASK		(0x0000FFFFul)    	/**< PREF mask */
#define ENC_SPCR_MASK		(0x0000FFFFul)    	/**< SCNT mask */
#define ENC_SPRR_MASK		(0x0000FFFFul)    	/**< SREF mask */
#define ENC_PACCR_MASK		(0x0000FFFFul)    	/**< PACNT mask */
#define ENC_PACDR_MASK		(0x0000FFFFul)    	/**< PACAP mask */
#define ENC_PBCCR_MASK		(0x0000FFFFul)    	/**< PBCNT mask */
#define ENC_PBCDR_MASK		(0x0000FFFFul)    	/**< PBCAP mask */

/******************************************************************************
************************** ENC REGISTER RESET VALUE  **************************
******************************************************************************/
#define ENC_IDR_RST			(0x00010011ul)    	/**< IDR reset value */
#define ENC_CEDR_RST		(0x00000000ul)    	/**< CEDR reset value */
#define ENC_SRR_RST			(0x00000000ul)    	/**< SRR reset value */
#define ENC_CR0_RST			(0x00000000ul)    	/**< CR0 reset value */
#define ENC_CR1_RST			(0x00000000ul)    	/**< CR1 reset value */
#define ENC_SR_RST			(0x00000000ul)    	/**< SR reset value */
#define ENC_IMSCR_RST		(0x00000000ul)    	/**< SR reset value */
#define ENC_RISR_RST		(0x00000000ul)    	/**< SR reset value */
#define ENC_MISR_RST		(0x00000000ul)    	/**< SR reset value */
#define ENC_ICR_RST			(0x00000000ul)    	/**< SR reset value */
#define ENC_PCR_RST			(0x00000000ul)    	/**< PCR  reset value */
#define ENC_PRR_RST			(0x00000000ul)    	/**< PREF reset value */
#define ENC_SPCR_RST		(0x00000000ul)    	/**< SCNT reset value */
#define ENC_SPRR_RST		(0x00000000ul)    	/**< SREF reset value */
#define ENC_PACCR_RST		(0x00000000ul)    	/**< PACNT reset value */
#define ENC_PACDR_RST		(0x00000000ul)    	/**< PACAP reset value */
#define ENC_PBCCR_RST		(0x00000000ul)    	/**< PBCNT reset value */
#define ENC_PBCDR_RST		(0x00000000ul)    	/**< PBCAP reset value */

/******************************************************************************
******************* ENC External Functions Declaration ************************
******************************************************************************/
extern void CSP_ENCPinConfiguration(CSP_ENC_T *const enc);
extern void CSP_ENCEnable(CSP_ENC_T *const enc, U8_T encclksel, U8_T fileterclk);
extern void CSP_ENCDisable(CSP_ENC_T *const enc);
extern void CSP_ENCEnablePA(CSP_ENC_T *const enc);
extern void CSP_ENCDisablePA(CSP_ENC_T *const enc);
extern void CSP_ENCEnablePB(CSP_ENC_T *const enc);
extern void CSP_ENCDisablePB(CSP_ENC_T *const enc);
extern void CSP_ENCClearPCounter(CSP_ENC_T *const enc);
extern void CSP_ENCClearSCounter(CSP_ENC_T *const enc);
extern void CSP_ENCClearPACounter(CSP_ENC_T *const enc);
extern void CSP_ENCClearPBCounter(CSP_ENC_T *const enc);

#endif /* _CSP_ENC_H_ */
