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
* @file name	csp_ssp.h
* @description Definitions, Macros and function declarations for SSP
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.  MCU Solution Part	Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef _CSP_SSP_H_
#define _CSP_SSP_H_

/******************************************************************************
************************* SPI(SPP) Structure Definition ****************************
******************************************************************************/

/******************************************************************************
@brief SPI(SPP) Structure
******************************************************************************/
typedef struct
{
	CSP_REGISTER_T  CR0;		/**< Control Register 0 					*/
	CSP_REGISTER_T  CR1;		/**< Control Register 1 					*/
	CSP_REGISTER_T  DR;			/**< Receive FIFO(read) and
								transmit FIFO data register(write) 			*/
	CSP_REGISTER_T  SR;			/**< Status register 						*/
	CSP_REGISTER_T  CPSR;		/**< Clock prescale register 				*/
	CSP_REGISTER_T  IMSCR;		/**< Interrupt mask set and clear register 	*/
	CSP_REGISTER_T  RISR;		/**< Raw interrupt status register 			*/
	CSP_REGISTER_T  MISR;		/**< Masked interrupt status register 		*/
	CSP_REGISTER_T  ICR;		/**< Interrupt clear register 				*/
  	CSP_REGISTER_T  DMACR;		/**< DMA control register 					*/
} CSP_SSP_T, *CSP_SSP_PTR;

/*******************************************************************************
**************************  SSP REGISTERS DEFINITION   *************************
*******************************************************************************/

/*******************************************************************************
* SSPCR0 : Control Register 0
*******************************************************************************/
#define SSP_DSS(val)	(((val) & 0x0Ful) << 0)	/**< Data Size Select */
#define SSP_DSS_4BIT	(0x03ul << 0)			/**< Data Size 4Bit Select */
#define SSP_DSS_5BIT	(0x04ul << 0)			/**< Data Size 5Bit Select */
#define SSP_DSS_6BIT	(0x05ul << 0)			/**< Data Size 6Bit Select */
#define SSP_DSS_7BIT	(0x06ul << 0)			/**< Data Size 7Bit Select */
#define SSP_DSS_8BIT	(0x07ul << 0)			/**< Data Size 8Bit Select */
#define SSP_DSS_9BIT	(0x08ul << 0)			/**< Data Size 9Bit Select */
#define SSP_DSS_10BIT	(0x09ul << 0)			/**< Data Size 10Bit Select */
#define SSP_DSS_11BIT	(0x0Aul << 0)			/**< Data Size 11Bit Select */
#define SSP_DSS_12BIT	(0x0Bul << 0)			/**< Data Size 12Bit Select */
#define SSP_DSS_13BIT	(0x0Cul << 0)			/**< Data Size 13Bit Select */
#define SSP_DSS_14BIT	(0x0Dul << 0)			/**< Data Size 14Bit Select */
#define SSP_DSS_15BIT	(0x0Eul << 0)			/**< Data Size 15Bit Select */
#define SSP_DSS_16BIT	(0x0Ful << 0)			/**< Data Size 16Bit Select */

#define SSP_FRF(val)	(((val) & 0x03ul) << 4)	/**< Frame Format */
#define SSP_SPO  	   	(0x01ul << 6)			/**< SSPCLK Polarity */
#define SSP_SPH  	    (0x01ul << 7)			/**< SSPCLK Phase */
#define SSP_SCR(val)	(((val) & 0x0FFul) << 8)	/**< Serial Clock Rate */

/*******************************************************************************
* SSPCR1 : Control Register 1
*******************************************************************************/
#define SSP_LBM  	    (0x01ul << 0)		/**< Loopback mode */
#define SSP_SSE  	    (0x01ul << 1)		/**< Synchronous Serial Port Enable */
#define SSP_MS 	 	    (0x01ul << 2)		/**< Master or Slave Mode Select */
#define SSP_SOD  	    (0x01ul << 3)		/**< Slave Mode Output Disable */
#define SSP_RXIFLSELFRF(val)    (((val) & 0x07ul) << 4)
						/**< Receive interrupt FIFO level select */

