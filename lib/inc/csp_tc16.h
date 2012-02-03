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
* @file name	csp_tc16.h
* @description Definitions, Macros and function declarations for TC16
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.  MCU Solution Part   Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_TC16_H
#define CSP_TC16_H

/******************************************************************************
************************* TC16 Structure Definition ***************************
******************************************************************************/
/******************************************************************************
@brief TC 16 bits Structure
******************************************************************************/ 
typedef struct
{
    CSP_REGISTER_T     	IDR;			/**< ID Register	              	  */
    CSP_REGISTER_T     	CSSR;        	/**< Clock Source Selection Register  */
    CSP_REGISTER_T     	CEDR;        	/**< Clock Enable/Disable Register    */
    CSP_REGISTER_T     	SRR;         	/**< Software Reset Register          */
    CSP_REGISTER_T     	CSR;        	/**< Control Set Register             */
    CSP_REGISTER_T     	CCR;        	/**< Control Clear Register           */
    CSP_REGISTER_T      SR;             /**< Status Register                  */
    CSP_REGISTER_T     	IMSCR;       	/**< Interrupt Mask Set/Clear Register*/
    CSP_REGISTER_T     	RISR;        	/**< Raw Interrupt Status Register    */
    CSP_REGISTER_T     	MISR;        	/**< Masked Interrupt Status Register */
    CSP_REGISTER_T    	ICR;        	/**< Interrupt Clear Register         */
    CSP_REGISTER_T     	CDR;        	/**< Clock Divider Register           */
    CSP_REGISTER_T     	CSMR;        	/**< Count Size Mask Register         */
    CSP_REGISTER_T      PRDR;           /**< Period Register                  */
    CSP_REGISTER_T      PULR;           /**< Pulse Register                   */
    CSP_REGISTER_T      CCDR;           /**< Counter Value Register           */
    CSP_REGISTER_T      CCSMR;          /**< Counter Value Register           */
    CSP_REGISTER_T      CPRDR;          /**< Counter Value Register           */
    CSP_REGISTER_T      CPULR;          /**< Counter Value Register           */
    CSP_REGISTER_T      CUCR;           /**< Capture Up Count Register        */
    CSP_REGISTER_T      CDCR;           /**< Capture Down Count Register      */
    CSP_REGISTER_T      CVR;            /**< Counter Value Register           */
} CSP_TC16_T, *CSP_TC16_PTR;

/******************************************************************************
************************** tc16 Registers Definition **************************
******************************************************************************/

/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define TC16_IPIDCODE_MASK  (0x03FFFFFFul << 0)    /**<  IPIDCODE mask      */
#define TC16_IPIDCODE  	    (0x0011000Aul << 0)    /**<  IPIDCODE value     */

/** Set IDR register 		                                                */
#define CSP_TC16_SET_IDR(tc16, val)	((tc16)->IDR = (val))
/** Get IDR register                                                        */
#define CSP_TC16_GET_IDR(tc16)		((tc16)->IDR)

/******************************************************************************
* CSSR : Clock Source Selection Register
******************************************************************************/
#define TC16_CLKSRC         (0x01ul << 0)         /**< IP Clock Source      */

/** Set CSSR register 		                                                */
#define CSP_TC16_SET_CSSR(tc16, val)	((tc16)->CSSR = (val))
/** Get CSSR register                                               		*/
#define CSP_TC16_GET_CSSR(tc16)        ((tc16)->CSSR)

/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define TC16_CLKEN          (0x01ul << 0)         /**< IP Clock             */
#define TC16_DBGEN          (0x01ul << 31)        /**< Debug Mode Enable     */

/** Set CEDR register 		                                                */
#define CSP_TC16_SET_CEDR(tc16, val)    ((tc16)->CEDR = (val))
/** Get CEDR register                                               */
#define CSP_TC16_GET_CEDR(tc16)        ((tc16)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define TC16_SWRST          (0x01ul << 0)         /**< Software Reset         */

/** Set SRR register 		                                             */
#define CSP_TC16_SET_SRR(tc16, val)    ((tc16)->SRR = (val))
/** Get SRR register                                               	     */
#define CSP_TC16_GET_SRR(tc16)        ((tc16)->SRR)


/******************************************************************************
* CSR : Control Set Register
* CCR : Control Clear Register
******************************************************************************/
#define TC16_START      (0x01ul << 0)     /**< tc16 Start	                     */
#define TC16_UPDATE     (0x01ul << 1)	 /**< tc16 Configuration update       */

