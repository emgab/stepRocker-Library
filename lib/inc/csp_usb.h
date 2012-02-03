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
* @file name	csp_usb.h
* @description Definitions, Macros and function declarations for USB
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_USB_H
#define CSP_USB_H

/******************************************************************************
************************* USB Structure Definition ****************************
******************************************************************************/																			 
/******************************************************************************
@brief description CSP_USB_T and CSP_USB_PTR
******************************************************************************/
 typedef struct
 {
    CSP_REGISTER_T   USBFA;		/**< USB Function Address Register  */
    CSP_REGISTER_T   USBPM;     /**< USB Power Management Register  */
    CSP_REGISTER_T   USBINTMON; /**< USB Interrupt Register          */
    CSP_REGISTER_T   USBINTCON; /**<USB Interrupt Enable Register   */
    CSP_REGISTER_T   USBFN;     /**<USB Frame Number Register       */
    CSP_REGISTER_T   USBEPLNUM; /**<USB Logical Endpoint Number	Control Reg. */
    CSP_REGISTER_T   ReservedA[2];
    CSP_REGISTER_T   USBEP0CSR;  /**< USB Endpoint 0 Common Status Register */
    CSP_REGISTER_T   USBEP1CSR;  /**< USB Endpoint 1 Common Status Register */
    CSP_REGISTER_T   USBEP2CSR;  /**< USB Endpoint 2 Common Status Register */
    CSP_REGISTER_T   USBEP3CSR;  /**< USB Endpoint 3 Common Status Register */
    CSP_REGISTER_T   USBEP4CSR;  /**< USB Endpoint 4 Common Status Register */
    CSP_REGISTER_T   ReservedB[3];
    CSP_REGISTER_T   USBEP0WC;   /**< USB Write Count Register for Endpoint 0 */
    CSP_REGISTER_T   USBEP1WC;   /**< USB Write Count Register for Endpoint 1 */
    CSP_REGISTER_T   USBEP2WC;	 /**< USB Write Count Register for Endpoint 2 */
    CSP_REGISTER_T   USBEP3WC;	 /**< USB Write Count Register for Endpoint 3 */
    CSP_REGISTER_T   USBEP4WC;	 /**< USB Write Count Register for Endpoint 4 */
    CSP_REGISTER_T   ReservedC[3];
    CSP_REGISTER_T   USBNAKCON1; /**< USB NAK Control 1 Register */
    CSP_REGISTER_T   USBNAKCON2; /**< USB NAK Control 2 Register */
    CSP_REGISTER_T   ReservedD[6];
    CSP_REGISTER_T   USBEP0;	 /**< USB Endpoint 0 FIFO */
    CSP_REGISTER_T   USBEP1;	 /**< USB Endpoint 1 FIFO */
    CSP_REGISTER_T   USBEP2;	 /**< USB Endpoint 2 FIFO */
    CSP_REGISTER_T   USBEP3;	 /**< USB Endpoint 3 FIFO */
    CSP_REGISTER_T   USBEP4;	 /**< USB Endpoint 4 FIFO */
    CSP_REGISTER_T   ReservedE[3];
    CSP_REGISTER_T   PROGREG;	 /**< USB Configuration */
    CSP_REGISTER_T   ReservedF[4];
    CSP_REGISTER_T   FSPULLUP;	 /**<  USB FS Pull Up Control*/
    CSP_REGISTER_T   CONFLAG;
 } CSP_USB_T, *CSP_USB_PTR;

/******************************************************************************
************************* USB Registers Definition ****************************
******************************************************************************/

/******************************************************************************
* FA : Function Address Register
******************************************************************************/
#define USB_USBFAF_MASK (0x7Ful << 0)    		/**<  IPIDCODE mask     	*/
#define USB_USBFAF(val) (((val) & 0x7Ful) << 0) /**< Writing Macro      	*/
#define USB_USBAUP   	(0x01ul << 7)    		/**<  Address Update     	*/

/** Set FA register 		                                             	*/
#define CSP_USB_SET_FA(usb, val)    ((usb)->USBFA = (val))
/** Get FA register                                                         */
#define CSP_USB_GET_FA(usb)        ((usb)->USBFA)

