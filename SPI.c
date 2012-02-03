/*******************************************************************************
  Project: stepRocker Mini-TMCL

  Module:  SPI.c
           Access to SPI devices (TMC429, TMC262, EEPROM)

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
  \file SPI.c
  \author Trinamic Motion Control GmbH & Co KG
  \version 1.00

  \brief SPI functions

  This file provides all functions needed for SPI
  access to the other ICs (TMC429, TMC262, EEPROM).
*/

#include "csp.h"
#include "bits.h"
#include "stepRocker.h"


/****************************************************//**
  \fn InitSPI(void)
  \brief SPI intialization

  This functions initializes the SPI. It has to be called
  once at the beginning of the main() function, before
  any other things are done that need SPI access.
********************************************************/
void InitSPI(void)
{
  //Configure Pins P0.7, P0.8 and P0.9 as SPI0 pins
  CSP_IOFunctionConfigure(GROUP0, IO_Port7, IOCONF_F1);
  CSP_IOFunctionConfigure(GROUP0, IO_Port8, IOCONF_F1);
  CSP_IOFunctionConfigure(GROUP0, IO_Port9, IOCONF_F1);

  //Configure Pins P1.14, P1.13 and P1.12 as SPI1 pins
  CSP_IOFunctionConfigure(GROUP1, IO_Port14, IOCONF_F3);
  CSP_IOFunctionConfigure(GROUP1, IO_Port13, IOCONF_F3);
  CSP_IOFunctionConfigure(GROUP1, IO_Port12, IOCONF_F3);

  //CS pins must all be high
  GPIO0->SODR=BIT10;
  GPIO1->SODR=BIT11|BIT10;

  //Configure SPI0 (where the EEPROM is connected to)
  SSP0->CR0=SSP_SPH|SSP_SPO|SSP_DSS_8BIT;
  SSP0->CR1=SSP_SSE;
  SSP0->CPSR=8;

  //Configure SPI1 (where the TMC429 and the TMC262 are connected to)
  SSP1->CR0=SSP_SPH|SSP_SPO|SSP_DSS_8BIT;
  SSP1->CR1=SSP_SSE;
  SSP1->CPSR=32;
}


/***************************************************************//**
   \fn ReadWriteSPI(UCHAR DeviceNumber, UCHAR Data, UCHAR LastTransfer)
   \brief SPI communication

   \param DeviceNumber  Index of the SPI device (see the constants in stepRocker.h)
   \param Data          Data byte to be sent
   \param LastTransfer  FALSE: device will be kept selected (for sending more bytes) \n
                        TRUE: the device will be deselected after the transfer \n

   \return Received byte

   This function handles SPI transfer. One byte will be sent, and the
   one byte will be received.
********************************************************************/
UCHAR ReadWriteSPI(UCHAR DeviceNumber, UCHAR Data, UCHAR LastTransfer)
{
  UCHAR Result;

  switch(DeviceNumber)
  {
    case SPI_DEV_TMC429:
      GPIO1->CODR=BIT11;
      break;

    case SPI_DEV_TMC262:
      GPIO1->CODR=BIT10;
      break;

    case SPI_DEV_EEPROM:
      GPIO0->CODR=BIT10;
      break;

    default:
      return 0;
      break;
  }

  switch(DeviceNumber)
  {
    case SPI_DEV_TMC429:
    case SPI_DEV_TMC262:
      SSP1->DR=Data;
      while(SSP1->SR & SSP_BSY);
      Result=SSP1->DR;
      break;

    case SPI_DEV_EEPROM:
      SSP0->DR=Data;
      while(SSP0->SR & SSP_BSY);
      Result=SSP0->DR;
      break;

    default:
      Result=0;
      break;
  }

  if(LastTransfer)
  {
    GPIO0->SODR=BIT10;
    GPIO1->SODR=BIT11|BIT10;
  }

  return Result;
}