#define TC16_STOPHOLD   (0x01ul << 2)      /**< Idle level for 0  */
#define TC16_STOPCLEAR  (0x01ul << 3)      /**< Sample level for 0*/
#define TC16_IDLESL     (0x01ul << 8)      /**< Dual mode for 0  */
#define TC16_OUTSL   	(0x01ul << 9)      /**< Dual mode for 0  */


#define TC16_KEEP      	(0x01ul << 10)     /**< tc16 Extension 0              */
#define TC16_PWMIM	    (0x01ul << 11)     /**< tc16 Extension 1              */
#define TC16_PWMEN     	(0x01ul << 12)     /**< tc16 Extension 2              */
#define TC16_REPEAT    	(0x01ul << 13)     /**< tc16 Extension 3              */
#define TC16_OVFM       (0x01ul << 14)     /**< tc16 Extension 4              */
#define TC16_CAPTEN   	(0x01ul << 16)     /**< tc16 Extension 5              */
#define TC16_CAPT_F		(0x01ul << 17)
#define TC16_CAPT_R		(0x01ul << 18)
#define TC16_PWMEX0		(0x01ul << 24)
#define TC16_PWMEX1		(0x01ul << 25)
#define TC16_PWMEX2		(0x01ul << 26)
#define TC16_PWMEX3		(0x01ul << 27)
#define TC16_PWMEX4		(0x01ul << 28)
#define TC16_PWMEX5		(0x01ul << 29)

/* CSR : Control Register	                                             */
/** Set CSR register                                                     */
#define CSP_TC16_SET_CSR(tc16, val)     ((tc16)->CSR = (val))
/** Get CSR register                                               	     */
#define CSP_TC16_GET_CSR(tc16)        ((tc16)->CSR)

/* CCR : Control Register	                                             */
/** Set CCR register                                                     */
#define CSP_TC16_SET_CCR(tc16, val)     ((tc16)->CCR = (val))
/** Get CCR register                                               	     */
#define CSP_TC16_GET_CCR(tc16)        ((tc16)->CCR)

/******************************************************************************
* SR : Status Register
******************************************************************************/
#define TC16_CLKSRCS		(0x01ul << 31)	 /**< tc16 DBGEN                 */
#define TC16_CLKENS     	(0x01ul << 30)	 /**< tc16 Clock Enable          */
#define TC16_CSMRS			(0x01ul << 19)	 /**< tc16 DBGEN                 */
#define TC16_CAPT_RS		(0x01ul << 18)	 /**< tc16 DBGEN                 */
#define TC16_CAPT_FS		(0x01ul << 17)	 /**< tc16 DBGEN                 */
#define TC16_CAPTENS		(0x01ul << 16)	 /**< tc16 DBGEN                 */

 /** Set SR register                                                         */
#define CSP_TC16_SET_SR(tc16, val)     ((tc16)->SR = (val))
/** Get SR register                                               	     	*/
#define CSP_TC16_GET_SR(tc16)        ((tc16)->SR)

/******************************************************************************
* IMSCR : Interrupt MASK Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Interrupt Status Register
* ICR : Interrupt Clear Register
******************************************************************************/
#define TC16_STARTI     (0x01ul << 0)      /**< Overflow Interrupt     		*/
#define TC16_STOPI    	(0x01ul << 1)      /**< Stop Interrupt            	*/
#define TC16_PSTARTI    (0x01ul << 2)      /**< Period Start Interrupt     	*/
#define TC16_PENDI    	(0x01ul << 3)      /**< Period End Interrupt        */
#define TC16_MATI   	(0x01ul << 4)      /**< Match Interrupt    			*/
#define TC16_OVFI 	   	(0x01ul << 5)      /**< Overflow Interrupt          */
#define TC16_CAPTI    	(0x01ul << 6)      /**< Capture Interrupt     		*/

#define TC32_STARTI     (0x01ul << 0)      /**< Overflow Interrupt     		*/
#define TC32_STOPI    	(0x01ul << 1)      /**< Stop Interrupt            	*/
#define TC32_PSTARTI    (0x01ul << 2)      /**< Period Start Interrupt     	*/
#define TC32_PENDI    	(0x01ul << 3)      /**< Period End Interrupt        */
#define TC32_MATI   	(0x01ul << 4)      /**< Match Interrupt     		*/
#define TC32_OVFI 	   	(0x01ul << 5)      /**< Overflow Interrupt          */
#define TC32_CAPTI    	(0x01ul << 6)      /**< Capture Interrupt     		*/

/** Set IMSCR register                                                      */
#define CSP_TC16_SET_IMSCR(tc16, val)    ((tc16)->IMSCR = (val))
/** Get IMSCR register                                                      */
#define CSP_TC16_GET_IMSCR(tc16)          ((tc16)->IMSCR)

