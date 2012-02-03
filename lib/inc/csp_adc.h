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
* @file name	csp_adc.h
* @description Definitions, Macros and function declarations for ADC
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   YH JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_ADC_H
#define CSP_ADC_H

/******************************************************************************
************************* ADC Structure Definition ****************************
******************************************************************************/
/******************************************************************************
@brief description CSP_ADC_T and CSP_ADC_PTR
******************************************************************************/
 typedef struct
 {
    CSP_REGISTER_T     	IDR;			/**< ID Register	  		          */
    CSP_REGISTER_T     	CEDR;        	/**< Clock Enable/Disable Register    */
    CSP_REGISTER_T     	SRR;         	/**< Software Reset Register          */
    CSP_REGISTER_T     	CSR;        	/**< Control Set Register             */
    CSP_REGISTER_T     	CCR;        	/**< Control Clear Register           */
    CSP_REGISTER_T     	CDR;        	/**< Clock Divider Register           */
    CSP_REGISTER_T     	MR;             /**< Mode Register                    */
    CSP_REGISTER_T     	SR;             /**< Status Register                  */
    CSP_REGISTER_T     	IMSCR;       	/**< Interrupt Mask Set/Clear Register*/
    CSP_REGISTER_T     	RISR;        	/**< Raw Interrupt Status Register    */
    CSP_REGISTER_T     	MISR;        	/**< Masked Interrupt Status Register */
    CSP_REGISTER_T     	ICR;        	/**< Interrupt Clear Register         */
    CSP_REGISTER_T		CRR;			/**< Conversion Result Register       */
    CSP_REGISTER_T	 	GCR;			/**< Gain Calibration Register        */
    CSP_REGISTER_T		OCR;			/**< Offset Calibration Register      */
    CSP_REGISTER_T		DMACR;			/**< DMA Control Register  	      	  */
 } CSP_ADC_T, *CSP_ADC_PTR;

/******************************************************************************
************************* ADC Registers Definition ****************************
******************************************************************************/
/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define ADC_IDCODE_MASK  	(0x03FFFFFFul << 0)		/**<  IPIDCODE mask     */
#define ADC_IDCODE  	  	(0x0001001F << 0)   	/**<  IPIDCODE value    */
																			  
/** Get IDR register                                                        */
 #define CSP_ADC_GET_IDR(adc)        ((adc)->IDR)

/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define ADC_CLKEN          (0x01ul << 0)         /**< IP Clock              */
#define ADC_DBGEN          (0x01ul << 31)        /**< Debug Mode Enable     */

/** Set CEDR register 		                                                */
 #define CSP_ADC_SET_CEDR(adc, val)    ((adc)->CEDR = (val))
/** Get CEDR register                                               */
 #define CSP_ADC_GET_CEDR(adc)        ((adc)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define ADC_SWRST          (0x01ul << 0)         /**< Software Reset  		*/

/** Set SRR register 		                                            	*/
#define CSP_ADC_SET_SRR(adc, val)    ((adc)->SRR = (val))

/******************************************************************************
* CSR : Control Set Register
* CCR : Control Clear Register
******************************************************************************/
#define ADC_ADCEN     (0x01ul << 0)     /**< ADC macro(engine)Enable        */

/* CSR only */
#define ADC_START     (0x01ul << 1)		/**< Conversion Start - Only CSR    */

/** Set CSR register                                                        */
#define CSP_ADC_SET_CSR(adc, val)     ((adc)->CSR = (val))

/** Set CCR register                                                        */
#define CSP_ADC_SET_CCR(adc, val)     ((adc)->CCR = (val))						

/******************************************************************************
* CDR : Clock Divider Register
******************************************************************************/
#define ADC_CDIV_MASK     	(0x1Ful << 0)     		/**< ADC CDIV mask      */
#define ADC_CDIV(val)    	(((val) & 0x1Ful) << 0) /**< Writing Macro      */

/** Set CDR register                                                        */
#define CSP_ADC_SET_CDR(adc, val)     ((adc)->CDR = (val))

/** Get CDR register                                               	        */
#define CSP_ADC_GET_CDR(adc)        ((adc)->CDR)

/******************************************************************************
* MR : ADC Mode Register
******************************************************************************/
#define ADC_CCSEL_MASK  (0x0Ful << 0)           /**< mask               */
#define ADC_CCSEL(val)  (((val) & 0x0Ful) << 0) /**< Writing Macro      */
#define ADC_TRIG_MASK  	(0x07ul << 5)   	/**< external start trigger type */
#define ADC_TRIG(val)  	(((val) & 0x07ul) << 5) /**< writing Macro      */
#define ADC_CALEN      	(0x01ul << 24)  /**< Calibration enable          */
#define ADC_ICRV      	(0x01ul << 25)  /**< Int. Calibration Reference Voltage*/
#define ADC_EICR      	(0x01ul << 26)  /**< ExtInt Calibration Reference*/

