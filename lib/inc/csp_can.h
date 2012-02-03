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
* @file name	csp_can.h
* @description	Definitions, Macros and function declarations for CAN
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when       who                       what
* |---+---+----------+-------------------------+----------------------
* |0.0 NEW 26/09/08    Ys OH                     Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_CAN_H
#define CSP_CAN_H

/******************************************************************************
************************** CAN Structure Definition ***************************
******************************************************************************/
/** Number of CAN interface                                                  */
#define NB_CAN_IF            2u

/** Number of CAN Message Object                                             */
#define NB_CAN_MO            32u

/** Interface definition                                                     */
#define IF0                  0u                   /**< Interface 0          */
#define IF1                  1u                   /**< Interface 1          */
#define TXIF                 0u                   /**< Transmit Interface   */
#define RXIF                 1u                   /**< Receive Interface    */

/******************************************************************************
@brief CAN Interface Structure
******************************************************************************/
typedef struct
{
   CSP_REGISTER_T     TMR;        /**< Command Register                     */
   CSP_REGISTER_T     DAR;        /**< Data Register A Interface X          */
   CSP_REGISTER_T     DBR;        /**< Data Register B Interface X          */
   CSP_REGISTER_T     MSKR;       /**< Mask Register Interface X            */
   CSP_REGISTER_T     IR;         /**< Identifier Register Interface X      */
   CSP_REGISTER_T     MCR;        /**< Message Control Register Interface X */
   CSP_REGISTER_T     STPR;       /**< Stamp Register Interface X           */
   CSP_REGISTER_T     ReservedA;
} CSP_CAN_IF_T;

/******************************************************************************
@brief CAN Structure 2 Interfaces
******************************************************************************/
typedef struct
{
   CSP_REGISTER_T     ReservedA[20];
   CSP_REGISTER_T     ECR;          /**< Enable Clock Register              */
   CSP_REGISTER_T     DCR;          /**< Disable Clock Register             */
   CSP_REGISTER_T     PMSR;         /**< Power Management Status Register   */
   CSP_REGISTER_T     ReservedB;
   CSP_REGISTER_T     CR;           /**< Control Register                   */
   CSP_REGISTER_T     MR;           /**< Mode Register                      */
   CSP_REGISTER_T     ReservedC;
   CSP_REGISTER_T     CSR;          /**< Clear Status Register              */
   CSP_REGISTER_T     SR;           /**< Status Register                    */
   CSP_REGISTER_T     IER;          /**< Interrupt Enable Register          */
   CSP_REGISTER_T     IDR;          /**< Interrupt Disable Register         */
   CSP_REGISTER_T     IMR;          /**< Interrupt Mask Register            */
   CSP_REGISTER_T     ReservedD;
   CSP_REGISTER_T     ISSR;         /**< Interrupt Source Status Register   */
   CSP_REGISTER_T     SIER;         /**< Source Interrupt Enable Register   */
   CSP_REGISTER_T     SIDR;         /**< Source Interrupt Disable Register  */
   CSP_REGISTER_T     SIMR;         /**< Source Interrupt Mask Register     */
   CSP_REGISTER_T     HPIR;         /**< Highest Priority Interrupt Register*/
   CSP_REGISTER_T     ERCR;         /**< Error Counter Register             */
   CSP_REGISTER_T     ReservedE[25];
   CSP_CAN_IF_T       IF[NB_CAN_IF];/**< CAN interface                      */
   CSP_REGISTER_T     TRR;          /**< Transmission Request Register      */
   CSP_REGISTER_T     NDR;          /**< New Data Register                  */
   CSP_REGISTER_T     MVR;          /**< Message Valid Register             */
   CSP_REGISTER_T     TSTR;         /**< Test Register                      */
} CSP_CAN_T, *CSP_CAN_PTR;

/******************************************************************************
************************** CAN Registers Definition ***************************
******************************************************************************/

