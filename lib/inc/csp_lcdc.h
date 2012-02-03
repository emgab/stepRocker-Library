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
* @file name	csp_lcdc.h
* @description Definitions, Macros and function declarations for LCD controller
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Younghee.Jin		 Creation
* |0.1 ADD 2010.08.23.   Younghee.Jin	     Add Pin,Clock configuration function
* |    MOD 2010.08.23.	 Younghee.Jin        Correction: Reserved[252]-->[251]
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_LCDC_H
#define CSP_LCDC_H

typedef enum
{
	Nodivider = 0x0,
	Dividers = 0x1
}eClockConfig;

typedef enum
{
	AllSegOff = 0x0,
	AllSegOn  = 0x1,
	Normal = 0x2,
	Disable = 3
}eDisplayMode;

typedef enum
{
	InternalRbias = 0x0,
	ExternalRbias = 0x1
}eBiasType;

typedef enum
{
	Static = 0x0,
	Duty2Bias2 = 0x1,
	Duty3Bias2 = 0x2,
	Duty3Bias3 = 0x3,
	Duty4Bias3 = 0x4,
	Duty8Bias4 = 0x5
}eDutyBiasMode;
/******************************************************************************
************************* LCD Structure Definition ****************************
******************************************************************************/

/******************************************************************************
@brief LCD Structure
******************************************************************************/
typedef struct
{ 
   CSP_REGISTER_T  IDR;				/**< ID Register	              	  */
   CSP_REGISTER_T  CEDR;           	/**< Clock Enable/Disable Register    */
   CSP_REGISTER_T  SRR;            	/**< Software Reset Register          */
   CSP_REGISTER_T  CR;           	/**< Control Register                 */
   CSP_REGISTER_T  CDR;            	/**< Clock Divider Register           */
   CSP_REGISTER_T  Reserved[251];					
   CSP_REGISTER_T  DMR[32];        	/**< LCD Display Memory Register      */
} CSP_LCDC_T, *CSP_LCDC_PTR;

/******************************************************************************
************************* LCDC Registers Definition ***************************
******************************************************************************/
/******************************************************************************
* CEDR Register
******************************************************************************/
#define LCDC_CLKEN      (0x01ul << 0)         /**< LCD Clock Enable          */

/******************************************************************************
* SRR Register
******************************************************************************/
#define LCDC_SWRST      (0x01ul << 0)         /**< LCD Software Reset        */


/******************************************************************************
* CR Register
******************************************************************************/	
#define LCDC_LCDEN      (0x01ul << 0)       /**< LCD Enable                 */

#define LCDC_DISC(val) 	((0x03ul & val) << 1) /**< Display Control          */
#define LCDC_DISOFF		(0x00ul << 0) 
#define LCDC_DISON 		(0x01ul << 0) 
#define LCDC_NORMAL 	(0x02ul << 0) 

#define LCDC_BTSEL      (0x01ul << 4)       /**< LCD Enable                 */	 
#define LCDC_IBIAS   	(0x00ul)            /**< Static Mode             */
#define LCDC_EBIAS		(0x01ul << 4)

#define LCDC_DBSEL(val) ((0x07ul & val) << 8) /**< Display Control          */
#define LCDC_STATIC    	(0x00ul)              /**< Static Mode             */
#define LCDC_2D2B      	(0x01ul)              /**< 1/2 Duty, 1/2 Bias mode */
#define LCDC_3D2B      	(0x02ul)              /**< 1/3 Duty, 1/2 Bias mode */
#define LCDC_3D3B      	(0x03ul)              /**< 1/3 Duty, 1/3 Bias mode */
#define LCDC_4D3B      	(0x04ul)              /**< 1/4 Duty, 1/3 Bias mode */
#define LCDC_8D4B      	(0x05ul)              /**< 1/8 Duty, 1/4 Bias mode */

/******************************************************************************
* CDR Register
******************************************************************************/
#define LCDC_CDIV(val) ((0x07ul & val) << 0)   /**< Display Control           */
#define LCDC_CDC       (0x01ul<<7)             /**< Clock Divider Control Bit */
#define LCDC_CPRE(val) ((0x0FFFFul & val) << 8)/**< Writing macro             */

