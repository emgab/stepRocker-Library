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
* @file name	csp_ifc.h
* @description Definitions, Macros and function declarations for Flash Controller
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+---------+------------------------------------
* |0.0 NEW 2009.12.01.   Yh JIN	   Creation
* |0.1 MOD 2009.12.12.   Ys OH     Add new APIs
* |0.1                             change MACROs in CR
* |0.2 ADD 2009.12.17.   YS OH     Add CSP_IFCGetFlagStatus, CSP_IFCGetRawITStatus
* |0.2                             CSP_IFCClearITFlag, CSP_IFCUnlockFlash
* |0.2                             IFC_CMD_MASK, CSP_IFCGetMaskedITStatus
* |0.3 MOD 2010.01.07.   Ys OH     Fix IFC_IDCODE, CEDR reset value
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_IFC_H
#define CSP_IFC_H

#include "csp.h"

/******************************************************************************
************************* IFC Structure Definition ***************************
******************************************************************************/
/******************************************************************************
@brief IFC Structure
******************************************************************************/ 
typedef struct
{
	CSP_REGISTER_T  IDR;		/**< ID Register	            		*/
	CSP_REGISTER_T  CEDR;      	/**< Clock Enable/Disable Register  	*/
	CSP_REGISTER_T  SRR;       	/**< Software Reset Register        	*/
	CSP_REGISTER_T  CR;        	/**< Control Register                   */
	CSP_REGISTER_T  MR;        	/**< Mode Register                    	*/
	CSP_REGISTER_T  IMSCR;     	/**< Interrupt Set/Clear Register       */
	CSP_REGISTER_T  RISR;      	/**< Raw Interrupt Status Register      */
	CSP_REGISTER_T  MISR;      	/**< Masked Interrupt Status Register   */
	CSP_REGISTER_T  ICR;       	/**< Clear Status Register              */
	CSP_REGISTER_T  SR;        	/**< Status Register                    */
	CSP_REGISTER_T  AR;        	/**< Address Register             		*/
	CSP_REGISTER_T  DR;	 		/**< Data Register             			*/
	CSP_REGISTER_T  KR;        	/**< Key Register    					*/
	CSP_REGISTER_T  SOPSR;     	/**< Smart Option - Protection Status 	*/
	CSP_REGISTER_T  SOCSR;     	/**< Smart Option - Configuration Status*/
	CSP_REGISTER_T  IOTR;
} CSP_IFC_T, *CSP_IFC_PTR;

/******************************************************************************
************************** IFC Registers Definition ***************************
******************************************************************************/
/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define IFC_IDCODE_MASK (0x3FFFFFF << 0)      /**< IDCODE mask	     	*/
#define IFC_IDCODE      (0x00020019ul << 0)   /**< flash ID code	    */

/** IDR : ID CODE register			                              		*/
#define CSP_IFC_GET_IDR(ifc)                  ((ifc)->IDR & IFC_IDCODE_MASK)

/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define IFC_CLKEN      (0x01ul << 0)  	 /**< flash clock enable	     	*/

/** CEDR : Clock en/disable register			               		     	*/
#define CSP_IFC_SET_CEDR(ifc, val)             ((ifc)->CEDR = val)

/** CEDR : Clock en/disable register			                      		*/
#define CSP_IFC_GET_CEDR(ifc)                  ((ifc)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define IFC_SWRST      (0x01ul << 0)  	 /**< software reset	     */

/** CEDR : Clock en/disable register			                     */
#define CSP_IFC_SET_SRR(ifc, val)               ((ifc)->SRR = val)

/*******************************************************************************
* CR Register
*******************************************************************************/
#define IFC_START       (0x01ul << 0)   /**< flash operation (P/ER) start bit*/
#define IFC_CMD(val)	((0x7ul & val) << 4)
#define IFC_CMD_MASK    (0x7ul << 4)
#define IFC_NP       	(0x01ul)     /**< flash normal program            	*/
#define IFC_PE       	(0x02ul)     /**< flash page erase              	*/
#define IFC_SE       	(0x03ul)     /**< flash sector erase                */
#define IFC_CE       	(0x04ul)     /**< flash chip erase              	*/
#define IFC_SOP      	(0x05ul)     /**< flash smart option program      	*/
#define IFC_SOE      	(0x06ul)     /**< flash smart option erase        	*/

