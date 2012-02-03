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
* @file name	csp_can.c
* @description Definitions, Macros and function declarations for CAN
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
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
* @brief     Switch on the clock, reset registers and state machines,
*            initialize Message RAM and configure the CAN mode
* @return    none
* @param     can
* \n         input
* \n         brief description - Pointer to CAN structure.
* @param     mode_u32
* \n         input
* \n         brief description - Configure the CAN mode.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_CANInit(CSP_CAN_T *can, U32_T mode_u32)
{
   /* Local variables */
   U8_T channel_u8;

   /* Enable CAN Clock */
   CSP_CAN_SET_ECR(can, CAN_CAN);

   /* CAN Software Reset */
   CSP_CAN_SET_CR(can, CAN_SWRST);

   /* Initialize Message RAM */
   for (channel_u8 = 1; channel_u8 <= (U8_T)NB_CAN_MO; channel_u8++)
   {
      while((CSP_CAN_GET_SR(can) & CAN_BUSY0) == CAN_BUSY0)
      {
      }
      CSP_CAN_IF_SET_DAR(can, IF0, 0x00000000);
      CSP_CAN_IF_SET_DBR(can, IF0, 0x00000000);
      CSP_CAN_IF_SET_MSKR(can, IF0, 0xDFFFFFFF);
      CSP_CAN_IF_SET_IR(can, IF0, 0x00000000);
      CSP_CAN_IF_SET_MCR(can, IF0, 0x00000000);
      CSP_CAN_IF_SET_TMR(can, IF0, (CAN_AMCR | CAN_AIR | CAN_AMSKR | CAN_ADAR | CAN_ADBR |
                        CAN_WR | channel_u8));
   }


   /* Enable configuration change */
   CSP_CAN_SET_CR(can, CAN_CCEN);

   /* Configure CAN Mode */
   CSP_CAN_SET_MR(can, mode_u32);

   /* Disable configuration change */
   CSP_CAN_SET_CR(can, CAN_CCDIS);
}


/**
*******************************************************************************
* @brief     Reset and switch off the clock
* @return    none
* @param     can
* \n          input
* \n          brief description - Pointer to CAN structure.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_CANClose(CSP_CAN_T *can)
{
   /* CAN Software Reset */
   CSP_CAN_SET_CR(can, CAN_SWRST);

   /* Disable CAN Clock */
   CSP_CAN_SET_DCR(can, CAN_CAN);
}


/**
*******************************************************************************
* @brief     Configure CAN Interrupts
* @return    none
* @param     can
* \n          input
* \n          brief description - Pointer to CAN structure.
* @param     intMask_u32
* \n          input
* \n          brief description - Configure which interrupt bits are activated.
* @param     channelMask_u32
* \n          input
* \n          brief description - Channel [0-31] to be configured.
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
void CSP_CANConfigInterrupt(CSP_CAN_T *can,
                            U32_T intMask_u32,
                            U32_T channelMask_u32,
                            FunctionalStatus newState)
{
	/* Local Variables */
	U8_T channel_u8;

	if (newState != DISABLE)
	{
		/* Disable all interrupts */
		CSP_CAN_SET_IDR(can, 0xFFFFFFFF);
		CSP_CAN_SET_SIDR(can, 0xFFFFFFFF);

		/* Clear interrupts at CAN controller level */
		CSP_CAN_SET_CSR(can, CAN_CSR_MASK);

		/* Clear interrupts at Message Object level */
		for (channel_u8 = 1; channel_u8 <= (U8_T)NB_CAN_MO; channel_u8++)
		{
			while((CSP_CAN_GET_SR(can) & CAN_BUSY0) == CAN_BUSY0)
			{
			}
			CSP_CAN_IF_SET_TMR(can, IF0, (CAN_CLRIT | channel_u8));
		}

		/* Enable interrupt at CAN controller level */
		CSP_CAN_SET_IER(can, intMask_u32);

		/* Enable interrupt at Message Object level */
		CSP_CAN_SET_SIER(can, channelMask_u32);
	}
	else
	{
		/* Disable all interrupt */
		CSP_CAN_SET_IDR(can, 0xFFFFFFFF);
		CSP_CAN_SET_SIDR(can, 0xFFFFFFFF);

		/* Clear all interrupt */
		CSP_CAN_SET_CSR(can, 0xFFFFFFFF);
	}
}


/**
*******************************************************************************
* @brief     Enable CAN
* @return    none
* @param     can
* \n          input
* \n          brief description - Pointer to CAN structure.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_CANEnable(CSP_CAN_T *can)
{
   /* Enable CAN */
   CSP_CAN_SET_CR(can, CAN_CANEN);
}


