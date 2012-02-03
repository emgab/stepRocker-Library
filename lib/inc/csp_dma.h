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
* @file name	csp_dmac.h
* @description Definitions, Macros and function declarations for DMA
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_DMA_H
#define CSP_DMA_H
/******************************************************************************
************************** DMA Exported types *********************************
******************************************************************************/

typedef enum
{
	Software = 0x0 ,
	Hardware = 0x1
}eDMA_Trig;

typedef enum
{
	BYTE = 0x0,
	HALFWORD = 0x1,
	WORD = 0x2
}eDMA_DataSize;

typedef enum
{
	SingleService = 0x0,
	ContinuousService = 0x1
}eDMA_ServiceMode;

typedef enum
{
	SingleTransfer = 0x0,
	BurstTransfer = 0x1
}eDMA_TransferSize;

typedef enum
{
	Increment = 0x0,
	Fixed = 0x1
}eDMA_AddressControl;

typedef struct
{
	U8_T Channel;
	U32_T CurrentCount;
}sDMA_CurrentStatus;

typedef struct
{
	U8_T Channel;
	U32_T SrcAddress;
	eDMA_AddressControl SrcLowIncrement;
	eDMA_AddressControl SrcHighIncrement;
	U32_T DestAddress;
	eDMA_AddressControl DestLowIncrement;
	eDMA_AddressControl DestHighIncrement;
	eDMA_DataSize DataSize;
	eDMA_TransferSize TransferSize;
	U32_T LowTransferCount;
	U32_T HighTransferCount;
	FunctionalStatus Autoreload;
	eDMA_ServiceMode ServiceMode;
	eDMA_Trig Trigger;
	U16_T HardwareReq;
	FunctionalStatus LTCInterrupt;
	FunctionalStatus TCInterrupt;
}sDMA_Channel;

/******************************************************************************
* DMA Channel Structure
******************************************************************************/
typedef struct
{
   CSP_REGISTER_T ISR;  		/**< Channel Control Register               */
   CSP_REGISTER_T ISCR;         /**< Channel Mode Register                  */
   CSP_REGISTER_T IDR;          /**< Channel Clear Status Register          */
   CSP_REGISTER_T IDCR;         /**< Channel Status Register                */
   CSP_REGISTER_T CR;          	/**< Channel Interrupt Enable Register      */
   CSP_REGISTER_T SR;       	/**< Status Register		   				*/
   CSP_REGISTER_T CSR;        	/**< Current Source Register	    		*/
   CSP_REGISTER_T CDR;       	/**< Current Destination Register   		*/
   CSP_REGISTER_T MTR;         	/**< Channel Interrupt Disable Register     */
   CSP_REGISTER_T RSR;          /**< Channel Interrupt Mode Register        */
   CSP_REGISTER_T ReservedB[22];
}CSP_DMA_CHANNEL_T;

/******************************************************************************
* DMA Structure
******************************************************************************/
typedef struct
{
   CSP_DMA_CHANNEL_T 	CHANNEL[NB_DMA_CHANNEL];
   CSP_REGISTER_T 		ReservedA[(0x500 - 0x300)/4];
   CSP_REGISTER_T     	IDR;		/**< ID Register	         	   	*/
   CSP_REGISTER_T     	SRR;		/**< Software Reset Register        */
   CSP_REGISTER_T     	CESR;       /**< Channel Enable Status Register */
   CSP_REGISTER_T     	ISR; 		/**< Interrupt Status Register      */
   CSP_REGISTER_T     	ICR;        /**< Interrupt Clear Register       */
 }CSP_DMA_T, *CSP_DMA_PTR;

/*******************************************************************************
************************** DMA Registers Definition ****************************
*******************************************************************************/
/*******************************************************************************
*  ISRx : Initial Source Register
*******************************************************************************/
#define DMA_SADDR_MASK  	(0xFFFFFFFFul << 0)   		 /**< Source mask   */
#define DMA_SADDR(val)   	((val & 0xFFFFFFFFul) << 0)  /**< Writing Macro */

/** Set ISRx register                                                         */
#define CSP_DMA_SET_ISRX(dma, channel, val)                                \
                                         (dma->CHANNEL[channel].ISR = val)
/** Get ISRx register                                                         */
#define CSP_DMA_GET_ISRX(dmac, channel) (dmac->CHANNEL[channel].ISR)

