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
* @file name	csp_dmac.c
* @description Definitions, Macros and function declarations for DMA
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			     Creation
* |0.1 MOD 2010.02.01.   Ys OH               Enable CSP_DMAGetFlagStatus
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

/******************************************************************************
* Include Files
******************************************************************************/
#include "csp.h"

sDMA_CurrentStatus GetSR;
sDMA_Channel StructInit;
/******************************************************************************
****************************  F U N C T I O N S  ******************************
******************************************************************************/
/******************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*****************************************************************************/
void CSP_DMAReset(void)
{
   /* Software Reset */
   CSP_DMA_SET_SRR(DMA0,DMA_SWRST);
}

/******************************************************************************
* @brief     Enable a DMAC channel.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @param     channel_u8
* \n          input
* \n          brief description - Channel to be enabled.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMAEnableChannel( U8_T ch)
{
   	/* Enable Channel */
	CSP_DMA_SET_MTRX(DMA0, ch, CSP_DMA_GET_MTRX(DMA0, ch)|DMA_CHEN);
}

/******************************************************************************
* @brief     Disable a DMAC channel.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @param     channel_u8
* \n          input
* \n          brief description - Channel to be disabled.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMADisableChannel( U8_T ch)
{
   /* Disable Channel */
   CSP_DMA_SET_MTRX(DMA0, ch,(CSP_DMA_GET_MTRX(DMA0,ch)& ~DMA_CHEN));
}

/******************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMAAddressConfiguration(U8_T ch,U32_T src_addr, U32_T des_addr)
{
   /* Source Address */
   CSP_DMA_SET_ISRX(DMA0, ch, src_addr);

   /* Destination Address */
   CSP_DMA_SET_IDRX(DMA0,ch, des_addr);
}

/******************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMASrcAddressControl(U8_T ch,eDMA_AddressControl high_inc, eDMA_AddressControl low_inc)
{
	U32_T temp = 0;

	temp = CSP_DMA_GET_ISCRX(DMA0, ch);
	if(high_inc == Fixed)
	{
		/* Source Address */
		CSP_DMA_SET_ISCRX(DMA0,ch, temp | DMA_HINC);
	}
	else
	{
		CSP_DMA_SET_ISCRX(DMA0,ch, temp & ~DMA_HINC);
	}

	temp = CSP_DMA_GET_ISCRX(DMA0, ch);
	if(low_inc == Fixed)
	{
		/* Source Address */
		CSP_DMA_SET_ISCRX(DMA0,ch, temp | DMA_LINC);
	}
	else
	{
		CSP_DMA_SET_ISCRX(DMA0,ch, temp & ~DMA_LINC);
	}
}

/*****************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMADestAddressControl(U8_T ch,eDMA_AddressControl high_inc, eDMA_AddressControl low_inc)
{
	U32_T temp = 0;

	temp = CSP_DMA_GET_IDCRX(DMA0, ch);
	if(high_inc == Fixed)
	{
		/* Source Address */
		CSP_DMA_SET_IDCRX(DMA0,ch, temp | DMA_HINC);
	}
	else
	{
		CSP_DMA_SET_IDCRX(DMA0,ch, temp & ~DMA_HINC);
	}

	temp = CSP_DMA_GET_IDCRX(DMA0,ch);
	if(low_inc == Fixed)
	{
		/* Source Address */
		CSP_DMA_SET_IDCRX(DMA0,ch, temp | DMA_LINC);
	}
	else
	{
		CSP_DMA_SET_IDCRX(DMA0,ch, temp & ~DMA_LINC);
	}
}

/******************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMADataSizeConfiguration(U8_T ch,eDMA_DataSize value)
{
	U32_T temp =0;
	temp = CSP_DMA_GET_CRX(DMA0, ch) & ~DMA_DSIZE_MASK;
	/* Data Size Setting*/
	CSP_DMA_SET_CRX(DMA0, ch, temp | DMA_DSIZE(value));
}

