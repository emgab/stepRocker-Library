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
* @file name	csp_usart.c
* @description Definitions, Macros and function declarations for USART
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.  MCU Solution Part	  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

/******************************************************************************
* Include Files
******************************************************************************/
#include "csp.h"

/******************************************************************************
****************************  F U N C T I O N S  ******************************
******************************************************************************/

/**
*******************************************************************************
* @brief     Switch on the clock, reset the registers and configure
*            the USART module mode and the LDMA RX/TX line
*@return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     mode_u32
* \n          input
* \n          brief description - Configure the USART mode.
* @param     baudrate
* \n          input
* \n          brief description - Configure the Baud Rate Generator.
* @param     time_out
* \n          input
* \n          brief description - Configure the receiver time-out :
* \n                              the time-out is loaded when the Start
* \n                              Time-out Command is given or when
* \n                              each new character is received.
* @param     time_guard
* \n          input
* \n          brief description - Configure the transmit time-guard : TXD is
* \n                              inactive (high level) after the transmission
* \n                              of each character for the time-guard duration
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTInit(CSP_USART_T *usart, U32_T mode_u32, U16_T baudrate_u16,
                   U8_T timeOut_u8, U8_T timeGuard_u8)
{

   /* Enable USART Clock */
   CSP_USART_SET_CEDR(usart, USART_CLKEN);

   /* USART Software Reset */
   CSP_USART_SET_SRR(usart, USART_SWRST);

   CSP_USART_SET_CR(usart, (USART_RSTRX | USART_RSTTX));

   /* Configure USART Mode */
   CSP_USART_SET_MR(usart, mode_u32);

   /* Set Receiver Time Out */
   CSP_USART_SET_RTOR(usart, timeOut_u8);

   /* Set Transmitter Timer Guard */
   CSP_USART_SET_TTGR(usart, timeGuard_u8);

   /* Set Baudrate */
   CSP_USART_SET_BRGR(usart, baudrate_u16);
}

/**
*******************************************************************************
* @brief     Switch on the clock, reset the registers and configure
*            the USART module for LIN mode
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     baudrate_u16
* \n          input
* \n          brief description - Configure the Baud Rate Generator.
* @param     LinVersion_u32
* \n          input
* \n          brief description -  Configure the LIN version 1.2 or 2.0
* @param     TimeGuard_u8
* \n          input
* \n          brief description - Configure the transmit time-guard
* \n                              (interbyte space)
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTInitLin(CSP_USART_T *usart, U16_T baudrate_u16, 
						U32_T linVersion_u32, U8_T timeGuard_u8)
{

   /* Enable USART & PIO Clock */
   CSP_USART_SET_CEDR(usart, USART_CLKEN);

   /* USART Software Reset */
   CSP_USART_SET_SRR(usart, USART_SWRST);

   /* Configure LIN Mode */
   CSP_USART_SET_MR(usart,  (linVersion_u32 | USART_CHMODE_NORMAL |
                             USART_NBSTOP_1 |USART_PAR_NO | USART_ASYNC |
                             USART_CHRL_8 | USART_CLKS_MCKI | USART_LIN));

   /* Set Baudrate */
   CSP_USART_SET_BRGR(usart, baudrate_u16);

   /* Set Transmitter Timer Guard */
   CSP_USART_SET_TTGR(usart, timeGuard_u8);
}

/**
*******************************************************************************
* @brief     Reset and switch off the clock
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTClose(CSP_USART_T *usart)
{
   /* USART Software Reset */
   CSP_USART_SET_SRR(usart, USART_SWRST);

   /* Disable USART Clock */
   CSP_USART_SET_CEDR(usart, USART_CLKEN);
}

