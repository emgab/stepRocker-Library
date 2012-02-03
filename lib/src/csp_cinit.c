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
* @file name	csp_cinit.c
* @description Copy RO code, RW data from ROM to RAM and zero-initialized
*              the ZI data areas in RAM
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	  Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

/******************************************************************************
* Include files
******************************************************************************/
#include "..\CSP\inc\csp.h"

/******************************************************************************
* Declarations
******************************************************************************/
extern U32_T Region$$Table$$Base;
extern U32_T Region$$Table$$Limit;
extern U32_T ZISection$$Table$$Base;
extern U32_T ZISection$$Table$$Limit;
/******************************************************************************
****************************  F U N C T I O N S  ******************************
******************************************************************************/

/******************************************************************************
* Function          : CSP_CInit
* Description       : Copy RO code, RW data from ROM to RAM and zero-initialized
*                     the ZI data areas in RAM
* Inputs            : None
* Functions called  : None
* Return            : None
******************************************************************************/
void CSP_CInit(void)
{
   /* Local variables */
   U32_T index_u32;
   U32_T source_u32;
   U32_T destination_u32;
   U32_T taille_u32;
   U32_T i_u32;
   U32_T start_u32;
   U32_T end_u32;

   start_u32 = (U32_T) &Region$$Table$$Base;
   end_u32   = (U32_T) &Region$$Table$$Limit;

   /* For RO & RW sections */
   for(index_u32 = start_u32; index_u32 < end_u32; index_u32 += (3*4))
   {
      source_u32      = *((U32_T*) (index_u32));
      destination_u32 = *((U32_T*) (index_u32 + 4));
      taille_u32      = *((U32_T*) (index_u32 + 8)) / 4;

      for(i_u32=0; i_u32 < taille_u32; i_u32++)
      {
         *((U32_T*) (destination_u32)) =  *((U32_T*) (source_u32));
         destination_u32 += 4;
         source_u32      += 4;
      }
   }

   start_u32 = (U32_T) &ZISection$$Table$$Base;
   end_u32   = (U32_T) &ZISection$$Table$$Limit;

   /* For ZI sections */
   for(index_u32 = start_u32; index_u32 < end_u32; index_u32 += (2*4))
   {
      destination_u32 = *((U32_T*) (index_u32));
      taille_u32      = *((U32_T*) (index_u32 + 4)) / 4;

      for(i_u32=0; i_u32 < taille_u32; i_u32++)
      {
         *((U32_T*) (destination_u32)) = 0;
         destination_u32 += 4;
      }
   }
}