/**
*******************************************************************************
* @brief     Disable CAN
* @return    none
* @param     can
* \n          input
* \n          brief description - Pointer to CAN structure.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_CANDisable(CSP_CAN_T *can)
{
   /* Disable CAN */
   CSP_CAN_SET_CR(can, CAN_CANDIS);
}

/**
*******************************************************************************
* @brief     Configure a CAN Message Object to pick up message from the network
* @return    none
* @param     can
* \n          input
* \n          brief description - Pointer to CAN structure.
*
* @param     interface_u8
* \n          input
* \n          brief description - Interface registers used for transfer to
*                                 Message RAM.
* @param     channel_u8
* \n          input
* \n          brief description - Receiver channel [0-31].
* @param     id_u32
* \n          input
* \n          brief description - Configure the identifier, the frame format
*                                 and direction
*                                 XTD  : extend format
*                                 MDIR : wait a remote frame
* @param     mask_u32
* \n          input
* \n          brief description - Configure the mask, the frame format and
*                                 direction mask.
* @param     control_u16
* \n          input
* \n          brief description - Configure the number of byte to receive and
*                                 the control bits.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_CANReceive(CSP_CAN_T *can,
                       U8_T  interface_u8,
                       U8_T  channel_u8,
                       U32_T id_u32,
                       U32_T mask_u32,
                       U16_T control_u16)
{
   /* Set Id Register */
   CSP_CAN_IF_SET_IR(can, interface_u8, CAN_MSGVAL | id_u32);

   /* Set Mask Register */
   CSP_CAN_IF_SET_MSKR(can, interface_u8, mask_u32);

   /* Set Control Register */
   CSP_CAN_IF_SET_MCR(can, interface_u8, control_u16);

   /* Set message object 'channel' with interface registers */
   CSP_CAN_IF_SET_TMR(can, interface_u8, CAN_AMCR | CAN_AIR | CAN_AMSKR |
                      CAN_WR | channel_u8);

   /* Wait before the transfer between interface registers and Message */
   /* Object RAM memory has completed */
   while (((CSP_CAN_GET_SR(can) & CAN_BUSY0) == CAN_BUSY0) ||
         ((CSP_CAN_GET_SR(can) & CAN_BUSY1) == CAN_BUSY1))
   {
   }
}


/**
*******************************************************************************
* @brief     Configure a CAN Message Object to transmit message on the network
* @return    none
* @param     can
* \n          input
* \n          brief description - Pointer to CAN structure.
* @param     interface_u8
* \n          input
* \n          brief description - Interface registers used for transfer to
*                                 Message RAM.
* @param     channel_u8
* \n          input
* \n          brief description - Transmitter channel [0-31].
* @param     dataa_u32
* \n          input
* \n          brief description - Pointer to an array where data packets are
*                                 stored.
* @param     datab_u32
* \n          input
* \n          brief description - Pointer to an array where data packets are
*                                 stored.
* @param     id_u32
* \n          input
* \n          brief description - Configure the identifier, the frame format
*                                 and the remote request
* @param     control_u16
* \n          input
* \n          brief description - Configure the number of byte to transmit and
* \n                              the control bits.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
void CSP_CANTransmit(CSP_CAN_T *can,
                        U8_T  interface_u8,
                        U8_T  channel_u8,
                        U32_T dataa_u32,
                        U32_T datab_u32,
                        U32_T id_u32,
                        U16_T control_u16)
{
   /* Set DATAA Register */
   CSP_CAN_IF_SET_DAR(can, interface_u8, dataa_u32);

   /* Set DATAB Register */
   CSP_CAN_IF_SET_DBR(can, interface_u8, datab_u32);

   /* Set Id Register */
   CSP_CAN_IF_SET_IR(can, interface_u8, CAN_MSGVAL | id_u32);

   /* Set Control Register */
   CSP_CAN_IF_SET_MCR(can, interface_u8, control_u16);

   /* Set message object 'channel' with interface registers */
   CSP_CAN_IF_SET_TMR(can, interface_u8, CAN_TRND | CAN_AMCR | CAN_AIR |
                      CAN_ADBR | CAN_ADAR | CAN_WR | channel_u8);

   /* Wait before the transfer between interface registers and Message */
   /* Object RAM memory has completed */
   while (((CSP_CAN_GET_SR(can) & CAN_BUSY0) == CAN_BUSY0) ||
         ((CSP_CAN_GET_SR(can) & CAN_BUSY1) == CAN_BUSY1))
   {
   }
}

