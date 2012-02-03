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
* @file name	csp_gpio.h
* @description Definitions, Macros and function declarations for GPIO
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_GPIO_H
#define CSP_GPIO_H

/******************************************************************************
************************ CAPTURE Structure Definition *************************
******************************************************************************/
 typedef struct
 {
    CSP_REGISTER_T  IDR;		/**< ID Register	            		*/
    CSP_REGISTER_T  CEDR;       /**< Clock Enable/Disable Register  	*/
    CSP_REGISTER_T  SRR;        /**< Software Reset Register       		*/
    CSP_REGISTER_T  IMSCR;      /**< Interrupt Mask Set/Clear Register  */
    CSP_REGISTER_T  RISR;       /**< Raw Interrupt Status Register      */
    CSP_REGISTER_T  MISR;       /**< Masked Interrupt Status Register   */
    CSP_REGISTER_T  ICR;        /**< Interrupt Clear Register           */
    CSP_REGISTER_T  OER;        /**< Output Enable Register       		*/
    CSP_REGISTER_T  ODR;        /**< Output Disable Register      		*/
    CSP_REGISTER_T  OSR;        /**< Output Status Register       		*/
    CSP_REGISTER_T  WODR;       /**< Write Output Data Register       	*/
    CSP_REGISTER_T  SODR;       /**< Set Output Data Register      		*/
    CSP_REGISTER_T  CODR;       /**< Clear Output Data Register       	*/
    CSP_REGISTER_T  ODSR;       /**< Output Data Status Register       	*/
    CSP_REGISTER_T  PDSR;       /**< Pin Data Status Register      		*/
 } CSP_GPIO_T, *CSP_GPIO_PTR;			  

/******************************************************************************
************************** GPIO Registers Definition **************************
******************************************************************************/
/******************************************************************************
* OER, ODR, OSR :
* WODR, SODR, CODR, ODSR, PDSR, MDER, MDDR : PIO Registers, Status Register and
* MDSR, CSR, SR, IER, IDR, IMR             : Interrupt Registers
******************************************************************************/
#define GPIO_P0  (0x01ul << 0)          /**< GPIO 0 pin                     */
#define GPIO_P1  (0x01ul << 1)          /**< GPIO 1 pin                     */
#define GPIO_P2  (0x01ul << 2)          /**< GPIO 2 pin                     */
#define GPIO_P3  (0x01ul << 3)          /**< GPIO 3 pin                     */
#define GPIO_P4  (0x01ul << 4)          /**< GPIO 4 pin                     */
#define GPIO_P5  (0x01ul << 5)          /**< GPIO 5 pin                     */
#define GPIO_P6  (0x01ul << 6)          /**< GPIO 6 pin                     */
#define GPIO_P7  (0x01ul << 7)          /**< GPIO 7 pin                     */
#define GPIO_P8  (0x01ul << 8)          /**< GPIO 8 pin                     */
#define GPIO_P9  (0x01ul << 9)          /**< GPIO 9 pin                     */
#define GPIO_P10 (0x01ul << 10)         /**< GPIO 10 pin                    */
#define GPIO_P11 (0x01ul << 11)         /**< GPIO 11 pin                    */
#define GPIO_P12 (0x01ul << 12)         /**< GPIO 12 pin                    */
#define GPIO_P13 (0x01ul << 13)         /**< GPIO 13 pin                    */
#define GPIO_P14 (0x01ul << 14)         /**< GPIO 14 pin                    */
#define GPIO_P15 (0x01ul << 15)         /**< GPIO 15 pin                    */
#define GPIO_P16 (0x01ul << 16)         /**< GPIO 16 pin                    */
#define GPIO_P17 (0x01ul << 17)         /**< GPIO 17 pin                    */
#define GPIO_P18 (0x01ul << 18)         /**< GPIO 18 pin                    */
#define GPIO_P19 (0x01ul << 19)         /**< GPIO 19 pin                    */
#define GPIO_P20 (0x01ul << 20)         /**< GPIO 20 pin                    */
#define GPIO_P21 (0x01ul << 21)         /**< GPIO 21 pin                    */
#define GPIO_P22 (0x01ul << 22)         /**< GPIO 22 pin                    */
#define GPIO_P23 (0x01ul << 23)         /**< GPIO 23 pin                    */
#define GPIO_P24 (0x01ul << 24)         /**< GPIO 24 pin                    */
#define GPIO_P25 (0x01ul << 25)         /**< GPIO 25 pin                    */
#define GPIO_P26 (0x01ul << 26)         /**< GPIO 26 pin                    */
#define GPIO_P27 (0x01ul << 27)         /**< GPIO 27 pin                    */
#define GPIO_P28 (0x01ul << 28)         /**< GPIO 28 pin                    */
#define GPIO_P29 (0x01ul << 29)         /**< GPIO 29 pin                    */
#define GPIO_P30 (0x01ul << 30)         /**< GPIO 30 pin                    */
#define GPIO_P31 (0x01ul << 31)         /**< GPIO 31 pin                    */
/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define GPIO_IPIDCODE_MASK  (0x03FFFFFFul << 0)    	/**<  IPIDCODE mask     */
#define GPIO_IPIDCODE  	  	(0x00010009 << 0)   	/**<  IPIDCODE mask     */

