/*******************************************************************************
  Project: stepRocker Mini-TMCL

  Module:  SysTick.c
           Use of the system tick timer (1ms timer)

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
  \file SysTick.c
  \author Trinamic Motion Control GmbH & Co KG
  \version 1.00

  \brief 1ms system tick timer functions

  This file provides all functions needed for easy
  access to the TMC262 stepper motor driver IC.
*/

#include "s3fn41f_conf.h"
#include "csp.h"
#include "bits.h"
#include "stepRocker.h"

static volatile U32_T TickCounter;              //!< System tick counter
extern volatile U32_T UART1TransmitDelayTimer;
extern volatile U8_T UART1TimeoutFlag;
extern volatile U32_T UART1TimeoutTimer;


/***************************************************//**
  \fn InitSysTimer(void)
  \brief Initalize system timer

  Initalize the tick timer for generating an interrupt
  every 1ms.
*******************************************************/
void InitSysTimer(void)
{
  CSP_SysTickClkConfig(SYSTICK_HCLK);
  CSP_SysTickReload(40000);
  CSP_SysTickConfigInterrupt(3, 0, ENABLE);
  CSP_SysTickEnable();
}


/***************************************************//**
  \fn CSP_SysTickHandler(void)
  \brief System timer interrupt handler

  The system timer interrupt handler counts up the
  1ms counter.
*******************************************************/
void CSP_SysTickHandler(void)
{
  //Update 1ms counter
  TickCounter++;

  //Count down RS485 transmit delay
  if(UART1TransmitDelayTimer>0) UART1TransmitDelayTimer--;

  //Count down RS485 receive timeout
  if(UART1TimeoutTimer>0)
  {
    UART1TimeoutTimer--;
    if(UART1TimeoutTimer==0) UART1TimeoutFlag=TRUE;
  }
}


/***************************************************//**
  \fn GetSysTimer(void)
  \brief Read the system timer
  \return System timer (1ms)

  This function returns the actual value of the 1ms
  system timer.
*******************************************************/
U32_T GetSysTimer(void)
{
  return TickCounter;
}
