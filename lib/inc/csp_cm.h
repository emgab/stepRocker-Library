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
* @file name	csp_cm.h
* @description Definitions, Macros and function declarations for clock manager
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part   Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_CM_H
#define CSP_CM_H

#define CSP_CM_STOPMODE_INT   	0
#define CSP_CM_STABLE_INT     	1

/******************************************************************************
************************** CM Structure Definition ****************************
******************************************************************************/

/******************************************************************************
*************************** CM types ******************************************
******************************************************************************/
/** CSR, CCR register parameter */
typedef enum
{
	EMCLK		= 0x1,
	IMCLK		= 0x2,
	ESCLK 		= 0x4,
	ISCLK		= 0x8,
	PLLCLK 		= 0x80,
	USBPLLCLK 	= 0x40
}eCM_CmdCLK;  

/** SYSCLK[2:0] parameter */
typedef enum
{
	SysEMCLK	= 0x1,
	SysIMCLK	= 0x3,
	SysESCLK 	= 0x0,
	SysISCLK	= 0x2,
	SysPLLCLK 	= 0x4
}eCM_SysCLK;  

/** Mode register parameter except SYSCLK[2:0] */
typedef enum
{
	MdEMCLK		= 0x0,
	MdIMCLK		= 0x1,
	MdESCLK		= 0x2,
	MdISCLK		= 0x3,
	MdPLLCLK_8	= 0x4,
	MdUSBPLLCLK_8= 0x5,
	MdSYSCLK_S	= 0x6,
	MdCORECLK	= 0x7
}eCM_MdCLK; 

typedef enum
{
	ChEMCLK	= 0x0,
	ChIMCLK	= 0x1,
	ChESCLK	= 0x2,
	ChISCLK	= 0x3,
	ChPLLCLK  = 0x4,
	ChIDLE    = 0x5,
	ChSTOP    = 0x6
}eClockSwitchState;
		   
typedef struct
{
	U32_T EMCLK_Frequency;
	U32_T IMCLK_Frequency;
	U32_T ESCLK_Frequency;
	U32_T ISCLK_Frequency;
	U32_T SYSCLK_Frequency;
	U32_T MAINCLK_Frequency;
	U32_T PCLK_Frequency;
	U32_T STCLK_Frequency;
	U32_T PLLCLK_Frequency;
	U32_T USBPLLCLK_Frequency;
}sCM_Frequency;

typedef enum
{
	WSRC_FRT = 0x0,
	WSRC_EXI0 = 0x1,
	WSRC_EXI1 = 0x2,
	WSRC_EXI2 = 0x3,
	WSRC_EXI3 = 0x4,
	WSRC_EXI4 = 0x5,
	WSRC_EXI5 = 0x6,
	WSRC_EXI6 = 0x7,
	WSRC_EXI7 = 0x8,
	WSRC_EXI8 = 0x9,
	WSRC_EXI9 = 0xA,
	WSRC_EXI10 = 0xB,
	WSRC_EXI11 = 0xC,
	WSRC_EXI12= 0xD,
	WSRC_EXI13= 0xE,
	WSRC_EXI14= 0xF,
	WSRC_EXI15 = 0x10,
	WSRC_USARTRX0 = 0x11,
	WSRC_USARTRX1 = 0x012,
	WSRC_USARTRX2 = 0x13,
	WSRC_CANRX0 = 0x15,
	WSRC_SPI0 = 0x17,
	WSRC_SPI1 = 0x18
}eCM_WSRC;

typedef enum
{
	eWFI = 0x0,
	eWFE = 0x1
}eWaitingForType;

typedef enum
{
	eRISING = 0x0,
	eFALLING = 0x1
}eWakeupEdgeType;

typedef struct
{
	ClockStatus emclk;
	ClockStatus imclk;
	ClockStatus esclk;
	ClockStatus isclk;
	ClockStatus pllclk;
}sCM_ClockStatus;


/******************************************************************************
@brief CM Structure
******************************************************************************/
typedef struct
{
  CSP_REGISTER_T        IDR;           	/**< Id Register                      	*/
  CSP_REGISTER_T        SRR;	       	/**< Software Reset Register          	*/
  CSP_REGISTER_T        CSR;           	/**< Control Set Register             	*/
  CSP_REGISTER_T        CCR;           	/**< Control Clear Register           	*/
  CSP_REGISTER_T        PCSR;          	/**< Peripheral Clock Set Register    	*/
  CSP_REGISTER_T		ReservedA;		/**< Reserved							*/
  CSP_REGISTER_T        PCCR;          	/**< Peripheral Clock Clear Register  	*/
  CSP_REGISTER_T		ReservedB;		/**< Reserved							*/
  CSP_REGISTER_T        PCKSR;         	/**< Peripheral Clock Status Register 	*/
  CSP_REGISTER_T		ReservedC;		/**< Reserved							*/
  CSP_REGISTER_T        MR0;           	/**< Mode Register 0                 	*/
  CSP_REGISTER_T        MR1;           	/**< Mode Register 1                 	*/
  CSP_REGISTER_T        IMSCR;         	/**< Interrupt Mask Set Clear Register	*/
  CSP_REGISTER_T        RISR;          	/**< Raw Interrupt Status Register    	*/
  CSP_REGISTER_T        MISR;          	/**< Masked Interrupt Status Register 	*/
  CSP_REGISTER_T        ICR;           	/**< Interrupt Clear Register         	*/
  CSP_REGISTER_T        SR; 	       	/**< Status Register                  	*/
  CSP_REGISTER_T        SCDR;          	/**< System Clock Divider Register    	*/
  CSP_REGISTER_T        PCDR;          	/**< Peripheral Clock Divider Register	*/
  CSP_REGISTER_T        FCDR;          	/**< FRT Clock Divider Register       	*/
  CSP_REGISTER_T        STCDR;         	/**< STT Clock Divider Register       	*/
  CSP_REGISTER_T        LCDR;          	/**< LCD Clock Divider Register       	*/
  CSP_REGISTER_T        PSTR;          	/**< PLL Stabilization Time Register  	*/
  CSP_REGISTER_T        PDPR;          	/**< PLL Divider Parameter Register   	*/
  CSP_REGISTER_T        UPSTR;         	/**< USB PLL Stabilization Time Reg.  	*/
  CSP_REGISTER_T        UPDPR;         	/**< USB PLL Divider Parameter Reg.   	*/
  CSP_REGISTER_T        EMSTR;         	/**< EMCLK Stabilization Time Register	*/
  CSP_REGISTER_T        ESSTR;         	/**< ESCLK Stabilization Time Register	*/
  CSP_REGISTER_T        BTCDR;			/**< Basic Timer Register	     		*/
  CSP_REGISTER_T        BTR;           	/**< Basic Timer Register	     		*/
  CSP_REGISTER_T        WCR0;          	/**< Wakeup Control Register0         	*/
  CSP_REGISTER_T        WCR1;          	/**< Wakeup Control Register1         	*/
  CSP_REGISTER_T		ReservedD[2];	/**< Reserved							*/
  CSP_REGISTER_T        WIMSCR;        	/**< Wakeup Interrupt Mask Set/Clear Reg*/
  CSP_REGISTER_T        WRISR;	       	/**< Wakeup Raw Interrupt Status Reg. 	*/
  CSP_REGISTER_T        WMISR;         	/**< Wakeup Masked Interrupt Status Reg.*/
  CSP_REGISTER_T        WICR;	       	/**< Wakeup Interrupt Clear Register  	*/
  CSP_REGISTER_T        NISR;	       	/**< NVIC Interrupt Status Register   	*/
  CSP_REGISTER_T		ReservedE;		/**< Reserved							*/
  CSP_REGISTER_T		SOCR;			/**< Sut-operating(Mode)Control Register*/
  CSP_REGISTER_T		PSR;		  	/**< Power Status Register   			*/
} CSP_CM_T, *CSP_CM_PTR;

