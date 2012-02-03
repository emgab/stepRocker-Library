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
* @file name	csp.h
* @description
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
* |0.1 MOD 2010.03.20.   Youngseok.oh    	 PFLASH_BASE_ADDRESS has to be 0x0
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_H
#define CSP_H	  
/******************************************************************************
****************************** Chip Declaration *******************************
******************************************************************************/
/** Number of DMA Channels (used in dma.h)                              	*/
#define NB_DMA_CHANNEL  		6u

/** Number of total interrupt (used in nvic.h)                              */
#define NB_INTERRUPT			32u

/******************************************************************************
* Include Files
******************************************************************************/

#include "csp_types.h"
#include "csp_systick.h"
#include "csp_pseudo_intrinsics.h"
#include "csp_nvic.h"
#include "csp_debug.h"			   
//#include "csp_svc_handler.h"	  

#include "csp_adc.h"
#include "csp_can.h"
#include "csp_cm.h"
#include "csp_dma.h"
#include "csp_enc.h"
#include "csp_frt.h"
#include "csp_gpio.h"
#include "csp_i2c.h"
#include "csp_ifc.h"
#include "csp_imc.h"
#include "csp_ioconf.h"
#include "csp_lcdc.h"
#include "csp_opamp.h"
#include "csp_pwm.h"
#include "csp_ssp.h"
#include "csp_stt.h"
#include "csp_tc16.h"
#include "csp_tc32.h"
#include "csp_usart.h"
#include "csp_usb.h"
#include "csp_wdt.h"

/******************************************************************************
* FLASH and SRAM Base Addresses
******************************************************************************/
/** Program flash controller base address                          			*/
#define PFLASH_BASE_ADDRESS     ((U32_T) 0x00000000)
/** SRAM base address 			                                            */	
#define SRAM_BASE_ADDRESS       ((U32_T) 0x20000000)							
/** SRAM bit band base address                                              */
#define SRAM_BB_BASE_ADDRESS    ((U32_T) 0x22000000)
/** SRAM mirror area base address                                           */
#define SRAM_MR_BASE_ADDRESS    ((U32_T) 0x10000000)

/******************************************************************************
* Peripheral Base Addreses
******************************************************************************/
/** Peripheral size            								 				*/
#define PERIPH_SIZE				0x1000ul     

/** Peripheral  base address 												*/                                                 
#define PSEL0_BASE_ADDRESS     	 ((U32_T) 0x40000000)

/** Memory part */
#define MEM_BASE_ADDRESS		(PSEL0_BASE_ADDRESS + 0x10000)
#define IFC0_BASE_ADDRESS    	(MEM_BASE_ADDRESS + 0x0000)
#define IFC0_OFFSET             (IFC0_BASE_ADDRESS - IFC0_BASE_ADDRESS)