/******************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMATransferCountConfiguration(U8_T ch,U16_T high_tc, U16_T low_tc)
{
	U32_T temp =0;
	temp = CSP_DMA_GET_CRX(DMA0, ch) & ~(DMA_HTC_MASK|DMA_LTC_MASK);

	/* Data Size Setting*/
	CSP_DMA_SET_CRX(DMA0, ch, temp | DMA_HTC(high_tc)|DMA_LTC(low_tc));
}

/******************************************************************************
* @brief     Reload(auto) Enable/Disable
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMAAutoReload(U8_T ch,FunctionalStatus newState)
{
	if(newState == ENABLE)
	{
		CSP_DMA_SET_CRX(DMA0,ch,  CSP_DMA_GET_CRX(DMA0, ch) & ~DMA_RELOAD);
	}
	if(newState == DISABLE)
	{
		/* DAM channel is turn off when CURR_TC = 0. AutoReload is disabled.*/
		CSP_DMA_SET_CRX(DMA0,ch, CSP_DMA_GET_CRX(DMA0, ch)| DMA_RELOAD);
	}
}

/*****************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*****************************************************************************/
void CSP_DMAServiceModeConfiguration(U8_T ch, eDMA_ServiceMode mode)
{
	if(mode == SingleService)
	{
		/* Data Size Setting*/
		CSP_DMA_SET_CRX(DMA0,ch, CSP_DMA_GET_CRX(DMA0, ch) & ~DMA_SMODE);
	}
	if(mode == ContinuousService)
	{
		/* Data Size Setting*/
		CSP_DMA_SET_CRX(DMA0,ch, CSP_DMA_GET_CRX(DMA0, ch)|DMA_SMODE);
	}
}

/*****************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*****************************************************************************/
void CSP_DMATransferSizeConfiguration(U8_T ch, eDMA_TransferSize unit)
{
	if(unit == SingleTransfer)
	{
		/* Data Size Setting*/
		CSP_DMA_SET_CRX(DMA0,ch, CSP_DMA_GET_CRX(DMA0, ch) & ~DMA_TSIZE);
	}
	if(unit == BurstTransfer)
	{
		/* Data Size Setting*/
		CSP_DMA_SET_CRX(DMA0,ch, CSP_DMA_GET_CRX(DMA0, ch)|DMA_TSIZE);
	}
}

/******************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMATriggerTypeConfiguration(U8_T ch, eDMA_Trig type)
{
	if(type == Software)
	{
		/* Software Trigger Setting*/
		CSP_DMA_SET_RSRX(DMA0,ch, CSP_DMA_GET_RSRX(DMA0, ch) & ~DMA_REQ);
	}
	if(type == Hardware)
	{
		/* Hardware Trigger Setting*/
		CSP_DMA_SET_RSRX(DMA0,ch, CSP_DMA_GET_RSRX(DMA0, ch)|DMA_REQ);
	}
}