#define ADC_SWSTART		(0x0)
#define ADC_ADTRG_R     (0x1)
#define ADC_ADTRG_F		(0x2)
#define ADC_ADTRG_B		(0x3)
#define ADC_TC			(0x4)
#define ADC_IMC			(0x5)

#define ADC_AIN0		0x0ul            /**< ADC Analog Input 0 	     */
#define ADC_AIN1    	0x1ul            /**< ADC Analog Input 1 	     */
#define ADC_AIN2    	0x2ul            /**< ADC Analog Input 2 	     */
#define ADC_AIN3    	0x3ul            /**< ADC Analog Input 3 	     */
#define ADC_AIN4    	0x4ul            /**< ADC Analog Input 4 	     */
#define ADC_AIN5    	0x5ul            /**< ADC Analog Input 5 	     */
#define ADC_AIN6    	0x6ul            /**< ADC Analog Input 6 	     */
#define ADC_AIN7    	0x7ul            /**< ADC Analog Input 7 	     */
#define ADC_AIN8    	0x8ul            /**< ADC Analog Input 8 	     */
#define ADC_AIN9    	0x9ul            /**< ADC Analog Input 9 	     */
#define ADC_AIN10   	0xAul            /**< ADC Analog Input 10	     */

#define AIN1        ADC_AIN1        	/**< ADC Analog Input 1 	     */
#define AIN2        ADC_AIN2            /**< ADC Analog Input 2 	     */
#define AIN3        ADC_AIN3            /**< ADC Analog Input 3 	     */
#define AIN4        ADC_AIN4            /**< ADC Analog Input 4 	     */
#define AIN5        ADC_AIN5            /**< ADC Analog Input 5 	     */
#define AIN6        ADC_AIN6            /**< ADC Analog Input 6 	     */
#define AIN7        ADC_AIN7            /**< ADC Analog Input 7 	     */
#define AIN8        ADC_AIN8            /**< ADC Analog Input 8 	     */
#define AIN9        ADC_AIN9             /**< ADC Analog Input 9 	     */
#define AIN10       ADC_AIN10           /**< ADC Analog Input 10	     */

/** Get MR register                                           */
#define CSP_ADC_GET_MR(adc)           ((adc)->MR)
/** Set MR register                                           */
#define CSP_ADC_SET_MR(adc, val)     ((adc)->MR = (val))

/******************************************************************************
* SR : ADC Status Registers
******************************************************************************/
#define ADC_BUSY      (0x01ul << 0)     /**< ADC macro busy for conversion   */

/** Get SR register (Status Register)                                        */
#define CSP_ADC_GET_SR(adc)           ((adc)->SR)

/******************************************************************************
* IMSCR : Interrupt RST Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Interrupt Status Register
* ICR : Interrupt Clear Register
******************************************************************************/
#define ADC_EOC     	(0x01ul << 0)      /**< End Of Conversion Interrupt     */
#define ADC_OVR      	(0x01ul << 1)      /**< Overrun Interrupt            */

/** Set IMSCR register                                                      */
#define CSP_ADC_SET_IMSCR(adc, val)    ((adc)->IMSCR = (val))

/** Get IMSCR register                                                      */
#define CSP_ADC_GET_IMSCR(adc)          ((adc)->IMSCR)

/** Get RISR register (Status)                                              */
#define CSP_ADC_GET_RISR(adc)          ((adc)->RISR)

/** Get MISR register (Status)                                              */
#define CSP_ADC_GET_MISR(adc)          ((adc)->MISR)

/** Set ICR register                                                       */
#define CSP_ADC_SET_ICR(adc, val)     ((adc)->ICR = (val))

/******************************************************************************
* CRR : ADC Conversion Result Register
******************************************************************************/
#define ADC_DATA_MASK     (0xFFFul << 0)    /**< ADC Converted Data Mask */

/** Get CRR register                                                          */
#define CSP_ADC_GET_CRR(adc)           ((adc)->CRR)

/******************************************************************************
* GCR : ADC Gain Calibration Register
******************************************************************************/
/** Get GCR register (Calibration Register)                      	*/
#define CSP_ADC_GET_GCR(adc)           ((adc)->GCR)

/** Set GCR register (Calibration Register)                        */
#define CSP_ADC_SET_GCR(adc, val)     ((adc)->GCR = (val & 0x7FFFul))

