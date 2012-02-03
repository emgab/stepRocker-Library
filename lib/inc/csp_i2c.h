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
* @file name	csp_i2c.h
* @description Definitions, Macros and function declarations for I2C
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_I2C_H
#define CSP_I2C_H

/******************************************************************************
************************** I2C Structure Definition ***************************
******************************************************************************/

/******************************************************************************
@brief description CSP_I2C_T and CSP_I2C_PTR
******************************************************************************/
 typedef struct
 {
    CSP_REGISTER_T      IDR;	/**< ID Register	                  		*/
    CSP_REGISTER_T      CEDR;   /**< Clock Enable/Disable Register       	*/
    CSP_REGISTER_T      SRR;    /**< Software Reset Register              	*/
    CSP_REGISTER_T      CR;     /**< Control Register                     	*/
    CSP_REGISTER_T      MR;     /**< Mode Register                        	*/
    CSP_REGISTER_T      SR;     /**< Status Register                      	*/
    CSP_REGISTER_T      IMSCR;  /**< Interrupt Mask Set/Clear Register   	*/
    CSP_REGISTER_T      RISR;   /**< Raw Interrupt Status Register        	*/
    CSP_REGISTER_T      MISR;   /**< Masked Interrupt Status Register     	*/
    CSP_REGISTER_T      ICR;   	/**< Masked Interrupt Status Register     	*/
    CSP_REGISTER_T  	SDR;   	/**< Serial Data Register                 	*/
    CSP_REGISTER_T  	SSAR;   /**< Serial Slave Address Register        	*/
    CSP_REGISTER_T  	HSDR;   /**< Hold/Setup Delay Register            	*/
    CSP_REGISTER_T  	DMACR;  /**< DMA Control Register                 	*/
 } CSP_I2C_T, *CSP_I2C_PTR;

/******************************************************************************
************************** I2C Registers Definition ***************************
******************************************************************************/
/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define I2C_IPIDCODE_MASK  (0x03FFFFFFul << 0)   	/**<  IPIDCODE mask     */
#define I2C_IPIDCODE  	   (0x0001000E << 0)   	 	/**<  IPIDCODE value    */

/** Get IDR register                                                         */
#define CSP_I2C_GET_IDR(i2c)        ((i2c)->IDR)

/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define I2C_CLKEN          (0x01ul << 0)         /**< i2c Clock             */

/** Set CEDR register 		                                                */
#define CSP_I2C_SET_CEDR(i2c, val)    ((i2c)->CEDR = (val))

/** Get CEDR register                                               		*/
#define CSP_I2C_GET_CEDR(i2c)        ((i2c)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define I2C_SWRST          (0x01ul << 0)         /**< Software Reset        */

/** Set SRR register 		                                             	*/
#define CSP_I2C_SET_SRR(i2c, val)    ((i2c)->SRR = (val))

/******************************************************************************
* CR : I2C Control Register
******************************************************************************/
#define I2C_AA             (0x01ul << 1)   /**< I2C Acknowledge Mask        */
#define I2C_AA_NO          (0x00ul << 1)   /**< I2C No Acknowledge          */
#define I2C_AA_RET         (0x01ul << 1)   /**< I2C Acknowledge Returned    */
#define I2C_STO            (0x01ul << 2)   /**< I2C Stop                    */
#define I2C_STA            (0x01ul << 3)   /**< I2C Start Mask              */
#define I2C_STA_MASTER     (0x01ul << 3)   /**< I2C Start Master            */
#define I2C_STA_SLAVE      (0x00ul << 3)   /**< I2C Start Slave             */
#define I2C_ENA            (0x01ul << 8)   /**< I2C Enable Mask             */
#define I2C_ENABLE         (0x01ul << 8)   /**< I2C Enable                  */
#define I2C_DISABLE        (0x00ul << 8)   /**< I2C Disable                 */

/* CR : I2C Control Register                                                 */
/** Get CR register                                                          */
#define CSP_I2C_GET_CR(i2c)            ((i2c)->CR)

/** Set CR register                                                          */
#define CSP_I2C_SET_CR(i2c, val)       ((i2c)->CR = (val))