/******************************************************************************
* PM : Power Management Register
******************************************************************************/
#define USB_SUSE        (0x01ul << 0)        /**< Suspend Enable            */
#define USB_SUSM        (0x01ul << 1)        /**< Suspend Mode              */
#define USB_RU          (0x01ul << 2)        /**< Resume		     		*/
#define USB_RST         (0x01ul << 3)        /**< Reset			    		*/
#define USB_ISOU        (0x01ul << 7)        /**< ISO Update		     	*/

/** Set PM register 		                                                */
 #define CSP_USB_SET_PM(usb, val)    ((usb)->USBPM = (val))
/** Get PM register                                               			*/
 #define CSP_USB_GET_PM(usb)        ((usb)->USBPM)

/******************************************************************************
* INTMON : Interrupt Register
******************************************************************************/
#define USB_EP0I          (0x01ul << 0)         /**< EP0 Interrupt         */
#define USB_EP1I          (0x01ul << 1)         /**< EP1 Interrupt         */
#define USB_EP2I          (0x01ul << 2)         /**< EP2 Interrupt         */
#define USB_EP3I          (0x01ul << 3)         /**< EP3 Interrupt         */
#define USB_EP4I          (0x01ul << 4)         /**< EP4 Interrupt         */
#define USB_SUSI          (0x01ul << 8)         /**< Suspend Interrupt     */
#define USB_RESI          (0x01ul << 9)         /**< Resume Interrupt      */
#define USB_RSTI          (0x01ul << 10)        /**< Reset Interrupt       */

#define USB_INT_ALLCLEAR  (0xFFul << 0)			/**< Clear All Interrupt	*/

/** Set INTMON register 		                                            */
#define CSP_USB_SET_INTMON(usb, val)    ((usb)->USBINTMON = (val))
/** Get INTMON register                                               	    */
#define CSP_USB_GET_INTMON(usb)        ((usb)->USBINTMON)


/******************************************************************************
* INTCON : USB Interrupt Enable Register
******************************************************************************/
#define USB_EP0IEN         (0x01ul << 0)	/**< EP0 Interrupt Enable   	*/
#define USB_EP1IEN         (0x01ul << 1)    /**< EP1 Interrupt Enable   	*/
#define USB_EP2IEN         (0x01ul << 2)    /**< EP2 Interrupt Enable   	*/
#define USB_EP3IEN         (0x01ul << 3)    /**< EP3 Interrupt Enable   	*/
#define USB_EP4IEN         (0x01ul << 4)    /**< EP4 Interrupt Enable    	*/
#define USB_SUSIEN         (0x01ul << 8)    /**< Suspend Interrupt Enable	*/
#define USB_RSTIEN         (0x01ul << 10)   /**< Reset Interrupt Enable 	*/

/** Set INTCON register                                                     */
#define CSP_USB_SET_INTCON(usb, val)     ((usb)->USBINTCON = (val))
/** Get INTCON register                                               	    */
#define CSP_USB_GET_INTCON(usb)        ((usb)->USBINTCON)

/******************************************************************************
* FN : USB Frame Number Register
******************************************************************************/
#define USB_FN_MASK      (0x7FFul << 0)     /**< USB Frame Number           */
#define USB_FN(val)    (((val) & 0x7FFul) << 0) /**< Writing Macro      	*/

/** Set FN register                                                         */
#define CSP_USB_SET_FN(usb, val)     ((usb)->USBFN = (val))
/** Get FN register                                               	     	*/
#define CSP_USB_GET_FN(usb)        ((usb)->USBFN)

/******************************************************************************
* EPLNUM : Logical Endpoint Number Control Register
******************************************************************************/
#define USB_LNUMEP1_MASK    (0x0Ful << 0)           /**< mask               */
#define USB_LNUMEP2_MASK    (0x0Ful << 4)           /**< mask               */
#define USB_LNUMEP3_MASK    (0x0Ful << 8)           /**< mask               */
#define USB_LNUMEP4_MASK    (0x0Ful << 12)          /**< mask               */

#define USB_LNUMEP1(val)    (((val) & 0x0Ful) << 0) /**< Writing Macro      */
#define USB_LNUMEP2(val)    (((val) & 0x0Ful) << 4) /**< Writing Macro      */
#define USB_LNUMEP3(val)    (((val) & 0x0Ful) << 8) /**< Writing Macro      */
#define USB_LNUMEP4(val)    (((val) & 0x0Ful) << 12) /**< Writing Macro     */