/******************************************************************************
*************************** CM Registers Definition ***************************
******************************************************************************/
/******************************************************************************
* IDR : Clock Manager ID Register
******************************************************************************/
#define CM_IDCODE_MASK		(0x03FFFFFFul << 0)
#define CM_IDCODE    	   	(0x0001001Cul << 0) 

#define CSP_CM_GET_IDR(cm)	(cm->IDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define CM_SWRST	   	 	 	(0x01ul << 0) /**< CM Software Reset         */
#define CSP_CM_SET_SRR(cm, val) (cm->SRR = (val))

/******************************************************************************
* CSR : Control Set Register
* CCR : Control Clear Register
* Refer to the Common Bit field above
******************************************************************************/
/** Set CSR register 							     					    */
#define CSP_CM_SET_CSR(cm, val)		(cm->CSR = (val))
/** Set CCR register 							    			    	    */
#define CSP_CM_SET_CCR(cm, val)		(cm->CCR = (val))

/******************************************************************************
* PCSR : Peripheral Clock Set Register
* PCCR : Peripheral Clock Clear Register
* PCKSR: Peripheral Clock Status Register
******************************************************************************/
#define CM_SFMCLK		(0x01ul << 0)	/**< SFR Clock Control Bit - User Hidden   */
#define CM_OPACLK		(0x01ul << 1) 	/**< OPAMP Clock Control Bit   			   	*/
#define CM_WDTCLK		(0x01ul << 2) 	/**< WatchDog Timer Clock Control Bit   	*/
#define CM_FRTCLK		(0x01ul << 3) 	/**< FRT Timer Clock Control Bit   			*/
#define CM_PWM0CLK  	(0x01ul << 4) 	/**< PWM0 Clock Control Bit 	*/
#define CM_PWM1CLK		(0x01ul << 5) 	/**< PWM1 Clock Control Bit    	*/
#define CM_ENCCLK		(0x01ul << 6) 	/**< ENC Clock Control Bit     	*/
#define CM_IMCCLK		(0x01ul << 7) 	/**< IMC Clock Control Bit     	*/
#define CM_TC0CLK		(0x01ul << 8) 	/**< TC0 Clock Control Bit     	*/
#define CM_TC1CLK		(0x01ul << 9) 	/**< TC1 Clock Control Bit     	*/
#define CM_TC2CLK		(0x01ul << 10) 	/**< TC2 Clock Control Bit    	*/
#define CM_TC3CLK		(0x01ul << 11) 	/**< TC3 Clock Control Bit    	*/
#define CM_TC4CLK   	(0x01ul << 12) 	/**< TC4 Clock Control Bit    	*/
#define CM_TC5CLK		(0x01ul << 13) 	/**< TC5 Clock Control Bit    	*/
#define CM_TC6CLK		(0x01ul << 14) 	/**< TC6 Clock Control Bit    	*/
#define CM_TC7CLK		(0x01ul << 15)	/**< TC7 Clock Control Bit    	*/
#define CM_USART0CLK   	(0x01ul << 16) 	/**< USART0 Clock Control Bit 	*/
#define CM_USART1CLK	(0x01ul << 17) 	/**< USART1 Clock Control Bit 	*/
#define CM_USART2CLK 	(0x01ul << 18) 	/**< USART2 Clock Control Bit 	*/
#define CM_CAN0CLK   	(0x01ul << 20) 	/**< CAN0 Clock Control Bit   	*/
#define CM_ADCCLK		(0x01ul << 22) 	/**< ADC Clock Control Bit    	*/
#define CM_LCDCLK		(0x01ul << 23) 	/**< LCD Clock Control Bit     */
#define CM_SPI0CLK   	(0x01ul << 24) 	/**< SPI0 Clock Control Bit   	*/
#define CM_SPI1CLK   	(0x01ul << 25) 	/**< SPI1 Clock Control Bit   	*/
#define CM_IIC0CLK   	(0x01ul << 26) 	/**< IIC0 Clock Control Bit   	*/
#define CM_IIC1CLK   	(0x01ul << 27) 	/**< IIC1 Clock Control Bit   	*/
#define CM_PFCCLK   	(0x01ul << 29) 	/**< PFC Clock Control Bit   	*/
#define CM_IOCLK 	 	(0x01ul << 30) 	/**< IOCONF & GPIO Clock Control Bit 	*/
#define CM_STTCLK    	(0x01ul << 31) 	/**< STT Clock Control Bit	*/

/** Set PSR register */
#define CSP_CM_SET_PCSR(cm, val)	(cm->PCSR = (val))
#define CSP_CM_SET_PCCR(cm, val)	(cm->PCCR = (val))

/** Get PSR register (Status) */
#define CSP_CM_GET_PCKSR(cm)		(cm->PCKSR)

/******************************************************************************
* MR0 : Mode register 0
******************************************************************************/
#define CM_LVDRL_MASK	(0x7ul << 0)
#define CM_LVDRL(val)	((val & 0x7ul) << 0) /**< LVD Reset level      		*/
#define CM_LVDRSTEN	   	(0x01ul << 3)        /**< LVD Reset en/disable		*/
#define CM_LVDIL_MASK	(0x7ul << 4)
#define CM_LVDIL(val)	((val & 0x7ul) << 4) /**< LVD Interrupt level  		*/
#define CM_LVDINTEN	   	(0x01ul << 7)        /**< LVD Interrupt en/disable	*/
#define CM_LVD_LEVEL0	(0x6)
#define CM_LVD_LEVEL1	(0x5)
#define CM_LVD_LEVEL2	(0x4)
#define CM_LVD_LEVEL3	(0x3)
#define CM_LVD_LEVEL4	(0x2)
#define CM_LVD_LEVEL5	(0x1)
#define CM_LVD_LEVEL6  	(0x0)

#define CM_DBGIDLE		(0x01ul<<8)			/**< DebugMode IDEL				*/
#define CM_RXEV        	(0x01ul<<9)    		/**< RXEV Enable 				*/
#define CM_STCLKEN		(0x01ul<<10)		/**< Systick Timer En/Disable 	*/
#define CM_LVDPD     	(0x01ul<<11)		/**< LVD Power-Down En/Disable 	*/