/******************************************************************************
* OCR : ADC Offset Calibration Register
******************************************************************************/
/** Get CCR register (Calibration Register)                      	*/
#define CSP_ADC_GET_OCR(adc)           ((adc)->OCR)

/** Set CCR register (Calibration Register)                        */
#define CSP_ADC_SET_OCR(adc, val)     ((adc)->OCR = (val & 0x3FFFul))

/******************************************************************************
* DMACR : DMA Control Register
******************************************************************************/
#define ADC_DMAE     (0x01ul << 0)    /**< ADC DMA Enable */

/** Set DMACR register                         */
#define CSP_ADC_SET_DMACR(adc, val)     ((adc)->DMACR = (val))

/** Get DMACR register	                              			*/
#define CSP_ADC_GET_DMACR(adc)           ((adc)->DMACR)

/******************************************************************************
***************************** ADC Registers mask ***************************
******************************************************************************/
#define ADC_IDR_MASK    (0x03FFFFFFul)  /**< IDR mask                       */
#define ADC_CEDR_MASK	(0x80000001ul)  /**< CEDR mask                      */
#define ADC_SRR_MASK    (0x00000001ul)  /**< SRR mask                       */
#define ADC_CSR_MASK   	(0x00000003ul)  /**< CSR mask		           		*/
#define ADC_CCR_MASK    (0x00000001ul)  /**< CCR mask                	    */
#define ADC_CDR_MASK    (0x0000001Ful)  /**< CDR mask                	    */
#define ADC_MR_MASK     (0x0100070Ful)  /**< MR   mask         	            */
#define ADC_SR_MASK     (0x00000001ul)  /**< SR   mask                      */
#define ADC_IMSCR_MASK  (0x00000003ul)  /**< IMSCR mask                     */
#define ADC_RISR_MASK   (0x00000003ul)  /**< RISR mask                      */
#define ADC_MISR_MASK   (0x00000003ul)  /**< MISR mask                      */
#define ADC_ICR_MASK    (0x00000003ul)  /**< ICR mask                       */
#define ADC_CRR_MASK    (0x00000FFFul)  /**< CRR mask    	                */
#define ADC_GCCR_MASK   (0x00007FFFul)  /**< GCCR  mask                     */
#define ADC_OCCR_MASK   (0x00003FFFul)  /**< OCCR  mask                     */
#define ADC_DMACR_MASK  (0x00000001ul)  /**< DMACR mask                     */

/******************************************************************************
************************* ADC Registers reset value ************************
******************************************************************************/
#define ADC_IDR_RST    (0x0001001Ful)  /**< IDR reset value                  */
#define ADC_CEDR_RST   (0x00000000ul)  /**< CEDR reset value                 */
#define ADC_SRR_RST    (0x00000000ul)  /**< SRR reset value                  */
#define ADC_CSR_RST    (0x00000000ul)  /**< CSR reset value		     	     */
#define ADC_CCR_RST    (0x00000000ul)  /**< CCR reset value                  */
#define ADC_CDR_RST    (0x00000000ul)  /**< CCR reset value                  */
#define ADC_MR_RST     (0x00000000ul)  /**< MR   reset value         	     */
#define ADC_SR_RST     (0x00000000ul)  /**< SR   reset value                 */
#define ADC_IMSCR_RST  (0x00000000ul)  /**< IMSCR reset value                */
#define ADC_RISR_RST   (0x00000000ul)  /**< RISR reset value                 */
#define ADC_MISR_RST   (0x00000000ul)  /**< MISR reset value                 */
#define ADC_ICR_RST    (0x00000000ul)  /**< ICR reset value                  */
#define ADC_CRR_RST    (0x00000000ul)  /**< CRR reset value    	             */
#define ADC_GCCR_RST   (0x00000000ul)  /**< GCCR  reset value                */
#define ADC_OCCR_RST   (0x00000000ul)  /**< OCCR  reset value                */
#define ADC_DMACR_RST  (0x00000000ul)  /**< DMACR reset value                */

/******************************************************************************
********************* ADC External Functions Declaration ********************
******************************************************************************/
extern void CSP_ADCInit(CSP_ADC_T *adc, U8_T clockdiv, U8_T ch, U8_T trig);
extern void CSP_ADCStartConversion(CSP_ADC_T *adc);
extern U16_T CSP_ADCReadConversionData(CSP_ADC_T *adc);
extern void CSP_ADCClose(CSP_ADC_T *adc);
extern void CSP_ADCConfigInterrupt(CSP_ADC_T *adc, U32_T intMask_u32,\
                              FunctionalStatus newState);
#endif   /**< CSP_ADC_H */