/**
*******************************************************************************
* @brief     Configure USART Interrupts
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     intMask_u32
* \n          input
* \n          brief description - Configure which interrupt bits are activated.
* @param     prePrio_u8
* \n          input
* \n          brief description - preemption priority
* @param     subPrio_u8
* \n          input
* \n          brief description - sub priority
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTConfigInterrupt( CSP_USART_T *usart,
						   	   U32_T intMask_u32,
                               FunctionalStatus newState)
{
	if (newState != DISABLE)
	{
		/* Disable target interrupts */
		CSP_USART_SET_IMSCR(usart, usart->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_USART_SET_ICR(usart, intMask_u32);

		/* Enable target interrupts */
		CSP_USART_SET_IMSCR(usart, usart->IMSCR|intMask_u32);
	}
	else
	{
		/* Disable target interrupts */
		CSP_USART_SET_IMSCR(usart, usart->IMSCR & (~intMask_u32));

		/* Clear target interrupts */
		CSP_USART_SET_ICR(usart, intMask_u32);
	}
}

/**
*******************************************************************************
* @brief     Enable USART
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     enableMask_u32
* \n          input
* \n          brief description -  Configure which functions (RX and/or TX)
* \n                               are enabled
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTEnable(CSP_USART_T *usart, U32_T enableMask_u32)
{
   /* USART Rx and/or Tx Enable */
   CSP_USART_SET_CR(usart, enableMask_u32);
}

/**
*******************************************************************************
* @brief     Disable USART
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     disableMask_u32
* \n          input
* \n          brief description -  Configure which functions (RX and/or TX)
* \n                               are disabled
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTDisable(CSP_USART_T *usart, U32_T disableMask_u32)
{
   /* USART Rx and/or Tx Disable */
   CSP_USART_SET_CR(usart, disableMask_u32);
}

/**
*******************************************************************************
* @brief     Configure USART to receive data. They will be transferred
*            automatically to memory thanks to DMA.
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     channel_u8
* \n          input
* \n          brief description - Configure USART LDMAC Channel
* @param     data_u8
* \n          input
* \n          brief description -  Pointer to an array where data packet
* \n                               received will be store
* @param     length_u16
* \n          input
* \n          brief description -  Number of byte to receive
* @pre       None
* @post      You should wait the set of the ENDRX bit in SR.
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTReceive(CSP_USART_T *usart,
                      U8_T channel_u8,
                      U32_T destAddress_u32,
                      U16_T length_u16)
{

#ifndef __NOTUSE_DMA_USART
   /* Disable Reception */
   CSP_USART_SET_CR(usart, USART_RXDIS);

   /* Configure LDMAC Rx Line to Receive a packet */
   if(usart == USART0)
	{
		CSP_DMAChannelInit( channel_u8,((U32_T) &usart->RHR), destAddress_u32,\
												Fixed, Fixed,\
												Increment, Increment,\
												BYTE, length_u16, 1,\
												SingleTransfer,\
												DISABLE, SingleService,\
												Hardware, DMA_USART0_RX,\
												ENABLE, DISABLE);
	}
	else if(usart == USART1)
	{
		CSP_DMAChannelInit( channel_u8,((U32_T) &usart->RHR), destAddress_u32,\
														Fixed, Fixed,\
														Increment, Increment,\
														BYTE, length_u16, 1,\
														SingleTransfer,\
														DISABLE, SingleService,\
														Hardware, DMA_USART1_RX,\
														ENABLE, DISABLE);
	}
	else if(usart == USART2)
	{
		CSP_DMAChannelInit( channel_u8,((U32_T) &usart->RHR), destAddress_u32,\
														Fixed, Fixed,\
														Increment, Increment,\
														BYTE, length_u16, 1,\
														SingleTransfer,\
														DISABLE, SingleService,\
														Hardware, DMA_USART2_RX,\
														ENABLE, DISABLE);
	}

   /* Clear Status */
   CSP_USART_SET_CR(usart, USART_STTTO);
   CSP_USART_SET_RTOR(usart, 0); //Set RTOR = 0 to disable receive time out

   /* Enable Reception (if RTOR = 0 time out is disabled) */
   CSP_USART_SET_CR(usart, USART_RXEN);

