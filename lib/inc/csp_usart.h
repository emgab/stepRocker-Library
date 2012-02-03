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
* @file name	csp_usart.h
* @description Definitions, Macros and function declarations for USART
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_USART_H
#define CSP_USART_H

/******************************************************************************
************************* USART Structure Definition **************************
******************************************************************************/
#ifndef __NOTUSE_DMA_USART
#define __NOTUSE_DMA_USART
#endif

/******************************************************************************
@brief description CSP_USART_T and CSP_USART_PTR
******************************************************************************/
 typedef struct
 {
    CSP_REGISTER_T  IDR;			/**< ID Register	            		*/
    CSP_REGISTER_T  CEDR;           /**< Clock Enable/Disable Register  	*/
    CSP_REGISTER_T  SRR;            /**< Software Reset Register        	*/
    CSP_REGISTER_T  CR;             /**< Control Register               	*/
    CSP_REGISTER_T  MR;             /**< Mode Register                  	*/
    CSP_REGISTER_T  IMSCR;          /**< Interrupt Set/Clear Register   	*/
    CSP_REGISTER_T  RISR;           /**< Raw Interrupt Status Register  	*/
    CSP_REGISTER_T  MISR;           /**< Masked Interrupt Status Register	*/
    CSP_REGISTER_T  ICR;            /**< Clear Status Register              */
    CSP_REGISTER_T  SR;             /**< Status Register                 	*/
    CSP_REGISTER_T  RHR;            /**< Receiver Holding Register       	*/
    CSP_REGISTER_T  THR;            /**< Transmit Holding Register       	*/
    CSP_REGISTER_T  BRGR;           /**< Baud Rate Generator Register    	*/
    CSP_REGISTER_T  RTOR;           /**< Receiver Time-out Register      	*/
    CSP_REGISTER_T  TTGR;           /**< Transmitter Time-guard Register 	*/
    CSP_REGISTER_T  LIR;            /**< LIN Identifier Register         	*/
    CSP_REGISTER_T  DFWR0;          /**< Data Field Write 0 Register     	*/
    CSP_REGISTER_T  DFWR1;          /**< Data Field Write 1 Register     	*/
    CSP_REGISTER_T  DFRR0;          /**< Data Field Read 0 Register      	*/
    CSP_REGISTER_T  DFRR1;          /**< Data Field Read 1 Register      	*/
    CSP_REGISTER_T  SBLR;           /**< Sync Break Length Register      	*/
    CSP_REGISTER_T  LCP1;           /**< Limit counter protocol 1        	*/
    CSP_REGISTER_T  LCP2;           /**< Limit counter protocol 2        	*/
    CSP_REGISTER_T  DMACR; 			/**< DMA Control Register            	*/
 } CSP_USART_T, *CSP_USART_PTR;								

/******************************************************************************
************************* USART Registers Definition **************************
******************************************************************************/

/******************************************************************************
* IDR : USART ID Registers
******************************************************************************/
#define USART_IPIDCODE_MASK   (0x3FFFFFFul << 4) /**< USART IPIDCODE MASK   */

/******************************************************************************
* CEDR : Clock Enable/Disable Registers
******************************************************************************/
#define USART_CLKEN           (0x01ul << 0)     /**< USART Clock            */
#define USART_DBGEN           (0x01ul << 31)    /**< Debug Mode Enable      */

/******************************************************************************
* SRR : USART Software Reset Register
******************************************************************************/
#define USART_SWRST           (0x01ul << 0)     /**< Software Reset         */

