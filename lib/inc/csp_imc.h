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
* @file name	csp_imc.h
* @description Definitions, Macros and function declarations for IMC
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef _CSP_IMC_H_
#define _CSP_IMC_H_
/*******************************************************************************
*****************************   IMC STRUCTURE DEFINITION   *********************
*******************************************************************************/
typedef struct
{
  	CSP_REGISTER_T	IDR;		/**< ID Register	                       */
   	CSP_REGISTER_T  CEDR;       /**< Clock Enable/Disable Register         */
   	CSP_REGISTER_T  SRR;        /**< Software Reset Register               */
	CSP_REGISTER_T  CR0;	    /**< Inverter Motor Control Register 0     */
	CSP_REGISTER_T  CR1;	    /**< Inverter Motor Control Register 1     */
	CSP_REGISTER_T  CNTR;	    /**< Inverter motor Counter Register       */
	CSP_REGISTER_T  SR;	     	/**< Inverter Motor Status Register        */
	CSP_REGISTER_T  IMSCR;      /**< Interrupt Mask Set/Clear Register     */
	CSP_REGISTER_T  RISR;       /**< Raw Interrupt Status Register         */
	CSP_REGISTER_T  MISR;       /**< Masked Interrupt Status Register      */
	CSP_REGISTER_T  ICR;        /**< Interrupt Clear Register              */
	CSP_REGISTER_T  TCR;	    /**< Top Compare Register                  */
	CSP_REGISTER_T  DTCR;	    /**< Deadtime compare Register             */
	CSP_REGISTER_T  PACRR;	    /**< Phase A compare register for Rising   */
	CSP_REGISTER_T  PBCRR;	    /**< Phase B compare register for Rising   */
	CSP_REGISTER_T  PCCRR;	    /**< Phase C compare register for Rising   */
	CSP_REGISTER_T  PACFR;	    /**< Phase A compare register for Falling  */
	CSP_REGISTER_T  PBCFR;	    /**< Phase B compare register for Falling  */
	CSP_REGISTER_T  PCCFR;	    /**< Phase C compare register for Falling  */
	CSP_REGISTER_T  ASTSR;	    /**< ADC Start Signal Select Register      */
	CSP_REGISTER_T  ASCRR0;	    /**< ADC Start Compare Register of Rising0 */
	CSP_REGISTER_T  ASCRR1;	    /**< ADC Start Compare Register of Rising1 */
	CSP_REGISTER_T  ASCRR2;	    /**< ADC Start Compare Register of Rising2 */
	CSP_REGISTER_T  ASCFR0;	    /**< ADC Start Compare Register of Falling0*/
	CSP_REGISTER_T  ASCFR1;	    /**< ADC Start Compare Register of Falling1*/
	CSP_REGISTER_T  ASCFR2;	    /**< ADC Start Compare Register of Falling2*/
} CSP_IMC_T, *CSP_IMC_PTR;

/*******************************************************************************
****************************  IMC REGISTERS DEFINITION   ***********************
*******************************************************************************/
/*******************************************************************************
* IDR : Clock Manager ID Register
*******************************************************************************/
#define IMC_IDCODE    	   		(0x00010012 << 0) 	/**< ID Code 		      */
#define CSP_IMC_GET_IDR(imc)    (imc->IDR)

/******************************************************************************
* CEDR : Clock En/disable Register
******************************************************************************/
#define IMC_CLKEN	   	  (0x01ul << 0) 	/**< Clock Enable       	*/
#define IMC_DBGEN	   	  (0x01ul << 31) 	/**< Debug Enable      		*/

#define CSP_IMC_SET_CEDR(imc, val)     (imc->CEDR = (val))
#define CSP_IMC_GET_CEDR(imc)          (imc->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define IMC_SWRST	   	  (0x01ul << 0)		/**< Software Reset          */
#define CSP_IMC_SET_SRR(imc, val)    	(imc->SRR = (val))