/** CR : Control register			                     */
#define CSP_IFC_SET_CR(ifc, val)               ((ifc)->CR = val)

/** CR : Control register			                      */
#define CSP_IFC_GET_CR(ifc)                  ((ifc)->CR)

/******************************************************************************
* MR Register
******************************************************************************/
#define IFC_BACEN     (0x01ul << 0)     /**< Boot area enable */
#define IFC_FSMODE    (0x01ul << 7)     /**< flash high speed mode selection */

/** MR : Mode register			                     */
#define CSP_IFC_SET_MR(ifc, val)             ((ifc)->MR = val)

/** MR : Mode register			                      */
#define CSP_IFC_GET_MR(ifc)                  ((ifc)->MR)

/******************************************************************************
* IMSCR : Interrupt Mask Set/Clear Register
* RISR 	: Raw Interrupt Status Register
* MISR 	: Masked Interrupt Status Register
* ICR	: Interrupt Clear Register
******************************************************************************/
#define IFC_END		(0x01ul << 0)	/**< Sable	                     	*/
#define IFC_ERR0	(0x01ul << 8) 	/**< ESCLK fail status end         	*/
#define IFC_ERR1    (0x01ul << 9) 	/**< ESCLK fail (clock monitor)    	*/
#define IFC_ERR2    (0x01ul << 10) 	/**< EMCLk fail status end         	*/

/** Set IMSCR register                                                       */
#define CSP_IFC_SET_IMSCR(ifc, val)       (ifc->IMSCR = (val))

/** Get IMSCR register                                                       */
#define CSP_IFC_GET_IMSCR(ifc)            (ifc->IMSCR)

/** Get RISR register                                                        */
#define CSP_IFC_GET_RISR(ifc)            (ifc->RISR)

/** Get MISR register                                                        */
#define CSP_IFC_GET_MISR(ifc)            (ifc->MISR)

/** Set ICR register                                                         */
#define CSP_IFC_SET_ICR(ifc, val)       (ifc->ICR = (val))

/*******************************************************************************
* SR : Status Register
*******************************************************************************/
#define IFC_BUSY     (0x01ul << 0)     /**< Busy flag */

/** SR : Status register			                      */
#define CSP_IFC_GET_SR(ifc)                  ((ifc)->SR)

/*******************************************************************************
* AR : Address Register
*******************************************************************************/
#define IFC_ADDR_MASK	(0xFFFFFFFFul << 0)
#define IFC_ADDR(val)   ((0xFFFFFFFFul & val) << 0)

/** AR: Program Start Address Value Register                            */
#define IFC_SOPADDR		(0x000000C0ul << 0)
#define IFC_SOCADDR		(0x000000C4ul << 0)

/** Set AR register                                                       */
#define CSP_IFC_SET_AR(ifc, val)    ((ifc)->AR = val)

/** Get AR register                                                       */
#define CSP_IFC_GET_AR(ifc)         ((ifc)->AR)

/*******************************************************************************
* DR : Data Register
*******************************************************************************/
/** Set DR register                                                       */
#define CSP_IFC_SET_DR(ifc, val)    ((ifc)->DR = val)

/** Get DR register                                                       */
#define CSP_IFC_GET_DR(ifc)         ((ifc)->DR)

/*******************************************************************************
* KR : KEY Registers
*******************************************************************************/
#define IFC_KEY_MASK      	(0xFFFFFFFF << 0)
#define IFC_KEYDAT(val)     ((0xFFFFFFFF & val) << 0)
#define IFC_KEY             (0x5A5A5A5Aul <<0)

/** Set KEY register                                                       */
#define CSP_IFC_SET_KR(ifc, key)    ((ifc)->KR = key)