/******************************************************************************
* CR : USART Control Register
******************************************************************************/
#define USART_RSTRX           (0x01ul << 2)     /**< Reset Receiver         */
#define USART_RSTTX           (0x01ul << 3)     /**< Reset Transmitter      */
#define USART_RXEN            (0x01ul << 4)     /**< Receiver Enable        */
#define USART_RXDIS           (0x01ul << 5)     /**< Receiver Disable       */
#define USART_TXEN            (0x01ul << 6)     /**< Transmitter Enable     */
#define USART_TXDIS           (0x01ul << 7)     /**< Transmitter Disable    */
#define USART_STTBRK          (0x01ul << 9)     /**< Start Break            */
#define USART_STPBRK          (0x01ul << 10)    /**< Stop Break             */
#define USART_STTTO           (0x01ul << 11)    /**< Start Time-out         */
#define USART_SENDA           (0x01ul << 12)    /**< Send Address           */
#define USART_STHEADER        (0x01ul << 16)    /**< Start Header           */
#define USART_STRESP          (0x01ul << 17)    /**< Start Response         */
#define USART_STMESSAGE       (0x01ul << 18)    /**< Send Response after Header */
#define USART_RSTLIN          (0x01ul << 19)    /**< Reset LIN APB register */

/******************************************************************************
* MR : USART Mode Register
******************************************************************************/
#define USART_LIN     (0x01ul << 0)     /**< Local Interconnect Network mode*/

/** SENDTIME : Send Time                                                    */
#define USART_SENDTIME_MASK   (0x07ul << 1)         /**< SENDTIME Mask      */
#define USART_SENDTIME(val)   (((val) & 0x07ul) << 1) /**< Writing Macro    */
#define USART_SENDTIME_0      (0x00ul << 1)         /**< Number of Time = 0 */
#define USART_SENDTIME_1      (0x01ul << 1)         /**< Number of Time = 1 */
#define USART_SENDTIME_2      (0x02ul << 1)         /**< Number of Time = 2 */
#define USART_SENDTIME_3      (0x03ul << 1)         /**< Number of Time = 3 */
#define USART_SENDTIME_4      (0x04ul << 1)         /**< Number of Time = 4 */
#define USART_SENDTIME_5      (0x05ul << 1)         /**< Number of Time = 5 */
#define USART_SENDTIME_6      (0x06ul << 1)         /**< Number of Time = 6 */
#define USART_SENDTIME_7      (0x07ul << 1)         /**< Number of Time = 7 */

/** USCLKS : Clock Selection                                                */
#define USART_CLKS_MASK       (0x03ul << 4)         /**< CLKS Mask          */
#define USART_CLKS(val)       (((val) & 0x03ul) << 4) /**< Writing Macro    */
#define USART_CLKS_MCKI       (0x00ul << 4)         /**< (MCKI)             */
#define USART_CLKS_MCKI_8     (0x01ul << 4)         /**< (MCKI/8)           */
#define USART_CLKS_SCK        (0x02ul << 4)         /**< Ext Clock (SCK)    */

/** CHRL : Character Length                                                 */
#define USART_CHRL_MASK       (0x03ul << 6)         /**< CHRL Mask          */
#define USART_CHRL(val)       (((val) & 0x03ul) << 6) /**< Writing Macro    */
#define USART_CHRL_5          (0x00ul << 6)         /**< Five bits length   */
#define USART_CHRL_6          (0x01ul << 6)         /**< Six bits length    */
#define USART_CHRL_7          (0x02ul << 6)         /**< Seven bits length  */
#define USART_CHRL_8          (0x03ul << 6)         /**< Height bits length */

/** SYNC : Synchronous Mode Select                                          */
#define USART_SYNC            (0x01ul << 8)     /**< Synchronous mode       */
#define USART_ASYNC           (0x00ul << 8)     /**< Asynchronous mode      */

/** PAR : Parity Type                                                       */
#define USART_PAR_MASK        (0x07ul << 9)         /**< PAR Mask           */
#define USART_PAR(val)        (((val) & 0x07ul) << 9) /**< Writing Macro    */
#define USART_PAR_EVEN        (0x00ul << 9)         /**< Even parity        */
#define USART_PAR_ODD         (0x01ul << 9)         /**< Odd parity         */
#define USART_PAR_SPACE       (0x02ul << 9)         /**< Space parity
                                                          (forced to 0)     */
#define USART_PAR_MARK        (0x03ul << 9)         /**< Mark parity
                                                          (forced to 1)     */
#define USART_PAR_NO          (0x04ul << 9)         /**< No parity          */
#define USART_PAR_MULTIDROP   (0x06ul << 9)         /**< Multi Drop parity  */