#else

   U32_T i;

	/* Enable Reception (if RTOR = 0 time out is disabled) */
	CSP_USART_SET_CR(usart, USART_RXEN);
	for(i=0;i<length_u16;i++)
	{
		while( (CSP_USART_GET_SR(usart)&USART_RXRDY) == 0)
			;

		((U32_T *)destAddress_u32)[i] = CSP_USART_GET_RHR(usart);
	}
#endif
}

/**
*******************************************************************************
* @brief     Configure USART to transmit data. They are transferred
*            automatically from memory to USART transmission buffer thanks
*            to LDMA.
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     channel_u8
* \n          input
* \n          brief description - Configure USART LDMAC Channel
* @param     data_u8
* \n          input
* \n          brief description -  Pointer to an array where data packet
* \n                               received will be store
* @param     length_u16
* \n          input
* \n          brief description -  Number of byte to receive
* @pre       None
* @post      You should wait the set of the ENDTX bit in SR.
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTTransmit(CSP_USART_T *usart,
                       U8_T channel_u8,
                       U32_T sourceAddress_u32,
                       U16_T length_u16)
{
#ifndef __NOTUSE_DMA_USART

   /* Disable Transmission */
   CSP_USART_SET_CR(usart, USART_TXDIS);

   /* Configure LDMAC Tx Line to Send a packet */
   if(usart == USART0)
   	{
   		CSP_DMAChannelInit( channel_u8, sourceAddress_u32, ((U32_T) & (usart->THR)),\
   						Increment,Increment,\
   						Fixed, Fixed,\
   						BYTE, length_u16, 1,\
   						SingleTransfer,\
   						DISABLE, SingleService,\
   						Hardware, DMA_USART0_TX,\
   						ENABLE, DISABLE);
   	}
   	else if(usart == USART1)
   	{
   		CSP_DMAChannelInit( channel_u8, sourceAddress_u32, ((U32_T) & (usart->THR)),\
   		   						Increment,Increment,\
   		   						Fixed, Fixed,\
   		   						BYTE, length_u16, 1,\
   		   						SingleTransfer,\
   		   						DISABLE, SingleService,\
   		   						Hardware, DMA_USART1_TX,\
   		   						ENABLE, DISABLE);
   	}
   	else if(usart == USART2)
   	{
  		CSP_DMAChannelInit( channel_u8, sourceAddress_u32, ((U32_T) & (usart->THR)),\
   		   						Increment,Increment,\
   		   						Fixed, Fixed,\
   		   						BYTE, length_u16, 1,\
   		   						SingleTransfer,\
   		   						DISABLE, SingleService,\
   		   						Hardware, DMA_USART2_TX,\
   		   						ENABLE, DISABLE);
   	}

   /* Enable Transmission */
   CSP_USART_SET_CR(usart, USART_TXEN);

#else

   U32_T i;
   
   /* Enable Transmission */
   CSP_USART_SET_CR(usart, USART_TXEN);
   for(i=0;i<length_u16;i++)
   	{
   		CSP_USART_SET_THR(usart, ((U32_T *)sourceAddress_u32)[i]);
   		while ((CSP_USART_GET_SR(usart) & USART_TXEMPTY) == 0)
   			;
   	}
#endif
}

/**
*******************************************************************************
* @brief     Transmit a LIN header Frame
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     sblr_u8
* \n          input
* \n          brief description - Configure the Synchro Break Length
* @param     LinMode_u32
* \n          input
* \n          brief description - Configure the LIN's mode
* @pre       None
* @post      You should wait the set of the ENDHEADER bit in SR.
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTTransmitLinHeaderFrame(CSP_USART_T *usart, U8_T sblr_u8,
                                     U32_T linMode_u32)
{
   /* Configure the Sync Break Length */
   CSP_USART_SET_SBLR(usart, sblr_u8);

   /* Configure LIN mode */
   CSP_USART_SET_LIR(usart, linMode_u32);

   /* Transmit Header */
   CSP_USART_SET_CR(usart, USART_STHEADER);
}