/******************************************************************************
* ECR, DCR, PMSR : CAN Power Management Registers
******************************************************************************/
#define CAN_CAN      (0x01ul << 1)            /**< CAN Clock                */
#define CAN_DBGEN    (0x01ul << 31)           /**< Debug Mode Enable        */

/******************************************************************************
* CR : CAN Control Register
******************************************************************************/
#define CAN_SWRST    (0x01ul << 0)         /**< CAN Software Reset          */
#define CAN_CANEN    (0x01ul << 1)         /**< CAN Enable                  */
#define CAN_CANDIS   (0x01ul << 2)         /**< CAN Disable                 */
#define CAN_CCEN     (0x01ul << 3)         /**< Configuration change enable */
#define CAN_CCDIS    (0x01ul << 4)         /**< Configuration change disable*/
#define CAN_RQBTX    (0x01ul << 8)         /**< Request basic transmission  */
#define CAN_ABBTX    (0x01ul << 9)         /**< Abort basic transmission    */
#define CAN_STSR     (0x01ul << 10)        /**< Store shift register        */

/******************************************************************************
* MR : CAN Mode Register
******************************************************************************/
/** BD : Baud rate Prescalar                                                 */
#define CAN_BD_MASK  (0x3FFul << 0)             /**< Mask                   */
#define CAN_BD(val)  (((val) & 0x3FFul) << 0)   /**< Writing Macro          */

/** SJW : Synchronization Jump width                                         */
#define CAN_SJW_MASK (0x03ul << 12)             /**< Mask                   */
#define CAN_SJW(val) (((val) & 0x03ul) << 12)   /**< Writing Macro          */
#define CAN_AR       (0x01ul << 14)             /**< Automatic Retransmission*/

/** PHSEG1 : Phase Segment 1 Value                                           */
#define CAN_PHSEG1_MASK  (0x0Ful << 16)         /**< Mask                   */
#define CAN_PHSEG1(val)  (((val) & 0x0Ful) << 16) /**< Writing Macro        */

/** PHSEG2 : Phase Segment 2 Value                                           */
#define CAN_PHSEG2_MASK  (0x07ul << 20)         /**< Mask                   */
#define CAN_PHSEG2(val)  (((val) & 0x07ul) << 20) /**< Writing Macro        */

/******************************************************************************
* CSR, SR, IER, IDR, IMR : CAN Status and Interrupt Registers
******************************************************************************/
#define CAN_ERWARNTR     (0x01ul << 1)  /**< Error passive warning
                                              transition                     */
#define CAN_ERPASSTR     (0x01ul << 2)  /**< Error passive transition       */
#define CAN_BUSOFFTR     (0x01ul << 3)  /**< Bus off transition             */
#define CAN_ACTVT        (0x01ul << 4)  /**< Activity                       */
#define CAN_RXOK         (0x01ul << 8)  /**< Successfully received message  */
#define CAN_TXOK         (0x01ul << 9)  /**< Successfully transmit message  */
#define CAN_STUFF        (0x01ul << 10) /**< Stuff error                    */
#define CAN_FORM         (0x01ul << 11) /**< Form error                     */
#define CAN_ACK          (0x01ul << 12) /**< Acknowledge error              */
#define CAN_BIT1         (0x01ul << 13) /**< Bit to one error               */
#define CAN_BIT0         (0x01ul << 14) /**< Bit to zero error              */
#define CAN_CRC          (0x01ul << 15) /**< CRC error                      */

/** SR Register Only                                                         */
#define CAN_ISS          (0x01ul << 0)  /**< Interrrupt Source status       */
#define CAN_CANENS       (0x01ul << 16) /**< CAN enable status              */
#define CAN_ERWARN       (0x01ul << 17) /**< Error passive warning          */
#define CAN_ERPASS       (0x01ul << 18) /**< Error passive                  */
#define CAN_BUSOFF       (0x01ul << 19) /**< Bus off                        */
#define CAN_BUSY0        (0x01ul << 20) /**< Busy flag of interface 0       */
#define CAN_BUSY1        (0x01ul << 21) /**< Busy flag of interface 1       */
#define CAN_RS           (0x01ul << 22) /**< Received status                */
#define CAN_TS           (0x01ul << 23) /**< Transmit status                */
#define CAN_CCENS        (0x01ul << 24) /**< Configuration change enable    */
#define CAN_BTXPD        (0x01ul << 25) /**< Basic transmission pending     */