/** NBSTOP : Number of Stop Bits                                            */
#define USART_NBSTOP_MASK     (0x03ul << 12)        /**< NBSTOP Mask        */
#define USART_NBSTOP(val)     (((val) & 0x03ul) << 12) /**< Writing Macro   */
#define USART_NBSTOP_1        (0x00ul << 12)        /**< 1 Stop bit         */
#define USART_NBSTOP_15       (0x01ul << 12)        /**< 1.5 Stop bit       */
#define USART_NBSTOP_2        (0x02ul << 12)        /**< 2 Stop bit         */

/** CHMODE : Channel Mode                                                   */
#define USART_CHMODE_MASK     (0x03ul << 14)   /**< CHMODE Mask             */
#define USART_CHMODE(val)     (((val) & 0x03ul) << 14) /**< Writing Macro   */
#define USART_CHMODE_NORMAL   (0x00ul << 14)   /**< Normal channel          */
#define USART_CHMODE_AUTO     (0x01ul << 14)   /**< Automatic echo channel  */
#define USART_CHMODE_LOCAL    (0x02ul << 14)   /**< Local loop back channel */
#define USART_CHMODE_REMOTE   (0x03ul << 14)   /**< Remote loop back channel*/

#define USART_SMCARDPT        (0x01ul << 16)   /**< Smart Card Protocol     */

/** MODE9 : 9-Bit Character Length                                          */
#define USART_MODE8           (0x00ul << 17)    /**< 8-Bits Mode            */
#define USART_MODE9           (0x01ul << 17)    /**< 9-Bits Mode            */

/** CLKO : Clock Output Select                                              */
#define USART_CLKO            (0x01ul << 18)    /**< Clock Output           */
#define USART_CLKI            (0x00ul << 18)    /**< Clock Input            */

#define USART_LIN1_2          (0x00ul << 19) /**<Local Interconnect Network
                                                  1.2 mode*/
#define USART_LIN2_0          (0x01ul << 19) /**<Local Interconnect Network
                                                  2.0 mode*/
#define USART_DFSB            (0x01ul << 20) /**< DataFrame Start Bit       */

/******************************************************************************
* IMSCR, RISR, MISR, ICR: USART Interrupt Registers
******************************************************************************/
#define USART_RXBRK           (0x01ul << 2)     /**< Receiver break         */
#define USART_OVRE            (0x01ul << 5)     /**< Overrun Error          */
#define USART_FRAME           (0x01ul << 6)     /**< Framing Error          */
#define USART_PARE            (0x01ul << 7)     /**< Parity Error           */
#define USART_IDLE            (0x01ul << 10)    /**< IDLE (J1708 Protocol)  */
#define USART_ENDHEADER       (0x01ul << 24)    /**< End of Header occurred
                                                      on a LIN Frame         */
#define USART_ENDMESS         (0x01ul << 25)    /**< End of Message occurred
                                                      on a LIN Frame         */
#define USART_NOTRESP         (0x01ul << 26)    /**< Not Responding detected
                                                      on a LIN Frame         */
#define USART_BITERROR        (0x01ul << 27)    /**< Bit Error detectedon a
                                                     LIN Frame               */
#define USART_IPERROR         (0x01ul << 28)    /**< Identity Parity Error
                                                     detectedon a LIN Frame  */
#define USART_CHECKSUM        (0x01ul << 29)    /**< Checksum error detected
                                                     on a LIN Frame          */
#define USART_WAKEUP          (0x01ul << 30)    /**< Wake up detected       */

#define USART_TIMEOUT         (0x01ul << 8)     /**< Receiver time out      */
#define USART_TXEMPTY         (0x01ul << 9)     /**< Transmitter empty      */
#define USART_RXEND        	  (0x01ul << 3)     /**< Receive end     		*/
#define USART_TXEND        	  (0x01ul << 4)     /**< Transmit end     		*/

/** SR, IER, IDR, IMR Registers Only                                         */
#define USART_RXRDY           (0x01ul << 0)     /**< Receiver ready         */
#define USART_TXRDY           (0x01ul << 1)     /**< Transmitter ready      */