/** Set RISR register                                                       */
#define CSP_TC16_SET_RISR(tc16, val)    ((tc16)->RISR = (val))
/** Get RISR register (Status)                                              */
#define CSP_TC16_GET_RISR(tc16)          ((tc16)->RISR)

/** Set MISR register                                                       */
#define CSP_TC16_SET_MISR(tc16, val)    ((tc16)->MISR = (val))
/** Get MISR register (Status)                                              */
#define CSP_TC16_GET_MISR(tc16)          ((tc16)->MISR)

/** Set ICR register                                                        */
#define CSP_TC16_SET_ICR(tc16, val)     ((tc16)->ICR = (val))
/** Get ICR register (Status)                                               */
#define CSP_TC16_GET_ICR(tc16)          ((tc16)->ICR)

/* Cortex-M0 Interrupt Set, Clear, Pending Registers 						*/
#define NVIC_TC16_1				(0x01ul << 2)				/** TC6 NVIC	*/
#define CPU_NVIC_SETEN(vec)		(*SETENA0 = (vec))
#define CPU_NVIC_CLREN(vec)		(*CLRENA0 = (vec))
#define CPU_NVIC_SETPE(vec)		(*SETPEND0 = (vec))
#define CPU_NVIC_CLRPE(vec)		(*CLRPEND0 = (vec))	 
  
/******************************************************************************
* CDR : Clock Divider Register
******************************************************************************/
#define CSP_TC16_SET_CDR(tc16, val)	((tc16)->CDR = (val))
#define CSP_TC16_GET_CDR(tc16)		((tc16)->CDR)

/******************************************************************************
* CSMR : Counter Size Mask Register
******************************************************************************/
#define CSP_TC16_SET_CSMR(tc16, val)	((tc16)->CSMR = (val))
#define CSP_TC16_GET_CSMR(tc16)			((tc16)->CSMR)

#define TC_CNTSIZE16		16	 /* 16-bit counter */
#define TC_MAXVALUE16		(1<<TC_CNTSIZE16)

#define TC_MAXCNT(x)			(1<<(x))
#define TC_CNTSIZE(x)			(((x) - 1)<<0)

/******************************************************************************
* PRDR : Counter Size Mask Register
******************************************************************************/
#define CSP_TC16_SET_PRDR(tc16, val)	((tc16)->PRDR = (val))
#define CSP_TC16_GET_PRDR(tc16)			((tc16)->PRDR)

/******************************************************************************
* PULR : Pulse Register
******************************************************************************/
#define CSP_TC16_SET_PULR(tc16, val)		((tc16)->PULR = (val))
#define CSP_TC16_GET_PULR(tc16)		((tc16)->PULR)					  

/******************************************************************************
* Cxxx : Current Value Register
******************************************************************************/
/** Get CCDR register                                               	     */
#define CSP_TC16_GET_CCDR(tc16)		((tc16)->CCDR)
/** Get CCSMR register                                               	     */
#define CSP_TC16_GET_CCSMR(tc16)    ((tc16)->CCSMR)
/** Get CPRDR register                                               	     */
#define CSP_TC16_GET_CPRDR(tc16)    ((tc16)->CPRDR)
/** Get CPULR register                                              	     */
#define CSP_TC16_GET_CPULR(tc16)    ((tc16)->CPULR)
/** Get CUCR register                                               	     */
#define CSP_TC16_GET_CUCR(tc16)     ((tc16)->CUCR)
/** Get CDCR register               	                              	     */
#define CSP_TC16_GET_CDCR(tc16)     ((tc16)->CDCR)						  

/******************************************************************************
* CVR : Counter Value Register
******************************************************************************/
#define TC16_COUNT(val)  (((val) & 0xFFFFFFFFul) << 0)  /**< Writing Macro   */

/** Set CVR register                                                         */
#define CSP_TC16_SET_CVR(tc16, val)     ((tc16)->CVR = (val))
/** Get SR register                                               	     	 */
#define CSP_TC16_GET_CVR(tc16)        ((tc16)->CVR)		   		   