/*******************************************************************************
*  ISCRx : Initial Source Control Register
*******************************************************************************/
#define DMA_LINC    	(0x01ul << 0)  			/**< Increment 			     */
#define DMA_HINC    	(0x01ul << 1)  			/**< Increment 			     */

/** Set ISCRx register */
#define CSP_DMA_SET_ISCRX(dmac, channel, val)                                \
                                         (dmac->CHANNEL[channel].ISCR = val)
/** Get ISCRx register */
#define CSP_DMA_GET_ISCRX(dmac, channel) (dmac->CHANNEL[channel].ISCR)

/*******************************************************************************
*  IDRx : Initial Destination Register
*******************************************************************************/
#define DMA_DADDR_MASK  	(0xFFFFFFFFul << 0)    /**< Destination mask     */
#define DMA_DADDR(val)   	((val & 0xFFFFFFFFul) << 0)   /**< Writing Macro */

/** Set IDRx register                                                         */
#define CSP_DMA_SET_IDRX(dmac, channel, val)                                \
                                        (dmac->CHANNEL[channel].IDR = val)
/** Get IDRx register                                                         */
#define CSP_DMA_GET_IDRX(dmac, channel) (dmac->CHANNEL[channel].IDR)

/*******************************************************************************
*  IDCRx : Initial Destination Control Register
*******************************************************************************/
#define    DMA_LINC    	(0x01ul << 0)  			/**< Increment 			     */
#define    DMA_HINC    	(0x01ul << 1)  			/**< Increment 			     */

/** Set IDCRx register                                                       */
#define CSP_DMA_SET_IDCRX(dmac, channel, val)                               \
                                         (dmac->CHANNEL[channel].IDCR = val)
/** Get IDCRx register                                                       */
#define CSP_DMA_GET_IDCRX(dmac, channel) (dmac->CHANNEL[channel].IDCR)

/*******************************************************************************
*  CRx : Control Register
*******************************************************************************/
#define	DMA_LTC_MASK  	(0xFFFul << 0)    		/**< Low TC mask     		 */
#define DMA_LTC(val)   	((val & 0xFFFul) << 0)	/**< Writing Macro 			 */
#define	DMA_HTC_MASK  	(0xFFFul << 12)    		/**< High TC mask	     	 */
#define DMA_HTC(val)   	((val & 0xFFFul) << 12)	/**< Writing Macro 			 */
#define	DMA_DSIZE_MASK 	(0x3ul << 24)   		/**< Destination mask     	 */
#define DMA_DSIZE(val) 	((val & 0x3ul) << 24) 	/**< Writing Macro    		 */

#define DMA_RELOAD    	(0x01ul << 26)  		/**< Reload      	     	 */
#define DMA_SMODE       (0x01ul << 27)  		/**< Service Mode 	    	 */
#define DMA_TSIZE       (0x01ul << 28)  		/**< Transfer Size 	     	 */
#define DMA_LTCINT      (0x01ul << 29)  		/**< Interrupt Enable/Disable*/
#define DMA_TCINT       (0x01ul << 30)  		/**< Interrupt Enable/Disable*/

/** Set CRx register */
#define CSP_DMA_SET_CRX(dmac, channel, val)                                \
                                       (dmac->CHANNEL[channel].CR = val)
/** Get CRx register */
#define CSP_DMA_GET_CRX(dmac, channel) (dmac->CHANNEL[channel].CR)

/******************************************************************************
*  SRx : Status Register
*******************************************************************************/
#define DMA_CURR_LTC_MASK 	(0xFFFul << 0) 	/**<Current Transfer Count Value*/
#define DMA_CURR_LTC(val) 	((val & 0xFFFul) << 0) 	/**< Writing macro      */
#define DMA_CURR_HTC_MASK 	(0xFFFul << 12) /**<Current Transfer Count Value*/
#define DMA_CURR_HTC(val) 	((val & 0xFFFul) << 12) /**< Writing macro      */
#define DMA_LTCST			(0x01ul << 31)         	/**< LTC BUSY Status 	*/
#define DMA_BUSY			(0x01ul << 31)         	/**< LTC BUSY Status 	*/

/** Get SR register (Status) */
#define CSP_DMA_GET_SRX(dmac,channel)		(dmac->CHANNEL[channel].SR)

/****************************************************************************
*  CSRx : Current Source Register
*****************************************************************************/
#define DMA_CURR_SADDR_MASK   (0xFFFFFFFFul << 0) /**<Current Source        */

