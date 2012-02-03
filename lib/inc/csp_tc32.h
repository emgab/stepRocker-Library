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
* @file name	csp_tc32.h
* @description Definitions, Macros and function declarations for TC32
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.  MCU Solution Part	 Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_TC32_H
#define CSP_TC32_H

/******************************************************************************
************************* TC32 Structure Definition ***************************
******************************************************************************/
/******************************************************************************
@brief TC 32 bits Structure
******************************************************************************/	 
typedef struct
{
    CSP_REGISTER_T     	IDR;			/**< ID Register	          		  */
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
} CSP_TC32_T, *CSP_TC32_PTR;

/******************************************************************************
************************** tc32 Registers Definition **************************
******************************************************************************/

/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define TC32_IPIDCODE_MASK  (0x03FFFFFFul << 0)    /**<  IPIDCODE mask     	*/
#define TC32_IPIDCODE  	   	(0x0011000Aul << 0)    /**<  IPIDCODE value     */

/** Set IDR register 		                                             	*/
 #define CSP_TC32_SET_IDR(tc32, val)    ((tc32)->IDR = (val))
/** Get IDR register                                                        */
 #define CSP_TC32_GET_IDR(tc32)        ((tc32)->IDR)

/******************************************************************************
* CSSR : Clock Source Selection Register
******************************************************************************/
#define TC32_CLKSRC         (0x01ul << 0)         /**< Clock Source			*/

/** Set CSSR register 		                                                */
 #define CSP_TC32_SET_CSSR(tc32, val)    ((tc32)->CSSR = (val))
/** Get CSSR register                                               		*/
 #define CSP_TC32_GET_CSSR(tc32)        ((tc32)->CSSR)


/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define TC32_CLKEN          (0x01ul << 0)         /**< Clock Enable          */
#define TC32_DBGEN          (0x01ul << 31)        /**< Debug Mode Enable     */

/** Set CEDR register 		                                                 */
 #define CSP_TC32_SET_CEDR(tc32, val)    ((tc32)->CEDR = (val))
/** Get CEDR register                                                  		 */
 #define CSP_TC32_GET_CEDR(tc32)        ((tc32)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define TC32_SWRST          (0x01ul << 0)         /**< Software Reset        */

/** Set SRR register 		                                             	 */
#define CSP_TC32_SET_SRR(tc32, val)    ((tc32)->SRR = (val))
/** Get SRR register                                               	     	 */
#define CSP_TC32_GET_SRR(tc32)        ((tc32)->SRR)					   

/******************************************************************************
* CSR : Control Set Register
* CCR : Control Clear Register
******************************************************************************/
#define TC32_START      (0x01ul << 0)		/**< tc32 Start	                */
#define TC32_UPDATE     (0x01ul << 1)		/**< tc32 Configuration update  */

#define TC32_STOPHOLD   (0x01ul << 2)      /**< Idle level for 0    */
#define TC32_STOPCLEAR  (0x01ul << 3)      /**< Sample level for 0  */
#define TC32_IDLESL     (0x01ul << 8)      /**< Dual mode for 0     */
#define TC32_OUTSL   	(0x01ul << 9)      /**< Dual mode for 0     */

#define TC32_KEEP      	(0x01ul << 10)     /**< tc32 Extension 0	*/
#define TC32_PWMIM	    (0x01ul << 11)     /**< tc32 Extension 1    */
#define TC32_PWMEN     	(0x01ul << 12)     /**< tc32 Extension 2    */
#define TC32_REPEAT    	(0x01ul << 13)     /**< tc32 Extension 3    */
#define TC32_OVFM       (0x01ul << 14)     /**< tc32 Extension 4    */
#define TC32_CAPTEN   	(0x01ul << 16)     /**< tc32 Extension 5    */
#define TC32_CAPT_F		(0x01ul << 17)
#define TC32_CAPT_R		(0x01ul << 18)
#define TC32_PWMEX0		(0x01ul << 24)
#define TC32_PWMEX1		(0x01ul << 25)
#define TC32_PWMEX2		(0x01ul << 26)
#define TC32_PWMEX3		(0x01ul << 27)
#define TC32_PWMEX4		(0x01ul << 28)
#define TC32_PWMEX5		(0x01ul << 29)