/** Get EPLNUM register                                           			*/
#define CSP_USB_GET_EPLNUM(usb)           ((usb)->USBEPLNUM)
/** Set EPLNUM register                                           			*/
#define CSP_USB_SET_EPLNUM(usb, val)     ((usb)->USBEPLNUM = (val))

/******************************************************************************
* EP0CSR : USB Endpoint 0 Common Status Register
******************************************************************************/
#define USB_EP0MAXP_MASK 	((0x03ul)<<0)
#define USB_EP0MAXP(val) 	((val&0x03ul)<<0)
#define USB_EP0MAXP_8BYTE	((0x00ul)<<0)		/**< MAXP size is 8 byte   	*/
#define USB_EP0MAXP_8BYTES	((0x01ul)<<0)		/**< MAXP size is 8 bytes  	*/
#define USB_EP0MAXP_16BYTES ((0x02ul)<<0)		/**< MAXP size is 16 bytes 	*/

#define USB_EP0MAXPSET   	(0x01ul << 7)        /**< MAXP size set table  	*/
#define USB_EP0MAXPSET_SIZE(val)   	((0x01ul << 7)|val)	/**< MAXP size set 	*/

#define USB_EP0ORDY    	(0x01ul << 24)           /**< OUT packet ready   	*/
#define USB_EP0INRDY    (0x01ul << 25)           /**< IN packet ready    	*/
#define USB_STSTALL    	(0x01ul << 26)           /**< Sent stall         	*/
#define USB_DEND    	(0x01ul << 27)           /**< Data end           	*/
#define USB_SETEND    	(0x01ul << 28)           /**< Setup end          	*/
#define USB_SDSTALL    	(0x01ul << 29)           /**< Send stall         	*/
#define USB_SVORDY    	(0x01ul << 30)           /**< Serviced out ready	*/
#define USB_SVSET    	(0x01ul << 31)           /**< Seviced setup end  	*/

/** Set EP0CSR register 			                                      	*/
#define CSP_USB_SET_EP0CSR(usb, val)     ((usb)->USBEP0CSR = (val))
/** Get EP0CSR register (Status Register)                                 	*/
#define CSP_USB_GET_EP0CSR(usb)           ((usb)->USBEP0CSR)

/******************************************************************************
* EPxCSR : USB Endpoint x Common Status Register
******************************************************************************/
#define USB_MAXP_MASK		(0x0Ful << 0)           /**< MAXP mask          */
#define USB_MAXP(val)   	(((val) & 0x0Ful) << 0) /**< Writing Macro      */
#define USB_MAXP_8BYTE		(0x00ul << 0)		/**< MAXP size is 8 byte 	*/
#define USB_MAXP_8BYTES		(0x01ul << 0)		/**< MAXP size is 8 bytes 	*/
#define USB_MAXP_16BYTES	(0x02ul << 0)		/**< MAXP size is 16 bytes	*/
#define USB_MAXP_24BYTES	(0x03ul << 0)		/**< MAXP size is 24 bytes 	*/
#define USB_MAXP_32BYTES	(0x04ul << 0)		/**< MAXP size is 32 bytes 	*/
#define USB_MAXP_40BYTES	(0x05ul << 0)		/**< MAXP size is 40 bytes 	*/
#define USB_MAXP_48BYTES	(0x06ul << 0)		/**< MAXP size is 48 bytes 	*/
#define USB_MAXP_56BYTES	(0x07ul << 0)		/**< MAXP size is 56 bytes 	*/
#define USB_MAXP_64BYTES	(0x08ul << 0)		/**< MAXP size is 64 bytes 	*/
#define USB_MAXP_72BYTES	(0x09ul << 0)		/**< MAXP size is 72 bytes 	*/
#define USB_MAXP_80BYTES	(0x0Aul << 0)		/**< MAXP size is 80 bytes 	*/
#define USB_MAXP_88BYTES	(0x0Bul << 0)		/**< MAXP size is 88 bytes 	*/
#define USB_MAXP_96BYTES	(0x0Cul << 0)		/**< MAXP size is 96 bytes 	*/
#define USB_MAXP_104BYTES	(0x0Dul << 0)		/**< MAXP size is 104 bytes */
#define USB_MAXP_112BYTES	(0x0Eul << 0)		/**< MAXP size is 112 bytes */
#define USB_MAXP_120BYTES	(0x0Ful << 0)		/**< MAXP size is 120 bytes */