/*****************************************************************************
* @brief     Reset registers and state machines.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMAHardwareTrigConfiguration(U8_T ch,U8_T Hwsrc)
{
	U32_T temp =0;
	temp = CSP_DMA_GET_RSRX(DMA0, ch) & ~DMA_HWSRC_MASK;

	/* Hardware Trigger Source Selection*/
	CSP_DMA_SET_RSRX(DMA0, ch, temp | DMA_HWSRC(Hwsrc));
}
/******************************************************************************
* @brief     Configure channel interrupt.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @param     channel_u8
* \n          input
* \n          brief description - channel whitch will be configured.
* @param     intChannelMask_u32
* \n          input
* \n          brief description - Configure which interrupt bits are activated
*                                 for the channel.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMAConfigChannelInterrupt(U8_T ch, FunctionalStatus tc_int, FunctionalStatus ltc_int)
{
	if (tc_int == DISABLE)
	{
		/* Disable interrupt */
		CSP_DMA_SET_CRX(DMA0, ch, (CSP_DMA_GET_CRX(DMA0, ch) & ~DMA_TCINT));

	}
	else
	{
		/* Enable interrupt */
		CSP_DMA_SET_CRX(DMA0, ch, (CSP_DMA_GET_CRX(DMA0, ch) |DMA_TCINT));
	}

	if (ltc_int == DISABLE)
	{
		/* Disable interrupt */
		CSP_DMA_SET_CRX(DMA0, ch, (CSP_DMA_GET_CRX(DMA0, ch) & ~DMA_LTCINT));

	}
	else
	{
		/* Enable interrupt */
		CSP_DMA_SET_CRX(DMA0, ch, (CSP_DMA_GET_CRX(DMA0, ch) |DMA_LTCINT));
	}
}
/******************************************************************************
* @brief     CSP_DMACStructInit: Fills each member of structure with default value
* @return    None
* @param     DMAC_ChannelTypeDef
* \n         input
* \n         brief description - pointer to a DMAC_ChannelTypeDef
* @pre       None
* @post      None
* @todo      Nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMAStructInit(sDMA_Channel* DMAInitStruct)
{
	DMAInitStruct->Channel = 0;
	DMAInitStruct->SrcAddress = 0x20001000;
	DMAInitStruct->SrcLowIncrement = Increment;
	DMAInitStruct->SrcHighIncrement = Fixed;
	DMAInitStruct->DestAddress = 0x20002000;
	DMAInitStruct->DestLowIncrement = Increment;
	DMAInitStruct->DestHighIncrement = Fixed;
	DMAInitStruct->DataSize = BYTE;
	DMAInitStruct->TransferSize = SingleTransfer;
	DMAInitStruct->LowTransferCount = 10;
	DMAInitStruct->HighTransferCount = 1;
	DMAInitStruct->Autoreload = DISABLE;
	DMAInitStruct->ServiceMode = SingleService;
	DMAInitStruct->Trigger = Software;
	DMAInitStruct->HardwareReq = NULL;
	DMAInitStruct->TCInterrupt = DISABLE;
	DMAInitStruct->LTCInterrupt = DISABLE;
}
/******************************************************************************
* @brief     CSP_DMAChannelInit: Configure each channel with given structure
* @return    None
* @param     CSP_DMAC_T
* \n         input
* \n         pointer to a CSP_DMAC_T
* @param     DMAC_ChannelTypeDef
* \n         input
* \n         pointer to a DMAC_ChannelTypeDef
* @pre       None
* @post      None
* @todo      Nothing
* @par InBodyDocs:
*****************************************************************************/
void CSP_DMAChannelStructInit(sDMA_Channel* DMAInitStruct)
{
	U8_T ch = 0;

	ch = DMAInitStruct->Channel;

	/* Disable(Off) the corresponding channel for configuration */
	CSP_DMADisableChannel(ch);

	/* Write Source and Destination Start Address */
	CSP_DMAAddressConfiguration(ch, DMAInitStruct->SrcAddress,\
								    DMAInitStruct->DestAddress);

	/* Increment option selection of source and destination address */
	CSP_DMASrcAddressControl(ch, DMAInitStruct->SrcHighIncrement,\
							    DMAInitStruct->SrcLowIncrement);
	/* Increment option selection of source and destination address */
	CSP_DMADestAddressControl(ch, DMAInitStruct->DestHighIncrement,\
							    DMAInitStruct->DestLowIncrement);

	/* Data Size Selection */
	CSP_DMADataSizeConfiguration(ch,DMAInitStruct->DataSize);

	/* Selection transfer size unit or burst */
	CSP_DMATransferSizeConfiguration(ch, DMAInitStruct->TransferSize);

	/* Transfer Count */
	CSP_DMATransferCountConfiguration(ch, DMAInitStruct->HighTransferCount,\
										DMAInitStruct->LowTransferCount );

	/* Auto-Reload Enable/Disable Configuration */
	CSP_DMAAutoReload(ch,DMAInitStruct->Autoreload);

	/* Selection service mode single or continuous mode */
	CSP_DMAServiceModeConfiguration(ch, DMAInitStruct->ServiceMode);

	/* Trigger Type Selection, Software or Hardware */
	CSP_DMATriggerTypeConfiguration(ch,DMAInitStruct->Trigger);

	/* Hardware Trigger Source Selection */
	CSP_DMAHardwareTrigConfiguration(ch, DMAInitStruct->HardwareReq);

	/* Interrupt Enable/Disable Selection */
	CSP_DMAConfigChannelInterrupt(ch, DMAInitStruct->TCInterrupt,\
									DMAInitStruct->LTCInterrupt);
}
/*******************************************************************************
* @brief     Configure and start a transfert.
* @return    none
* @param     dma
* \n          input
* \n          brief description - Pointer to DMACC structure.
* @param     channel_u8
* \n          input
* \n          brief description - channel number.
* @param     srcAddress_u32
* \n          input
* \n          brief description - source address.
* @param     destAddress_u32
* \n          input
* \n          brief description - destination address.
* @param     nbData_u32
* \n          input
* \n          brief description - number of data to be tranfered.
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
void CSP_DMAChannelInit( U8_T ch, U32_T srcAddress_u32, U32_T destAddress_u32,\
		eDMA_AddressControl Src_HighIncrement,eDMA_AddressControl Src_LowIncrement,\
		eDMA_AddressControl Dest_HighIncrement,eDMA_AddressControl Dest_LowIncrement,\
		eDMA_DataSize datasize, U32_T high_count , U32_T low_count ,\
		eDMA_TransferSize transfersize,\
		FunctionalStatus autorelad,	eDMA_ServiceMode servicemode,\
		eDMA_Trig trigtype, U16_T hwreq,\
		FunctionalStatus tc_interrupt,FunctionalStatus ltc_interrupt)
{
		/* Disable(Off) the corresponding channel for configuration */
		CSP_DMADisableChannel(ch);

		/* Write Source and Destination Start Address */
		CSP_DMAAddressConfiguration(ch, srcAddress_u32, destAddress_u32);

		/* Increment option selection of source and destination address */
		CSP_DMASrcAddressControl(ch, Src_HighIncrement,Src_LowIncrement);

		/* Increment option selection of source and destination address */
		CSP_DMADestAddressControl(ch, Dest_HighIncrement,Dest_LowIncrement);

		/* Data Size Selection */
		CSP_DMADataSizeConfiguration(ch,datasize);

		/* Selection transfer size unit or burst */
		CSP_DMATransferSizeConfiguration(ch, transfersize);

		/* Transfer Count */
		CSP_DMATransferCountConfiguration(ch, high_count, low_count);

		/* Auto-Reload Enable/Disable Configuration */
		CSP_DMAAutoReload(ch,autorelad);

		/* Selection service mode single or continuous mode */
		CSP_DMAServiceModeConfiguration(ch, servicemode);

		/* Trigger Type Selection, Software or Hardware */
		CSP_DMATriggerTypeConfiguration(ch,trigtype);
		/* Hardware Trigger Source Selection */
		CSP_DMAHardwareTrigConfiguration(ch, hwreq);

		/* Interrupt Enable/Disable Selection */
		CSP_DMAConfigChannelInterrupt(ch, tc_interrupt, ltc_interrupt);

		CSP_DMAEnableChannel(ch);
}

