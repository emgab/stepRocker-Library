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
* @file name	csp_pwm.h
* @description Definitions, Macros and function declarations for PWM
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   Yh JIN			  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

#ifndef CSP_PWM_H
#define CSP_PWM_H
#include <stdio.h>

/* Duty Generation -----------------------------------------------------------*/
#define PERIOD(p)		p
#define PULSE(s)		s
#define IDLE(x)			x
#define START(y)		y
#define Mdiv(m)			m
#define Ndiv(n)			n

/******************************************************************************
************************** PWM Structure Definition ***************************
******************************************************************************/
/******************************************************************************
@brief PWM Structure
******************************************************************************/
typedef struct
{
  	CSP_REGISTER_T     IDR;		/**< ID Register	            		*/
   	CSP_REGISTER_T     CEDR;    /**< Clock Enable/Disable Register 	 	*/
   	CSP_REGISTER_T     SRR;     /**< Software Reset Register        	*/
	CSP_REGISTER_T     CSR;     /**< Control Set Register               */
	CSP_REGISTER_T     CCR;     /**< Control Clear Register             */
	CSP_REGISTER_T     SR;      /**< Status Register                    */
	CSP_REGISTER_T     IMSCR;   /**< Interrupt Mask Set/Clear Register  */
	CSP_REGISTER_T     RISR;    /**< Raw Interrupt Status Register      */
	CSP_REGISTER_T     MISR;    /**< Masked Interrupt Status Register   */
	CSP_REGISTER_T     ICR;     /**< Interrupt Clear Register           */
  	CSP_REGISTER_T     CDR;     /**< Clock Divider Register             */
 	CSP_REGISTER_T     PRDR;    /**< Period Register                    */
   	CSP_REGISTER_T     PULR;    /**< Pulse Register						*/
   	CSP_REGISTER_T     CCDR;    /**< Current Clock Divider Register     */
 	CSP_REGISTER_T     CPRDR;   /**< Current Period Register            */
   	CSP_REGISTER_T     CPULR;   /**< Current Pulse Register				*/
 } CSP_PWM_T, *CSP_PWM_PTR;

/******************************************************************************
* IDR : ID Register
******************************************************************************/
#define PWM_IPIDCODE_MASK  (0x03FFFFFFul << 0)  /**< PWM IPIDCODE mask     */
#define PWM_IPIDCODE  	   (0x00010009 << 0) 	/**< PWM IPIDCODE mask     */

/** Get IDR register                                                         */
#define CSP_PWM_GET_IDR(pwm)        ((pwm)->IDR)

/******************************************************************************
* CEDR : Clock Enable/Disable Register
******************************************************************************/
#define PWM_CLKEN          (0x01ul << 0)         /**< PWM Clock             */
#define PWM_DBGEN          (0x01ul << 31)        /**< Debug Mode Enable     */

/** Set CEDR register 		                                                */
#define CSP_PWM_SET_CEDR(pwm, val)    ((pwm)->CEDR = (val))
/** Get CEDR register                                              			*/
#define CSP_PWM_GET_CEDR(pwm)        ((pwm)->CEDR)

/******************************************************************************
* SRR : Software Reset Register
******************************************************************************/
#define PWM_SWRST          (0x01ul << 0)         /**< Software Reset        */

/** Set SRR register 		                                             	*/
#define CSP_PWM_SET_SRR(pwm, val)    ((pwm)->SRR = (val))
/******************************************************************************
* CSR : Control Set Register
* CCR : Control Clear Register
* SR : Statis Register
******************************************************************************/
#define PWM_PWMEX_MASK (0x03Ful << 24)

#define PWM_START      (0x01ul << 0)	/**< PWM Start	                    */
#define PWM_UPDATE     (0x01ul << 1)	/**< PWM Configuration update       */
#define PWM_IDLESL     (0x01ul << 8)    /**< Idle level for 0  				*/
#define PWM_OUTSL	   (0x01ul << 9)    /**< Sample level for 0				*/
#define PWM_KEEP       (0x01ul << 10)   /**< Dual mode for 0  				*/
#define PWM_PWMIM      (0x01ul << 11)   /**< Interval Mode 					*/
#define PWM_PWMEX0     (0x01ul << 24)   /**< PWM Extension 0              	*/
#define PWM_PWMEX1     (0x01ul << 25)   /**< PWM Extension 1              	*/
#define PWM_PWMEX2     (0x01ul << 26)   /**< PWM Extension 2              	*/
#define PWM_PWMEX3     (0x01ul << 27)   /**< PWM Extension 3              	*/
#define PWM_PWMEX4     (0x01ul << 28)   /**< PWM Extension 4              	*/
#define PWM_PWMEX5     (0x01ul << 29)   /**< PWM Extension 5              	*/