/** Set IDR register 		                                   				*/
#define CSP_GPIO_SET_IDR(gpio, val)    ((gpio)->IDR = (val))
/** Get IDR register                                                        */
#define CSP_GPIO_GET_IDR(gpio)        ((gpio)->IDR)


/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define GPIO_CLKEN          (0x01ul << 0)         	/**< PWM Clock          */

/** Set CEDR register 		                                                */
#define CSP_GPIO_SET_CEDR(gpio, val)    ((gpio)->CEDR = (val))

/** Get CEDR register                                               		*/
#define CSP_GPIO_GET_CEDR(gpio)        ((gpio)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define GPIO_SWRST          (0x01ul << 0)         	/**< Software Reset     */

/** Set SRR register 		                                           		*/
#define CSP_GPIO_SET_SRR(gpio, val)    ((gpio)->SRR = (val))

/** Get SRR register                                               	     	*/
#define CSP_GPIO_GET_SRR(gpio)        ((gpio)->SRR)

/******************************************************************************
***************************** GPIO Registers mask *****************************
******************************************************************************/

#define GPIO_IDR_MASK 	       (0x3FFFFFFFul)    /**< OER mask        	*/
#define GPIO_CEDR_MASK         (0x00000001ul)    /**< ODR mask          */
#define GPIO_SRR_MASK          (0x00000001ul)    /**< OSR mask          */
#define GPIO_IMSCR_MASK        (0xFFFFFFFFul)    /**< WODR mask         */
#define GPIO_RISR_MASK         (0xFFFFFFFFul)    /**< SODR mask         */
#define GPIO_MISR_MASK         (0xFFFFFFFFul)    /**< CODR mask         */
#define GPIO_ICR_MASK          (0xFFFFFFFFul)    /**< ODSR mask         */
#define GPIO_OER_MASK          (0xFFFFFFFFul)    /**< OER mask          */
#define GPIO_ODR_MASK          (0xFFFFFFFFul)    /**< ODR mask          */
#define GPIO_OSR_MASK          (0xFFFFFFFFul)    /**< OSR mask          */
#define GPIO_WODR_MASK         (0xFFFFFFFFul)    /**< WODR mask         */
#define GPIO_SODR_MASK         (0xFFFFFFFFul)    /**< SODR mask         */
#define GPIO_CODR_MASK         (0xFFFFFFFFul)    /**< CODR mask         */
#define GPIO_ODSR_MASK         (0xFFFFFFFFul)    /**< ODSR mask         */
#define GPIO_PDSR_MASK         (0xFFFFFFFFul)    /**< PDSR mask         */