/*******************************************************************************
* DMRX Registers
*******************************************************************************/
#define LCDC_SEGxCOM_MASK  (0xFFul)      	/**< COM mask in DMx registers   */
#define LCDC_SEGxCOM0      (0x1ul)      	/**< COM 0 mask in DMx registers */
#define LCDC_SEGxCOM1      (0x2ul)     		/**< COM 1 mask in DMx registers */
#define LCDC_SEGxCOM2      (0x4ul)      	/**< COM 2 mask in DMx registers */
#define LCDC_SEGxCOM3      (0x8ul)      	/**< COM 3 mask in DMx registers */
#define LCDC_SEGxCOM4      (0x10ul)      	/**< COM 4 mask in DMx registers */
#define LCDC_SEGxCOM5      (0x20ul)      	/**< COM 5 mask in DMx registers */
#define LCDC_SEGxCOM6      (0x40ul)      	/**< COM 6 mask in DMx registers */
#define LCDC_SEGxCOM7      (0x80ul)      	/**< COM 7 mask in DMx registers */

/******************************************************************************
***************************** LCDC Registers mask *****************************
******************************************************************************/
#define LCDC_IDR_MASK     	(0x03FFFFFFul)        /**< ECR mask                */
#define LCDC_CEDR_MASK		(0x00000001ul)        /**< DCR mask                */
#define LCDC_SRR_MASK      	(0x000000001ul)       /**< PMSR mask               */
#define LCDC_CR_MASK      	(0x00000717ul)        /**< CR mask                 */
#define LCDC_CDR_MASK      	(0x00FFFF87ul)        /**< MR mask                 */
#define LCDC_DMRX_MASK     	(0x000000FFul)        /**< DMX mask                */

/******************************************************************************
************************* LCDC Registers reset value **************************
******************************************************************************/
#define LCDC_IDR_RST     	(0x00110022ul)        /**< ECR reset               */
#define LCDC_CEDR_RST      	(0x00000000ul)        /**< DCR reset               */
#define LCDC_SRR_RST     	(0x00000000ul)        /**< PMSR reset              */
#define LCDC_CR_RST       	(0x00000000ul)        /**< CR reset                */
#define LCDC_CDR_RST       	(0x00000000ul)        /**< MR reset                */
#define LCDC_DMRX_RST      	(0x00000000ul)        /**< DMX reset               */
			
/******************************************************************************
*************************** LCDC Macros Definition ****************************
******************************************************************************/
/* IDR : ID register                               							*/
/** Get IDR register (Status)                                               */
#define CSP_LCDC_GET_IDR(lcdc)      	((lcdc)->IDR)

/** Set CEDR register                                                        */
#define CSP_LCDC_SET_CEDR(lcdc, val)	((lcdc)->CEDR = (val))
/** Get CEDR register (Status)                                               */
#define CSP_LCDC_GET_CEDR(lcdc)		((lcdc)->CEDR)

/* SRR : Software Register	                                     			*/
/** Set SRR register                                                        */
#define CSP_LCDC_SET_SRR(lcdc, val)  	((lcdc)->SRR = (val))
 
/* CR : LCDC Control Register                                                */
/** Set CR register                                                          */
#define CSP_LCDC_SET_CR(lcdc,val)       ((lcdc)->CR = (val))
/** Get CR register   														 */	
#define CSP_LCDC_GET_CR(lcdc)   	    ((lcdc)->CR)

/* CDR : Clock Divider Register                                              */
/** Get CDR register 		                                            	 */
#define CSP_LCDC_GET_CDR(lcdc)          ((lcdc)->CDR)
/** Set CDR register (Mode Register)                                         */
#define CSP_LCDC_SET_CDR(lcdc,mode)     ((lcdc)->CDR = (mode))


/* DMRX : LCDC Display Memory Register                                       */
/** Set DMX register (Status Register)                                       */
#define CSP_LCDC_SET_DMR(lcdc,mem,val)   ((lcdc)->DMR[mem] = (val))
/** Get DMX register (Status Register)                                       */
#define CSP_LCDC_GET_DMR(lcdc,mem)       ((lcdc)->DMR[mem])

/******************************************************************************
********************* LCDC External Functions Declaration *********************
******************************************************************************/
extern void CSP_LCDPinConfig(void);
extern void CSP_LCDClockSrcConfig(eCM_MdCLK clksrc,U32_T Jdiv,U32_T Kdiv);
extern void CSP_LCDClockConfig(eClockConfig clkctr, U32_T Prescale, U32_T Cdiv);
extern void CSP_LCDEnable(void);
extern void CSP_LCDSoftwareReset(void);  
extern void CSP_LCDDisplayMode(eDisplayMode whichMode,FunctionalStatus endis);
extern void CSP_LCDBiasType(eBiasType whichType);
extern void CSP_LCDDutyBiasConfig(eDutyBiasMode whichMode);
extern void CSP_LCDWriteDisplayMemory(U32_T numMem, U32_T segData);

#endif   /* CSP_LCDC_H */