/******************************************************************************
* ISSR, SIER, SIDR, SIMR : CAN Interrupt Source Registers - TRR, NDR, MVR
******************************************************************************/
#define CAN_CH1          (0x01ul << 0)        /**< Interrupt channel 1      */
#define CAN_CH2          (0x01ul << 1)        /**< Interrupt channel 2      */
#define CAN_CH3          (0x01ul << 2)        /**< Interrupt channel 3      */
#define CAN_CH4          (0x01ul << 3)        /**< Interrupt channel 4      */
#define CAN_CH5          (0x01ul << 4)        /**< Interrupt channel 5      */
#define CAN_CH6          (0x01ul << 5)        /**< Interrupt channel 6      */
#define CAN_CH7          (0x01ul << 6)        /**< Interrupt channel 7      */
#define CAN_CH8          (0x01ul << 7)        /**< Interrupt channel 8      */
#define CAN_CH9          (0x01ul << 8)        /**< Interrupt channel 9      */
#define CAN_CH10         (0x01ul << 9)        /**< Interrupt channel 10     */
#define CAN_CH11         (0x01ul << 10)       /**< Interrupt channel 11     */
#define CAN_CH12         (0x01ul << 11)       /**< Interrupt channel 12     */
#define CAN_CH13         (0x01ul << 12)       /**< Interrupt channel 13     */
#define CAN_CH14         (0x01ul << 13)       /**< Interrupt channel 14     */
#define CAN_CH15         (0x01ul << 14)       /**< Interrupt channel 15     */
#define CAN_CH16         (0x01ul << 15)       /**< Interrupt channel 16     */
#define CAN_CH17         (0x01ul << 16)       /**< Interrupt channel 17     */
#define CAN_CH18         (0x01ul << 17)       /**< Interrupt channel 18     */
#define CAN_CH19         (0x01ul << 18)       /**< Interrupt channel 19     */
#define CAN_CH20         (0x01ul << 19)       /**< Interrupt channel 20     */
#define CAN_CH21         (0x01ul << 20)       /**< Interrupt channel 21     */
#define CAN_CH22         (0x01ul << 21)       /**< Interrupt channel 22     */
#define CAN_CH23         (0x01ul << 22)       /**< Interrupt channel 23     */
#define CAN_CH24         (0x01ul << 23)       /**< Interrupt channel 24     */
#define CAN_CH25         (0x01ul << 24)       /**< Interrupt channel 25     */
#define CAN_CH26         (0x01ul << 25)       /**< Interrupt channel 26     */
#define CAN_CH27         (0x01ul << 26)       /**< Interrupt channel 27     */
#define CAN_CH28         (0x01ul << 27)       /**< Interrupt channel 28     */
#define CAN_CH29         (0x01ul << 28)       /**< Interrupt channel 29     */
#define CAN_CH30         (0x01ul << 29)       /**< Interrupt channel 30     */
#define CAN_CH31         (0x01ul << 30)       /**< Interrupt channel 31     */
#define CAN_CH32         (0x01ul << 31)       /**< Interrupt channel 32     */

/******************************************************************************
* HPIR : CAN Highest Priority Interrup Register
******************************************************************************/
/** INTID : Interupt identifier                                              */
#define CAN_INTID_MASK   (0xFFFFul << 0)      /**< Mask                     */

/******************************************************************************
* ERCR : CAN Error Counter Register
******************************************************************************/
/** REC : Reception error counter                                            */
#define CAN_REC_MASK     (0x7Ful << 0)        /**< Mask                     */
#define CAN_REP          (0x01ul << 7)        /**< Receive Error Passive    */