/**
*******************************************************************************
* @brief     Configure a CAN Message Object to transmit message on the network
* @return    none
* @param     can
* \n          input
* \n          brief description - Pointer to CAN structure.
* @param     coreClk_u32
* \n          input
* \n          brief description - Core clock frequency expressed in Hz.
* @param     baudRate_u32
* \n          input
* \n          brief description - CAN baud rate desired expressed in bits/s.
* @pre       None
* @post      None
* @todo      nothing
*******************************************************************************
*/
U32_T CSP_CANComputeBT(CSP_CAN_T *can,
                       U32_T     coreClk_u32,
                       U32_T     baudRate_u32)
{
   /* Locals variables used for bit timing computation */
   U32_T       mode_u32;
   U32_T       baudRatePrescalar_u32;
   U32_T       bitTimeLength_u32;
   U32_T       bitTimeLengthTenth_u32;
   U32_T       propSegment_u32;
   U32_T       phaseSegments_u32;
   U32_T       phaseSegment1_u32;
   U32_T       phaseSegment2_u32;
   U32_T       sjwSegment_u32;
   U8_T        error_u8 = 0;

   /* Core clock frequency may be an integer multiple of the CAN baud rate */
   if ((((100 * coreClk_u32) / baudRate_u32) -
      (100 * (coreClk_u32 / baudRate_u32))) != 0)
   {
      error_u8 = 1;
   }

   /* The bit time may consist of 4 to 25 time quanta tq, where
      tq =(BD[9:0] / CoreClk) */
   baudRatePrescalar_u32 = 0;
   bitTimeLength_u32 = coreClk_u32 / baudRate_u32;
   bitTimeLengthTenth_u32 = (10 * coreClk_u32) / baudRate_u32;
   /* BitTimeLength expressed in tq may be at max of 25 and
      may be an integer multiple */
   while ((bitTimeLength_u32 > 25) | (bitTimeLengthTenth_u32 !=
         (10 * bitTimeLength_u32)))
   {
      baudRatePrescalar_u32 = baudRatePrescalar_u32 + 1;
      /* It's rouded. */
      bitTimeLength_u32 = coreClk_u32 / baudRate_u32 /
                         (baudRatePrescalar_u32 + 1);
      /* Here, the tenth accuracy is keeped */
      bitTimeLengthTenth_u32 = (10 * coreClk_u32) / baudRate_u32 /
                               (baudRatePrescalar_u32 + 1);
   }
   if (bitTimeLength_u32 < 4) error_u8 = 1; // A bit time is at min 4 tq

   /* Propagation delay = 300ns = 3.333MHz */
   /* (Physical interface transmitter:140ns, 2 meters bus line:10ns) */
   propSegment_u32 = 1;
   while ((coreClk_u32 / (baudRatePrescalar_u32 + 1) /
           propSegment_u32) > 3333333)
   {
      propSegment_u32 = propSegment_u32 + 1;
   }
   /* (Prop_seg + Sync_seg) may be < (Bit time length - 1) */
   if ((propSegment_u32 + 1) >= (bitTimeLength_u32-1)) error_u8 = 1;
   /* The two phase segments are (Bit time - Prop_seg - Sync_seg) long */
   /* If (Bit time - Prop_seg - Sync_seg) is even : */
   /* Phase_seg2 = Phase_seg1 else Phase_seg2 = (Phase_seg1 + 1) */
   /* The IPT Information processing time is 0 tq. */
   /* Phase_seg2 must be > IPT : no problem */
   phaseSegments_u32 = bitTimeLength_u32 - propSegment_u32 - 1;
   phaseSegment1_u32 = phaseSegments_u32 / 2;
   phaseSegment2_u32 = phaseSegments_u32 - phaseSegment1_u32;
   phaseSegment1_u32 = phaseSegment1_u32 + propSegment_u32;
   /* There are only 3 bits to code phase seg2 length : */
   /* then it can not exceed 8 */
   while (phaseSegment2_u32 > 8)
   {
      phaseSegment2_u32 = phaseSegment2_u32 - 1;
      phaseSegment1_u32 = phaseSegment1_u32 + 1;
   }

   /* The length of the Synchronization Jump Width is the smaller */
   /* of 4 and Phase_seg1 */
   if ((phaseSegment1_u32 - propSegment_u32) < 4)
   {
      sjwSegment_u32 = (phaseSegment1_u32 - propSegment_u32);
   }
   else
   {
      sjwSegment_u32 = 4;
   }

   /* Store MR value */
   mode_u32 = baudRatePrescalar_u32 | (sjwSegment_u32 - 1) << 12 | CAN_AR |
             (phaseSegment1_u32 - 1) << 16 | (phaseSegment2_u32 - 1) << 20;
   if(error_u8 != 0)
   {
      mode_u32 = 0;
   }

   /* Return */
   return(mode_u32);
}