#define USB_MAXPSET   		(0x01ul << 7)      /**< MAXP size set table */
#define USB_MAXPSET_SIZE(val)	((0x01ul << 7)|val)

#define USB_OISO		((0x01ul)<<8)		/**< OUT mode set          		*/
#define USB_OISO_BULK	((0x00ul)<<8)		/**< OUT Bulk mode         		*/
#define USB_OISO_ISO	((0x01ul)<<8)		/**< OUT ISO mode          		*/

#define USB_OATCLR   	(0x01ul << 9)       /**< Out Mode, Auto Clear		*/

#define USB_DMA_IN_PKT  (0x01ul << 11)      
#define USB_DMA_MODE   	(0x01ul << 12)      /**< Enable DMA mode			*/

#define USB_MODE		((0x01ul)<<13)	 	/**< IN/OUT mode selection  	*/
#define USB_MODE_IN		((0x01ul)<<13)
#define USB_MODE_OUT	((0x00ul)<<13)

#define USB_IISO		((0x01ul)<<14)      /**< IN mode, ISO mode       	*/
#define USB_IISO_BULK	((0x00ul)<<14)
#define USB_IISO_ISO	((0x01ul)<<14)

#define USB_IATSETT   	(0x01ul << 15)      /**< IN mode, Auto set          */
#define USB_OORDY   	(0x01ul << 16)		/**< OUT mode, out packet ready */
#define USB_OFFULL   	(0x01ul << 17)      /**< OUT mode, FIFO full        */
#define USB_OOVER   	(0x01ul << 18)      /**< OUT mode, FIFO over run    */
#define USB_ODERR   	(0x01ul << 19)      /**< OUT mode, data error       */
#define USB_OFFLUSH   	(0x01ul << 20)      /**< OUT mode, FIFO flush       */
#define USB_OSDSTALL   	(0x01ul << 21)      /**< Out mode, Send stall       */
#define USB_OSTSTALL   	(0x01ul << 22)      /**< Out mode, Sent stall       */
#define USB_OCLTOG  	(0x01ul << 23)      /**< Out mode, Clear data toggle*/
#define USB_INRDY   	(0x01ul << 24)      /**< In mode, IN packet ready   */
#define USB_INEMP    	(0x01ul << 25)      /**< In mode, FIFO not empty    */
#define USB_IUNDER   	(0x01ul << 26)      /**< In mode, Under run         */
#define USB_IFFLUSH    	(0x01ul << 27)      /**< In mode, FIFO flush        */
#define USB_ISDSTALL    (0x01ul << 28)      /**< In mode, Send stall        */
#define USB_ISTSTALL    (0x01ul << 29)      /**< In mode, Sent stall        */
#define USB_ICLTOG    	(0x01ul << 30)      /**< In mode, Clear data toggle */

/** Set EP1CSR register                                                     */
#define CSP_USB_SET_EP1CSR(usb, val)    ((usb)->USBEP1CSR = (val))
/** Get EP1CSR register                                                     */
#define CSP_USB_GET_EP1CSR(usb)          ((usb)->USBEP1CSR)


/** Set EP2CSR register                                                      */
#define CSP_USB_SET_EP2CSR(usb, val)    ((usb)->USBEP2CSR = (val))
/** Get EP2CSR register                                                      */
#define CSP_USB_GET_EP2CSR(usb)          ((usb)->USBEP2CSR)


/** Set EP3CSR register                                                      */
#define CSP_USB_SET_EP3CSR(usb, val)    ((usb)->USBEP3CSR = (val))
/** Get EP3CSR register                                                      */
#define CSP_USB_GET_EP3CSR(usb)          ((usb)->USBEP3CSR)

/** Set EP4CSR register                                                      */
#define CSP_USB_SET_EP4CSR(usb, val)    ((usb)->USBEP4CSR = (val))
/** Get EP4CSR register                                                      */
#define CSP_USB_GET_EP4CSR(usb)          ((usb)->USBEP4CSR)

/******************************************************************************
* WC0 : USB Write Count Register for Endpoint 0
******************************************************************************/
#define USB_WRTCNT_MASK     (0x1Ful << 0)    /**< USB Converted Data Mask 	*/
#define USB_WRTCNT(val)   	(((val) & 0x1Ful) << 0) /**< Writing Macro      */