/** SR Register Only                                                         */
#define USART_IDLEFLAG        (0x01ul << 11)    /**< IDLE Flag
                                                      (J1708 Protocol)       */
/******************************************************************************
* RHR : USART Receiver Holding Register
******************************************************************************/
#define USART_RXCHR_MASK     (0x1FFul << 0)     /**< Received Character Mask*/

/******************************************************************************
* THR : USART Transmit Holding Register
******************************************************************************/
#define USART_TXCHR_MASK (0x1FFul << 0)         /**< Character to be
                                                     transmitted Mask       */
/******************************************************************************
* BRGR : USART Baud Rate Generator Register
******************************************************************************/

/** CD : Clock Divisor                                                       */
#define USART_CD_MASK       (0xFFFFul << 0)     /**< CD Mask                */
#define USART_CD(val)       ((0xFFFFul & val) << 0) /**< Writing macro      */

#define USART_CD_DISABLE    (0x00000ul)         /**< Disable Clock          */
#define USART_CD_BYPASS     (0x00001ul)         /**< Clock Divisor Bypass   */

/******************************************************************************
* RTOR : Receiver Time-out Register
******************************************************************************/
#define USART_TO_MASK      (0xFFFFul << 0)    /**< Time-out value Mask      */
#define USART_TO(val)      ((0xFFFFul & val) << 0)  /**< Writing macro      */
#define USART_TO_DISABLE   (0x0000ul)         /**< Disable Receiver Time-out*/

/******************************************************************************
* TTGR : Transmit Time-guard Register
******************************************************************************/
#define USART_TG_MASK        (0xFFul << 0)   /**< Time-guard value Mask     */
#define USART_TG(val)        ((0xFFul & val) << 0) /**< Writing macro       */
#define USART_TG_DISABLE     (0x00ul << 0)   /**< Disable Transmit
                                                   Time-guard                */
/******************************************************************************
* LIR : LIN Identifier Register
******************************************************************************/
#define USART_IDENTIFIER_MASK (0x3Ful << 0)  /**< LIN's IDENTIFER Mask      */
#define USART_IDENTIFIER(val) ((0x3F & val) << 0) /**< Writing macro        */

#define USART_NDATA_MASK (0x07ul << 6)       /**< LIN's IDENTIFER Mask      */
#define USART_NDATA(val) ((0x07ul & val) << 6) /**< Writing macro           */
#define USART_NDATA_1    (0x00ul << 6)       /**< 1 Data Field selection    */
#define USART_NDATA_2    (0x01ul << 6)       /**< 2 Data Fields selection   */
#define USART_NDATA_3    (0x02ul << 6)       /**< 3 Data Fields selection   */
#define USART_NDATA_4    (0x03ul << 6)       /**< 4 Data Fields selection   */
#define USART_NDATA_5    (0x04ul << 6)       /**< 5 Data Fields selection   */
#define USART_NDATA_6    (0x05ul << 6)       /**< 6 Data Fields selection   */
#define USART_NDATA_7    (0x06ul << 6)       /**< 7 Data Fields selection   */
#define USART_NDATA_8    (0x07ul << 6)       /**< 8 Data Fields selection   */

#define USART_CHK_SEL    (0x01ul << 9)       /**< LIN's 2.0 Checksum
                                                   selection                 */
#define USART_WAKE_UP_TIME_MASK (0x3FFFul << 16) /**< LIN's 2.0 Wake
                                                       Up time Mask          */
#define USART_WAKE_UP_TIME(val) ((0x3FFFul & val) << 16) /**< Writing macro */