/** System part */
#define SYS_BASE_ADDRESS       	(PSEL0_BASE_ADDRESS + 0x20000)
#define CM0_BASE_ADDRESS       	(SYS_BASE_ADDRESS + 0x0000)
#define CM0_OFFSET            	(CM0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/** WDT & FRT part */
#define WDT_BASE_ADDRESS        (PSEL0_BASE_ADDRESS + 0x30000)
#define WDT0_BASE_ADDRESS       (WDT_BASE_ADDRESS + 0x0000)
#define FRT0_BASE_ADDRESS       (WDT_BASE_ADDRESS + 0x1000)
#define WDT0_OFFSET             (WDT0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)
#define FRT0_OFFSET             (FRT0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/** ADC & DAC & OP-AMP part */
#define ADC_BASE_ADDRESS       	(PSEL0_BASE_ADDRESS + 0x40000)
#define ADC0_BASE_ADDRESS      	(ADC_BASE_ADDRESS + 0x0000)
#define OPAMP0_BASE_ADDRESS   	(ADC_BASE_ADDRESS + 0x1000)
#define ADC0_OFFSET             (ADC0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)
#define OPAMP0_OFFSET           (OPAMP0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/** GPIO part */
#define GPIO_BASE_ADDRESS       (PSEL0_BASE_ADDRESS + 0x50000)
#define GPIO0_BASE_ADDRESS     	(GPIO_BASE_ADDRESS + 0x0000)
#define GPIO1_BASE_ADDRESS      (GPIO_BASE_ADDRESS + 0x1000)
#define IOCONF0_BASE_ADDRESS    (GPIO_BASE_ADDRESS + 0x8000)
#define GPIO_OFFSET(n)			(GPIO_BASE_ADDRESS + 0x1000*(n) - PSEL0_BASE_ADDRESS)
#define IOCONF0_OFFSET   		 (IOCONF0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/** Timer part */
#define TC_BASE_ADDRESS         (PSEL0_BASE_ADDRESS + 0x60000)
#define TC0_BASE_ADDRESS        (TC_BASE_ADDRESS + 0x0000)
#define TC1_BASE_ADDRESS        (TC_BASE_ADDRESS + 0x1000)
#define TC2_BASE_ADDRESS        (TC_BASE_ADDRESS + 0x2000)
#define TC3_BASE_ADDRESS        (TC_BASE_ADDRESS + 0x3000)
#define TC4_BASE_ADDRESS        (TC_BASE_ADDRESS + 0x4000)
#define TC5_BASE_ADDRESS        (TC_BASE_ADDRESS + 0x5000)
#define TC6_BASE_ADDRESS        (TC_BASE_ADDRESS + 0x6000)
#define TC7_BASE_ADDRESS        (TC_BASE_ADDRESS + 0x7000)
#define STT0_BASE_ADDRESS		(TC_BASE_ADDRESS + 0x8000)
#define TC_OFFSET(n)            (TC_BASE_ADDRESS + 0x1000*(n) - PSEL0_BASE_ADDRESS)
			 
/**  PWM part */
#define PWM_BASE_ADDRESS        (PSEL0_BASE_ADDRESS + 0x70000)
#define PWM0_BASE_ADDRESS       (PWM_BASE_ADDRESS + 0x0000)
#define PWM1_BASE_ADDRESS       (PWM_BASE_ADDRESS + 0x1000)
#define PWM_OFFSET(n)           (PWM_BASE_ADDRESS + 0x1000*(n) - PSEL0_BASE_ADDRESS)

/**  USART part */
#define USART_BASE_ADDRESS      (PSEL0_BASE_ADDRESS + 0x80000)
#define USART0_BASE_ADDRESS     (USART_BASE_ADDRESS + 0x0000)
#define USART1_BASE_ADDRESS     (USART_BASE_ADDRESS + 0x1000)
#define USART2_BASE_ADDRESS     (USART_BASE_ADDRESS + 0x2000)
#define USART_OFFSET(n)         (USART_BASE_ADDRESS + 0x1000*(n)- PSEL0_BASE_ADDRESS)

/**  SPI part */
#define SSP_BASE_ADDRESS        (PSEL0_BASE_ADDRESS + 0x90000)
#define SSP0_BASE_ADDRESS       (SSP_BASE_ADDRESS + 0x0000)
#define SSP1_BASE_ADDRESS       (SSP_BASE_ADDRESS + 0x1000)
#define SSP_OFFSET(n)          	(SSP_BASE_ADDRESS + 0x1000*(n) - PSEL0_BASE_ADDRESS)

/**  I2C part */
#define I2C_BASE_ADDRESS        (PSEL0_BASE_ADDRESS + 0xA0000)
#define I2C0_BASE_ADDRESS       (I2C_BASE_ADDRESS + 0x0000)
#define I2C1_BASE_ADDRESS       (I2C_BASE_ADDRESS + 0x1000)
#define I2C_OFFSET(n)           (I2C_BASE_ADDRESS + 0x1000*(n)- PSEL0_BASE_ADDRESS)