/** Set WC0 register                                                        */
#define CSP_USB_SET_WC0(usb,val)	((usb)->USBEP0WC = val)

/** Get WC0 register                                                        */
#define CSP_USB_GET_WC0(usb)        	((usb)->USBEP0WC)


/******************************************************************************
* WCx : USB Write Count Register for Endpoint x
******************************************************************************/
#define USB_WRTCNT0_MASK    (0xFFul << 0)    /**< USB Converted Data Mask 	*/
#define USB_WRTCNT0(val)    (((val) & 0xFFul) << 0) /**< Writing Macro      */

#define USB_WRTCNT1_MASK	(0xFFul << 0)    /**< USB Converted Data Mask 	*/
#define USB_WRTCNT1(val)    (((val) & 0xFFul) << 0) /**< Writing Macro      */

/** Set WC1 register                                                        */
#define CSP_USB_SET_WC1(usb,val) 	((usb)->USBEP1WC = val)
/** Get WC1 register                                                        */
#define CSP_USB_GET_WC1(usb)		((usb)->USBEP1WC)
#define CSP_USB_GET_WC1_L(usb)      (((usb)->USBEP1WC&0xFF)>>0)
#define CSP_USB_GET_WC1_H(usb)      (((usb)->USBEP1WC&0xFF00)>>8)

/** Set WC2 register                                                        */
#define CSP_USB_SET_WC2(usb,val)    ((usb)->USBEP2WC = val)
/** Get WC2 register                                                        */
#define CSP_USB_GET_WC2(usb)        ((usb)->USBEP2WC)
#define CSP_USB_GET_WC2_L(usb)      (((usb)->USBEP2WC&0xFF)>>0)
#define CSP_USB_GET_WC2_H(usb)      (((usb)->USBEP2WC&0xFF00)>>8)

/** Set WC3 register                                                        */
#define CSP_USB_SET_WC3(usb,val)    ((usb)->USBEP3WC = val)
/** Get WC1 register                                                        */
#define CSP_USB_GET_WC3(usb)        ((usb)->USBEP3WC)
#define CSP_USB_GET_WC3_L(usb)      (((usb)->USBEP3WC&0xFF)>>0)
#define CSP_USB_GET_WC3_H(usb)      (((usb)->USBEP3WC&0xFF00)>>8)

/** Set WC4 register                                                        */
#define CSP_USB_SET_WC4(usb,val)    ((usb)->USBEP4WC = val)
/** Get WC4 register                                                        */
#define CSP_USB_GET_WC4(usb)        ((usb)->USBEP4WC)
#define CSP_USB_GET_WC4_L(usb)      (((usb)->USBEP4WC&0xFF)>>0)
#define CSP_USB_GET_WC4_H(usb)      (((usb)->USBEP4WC&0xFF00)>>8)

/******************************************************************************
* NAKCON1 : USB NAK Control 1 Register
******************************************************************************/
#define USB_NAKEP6_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP6(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP5_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP5(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP4_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP4(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP3_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP3(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP2_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP2(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP1_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP1(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEN	    	(0x01ul << 31)    /**< USB Converted Data Mask*/

/** Set NAKCON1 register                       				 */
#define CSP_USB_SET_NAKCON1(usb, val)     ((usb)->USBNAKCON1 = (val))
/** Get NAKCON1 register 			                   	*/
#define CSP_USB_GET_NAKCON1(usb)           ((usb)->USBNAKCON1)

/******************************************************************************
* NAKCON2 : USB NAK Control 2 Register
******************************************************************************/
#define USB_NAKEP12_MASK	(0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP12(val)    (((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP11_MASK    (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP11(val)    (((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP10_MASK    (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP10(val)    (((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP9_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP9(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP8_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP8(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEP7_MASK     (0x0Ful << 0)    /**< USB Converted Data Mask */
#define USB_NAKEP7(val)    	(((val) & 0x0Ful) << 0) /**< Writing Macro    */
#define USB_NAKEN	    	(0x01ul << 31)    /**< USB Converted Data Mask*/