#define CM_CLKOUT_MASK	(0x7ul << 12) 	   /**< CLK OUT Port Selection mask */
#define CM_CLKOUT(val)	((val & 0x7ul) << 12) /**< Clock out source select  */

/** Set MR register */
#define CSP_CM_SET_MR0(cm, val)	(cm->MR0 = (val))
/** Get MR register */
#define CSP_CM_GET_MR0(cm) 		(cm->MR0)

/******************************************************************************
* MR1 : Mode register 1
******************************************************************************/
#define CM_SYSCLK_MASK	(0x7ul << 0)  	/**< SYSCLK Selection mask 			*/
#define CM_WDTCLK_MASK	(0x7ul << 4)  	/**< WDT Clock selection mask     	*/
#define CM_FRTCLK_MASK	(0x7ul << 8)  	/**< FRT Clock selection mask   	*/
#define CM_STTCLK_MASK	(0x7ul << 12) 	/**< STT Clock selection mask   	*/
#define CM_LCDCLK_MASK	(0x7ul << 16) 	/**< LCD Clock selection mask   	*/
						  
#define CM_SYSCLK_SEL(val)	((val & 0x7ul) << 0)  /**< SYSCLK Selection		*/
#define CM_WDTCLK_SEL(val)  ((val & 0x7ul) << 4)  /**< WDT Clock selection  */
#define CM_FRTCLK_SEL(val)  ((val & 0x7ul) << 8)  /**< FRT Clock selection  */
#define CM_STTCLK_SEL(val)  ((val & 0x7ul) << 12) /**< STT Clock selection  */
#define CM_LCDCLK_SEL(val)  ((val & 0x7ul) << 16) /**< LCD Clock selection  */

/* N41F - ADD Status/Interrupt Bit 20110318*/
#define CM_WDTCLKS		(0x1ul << 20) 	/**< WDTCLK source switching stable bit */	
#define CM_FRTCLKS		(0x1ul << 21) 	/**< FRTCLK source switching stable bit */	
#define CM_STTCLKS		(0x1ul << 22) 	/**< STTCLL source switching stable bit */	
#define CM_LCDCLKS		(0x1ul << 23) 	/**< LCDCLK source switching stable bit */	

/* CM_X_SEL(val) For 'val', refer to  and use the typedef enum eCM_SysCLK */

/** Set MR register */
#define CSP_CM_SET_MR1(cm, val)	(cm->MR1 = (val))
/** Get MR register */
#define CSP_CM_GET_MR1(cm) 		(cm->MR1)

/******************************************************************************
* IMSCR : Interrupt Mask Set/Clear Register
* RISR 	: Raw Interrupt Status Register
* MISR 	: Masked Interrupt Status Register
* ICR	: Interrupt Clear Register
******************************************************************************/
/** Set IMSCR register */
#define CSP_CM_SET_IMSCR(cm, val)	(cm->IMSCR = (val))
/** Get IMSCR register */
#define CSP_CM_GET_IMSCR(cm)		(cm->IMSCR)

/** Set RISR register */
#define CSP_CM_SET_RISR(cm, val)	(cm->RISR = (val))
/** Get RISR register */
#define CSP_CM_GET_RISR(cm)         (cm->RISR)

/** Set MISR register */
#define CSP_CM_SET_MISR(cm, val)	(cm->MISR = (val))
/** Get MISR register */
#define CSP_CM_GET_MISR(cm)			(cm->MISR)

/** Set ICR register */
#define CSP_CM_SET_ICR(cm, val)		(cm->ICR = (val))
/** Get ICR register */
#define CSP_CM_GET_ICR(cm)          (cm->ICR)

/******************************************************************************
* SR  : Status Register
******************************************************************************/
#define CM_EMCLK		(0x01ul << 0)	/**< External Main Clock En/Disable	*/
#define CM_IMCLK		(0x01ul << 1) 	/**< Internal Main Clock En/Disable */
#define CM_ESCLK		(0x01ul << 2) 	/**< External Sub Clock        	 	*/
#define CM_ISCLK		(0x01ul << 3) 	/**< Internal  Sub Clock        	*/
#define CM_STABLE		(0x01ul << 4)   /**< Clock Switching Sable       	*/
#define CM_FWAKE		(0x01ul << 5) 	/**< External Main Clock        	*/
#define CM_USBPLL		(0x01ul << 6) 	/**< External Main Clock        	*/
#define CM_PLL	   		(0x01ul << 7)	/**< External Main Clock        	*/

#define CM_STCLK		(0x01ul << 8) 	/**< External Main Clock        	*/
#define CM_PCLK	   		(0x01ul << 9) 	/**< External Main Clock        	*/
#define CM_ISCLKS		(0x01ul << 10) 	/**< External Main Clock        	*/
#define CM_IDLEW		(0x01ul << 11) 	/**< External Main Clock			*/
#define CM_ESCKFAIL_END	(0x01ul << 12)	/**< ESCLK fail status end      	*/
#define CM_ESCLKFAIL    (0x01ul << 13) 	/**< ESCLK fail (clock monitor) 	*/
#define CM_EMCKFAIL_END (0x01ul << 14) 	/**< EMCLk fail status end      	*/
#define CM_EMCLKFAIL    (0x01ul << 15)	/**< EMCLK fail (clock monitor)		*/

#define CM_LVDINT  		(0x01ul << 16) 	/**< LVD Interrupt Flag 			*/
#define CM_LVDRS		(0x01ul << 17) 	/**< LVD Reset Flag 				*/
#define CM_CMDERR		(0x01ul << 18)	/**< BAD Command Flag 				*/
#define CM_IDLESP   	(0x01ul << 19) 	/**< During the SubIdle Mode,
											the Stop IVC will only be used 	*/
#define CM_ESCMRST		(0x01ul << 20)	/**< External Main Clock    		*/
#define CM_ESCM	   		(0x01ul << 21) 	/**< External Main Clock   			*/
#define CM_EMCMRST		(0x01ul << 22)	/**< External Main Clock			*/
#define CM_EMCM	   		(0x01ul << 23) 	/**< External Main Clock    		*/

#define CM_SWRSTS		(0x01ul << 24) 	/**< Software Reset Flag        	*/
#define CM_NRSTS		(0x01ul << 25) 	/**< nReset Flag 		     		*/
#define CM_LVDRSTS		(0x01ul << 26) 	/**< LVD Reset Flag             	*/
#define CM_WDTRSTS		(0x01ul << 27) 	/**< WDT Reset Flag             	*/
#define CM_PORRSTS		(0x01ul << 28) 	/**< POR Reset Flag             	*/
#define CM_ESCMRSTS 	(0x01ul << 29) 	/**< ESCLK Clock Monitor Reset Flag	*/
#define CM_EMCMRSTS		(0x01ul << 30) 	/**< EMCLK Clock Monitor Reset Flag	*/
#define CM_SYSRSTS		(0x01ul << 31) 	/**< CortexM0 System Reset      	*/