/******************************************************************************
* MR : I2C Mode Register
******************************************************************************/
/** PRV : Prescaler Value                                                    */
#define I2C_PRV_MASK  (0xFFFul << 0)           /**< Prescaler Value Mask    */
#define I2C_PRV(val)  (((val) & 0xFFFul) << 0) /**< Prescaler Value
                                                   Writing Macro            */
#define I2C_FAST      (0x01ul  << 12)          /**< Enable/Disable Fast Mode*/
#define I2C_STANDARD  (0x00ul  << 12)          /**< Enable/Disable Fast Mode*/

/* MR : I2C Mode Register                                                    */
/** Get MR register                                                          */
#define CSP_I2C_GET_MR(i2c)            ((i2c)->MR)

/** Set MR register                                                          */
#define CSP_I2C_SET_MR(i2c, mode)      ((i2c)->MR = (mode))

/***************************************************************************** *
SR : I2C Status Register - Refer to I2C Registers mask
******************************************************************************/
/** Get SR register (Status)                                                 */
#define CSP_I2C_GET_SR(i2c)            ((i2c)->SR)

/******************************************************************************
* Master Transmitter mode status codes
******************************************************************************/
#define I2C_MTX_START                0x08u  /**< START condition has been
                                                  transmitted                */
#define I2C_MTX_RSTART               0x10u  /**< REPEAT START condition has
                                                  been transmitted           */
#define I2C_MTX_SADDR_ACK            0x18u  /**< Slave address and WRITE has
                                                  been sent, ACK received    */
#define I2C_MTX_SADDR_NACK           0x20u  /**< Slave address and WRITE has
                                                  been sent, No ACK received */
#define I2C_MTX_DATATX_ACK           0x28u  /**< Data byte transmitted,
                                                  ACK received               */
#define I2C_MTX_DATATX_NACK          0x30u  /**< Data byte transmitted,
                                                  No ACK received            */
#define I2C_MTX_AL                   0x38u  /**< Arbitration lost           */

/******************************************************************************
* Master Receiver mode status codes
******************************************************************************/
#define I2C_MRX_START                0x08u  /**< START condition has been
                                                 transmitted                */
#define I2C_MRX_RSTART               0x10u  /**< REPEAT START condition has
                                                  been transmitted           */
#define I2C_MRX_AL                   0x38u  /**< Arbitration lost           */
#define I2C_MRX_SADDR_ACK            0x40u  /**< Slave address and Read has
                                                  been sent, ACK received    */
#define I2C_MRX_SADDR_NACK           0x48u  /**< Slave address and Read has
                                                 been sent, No ACK received */
#define I2C_MRX_DATARX_ACK           0x50u  /**< Data byte received,
                                                  ACK returned               */
#define I2C_MRX_DATARX_NACK          0x58u  /**< Data byte received,
                                                  No ACK returned            */
/******************************************************************************
* Slave Receiver mode status codes
******************************************************************************/
#define I2C_SRX_OADDR_WRI_ACK        0x60u  /**< Own Slave address + WRITE
                                                 received, ACK returned     */
#define I2C_SRX_AL_OADDR_ACK         0x68u  /**< Arbitration lost, own slave
                                                 address received,
                                                 ACK returned               */
#define I2C_SRX_GCA_ACK              0x70u  /**< General Call Address has
                                                 been received, ACK returned*/
#define I2C_SRX_AL_GCADDR_ACK        0x78u  /**< Arbitration lost, general
                                                 call address received,
                                                 ACK returned               */
#define I2C_SRX_OADDR_DATARX_ACK     0x80u  /**< Addressed with own address
                                                 and W, data byte received,
                                                 ACK returned               */
#define I2C_SRX_OADDR_DATARX_NACK    0x88u  /**< Addressed with own address,
                                                 data byte received,
                                                 no ACK returned            */
#define I2C_SRX_GCADDR_DATARX_ACK    0x90u  /**< Addressed by general call
                                                 address, data byte received,
                                                 ACK returned               */
