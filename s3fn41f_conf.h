
/**
* @file name	s3fn41f_conf.h
* @description
*
* @history	History type - NEW/MODify/ADD/DELete
*  		 -------------------------------------------------------------------
*			|ver type when       who                       what
*			|---+---+----------+-------------------------+----------------------
*	 		 -------------------------------------------------------------------
*
* @see	RealView MDK-ARM Version 4.01
*		Config        /S3FN41F
*/

#ifndef S3FN41F_CONF_H_
#define S3FN41F_CONF_H_		
/******************************************************************************
* All includes here                                                           *
******************************************************************************/

/******************************************************************************
* All defines here                                                            *
*****************************************************************************/
//#define EVB_TYPE_A

#define USE_UART2
#define RS232_BDRATE			19200

#define Delay(i)		cnt = i;\
						while(cnt--);

/* Clock Source Specification */
//#define IMCLK20_Value ((U32_T) 20000000)
#define IMCLK_Value	 ((U32_T) 20000000)
#define EMCLK_Value	 ((U32_T) 8000000)
#define ESCLK_Value	 ((U32_T) 32768) 
#define ISCLK_Value	 ((U32_T) 32768)   

/* Flash Specification */
#define FLASHSIZE		0x40000		/* 256KB 		*/
#define SECTORSIZE		0x4000		/* 16KB 		*/
#define PAGESIZE		0x200		/* 512Byte 		*/
#define BLOCKSIZE		0x4			/* 4Byte 		*/
#define SECTOR_NUM		16
#define BLANKPATTERN	0xffffffff
#define CONFIG_SMARTOPTION  0xC0    /* chip configuration 			*/
#define PROTECT_SMARTOPTION 0xC4    /* flash memory hard protection */

#define SRAMSIZE            0x8000  /* 32KB */  	  

/* PLL P,M,S Configuration */
#define PMS_FIN1PLL20	(CM_PLLPRE(0)|CM_PLLMUL(12)|CM_PLLPOST(0)|CM_LFPASS) 
#define PMS_FIN1PLL24	(CM_PLLPRE(0)|CM_PLLMUL(16)|CM_PLLPOST(0)|CM_LFPASS)
#define PMS_FIN1PLL28	(CM_PLLPRE(0)|CM_PLLMUL(20)|CM_PLLPOST(0)|CM_LFPASS) 
#define PMS_FIN1PLL32	(CM_PLLPRE(0)|CM_PLLMUL(24)|CM_PLLPOST(0)|CM_LFPASS) 
#define PMS_FIN1PLL36	(CM_PLLPRE(0)|CM_PLLMUL(28)|CM_PLLPOST(0)|CM_LFPASS) 
#define PMS_FIN1PLL40	(CM_PLLPRE(0)|CM_PLLMUL(32)|CM_PLLPOST(0)|CM_LFPASS) 

#define PMS_FIN2PLL20	(CM_PLLPRE(0)|CM_PLLMUL(2) |CM_PLLPOST(0)|CM_LFPASS)	
#define PMS_FIN2PLL24	(CM_PLLPRE(0)|CM_PLLMUL(4) |CM_PLLPOST(0)|CM_LFPASS)	
#define PMS_FIN2PLL28	(CM_PLLPRE(0)|CM_PLLMUL(6) |CM_PLLPOST(0)|CM_LFPASS)	
#define PMS_FIN2PLL32	(CM_PLLPRE(0)|CM_PLLMUL(8) |CM_PLLPOST(0)|CM_LFPASS)	
#define PMS_FIN2PLL36	(CM_PLLPRE(0)|CM_PLLMUL(10)|CM_PLLPOST(0)|CM_LFPASS)	
#define PMS_FIN2PLL40	(CM_PLLPRE(0)|CM_PLLMUL(12)|CM_PLLPOST(0)|CM_LFPASS)	

/* PLL P,M,S Configuration */								  
#define PMS_FIN4PLL20	(CM_PLLPRE(2)|CM_PLLMUL(32)|CM_PLLPOST(1))
#define PMS_FIN4PLL24	(CM_PLLPRE(2)|CM_PLLMUL(40)|CM_PLLPOST(1))
#define PMS_FIN4PLL28	(CM_PLLPRE(2)|CM_PLLMUL(20)|CM_PLLPOST(0))
#define PMS_FIN4PLL32	(CM_PLLPRE(2)|CM_PLLMUL(24)|CM_PLLPOST(0))
#define PMS_FIN4PLL36	(CM_PLLPRE(2)|CM_PLLMUL(28)|CM_PLLPOST(0))
#define PMS_FIN4PLL40	(CM_PLLPRE(2)|CM_PLLMUL(32)|CM_PLLPOST(0))								 

#define PMS_FIN6PLL20	(CM_PLLPRE(4)|CM_PLLMUL(32)|CM_PLLPOST(1))
#define PMS_FIN6PLL24	(CM_PLLPRE(4)|CM_PLLMUL(40)|CM_PLLPOST(1))
#define PMS_FIN6PLL28	(CM_PLLPRE(4)|CM_PLLMUL(20)|CM_PLLPOST(0))
#define PMS_FIN6PLL32	(CM_PLLPRE(4)|CM_PLLMUL(24)|CM_PLLPOST(0))
#define PMS_FIN6PLL36	(CM_PLLPRE(4)|CM_PLLMUL(28)|CM_PLLPOST(0))
#define PMS_FIN6PLL40	(CM_PLLPRE(4)|CM_PLLMUL(32)|CM_PLLPOST(0))
	 																  