/** TEC : Transmit error counter                                             */
#define CAN_TEC_MASK     (0xFFul << 8)        /**< Mask                     */

/******************************************************************************
* TMR : CAN Interface X Transfer Management Register
******************************************************************************/
/** NUMBER : Message number                                                  */
#define CAN_NUMBER_MASK  (0x3Ful << 0)  /**< Mask                           */
#define CAN_NUMBER(val)  (((val) & 0x3Ful) << 0) /**< Writing Macro         */

#define CAN_WR           (0x01ul << 7)  /**< Write or Read direction        */
#define CAN_ADAR         (0x01ul << 8)  /**< Access lower data bits         */
#define CAN_ADBR         (0x01ul << 9)  /**< Access upper data bits         */
#define CAN_AMSKR        (0x01ul << 10) /**< Access mask bits               */
#define CAN_AIR          (0x01ul << 11) /**< Access Identifier bits         */
#define CAN_AMCR         (0x01ul << 12) /**< Access Message control bits    */
#define CAN_ASTPR        (0x01ul << 13) /**< Access stamp bits              */
#define CAN_TRND         (0x01ul << 14) /**< Access transmission request bit*/
#define CAN_CLRIT        (0x01ul << 15) /**< Clear interrupt pending bit    */

/******************************************************************************
* DRA : CAN interface X Data A Register
******************************************************************************/
/** DATA0                                                                    */
#define CAN_DATA0_MASK   (0xFFul << 0)            /**< Mask                 */
#define CAN_DATA0(val)   (((val) & 0xFFul) << 0)  /**< Writing Macro        */

/** DATA1                                                                    */
#define CAN_DATA1_MASK   (0xFFul << 8)            /**< Mask                 */
#define CAN_DATA1(val)   (((val) & 0xFFul) << 8)  /**< Writing Macro        */

/** DATA2                                                                    */
#define CAN_DATA2_MASK   (0xFFul << 16)           /**< Mask                 */
#define CAN_DATA2(val)   (((val) & 0xFFul) << 16) /**< Writing Macro        */

/** DATA3                                                                    */
#define CAN_DATA3_MASK   (0xFFul << 24)           /**< Mask                 */
#define CAN_DATA3(val)   (((val) & 0xFFul) << 24) /**< Writing Macro        */

/******************************************************************************
* DRB : CAN interface X Data B Register
******************************************************************************/
/** DATA4                                                                    */
#define CAN_DATA4_MASK  (0xFFul << 0)             /**< Mask                 */
#define CAN_DATA4(val)  (((val) & 0xFFul) << 0)   /**< Writing Macro        */

/** DATA5                                                                    */
#define CAN_DATA5_MASK  (0xFFul << 8)             /**< Mask                 */
#define CAN_DATA5(val)  (((val) & 0xFFul) << 8)   /**< Writing Macro        */

/** DATA6                                                                    */
#define CAN_DATA6_MASK  (0xFFul << 16)            /**< Mask                 */
#define CAN_DATA6(val)  (((val) & 0xFFul) << 16)  /**< Writing Macro        */

/** DATA7                                                                    */
#define CAN_DATA7_MASK  (0xFFul << 24)            /**< Mask                 */
#define CAN_DATA7(val)  (((val) & 0xFFul) << 24)  /**< Writing Macro        */

/******************************************************************************
* MSK : CAN interface X Mask Register
******************************************************************************/
/** EXTMASK : Extented identifier mask                                       */
#define CAN_EXTMASK_MASK  (0x3FFFFul << 0)        /**< Mask                 */
#define CAN_EXTMASK(val)  (((val) & 0x3FFFFul) << 0) /**< Writing Macro     */

/** BASEMASK : Base identifier mask                                          */
#define CAN_BASEMASK_MASK (0x7FFul << 18)         /**< Mask                 */
#define CAN_BASEMASK(val) (((val) & 0x7FFul) << 18)  /**< Writing Macro     */