/*******************************************************************************
* SOPSR : Smart Option Protection Status Register
*******************************************************************************/
#define IFC_NJTAGP              (0x01ul << 8)
#define IFC_NHWP                (0x01ul << 17)
#define IFC_NSRP                (0x01ul << 27)

#define IFC_NHWPA_ALL			(0xF0F0F0F0)
#define IFC_NHWPA0              (0x01ul << 4)
#define IFC_NHWPA1              (0x01ul << 5)
#define IFC_NHWPA2              (0x01ul << 6)
#define IFC_NHWPA3              (0x01ul << 7)
#define IFC_NHWPA4              (0x01ul << 12)
#define IFC_NHWPA5              (0x01ul << 13)
#define IFC_NHWPA6              (0x01ul << 14)
#define IFC_NHWPA7              (0x01ul << 15)
#define IFC_NHWPA8              (0x01ul << 20)
#define IFC_NHWPA9              (0x01ul << 21)
#define IFC_NHWPA10             (0x01ul << 22)
#define IFC_NHWPA11             (0x01ul << 23)
#define IFC_NHWPA12             (0x01ul << 28)
#define IFC_NHWPA13             (0x01ul << 29)
#define IFC_NHWPA14             (0x01ul << 30)
#define IFC_NHWPA15             (0x01ul << 31)

/** PTSOR: IFC Protection smart option read register                         */
/** Get PTSOR register                                                       */
#define CSP_IFC_GET_SOPSR(ifc)    ((ifc)->SOPSR)

/*******************************************************************************
* SOCSR : Smart Option Configuration Status Register
*******************************************************************************/
#define IFC_POCCS_MASK		(0x3ul << 0)
#define IFC_POCCS(val)      ((0x3ul & val) << 0)
#define IFC_SO_ESCLK	    (0x00ul << 0)
#define IFC_SO_EMCLK	    (0x01ul << 0)
#define IFC_SO_ISCLK	    (0x02ul << 0)
#define IFC_SO_IMCLK	    (0x03ul << 0)

#define IFC_XIO 		    (0x01ul << 2)
#define IFC_XTIO	        (0x01ul << 3)
#define IFC_NRST	        (0x01ul << 4)

#define IFC_IMSEL_MASK		(0x3ul << 6)
#define IFC_IMSEL(val)      ((0x3ul & val) << 6)
#define IFC_IMCLK8	        (0x01ul)
#define IFC_IMCLK16		    (0x02ul)
#define IFC_IMCLK20		    (0x03ul)

#define IFC_BTDIV(val)      ((0xFul & val) << 12)
#define IFC_BTDIV1	        (0x03ul)
#define IFC_BTDIV2	        (0x04ul)
#define IFC_BTDIV4	        (0x05ul)
#define IFC_BTDIV8	        (0x06ul)
#define IFC_BTDIV16	        (0x07ul)
#define IFC_BTDIV32	        (0x08ul)
#define IFC_BTDIV64	        (0x09ul)
#define IFC_BTDIV128	 	(0x0Aul)
#define IFC_BTDIV256	 	(0x0Bul)
#define IFC_BTDIV512	 	(0x0Cul)
#define IFC_BTDIV1024	 	(0x0Dul)
#define IFC_BTDIV2048	  	(0x0Eul)
#define IFC_BTDIV4096	 	(0x0Ful)

#define CSP_IFC_GET_SOCSR(ifc)    ((ifc)->SOCSR)

/*******************************************************************************
* IOTR : Internal OSC Trimming Register
*******************************************************************************/
#define IFC_OSC0(val)	((0x7Ful & val) << 0)
#define IFC_OSC(val)	((0x3Ful & val) << 16)
#define IFC_IOTKEY     	((0x53 & 0xFF) << 24)

/** Get IOTR register                                                       */
#define CSP_IFC_GET_IOTR(ifc)   ((ifc)->IOTR)

