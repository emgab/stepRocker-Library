/*******************************************************************************
  Project: stepRocker Mini-TMCL

  Module:  SPI.h
           Definitions of SPI access functions

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
  \file SPI.h
  \author Trinamic Motion Control GmbH & Co KG
  \version 1.00

  \brief SPI functions

  This file contains the definitions of the SPI access functions.
*/

void InitSPI(void);
UCHAR ReadWriteSPI(UCHAR DeviceNumber, UCHAR Data, UCHAR LastTransfer);