/** Set NAKCON2 register                       				 */
#define CSP_USB_SET_NAKCON2(usb, val)     ((usb)->USBNAKCON2 = (val))  
/** Get NAKCON2 register 			                   	*/
#define CSP_USB_GET_NAKCON2(usb)           ((usb)->USBNAKCON2)

/******************************************************************************
* EPx : USB endpoint 0 FIFO
******************************************************************************/
#define USB_EPFIFO_MASK     (0xFFul << 0)    /**< USB Converted Data Mask */
#define USB_EPFIFO(val)    	(((val) & 0xFFul) << 0) /**< Writing Macro      */

/** Set EP0 register                       				 */
#define CSP_USB_SET_EP0(usb, val)     ((usb)->USBEP0 = (val))
/** Get EP0 register 			                   	*/
#define CSP_USB_GET_EP0(usb)           ((usb)->USBEP0)

/** Set EP1 register                       				 */
#define CSP_USB_SET_EP1(usb, val)     ((usb)->USBEP1 = (val))
/** Get EP1 register 			                   	*/
#define CSP_USB_GET_EP1(usb)           ((usb)->USBEP1)

/** Set EP2 register                       				 */
#define CSP_USB_SET_EP2(usb, val)     ((usb)->USBEP2 = (val))
/** Get EP2 register 			                   	*/
#define CSP_USB_GET_EP2(usb)           ((usb)->USBEP2)

/** Set EP3 register                       				 */
#define CSP_USB_SET_EP3(usb, val)     ((usb)->USBEP3 = (val))
/** Get EP3 register 			                   	*/
#define CSP_USB_GET_EP3(usb)           ((usb)->USBEP3)

/** Set EP4 register                       				 */
#define CSP_USB_SET_EP4(usb, val)     ((usb)->USBEP4 = (val))
/** Get EP4 register 			                   	*/
#define CSP_USB_GET_EP4(usb)           ((usb)->USBEP4)

/******************************************************************************
* PROGREG : USB Configuration
******************************************************************************/
#define USB_DN	    (0x01ul << 0)    /**< USB D- Value */
#define USB_DP	    (0x01ul << 1)    /**< USB D+ Value */
#define USB_DD	    (0x01ul << 2)    /**< USB D+/D- Direction */
#define USB_CIO	    (0x01ul << 3)    /**< USB Crystal IO Enable */
#define USB_SUSC    (0x01ul << 5)    /**< USB Suspend Control */
#define USB_WKP	    (0x01ul << 6)    /**< USB WAkeup Control*/
#define USB_TCLK    (0x01ul << 7)    /**< USB USB Transaction Clock Selection */
#define USB_NAKC    (0x01ul << 8)    /**< USB NAK Control */
#define USB_SOFINT_MASK     (0x3ul << 9)    /**< SOF Interrupt Control */
#define USB_SOFINT(val)		(((val) & 0x3ul) << 9) /**< Writing Macro */

/** Set PROGREG register (Calibration Register)                         */
#define CSP_USB_SET_PROGREG(usb, val)     ((usb)->PROGREG = (val))
/** Get PROGREG register (Calibration Register)                      	*/
#define CSP_USB_GET_PROGREG(usb)           ((usb)->PROGREG)

/******************************************************************************
* FSPULLUP : USB FS Pull Up Control
******************************************************************************/
#define USB_FSPU     (0x01ul << 0)    /**< USB Pull-up Enable */

/** Set FSPULLUP register                         */
#define CSP_USB_SET_FSPULLUP(usb, val)     ((usb)->FSPULLUP = (val))
/** Get FSPULLUP register	                              			*/
#define CSP_USB_GET_FSPULLUP(usb)           ((usb)->FSPULLUP)