#define I2C_SRX_GCADDR_DATARX_NACK   0x98u  /**< Addressed by general call
                                                 address, data byte received,
                                                 no ACK returned            */
#define I2C_SRX_STOP_START           0xA0u  /**< A stop or repeated start
                                                 has been received while
                                                 still addressed as slave   */
/*****************************************************************************
* Slave Transmitter mode status codes
******************************************************************************/
#define I2C_STX_OADDR_READ_ACK       0xA8u  /**< Own Slave address +        */
                                            /**< R received, ACK returned   */
#define I2C_STX_AL_OADDR_ACK         0xB0u  /**< Arbitration lost, own slave*/
                                            /**< address has been received, */
                                            /**< ACK returned               */
#define I2C_STX_DATATX_ACK           0xB8u  /**< Data has been transmitted, */
                                            /**< ACK has been received      */
#define I2C_STX_DATATX_NACK          0xC0u  /**< Data has been transmitted, */
                                            /**< No ACK has been received   */
#define I2C_STX_LDATATX_ACK          0xC8u  /**< Last data has been
                                                 transmitted, ACK received  */
/*****************************************************************************
* Miscellaneous status codes
******************************************************************************/
#define I2C_NO_INFORMATION           0xF8u  /**< No revelant state
                                                 information                */
#define I2C_BUS_ERROR                0x00u  /**< Bus error due to an illegal*/
                                            /**< START or STOP condition    */
/******************************************************************************
* IMSCR : Interrupt Mask Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Interrupt Status Register
* ICR : Interrupt Clear Register
******************************************************************************/
#define I2C_SI				(0x01ul << 4)

/** Set IMSCR register                                                      */
#define CSP_I2C_SET_IMSCR(i2c, val)    ((i2c)->IMSCR = (val))

/** Get IMSCR register                                                      */
#define CSP_I2C_GET_IMSCR(i2c)          ((i2c)->IMSCR)

/** Get RISR register (Status)                                              */
#define CSP_I2C_GET_RISR(i2c)          ((i2c)->RISR)

/** Get MISR register (Status)                                              */
#define CSP_I2C_GET_MISR(i2c)          ((i2c)->MISR)

/** Set ICR register                                                       */
#define CSP_I2C_SET_ICR(i2c, val)     ((i2c)->ICR = (val))

/******************************************************************************
*  SDR : I2C Serial Data Registers
******************************************************************************/
#define I2C_DATA_RST    (0xFFul << 0)            	/**< Data reset value	*/
#define I2C_DATA(val)	(((val) & 0xFFul) << 0)  	/**< Data Writing Macro */

/* SDR : I2C Serial Data Register                                            */
/** Get SDR register                                                         */
#define CSP_I2C_GET_SDR(i2c)          ((i2c)->SDR)

/** Set DAT register                                                         */
#define CSP_I2C_SET_SDR(i2c, val)      ((i2c)->SDR = (val))

/******************************************************************************
*  SSAR : I2C Serial Slave Address Registers
******************************************************************************/
#define I2C_GC         	(0x01ul << 0)           /**< General call           */
#define I2C_ADDR_RST   	(0x7Ful << 1)           /**< Address reset value    */
#define I2C_ADDR(val)	(((val) & 0x7Ful) << 1) /**< Writing Macro          */

/* SSAR : I2C Serial Slave Address Register                                 */
/** Get ADR register                                                        */
#define CSP_I2C_GET_SSAR(i2c)           ((i2c)->SSAR)
/** Set ADR register                                                        */
#define CSP_I2C_SET_SSAR(i2c, val)      ((i2c)->SSAR = (val))

/******************************************************************************
*  HSDR : I2C Hold/Setup Delay Registers
******************************************************************************/
#define I2C_DL_RST 		(0xFFul << 0)     /**< Hold/Setup Delay reset value */
#define I2C_DL(val)    	(((val) & 0xFFul) << 0)  /**< Hold/Setup Delay      */

/* HSDR : I2C Hold/Setup Delay Register                                     */
/** Get HSDR register                                                       */
#define CSP_I2C_GET_HSDR(i2c)         ((i2c)->HSDR)

