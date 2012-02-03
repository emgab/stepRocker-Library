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
* @file name	csp_ioconf.h
* @description Definitions, Macros and function declarations for IO Configuration
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_IOCONF_H
#define CSP_IOCONF_H

/******************************************************************************
************************* IO CONF Structure Definition ************************
******************************************************************************/
#define UNUSED_ADDRESS      0xDEADDEADul     /**< Unused address              */

typedef enum {
	GROUP0 = 0,
	GROUP1 = 1
} eGROUPy;

/******************************************************************************
@brief description CSP_IOCONF_T and CSP_IOCONF_CFG_PTR
******************************************************************************/
typedef struct
{
	CSP_REGISTER_T MLR0;
	CSP_REGISTER_T MHR0;
	CSP_REGISTER_T PUCR0;
	CSP_REGISTER_T ODCR0;
	CSP_REGISTER_T MLR1;
	CSP_REGISTER_T MHR1;
	CSP_REGISTER_T PUCR1;
	CSP_REGISTER_T ODCR1;
} CSP_IOCONF_T, *CSP_IOCONF_PTR;

/******************************************************************************
************************ IO_CONF Registers Definition *************************
******************************************************************************/
#define IO_Port0  (0x00ul)          /**< IO 0 pin                     */
#define IO_Port1  (0x01ul)          /**< IO 1 pin                     */
#define IO_Port2  (0x02ul)          /**< IO 2 pin                     */
#define IO_Port3  (0x03ul)          /**< IO 3 pin                     */
#define IO_Port4  (0x04ul)          /**< IO 4 pin                     */
#define IO_Port5  (0x05ul)          /**< IO 5 pin                     */
#define IO_Port6  (0x06ul)          /**< IO 6 pin                     */
#define IO_Port7  (0x07ul)          /**< IO 7 pin                     */
#define IO_Port8  (0x08ul)          /**< IO 8 pin                     */
#define IO_Port9  (0x09ul)          /**< IO 9 pin                     */
#define IO_Port10 (0x0Aul)          /**< IO 10 pin                    */
#define IO_Port11 (0x0Bul)          /**< IO 11 pin                    */
#define IO_Port12 (0x0Cul)          /**< IO 12 pin                    */
#define IO_Port13 (0x0Dul)          /**< IO 13 pin                    */
#define IO_Port14 (0x0Eul)          /**< IO 14 pin                    */
#define IO_Port15 (0x0Ful)          /**< IO 15 pin                    */
#define IO_Port16 (0x10ul)          /**< IO 16 pin                    */
#define IO_Port17 (0x11ul)          /**< IO 17 pin                    */
#define IO_Port18 (0x12ul)          /**< IO 18 pin                    */
#define IO_Port19 (0x13ul)          /**< IO 19 pin                    */
#define IO_Port20 (0x14ul)          /**< IO 20 pin                    */
#define IO_Port21 (0x15ul)          /**< IO 21 pin                    */
#define IO_Port22 (0x16ul)          /**< IO 22 pin                    */
#define IO_Port23 (0x17ul)          /**< IO 23 pin                    */
#define IO_Port24 (0x18ul)          /**< IO 24 pin                    */
#define IO_Port25 (0x19ul)          /**< IO 25 pin                    */
#define IO_Port26 (0x1Aul)          /**< IO 26 pin                    */
#define IO_Port27 (0x1Bul)          /**< IO 27 pin                    */
#define IO_Port28 (0x1Cul)          /**< IO 28 pin                    */
#define IO_Port29 (0x1Dul)          /**< IO 29 pin                    */
#define IO_Port30 (0x1Eul)          /**< IO 30 pin                    */
#define IO_Port31 (0x1Ful)          /**< IO 31 pin                    */

/******************************************************************************
* MLRx : Mode Low Register x
* MHRx : Mode High Register x
******************************************************************************/
#define IOCONF_FSEL_MASK	(0x3ul)
#define IOCONF_F0			(0x0)	/* Function 0 - GPIO 		*/
#define IOCONF_F1			(0x1)	/* Function 1				*/
#define IOCONF_F2			(0x2)	/* Function 2				*/
#define IOCONF_F3			(0x3)	/* Function 3				*/

/** Set MRx register                                                        */
#define CSP_IOCONF_SET_MLR0(ioconf,val) (ioconf->MLR0 = (val))
#define CSP_IOCONF_SET_MHR0(ioconf,val) (ioconf->MHR0 = (val))
#define CSP_IOCONF_SET_MLR1(ioconf,val) (ioconf->MLR1 = (val))
#define CSP_IOCONF_SET_MHR1(ioconf,val) (ioconf->MHR1 = (val))