/*******************************************************************************
* CR0 : Inverter Motor Control Register 0
*******************************************************************************/
#define IMC_IMEN		(0x01ul << 0)  	/**< Inverter Motor Enable Bit 	*/
#define IMC_IMMODE		(0x01ul << 1)  	/**< Inverter Motor Mode Bit 	*/
#define IMC_WMODE  		(0x01ul << 2)	/**< Write Mode of Compare Register */
#define IMC_PWMSWAP 	(0x01ul << 3)	/**< Swapping of PWMxUx and PWMxDx 	*/
#define IMC_PWMPOLU  	(0x01ul << 4)  	/**< Polarity of PWM in PWMxU0/1/2 	*/
#define IMC_PWMPOLD  	(0x01ul << 5)  	/**< Polarity of PWM in PWMxD0/1/2 	*/
#define IMC_ESELPWMOFF(val) (((val) & 0x03) << 6)/**< PWMxOFF Active Selection */
#define IMC_IMFILTER(val)	(((val) & 0x07) << 8)
							/**< Filter Clock Selection of PWMxOFFP */
#define IMC_PWMOFFEN 		(0x01ul << 12)  /**< PWMxOFF Enable Bit */
#define IMC_PWMOUTOFFEN 	(0x01ul << 13) 	/**< PWM output Disable by PWMxOFF */
#define IMC_PWMOUTEN 		(0x01ul << 14) 	/**< PWM output Enable Bit */
#define IMC_IMCLKSEL(val) 	(((val) & 0x07) << 16) /**< IMCLK Selection */
#define IMC_NUMSKIP(val)  	(((val) & 0x1F) << 20)
							/**< Number of Skip for Motor Match Interrupt */
#define IMC_SYNCSEL(val)    (((val) & 0x03) << 26) /**< Synchronous wirte selection */

/** Set CR0 register */
#define CSP_IMC_SET_CR0(imc, val)   ((imc)->CR0 = (val))

/** Get CR0 register */
#define CSP_IMC_GET_CR0(imc)		((imc)->CR0)

/*******************************************************************************
* CR1 : Inverter Motor Control Register 1
*******************************************************************************/
#define IMC_PWMxD2EN		(0x01ul << 0)   /**< PWMxD2 PWM Output Disable */
#define IMC_PWMxD1EN		(0x01ul << 1)   /**< PWMxD1 PWM Output Disable */
#define IMC_PWMxD0EN		(0x01ul << 2)   /**< PWMxD0 PWM Output Disable */
#define IMC_PWMxU2EN		(0x01ul << 3)   /**< PWMxU2 PWM Output Disable */
#define IMC_PWMxU1EN		(0x01ul << 4)   /**< PWMxU1 PWM Output Disable */
#define IMC_PWMxU0EN		(0x01ul << 5)   /**< PWMxU0 PWM Output Disable */

#define IMC_PWMxD2LEVEL	    (0x01ul << 8)   /**< PWMxD2 Output Level: High */
#define IMC_PWMxD1LEVEL	    (0x01ul << 9)   /**< PWMxD1 Output Level: High */
#define IMC_PWMxD0LEVEL	    (0x01ul << 10)  /**< PWMxD0 Output Level: High */
#define IMC_PWMxU2LEVEL	    (0x01ul << 11)  /**< PWMxU2 Output Level: High */
#define IMC_PWMxU1LEVEL	    (0x01ul << 12)  /**< PWMxU1 Output Level: High */
#define IMC_PWMxU0LEVEL	    (0x01ul << 13)  /**< PWMxU0 Output Level: High */

#define IMC_PWMxD2DT		(0x01ul << 16)  /**< PWMxD2 Deadtime insert */
#define IMC_PWMxD1DT		(0x01ul << 17)  /**< PWMxD1 Deadtime insert */
#define IMC_PWMxD0DT		(0x01ul << 18)  /**< PWMxD0 Deadtime insert */
#define IMC_PWMxU2DT		(0x01ul << 19)  /**< PWMxU2 Deadtime insert */
#define IMC_PWMxU1DT		(0x01ul << 20)  /**< PWMxU1 Deadtime insert */
#define IMC_PWMxU0DT		(0x01ul << 21)  /**< PWMxU0 Deadtime insert */

/** Set CR1 register */
#define CSP_IMC_SET_CR1(imc, val)	((imc)->CR1 = (val))

/** Get CR1 register */
#define CSP_IMC_GET_CR1(imc)		((imc)->CR1)

/*******************************************************************************
* CNTR : Inverter motor Counter Register
*******************************************************************************/
#define IMC_CV(val)				(((val) & 0x0FFFF) << 0)	/**< Count value */

/** Get CNTR register */
#define CSP_IMC_GET_CNTR(imc)	((imc)->CNTR)

