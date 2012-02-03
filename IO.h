/*******************************************************************************
  Project: stepRocker Mini-TMCL

  Module:  IO.h
           Definitions of I/O functions

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
  \file IO.h
  \author Trinamic Motion Control GmbH & Co KG
  \version 1.00

  \brief I/O functions

  This file contains definitions for using the I/O functions.
*/

void InitIO(void);
void EnableInterrupts(void);
void DisableInterrupts(void);
void SetMotorCurrent(UCHAR Motor, UCHAR Current);
UCHAR GetStallState(UCHAR Motor);