/** Set CSR register                                                        */
#define CSP_PWM_SET_CSR(pwm, val)   ((pwm)->CSR = (val))

/** Set CCR register                                                        */
#define CSP_PWM_SET_CCR(pwm, val)	((pwm)->CCR = (val))

/** Get SR register                                               	        */
#define CSP_PWM_GET_SR(pwm)        	((pwm)->SR)
/******************************************************************************
* IMSCR : Interrupt Mask Set/Clear Register
* RISR : Raw Interrupt Status Register
* MISR : Interrupt Status Register
* ICR : Interrupt Clear Register
******************************************************************************/
#define PWM_START     (0x01ul << 0)      /**< PWM Start Interrupt           */
#define PWM_STOP      (0x01ul << 1)      /**< PWM Stop Interrupt            */
#define PWM_PSTART    (0x01ul << 2)      /**< Period Start Interrupt        */
#define PWM_PEND      (0x01ul << 3)      /**< Period End Interrupt          */
#define PWM_PMATCH    (0x01ul << 4)      /**< Pulse Match Interrupt         */

/** Set IMSCR register                                                      */
#define CSP_PWM_SET_IMSCR(pwm, val)		((pwm)->IMSCR = (val))
/** Get IMSCR register                                                      */
#define CSP_PWM_GET_IMSCR(pwm)          ((pwm)->IMSCR)

/** Get RISR register (Status)                                              */
#define CSP_PWM_GET_RISR(pwm)          	((pwm)->RISR)

/** Get MISR register (Status)                                              */
#define CSP_PWM_GET_MISR(pwm)          	((pwm)->MISR)

/** Set ICR register                                                       */
#define CSP_PWM_SET_ICR(pwm, val)     	((pwm)->ICR = (val))

/******************************************************************************
* CDR : Clock Divider Register
******************************************************************************/
#define PWM_DIVN_MASK   (0x0Ful << 0) 	/**< Clock Divider N  		     */
#define PWM_DIVM_MASK   (0xFFFul << 4) 	/**< Clock Divider M       	     */

#define PWM_DIVN(val)  (((val) & 0x0Ful) <<0)  /**< Divier N          */
#define PWM_DIVM(val)  (((val) & 0xFFFul)<<4)  /**< Divier N  	     */

/** Set CDR register                                                         */
#define CSP_PWM_SET_CDR(pwm, val)   ((pwm)->CDR = (val))

 /** Get CDR register                                               	     */
#define CSP_PWM_GET_CDR(pwm)        ((pwm)->CDR)

/******************************************************************************
* PRDR : Period Register
******************************************************************************/
#define PWM_PERIOD_MASK   (0xFFFFul << 0)            /**< Period Mask       */
#define PWM_PERIOD(val)   (((val) & PWM_PERIOD_MASK))  /**< Period  Macro   */

/** Set PERIOD register                                                     */
#define CSP_PWM_SET_PRDR(pwm, val) 	((pwm)->PRDR = (val))

/** Get PERIOD register                                                     */
#define CSP_PWM_GET_PRDR(pwm)      	((pwm)->PRDR)

/******************************************************************************
* PULR : Pulse Register
******************************************************************************/
#define PWM_PULSE_MASK   (0xFFFFul << 0)    /**< Pulse Width Mask   */
#define PWM_PULSE(val)   ((val) & PWM_PULSE_MASK)   /**< Pulse Writing Macro*/

/** Set PULR register                                                         */
#define CSP_PWM_SET_PULR(pwm, val)	((pwm)->PULR = (val))

/** Get PULR register                                                         */
#define CSP_PWM_GET_PULR(pwm)		((pwm)->PULR)

/******************************************************************************
* CCDR : Current Clock Divider Register
******************************************************************************/
/** Get CCDR register */
#define CSP_PWM_GET_CCDR(pwm)       ((pwm)->CCDR)

/******************************************************************************
* CPRDR : Current Period Register
******************************************************************************/
/** Get CPRDR register */
#define CSP_PWM_GET_CPRDR(pwm)      ((pwm)->CPRDR)

/******************************************************************************
* CPULR : Current Pulse Register
******************************************************************************/
/** Get CPULR register */
#define CSP_PWM_GET_CPULR(pwm)		((pwm)->CPULR)