/** Get CSR register (Status) */
#define CSP_DMA_GET_CSRX(dmac,channel)	 	(dmac->CHANNEL[channel].CSR)

/****************************************************************************
*  CDRx : Current Destination Register
*****************************************************************************/
#define DMA_CURR_DADDR_MASK   (0xFFFFFFFFul << 0) /**<Current Destination   */

/** Get CDR register (Status) */
#define CSP_DMA_GET_CDRX(dmac,channel)	 	(dmac->CHANNEL[channel].CDR)

/*******************************************************************************
*  MTRx : Mask Trigger Register
*******************************************************************************/
#define DMA_SWTRIG         (0x01ul << 0)  /**< Software Request Trigger */
#define DMA_CHEN           (0x01ul << 1)  /**< Channel ON/OFF           */
#define DMA_STOP           (0x01ul << 2)  /**< DMA Stop      	    	*/

/** Set MTRx register */
#define CSP_DMA_SET_MTRX(dmac, channel, val)                                \
                                        (dmac->CHANNEL[channel].MTR = val)
/** Get MTRx register */
#define CSP_DMA_GET_MTRX(dmac, channel) (dmac->CHANNEL[channel].MTR)

/*******************************************************************************
*  RSRx : Request Selection Register
*******************************************************************************/
#define DMA_REQ         (0x01ul << 0)  			/**< Software Request Trigger */
#define	DMA_HWSRC_MASK	(0x1Ful << 1)    		/**< Destination mask    	  */
#define DMA_HWSRC(val)  ((val & 0x1Ful) << 1) 	/**< Writing Macro    		  */

#define DMA_USART0_TX		((U8_T)0x00)
#define DMA_USART0_RX		((U8_T)0x01)
#define DMA_USART1_TX		((U8_T)0x02)
#define DMA_USART1_RX		((U8_T)0x03)
#define DMA_USART2_TX		((U8_T)0x04)
#define DMA_USART2_RX		((U8_T)0x05)
#define DMA_SSP0_TX			((U8_T)0x0A)
#define DMA_SSP0_RX			((U8_T)0x0B)
#define DMA_SSP1_TX			((U8_T)0x0C)
#define DMA_SSP1_RX			((U8_T)0x0D)
#define DMA_I2C0_TX			((U8_T)0x12)
#define DMA_I2C0_RX			((U8_T)0x13)
#define DMA_I2C1_TX			((U8_T)0x14)
#define DMA_I2C1_RX			((U8_T)0x15)
#define DMA_ADC				((U8_T)0x16)
#define DMA_USBEP1			((U8_T)0x1A)
#define DMA_USBEP2			((U8_T)0x1B)
#define DMA_USBEP3			((U8_T)0x1C)
#define DMA_USBEP4			((U8_T)0x1D)

/** Set RSRx register                                                         */
#define CSP_DMA_SET_RSRX(dmac, channel, val)                                \
                                        (dmac->CHANNEL[channel].RSR = val)
/** Get RSRx register                                                         */
#define CSP_DMA_GET_RSRX(dmac, channel) (dmac->CHANNEL[channel].RSR)

/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define DMA_IDCODE_MASK (0x03FFFFFFul << 0)    /**< DMAC IPIDCODE mask     */
#define DMA_IDCODE		(0x00000000 << 0)    /**< DMAC IPIDCODE mask     */

/** Get IDR register                                                         */
#define CSP_DMA_GET_IDR(dmac)      	((dmac)->IDR)
/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define DMA_SWRST	(0x01ul << 0)         /**< Software Reset         */

/** Set SRR register 		                                             */
#define CSP_DMA_SET_SRR(dmac, val)	((dmac)->SRR = (val))
/** Get SRR register                                               	     */
#define CSP_DMA_GET_SRR(dmac)       ((dmac)->SRR)

/******************************************************************************
* CESR : Channel Enable Status Register
******************************************************************************/
#define DMA_CH0EN	(0x01ul << 0)         /**< dmac channel 0 enable */
#define DMA_CH1EN   (0x01ul << 1)         /**< dmac channel 0 enable */
#define DMA_CH2EN   (0x01ul << 2)         /**< dmac channel 0 enable */
#define DMA_CH3EN   (0x01ul << 3)         /**< dmac channel 0 enable */
#define DMA_CH4EN   (0x01ul << 4)         /**< dmac channel 0 enable */
#define DMA_CH5EN   (0x01ul << 5)         /**< dmac channel 0 enable */
#define DMA_CH(val) (0x01ul << val)