#define CAN_MMDIR         (0x01ul << 30)         /**< Message direction mask*/
#define CAN_MXTD          (0x01ul << 31)         /**< XTD bit mask          */

/******************************************************************************
* IR : CAN interface  Identifier Register
******************************************************************************/
/** EXTID : Extended identifier                                              */
#define CAN_EXTID_MASK    (0x3FFFFul << 0)        /**< Mask                 */
#define CAN_EXTID(val)    (((val) & 0x3FFFFul) << 0) /**< Writing Macro     */

/** BASEID : Base identifier                                                 */
#define CAN_BASEID_MASK   (0x7FFul << 18)         /**< Mask                 */
#define CAN_BASEID(val)   (((val) & 0x7FFul) << 18) /**< Writing Macro      */

#define CAN_MDIR          (0x01ul << 29)          /**< Message direction    */
#define CAN_XTD           (0x01ul << 30)          /**< Extended identifier  */
#define CAN_MSGVAL        (0x01ul << 31)          /**< Message Valid        */

/******************************************************************************
* MCR : CAN Interface X Message Control Register
******************************************************************************/
/** DLC : Data Length Code                                                   */
#define CAN_DLC_MASK     (0x0Ful << 0)        /**< Mask                     */
#define CAN_DLC(val)     (((val) & 0x0Ful) << 0) /**< Writing Macro         */

#define CAN_OVERWRITE    (0x01ul << 7)        /**< Overwrite mode           */
#define CAN_TXRQST       (0x01ul << 8)        /**< Transmit request         */
#define CAN_RMTEN        (0x01ul << 9)        /**< Remote enable            */
#define CAN_RXIE         (0x01ul << 10)       /**< Receive interrupt enable */
#define CAN_TXIE         (0x01ul << 11)       /**< Transmit interrupt enable*/
#define CAN_UMASK        (0x01ul << 12)       /**< Use acceptance mask      */
#define CAN_ITPND        (0x01ul << 13)       /**< Interrupt pending        */
#define CAN_MSGLST       (0x01ul << 14)       /**< Message lost             */
#define CAN_NEWDAT       (0x01ul << 15)       /**< New data                 */

/******************************************************************************
* STPR : CAN Interface X Stamp Register
******************************************************************************/
/** STAMP                                                                    */
#define CAN_STAMP_MASK   (0xFFFFFFFFul << 0)  /**< Mask                     */

/******************************************************************************
* TSTR : CAN Test Register
******************************************************************************/
/** Test access key                                                          */
#define CAN_TSTKEY_MASK  (0xFFFFul << 16)  /**< TSTKEY Mask                 */
#define CAN_TSTKEY       (0x0C75ul << 16)  /**< Write access in TSTR allowed*/

#define CAN_BASIC        (0x01ul << 0)     /**< Basic mode                  */
#define CAN_SILENT       (0x01ul << 1)     /**< Silent mode                 */
#define CAN_LBACK        (0x01ul << 2)     /**< Loop Back mode              */

/* Control of CAN_TX pin                                                     */
#define CAN_TX_MASK      (0x03ul << 3)     /**< Mask                        */
#define CAN_TX(val)      (((val) & 0x03ul) << 3) /**< Writing Macro         */

#define CAN_TXOPD        (0x01ul << 5)     /**< TX open drain               */
#define CAN_RX           (0x01ul << 6)     /**< Monitor CAN_RX pin value    */