/**
*******************************************************************************
* @brief     Initialise Data Field Write Registers for LIN Response Frame
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @param     data_u8
* \n          input
* \n          brief description - Pointer to an array where data packet
*             sent is stored
* @pre        You should use this function before the
* \n          CSP_USARTTransmitLinHeaderFrame function in case of
* \n          a Master Request Frame.
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTLinResponseFrameInit(CSP_USART_T *usart, U8_T *data_u8)
{

   /* The writing in DFWR must be in 32 bits */
   CSP_USART_SET_DFWR0(usart, (*(U32_T*)&data_u8[0]));
   CSP_USART_SET_DFWR1(usart, (*(U32_T*)&data_u8[4]));

}

/**
*******************************************************************************
* @brief     Transmit a LIN Response Frame
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @pre       You should use the CSP_USARTTransmitLinHeaderFrame function
* \n         before using this function.
* @post      You should wait the set of the ENDMESS bit in SR.
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTTransmitLinRpseFrame(CSP_USART_T *usart)
{
   /* Transmit Response */
   CSP_USART_SET_CR(usart, USART_STRESP);
}

/**
*******************************************************************************
* @brief     Port setting for USART with sync option
* @return    none
* @param     usart
* \n          input
* \n          brief description - Pointer to USART structure.
* @pre       You should use the CSP_USARTTransmitLinHeaderFrame function
* \n         before using this function.
* @post      You should wait the set of the ENDMESS bit in SR.
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTPortInit(CSP_USART_T* usart, U8_T sync_mode)
{
	if(usart == USART1)
	{
		CSP_IOFunctionConfigure(GROUP1, IO_Port4, IOCONF_F1 ); //IOCONF 1.4 for USART01 TX
		CSP_IOFunctionConfigure(GROUP1, IO_Port3, IOCONF_F1 ); //IOCONF 1.3 for USART01 RX
		if(sync_mode)
		{
			CSP_IOFunctionConfigure(GROUP0, IO_Port31, IOCONF_F1 ); //IOCONF 0.31 for USART01 CLK
		}
	}
	else if(usart == USART0)
	{
		CSP_IOFunctionConfigure(GROUP1, IO_Port2, IOCONF_F1 ); //IOCONF 1.2 for USART00 TX
		CSP_IOFunctionConfigure(GROUP1, IO_Port1, IOCONF_F1 ); //IOCONF 1.1 for USART00 RX
		if(sync_mode)
		{
			CSP_IOFunctionConfigure(GROUP0, IO_Port30, IOCONF_F1 ); //IOCONF 0.30 for USART00 CLK
		}
	}
	else if(usart == USART2)
	{
		CSP_IOFunctionConfigure(GROUP1, IO_Port9, IOCONF_F1 ); //IOCONF 1.9 for USART02 TX
		CSP_IOFunctionConfigure(GROUP1, IO_Port8, IOCONF_F1 ); //IOCONF 1.8 for USART02 RX
		if(sync_mode)
		{
			CSP_IOFunctionConfigure(GROUP1, IO_Port0, IOCONF_F1 ); //IOCONF 1.0 for USART02 CLK
		}
	}

}

/**
*******************************************************************************
* @brief     DMA channel selection
* @return    none
* @param     usart
* \n         input
* \n         brief description - Pointer to USART structure.
* @pre       You should use the CSP_USARTTransmitLinHeaderFrame function
* \n         before using this function.
* @post      You should wait the set of the ENDMESS bit in SR.
* @todo      nothing
*******************************************************************************
*/
void CSP_USARTDMACHSelc(CSP_USART_T* usart, U8_T *hwsrc_tx, U8_T *hwsrc_rx)
{
	if(usart == USART1)
	{
		*hwsrc_tx = DMA_USART1_TX;
		*hwsrc_rx = DMA_USART1_RX;
	}
	else if(usart == USART0)
	{
		*hwsrc_tx = DMA_USART0_TX;
		*hwsrc_rx = DMA_USART0_RX;
	}
	else if(usart == USART2)
	{
		*hwsrc_tx = DMA_USART2_TX;
		*hwsrc_rx = DMA_USART2_RX;
	}	
}