void CSP_DMAStart(U8_T ch)
{
	/* Start DMA Operation by Software Trigger*/
   CSP_DMA_SET_MTRX(DMA0, ch, CSP_DMA_GET_MTRX(DMA0, ch)|DMA_CHEN|DMA_SWTRIG);
}

/******************************************************************************
* @brief     Get interrupt mask status from Channel X IMR register
* @return    none
* @param     CSP_DMAC_T
* \n         input
* \n         pointer to a CSP_DMAC_T
* @param     U32_T
* \n          input
* \n          brief description - mask status in IMR register
* @param     ITStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Interrupt is enabled
*           - RESET: interrupt is disabled
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*****************************************************************************/
ITStatus CSP_DMAGetIntStatus(U32_T InterruptStatus)
{
	U32_T temp = 0;

	/* get status from SR register */
	temp = CSP_DMA_GET_ISR(DMA0) & DMA_ISR_MASK;

	if ((temp & InterruptStatus) != InterruptStatus)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}

/******************************************************************************
* @brief     Get interrupt mask status from Channel X IMR register
* @return    none
* @param     CSP_DMAC_T
* \n         input
* \n         pointer to a CSP_DMAC_T
* @param     U32_T
* \n          input
* \n          brief description - mask status in IMR register
* @param     ITStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Interrupt is enabled
*           - RESET: interrupt is disabled
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
FunctionalStatus CSP_DMAGetChannelEnableStatus(U8_T ch)
{
	if ((CSP_DMA_GET_MTRX(DMA0,ch)& DMA_CHEN) == DMA_CHEN)
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/******************************************************************************
* @brief     Get flag status from Channel X SR register
* @return    none
* @param     CSP_DMAC_T
* \n         input
* \n         pointer to a CSP_DMAC_T
* @param     U8_T
* \n         input
* \n         channel number
* @param     Flag
* \n          input
* \n          brief description - Flags in Channel X SR register
* @param     FlagStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Flag is set
*           - RESET: Flag is reset
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
******************************************************************************/
FlagStatus CSP_DMAGetFlagStatus(U8_T ch, U32_T Flag)
{
	U32_T temp = 0;

	/* get status from SR register */
	temp = (CSP_DMA_GET_SRX(DMA0, ch) & DMA_SRX_MASK);

	if ((temp & Flag) != Flag)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}