/******************************************************************************
***************************** CAN Registers mask ******************************
******************************************************************************/
#define CAN_ECR_MASK     (0x80000002ul)         /**< ECR mask               */
#define CAN_DCR_MASK     (0x80000002ul)         /**< DCR mask               */
#define CAN_PMSR_MASK    (0x80000002ul)         /**< PMSR mask              */
#define CAN_CR_MASK      (0x0000071Ful)         /**< CR mask                */
#define CAN_MR_MASK      (0x007F73FFul)         /**< MR mask                */
#define CAN_CSR_MASK     (0x0000FF1Eul)         /**< CSR mask               */
#define CAN_SR_MASK      (0x03FFFF1Ful)         /**< SR mask                */
#define CAN_IER_MASK     (0x0000FF1Eul)         /**< IER mask               */
#define CAN_IDR_MASK     (0x0000FF1Eul)         /**< IDR mask               */
#define CAN_IMR_MASK     (0x0000FF1Eul)         /**< IMR mask               */
#define CAN_ISSR_MASK    (0xFFFFFFFFul)         /**< ISSR mask              */
#define CAN_SIER_MASK    (0xFFFFFFFFul)         /**< SIER mask              */
#define CAN_SIDR_MASK    (0xFFFFFFFFul)         /**< SIDR mask              */
#define CAN_SIMR_MASK    (0xFFFFFFFFul)         /**< SIMR mask              */
#define CAN_HPIR_MASK    (0x0000FFFFul)         /**< HPIR mask              */
#define CAN_ERCR_MASK    (0x0000FFFFul)         /**< ERCR mask              */
#define CAN_TMRX_MASK    (0x0000FFBFul)         /**< TMRX mask              */
#define CAN_DARX_MASK    (0xFFFFFFFFul)         /**< DARX mask              */
#define CAN_DBRX_MASK    (0xFFFFFFFFul)         /**< DBRX mask              */
#define CAN_MSKRX_MASK   (0xDFFFFFFFul)         /**< MSKRX mask             */
#define CAN_IRX_MASK     (0xFFFFFFFFul)         /**< IRX mask               */
#define CAN_MCRX_MASK    (0x0000FF8Ful)         /**< MCRX mask              */
#define CAN_STPRX_MASK   (0xFFFFFFFFul)         /**< STPRX mask             */
#define CAN_TRR_MASK     (0xFFFFFFFFul)         /**< TRR mask               */
#define CAN_NDR_MASK     (0xFFFFFFFFul)         /**< NDR mask               */
#define CAN_MVR_MASK     (0xFFFFFFFFul)         /**< MVR mask               */
#define CAN_TSTR_MASK    (0xFFFF007Ful)         /**< TSTR mask              */

/******************************************************************************
************************* CAN Registers reset value ***************************
******************************************************************************/
#define CAN_ECR_RST      (0x00000000ul)        /**< ECR reset value         */
#define CAN_DCR_RST      (0x00000000ul)        /**< DCR reset value         */
#define CAN_PMSR_RST     (0x00000000ul)        /**< PMSR reset value        */
#define CAN_CR_RST       (0x00000000ul)        /**< CR reset value          */
#define CAN_MR_RST       (0x00234001ul)        /**< MR reset value          */
#define CAN_CSR_RST      (0x00000000ul)        /**< CSR reset value         */
#define CAN_SR_RST       (0x00000000ul)        /**< SR reset value          */
#define CAN_IER_RST      (0x00000000ul)        /**< IER reset value         */
#define CAN_IDR_RST      (0x00000000ul)        /**< IDR reset value         */
#define CAN_IMR_RST      (0x00000000ul)        /**< IMR reset value         */
#define CAN_ISSR_RST     (0x00000000ul)        /**< ISSR reset value        */
#define CAN_SIER_RST     (0x00000000ul)        /**< SIER reset value        */
#define CAN_SIDR_RST     (0x00000000ul)        /**< SIDR reset value        */
#define CAN_SIMR_RST     (0x00000000ul)        /**< SIMR reset value        */
#define CAN_HPIR_RST     (0x00000000ul)        /**< HPIR reset value        */
#define CAN_ERCR_RST     (0x00000000ul)        /**< ERCR reset value        */
#define CAN_TMRX_RST     (0x00000001ul)        /**< IF_TMR reset value      */
#define CAN_DARX_RST     (0x00000000ul)        /**< IF_DAR reset value      */
#define CAN_DBRX_RST     (0x00000000ul)        /**< IF_DBR reset value      */
#define CAN_MSKRX_RST    (0xDFFFFFFFul)        /**< IF_MSKR reset value     */
#define CAN_IRX_RST      (0x00000000ul)        /**< IF_IR reset value       */
#define CAN_MCRX_RST     (0x00000000ul)        /**< IF_MCR reset value      */
#define CAN_STPRX_RST    (0x00000000ul)        /**< IF_STPR reset value     */
#define CAN_TRR_RST      (0x00000000ul)        /**< TRR reset value         */
#define CAN_NDR_RST      (0x00000000ul)        /**< NDR reset value         */
#define CAN_MVR_RST      (0x00000000ul)        /**< MVR reset value         */
#define CAN_TSTR_RST     (0x00000020ul)        /**< TSTR reset value        */