/*******************************************************************************
* SSPDR : Data Register
*******************************************************************************/
#define SSP_DATA(val)	(((val) & 0x0FFFF) << 0)	/**< Transmit/Receive FIFO */

/*******************************************************************************
* SSPSR : Status Register
*******************************************************************************/
#define SSP_TFE  	    (0x01ul << 0)		/**< Transmit FIFO Empty */
#define SSP_TNF  	    (0x01ul << 1)		/**< Transmit FIFO Full */
#define SSP_RNE 	 	(0x01ul << 2)		/**< Receive is not Empty */
#define SSP_RFF 	 	(0x01ul << 3)		/**< Receive FIFO Full */
#define SSP_BSY	 	    (0x01ul << 4)		/**< PrimeCell SSP Busy Flag */

/*******************************************************************************
* SSPCPSR : Clock prescale register
*******************************************************************************/
#define SSP_CPSDVSR(val) (((val) & 0x0FF) << 0)	/**< Clock Prescale Devisor */

/*******************************************************************************
* SSPIMSC : Interrupt mask set and clear register
*******************************************************************************/
#define SSP_RORIM  	(0x01ul << 0)		/**< Receive Overrun Interrupt Mask */
#define SSP_RTIM  	(0x01ul << 1)		/**< Receive Timeout Interrupt Mask */
#define SSP_RXIM 	(0x01ul << 2)		/**< Receive FIFO Interrupt Mask */
#define SSP_TXIM 	(0x01ul << 3)		/**< Transmit FIFO interrupt Mask */

/*******************************************************************************
* SSPRIS : Raw interrupt status register
*******************************************************************************/
#define SSP_RORRIS 	(0x01ul << 0)
			/**< Gives the Raw Interrupt Status of the SSPRORINTR Interrupt */
#define SSP_RTRIS   (0x01ul << 1)
			/**< Gives the raw interrupt state of the SSPRTINTR interrupt */
#define SSP_RXRIS 	(0x01ul << 2)
			/**< Gives the raw interrupt state of the SSPRXINTR interrupt  */
#define SSP_TXRIS	(0x01ul << 3)
			/**< Gives the raw interrupt state of the SSPTXINTR interrupt  */

/*******************************************************************************
* SSPMIS : Masked interrupt status register
*******************************************************************************/
#define SSP_RORRIS  (0x01ul << 0)
/**<Gives the receive over run masked interrupt status of SSPRORINTR interrupt*/
#define SSP_RTRIS  	(0x01ul << 1)
/**<Gives the receive timeout masked interrupt state of SSPRTINTR interrupt */
#define SSP_RXRIS 	(0x01ul << 2)
/**<Gives the receive FIFO masked interrupt state of SSPRXINTR interrupt */
#define SSP_TXRIS	(0x01ul << 3)
/**<Gives the transmit FIFO masked interrupt state of SSPTXINTR interrupt */

/*******************************************************************************
* SSPICR : Interrupt clear register
*******************************************************************************/
#define SSP_RORIC 	(0x01ul << 0)		/**< Clears the SSPRORINTR interrupt */
#define SSP_RTIC  	(0x01ul << 1)		/**< Clears the SSPRTINTR interrupt */

/*******************************************************************************
* DMACR : DMA control register
*******************************************************************************/
#define SSP_RXDMAE 	(0x01ul << 0)		/**< Clears the SSPRORINTR interrupt */
#define SSP_TXDMAE  (0x01ul << 1)		/**< Clears the SSPRTINTR interrupt */

/*******************************************************************************
***************************** SSP REGISTER MASK  *******************************
*******************************************************************************/
#define SSP_CR0_MASK 	(0x0000FFFFul)  /**< Control Register 0 mask */
#define SSP_CR1_MASK 	(0x0000007Ful)  /**< Control Register 1 mask */
#define SSP_DR_MASK 	(0x0000FFFFul)
			/**< Receive FIFO(read) and transmit FIFO data register(write) mask */
#define SSP_SR_MASK    	(0x0000001Ful)  /**< Status register  mask */
#define SSP_CPSR_MASK 	(0x000000FFul)  /**< Clock prescale register mask */
#define SSP_IMSCR_MASK	(0x0000000Ful)
			/**< Interrupt mask set and clear register mask */