/******************************************************************************
***************************** PWM Registers mask ******************************
******************************************************************************/
#define PWM_IDR_MASK    (0x3FFFFFFFul)  /**< IDR mask                       */
#define PWM_CEDR_MASK	(0x80000001ul)  /**< CEDR mask                      */
#define PWM_SRR_MASK    (0x00000001ul)  /**< SRR mask                       */
#define PWM_CSR_MASK   	(0x3F000F03ul)  /**< CSR mask		            	*/
#define PWM_CCR_MASK    (0x3F000F01ul)  /**< CCR mask                	    */
#define PWM_SR_MASK     (0x3F000F01ul)  /**< SR mask                        */
#define PWM_IMSCR_MASK  (0x0000001Ful)  /**< IMSCR mask                     */
#define PWM_RISR_MASK   (0x0000001Ful)  /**< RISR mask                      */
#define PWM_MISR_MASK   (0x0000001Ful)  /**< MISR mask                      */
#define PWM_ICR_MASK    (0x0000001Ful)  /**< ICR mask                       */

#define PWM_CDR_MASK    (0x00007FFFul)  /**< CDR mask                       */
#define PWM_PRDR_MASK   (0x0000FFFFul)  /**< PRDR mask                      */
#define PWM_PULR_MASK   (0x0000FFFFul)  /**< PULR mask                      */
#define PWM_CCDR_MASK   (0x00007FFFul)  /**< CCDR mask                      */
#define PWM_CPRDR_MASK  (0x0000FFFFul)  /**< CPRDR mask                     */
#define PWM_CPULR_MASK  (0x0000FFFFul)  /**< CPULR mask                     */
/******************************************************************************
************************* PWM Registers reset value ***************************
******************************************************************************/
#define PWM_IDR_RST     (0x00010009ul)  /**< IDR reset value                */
#define PWM_CEDR_RST	(0x00000000ul)  /**< CEDR reset value               */
#define PWM_SRR_RST     (0x00000000ul)  /**< SRR reset value                */
#define PWM_CSR_RST     (0x00000000ul)  /**< CSR reset value		    	*/
#define PWM_CCR_RST     (0x00000000ul)  /**< CCR reset value                */
#define PWM_SR_RST      (0x00000000ul)  /**< SR reset value                 */
#define PWM_IMSCR_RST   (0x00000000ul)  /**< IMSCR reset value              */
#define PWM_RISR_RST    (0x00000000ul)  /**< RISR reset value               */
#define PWM_MISR_RST    (0x00000000ul)  /**< MISR reset value               */
#define PWM_ICR_RST     (0x00000000ul)  /**< ICR reset value                */
#define PWM_CDR_RST     (0x00000000ul)  /**< CDR reset value                */
#define PWM_PRDR_RST    (0x00000000ul)  /**< PRDR reset value               */
#define PWM_PULR_RST    (0x00000000ul)  /**< PULR reset value               */
#define PWM_CCDR_RST    (0x00000000ul)  /**< CCDR reset value               */
#define PWM_CPRDR_RST   (0x00000000ul)  /**< CPRDR reset value              */
#define PWM_CPULR_RST   (0x00000000ul)  /**< CPULR reset value              */
/******************************************************************************
********************** PWM External Functions Declaration *********************
******************************************************************************/
extern void CSP_PWMInit(CSP_PWM_T *pwm);
extern void CSP_PWMClockEnable(CSP_PWM_T *pwm);
extern void CSP_PWMClockDisable(CSP_PWM_T *pwm);
extern void CSP_PWMDbgenCmd(CSP_PWM_T *pwm, FunctionalStatus cmd);
extern void CSP_PWMClose(CSP_PWM_T *pwm);
extern void CSP_PWMConfigInterrupt(CSP_PWM_T *pwm,\
                            	  U32_T intMask_u32, FunctionalStatus newState);
extern void CSP_PWMClockConfiguration(CSP_PWM_T *pwm,\
									U16_T clkdiv_m,U8_T clkdiv_n);
extern void CSP_PWMConfigure(CSP_PWM_T *pwm,U8_T idlelevel, U8_T startlevel,
                               U16_T period_u16, U16_T pulse_u16);
extern ErrorStatus CSP_PWMIntervalMode(CSP_PWM_T *pwm);
extern ErrorStatus CSP_PWMNormalMode(CSP_PWM_T *pwm);
extern ErrorStatus CSP_PWMStopLevelKeep(CSP_PWM_T *pwm);
extern void CSP_PWMStart(CSP_PWM_T *pwm );
extern void CSP_PWMStop(CSP_PWM_T *pwm);
extern void CSP_PWMUpdate(CSP_PWM_T *pwm);


#endif   /* CSP_PWM_H */