/*******************************************************************************
* SR : Inverter Motor Status Register
*******************************************************************************/
#define IMC_FAULTSTAT	(0x01ul << 0)  /**< Status of PWM Output:High-Z */
#define IMC_UPDOWNSTAT  (0x01ul << 1)  /**< Status of PWM Counter:Down Counting*/

/** Set SR register */
#define CSP_IMC_SET_SR(imc, val)	((imc)->SR = (val))

/** Get SR register */
#define CSP_IMC_GET_SR(imc)		((imc)->SR)

/******************************************************************************
* IMSCR : Interrupt Mask Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Interrupt Status Register
* ICR : Interrupt Clear Register
******************************************************************************/
#define IMC_ZERO		 (0x01ul << 6)
/** Set IMSCR register                                                      */
#define CSP_IMC_SET_IMSCR(imc, val)	((imc)->IMSCR = (val))
/** Get IMSCR register                                                      */
#define CSP_IMC_GET_IMSCR(imc)	((imc)->IMSCR)

/** Set RISR register                                                       */
#define CSP_IMC_SET_RISR(imc, val)	((imc)->RISR = (val))
/** Get RISR register (Status)                                              */
#define CSP_IMC_GET_RISR(imc)	((imc)->RISR)

/** Set MISR register                                                       */
#define CSP_IMC_SET_MISR(imc, val)	((imc)->MISR = (val))
/** Get MISR register (Status)                                              */
#define CSP_IMC_GET_MISR(imc)	((imc)->MISR)

/** Set ICR register                                                       */
#define CSP_IMC_SET_ICR(imc, val)	((imc)->ICR = (val))

/*******************************************************************************
* TCR : Top Compare Register
*******************************************************************************/
#define IMC_TOPCMPDATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set TCR register */
#define CSP_IMC_SET_TCR(imc, val)	((imc)->TCR = (val))

/** Get TCR register */
#define CSP_IMC_GET_TCR(imc)	((imc)->TCR)

/*******************************************************************************
* DTCR : Deadtime compare Register
*******************************************************************************/
#define IMC_DTCMPDATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set DTCR register */
#define CSP_IMC_SET_DTCR(imc, val)	((imc)->DTCR = (val))

/** Get DTCR register */
#define CSP_IMC_GET_DTCR(imc)	((imc)->DTCR)		

/*******************************************************************************
* ASTSR : ADC Start Signal Select Register
*******************************************************************************/
#define IMC_TOPCMPSEL	(0x01ul << 0)
						/**< ADC Start Trigger Signal by TOPCMP Match */
#define IMC_0SEL		(0x01ul << 1)
						/**< ADC Start Trigger Signal by Counter Zero Match */
#define IMC_ADCCMPR0SEL	(0x01ul << 2)
						/**< ADC Start Trigger Signal by ADCCMPR0 Match */
#define IMC_ADCCMPF0SEL	(0x01ul << 3)
						/**< ADC Start Trigger Signal by ADCCMPF0 Match */
#define IMC_ADCCMPR1SEL	(0x01ul << 4)
						/**< ADC Start Trigger Signal by ADCCMPR1 Match */
#define IMC_ADCCMPF1SEL	(0x01ul << 5)
						/**< ADC Start Trigger Signal by ADCCMPF1 Match */
#define IMC_ADCCMPR2SEL	(0x01ul << 6)
						/**< ADC Start Trigger Signal by ADCCMPR2 Match */
#define IMC_ADCCMPF2SEL	(0x01ul << 7)
						/**< ADC Start Trigger Signal by ADCCMPF2 Match */ 

/*******************************************************************************
* PACRR : Phase A compare register for Rising
* PBCRR : Phase B compare register for Rising
* PCCRR : Phase C compare register for Rising
*******************************************************************************/
#define IMC_PACMPRDATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */
#define IMC_PBCMPRDATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */
#define IMC_PCCMPRDATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set PACRR register */
#define CSP_IMC_SET_PACRR(imc, val)	((imc)->PACRR = (val))

/** Get PACRR register */
#define CSP_IMC_GET_PACRR(imc)	((imc)->PACRR)

/** Set PBCRR register */
#define CSP_IMC_SET_PBCRR(imc, val)	((imc)->PBCRR = (val))

/** Get PBCMPR register */
#define CSP_IMC_GET_PBCRR(imc)	((imc)->PBCRR)

/** Set PCCRR register */
#define CSP_IMC_SET_PCCRR(imc, val)	((imc)->PCCRR = (val))