/** Set SR register 							     */
#define CSP_CM_SET_SR(cm, val)	(cm->SR = (val))
/** Get SR register 							     */
#define CSP_CM_GET_SR(cm)		(cm->SR)

/******************************************************************************
* SCDR : System Clock Divider Register
******************************************************************************/
#define CM_SDIVKEY_MASK (0xFFFFul << 16)   /**< SDIVKEY mask            */
#define CM_SDIVKEY		(0xACDCul << 16)   /**< Key for write access	*/

#define CM_SDIV_MASK	(0x07ul << 0)        /**< SysClock select mask	*/
#define CM_SDIV(val)	((val & 0x7ul) << 0) /**< SYSCLK divider	    */
#define CM_SYSCLK_DIV1  (0x00ul)
#define CM_SYSCLK_DIV2  (0x01ul)
#define CM_SYSCLK_DIV3  (0x02ul)
#define CM_SYSCLK_DIV4  (0x03ul)
#define CM_SYSCLK_DIV5  (0x04ul)
#define CM_SYSCLK_DIV6  (0x05ul)
#define CM_SYSCLK_DIV7  (0x06ul)
#define CM_SYSCLK_DIV8  (0x07ul)

/** Set SCDR register */
#define CSP_CM_SET_SCDR(cm, val)	(cm->SCDR = (val|CM_SDIVKEY))
/** Get SCDR register (Status) */
#define CSP_CM_GET_SCDR(cm)         (cm->SCDR)

/******************************************************************************
* PCDR : Peripheral Clock Divider Register
******************************************************************************/
#define CM_PDIVKEY_MASK	(0xFFFFul << 16)   /**< PDIVKEY mask              */
#define CM_PDIVKEY      (0xA3C5ul << 16)   /**< Key for write access      */

#define CM_PDIV_MASK	(0xFul << 0)           /**< PCLK  mask            */
#define CM_PDIV(val)    ((val & 0xFul) << 0)   /**< PCLK  macro           */
#define CM_PCLK_DIV1    (0x00ul)
#define CM_PCLK_DIV2    (0x01ul << 0)
#define CM_PCLK_DIV4    (0x02ul << 0)
#define CM_PCLK_DIV8    (0x04ul << 0)
#define CM_PCLK_DIV16   (0x08ul << 0)

/** Set PCDR register                                                         */
#define CSP_CM_SET_PCDR(cm, val)      (cm->PCDR = (val|CM_PDIVKEY))
/** Get SCDR register (Status)                                               */
#define CSP_CM_GET_PCDR(cm)           (cm->PCDR)

/******************************************************************************
* FCDR : FRT Clock Divider Register
******************************************************************************/
#define CM_FDIVKEY_MASK	(0xFFFFul << 16)   /**< FDIVKEY mask              */
#define CM_FDIVKEY      (0xC3DCul << 16)   /**< Key for write access      */
#define CM_NDIV_MASK	(0xFul << 0)
#define CM_MDIV_MASK	(0x7ul << 4)
#define CM_NDIV(val)    ((val & 0xFul) << 0) /**< FRT Clock Divider N     */
#define CM_MDIV(val)    ((val & 0x7ul) << 4) /**< FRT Clock Divider N     */

/** Set FCDR register                                                         */
#define CSP_CM_SET_FCDR(cm, val)	(cm->FCDR = (val|CM_FDIVKEY))
/** Get SCDR register (Status)                                               */
#define CSP_CM_GET_FCDR(cm)         (cm->FCDR)

/******************************************************************************
* STCDR : STT Clock Divider Register
******************************************************************************/
#define CM_STDIVKEY_MASK	(0xFFFFul << 16)   /**< FDIVKEY mask              */
#define CM_STDIVKEY      	(0xDC3Cul << 16)   /**< Key for write access      */
#define CM_DDIV_MASK		(0xFul << 0)
#define CM_CDIV_MASK		(0x7ul << 4)
#define CM_DDIV(val)    	((val & 0xFul) << 0) /**< FRT Clock Divider N     */
#define CM_CDIV(val)    	((val & 0x7ul) << 4) /**< FRT Clock Divider N     */

/** Set STCDR register                                                         */
#define CSP_CM_SET_STCDR(cm, val)      (cm->STCDR = (val|CM_STDIVKEY))
/** Get STCDR register (Status)                                               */
#define CSP_CM_GET_STCDR(cm)           (cm->STCDR)	
  
/******************************************************************************
* LCDR : LCD Clock Divider Register
******************************************************************************/
#define CM_LDIVKEY_MASK (0xFFFFul << 16)   /**< LDIVKEY mask              */
#define CM_LDIVKEY      (0x3CCDul << 16)   /**< Key for write access      */
#define CM_KDIV_MASK	(0xFul << 0)
#define CM_JDIV_MASK	(0x7ul << 4)
#define CM_KDIV(val)    ((val & 0xFul) << 0) /**< LCD Clock Divider K     */
#define CM_JDIV(val)    ((val & 0x7ul) << 4) /**< LCD Clock Divider J     */

/** Set LCDR register                                                         */
#define CSP_CM_SET_LCDR(cm, val)	(cm->LCDR = (val|CM_LDIVKEY))
/** Get SCDR register (Status)                                               */
#define CSP_CM_GET_LCDR(cm)			(cm->LCDR)

/******************************************************************************
* PSTR : PLL Stabilization Time Register
******************************************************************************/
#define CM_PLLSKEY_MASK	(0xFFFFul << 16)       /**< PLLSKEY mask         */
#define CM_PLLSKEY      (0x59C1ul << 16)       /**< Key for write access */
#define CM_PST_MASK     (0x7FFul << 0)
#define CM_PST(val)     ((val & 0x7FFul) << 0) /**< PLL stabilization time macro         */

/** Set PSTR register                                                        */
#define CSP_CM_SET_PSTR(cm, val)     (cm->PSTR = (val | CM_PLLSKEY))
/** Get PSTR register                                                        */
#define CSP_CM_GET_PSTR(cm)          (cm->PSTR)
					
/******************************************************************************
* PDPR : PLL Divider Parameter Register
******************************************************************************/
#define CM_PLLMUL_MASK     ((0xFFul)<< 0)    /**< PLL Multiplier mask    */
#define CM_PLLPRE_MASK     ((0x3Ful)<< 8)    /**< Pre divider parameter mask */
#define CM_PLLPOST_MASK    ((0x03ul)<< 16)   /**< Post scalar parameter mask */
#define CM_PLLKEY_MASK     (0xFFul  << 24)   /**< PLLKEY mask            */

#define CM_PLLMUL(val)     ((val & 0xFFul) << 0) /**< PLL Multiplier macro   */
#define CM_PLLPRE(val)     ((val & 0x3Ful) << 8) /**< Pre divider parameter macro */
#define CM_PLLPOST(val)    ((val & 0x03ul) << 16)/**< Post scalar parameter macro */
#define CM_LFPASS		   (0x01ul << 23) 		 /**< LFPASS Enable*/
#define CM_PLLKEY          (0xC1ul << 24) 	 	 /**< Key for write access   */