/******************************************************************************
*************************** CAN Macros Definition *****************************
******************************************************************************/
/* ECR, DCR, PMSR : CAN Power Management Registers                           */
/** Set ECR register (Enable)                                                */
#define CSP_CAN_SET_ECR(can, val)                ((can)->ECR = (val))
/** Set DCR register (Disable)                                               */
#define CSP_CAN_SET_DCR(can, val)                ((can)->DCR = (val))
/** Get PMSR register (Status)                                               */
#define CSP_CAN_GET_PMSR(can)                    ((can)->PMSR)

/** CR : CAN Control Register                                                */
#define CSP_CAN_SET_CR(can, val)                 ((can)->CR = (val))

/* MR : CAN Mode Register                                                    */
/** Get MR register (Mode Register)                                          */
#define CSP_CAN_GET_MR(can)                      ((can)->MR)
/** Set MR register (Mode Register)                                          */
#define CSP_CAN_SET_MR(can, mode)                ((can)->MR = (mode))

/* CSR, SR : CAN Status Register                                             */
/** Set CSR register (Clear Status Register)                                 */
#define CSP_CAN_SET_CSR(can, val)                ((can)->CSR = (val))
/** Get SR register (Status Register)                                        */
#define CSP_CAN_GET_SR(can)                      ((can)->SR)

/* IER, IDR, IMR : CAN Interrupt Registers                                   */
/** Set IER register (Enable Interrupt)                                      */
#define CSP_CAN_SET_IER(can, val)                ((can)->IER = (val))
/** Set IDR register (Disable Interrupt)                                     */
#define CSP_CAN_SET_IDR(can, val)                ((can)->IDR = (val))
/** Get IMR register (Status Interrupt)                                      */
#define CSP_CAN_GET_IMR(can)                     ((can)->IMR)

/* CISR, ISSR, SIER, SIDR, SIMR : CAN Interrupt Source Registers             */
/** Get ISSR register (Status)                                               */
#define CSP_CAN_GET_ISSR(can)                    ((can)->ISSR)
/** Set SIER register (Enable)                                               */
#define CSP_CAN_SET_SIER(can, val)               ((can)->SIER = (val))
/** Set SIDR register (Disable)                                              */
#define CSP_CAN_SET_SIDR(can, val)               ((can)->SIDR = (val))
/** Get SIMR register                                                        */
#define CSP_CAN_GET_SIMR(can)                    ((can)->SIMR)

/* HPIR : CAN Highest Priority Interrupt Register                            */
/** Get HIPR register                                                        */
#define CSP_CAN_GET_HPIR(can)                    ((can)->HPIR)

/* ERCR : CAN Error Counter Register                                         */
/** Get ERCR register                                                        */
#define CSP_CAN_GET_ERCR(can)                    ((can)->ERCR)

/* TMR : CAN Interface X Transfer Management Register                        */
/** Get TMR register                                                         */
#define CSP_CAN_IF_GET_TMR(can, interface)       ((can)->IF[(interface)].TMR)
/** Set TMR register                                                         */
#define CSP_CAN_IF_SET_TMR(can, interface, val)                              \
                          ((can)->IF[(interface)].TMR = (val))