/** Set IOTR register                                                       */
#define CSP_IFC_SET_IOTR(ifc, val)    ((ifc)->IOTR = (val|IFC_IOTKEY))

/******************************************************************************
***************************** IFC Registers mask ******************************
*******************************************************************************/
#define IFC_IDR_MASK	(0x03FFFFFFul <<0) 	/**< IFC IPIDCODE            */
#define IFC_CEDR_MASK   (0x00000001ul)      /**< ECR mask                */
#define IFC_SRR_MASK    (0x00000001ul)      /**< DCR mask                */
#define IFC_CR_MASK     (0x00000071ul)      /**< CR mask                 */
#define IFC_MR_MASK     (0x00000081ul)      /**< MR mask                 */
#define IFC_IMSCR_MASK  (0x00000701ul)      /**< IER mask                */
#define IFC_RISR_MASK   (0x00000701ul)      /**< IDR mask                */
#define IFC_MISR_MASK   (0x00000701ul)      /**< IMR mask                */
#define IFC_ICR_MASK    (0x00000701ul)      /**< IMR mask                */
#define IFC_SR_MASK     (0x00000001ul)      /**< SR mask                 */
#define IFC_AR_MASK   	(0xFFFFFFFFul)      /**< CFGCR mask              */
#define IFC_DR_MASK     (0xFFFFFFFFul)      /**< PTSO mask               */
#define IFC_KR_MASK     (0xFFFFFFFFul)      /**< KEY mask                */
#define IFC_SOPSR_MASK  (0xF8F2F1F0ul)      /**< STADDR mask             */
#define IFC_SOCSR_MASK 	(0x0000F0DFul)      /**< PECCADDR mask           */
#define IFC_IOTR_MASK	(0x003F7F7Ful)

/******************************************************************************
************************* IFC Registers reset value ***************************
*******************************************************************************/
#define IFC_IDR_RST     (0x00020019ul) 		  /**< ID reset value 	        */
#define IFC_CEDR_RST    (0x00000000ul)        /**< CR reset value           */
#define IFC_SRR_RST     (0x00000000ul)        /**< MR reset value           */
#define IFC_CR_RST      (0x00000000ul)        /**< CSR reset value          */
#define IFC_MR_RST      (0x00000000ul)        /**< SR reset value           */
#define IFC_IMSCR_RST   (0x00000000ul)        /**< IER reset value          */
#define IFC_RISR_RST    (0x00000000ul)        /**< IDR reset value          */
#define IFC_MISR_RST    (0x00000000ul)        /**< IMR reset value          */
#define IFC_ICR_RST    	(0x00000000ul)        /**< CFGCR reset value        */
#define IFC_SR_RST   	(0x00000000ul)        /**< PTSOR reset value        */
#define IFC_AR_RST   	(0x00000000ul)        /**< STADDR reset value       */
#define IFC_DR_RST 		(0x00000000ul)        /**< PECCADDR reset value     */
#define IFC_KR_RST 		(0x00000000ul)        /**< DECCADDR reset value     */
#define IFC_SOPSR_RST   (0xFFFFFFFFul)        /**< DATn reset value         */
#define IFC_SOCSR_RST   (0xFFFFFFFFul)        /**< DATn reset value         */

/*******************************************************************************
* IFC CSP Driver Enum Declaration
*******************************************************************************/
typedef enum
{
	CSP_IFC_OK = 0,
   	CSP_IFC_BUSY,
	CSP_IFC_ERR0,
	CSP_IFC_ERR1,
	CSP_IFC_ERR2,  /* timeout error */
   	CSP_IFC_INVALID_PARAMETER
} eCSP_IFC_ERROR_E;

/******************************************************************************
* IFC CSP Driver Enum Declaration
******************************************************************************/
typedef enum
{
	IFC_NORMAL_PROGRAM = 1,
	IFC_SECTOR_ERASE=2,
	IFC_PAGE_ERASE=3,
	IFC_CHIP_ERASE=4,
	IFC_SMART_PROGRAM=5,
	IFC_SMART_ERASE=6
} eCSP_IFCCmd;