typedef enum {
	DMA_CH0 = DMA_CH0EN,
	DMA_CH1 = DMA_CH1EN,
	DMA_CH2 = DMA_CH2EN,
	DMA_CH3 = DMA_CH3EN,
	DMA_CH4 = DMA_CH4EN,
	DMA_CH5 = DMA_CH5EN
 } eDMA_CHx;

/** Get CESR register                                               */
 #define CSP_DMA_GET_CESR(dmac)        ((dmac)->CESR)

/*****************************************************************************
* ISR : Interrupt Status Register
******************************************************************************/
#define DMA_CH0_LTC	(0x01ul << 0)       /**< Channel 0 interrupt         */
#define DMA_CH1_LTC (0x01ul << 1)       /**< Channel 1 interrupt         */
#define DMA_CH2_LTC (0x01ul << 2)       /**< Channel 2 interrupt         */
#define DMA_CH3_LTC (0x01ul << 3)       /**< Channel 3 interrupt         */
#define DMA_CH4_LTC (0x01ul << 4)       /**< Channel 4 interrupt         */
#define DMA_CH5_LTC (0x01ul << 5)       /**< Channel 5 interrupt         */

#define DMA_CH0_TC	(0x01ul << 16)       /**< Channel 0 interrupt         */
#define DMA_CH1_TC 	(0x01ul << 17)       /**< Channel 1 interrupt         */
#define DMA_CH2_TC 	(0x01ul << 18)       /**< Channel 2 interrupt         */
#define DMA_CH3_TC 	(0x01ul << 19)       /**< Channel 3 interrupt         */
#define DMA_CH4_TC 	(0x01ul << 20)       /**< Channel 4 interrupt         */
#define DMA_CH5_TC 	(0x01ul << 21)       /**< Channel 5 interrupt         */

/** Get ISR register (Status) */
#define CSP_DMA_GET_ISR(dmac)          (dmac->ISR)
/*****************************************************************************
* ICR : Interrupt Clear Register
******************************************************************************/
#define DMA_CH0_IT	(0x01ul << 0)       /**< Channel 0 interrupt         */
#define DMA_CH1_IT	(0x01ul << 1)       /**< Channel 1 interrupt         */
#define DMA_CH2_IT  (0x01ul << 2)       /**< Channel 2 interrupt         */
#define DMA_CH3_IT 	(0x01ul << 3)       /**< Channel 3 interrupt         */
#define DMA_CH4_IT 	(0x01ul << 4)       /**< Channel 4 interrupt         */
#define DMA_CH5_IT	(0x01ul << 5)       /**< Channel 5 interrupt         */

 /** Set ICR register */
 #define CSP_DMA_SET_ICR(dmac, val)    ((dmac)->ICR = (val))

/****************************************************************************
***************************** DMA Registers mask ****************************
*****************************************************************************/
#define DMA_ISRX_MASK    (0xFFFFFFFFul)               /**< ISRx mask        */
#define DMA_ISCRX_MASK   (0x00000003ul)               /**< ISCRx mask       */
#define DMA_IDRX_MASK    (0xFFFFFFFFul)               /**< IDRx mask        */
#define DMA_IDCRX_MASK   (0x00000003ul)               /**< IDCRx mask       */
#define DMA_CRX_MASK     (0x7FFFFFFFul)               /**< CRx mask         */
#define DMA_SRX_MASK     (0x80FFFFFFul)               /**< SR mask          */
#define DMA_CSRX_MASK    (0xFFFFFFFFul)               /**< CSR mask         */
#define DMA_CDRX_MASK    (0xFFFFFFFFul)               /**< CDR mask         */
#define DMA_MTRX_MASK    (0x00000007ul)               /**< MTRx mask        */
#define DMA_RSRX_MASK    (0x0000003Ful)               /**< RSRx mask        */
#define DMA_IDR_MASK     (0x03FFFFFFul)               /**< IDR mask         */
#define DMA_SRR_MASK     (0x00000001ul)               /**< SRR mask         */
#define DMA_CESR_MASK    (0x0000003Ful)               /**< CESR mask        */
#define DMA_ISR_MASK     (0x003F003Ful)               /**< ISR mask         */
#define DMA_ICR_MASK     (0x0000003Ful)               /**< ICR mask         */