/******************************************************************************
***************************** USB Registers mask ******************************
******************************************************************************/
#define	USBFA_MASK		(0x000000FFul) /**<   USBFA mask	         	*/
#define USBPM_MASK      (0x0000008Ful) /**<   USBPM mask                */
#define USBINTMON_MASK  (0x0000071Ful) /**<   USBINTMON mask            */
#define USBINTCON_MASK  (0x0000051Ful) /**<   USBINTCON mask          	*/
#define USBFN_MASK      (0x000007FFul) /**<   USBFN mask        	 	*/
#define USBEPLNUM_MASK  (0x0000FFFFul) /**<   USBEPLNUM mask            */
#define USBEP0CSR_MASK  (0xFF000083ul) /**<   USBEP0CSR mask            */
#define USBEP1CSR_MASK  (0x7FFFFB8Ful) /**<   USBEP1CSR mask            */
#define USBEP2CSR_MASK  (0x7FFFFB8Ful) /**<   USBEP2CSR mask            */
#define USBEP3CSR_MASK  (0x7FFFFB8Ful) /**<   USBEP3CSR mask            */
#define USBEP4CSR_MASK  (0x7FFFFB8Ful) /**<   USBEP4CSR mask            */
#define USBEP0WC_MASK   (0x0000001Ful) /**<   USBEP0WC mask             */
#define USBEP1WC_MASK   (0x00FF00FFul) /**<   USBEP1WC mask             */
#define USBEP2WC_MASK	(0x00FF00FFul) /**<   USBEP2WC mask	          	*/
#define USBEP3WC_MASK	(0x00FF00FFul) /**<   USBEP3WC mask	          	*/
#define USBEP4WC_MASK   (0x00FF00FFul) /**<   USBEP4WC mask             */
#define USBNAKCON1_MASK (0x80FFFFFFul) /**<   USBNAKCON1 mask           */
#define USBNAKCON2_MASK (0x80FFFFFFul) /**<   USBNAKCON2 mask         	*/
#define USBEP0_MASK	 	(0x000000FFul) /**<   USBEP0 mask	  		 	*/
#define USBEP1_MASK	 	(0x000000FFul) /**<   USBEP1 mask	          	*/
#define USBEP2_MASK	 	(0x000000FFul) /**<   USBEP2 mask	          	*/
#define USBEP3_MASK	 	(0x000000FFul) /**<   USBEP3 mask	          	*/
#define USBEP4_MASK	 	(0x000000FFul) /**<   USBEP4 mask	          	*/
#define PROGREG_MASK    (0x000007EFul) /**<   PROGREG mask              */
#define FSPULLUP_MASK	(0x00000001ul) /**<   FSPULLUP mask	          	*/

/******************************************************************************
************************* USB Registers reset value ***************************
******************************************************************************/
#define	USBFA_RST		(0x00000000ul)  /**<    USBFA reset value	   	*/
#define USBPM_RST       (0x00000000ul)  /**<    USBPM reset value       */
#define USBINTMON_RST   (0x00000000ul)  /**<    USBINTMON reset value   */
#define USBINTCON_RST   (0x0000041Ful)  /**<    USBINTCON reset value   */
#define USBFN_RST       (0x00000000ul)  /**<    USBFN reset value       */
#define USBEPLNUM_RST   (0x04030201ul)  /**<    USBEPLNUM reset value   */
#define USBEP0CSR_RST   (0x00000001ul)  /**<    USBEP0CSR reset value   */
#define USBEP1CSR_RST   (0x00002001ul)  /**<    USBEP1CSR reset value   */
#define USBEP2CSR_RST   (0x00002001ul)  /**<    USBEP2CSR reset value   */
#define USBEP3CSR_RST   (0x00002001ul)  /**<    USBEP3CSR reset value   */
#define USBEP4CSR_RST   (0x00002001ul)  /**<    USBEP4CSR reset value   */
#define USBEP0WC_RST    (0x00000000ul)  /**<    USBEP0WC reset value    */
#define USBEP1WC_RST    (0x00000000ul)  /**<    USBEP1WC reset value    */
#define USBEP2WC_RST	(0x00000000ul)  /**<    USBEP2WC reset value	*/
#define USBEP3WC_RST	(0x00000000ul)  /**<    USBEP3WC reset value	*/
#define USBEP4WC_RST    (0x00000000ul)  /**<    USBEP4WC reset value    */
#define USBNAKCON1_RST  (0x00000000ul)  /**<    USBNAKCON1 reset value  */
#define USBNAKCON2_RST  (0x00000000ul)  /**<    USBNAKCON2 reset value  */
/*USBEP0_RST~USBEP4_RST reset value is undefined 						*/
#define PROGREG_RST     (0x00000080ul)  /**<    PROGREG reset value     */
#define FSPULLUP_RST	(0x00000000ul)  /**<    FSPULLUP reset value    */

/*******************************************************************************
********************* USB External Functions Declaration ***********************
*******************************************************************************/

#endif   /**< CSP_USB_H */