/** Get PCCRR register */
#define CSP_IMC_GET_PCCRR(imc)	((imc)->PCCRR)

/*******************************************************************************
* PACFR : Phase A compare register for Rising
* PBCFR : Phase B compare register for Rising
* PCCFR : Phase C compare register for Rising
*******************************************************************************/
#define IMC_PACMPFDATA(val) (((val) & 0x0FFFF) << 0)	/**< Data value */
#define IMC_PBCMPFDATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */
#define IMC_PCCMPFDATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set PACFR register */
#define CSP_IMC_SET_PACFR(imc, val)		((imc)->PACFR = (val))

/** Get PACFR register */
#define CSP_IMC_GET_PACFR(imc)			((imc)->PACFR)

/** Set PBCFR register */
#define CSP_IMC_SET_PBCFR(imc, val)		((imc)->PBCFR = (val))

/** Get PBCFR register */
#define CSP_IMC_GET_PBCFR(imc)			((imc)->PBCFR)

/** Set PCCFR register */
#define CSP_IMC_SET_PCCFR(imc, val)		((imc)->PCCFR = (val))

/** Get PCCFR register */
#define CSP_IMC_GET_PCCFR(imc)			((imc)->PCCFR)


/*******************************************************************************
* ASTSR : ADC Start Trigger SElect Rising
*******************************************************************************/
#define IMC_TOPCMPSEL	(0x01ul << 0)
						/**< ADC Start Trigger Signal by TOPCMP Match */
#define IMC_0SEL		(0x01ul << 1)
						/**< ADC Start Trigger Signal by Counter Zero Match */
#define IMC_ADCCMPR0SEL	(0x01ul << 2)
						/**< ADC Start Trigger Signal by ADCCMPR0 Match */
#define IMC_ADCCMPF0SEL	(0x01ul << 3)
						/**< ADC Start Trigger Signal by ADCCMPF0 Match */
#define IMC_ADCCMPR1SEL	(0x01ul << 4)
						/**< ADC Start Trigger Signal by ADCCMPR1 Match */
#define IMC_ADCCMPF1SEL	(0x01ul << 5)
						/**< ADC Start Trigger Signal by ADCCMPF1 Match */
#define IMC_ADCCMPR2SEL	(0x01ul << 6)
						/**< ADC Start Trigger Signal by ADCCMPR2 Match */
#define IMC_ADCCMPF2SEL	(0x01ul << 7)
						/**< ADC Start Trigger Signal by ADCCMPF2 Match */

/** Set ASTSR register */
#define CSP_IMC_SET_ASTSR(imc, val)   ((imc)->ASTSR = (val))

/** Get ASTSR register */
#define CSP_IMC_GET_ASTSR(imc)		((imc)->ASTSR)

/*******************************************************************************
* ASCRR0 : ADC Start Compare Register of Rising 0
* ASCRR1 : ADC Start Compare Register of Rising 1
* ASCRR2 : ADC Start Compare Register of Rising 2
*******************************************************************************/
#define IMC_ADCCMPR0DATA(val)   (((val) & 0x0FFFF) << 0)	/**< Data value */
#define IMC_ADCCMPR1DATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */
#define IMC_ADCCMPR2DATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set ASCRR0 register */
#define CSP_IMC_SET_ASCRR0(imc, val)	((imc)->ASCRR0 = (val))

/** Get ASCRR0 register */
#define CSP_IMC_GET_ASCRR0(imc)			((imc)->ASCRR0)

/** Set ASCRR1 register */
#define CSP_IMC_SET_ASCRR1(imc, val)	((imc)->ASCRR1 = (val))

/** Get ASCRR1 register */
#define CSP_IMC_GET_ASCRR1(imc)			((imc)->ASCRR1)

/** Set ASCRR2 register */
#define CSP_IMC_SET_ASCRR2(imc, val)	((imc)->ASCRR2 = (val))

/** Get ASCRR2 register */
#define CSP_IMC_GET_ASCRR2(imc)			((imc)->ASCRR2)

/*******************************************************************************
* ASCFR0 : ADC Start Compare Register of Falling 0
* ASCFR1 : ADC Start Compare Register of Falling 1
* ASCFR2 : ADC Start Compare Register of Falling 2
* *******************************************************************************/
#define IMC_ADCCMPF0DATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */
#define IMC_ADCCMPF1DATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */
#define IMC_ADCCMPF2DATA(val)	(((val) & 0x0FFFF) << 0)	/**< Data value */