/** Set THOLD register                                                      */
#define CSP_I2C_SET_HSDR(i2c, val)    ((i2c)->HSDR = (val))

/******************************************************************************
*  DMACR : DMA Control Register
******************************************************************************/
#define I2C_RXDMAE	(0x01ul << 0) /**<DMA for the receive En/Disable control */
#define I2C_TXDMAE  (0x01ul << 1) /**<DMA for the transmit En/Disable control*/

/** Set DMACR register                                                       */
#define CSP_I2C_SET_DMACR(i2c, val)     ((i2c)->DMACR = (val))

/** Get DMACR register (Status)                                              */
#define CSP_I2C_GET_DMACR(i2c)          ((i2c)->DMACR)

/*******************************************************************************
*********************** I2C Registers reset value ******************************
********************************************************************************/
#define I2C_IDR_MASK     (0x03FFFFFFul)  /**< IDR mask                        */
#define I2C_CEDR_MASK	 (0x00000001ul)  /**< CEDR mask                       */
#define I2C_SRR_MASK     (0x00000001ul)  /**< SRR mask                        */
#define I2C_CR_MASK      (0x0000010Eul)  /**< CR mask                         */
#define I2C_MR_MASK      (0x00001FFFul)  /**< MR mask                         */
#define I2C_SR_MASK      (0x000000F8ul)  /**< SR mask                         */
#define I2C_IMSCR_MASK   (0x00000010ul)  /**< IMSCR mask                      */
#define I2C_RISR_MASK    (0x00000010ul)  /**< RISR mask                       */
#define I2C_MISR_MASK    (0x00000010ul)  /**< MISR mask                       */
#define I2C_ICR_MASK     (0x00000010ul)  /**< ICR mask                        */
#define I2C_SDR_MASK     (0x000000FFul)  /**< Serial Data Register mask       */
#define I2C_SSAR_MASK    (0x000000FFul)  /**< Serail Slave Address mask       */
#define I2C_HSDR_MASK    (0x000000FFul)  /**< Hold/Setup Delay Register mask  */
#define I2C_DMACR_MASK   (0x00000003ul)  /**< DMACR mask                      */
/******************************************************************************
************************* I2C Registers reset value ***************************
******************************************************************************/
#define I2C_IDR_RST     (0x0001000Eul)  /**< IDR reset value                 */
#define I2C_CEDR_RST	(0x00000000ul)  /**< CEDR reset value                */
#define I2C_SRR_RST     (0x00000000ul)  /**< SRR reset value                 */
#define I2C_CR_RST      (0x00000000ul)  /**< CR reset value                  */
#define I2C_MR_RST      (0x000001F4ul)  /**< MR reset value                  */
#define I2C_SR_RST      (0x000000F8ul)  /**< SR reset value                  */
#define I2C_IMSCR_RST   (0x00000000ul)  /**< IMSCR reset value               */
#define I2C_RISR_RST    (0x00000000ul)  /**< RISR reset value                */
#define I2C_MISR_RST    (0x00000000ul)  /**< MISR reset value                */
#define I2C_ICR_RST     (0x00000000ul)  /**< ICR reset value                 */
#define I2C_SDR_RST     (0x00000000ul)  /**< Serial Data reset value 		 */
#define I2C_SSAR_RST    (0x00000000ul)  /**< Serail Slave Address reset value*/
#define I2C_HSDR_RST    (0x00000001ul)  /**< Hold/Setup Delay reset value    */
#define I2C_DMACR_RST   (0x00000000ul)  /**< DMACR reset value               */
/******************************************************************************
********************* I2C External Functions Declaration **********************
******************************************************************************/
extern void CSP_I2CInit(CSP_I2C_T *i2c, U32_T mode_u32, U32_T thold_u32);
extern void CSP_I2CClose(CSP_I2C_T *i2c);
extern void CSP_I2CConfigInterrupt(CSP_I2C_T *i2c, U32_T intMask_u32,
                                   		FunctionalStatus newState);
extern void CSP_I2CModeConfig(CSP_I2C_T *i2c, U16_T cr_u16, U8_T add_u8);

#endif   /**< CSP_I2C_H */