/******************************************************************************
* DFWR0, DFWR1, DFRR0, DFRR1 : Data Field Register
******************************************************************************/
#define USART_DATA0_MASK     (0xFFul << 0)  /**< LIN byte field transmitted */
#define USART_DATA0(val)     (((val) & 0xFFul) << 0)  /**< Writing Macro    */
#define USART_DATA1_MASK     (0xFFul << 8)  /**< LIN byte field transmitted */
#define USART_DATA1(val)     (((val) & 0xFFul) << 8)  /**< Writing Macro    */
#define USART_DATA2_MASK     (0xFFul << 16) /**< LIN byte field transmitted */
#define USART_DATA2(val)     (((val) & 0xFFul) << 16) /**< Writing Macro    */
#define USART_DATA3_MASK     (0xFFul << 24) /**< LIN byte field transmitted */
#define USART_DATA3(val)     (((val) & 0xFFul) << 24) /**< Writing Macro    */
#define USART_DATA4_MASK     (0xFFul << 0)  /**< LIN byte field transmitted */
#define USART_DATA4(val)     (((val) & 0xFFul) << 0)  /**< Writing Macro    */
#define USART_DATA5_MASK     (0xFFul << 8)  /**< LIN byte field transmitted */
#define USART_DATA5(val)     (((val) & 0xFFul) << 8)  /**< Writing Macro    */
#define USART_DATA6_MASK     (0xFFul << 16) /**< LIN byte field transmitted */
#define USART_DATA6(val)     (((val) & 0xFFul) << 16) /**< Writing Macro    */
#define USART_DATA7_MASK     (0xFFul << 24) /**< LIN byte field transmitted */
#define USART_DATA7(val)     (((val) & 0xFFul) << 24) /**< Writing Macro    */

/******************************************************************************
* SBLR : Sync Break Length Register
******************************************************************************/
#define USART_SYNC_BRK_MASK   (0x1Ful << 0)     /**< Sync Break Length Mask */
#define USART_SYNC_BRK(val)   ((0x1Ful & val) << 0) /**< Writing macro      */

/******************************************************************************
* LCPx : Sync Break Length Register
******************************************************************************/
#define USART_LCP00_MASK       (0xFFul << 0)     /**< LCP0 Mask              */
#define USART_LCP00(val)       ((0xFFul & val) << 0) /**< Writing macro      */
#define USART_LCP01_MASK       (0xFFul << 8)     /**< LCP0 Mask              */
#define USART_LCP01(val)       ((0xFFul & val) << 8) /**< Writing macro      */
#define USART_LCP02_MASK       (0xFFul << 16)    /**< LCP0 Mask              */
#define USART_LCP02(val)       ((0xFFul & val) << 16)/**< Writing macro      */
#define USART_LCP03_MASK       (0xFFul << 24)    /**< LCP0 Mask              */
#define USART_LCP03(val)       ((0xFFul & val) << 24)/**< Writing macro      */
#define USART_LCP04_MASK       (0xFFul << 0)     /**< LCP0 Mask              */
#define USART_LCP04(val)       ((0xFFul & val) << 0) /**< Writing macro      */
#define USART_LCP05_MASK       (0xFFul << 8)     /**< LCP0 Mask              */
#define USART_LCP05(val)       ((0xFFul & val) << 8) /**< Writing macro      */
#define USART_LCP06_MASK       (0xFFul << 16)    /**< LCP0 Mask              */
#define USART_LCP06(val)       ((0xFFul & val) << 16)/**< Writing macro      */
#define USART_LCP07_MASK       (0xFFul << 24)    /**< LCP0 Mask              */
#define USART_LCP07(val)       ((0xFFul & val) << 24)/**< Writing macro      */

/******************************************************************************
* DMACR : DMA Control Register
******************************************************************************/
#define USART_RXDMAE       (0x01ul << 0)     /**< DMA RX Enable             */
#define USART_TXDMAE       (0x01ul << 1)     /**< DMA TX Enable             */

/******************************************************************************
************************** USART Macros Definition ****************************
******************************************************************************/
/* PER, PDR, PSR : USART PIO Registers                                       */
/** Set PER register (Enable)                                                */
#define CSP_USART_SET_PER(usart, val)  ((usart)->PER = (val))
/** Set PDR register (Disable)                                               */
#define CSP_USART_SET_PDR(usart, val)  ((usart)->PDR = (val))
/** Get PSR register (Disable)                                               */
#define CSP_USART_GET_PSR(usart)       ((usart)->PSR)