/** Set ASCFR0 register */
#define CSP_IMC_SET_ASCFR0(imc, val)	((imc)->ASCFR0 = (val))

/** Get ADCCMPF0 register */
#define CSP_IMC_GET_ASCFR0(imc)			((imc)->ASCFR0)

/** Set ASCFR1 register */
#define CSP_IMC_SET_ASCFR1(imc, val)	((imc)->ASCFR1 = (val))

/** Get ASCFR1 register */
#define CSP_IMC_GET_ASCFR1(imc)			((imc)->ASCFR1)

/** Set ASCFR2 register */
#define CSP_IMC_SET_ASCFR2(imc, val)	((imc)->ASCFR2 = (val))

/** Get ASCFR2 register */
#define CSP_IMC_GET_ASCFR2(imc)			((imc)->ASCFR2)

/*******************************************************************************
******************************* IMC REGISTER MASK  *****************************
*******************************************************************************/
#define IMC_IDR_MASK    	(0x03FFFFFFul)  /**< IDR mask          	*/
#define IMC_CEDR_MASK		(0x80000001ul)  /**< CEDR mask        	*/
#define IMC_SRR_MASK    	(0x00000001ul)  /**< SRR mask         	*/
#define IMC_CR0_MASK		(0x0DF777FFul)  /**< IMCON0 mask 		*/
#define IMC_CR1_MASK		(0x003F3F3Ful)  /**< IMCON1 mask 		*/
#define IMC_CNTR_MASK		(0x0000FFFFul)  /**< IMCNT mask 		*/
#define IMC_SR_MASK			(0x00000003ul)  /**< IMSTATUS mask 		*/
#define IMC_IMSCR_MASK  	(0x00003FC1ul)  /**< IMSCR mask        	*/
#define IMC_RISR_MASK   	(0x00003FC1ul)  /**< RISR mask         	*/
#define IMC_MISR_MASK   	(0x00003FC1ul)  /**< MISR mask         	*/
#define IMC_ICR_MASK    	(0x00003FC1ul)  /**< ICR mask          	*/
#define IMC_TCR_MASK		(0x0000FFFFul)  /**< TOPCMP mask 		*/
#define IMC_DTCR_MASK		(0x0000FFFFul)  /**< DTCMP mask 		*/
#define IMC_PACRR_MASK		(0x0000FFFFul)  /**< PACMPR mask		*/
#define IMC_PBCRR_MASK		(0x0000FFFFul)  /**< PBCMPR mask 		*/
#define IMC_PCCRR_MASK		(0x0000FFFFul)  /**< PCCMPR mask 		*/
#define IMC_PACFR_MASK		(0x0000FFFFul)  /**< PACMPF mask 		*/
#define IMC_PBCFR_MASK		(0x0000FFFFul)  /**< PBCMPF mask 		*/
#define IMC_PCCFR_MASK		(0x0000FFFFul)  /**< PCCMPF mask 		*/
#define IMC_ASTSR_MASK		(0x000000FFul)  /**< ADCSTARTSEL  mask 	*/
#define IMC_ASCRR0_MASK		(0x0000FFFFul)  /**< ADCCMPR0 mask 		*/
#define IMC_ASCRR1_MASK		(0x0000FFFFul)  /**< ADCCMPR1 mask 		*/
#define IMC_ASCRR2_MASK		(0x0000FFFFul)  /**< ADCCMPR2 mask 		*/
#define IMC_ASCFR0_MASK		(0x0000FFFFul)  /**< ADCCMPF0  mask		*/
#define IMC_ASCFR1_MASK		(0x0000FFFFul)  /**< ADCCMPF1 mask 		*/
#define IMC_ASCFR2_MASK		(0x0000FFFFul)  /**< ADCCMPF2 mask 		*/