/******************************************************************************
************************* GPIO Registers reset value ***************************
******************************************************************************/
#define GPIO_IDR_RST 	      (0x00010020ul)    /**< OER reset value        */
#define GPIO_CEDR_RST         (0x00000000ul)    /**< ODR reset value        */
#define GPIO_SRR_RST          (0x00000000ul)    /**< OSR reset value        */
#define GPIO_IMSCR_RST        (0x00000000ul)    /**< WODR reset value       */
#define GPIO_RISR_RST         (0x00000000ul)    /**< SODR reset value       */
#define GPIO_MISR_RST         (0x00000000ul)    /**< CODR reset value       */
#define GPIO_ICR_RST          (0x00000000ul)    /**< ODSR reset value       */
#define GPIO_OER_RST          (0x00000000ul)    /**< OER reset value        */
#define GPIO_ODR_RST          (0x00000000ul)    /**< ODR reset value        */
#define GPIO_OSR_RST          (0x00000000ul)    /**< OSR reset value        */
#define GPIO_WODR_RST         (0x00000000ul)    /**< WODR reset value       */
#define GPIO_SODR_RST         (0x00000000ul)    /**< SODR reset value       */
#define GPIO_CODR_RST         (0x00000000ul)    /**< CODR reset value       */
#define GPIO_ODSR_RST         (0x00000000ul)    /**< ODSR reset value       */
#define GPIO_PDSR_RST         (0x00000000ul)    /**< PDSR reset value       */

/******************************************************************************
*************************** GPIO Macros Definition ****************************
******************************************************************************/

/* OER, ODR, OSR : GPIO Output Registers                                     */
/** Set OER register (Enable)                                                */
 #define CSP_GPIO_SET_OER(gpio, val)       ((gpio)->OER = (val))
/** Set ODR register (Disable)                                               */
 #define CSP_GPIO_SET_ODR(gpio, val)       ((gpio)->ODR = (val))
/** Get OSR register (Status)                                                */
 #define CSP_GPIO_GET_OSR(gpio)            ((gpio)->OSR)

/* WODR, SODR, CODR, ODSR : PIO Control level Registers                      */
/** Set WODR register (Write)                                                */
 #define CSP_GPIO_SET_WODR(gpio, val)       ((gpio)->WODR = (val))
/** Set SODR register (Set)                                                  */
 #define CSP_GPIO_SET_SODR(gpio, val)       ((gpio)->SODR = (val))
/** Set CODR register (Clear)                                                */
 #define CSP_GPIO_SET_CODR(gpio, val)       ((gpio)->CODR = (val))
/** Get ODSR register (Status)                                               */
 #define CSP_GPIO_GET_ODSR(gpio)            ((gpio)->ODSR)

/* PDSR : PIO Status Registers                                               */
/** Get PDSR register (Pin Status)                                           */
 #define CSP_GPIO_GET_PDSR(gpio)            ((gpio)->PDSR)

/******************************************************************************
* IMSCR : Interrupt Mask Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Interrupt Status Register
* ICR : Interrupt Clear Register
******************************************************************************/
/** Set IMSCR register                                                      */
#define CSP_GPIO_SET_IMSCR(gpio, val)    ((gpio)->IMSCR = (val))

/** Get IMSCR register                                                      */
#define CSP_GPIO_GET_IMSCR(gpio)          ((gpio)->IMSCR)

/** Get RISR register (Status)                                              */
#define CSP_GPIO_GET_RISR(gpio)          ((gpio)->RISR)

/** Get MISR register (Status)                                              */
#define CSP_GPIO_GET_MISR(gpio)          ((gpio)->MISR)

/** Set ICR register                                                        */
#define CSP_GPIO_SET_ICR(gpio, val)     ((gpio)->ICR = (val))

/******************************************************************************
********************* PIO External Functions Declaration **********************
******************************************************************************/
extern void CSP_GPIOInit(CSP_GPIO_T *gpio, U32_T gpioOutput_u32);
extern void CSP_GPIOClose(CSP_GPIO_T *gpio);
extern void CSP_GPIOConfigInterrupt(CSP_GPIO_T *gpio,\
                              U32_T intMask_u32,\
                              FunctionalStatus newState);
extern U32_T CSP_GPIOGetStatus(CSP_GPIO_T *gpio);
extern void CSP_GPIOClear(CSP_GPIO_T *gpio, U32_T gpioMask_u32);
extern void CSP_GPIOSet(CSP_GPIO_T *gpio, U32_T gpioMask_u32);

#endif   /**< CSP_GPIO_H */