/* OER, ODR, OSR : USART Output Registers                                    */
/** Set OER register (Enable)                                                */
#define CSP_USART_SET_OER(usart, val)  ((usart)->OER = (val))
/** Set ODR register (Disable)                                               */
#define CSP_USART_SET_ODR(usart, val)  ((usart)->ODR = (val))
/** Get OSR register (Status)                                                */
#define CSP_USART_GET_OSR(usart)       ((usart)->OSR)

/* SODR, CODR, ODSR, PDSR : USART Output Data Registers                      */
/** Set SODR register (Set)                                                  */
#define CSP_USART_SET_SODR(usart, val) ((usart)->SODR = (val))
/** Set CODR register (Clear)                                                */
#define CSP_USART_SET_CODR(usart, val) ((usart)->CODR = (val))
/** Get ODSR register (Status)                                               */
#define CSP_USART_GET_ODSR(usart)      ((usart)->ODSR)
/** Get PDSR register (Pin Status)                                           */
#define CSP_USART_GET_PDSR(usart)      ((usart)->PDSR)

/* MDER, MDDR, MDSR : USART Multi-Driver Registers                           */
/** Set MDER register (Enable)                                               */
#define CSP_USART_SET_MDER(usart, val) ((usart)->MDER = (val))
/** Set MDDR register (Disable)                                              */
#define CSP_USART_SET_MDDR(usart, val) ((usart)->MDDR = (val))
/** Set MDSR register (Status)                                               */
#define CSP_USART_GET_MDSR(usart)      ((usart)->MDSR)

/* IDR : USART ID register                               */
/** Get IDR register (Status)                                               */
#define CSP_USART_GET_IDR(usart)      ((usart)->IDR)

/* CEDR : USART Clock Enable/Disable Registers                               */
/** Set CEDR register                                                        */
#define CSP_USART_SET_CEDR(usart, val)  ((usart)->CEDR = (val))
/** Get CEDR register (Status)                                               */
#define CSP_USART_GET_CEDR(usart)      ((usart)->CEDR)

/* SRR : USART Software Register	                                     */
/** Set SRR register                                                        */
#define CSP_USART_SET_SRR(usart, val)  ((usart)->SRR = (val))

/* CR : USART Control Register                                               */
/** Set CR register (Control Register)                                       */
#define CSP_USART_SET_CR(usart, val)   ((usart)->CR = (val))

/** MR : USART Mode Register                                                 */
/** Set MR register (Mode Register)                                          */
#define CSP_USART_SET_MR(usart, mode)  ((usart)->MR = (mode))
/** Get MR register (Mode Register)                                          */
#define CSP_USART_GET_MR(usart)        ((usart)->MR)


/* IMSCR, RISR, MISR, ICR: USART Interrupt Registers                          */
/** Set IMSCR register 			                                      */
#define CSP_USART_SET_IMSCR(usart, val)  ((usart)->IMSCR = (val))
/** Get IMSCR register (Status Interrupt)                                      */
#define CSP_USART_GET_IMSCR(usart)       ((usart)->IMSCR)

/** Get RISR register (Status Interrupt)                                      */
#define CSP_USART_GET_RISR(usart)       ((usart)->RISR)

/** Get MISR register (Status Interrupt)                                      */
#define CSP_USART_GET_MISR(usart)       ((usart)->MISR)

/** Set ICR register 			                                      */
#define CSP_USART_SET_ICR(usart, val)  ((usart)->ICR = (val))

/* SR : USART Status Register                                           */
/** Get SR register (Status Register)                                        */
#define CSP_USART_GET_SR(usart)        ((usart)->SR)

/* RHR : USART Receive Holding Register                                      */
/** Get RHR register (Receiver Holding)                                      */
#define CSP_USART_GET_RHR(usart)       ((usart)->RHR)

/* THR : USART Transmit Holding Register                                     */
/** Set THR register (Transmit Holding)                                      */
#define CSP_USART_SET_THR(usart, val)  ((usart)->THR = (val))

/* BRGR : USART Baud Rate Generator Register                                 */
/** Get BRGR register (Baud Rate Generator)                                  */
#define CSP_USART_GET_BRGR(usart)      ((usart)->BRGR)
/** Set THR register (Baud Rate Generator)                                   */
#define CSP_USART_SET_BRGR(usart, val) ((usart)->BRGR = (val))