/** Set PDPR register                                                        */
#define CSP_CM_SET_PDPR(cm, val)     (cm->PDPR = (val | CM_PLLKEY))
/** Get PDPR register                                                        */
#define CSP_CM_GET_PDPR(cm)          (cm->PDPR)

/******************************************************************************
* UPSTR : USB PLL Stabilization Time Register
******************************************************************************/
#define CM_UPLLSKEY_MASK     (0xFFFFul << 16)       /**< USB PLLSKEY mask     */
#define CM_UPLLSKEY          (0x951Cul << 16)       /**< Key for write access */
#define CM_UPST_MASK		 (0x7FFul << 0)		 
#define CM_UPST(val)         ((val & 0x7FFul) << 0) /**< USB PLL stabilization
                                                        time macro            */
/** Set UPSTR register                                                        */
#define CSP_CM_SET_UPSTR(cm, val)     (cm->UPSTR = (val | CM_UPLLSKEY))
/** Get UPSTR register                                                        */
#define CSP_CM_GET_UPSTR(cm)          (cm->UPSTR)
				 
/******************************************************************************
* UPDPR : USB PLL Divider Parameter Register
******************************************************************************/
#define CM_UPLLMUL_MASK     ((0xFFul)<< 0)    /**< USB PLL Multiplier mask    */
#define CM_UPLLPRE_MASK     ((0x3Ful)<< 8)    /**< Pre divider parameter mask */
#define CM_UPLLPOST_MASK    ((0x03ul)<< 16)   /**< Post scalar parameter mask */
#define CM_UPLLKEY_MASK     (0xFFul  << 24)   /**< PLLKEY mask            */

#define CM_UPLLMUL(val)     ((val & 0xFFul) << 0) /**< USB PLL Multiplier macro   */
#define CM_UPLLPRE(val)     ((val & 0x3Ful) << 8) /**< Pre divider parameter macro */
#define CM_UPLLPOST(val)    ((val & 0x03ul) << 16)/**< Post scalar parameter macro */
#define CM_ULFPASS		    (0x01ul << 23) 		 /**< USB PLL - LFPASS Enable*/
#define CM_UPLLKEY          (0x1Cul << 24) 	 	 /**< Key for write access   */

/** Set PDPR register                                                        */
#define CSP_CM_SET_UPDPR(cm, val)     (cm->UPDPR = (val | CM_UPLLKEY))
/** Get PDPR register                                                        */
#define CSP_CM_GET_UPDPR(cm)          (cm->UPDPR)

/******************************************************************************
* EMSTR : External Main Oscillator Stabilization Time Register
******************************************************************************/
#define CM_EMSKEY_MASK     (0xFFFFul << 16)       /**< EMSTR KEY mask     */
#define CM_EMSKEY          (0xFA4Bul << 16)       /**< Key for write access */
#define CM_EMST_MASK       (0xFFFFul << 0)
#define CM_EMST(val)       ((val & 0xFFFFul) << 0) /**< EM osc stabilization
                                                        time macro */
/** Set EMSTR register                                                        */
#define CSP_CM_SET_EMSTR(cm, val)     (cm->EMSTR = (val | CM_EMSKEY))
/** Get EMSTR register                                                        */
#define CSP_CM_GET_EMSTR(cm)          (cm->EMSTR)

/******************************************************************************
* ESSTR : External Sub Oscillator Stabilization Time Register
******************************************************************************/
#define CM_ESSKEY_MASK	(0xFFFFul << 16)       /**< ESSTR KEY mask     */
#define CM_ESSKEY       (0xAFB4ul << 16)       /**< Key for write access */
#define CM_ESST_MASK    (0xFFFul << 0)
#define CM_ESST(val)    ((val & 0xFFFul) << 0) /**< ES osc stabilization
                                                        time macro            */
/** Set ESSTR register                                                        */
#define CSP_CM_SET_ESSTR(cm, val)     (cm->ESSTR = (val | CM_ESSKEY))
/** Get EMSTR register                                                        */
#define CSP_CM_GET_ESSTR(cm)          (cm->ESSTR)

/******************************************************************************
* BTCDR : Basic Timer Clock Divider Register
******************************************************************************/
#define CM_BTCDKEY_MASK     (0xFFFFul << 16)       /**< BT KEY mask          */
#define CM_BTCDKEY          (0x3569ul << 16)       /**< Key for write access */
#define CM_BTCDIV_MASK		(0xFul << 0)
#define CM_BTCDIV(val)		((val & 0xFul) << 0) /**< BT Clock divider      */
#define CM_BTCDIV4096       (0xFul)        /**< divider 4096 */
#define CM_BTCDIV2048		(0xEul)
#define CM_BTCDIV1024		(0xDul)
#define CM_BTCDIV512		(0xCul)
#define CM_BTCDIV256		(0xBul)
#define CM_BTCDIV128		(0xAul)
#define CM_BTCDIV64			(0x9ul)
#define CM_BTCDIV32			(0x8ul)
#define CM_BTCDIV16			(0x7ul)
#define CM_BTCDIV8			(0x6ul)
#define CM_BTCDIV4			(0x5ul)
#define CM_BTCDIV2			(0x4ul)
#define CM_BTCDIV1			(0x3ul)

/** Set BTCDR register                                                        */
#define CSP_CM_SET_BTCDR(cm, val)     (cm->BTCDR = (val | CM_BTCDKEY))
/** Get BTCDR register                                                        */
#define CSP_CM_GET_BTCDR(cm)          (cm->BTCDR)

/******************************************************************************
* BTR : Basic Timer Register
******************************************************************************/
#define CM_BTCV(val)       ((val & 0xFFFFul) << 0) /**< BT Count Value       */

/** Set BTR register                                                        */
#define CSP_CM_SET_BTR(cm, val)     (cm->BTR = (val))
/** Get BTR register                                                        */
#define CSP_CM_GET_BTR(cm)          (cm->BTR)

/******************************************************************************
* WCR0 : Wake-up Control Register
******************************************************************************/
#define CM_WSRC(val)	((val & 0x1Ful))  		 /**< Wake-up Source0          */

#define CM_WSRC0(val)	((val & 0x1Ful) << 0)   /**< Wake-up Source0          */
#define CM_EDGE0		(0x01ul << 6)    		/**< Wake-up Source0 Edge Type*/
#define CM_WEN0  		(0x01ul << 7)    		/**< Wake-up Source0 Enable	  */

#define CM_WSRC1(val)   ((val & 0x1Ful) << 8)   /**< Wake-up Source1          */
#define CM_EDGE1  		(0x01ul << 14)   		/**< Wake-up Source1 Edge Type*/
#define CM_WEN1     	(0x01ul << 15)   		/**< Wake-up Source1 Enable	  */

#define CM_WSRC2(val)   ((val & 0x1Ful) << 16)   /**< Wake-up Source2          */
#define CM_EDGE2  		(0x01ul << 22)  		 /**< Wake-up Source2 Edge Type*/
#define CM_WEN2			(0x01ul << 23)  		 /**< Wake-up Source2 Enable   */

