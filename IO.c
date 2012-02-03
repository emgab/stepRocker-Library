/*******************************************************************************
  Project: stepRocker Mini-TMCL

  Module:  IO.c
           I/O routines and some other useful stuff

   Copyright (C) 2011 TRINAMIC Motion Control GmbH & Co KG
                      Waterloohain 5
                      D - 22769 Hamburg, Germany
                      http://www.trinamic.com/

   This program is free software; you can redistribute it and/or modify it
   freely.

   This program is distributed "as is" in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

/**
  \file IO.c
  \author Trinamic Motion Control GmbH & Co KG
  \version 1.00

  \brief I/O functions

  This file provides functions for intializing and
  using the I/O ports and some other miscellaneous
  stuff.
*/


#include <stdlib.h>
#include "csp.h"
#include "bits.h"
#include "stepRocker.h"
#include "TMC262.h"


/*********************************************//**
  \fn InitIO(void)
  \brief Initialize I/O

  This function initalizes all I/O port pins of
  the CPU that are not initialized in somewhere
  else in other initialization functions.
*************************************************/
void InitIO(void)
{
  // GPIO init
  GPIO0->CEDR = 1;
  GPIO0->SRR = 1;
  GPIO0->OER = (1UL << 10)|(1UL << 5)|(1UL << 3)|(1UL << 1)|(1UL << 0);
  GPIO0->CODR = (1UL << 5);
  GPIO0->ODR = (1UL << 31)|(1UL << 30)|(1UL << 4)|(1UL << 2);

  GPIO1->CEDR = 1;
  GPIO1->SRR = 1;
  GPIO1->ODR = (1UL << 20)|(1UL << 19)|(1UL << 18);
  GPIO1->OER = (1UL << 22)|(1UL << 11)|(1UL << 10)|(1UL << 9)|(1UL << 8)|(1UL << 7)|(1UL << 6)|(1UL << 5);
  GPIO1->WODR = (1UL << 9)|(1UL << 8); // set open drain transistors
  CSP_IOFunctionConfigure(GROUP1, IO_Port21, IOCONF_F1);
}


/***************************************************************//**
   \fn EnableInterrupts(void)
   \brief Enable all interrupts

  This function globally enables all interrupts.
********************************************************************/
void EnableInterrupts(void)
{
  asm volatile("CPSIE I\n");
}


/***************************************************************//**
   \fn DisableInterrupts(void)
   \brief Disable all interrupts

  This function globally disables all interrupts.
********************************************************************/
void DisableInterrupts(void)
{
  asm volatile("CPSID I\n");
}


/***************************************************************//**
   \fn SetMotorCurrent(UCHAR Motor, UCHAR Current)
   \brief Set motor current
   \param Motor    Motor number (with stepRocker always 0)
   \param Current  Motor current scaled to 0..255

   This function sets the motor current, scaled to 0..255 as
   usual in TMCL.
********************************************************************/
void SetMotorCurrent(UCHAR Motor, UCHAR Current)
{
  Set262StallGuardCurrentScale(WHICH_262(Motor), Current>>3);
}


/***************************************************************//**
   \fn GetStallState(UCHAR Motor)
   \brief Get stall flag state of motor driver
   \param Motor  Motor number (with stepRocker always 0)
   \return  TRUE stall\n
            FALSE no stall

   This function reads the state of the SG_TEST pin of the TMC262.
********************************************************************/
UCHAR GetStallState(UCHAR Motor)
{
  if(Motor==0)
  {
    if(GPIO1->PDSR & BIT20)
      return TRUE;
    else
      return FALSE;
  }
  else return FALSE;
}