#define SSP_RISR_MASK 	(0x0000000Ful)  /**< Raw interrupt status register mask*/
#define SSP_MISR_MASK 	(0x0000000Ful)
			/**< Masked interrupt status register mask */
#define SSP_ICR_MASK 	(0x00000003ul)  /**< Interrupt clear register mask */

/*******************************************************************************
************************* SSP REGISTER RESET VALUE  ****************************
*******************************************************************************/
#define SSP_CR0_RST 	(0x00000000ul) /**< Control Register 0 reset value */
#define SSP_CR1_RST 	(0x00000010ul) /**< Control Register 1 reset value */
#define SSP_DR_RST		(0x00000000ul)
	/**< Receive FIFO(read) and transmit FIFO data register(write) reset value */
#define SSP_SR_RST		(0x00000003ul)  /**< Status register  reset value */
#define SSP_CPSR_RST	(0x00000000ul)
							/**< Clock prescale register reset value */
#define SSP_IMSCR_RST 	(0x00000000ul)
							/**< Interrupt mask set and clear register reset value */
#define SSP_RISR_RST 	(0x00000008ul)
							/**< Raw interrupt status register reset value*/
#define SSP_MISR_RST 	(0x00000000ul)
							 /**< Masked interrupt status register reset value */
#define SSP_ICR_RST 	(0x00000000ul)
							/**< Interrupt clear register reset value */
#define SSP_DMACR_RST 	(0x00000000ul)
							/**< DMA control register reset value */

/*******************************************************************************
*****************************  SSP MACROS DEFINITION  **************************
*******************************************************************************/
/** Set CR0 register */
#define CSP_SSP_SET_CR0(ssp, val)	((ssp)->CR0 = (val & 0x0000FFFFul))

/** Get CR0 register */
#define CSP_SSP_GET_CR0(ssp)		((ssp)->CR0)

/** Set CR1 register */
#define CSP_SSP_SET_CR1(ssp, val)	((ssp)->CR1 = (val & 0x0000007Ful))

/** Get CR1 register */
#define CSP_SSP_GET_CR1(ssp)		((ssp)->CR1)

/** Set DR register */
#define CSP_SSP_SET_DR(ssp, val)	((ssp)->DR = (val))

/** Get DR register */
#define CSP_SSP_GET_DR(ssp)			((ssp)->DR)

/** Get SR register */
#define CSP_SSP_GET_SR(ssp)			((ssp)->SR)

/** Set CPSR register */
#define CSP_SSP_SET_CPSR(ssp, val)	((ssp)->CPSR = (val & 0x000000FFul))

/** Get CPSR register */
#define CSP_SSP_GET_CPSR(ssp)		((ssp)->CPSR)

/** Set IMSC register */
#define CSP_SSP_SET_IMSCR(ssp, val)	((ssp)->IMSCR = (val & 0x0000000Ful))

/** Get IMSC register */
#define CSP_SSP_GET_IMSCR(ssp)		((ssp)->IMSCR)

/** Get RIS register */
#define CSP_SSP_GET_RISR(ssp)		((ssp)->RISR)

/** Get MIS register */
#define CSP_SSP_GET_MISR(ssp)		((ssp)->MISR)

/** Set ICR register */
#define CSP_SSP_SET_ICR(ssp, val)	((ssp)->ICR = (val & 0x00000003ul))

/** Set DMACR register */
#define CSP_SSP_SET_DMACR(ssp, val)	((ssp)->DMACR = (val))


/*********************************************************************************
********************* SSP External Functions Declaration *************************
*********************************************************************************/
extern void CSP_SSPPinConfiguration(CSP_SSP_T *const ssp);
extern void CSP_SSPInit(CSP_SSP_T *const ssp, U32_T datasize,
						U32_T serialClock, U32_T prescaleDivisor, U32_T master);
extern void CSP_SSPTransmit(CSP_SSP_T *const  ssp,U16_T sspString);
extern U16_T CSP_SSPReceive(CSP_SSP_T *const ssp);
extern void CSP_SSPEnable(CSP_SSP_T *const ssp);
extern void CSP_SSPDisable(CSP_SSP_T *const ssp);

#endif /* _CSP_SSP_H_ */