/* RTOR : USART Receiver Time-out Register                                   */
/** Get RTOR register (Receiver Time-out)                                    */
#define CSP_USART_GET_RTOR(usart)      ((usart)->RTOR)
/** Set RTOR register (Receiver Time-out)                                    */
#define CSP_USART_SET_RTOR(usart, val) ((usart)->RTOR = (val))

/* TTGR : USART Transmitter Time-guard Register                              */
/** Get TTGR register (Transmitter Time-out)                                 */
#define CSP_USART_GET_TTGR(usart)      ((usart)->TTGR)
/** Set TTGR register (Transmitter Time-out)                                 */
#define CSP_USART_SET_TTGR(usart, val) ((usart)->TTGR = (val))

/* LIR : USART LIN Identifier Register                                       */
/** Set LIR register (LIN Identifier)                                        */
#define CSP_USART_GET_LIR(usart)       ((usart)->LIR)
/** Get LIR register (LIN Identifier)                                        */
#define CSP_USART_SET_LIR(usart, val)  ((usart)->LIR = (val))

/* DFWR0 : USART Data Field Write 0 Register                                 */
/** Get DFWR0 register (USART Data Field Write 0)                            */
#define CSP_USART_GET_DFWR0(usart)        ((usart)->DFWR0)
/** Set DFWR0 register (USART Data Field Write 0)                            */
#define CSP_USART_SET_DFWR0(usart, val)   ((usart)->DFWR0 = (val))

/* DFWR1 : USART Data Field Write 1 Register                                 */
/** Get DFWR1 register (USART Data Field Write 1)                            */
#define CSP_USART_GET_DFWR1(usart)        ((usart)->DFWR1)
/** Set DFWR1 register (USART Data Field Write 1)                            */
#define CSP_USART_SET_DFWR1(usart, val)   ((usart)->DFWR1 = (val))

/* DFRR0 : USART Data Field Read 0 Register                                  */
/** Get DFRR0 register (USART Data Field Read 0)                             */
#define CSP_USART_GET_DFRR0(usart)        ((usart)->DFRR0)

/* DFRR1 : USART Data Field Read 1 Register                                  */
/** Get DFRR1 register (USART Data Field Read 1)                             */
#define CSP_USART_GET_DFRR1(usart)        ((usart)->DFRR1)

/* SBLR : USART Sync Break Length Register                                   */
/** Get SBLR register (USART Sync Break Length)                              */
#define CSP_USART_GET_SBLR(usart)         ((usart)->SBLR)
/** Set SBLR register (USART Sync Break Length)                              */
#define CSP_USART_SET_SBLR(usart, val)    ((usart)->SBLR = (val))

/* LCPx : USART Limit Counter Protocol Register                              */
/** Get LCP1 register                                                        */
#define CSP_USART_GET_LCP1(usart)         ((usart)->LCP1)
/** Set LCP1 register                                                        */
#define CSP_USART_SET_LCP1(usart, val)    ((usart)->LCP1 = (val))
/** Get LCP1 register                                                        */
#define CSP_USART_GET_LCP2(usart)         ((usart)->LCP2)
/** Set LCP1 register                                                        */
#define CSP_USART_SET_LCP2(usart, val)    ((usart)->LCP2 = (val))

/******************************************************************************
* Mask value definition
******************************************************************************/
#define    USART_IDR_MASK      (0x03FFFFFFul)
#define    USART_CEDR_MASK     (0x80000001ul)
#define    USART_SRR_MASK      (0x00000001ul)
#define    USART_CR_MASK       (0x00031EFBul)
#define    USART_MR_MASK       (0x000FFFFFul)
#define    USART_CSR_MASK      (0x7F0004E4ul)
#define    USART_SR_MASK       (0x7F000FE7ul)
#define    USART_IMSCR_MASK    (0x7F0007E7ul)
#define    USART_RISR_MASK     (0x7F0007E7ul)
#define    USART_MISR_MASK     (0x7F0007FFul)
#define    USART_ICR_MASK      (0x7F0007FFul)
#define    USART_RHR_MASK      (0x000001FFul)
#define    USART_THR_MASK      (0x000001FFul)
#define    USART_BRGR_MASK     (0x0000FFFFul)
#define    USART_RTOR_MASK     (0x0000FFFFul)
#define    USART_TTGR_MASK     (0x000000FFul)
#define    USART_LIR_MASK      (0x3FFF03FFul)
#define    USART_DFWRX_MASK    (0xFFFFFFFFul)
#define    USART_DFRRX_MASK    (0xFFFFFFFFul)
#define    USART_SBLR_MASK     (0x0000001Ful)
#define    USART_LCP1_MASK     (0xFFFFFFFFul)
#define    USART_LCP2_MASK     (0xFFFFFFFFul)
#define    USART_DMACR_MASK    (0x00000003ul)
															