/** Get MRx register                                                        */
#define CSP_IOCONF_GET_MLR0(ioconf) (ioconf->MLR0)
#define CSP_IOCONF_GET_MHR0(ioconf) (ioconf->MHR0)
#define CSP_IOCONF_GET_MLR1(ioconf) (ioconf->MLR1)
#define CSP_IOCONF_GET_MHR1(ioconf) (ioconf->MHR1)
/******************************************************************************
* PUCRx: Pull-up enable/disable
******************************************************************************/
#define IOCONF_PUCR_OFFSET(group) (0x0 + IOCONF0_OFFSET + 0x4 * (group))
#define IOCONF_PUEN(port)      (0x1ul << (port))  /**< en/dis pull-up resistor*/
#define IOCONF_PUEN_BIT(port)  (port)

/** Set PUCRx register                                                        */
#define CSP_IOCONF_SET_PUCR0(ioconf, val) (ioconf->PUCR0 = (val))
#define CSP_IOCONF_SET_PUCR1(ioconf, val) (ioconf->PUCR1 = (val))

/** Get PUCRx register                                                        */
#define CSP_IOCONF_GET_PUCR0(ioconf)      (ioconf->PUCR0)
#define CSP_IOCONF_GET_PUCR1(ioconf)      (ioconf->PUCR1)

/******************************************************************************
* ODCRx: Open-drain enable/disable
******************************************************************************/
#define IOCONF_ODCR_OFFSET(group) (0x0 + IOCONF0_OFFSET + 0x4 * (group))
#define IOCONF_ODEN(port)      (0x1ul << (port))  /**< en/dis pull-up resistor*/
#define IOCONF_ODEN_BIT(port)  (port)

/** Set ODCRx register                                                        */
#define CSP_IOCONF_SET_ODCR0(ioconf, val) (ioconf->ODCR0 = (val))
#define CSP_IOCONF_SET_ODCR1(ioconf, val) (ioconf->ODCR1 = (val))

/** Get ODCRx register                                                        */
#define CSP_IOCONF_GET_ODCR0(ioconf)      (ioconf->ODCR0)
#define CSP_IOCONF_GET_ODCR1(ioconf)      (ioconf->ODCR1)

/******************************************************************************
***************************** IOCONG Registers mask ***************************
******************************************************************************/
#define IOCONF_MLR0_MASK	(0xFFFFFFFFul)    /**< MLR0 mask        		*/
#define IOCONF_MHR0_MASK    (0xFFFFFFFFul)    /**< MHR0 mask             	*/
#define IOCONF_PUCR0_MASK   (0xFFFFFFFFul)    /**< PUCR0 mask            	*/
#define IOCONF_ODCR0_MASK   (0xFFFFFFFFul)    /**< ODCR0 mask            	*/
#define IOCONF_MLR1_MASK    (0xFFFFFFFFul)    /**< MLR1 mask          	 	*/
#define IOCONF_MHR1_MASK    (0x00003FFFul)    /**< MHR1 mask        	 	*/
#define IOCONF_PUCR1_MASK   (0x007FFFFFul)    /**< PUCR1 mask            	*/
#define IOCONF_ODCR1_MASK   (0x007FFFFFul)    /**< ODCR1 mask				*/

/******************************************************************************
************************* IOCONG Registers reset value ************************
******************************************************************************/
#define IOCONF_MLR0_RST		(0x00000000ul)    /**< MLR0 reset value     	*/
#define IOCONF_MHR0_RST     (0x0000F000ul)    /**< MHR0 reset value     	*/
#define IOCONF_PUCR0_RST    (0x00000000ul)    /**< PUCR0 reset value     	*/
#define IOCONF_ODCR0_RST    (0x00000000ul)    /**< ODCR0 reset value     	*/
#define IOCONF_MLR1_RST     (0x00000000ul)    /**< MLR1 reset value     	*/
#define IOCONF_MHR1_RST     (0x00000000ul)    /**< MHR1 reset value      	*/
#define IOCONF_PUCR1_RST    (0x00000000ul)    /**< PUCR1 reset value     	*/
#define IOCONF_ODCR1_RST    (0x00000000ul)    /**< ODCR1 reset value     	*/

/******************************************************************************
******************** IO CONF External Functions Declaration *********************
******************************************************************************/
extern void CSP_IOFunctionConfigure(eGROUPy iogroup,U8_T port, U8_T function);
extern void CSP_IOPullupEnable(eGROUPy group, U8_T port);
extern void CSP_IOPullupDisable(eGROUPy group, U8_T port);
extern void CSP_IOOpendrainEnable(eGROUPy group, U8_T port);
extern void CSP_IOOpendrainDisable(eGROUPy group, U8_T port);

#endif   /** CSP_IOCONF_H */