/****************************************************************************
************************* DMA Registers reset value *************************
*****************************************************************************/
#define DMA_ISRX_RST    (0x00000000ul)               /**< ISRx reset value  */
#define DMA_ISCRX_RST   (0x00000000ul)               /**< ISCRx reset value */
#define DMA_IDRX_RST    (0x00000000ul)               /**< IDRx reset value  */
#define DMA_IDCRX_RST   (0x00000000ul)               /**< IDCRx reset value */
#define DMA_CRX_RST     (0x00000000ul)               /**< CRx reset value   */
#define DMA_SRX_RST     (0x00000000ul)               /**< SR reset value    */
#define DMA_CSRX_RST    (0x00000000ul)               /**< CSR reset value   */
#define DMA_CDRX_RST    (0x00000000ul)               /**< CDR reset value   */
#define DMA_MTRX_RST    (0x00000000ul)               /**< MTRx reset value  */
#define DMA_RSRX_RST    (0x00000000ul)               /**< RSRx reset value  */
#define DMA_IDR_RST     (0x00620018ul)               /**< IDR reset value   */
#define DMA_SRR_RST     (0x00000000ul)               /**< SRR reset value   */
#define DMA_CESR_RST    (0x00000000ul)               /**< CESR reset value  */
#define DMA_ISR_RST     (0x00000000ul)               /**< ISR reset value   */
#define DMA_ICR_RST     (0x00000000ul)               /**< ICR reset value   */

/****************************************************************************
********************* DMA External Functions Declaration ********************
*****************************************************************************/
extern void CSP_DMAReset(void);
extern void CSP_DMAEnableChannel( U8_T ch);
extern void CSP_DMADisableChannel( U8_T ch);
extern void CSP_DMADestAddressControl(U8_T ch,eDMA_AddressControl high_inc,\
									eDMA_AddressControl low_inc);
extern void CSP_DMASrcAddressControl(U8_T ch,eDMA_AddressControl high_inc, \
									eDMA_AddressControl low_inc);
extern void CSP_DMADataSizeConfiguration(U8_T ch,eDMA_DataSize value);
extern void CSP_DMATransferCountConfiguration(U8_T ch,U16_T high_tc, U16_T low_tc);
extern void CSP_DMAAutoReload(U8_T ch,FunctionalStatus newState);
extern void CSP_DMAServiceModeConfiguration(U8_T ch, eDMA_ServiceMode mode);
extern void CSP_DMATransferSizeConfiguration(U8_T ch, eDMA_TransferSize unit);
extern void CSP_DMATriggerTypeConfiguration(U8_T ch, eDMA_Trig type);
extern void CSP_DMAHardwareTrigConfiguration(U8_T ch,U8_T Hwsrc);
extern void CSP_DMAConfigChannelInterrupt(U8_T ch, FunctionalStatus tc_int,\
											FunctionalStatus ltc_int);
extern void CSP_DMAStructInit(sDMA_Channel* DMAInitStruct);
extern void CSP_DMAChannelStructInit(sDMA_Channel* DMAInitStruct);
extern void CSP_DMAChannelInit( U8_T ch, U32_T srcAddress_u32, U32_T destAddress_u32,\
		eDMA_AddressControl Src_HighIncrement,eDMA_AddressControl Src_LowIncrement,\
		eDMA_AddressControl Dest_HighIncrement,eDMA_AddressControl Dest_LowIncrement,\
		eDMA_DataSize datasize, U32_T high_count , U32_T low_count ,\
		eDMA_TransferSize transfersize,\
		FunctionalStatus autorelad,	eDMA_ServiceMode servicemode,\
		eDMA_Trig trigtype, U16_T hwreq,\
		FunctionalStatus tc_interrupt,FunctionalStatus ltc_interrupt);
extern void CSP_DMAStart(U8_T ch);
extern ITStatus CSP_DMAGetITStatus(U32_T InterruptStatus);
extern FunctionalStatus CSP_DMAGetChannelEnableStatus(U8_T ch);
extern FlagStatus CSP_DMAGetFlagStatus(U8_T ch, U32_T Flag);
extern U32_T CSP_DMAGetCurrSrcAddress(U8_T ch);
extern U32_T CSP_DMAGetCurrDesAddress(U8_T ch);
extern U32_T CSP_DMAGetCurrLowTransferCounnt(U8_T ch);
extern U32_T CSP_DMAGetCurrHighTransferCounnt(U8_T ch);
extern void CSP_DMAClearStop(U8_T ch);
extern FlagStatus CSP_DMAGetSWTrig(U8_T ch);

#endif   /* CSP_DMA_H */
