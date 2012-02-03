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
* @file name	csp_opamp.h
* @description Definitions, Macros and function declarations for OPAMP
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_OPAMP_H
#define CSP_OPAMP_H

/******************************************************************************
************************* OPAMP Structure Definition **************************
******************************************************************************/
/******************************************************************************
@brief description CSP_OPAMP_T and CSP_OPAMP_PTR
******************************************************************************/
 typedef struct
 {
    CSP_REGISTER_T     	IDR;		/**< ID Register	              		*/
    CSP_REGISTER_T     	CEDR;       /**< Clock Enable/Disable Register    	*/
    CSP_REGISTER_T     	SRR;        /**< Software Reset Register          	*/
    CSP_REGISTER_T     	CR;        	/**< Control Register             		*/
    CSP_REGISTER_T     	GCR;        /**< Gain Control Register          	*/
 } CSP_OPAMP_T, *CSP_OPAMP_PTR;
					 
/******************************************************************************
************************* OPAMP Registers Definition **************************
******************************************************************************/

/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define OPAMP_IPIDCODE_MASK (0x03FFFFFFul << 0)   	 /**<  IPIDCODE mask     */
#define OPAMP_IPIDCODE  	(0x0001001F << 0)    	/**<  IPIDCODE value     */

/** Set IDR register 		                                             	*/
 #define CSP_OPAMP_SET_IDR(opamp, val)    ((opamp)->IDR = (val))

/** Get IDR register                                                        */
 #define CSP_OPAMP_GET_IDR(opamp)        ((opamp)->IDR)
 
/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define OPAMP_CLKEN          (0x01ul << 0)         /**< IP Clock            */

/** Set CEDR register 		                                                */
 #define CSP_OPAMP_SET_CEDR(opamp, val)    ((opamp)->CEDR = (val))
/** Get CEDR register                                               		*/
 #define CSP_OPAMP_GET_CEDR(opamp)        ((opamp)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define OPAMP_SWRST          (0x01ul << 0)         /**< Software Reset      */

/** Set SRR register 		                                            	*/
#define CSP_OPAMP_SET_SRR(opamp, val)    ((opamp)->SRR = (val))
/** Get SRR register                                               	     	*/
#define CSP_OPAMP_GET_SRR(opamp)        ((opamp)->SRR)

/******************************************************************************
* CR : Control Register
******************************************************************************/
#define OPAMP_OPA0      (0x01ul << 0)    /**< opamp 0 enable                 */
#define OPAMP_OPA1      (0x01ul << 1)	 /**< opamp 1 enable                 */
#define OPAMP_OPA2      (0x01ul << 2)	 /**< opamp 2 enable                 */

/** Set CR register                                                          */
#define CSP_OPAMP_SET_CR(opamp, val)     ((opamp)->CR = (val & 0x7))

/** Get CR register                                               	     	 */
#define CSP_OPAMP_GET_CR(opamp)       	 ((opamp)->CR)

/******************************************************************************
* GCR : Gain Control Register
******************************************************************************/
#define OPAMP_GCT0      (0x01ul << 7)    /**< opamp gain control type0       */
#define OPAMP_GCT1      (0x01ul << 15)	 /**< opamp gain control type1       */
#define OPAMP_GCT2      (0x01ul << 23)	 /**< opamp gain control type2       */

#define CSP_OPAMP_GV0(opamp, val)     ((opamp)->GCR = (val & 0xFul) <<0)
#define CSP_OPAMP_GV1(opamp, val)     ((opamp)->GCR = (val & 0xFul) <<8)
#define CSP_OPAMP_GV2(opamp, val)     ((opamp)->GCR = (val & 0xFul) <<16)

/** Set GCR register                         								*/
#define CSP_OPAMP_SET_GCR(opamp, val)     ((opamp)->GCR = (val ))			   
/** Get GCR register                     									*/
#define CSP_OPAMP_GET_GCR(opamp)           ((opamp)->GCR)

/******************************************************************************
***************************** OPAMP Registers mask ****************************
******************************************************************************/
#define OPAMP_IDR_MASK  (0x03FFFFFFul) 		/**< IDR mask                	*/
#define OPAMP_CEDR_MASK	(0x00000001ul)  	/**< CEDR mask               	*/
#define OPAMP_SRR_MASK  (0x00000001ul)  	/**< SRR mask                	*/
#define OPAMP_CR_MASK   (0x00000707ul)  	/**< CR mask		    		*/
#define OPAMP_GCR_MASK	(0x001F1F1Ful)  	/**< GCR mask                	*/

/******************************************************************************
************************* OPAMP Registers reset value *************************
******************************************************************************/
#define OPAMP_IDR_RST	(0x0001001Dul)  	/**< IDR reset value            */
#define OPAMP_CEDR_RST	(0x00000000ul)  	/**< CEDR reset value           */
#define OPAMP_SRR_RST   (0x00000000ul)  	/**< SRR reset value            */
#define OPAMP_CR_RST   	(0x00000000ul)  	/**< CR reset value		        */
#define OPAMP_GCR_RST   (0x00000000ul)  	/**< GCR reset value            */

/******************************************************************************
********************* OPAMP External Functions Declaration ********************
******************************************************************************/
extern void CSP_OPAMPInit(CSP_OPAMP_T *const OPAMP, U32_T mode_u32);
extern void CSP_OPAMPClose(CSP_OPAMP_T *const OPAMP);
extern void CSP_OPAMPConfigInterrupt(CSP_OPAMP_T *const OPAMP,
		                             U32_T intMask_u32,
                                     U8_T prePrio_u8,
                                     U8_T subPrio_u8,
                                     FunctionalStatus newState);
extern void CSP_OPAMPStartConversion(CSP_OPAMP_T *const OPAMP,
                                     U32_T *orderConversion_u32,
                                     U8_T nbConversion_u8);
extern void CSP_OPAMPStopConversion(CSP_OPAMP_T *const OPAMP);
extern void CSP_OPAMPEnable(CSP_OPAMP_T *const OPAMP);
extern void CSP_OPAMPDisable(CSP_OPAMP_T *const OPAMP);

#endif   /**< CSP_OPAMP_H */