/** IMC part */
#define IMC_BASE_ADDRESS        (PSEL0_BASE_ADDRESS + 0xB0000)
#define IMC0_BASE_ADDRESS       (IMC_BASE_ADDRESS + 0x0000)
#define IMC0_OFFSET             (IMC0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/** ENC part */
#define ENC_BASE_ADDRESS        (PSEL0_BASE_ADDRESS + 0xC0000)
#define ENC0_BASE_ADDRESS       (ENC_BASE_ADDRESS + 0x0000)
#define ENC0_OFFSET             (ENC0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/** LCDC part */
#define LCDC_BASE_ADDRESS       (PSEL0_BASE_ADDRESS + 0xD0000)
#define LCDC0_BASE_ADDRESS      (LCDC_BASE_ADDRESS + 0x0000)
#define LCDC0_OFFSET            (LCDC0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/**  CAN part */
#define CAN_BASE_ADDRESS        (PSEL0_BASE_ADDRESS + 0xE0000)
#define CAN0_BASE_ADDRESS       (CAN_BASE_ADDRESS + 0x0000)
#define CAN0_OFFSET             (CAN0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/** DMA part */
#define DMA_BASE_ADDRESS        (PSEL0_BASE_ADDRESS + 0xF0000)
#define DMA0_BASE_ADDRESS       (DMA_BASE_ADDRESS + 0x0000)
#define DMA0_OFFSET             (DMA0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/** USB part */
#define USB_BASE_ADDRESS       	(PSEL0_BASE_ADDRESS + 0x100000)
#define USB0_BASE_ADDRESS      	(USB_BASE_ADDRESS + 0x0000)
#define USB0_OFFSET             (USB0_BASE_ADDRESS - PSEL0_BASE_ADDRESS)

/*****************************************************************************
* Core Debug / System Debug / TPIU Base Registers
******************************************************************************/
/** Data Watchpoint adn Trace												*/
#define DWT_BASE_ADDRESS   		((U32_T)0xE0001000) 
/** Data Watchpoint adn Trace												*/
#define DWT_PART_BASE_ADDRESS	 ((U32_T)0xE0001020) 
/**	Breakpoint Unit															*/
#define BPU_BASE_ADDRESS		((U32_T)0xE0002000)  

/******************************************************************************
* System Control Space (SCS) Base Addresses
******************************************************************************/
#define SCS_BASE_ADDRESS        ((U32_T)0xE000E000)  
#define SYSTICK0_BASE_ADDRESS	((U32_T)0xE000E010)
#define NVIC0_BASE_ADDRESS     	((U32_T)0xE000E100)
#define SCB0_BASE_ADDRESS      	((U32_T)0xE000ED00)
#define DCB_BASE_ADDRESS		((U32_T)0xE000EDF0)  