#define PMS_FIN8PLL20	(CM_PLLPRE(6)|CM_PLLMUL(32)|CM_PLLPOST(1))
#define PMS_FIN8PLL24	(CM_PLLPRE(6)|CM_PLLMUL(40)|CM_PLLPOST(1))
#define PMS_FIN8PLL28	(CM_PLLPRE(6)|CM_PLLMUL(20)|CM_PLLPOST(0))
#define PMS_FIN8PLL32	(CM_PLLPRE(6)|CM_PLLMUL(24)|CM_PLLPOST(0))
#define PMS_FIN8PLL36	(CM_PLLPRE(6)|CM_PLLMUL(28)|CM_PLLPOST(0))
#define PMS_FIN8PLL40	(CM_PLLPRE(6)|CM_PLLMUL(32)|CM_PLLPOST(0))	  
																	  
#define PMS_FIN10PLL20	(CM_PLLPRE(8)|CM_PLLMUL(32)|CM_PLLPOST(1))
#define PMS_FIN10PLL24	(CM_PLLPRE(8)|CM_PLLMUL(40)|CM_PLLPOST(1))
#define PMS_FIN10PLL28	(CM_PLLPRE(8)|CM_PLLMUL(20)|CM_PLLPOST(0))
#define PMS_FIN10PLL32	(CM_PLLPRE(8)|CM_PLLMUL(24)|CM_PLLPOST(0))
#define PMS_FIN10PLL36	(CM_PLLPRE(8)|CM_PLLMUL(28)|CM_PLLPOST(0))
#define PMS_FIN10PLL40	(CM_PLLPRE(8)|CM_PLLMUL(32)|CM_PLLPOST(0))

#define PMS_FIN12PLL20	(CM_PLLPRE(10)|CM_PLLMUL(32)|CM_PLLPOST(1))
#define PMS_FIN12PLL24	(CM_PLLPRE(10)|CM_PLLMUL(40)|CM_PLLPOST(1))
#define PMS_FIN12PLL28	(CM_PLLPRE(10)|CM_PLLMUL(20)|CM_PLLPOST(0))
#define PMS_FIN12PLL32	(CM_PLLPRE(10)|CM_PLLMUL(24)|CM_PLLPOST(0))
#define PMS_FIN12PLL36	(CM_PLLPRE(10)|CM_PLLMUL(28)|CM_PLLPOST(0))
#define PMS_FIN12PLL40	(CM_PLLPRE(10)|CM_PLLMUL(32)|CM_PLLPOST(0))

#define PMS_FIN16PLL20	(CM_PLLPRE(14)|CM_PLLMUL(32)|CM_PLLPOST(1))
#define PMS_FIN16PLL24	(CM_PLLPRE(14)|CM_PLLMUL(40)|CM_PLLPOST(1))
#define PMS_FIN16PLL28	(CM_PLLPRE(14)|CM_PLLMUL(20)|CM_PLLPOST(0))
#define PMS_FIN16PLL32	(CM_PLLPRE(14)|CM_PLLMUL(24)|CM_PLLPOST(0))
#define PMS_FIN16PLL36	(CM_PLLPRE(14)|CM_PLLMUL(28)|CM_PLLPOST(0))
#define PMS_FIN16PLL40	(CM_PLLPRE(14)|CM_PLLMUL(32)|CM_PLLPOST(0))

#define PMS_FIN20PLL20	(CM_PLLPRE(8) |CM_PLLMUL(32)|CM_PLLPOST(2))
#define PMS_FIN20PLL24	(CM_PLLPRE(3) |CM_PLLMUL(4) |CM_PLLPOST(1))
#define PMS_FIN20PLL28	(CM_PLLPRE(3) |CM_PLLMUL(6) |CM_PLLPOST(1))
#define PMS_FIN20PLL32	(CM_PLLPRE(3) |CM_PLLMUL(8) |CM_PLLPOST(1))
#define PMS_FIN20PLL36	(CM_PLLPRE(3) |CM_PLLMUL(10)|CM_PLLPOST(1))
#define PMS_FIN20PLL40	(CM_PLLPRE(3) |CM_PLLMUL(2) |CM_PLLPOST(0))	

/* USB PLL P,M,S Configuration */
#define PMS_FIN1UPLL48	(CM_UPLLPRE(0) |CM_UPLLMUL(40)|CM_UPLLPOST(0)|CM_LFPASS)
#define PMS_FIN2UPLL48	(CM_UPLLPRE(0) |CM_UPLLMUL(16)|CM_UPLLPOST(0)|CM_LFPASS)
#define PMS_FIN4UPLL48	(CM_UPLLPRE(2) |CM_UPLLMUL(40)|CM_UPLLPOST(0))	
#define PMS_FIN6UPLL48	(CM_UPLLPRE(4) |CM_UPLLMUL(40)|CM_UPLLPOST(0))
#define PMS_FIN8UPLL48	(CM_UPLLPRE(6) |CM_UPLLMUL(40)|CM_UPLLPOST(0))
#define PMS_FIN10UPLL48	(CM_UPLLPRE(8) |CM_UPLLMUL(40)|CM_UPLLPOST(0))	
#define PMS_FIN12UPLL48	(CM_UPLLPRE(10)|CM_UPLLMUL(40)|CM_UPLLPOST(0))
#define PMS_FIN16UPLL48	(CM_UPLLPRE(14)|CM_UPLLMUL(40)|CM_UPLLPOST(0))	 
#define PMS_FIN20UPLL48	(CM_UPLLPRE(3) |CM_UPLLMUL(4) |CM_UPLLPOST(0))	 

#endif /**< S3FN41F_CONF_H_ */