/******************************************************************************
***************************** TC16 Registers mask *****************************
******************************************************************************/
#define TC16_IDR_MASK          (0x03FFFFFFul)    /**< IDR mask        */
#define TC16_CSSR_MASK	       (0x00000001ul)    /**< CSSR mask       */
#define TC16_CEDR_MASK	       (0x80000001ul)    /**< CEDR mask       */
#define TC16_SRR_MASK          (0x00000001ul)    /**< SRR mask        */
#define TC16_CSR_MASK          (0x00077F0Dul)    /**< CSR mask        */
#define TC16_CCR_MASK          (0x00077F0Dul)    /**< CCR mask        */
#define TC16_SR_MASK           (0xFFFF7F0Dul)    /**< SR mask         */
#define TC16_IMSCR_MASK        (0x0000007Ful)    /**< IMSCR mask      */
#define TC16_RISR_MASK         (0x0000007Ful)    /**< RISR mask       */
#define TC16_MISR_MASK         (0x0000007Ful)    /**< MIS Rmask       */
#define TC16_ICR_MASK          (0x0000007Ful)    /**< ICR mask        */ 
#define TC16_CDR_MASK          (0x00000FFFul)    /**< SR mask         */
#define TC16_CSMR_MASK         (0x0000001Ful)    /**< SR mask         */
#define TC16_PRDR_MASK         (0xFFFFFFFFul)    /**< DR mask         */
#define TC16_PULR_MASK         (0xFFFFFFFFul)    /**< SR mask         */
#define TC16_CCDR_MASK         (0x00000000ul)    /**< CCDR mask       */
#define TC16_CCSMR_MASK        (0x0000000Ful)    /**< CCSMR mask      */
#define TC16_CPRDR_MASK        (0x00000000ul)    /**< CPRDR mask      */
#define TC16_CPULR_MASK        (0x00000000ul)    /**< CPULR mask      */	   
#define TC16_CUCR_MASK         (0xFFFFFFFFul)    /**< SR mask         */
#define TC16_CDCR_MASK         (0xFFFFFFFFul)    /**< SR mask         */  
#define TC16_CVR_MASK          (0xFFFFFFFFul)    /**< CVR mask        */
/******************************************************************************
***************************** TC16 reset value    *****************************
******************************************************************************/
#define TC16_IDR_RST          (0x0011000Aul)    /**< IDR reset value         */
#define TC16_CSSR_RST	      (0x00000000ul)    /**< CSSR reset value        */
#define TC16_CEDR_RST	      (0x00000000ul)    /**< CEDR reset value        */
#define TC16_SRR_RST          (0x00000000ul)    /**< SRR reset value         */
#define TC16_CSR_RST          (0x00000000ul)    /**< CSR reset value         */
#define TC16_CCR_RST          (0x00000000ul)    /**< CCR reset value         */
#define TC16_SR_RST           (0x00000000ul)    /**< SR reset value          */
#define TC16_IMSCR_RST        (0x00000000ul)    /**< IMSCR reset value       */
#define TC16_RISR_RST         (0x00000000ul)    /**< RISR reset value        */
#define TC16_MISR_RST         (0x00000000ul)    /**< MIS Rreset value        */
#define TC16_ICR_RST          (0x00000000ul)    /**< ICR reset value         */
#define TC16_CDR_RST          (0x00000000ul)    /**< CDR reset value          */
#define TC16_CSMR_RST         (0x0000000Ful)    /**< CSMR reset value         */
#define TC16_PRDR_RST         (0x00000000ul)    /**< PRDR reset value         */
#define TC16_PULR_RST         (0x00000000ul)    /**< PULP reset value         */
#define TC16_CCDR_RST         (0x00000000ul)    /**< CCDR reset value         */
#define TC16_CCSMR_RST        (0x0000000Ful)    /**< CCSMR reset value        */
#define TC16_CPRDR_RST        (0x00000000ul)    /**< CPRDR reset value        */
#define TC16_CPULR_RST        (0x00000000ul)    /**< CPULR reset value        */
#define TC16_CUCR_RST         (0x00000000ul)    /**< CUCR reset value         */
#define TC16_CDCR_RST         (0x00000000ul)    /**< CDCR reset value         */	
#define TC16_CVR_RST          (0x00000000ul)    /**< CVR reset value          */

/******************************************************************************
********************** TC16 External Functions Declaration **********************
******************************************************************************/
extern void CSP_TC16Init(CSP_TC16_T *st);
extern void CSP_TC16Close(CSP_TC16_T *st);
extern void CSP_TC16Configure(CSP_TC16_T *const tc16,
		U32_T csiz_u32, U16_T cdiv_u16, U32_T mode_32, U32_T prdr_u32);
extern void CSP_TC16ConfigPulse(CSP_TC16_T *const tc16,
		U32_T pwmstate_u32, U32_T pulse_u32);
extern void CSP_TC16ConfigInterrupt(CSP_TC16_T *st,
                                    U32_T intMask_u32,
                                    FunctionalStatus newState);
extern void CSP_TC16Enable(CSP_TC16_T *st);
extern void CSP_TC16Disable(CSP_TC16_T *st);
extern void CSP_TC16Update(CSP_TC16_T *st);


#endif   /* CSP_TC16_H */