#define CM_WSRC3(val)   ((val & 0x1Ful) << 24)   /**< Wake-up Source3          */
#define CM_EDGE3  		(0x01ul << 30)  		 /**< Wake-up Source3 Edge Type*/
#define CM_WEN3			(0x01ul << 31)  		 /**< Wake-up Source3 Enable   */

/** Set WCR0 register                                                        */
#define CSP_CM_SET_WCR0(cm, val)     (cm->WCR0 = (val))
/** Get WCR0 register                                                        */
#define CSP_CM_GET_WCR0(cm)          (cm->WCR0)

/******************************************************************************
* WCR1 : Wake-up Control Register
******************************************************************************/
#define CM_WSRC4(val)	((val & 0x1Ful) << 0)   /**< Wake-up Source0          */
#define CM_EDGE4  		(0x01ul << 6)   		/**< Wake-up Source0 Edge Type*/
#define CM_WEN4  		(0x01ul << 7)   		/**< Wake-up Source0 Enable   */

#define CM_WSRC5(val)   ((val & 0x1Ful) << 8)   /**< Wake-up Source1          */
#define CM_EDGE5  		(0x01ul << 14)   		/**< Wake-up Source1 Edge Type*/
#define CM_WEN5     	(0x01ul << 15)   		/**< Wake-up Source1 Enable   */

#define CM_WSRC6(val)   ((val & 0x1Ful) << 16)  /**< Wake-up Source2          */
#define CM_EDGE6  		(0x01ul << 22)   		/**< Wake-up Source2 Edge Type*/
#define CM_WEN6			(0x01ul << 23)   		/**< Wake-up Source2 Enable   */

#define CM_WSRC7(val)   ((val & 0x1Ful) << 24)  /**< Wake-up Source3          */
#define CM_EDGE7		(0x01ul << 30)   		/**< Wake-up Source3 Edge Type*/
#define CM_WEN7			(0x01ul << 31)   		/**< Wake-up Source3 Enable   */

/** Set WCR1 register                                                        */
#define CSP_CM_SET_WCR1(cm, val)     (cm->WCR1 = (val))
/** Get WCR1 register                                                       */
#define CSP_CM_GET_WCR1(cm)          (cm->WCR1)

#define CM_WSRC_EXI0 		(0)   /**< Wake-up Source - EXI0        */
#define CM_WSRC_EXI1 		(1)   /**< Wake-up Source - EXI1        */
#define CM_WSRC_EXI2 		(2)   /**< Wake-up Source - EXI2        */
#define CM_WSRC_EXI3 		(3)   /**< Wake-up Source - EXI3        */
#define CM_WSRC_EXI4 		(4)   /**< Wake-up Source - EXI4        */
#define CM_WSRC_EXI5 		(5)   /**< Wake-up Source - EXI5        */
#define CM_WSRC_EXI6 		(6)   /**< Wake-up Source - EXI6        */
#define CM_WSRC_EXI7 		(7)   /**< Wake-up Source - EXI7        */
#define CM_WSRC_EXI8 		(8)   /**< Wake-up Source - EXI8        */
#define CM_WSRC_EXI9 		(9)   /**< Wake-up Source - EXI9        */
#define CM_WSRC_EXI10 		(10)   /**< Wake-up Source - EXI10        */
#define CM_WSRC_EXI11 		(11)   /**< Wake-up Source - EXI11        */
#define CM_WSRC_EXI12 		(12)   /**< Wake-up Source - EXI12        */
#define CM_WSRC_EXI13 		(13)   /**< Wake-up Source - EXI13        */
#define CM_WSRC_EXI14 		(14)   /**< Wake-up Source - EXI14        */
#define CM_WSRC_EXI15 		(15)   /**< Wake-up Source - EXI15        */
#define CM_WSRC_FRT 		(16)   /**< Wake-up Source - FRT	        */
#define CM_WSRC_USARTRX0	(17)   /**< Wake-up Source - USARTRX0     */
#define CM_WSRC_USARTRX1 	(18)   /**< Wake-up Source - USARTRX1     */
#define CM_WSRC_USARTRX2 	(19)   /**< Wake-up Source - USARTRX2     */
//Reserved 					(20)
#define CM_WSRC_CANRX0	 	(21)   /**< Wake-up Source - CANRX0       */
//Reserved					(22)
#define CM_WSRC_SPI0		(23)   /**< Wake-up Source - SPI0        */
#define CM_WSRC_SPI1 		(24)   /**< Wake-up Source - SPI1        */
//Reserved					(25~29)
#define CM_WSRC_VUSBDET		(30)
#define CM_WSRC_USB			(31)
/******************************************************************************
* WIMSCR: Wake-up Interrupt Mask Set/Clear Register
* WISR 	: Wake-up Raw Interrupt Status Register
* WMISR	: Wake-up Masked Interrupt Status Register
* WICR	: Wake-up Interrupt Clear Register
******************************************************************************/
#define CM_WI0	   (0x01ul << 0)  /**< Wake-up interrupt 0 en/disable         */
#define CM_WI1	   (0x01ul << 1)  /**< Wake-up interrupt 1 en/disable         */
#define CM_WI2	   (0x01ul << 2)  /**< Wake-up interrupt 2 en/disable         */
#define CM_WI3	   (0x01ul << 3)  /**< Wake-up interrupt 3 en/disable         */
#define CM_WI4	   (0x01ul << 4)  /**< Wake-up interrupt 4 en/disable         */
#define CM_WI5	   (0x01ul << 5)  /**< Wake-up interrupt 5 en/disable         */
#define CM_WI6	   (0x01ul << 6)  /**< Wake-up interrupt 6 en/disable         */
#define CM_WI7	   (0x01ul << 7)  /**< Wake-up interrupt 7 en/disable         */

/** Set WIMSCR register                                                       */
#define CSP_CM_SET_WIMSCR(cm, val)       (cm->WIMSCR = (val))
/** Get WIMSCR register                                                       */
#define CSP_CM_GET_WIMSCR(cm)            (cm->WIMSCR)

/** Set WRISR register                                                        */
#define CSP_CM_SET_WRISR(cm, val)       (cm->WRISR = (val))
/** Get WRISR register                                                        */
#define CSP_CM_GET_WRISR(cm)            (cm->WRISR)

/** Set WMISR register                                                        */
#define CSP_CM_SET_WMISR(cm, val)       (cm->WMISR = (val))
/** Get WMISR register                                                        */
#define CSP_CM_GET_WMISR(cm)            (cm->WMISR)

/** Set WICR register                                                         */
#define CSP_CM_SET_WICR(cm, val)       (cm->WICR = (val))
/** Get WICR register                                                         */
#define CSP_CM_GET_WICR(cm)            (cm->WICR)

/******************************************************************************
* NISR : NVIC Interrupt Status Register
******************************************************************************/
#define CM_NVIC(n)	   (0x01ul << n)  /**< NVIC interrupt 0 status   */