/* CSR : Control Register	                                             	*/
/** Set CSR register                                                        */
#define CSP_TC32_SET_CSR(tc32, val)     ((tc32)->CSR = (val))
/** Get CSR register                                               	     	*/
#define CSP_TC32_GET_CSR(tc32)        ((tc32)->CSR)

/* CCR : Control Register	                                             	*/
/** Set CCR register                                                        */
#define CSP_TC32_SET_CCR(tc32, val)     ((tc32)->CCR = (val))
/** Get CCR register                                               	     	*/
#define CSP_TC32_GET_CCR(tc32)        ((tc32)->CCR)

/******************************************************************************
* SR : Status Register
******************************************************************************/
#define TC32_CLKSRCS		(0x01ul << 31)	 /**< tc32 DBGEN           		 */
#define TC32_CLKENS     	(0x01ul << 30)	 /**< tc32 Clock Enable          */
#define TC32_CSMRS			(0x01ul << 19)	 /**< tc32 DBGEN                 */
#define TC32_CAPT_RS		(0x01ul << 18)	 /**< tc32 DBGEN                 */
#define TC32_CAPT_FS		(0x01ul << 17)	 /**< tc32 DBGEN                 */
#define TC32_CAPTENS		(0x01ul << 16)	 /**< tc32 DBGEN                 */

 /** Set SR register                                                         */
#define CSP_TC32_SET_SR(tc32, val)     ((tc32)->SR = (val))
/** Get SR register                                               	     	 */
#define CSP_TC32_GET_SR(tc32)        ((tc32)->SR)

/******************************************************************************
* IMSCR : Interrupt MASK Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Interrupt Status Register
* ICR : Interrupt Clear Register
******************************************************************************/
#define TC32_STARTI     (0x01ul << 0)      /**< Overflow Interrupt    		*/
#define TC32_STOPI    	(0x01ul << 1)      /**< Stop Interrupt            	*/
#define TC32_PSTARTI    (0x01ul << 2)      /**< Period Start Interrupt    	*/
#define TC32_PENDI    	(0x01ul << 3)      /**< Period End Interrupt        */
#define TC32_MATI   	(0x01ul << 4)      /**< Match Interrupt     		*/
#define TC32_OVFI 	   	(0x01ul << 5)      /**< Overflow Interrupt          */
#define TC32_CAPTI    	(0x01ul << 6)      /**< Capture Interrupt     		*/

#define TC32_STARTI     (0x01ul << 0)      /**< Overflow Interrupt     		*/
#define TC32_STOPI    	(0x01ul << 1)      /**< Stop Interrupt            	*/
#define TC32_PSTARTI    (0x01ul << 2)      /**< Period Start Interrupt     	*/
#define TC32_PENDI    	(0x01ul << 3)      /**< Period End Interrupt       	*/
#define TC32_MATI   	(0x01ul << 4)      /**< Match Interrupt     		*/
#define TC32_OVFI 	   	(0x01ul << 5)      /**< Overflow Interrupt          */
#define TC32_CAPTI    	(0x01ul << 6)      /**< Capture Interrupt     		*/

/** Set IMSCR register                                                      */
#define CSP_TC32_SET_IMSCR(tc32, val)    ((tc32)->IMSCR = (val))
/** Get IMSCR register                                                      */
#define CSP_TC32_GET_IMSCR(tc32)          ((tc32)->IMSCR)

/** Set RISR register                                                       */
#define CSP_TC32_SET_RISR(tc32, val)    ((tc32)->RISR = (val))
/** Get RISR register (Status)                                              */
#define CSP_TC32_GET_RISR(tc32)          ((tc32)->RISR)

/** Set MISR register                                                       */
#define CSP_TC32_SET_MISR(tc32, val)    ((tc32)->MISR = (val))
/** Get MISR register (Status)                                              */
#define CSP_TC32_GET_MISR(tc32)          ((tc32)->MISR)

/** Set ICR register                                                        */
#define CSP_TC32_SET_ICR(tc32, val)     ((tc32)->ICR = (val))
/** Get ICR register (Status)                                               */
#define CSP_TC32_GET_ICR(tc32)          ((tc32)->ICR)