/******************************************************************************
* IRQ sources
******************************************************************************/
#define NVIC_WDT		((U8_T)0x00)     /**< Watchdog Timer          */
#define NVIC_FRT       	((U8_T)0x01)     /**< Free Running Timer      */
#define NVIC_CM    		((U8_T)0x02)     /**< Clock Management	      */
#define NVIC_IFC        ((U8_T)0x03)     /**< Flash controller        */
#define NVIC_DMA      	((U8_T)0x04)     /**< DMA                     */
#define NVIC_ADC		((U8_T)0x05)     /**< ADC                     */
#define NVIC_WSI0      	((U8_T)0x06)     /**< WakeupSource 0          */
#define NVIC_TC0       	((U8_T)0x07)     /**< TC0                     */
#define NVIC_IMC       	((U8_T)0x08)     /**< IMC                     */
#define NVIC_ENC       	((U8_T)0x09)     /**< ENC                     */
#define NVIC_TC1        ((U8_T)0x0A)     /**< TC1                     */
#define NVIC_USART0 	((U8_T)0x0B)     /**< USART0                  */
#define NVIC_PWM0       ((U8_T)0x0C)     /**< PWM0                    */
#define NVIC_SSP0       ((U8_T)0x0D)     /**< SSP0                    */
#define NVIC_I2C0       ((U8_T)0x0E)     /**< I2C0                    */
#define NVIC_USART1     ((U8_T)0x0F)     /**< USART1                  */
#define NVIC_TC2        ((U8_T)0x10)     /**< TC2                     */
#define NVIC_USART2     ((U8_T)0x11)     /**< USART2                  */
#define NVIC_TC3        ((U8_T)0x12)     /**< TC3                     */
#define NVIC_SSP1       ((U8_T)0x13)     /**< SSP1                    */
#define NVIC_I2C1       ((U8_T)0x14)     /**< I2C1                    */
#define NVIC_PWM1       ((U8_T)0x15)     /**< PWM1                    */
#define NVIC_TC4        ((U8_T)0x16)     /**< TC4                     */
#define NVIC_TC5        ((U8_T)0x17)     /**< TC5                     */
#define NVIC_TC6        ((U8_T)0x18)     /**< TC6                     */
#define NVIC_TC7        ((U8_T)0x19)     /**< TC7                     */
#define NVIC_USB        ((U8_T)0x1A)     /**< USB                     */
#define NVIC_CAN        ((U8_T)0x1B)     /**< CAN                     */
#define NVIC_STT        ((U8_T)0x1C)     /**< STT	               	  */
#define NVIC_GPIO0      ((U8_T)0x1D)     /**< GPIO0                   */
#define NVIC_GPIO1      ((U8_T)0x1E)     /**< GPIO1                   */
#define NVIC_WSIx       ((U8_T)0x1F)     /**< WakeupSource X          */

/******************************************************************************
********************* External Peripheral Declaration *************************
******************************************************************************/
#ifndef DEBUG	   
#define ADC0			((CSP_ADC_T *) ADC0_BASE_ADDRESS)
#define CAN0			((CSP_CAN_T *) CAN0_BASE_ADDRESS)
#define CM0				((CSP_CM_T *) CM0_BASE_ADDRESS)
#define DMA0			((CSP_DMA_T *) DMA0_BASE_ADDRESS)
#define ENC0			((CSP_ENC_T *) ENC0_BASE_ADDRESS)
#define FRT0			((CSP_FRT_T *) FRT0_BASE_ADDRESS)
#define GPIO0			((CSP_GPIO_T *) GPIO0_BASE_ADDRESS)
#define GPIO1			((CSP_GPIO_T *) GPIO1_BASE_ADDRESS)
#define I2C0			((CSP_I2C_T *) I2C0_BASE_ADDRESS)
#define I2C1			((CSP_I2C_T *) I2C1_BASE_ADDRESS)
#define IMC0			((CSP_IMC_T *) IMC0_BASE_ADDRESS)
#define IOCONF0			((CSP_IOCONF_T *) IOCONF0_BASE_ADDRESS)
#define LCDC0			((CSP_LCDC_T *) LCDC0_BASE_ADDRESS)
#define OPAMP0			((CSP_OPAMP_T *) OPAMP0_BASE_ADDRESS)
#define IFC0			((CSP_IFC_T *) IFC0_BASE_ADDRESS)
#define PWM0			((CSP_PWM_T *) PWM0_BASE_ADDRESS)
#define PWM1			((CSP_PWM_T *) PWM1_BASE_ADDRESS)
#define SSP0			((CSP_SSP_T *) SSP0_BASE_ADDRESS)
#define SSP1			((CSP_SSP_T *) SSP1_BASE_ADDRESS)
#define TC0				((CSP_TC16_T *) TC0_BASE_ADDRESS)
#define TC1				((CSP_TC16_T *) TC1_BASE_ADDRESS)
#define TC2				((CSP_TC16_T *) TC2_BASE_ADDRESS)
#define TC3				((CSP_TC16_T *) TC3_BASE_ADDRESS)
#define TC4				((CSP_TC16_T *) TC4_BASE_ADDRESS)
#define TC5				((CSP_TC16_T *) TC5_BASE_ADDRESS)
#define TC6				((CSP_TC32_T *) TC6_BASE_ADDRESS)
#define TC7				((CSP_TC32_T *) TC7_BASE_ADDRESS)
#define STT0 			((CSP_STT_T *) STT0_BASE_ADDRESS)
#define USART0			((CSP_USART_T *) USART0_BASE_ADDRESS)
#define USART1			((CSP_USART_T *) USART1_BASE_ADDRESS)
#define USART2			((CSP_USART_T *) USART2_BASE_ADDRESS)
#define USB0			((CSP_USB_T *) USB0_BASE_ADDRESS)
#define WDT0			((CSP_WDT_T *) WDT0_BASE_ADDRESS)

