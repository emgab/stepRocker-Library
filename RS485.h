/*******************************************************************************
  Project: stepRocker Mini-TMCL

  Module:  RS485.h
           Definitons of RS485 functions

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
  \file RS485.h
  \author Trinamic Motion Control GmbH & Co KG
  \version 1.00

  \brief Motor monitoring

  This file contains the definitions of the RS485 functions.
*/

void InitRS485(U8_T Baudrate);
void WriteRS485(U8_T Byte);
U8_T ReadRS485(U8_T *Byte);
void SetUARTTransmitDelay(U32_T Delay);
UINT CheckUARTTimeout(void);