/*******************************************************************************
* IFC CSP Driver Enum Declaration
*******************************************************************************/
typedef enum
{
	CSP_IFC_Programming = 0,
	CSP_IFC_Erasing,
	CSP_IFC_TIMEOUT,
	CSP_IFC_NOT_BUSY,
	CSP_IFC_END
} eCSP_IFCStatus;

/******************************************************************************
* IFC CSP Driver Enum Declaration
******************************************************************************/
typedef enum
{
	CSP_IFC_POLLING_ON_BUSY = 0,
	CSP_IFC_POLLING,
	CSP_IFC_INTERRUPT
} eCSP_IFCMode;

typedef enum
{
	PageErase	= 0x0,
	SectorErase = 0x1,
	ChipErase 	= 0x2
}eEraseType; 

/******************************************************************************
* IFC CSP Driver Declaration
******************************************************************************/
typedef struct
{
	U32_T 	*source_ptr_u32;
	U32_T   *destination_ptr_u32;
	U32_T   nb_data_u32;
	eCSP_IFCStatus status_e;
} CSP_IFC_STATUS_T, CSP_IFC_STATUS_PTR;

typedef enum
{
	CSP_ChipErase = IFC_CMD(IFC_CE),
	CSP_SectorErase = IFC_CMD(IFC_SE),
	CSP_PageErase = IFC_CMD(IFC_PE),
	CSP_NormalProgram = IFC_CMD(IFC_NP),
	CSP_SmartProgram = IFC_CMD(IFC_SOP),
	CSP_SmartErase = IFC_CMD(IFC_SOE)
} eCSP_IFCCommand;

typedef enum
{
	CSP_NO_JTAGProtect = IFC_NJTAGP,
	CSP_NO_HWProtect = IFC_NHWP,
	CSP_NO_SerialReadProtect = IFC_NSRP
} eCSP_IFCSOProtect;

/*****************************************************************************
* IFC CSP Driver
******************************************************************************/
extern CSP_IFC_STATUS_T CSP_IFCStatus_t;

/******************************************************************************
********************* IFC External Functions Declaration **********************
*******************************************************************************/
extern void CSP_IFCInit(CSP_IFC_T *const ifc, U32_T mode_u32);
extern void CSP_IFCConfigInterrupt(CSP_IFC_T *const ifc,
		U32_T intMask_u32, \
		FunctionalStatus newState);
extern eCSP_IFC_ERROR_E CSP_IFCErase(CSP_IFC_T *const ifc, eCSP_IFCMode mode_e,\
		U32_T addr, U32_T command);
extern eCSP_IFC_ERROR_E CSP_IFCWrite(CSP_IFC_T *const ifc, eCSP_IFCMode mode_e,
		U32_T *dest_ptr_u32, \
		U32_T *src_ptr_u32,\
		U32_T nb_data_u32, U32_T command);
extern FlagStatus CSP_IFCGetFlagStatus(CSP_IFC_T *const ifc, U32_T Flag);
extern ITStatus CSP_IFCGetRawITStatus(CSP_IFC_T *const ifc, U32_T InterruptStatus);
extern ITStatus CSP_IFCGetMaskedITStatus(CSP_IFC_T *const ifc, U32_T InterruptStatus);
extern void CSP_IFCClearITFlag(CSP_IFC_T *const ifc, U32_T Flag);
extern void CSP_IFCUnlockFlash(CSP_IFC_T *const ifc);
extern void CSP_IFCConfigBootSectorProtect(CSP_IFC_T *const ifc, FunctionalStatus newState);
extern void CSP_IFCReset(CSP_IFC_T *const ifc);
extern void CSP_IFCConfigInterleave(CSP_IFC_T *const ifc, FunctionalStatus newState);
extern U32_T CSP_IFCGetSmartOptionProtect(CSP_IFC_T *const ifc);
extern U32_T CSP_IFCGetSmartOptionConfig(CSP_IFC_T *const ifc);

#endif   /* CSP_IFC_H */