/* Cortex-M0 Interrupt Set, Clear, Pending Registers 						*/
#define NVIC_TC32_1					(0x01ul << 2)		/** TC32 NVIC		*/
#define CPU_NVIC_SETEN(vec)			(*SETENA0 = (vec))
#define CPU_NVIC_CLREN(vec)			(*CLRENA0 = (vec))
#define CPU_NVIC_SETPE(vec)			(*SETPEND0 = (vec))
#define CPU_NVIC_CLRPE(vec)			(*CLRPEND0 = (vec))	   
/******************************************************************************
* CDR : Clock Divider Register
******************************************************************************/
#define CSP_TC32_SET_CDR(tc32, val)		((tc32)->CDR = (val))
#define CSP_TC32_GET_CDR(tc32)			((tc32)->CDR)

/******************************************************************************
* CSMR : Counter Size Mask Register
******************************************************************************/
#define CSP_TC32_SET_CSMR(tc32, val)	((tc32)->CSMR = (val))
#define CSP_TC32_GET_CSMR(tc32)			((tc32)->CSMR)

/******************************************************************************
* PRDR : Counter Size Mask Register
******************************************************************************/
#define CSP_TC32_SET_PRDR(tc32, val)	((tc32)->PRDR = (val))
#define CSP_TC32_GET_PRDR(tc32)			((tc32)->PRDR)

/******************************************************************************
* PULR : Pulse Register
******************************************************************************/
#define CSP_TC32_SET_PULR(tc32, val)	((tc32)->PULR = (val))
#define CSP_TC32_GET_PULR(tc32)			((tc32)->PULR)					  

/******************************************************************************
* Cxxx : Current Value Register
******************************************************************************/
/** Get CCDR register                                               	     */
#define CSP_TC32_GET_CCDR(tc32)		((tc32)->CCDR)
/** Get CCSMR register                                               	     */
#define CSP_TC32_GET_CCSMR(tc32)    ((tc32)->CCSMR)
/** Get CPRDR register                                               	     */
#define CSP_TC32_GET_CPRDR(tc32)    ((tc32)->CPRDR)
/** Get CPULR register                                               	     */
#define CSP_TC32_GET_CPULR(tc32)    ((tc32)->CPULR)
/** Get CUCR register                                              	     	 */
#define CSP_TC32_GET_CUCR(tc32)     ((tc32)->CUCR)
/** Get CDCR register                                               	     */
#define CSP_TC32_GET_CDCR(tc32)     ((tc32)->CDCR)						  

/******************************************************************************
* CVR : Counter Value Register
******************************************************************************/
#define TC32_COUNT(val)  (((val) & 0xFFFFFFFFul) << 0)  /**< Writing Macro   */

/** Set CVR register                                                         */
#define CSP_TC32_SET_CVR(tc32, val)     ((tc32)->CVR = (val))
/** Get SR register                                               	     	 */
#define CSP_TC32_GET_CVR(tc32)       	((tc32)->CVR)

/******************************************************************************
***************************** TC32 Registers mask *****************************
******************************************************************************/
#define TC32_IDR_MASK          (0x03FFFFFFul)    /**< IDR mask        */
#define TC32_CSSR_MASK	       (0x00000001ul)    /**< CSSR mask       */
#define TC32_CEDR_MASK	       (0x80000001ul)    /**< CEDR mask       */
#define TC32_SRR_MASK          (0x00000001ul)    /**< SRR mask        */
#define TC32_CSR_MASK          (0x3F077F0Ful)    /**< CSR mask        */
#define TC32_CCR_MASK          (0x3F077F0Ful)    /**< CCR mask        */
#define TC32_SR_MASK           (0x3F077F0Dul)    /**< SR mask         */
#define TC32_IMSCR_MASK        (0x0000007Ful)    /**< IMSCR mask      */
#define TC32_RISR_MASK         (0x0000007Ful)    /**< RISR mask       */
#define TC32_MISR_MASK         (0x0000007Ful)    /**< MIS Rmask       */
#define TC32_ICR_MASK          (0x0000007Ful)    /**< ICR mask        */ 
#define TC32_CDR_MASK          (0x00007FFFul)    /**< SR mask         */
#define TC32_CSMR_MASK         (0x0000001Ful)    /**< SR mask         */
#define TC32_PRDR_MASK         (0xFFFFFFFFul)    /**< DR mask         */
#define TC32_PULR_MASK         (0xFFFFFFFFul)    /**< SR mask         */
#define TC32_CCDR_MASK         (0xFFFFFFFFul)    /**< CCDR mask       */
#define TC32_CCSMR_MASK        (0x0000001Ful)    /**< CCSMR mask      */
#define TC32_CPRDR_MASK        (0xFFFFFFFFul)    /**< CPRDR mask      */
#define TC32_CPULR_MASK        (0xFFFFFFFFul)    /**< CPULR mask      */	   
#define TC32_CUCR_MASK         (0xFFFFFFFFul)    /**< SR mask         */
#define TC32_CDCR_MASK         (0xFFFFFFFFul)    /**< SR mask         */  
#define TC32_CVR_MASK          (0xFFFFFFFFul)    /**< CVR mask        */