/******************************************************************************
* Reset value definition
******************************************************************************/
#define    USART_IDR_RST       	(0x0001001Bul)
#define	   USART_CEDR_RST		(0x00000000ul)
#define	   USART_SRR_RST		(0x00000000ul)
#define	   USART_CR_RST			(0x00000000ul)
#define    USART_MR_RST        	(0x00000000ul)
#define    USART_IMSCR_RST     	(0x00000000ul)
#define    USART_RISR_RST     	(0x00000000ul)
#define    USART_MISR_RST     	(0x00000000ul)
#define    USART_ICR_RST  		(0x00000000ul)
#define    USART_SR_RST        	(0x00000800ul)
#define    USART_RHR_RST       	(0x00000000ul)
#define    USART_THR_RST       	(0x00000000ul)
#define    USART_BRGR_RST      	(0x00000000ul)
#define    USART_RTOR_RST      	(0x00000000ul)
#define    USART_TTGR_RST      	(0x00000000ul)
#define    USART_LIR_RST       	(0x3AD40000ul)
#define    USART_DFWRX_RST     	(0x00000000ul)
#define    USART_DFRRX_RST     	(0x00000000ul)
#define    USART_SBLR_RST      	(0x0000000Dul)
#define    USART_LCP1_RST      	(0x77685B4Cul)
#define    USART_LCP2_RST      	(0xAFA09284ul)
#define    USART_DMACR_RST     	(0x00000000ul)	

/******************************************************************************
******************** USART External Functions Declaration *********************
******************************************************************************/
extern void CSP_USARTInit(CSP_USART_T *usart,
                   U32_T mode_u32,
                   U16_T baudrate_u16,
                   U8_T timeOut_u8,
                   U8_T timeGuard_u8);
extern void CSP_USARTInitLin(CSP_USART_T *usart,
                      U16_T baudrate_u16,
                      U32_T linVersion_u32,
                      U8_T timeGuard_u8);
extern void CSP_USARTClose(CSP_USART_T *usart);
extern void CSP_USARTConfigInterrupt(CSP_USART_T *usart,
                                     U32_T intMask_u32,
                                     FunctionalStatus newState);
extern void CSP_USARTEnable(CSP_USART_T *usart, U32_T enable_mask_u32);
extern void CSP_USARTDisable(CSP_USART_T *usart, U32_T disable_mask_u32);
extern void CSP_USARTReceive(CSP_USART_T *usart,
                             U8_T channel_u8,
                             U32_T destAddress_u32,
                             U16_T length_u16);
extern void CSP_USARTTransmit(CSP_USART_T *usart,
                              U8_T channel_u8,
                              U32_T sourceAddress_u32,
                              U16_T length_u16);
extern void CSP_USARTTransmitLinHeaderFrame(CSP_USART_T *usart,
                                            U8_T sblr_u8,
                                            U32_T linMode_u32);
extern void CSP_USARTLinResponseFrameInit(CSP_USART_T *usart,
                                          U8_T *data_u8);
extern void CSP_USARTTransmitLinRpseFrame(CSP_USART_T *usart);
extern void CSP_USARTPortInit(CSP_USART_T* usart, U8_T sync_mode); 
extern void CSP_USARTDMACHSelc(CSP_USART_T* usart, U8_T *hwsrc_tx, U8_T *hwsrc_rx); 

#endif   /**< CSP_USART_H */