#define CM_NVIC0	   (0x01ul << 0)  /**< NVIC interrupt 0 status        */
#define CM_NVIC1	   (0x01ul << 1)  /**< NVIC interrupt 1 status         */
#define CM_NVIC2	   (0x01ul << 2)  /**< NVIC interrupt 2 status         */
#define CM_NVIC3	   (0x01ul << 3)  /**< NVIC interrupt 3 status         */
#define CM_NVIC4	   (0x01ul << 4)  /**< NVIC interrupt 4 status         */
#define CM_NVIC5	   (0x01ul << 5)  /**< NVIC interrupt 5 status         */
#define CM_NVIC6	   (0x01ul << 6)  /**< NVIC interrupt 6 status         */
#define CM_NVIC7	   (0x01ul << 7)  /**< NVIC interrupt 7 status         */
#define CM_NVIC8	   (0x01ul << 8)  /**< NVIC interrupt 8 status         */
#define CM_NVIC9	   (0x01ul << 9)  /**< NVIC interrupt 9 status         */
#define CM_NVIC10	   (0x01ul << 10)  /**< NVIC interrupt 10 status         */
#define CM_NVIC11	   (0x01ul << 11)  /**< NVIC interrupt 11 status         */
#define CM_NVIC12	   (0x01ul << 12)  /**< NVIC interrupt 12 status         */
#define CM_NVIC13  	   (0x01ul << 13)  /**< NVIC interrupt 13 status         */
#define CM_NVIC14	   (0x01ul << 14)  /**< NVIC interrupt 14 status         */
#define CM_NVIC15	   (0x01ul << 15)  /**< NVIC interrupt 15 status         */
#define CM_NVIC16	   (0x01ul << 16)  /**< NVIC interrupt 16 status         */
#define CM_NVIC17	   (0x01ul << 17)  /**< NVIC interrupt 17 status         */
#define CM_NVIC18	   (0x01ul << 18)  /**< NVIC interrupt 18 status         */
#define CM_NVIC19	   (0x01ul << 19)  /**< NVIC interrupt 19 status         */
#define CM_NVIC20	   (0x01ul << 20)  /**< NVIC interrupt 20 status         */
#define CM_NVIC21	   (0x01ul << 21)  /**< NVIC interrupt 21 status         */
#define CM_NVIC22	   (0x01ul << 22)  /**< NVIC interrupt 22 status         */
#define CM_NVIC23	   (0x01ul << 23)  /**< NVIC interrupt 23 status         */
#define CM_NVIC24	   (0x01ul << 24)  /**< NVIC interrupt 24 status         */
#define CM_NVIC25	   (0x01ul << 25)  /**< NVIC interrupt 25 status         */
#define CM_NVIC26	   (0x01ul << 26)  /**< NVIC interrupt 26 status         */
#define CM_NVIC27	   (0x01ul << 27)  /**< NVIC interrupt 27 status         */
#define CM_NVIC28	   (0x01ul << 28)  /**< NVIC interrupt 28 status         */
#define CM_NVIC29	   (0x01ul << 29)  /**< NVIC interrupt 29 status         */
#define CM_NVIC30	   (0x01ul << 30)  /**< NVIC interrupt 30 status         */
#define CM_NVIC31	   (0x01ul << 31)  /**< NVIC interrupt 31 status         */

/** Set NISR register                                                        */
#define CSP_CM_SET_NISR(cm, val)     (cm->NISR = (val))
/** Get NISR register                                                        */
#define CSP_CM_GET_NISR(cm)          (cm->NISR)

/******************************************************************************
* SOCR : Normal Sub Operation Mode Control using Stop IVC (For internal only)
******************************************************************************/
#define CM_SOWSIVC			  (0x01ul<<0) /* Sub-operating mode with Stop IVC */

/** Set NISR register */
#define CSP_CM_SET_SOCR(cm, val) 	(cm->SOCR = (val))
/** Get NISR register */
#define CSP_CM_GET_SOCR(cm) 		(cm->SOCR)

/******************************************************************************
* PSR : Power Status Register
******************************************************************************/
#define CM_SUBIVCS		(0x01ul<<0)
#define CM_NORIVCS		(0x01ul<<1)
#define CM_VUSBDET		(0x1ul<<31)

#define CSP_CM_GET_PSR(cm) (cm->PSR)

/******************************************************************************
*************************** CM Registers mask *********************************
******************************************************************************/
#define CM_IDR_MASK	    (0x03FFFFFFul) /**< IDR mask                   */
#define CM_SRR_MASK    	(0x00000001ul) /**< SRR mask                   */
#define CM_CSR_MASK     (0x00F80FEFul) /**< CSR mask                   */
#define CM_CCR_MASK    	(0x00F80FEFul) /**< CCR mask                   */
#define CM_PCSR_MASK  	(0xFFFFFFFFul) /**< PCSR mask                  */
#define CM_PCCR_MASK    (0xFFFFFFFFul) /**< PCCR mask                  */
#define CM_PCKSR_MASK   (0xFFFFFFFFul) /**< PCKSR mask                 */
#define CM_MR0_MASK     (0x00007FFFul) /**< MR0 mask                   */
#define CM_MR1_MASK     (0x00077777ul) /**< MR1 mask 		 	       */
#define CM_IMSCR_MASK   (0x0005F0DFul) /**< IMSCR mask 		           */
#define CM_RISR_MASK    (0x0007F0DFul) /**< RISR mask 				   */
#define CM_MISR_MASK    (0x0005F0DFul) /**< MISR mask 		           */
#define CM_ICR_MASK     (0x0007F0DFul) /**< ICR mask 		           */
#define CM_SR_MASK      (0xFFFFFFFFul) /**< SR mask                    */
#define CM_SCDR_MASK    (0xFFFF0007ul) /**< SCDR mask                  */
#define CM_PCDR_MASK    (0xFFFF000Ful) /**< PCDR mask                  */
#define CM_FCDR_MASK    (0xFFFF007Ful) /**< FCDR mask                  */
#define CM_STCDR_MASK   (0xFFFF007Ful) /**< FCDR mask                  */
#define CM_LCDR_MASK    (0xFFFF007Ful) /**< LCDR mask                  */
#define CM_PSTR_MASK    (0xFFFF07FFul) /**< PSTR mask                  */
#define CM_PDPR_MASK   	(0xFF833FFFul) /**< PDPR reret                 */
#define CM_UPSTR_MASK   (0xFFFF07FFul) /**< UPSRT mask                 */
#define CM_UPDPR_MASK   (0xFF833FFFul) /**< UPDPR mask                 */
#define CM_EMSTR_MASK   (0xFFFFFFFFul) /**< EMSTR mask                 */
#define CM_ESSTR_MASK   (0xFFFFFFFFul) /**< ESSTR mask                 */
#define CM_BTCDR_MASK   (0xFFFF000Ful) /**< ESSTR mask                 */
#define CM_BTR_MASK     (0x0000FFFFul) /**< BTR mask                   */
#define CM_WCR0_MASK    (0xFFFFFFFFul) /**< WCR0 mask                  */
#define CM_WCR1_MASK    (0xFFFFFFFFul) /**< WCR1 mask                  */
#define CM_WIMSCR_MASK  (0x000000FFul) /**< WIMSCR mask                */
#define CM_WRISR_MASK   (0x000000FFul) /**< WRISR mask                 */
#define CM_WMISR_MASK   (0x000000FFul) /**< WMISR mask                 */
#define CM_WICR_MASK    (0x000000FFul) /**< WICR mask                  */
#define CM_NISR_MASK    (0xFFFFFFFFul) /**< NISR mask                  */
#define CM_SOCR_MASK    (0x00000001ul) /**< SOCR mask                  */
#define CM_PSR_MASK     (0x80000003ul) /**< PSR mask                   */