/******************************************************************************
***************************** TC32 reset value    *****************************
******************************************************************************/
#define TC32_IDR_RST          (0x0011000Aul)    /**< IDR reset value         */
#define TC32_CSSR_RST	      (0x00000000ul)    /**< CSSR reset value        */
#define TC32_CEDR_RST	      (0x00000000ul)    /**< CEDR reset value        */
#define TC32_SRR_RST          (0x00000000ul)    /**< SRR reset value         */
#define TC32_CSR_RST          (0x00000000ul)    /**< CSR reset value         */
#define TC32_CCR_RST          (0x00000000ul)    /**< CCR reset value         */
#define TC32_SR_RST           (0x00000000ul)    /**< SR reset value          */
#define TC32_IMSCR_RST        (0x00000000ul)    /**< IMSCR reset value       */
#define TC32_RISR_RST         (0x00000000ul)    /**< RISR reset value        */
#define TC32_MISR_RST         (0x00000000ul)    /**< MIS Rreset value        */
#define TC32_ICR_RST          (0x00000000ul)    /**< ICR reset value         */
#define TC32_CDR_RST          (0x00000000ul)    /**< CDR reset value         */
#define TC32_CSMR_RST         (0x0000001Ful)    /**< CSMR reset value        */
#define TC32_PRDR_RST         (0x00000000ul)    /**< PRDR reset value        */
#define TC32_PULR_RST         (0x00000000ul)    /**< PULP reset value        */
#define TC32_CCDR_RST         (0x00000000ul)    /**< CCDR reset value        */
#define TC32_CCSMR_RST        (0x0000001Ful)    /**< CCSMR reset value       */
#define TC32_CPRDR_RST        (0x00000000ul)    /**< CPRDR reset value       */
#define TC32_CPULR_RST        (0x00000000ul)    /**< CPULR reset value       */
#define TC32_CUCR_RST         (0x00000000ul)    /**< CUCR reset value        */
#define TC32_CDCR_RST         (0x00000000ul)    /**< CDCR reset value        */	
#define TC32_CVR_RST          (0x00000000ul)    /**< CVR reset value         */

#define TC_CNTSIZE16			16	 /* 16-bit counter */
#define TC_MAXVALUE16			(1<<TC_CNTSIZE16)

#define TC_MAXCNT(x)			(1<<(x))
#define TC_CNTSIZE(x)			(((x) - 1)<<0)

/******************************************************************************
********************** TC32 External Functions Declaration ********************
******************************************************************************/
extern void CSP_TC32Init(CSP_TC32_T *st);
extern void CSP_TC32Close(CSP_TC32_T *st);
extern void CSP_TC32Configure(CSP_TC32_T *const tc32,
		U32_T csiz_u32, U16_T cdiv_u16, U32_T mode_32, U32_T prdr_u32);
extern void CSP_TC32ConfigPulse(CSP_TC32_T *const tc32,
		U32_T pwmstate_u32, U32_T pulse_u32);
extern void CSP_TC32ConfigInterrupt(CSP_TC32_T *st,
                                    U32_T intMask_u32,
                                    FunctionalStatus newState);
extern void CSP_TC32Enable(CSP_TC32_T *st);
extern void CSP_TC32Disable(CSP_TC32_T *st);
extern void CSP_TC32Update(CSP_TC32_T *st);	 

#endif   /* CSP_TC32_H */
