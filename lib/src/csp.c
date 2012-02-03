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
* You shall not disclose such Confidential Inforamtion and shall use it only
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
* @file name	csp.c
* @description	Structure for for S3FN41F
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when       who                       what
* |---+---+----------+-------------------------+----------------------
* |0.0 NEW 01/DEC/09   Yh JIN                     Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

/******************************************************************************
* Include Files
******************************************************************************/
#include "..\CSP\inc\csp.h"

#ifdef DEBUG
/******************************************************************************
* Peripheral Declaration
******************************************************************************/
/** Analog to Digital Converter                                             */
CSP_ADC_T    	*ADC0    = ((CSP_ADC_T*)    ADC0_BASE_ADDRESS);

/** Controller Area Network                                                 */
CSP_CAN_T		*CAN0    = ((CSP_CAN_T*)      CAN0_BASE_ADDRESS);

/** Stamp Timer				                                                */
CSP_STT_T		*STT0    = ((CSP_STT_T*)      STT0_BASE_ADDRESS);

/** Clock Manager                                                           */
CSP_CM_T       	*CM0     = ((CSP_CM_T*)       CM0_BASE_ADDRESS);

/**  Direct Memory Access                                               	*/
CSP_DMA_T     	*DMA0  = ((CSP_DMA_T*)         DMA0_BASE_ADDRESS);

/** Encoder			                                          				*/
CSP_ENC_T     	*ENC0    = ((CSP_ENC_T*)      ENC0_BASE_ADDRESS);

/** Free Running Timer		                                           		*/
CSP_FRT_T     	*FRT0    = ((CSP_FRT_T*)      FRT0_BASE_ADDRESS);

/** General Purpose I/O                                                     */
CSP_GPIO_T      *GPIO0    = ((CSP_GPIO_T*)      GPIO0_BASE_ADDRESS);
CSP_GPIO_T      *GPIO1    = ((CSP_GPIO_T*)      GPIO1_BASE_ADDRESS);
CSP_IOCONF_T   	*IOCONF0 = ((CSP_IOCONF_T*)   IOCONF0_BASE_ADDRESS);

/** Inter-Integrated Circuit                                                */
CSP_I2C_T      	*I2C0    = ((CSP_I2C_T*)      I2C0_BASE_ADDRESS);
CSP_I2C_T      	*I2C1    = ((CSP_I2C_T*)      I2C1_BASE_ADDRESS);

/** Internal Flash Controller                                              	*/
CSP_IFC_T      	*IFC0    = ((CSP_IFC_T*)      IFC0_BASE_ADDRESS);

/** Inverter Motor Controller                                             	*/
CSP_IMC_T      	*IMC0    = ((CSP_IMC_T*)      IMC0_BASE_ADDRESS);

/** LCD Controller	                                                     	*/
CSP_LCDC_T    	*LCDC0     = ((CSP_LCDC_T*)     LCDC0_BASE_ADDRESS);

/** OP-AMP 		                                                     		*/
CSP_OPAMP_T    	*OPAMP0     = ((CSP_OPAMP_T*)     OPAMP0_BASE_ADDRESS);

/** Pulse Width Modulation                                                  */
CSP_PWM_T      	*PWM0    = ((CSP_PWM_T*)      PWM0_BASE_ADDRESS);
CSP_PWM_T      	*PWM1    = ((CSP_PWM_T*)      PWM1_BASE_ADDRESS);

/** Serial Peripheral Interface                                             */
CSP_SSP_T      	*SSP0    = ((CSP_SSP_T*)      SSP0_BASE_ADDRESS);
CSP_SSP_T      	*SSP1    = ((CSP_SSP_T*)      SSP1_BASE_ADDRESS);

/** Timer/Counter                                                           */
CSP_TC16_T     	*TC0    = ((CSP_TC16_T*)      TC0_BASE_ADDRESS);
CSP_TC16_T     	*TC1    = ((CSP_TC16_T*)      TC1_BASE_ADDRESS);
CSP_TC16_T     	*TC2    = ((CSP_TC16_T*)      TC2_BASE_ADDRESS);
CSP_TC16_T     	*TC3    = ((CSP_TC16_T*)      TC3_BASE_ADDRESS);
CSP_TC16_T     	*TC4    = ((CSP_TC16_T*)      TC4_BASE_ADDRESS);
CSP_TC16_T     	*TC5    = ((CSP_TC16_T*)      TC5_BASE_ADDRESS);
CSP_TC32_T      *TC6    = ((CSP_TC32_T*)      TC6_BASE_ADDRESS);
CSP_TC32_T     	*TC7    = ((CSP_TC32_T*)      TC7_BASE_ADDRESS);

/** Universal Sync/Async receiver/Transmitter                               */
CSP_USART_T    	*USART0   = ((CSP_USART_T*)    USART0_BASE_ADDRESS);
CSP_USART_T    	*USART1   = ((CSP_USART_T*)    USART1_BASE_ADDRESS);
CSP_USART_T    	*USART2   = ((CSP_USART_T*)    USART2_BASE_ADDRESS);

/** USB																		*/
CSP_USB_T	    *USB0   = ((CSP_USB_T*)    USB0_BASE_ADDRESS);

/** Watchdog                                                                */
CSP_WDT_T       *WDT0     = ((CSP_WDT_T*)       WDT0_BASE_ADDRESS);

/******************************************************************************
* System Control Space Declaration
******************************************************************************/
/** SysTick in Cortex-M0                                                     */
CSP_SYSTICK_T  *SYSTICK0 = ((CSP_SYSTICK_T*) SYSTICK0_BASE_ADDRESS);

/** Nested Vectored Interrupt Controller in Cortex-M0                      	 */
CSP_NVIC_T     *NVIC0    = ((CSP_NVIC_T*)    NVIC0_BASE_ADDRESS);

/** System Control Block in Cortex-M0                                        */
CSP_SCB_T      *SCB0     = ((CSP_SCB_T*)     SCB0_BASE_ADDRESS);

/******************************************************************************
* Core Debug / System Debug / TPIU
******************************************************************************/
CSP_BPU_T  *BPU   = ((CSP_BPU_T*) BPU_BASE_ADDRESS);

#endif /** DEBUG */