/*****************************************************************************
* @brief     Get flag status from Channel X SR register
* @return    none
* @param     CSP_DMAC_T
* \n         input
* \n         pointer to a CSP_DMAC_T
* @param     U8_T
* \n         input
* \n         channel number
* @param     Flag
* \n          input
* \n          brief description - Flags in Channel X SR register
* @param     FlagStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Flag is set
*           - RESET: Flag is reset
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*****************************************************************************/
U32_T CSP_DMAGetCurrSrcAddress(U8_T ch)
{
	return (CSP_DMA_GET_CSRX(DMA0, ch));
}

/****************************************************************************
* @brief     Get flag status from Channel X SR register
* @return    none
* @param     CSP_DMAC_T
* \n         input
* \n         pointer to a CSP_DMAC_T
* @param     U8_T
* \n         input
* \n         channel number
* @param     Flag
* \n          input
* \n          brief description - Flags in Channel X SR register
* @param     FlagStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Flag is set
*           - RESET: Flag is reset
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*****************************************************************************/
U32_T CSP_DMAGetCurrDesAddress(U8_T ch)
{
	return (CSP_DMA_GET_CDRX(DMA0,ch));
}

/******************************************************************************
* @brief     Get flag status from Channel X SR register
* @return    none
* @param     CSP_DMAC_T
* \n         input
* \n         pointer to a CSP_DMAC_T
* @param     U8_T
* \n         input
* \n         channel number
* @param     Flag
* \n          input
* \n          brief description - Flags in Channel X SR register
* @param     FlagStatus
* \n          output
* \n          brief description - Status of flag (set or reset)
*           - SET: Flag is set
*           - RESET: Flag is reset
* @pre       None
* @post      None
* @todo      nothing
* @par InBodyDocs:
*****************************************************************************/
U32_T CSP_DMAGetCurrHighTransferCounnt(U8_T ch)
{
	U32_T temp =0;
	temp = CSP_DMA_GET_SRX(DMA0, ch)& DMA_CURR_HTC_MASK;
	return (temp>>12);
}

U32_T CSP_DMAGetCurrLowTransferCounnt(U8_T ch)
{
	U32_T temp =0;
	temp = CSP_DMA_GET_SRX(DMA0, ch)& DMA_CURR_LTC_MASK;
	return (temp);
}

void CSP_DMAClearStop(U8_T ch)
{
   /* Start DMA Operation by Software Trigger*/
   CSP_DMA_SET_MTRX(DMA0, ch, CSP_DMA_GET_MTRX(DMA0, ch)& ~DMA_STOP);
}

FlagStatus CSP_DMAGetSWTrig(U8_T ch)
{
	U32_T temp =0;

	temp = CSP_DMA_GET_MTRX(DMA0, ch);

	if ((temp & DMA_SWTRIG) != DMA_SWTRIG)
	{
		return RESET;
	}
	else
	{
		return SET;
	}
}