/*******************************************************************************
******************************* IMC REGISTER RESET VALUE  **********************
*******************************************************************************/
#define IMC_IDR_RST         (0x00010012ul)	/**< IDR reset value      	*/
#define IMC_CEDR_RST	    (0x00000000ul)  /**< CEDR reset value      	*/
#define IMC_SRR_RST         (0x00000000ul)  /**< SRR reset value		*/
#define IMC_CR0_RST	        (0x00000000ul)  /**< IMCON0 reset value 	*/
#define IMC_CR1_RST	        (0x00000000ul)  /**< IMCON1 reset value 	*/
#define IMC_CNTR_RST	    (0x00000000ul)  /**< IMCNT reset value 		*/
#define IMC_SR_RST	        (0x00000000ul)  /**< IMSTATUS reset value 	*/
#define IMC_IMSCR_RST       (0x00000000ul)  /**< IMSCR reset value      */
#define IMC_RISR_RST   		(0x00000000ul)  /**< RISR reset value       */
#define IMC_MISR_RST   		(0x00000000ul)  /**< MISR reset value       */
#define IMC_ICR_RST    		(0x00000000ul)  /**< ICR reset value        */
#define IMC_TCR_RST	        (0x00000000ul)  /**< TOPCMP reset value 	*/
#define IMC_DTCR_RST		(0x00000000ul)  /**< DTCMP reset value 		*/
#define IMC_PACRR_RST		(0x00000000ul)  /**< PACMPR reset value		*/
#define IMC_PBCRR_RST		(0x00000000ul)  /**< PBCMPR reset value 	*/
#define IMC_PCCRR_RST		(0x00000000ul)  /**< PCCMPR reset value 	*/
#define IMC_PACFR_RST		(0x00000000ul)  /**< PACMPF reset value 	*/
#define IMC_PBCFR_RST		(0x00000000ul)  /**< PBCMPF reset value 	*/
#define IMC_PCCFR_RST		(0x00000000ul)  /**< PCCMPF reset value 	*/
#define IMC_ASTSR_RST		(0x00000000ul)  /**< ADCSTARTSEL  reset value*/
#define IMC_ASCRR0_RST		(0x00000000ul)  /**< ADCCMPR0 reset value 	*/
#define IMC_ASCRR1_RST		(0x00000000ul)  /**< ADCCMPR1 reset value 	*/
#define IMC_ASCRR2_RST		(0x00000000ul)  /**< ADCCMPR2 reset value 	*/
#define IMC_ASCFR0_RST		(0x00000000ul)  /**< ADCCMPF0  reset value	*/
#define IMC_ASCFR1_RST		(0x00000000ul)  /**< ADCCMPF1 reset value 	*/
#define IMC_ASCFR2_RST		(0x00000000ul)  /**< ADCCMPF2 reset value 	*/
#define IMC_ASCFR2_RST		(0x00000000ul)  /**< DTCMP reset value 		*/

/*******************************************************************************
********************* IMC External Functions Declaration ***********************
*******************************************************************************/
extern void CSP_IMCPinConfiguration(CSP_IMC_T *const imc);
extern void CSP_IMCEnable(CSP_IMC_T *const imc);
extern void CSP_IMCDisable(CSP_IMC_T *const imc);

extern void CSP_IMCSetFaultControl( CSP_IMC_T *const imc, 
				U8_T pwmoff1_ornot0_atfault, U8_T filterclk_3bit,
				 U8_T define_faultSigtype_2bit, U8_T pwmoutoff1_ornot0,
											 U8_T pwmout_highz1_pwmsig0);
extern void CSP_IMCSetPhaseCompareRegisters( CSP_IMC_T *const imc, U16_T topcmp,
U16_T pacmpr, U16_T pbcmpr, U16_T pccmpr, U16_T pacmpf, U16_T pbcmpf, U16_T pccmpf);

extern void CSP_IMCSetADCCompareRegisters(CSP_IMC_T *const imc,
					U16_T acdcmpr0, U16_T acdcmpr1, U16_T acdcmpr2,
					U16_T acdcmpf0, U16_T acdcmpf1, U16_T acdcmpf2);
extern void CSP_IMCSetADCStartTriggerSrc(CSP_IMC_T *const imc, U8_T select_compr);
extern void CSP_IMCOutSignalSetting( CSP_IMC_T *const imc, U8_T mode_Tri0_Saw1,
	    	U8_T swap1_ornot0, U8_T pwmup_start_1or0 , U8_T pwndown_start_1or0);
extern void CSP_IMCControlPWNOutGateSwitch( CSP_IMC_T *const imc,
					U8_T pwmxu0_on0_off1,U8_T pwmxd0_on0_off1,
					U8_T pwmxu1_on0_off1, U8_T pwmxd1_on0_off1,
					U8_T pwmxu2_on0_off1, U8_T pwmxd2_on0_off1);

#endif /* _CSP_IMC_H_ */