/* DRA : CAN Interface X Data A Register                                     */
/** Get DAR register                                                         */
#define CSP_CAN_IF_GET_DAR(can, interface)       ((can)->IF[(interface)].DAR)
/** Set DAR register                                                         */
#define CSP_CAN_IF_SET_DAR(can, interface, val)                              \
                          ((can)->IF[(interface)].DAR = (val))

/* DBR : CAN Interface X  Data B Register                                    */
/** Get DBR register                                                         */
#define CSP_CAN_IF_GET_DBR(can, interface)       ((can)->IF[(interface)].DBR)
/** Set DBR register                                                         */
#define CSP_CAN_IF_SET_DBR(can, interface, val)                              \
                          ((can)->IF[(interface)].DBR = (val))

/* MSK : CAN Interface X RST Register                                        */
/** Get MSKR register                                                        */
#define CSP_CAN_IF_GET_MSKR(can, interface)      ((can)->IF[(interface)].MSKR)
/** Set MSKR register                                                        */
#define CSP_CAN_IF_SET_MSKR(can, interface, val)                             \
                           ((can)->IF[(interface)].MSKR = (val))

/* IR : CAN Interface X Identifier Register                                  */
/** Get IR register                                                          */
#define CSP_CAN_IF_GET_IR(can, interface)        ((can)->IF[(interface)].IR)
/** Set IR register                                                          */
#define CSP_CAN_IF_SET_IR(can, interface, val)                               \
                         ((can)->IF[(interface)].IR = (val))

/* MCR : CAN Interface X Control Register                                    */
/** Get MCR register                                                         */
#define CSP_CAN_IF_GET_MCR(can, interface)       ((can)->IF[(interface)].MCR)
/** Set MCR register                                                         */
#define CSP_CAN_IF_SET_MCR(can, interface, val)                              \
                          ((can)->IF[(interface)].MCR = (val))

/* STPR : CAN Interface X Stamp Register                                     */
/** Get STPR register                                                        */
#define CSP_CAN_IF_GET_STPR(can, interface)      ((can)->IF[(interface)].STPR)

/* TRR : CAN Transmission Request Register                                   */
/** Get TRR register                                                         */
#define CSP_CAN_GET_TRR(can)                     ((can)->TRR)

/* NDR : CAN New Data Register                                               */
/** Get NDR register                                                         */
#define CSP_CAN_GET_NDR(can)                     ((can)->NDR)

/* MVR : CAN Message Valid Register                                          */
/** Get MVR register                                                         */
#define CSP_CAN_GET_MVR(can)                     ((can)->MVR)

/* TSTR : CAN Test Register                                                  */
/** Get TSTR register                                                        */
#define CSP_CAN_GET_TSTR(can)                    ((can)->TSTR )
/** Set TSTR register                                                        */
#define CSP_CAN_SET_TSTR(can, val)          ((can)->TSTR = (val | CAN_TSTKEY))

/******************************************************************************
********************* CAN External Functions Declaration **********************
******************************************************************************/
extern void CSP_CANInit(CSP_CAN_T *can, U32_T mode_u32);
extern void CSP_CANClose(CSP_CAN_T *can);
extern void CSP_CANConfigInterrupt(CSP_CAN_T *can,
							        U32_T intMask_u32,
							        U32_T channelMask_u32,
							        FunctionalStatus newState);
extern void CSP_CANEnable(CSP_CAN_T *can);
extern void CSP_CANDisable(CSP_CAN_T *can);
extern void CSP_CANReceive(CSP_CAN_T *can,
                           U8_T  interface_u8,
                           U8_T  channel_u8,
                           U32_T id_u32,
                           U32_T mask_u32,
                           U16_T  control_u16);
extern void CSP_CANTransmit(CSP_CAN_T *can,
                            U8_T  interface_u8,
                            U8_T  channel_u8,
                            U32_T dataa_u32,
                            U32_T datab_u32,
                            U32_T id_u32,
                            U16_T control_u16);
extern U32_T CSP_CANComputeBT(CSP_CAN_T *can,
                       U32_T     coreClk_u32,
                       U32_T     baudRate_u32);

#endif   /* CSP_CAN_H */