#define DWT0			((CSP_DWT_T *) DWT_BASE_ADDRESS)
#define DWT0_PART		((CSP_DWT_PART_T *) DWT_PART_BASE_ADDRESS)
#define BPU0			((CSP_BPU_T *) BPU_BASE_ADDRESS)

#define SCB0			((CSP_SCB_T *) SCB0_BASE_ADDRESS)
#define SYSTICK0		((CSP_SYSTICK_T *) SYSTICK0_BASE_ADDRESS)
#define NVIC0			((CSP_NVIC_T *) NVIC0_BASE_ADDRESS)
#define DEBUG0			((CSP_DEBUG_T *) DEBUG_BASE_ADDRESS)
  
#else /** DEBUG */
/* Peripherals */
extern CSP_ADC_T      	*ADC0;
extern CSP_CAN_T      	*CAN0;
extern CSP_CM_T       	*CM0;
extern CSP_DMA_T      	*DMA0;
extern CSP_ENC_T      	*ENC0;
extern CSP_FRT_T      	*FRT0;
extern CSP_GPIO_T     	*GPIO0;
extern CSP_GPIO_T     	*GPIO1;
extern CSP_I2C_T      	*I2C0;
extern CSP_I2C_T      	*I2C1; 

extern CSP_IMC_T     	*IMC0;
extern CSP_IOCONF_T		*IOCONF0;
extern CSP_LCDC_T     	*LCDC0;
extern CSP_OPAMP_T   	*OPAMP0;
extern CSP_IFC_T      	*IFC0;
extern CSP_PWM_T      	*PWM0;
extern CSP_PWM_T     	*PWM1;
extern CSP_SSP_T      	*SSP0;
extern CSP_SSP_T      	*SSP1;
extern CSP_TC16_T		*TC0;

extern CSP_TC16_T	 	*TC1;
extern CSP_TC16_T       *TC2;
extern CSP_TC16_T       *TC3;
extern CSP_TC16_T       *TC4;
extern CSP_TC16_T       *TC5;
extern CSP_TC32_T       *TC6;
extern CSP_TC32_T       *TC7;
extern CSP_STT_T       	*STT0;

extern CSP_USART_T    	*USART0;
extern CSP_USART_T    	*USART1;
extern CSP_USART_T    	*USART2;
extern CSP_USB_T		*USB0;
extern CSP_WDT_T		*WDT0;

/** Cortex-M0 Peripherals */
extern CSP_SYSTICK_T	*SYSTICK0;
extern CSP_NVIC_T     	*NVIC0;
extern CSP_SCB_T      	*SCB0;
extern CSP_DEBUG_T		*DEBUG0;
extern CSP_BPU_T      	*BPU0;
extern CSP_DWT_T      	*DWT0;
extern CSP_DWT_PART_T	*DWT0_PART;	  

#endif /** DEBUG */

#endif   /** CSP_H */