/**************************************************************************
************************* CM Registers reset value ************************
**************************************************************************/
#define CM_IDR_RST	  (0x0001001Cul)  /**< IDR reset                   */
#define CM_SRR_RST    (0x00000000ul)  /**< SRR reset                   */
#define CM_CSR_RST    (0x00000000ul)  /**< CSR reset                   */
#define CM_CCR_RST    (0x00000000ul)  /**< CCR reset                   */
#define CM_PCSR_RST   (0x00000000ul)  /**< PCSR reset                  */
#define CM_PCCR_RST   (0x00000000ul)  /**< PCCR reset                  */
#define CM_PCKSR_RST  (0x0000000Cul)  /**< PSR reset                   */
#define CM_MR0_RST    (0x00000828ul)  /**< MR0 reset                   */
#define CM_MR1_RST    (0x00020313ul)  /**< MR1 reset  			       */
#define CM_IMSCR_RST  (0x00000000ul)  /**< IMSCR reset                 */
#define CM_RISR_RST   (0x0000001Ful)  /**< RISR reset 			       */
#define CM_MISR_RST   (0x00000000ul)  /**< MISR reset                  */
#define CM_ICR_RST    (0x00000000ul)  /**< ICR reset                   */
#define CM_SR_RST     (0x16A0001Ful)  /**< SR reset                    */
#define CM_SCDR_RST   (0x00000007ul)  /**< SCDR reset                  */
#define CM_PCDR_RST   (0x00000000ul)  /**< PCDR reset                  */
#define CM_FCDR_RST   (0x00000000ul)  /**< FCDR reset                  */
#define CM_STCDR_RST  (0x00000000ul)  /**< FCDR reset                  */
#define CM_LCDR_RST   (0x00000000ul)  /**< LCDR reset                  */
#define CM_PSTR_RST   (0x00000154ul)  /**< PSTR reset                  */
#define CM_PDPR_RST   (0x00000000ul)  /**< PDPR reret                  */
#define CM_UPSTR_RST  (0x00000154ul)  /**< UPSRT reset                 */
#define CM_UPDPR_RST  (0x00000000ul)  /**< UPDPR reset                 */
#define CM_EMSTR_RST  (0x00002710ul)  /**< EMSTR reset                 */
#define CM_ESSTR_RST  (0x0000FFFFul)  /**< ESSTR reset                 */
#define CM_BTCDR_RST  (0x0000000Ful)  /**< BTCDR reset                 */
#define CM_BTR_RST    (0x00000100ul)  /**< BTR reset                   */
#define CM_WCR0_RST   (0x00000000ul)  /**< WCR0 reset                  */
#define CM_WCR1_RST   (0x00000000ul)  /**< WCR1 reset                  */
#define CM_WIMSCR_RST (0x00000000ul)  /**< WIMSCR reset                */
#define CM_WRISR_RST  (0x00000000ul)  /**< WRISR reset                 */
#define CM_WMISR_RST  (0x00000000ul)  /**< WMISR reset                 */
#define CM_WICR_RST   (0x00000000ul)  /**< WICR reset                  */
#define CM_NISR_RST   (0x00000000ul)  /**< NISR reset                  */
#define CM_SOCR_RST   (0x00000000ul)  /**< SOCR reset                  */
#define CM_PSR_RST    (0x00000002ul)  /**< PSR reset                   */

/******************************************************************************
****************** Clock Manager External Functions Declaration ***************
******************************************************************************/
extern sCM_Frequency n41f; 							 
extern void CSP_CMSoftwareReset(void);
extern void CSP_CMEMCLKCmd(ClockStatus cmd);
extern void CSP_CMIMCLKCmd(ClockStatus cmd);
extern void CSP_CMESCLKCmd(ClockStatus cmd);
extern void CSP_CMISCLKCmd(ClockStatus cmd);
extern void CSP_CMPLLCmd(ClockStatus cmd);
extern void CSP_CMUSBPLLCmd(ClockStatus cmd);
extern void CSP_CMPclkCmd(U32_T Pclk,ClockStatus endis);
extern void CSP_CMLVDRCmd(FunctionalStatus cmd,U32_T level);  	
extern void CSP_CMIdleClkCmd(ClockStatus stclk, ClockStatus pclk);
extern void CSP_CMFastWakeupCmd(FunctionalStatus cmd);
extern void CSP_CMPLLConfig(U32_T PMS_value);
extern void CSP_CMUSBPLLConfig(U32_T PMS_value);					 
extern void CSP_CMEMClkMonitorConfig(FunctionalStatus cmMonitor,FunctionalStatus cmReset);
extern void CSP_CMESClkMonitorConfig(FunctionalStatus cmMonitor,FunctionalStatus cmReset); 
extern void CSP_CMSysclkDivConfig(U32_T SClkDiv);
extern void CSP_CMPclkDivConfig(U32_T PClkDiv);
extern void CSP_CMSysclkChange(eCM_SysCLK clkSrc);			   
extern void CSP_CMWDTClkConfig(eCM_MdCLK clkSrc);
extern void CSP_CMFRTClkConfig(eCM_MdCLK clkSrc,U32_T Mdiv, U32_T Ndiv);
extern void CSP_CMSTTClkConfig(eCM_MdCLK clkSrc,U32_T Cdiv, U32_T Ddiv);
extern void CSP_CMLCDClkConfig(eCM_MdCLK clkSrc,U32_T Jdiv, U32_T Kdiv); 
extern void CSP_CMGetFrequency(sCM_Frequency* CMClk);				
extern void CSP_CMConfigInterrupt(U32_T intMask_u32,FunctionalStatus newState);
extern FlagStatus CSP_CMGetFlagStatus(U32_T Flag);
extern FlagStatus CSP_CMGetRawITStatus(U32_T Flag);
extern FlagStatus CSP_CMGetMaskedITStatus(U32_T Flag);
extern void CSP_CMClearITFlag(U32_T Flag);					 
extern void CSP_CMStopCmd(eWaitingForType type);
extern void CSP_CMIdleCmd(eWaitingForType type);
extern void CSP_CMWakeupSrcConfig(U32_T num, U32_T src, eWakeupEdgeType edge,FunctionalStatus cmd);	
extern void CSP_CMClockOutCmd(eCM_MdCLK clksrc);
extern void CSP_CMClockOutPinConfig(FunctionalStatus cmd);

#endif /* CSP_CM_H */

