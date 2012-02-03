/*******************************************************************************
  Project: stepRocker Mini-TMCL

  Module:  RS485.c
           Access to the RS485 interface

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
  \file RS485.c
  \author Trinamic Motion Control GmbH & Co KG
  \version 1.00

  \brief RS485 functions

  This file provides all functions needed for using
  the RS485 interface.
*/

#include "s3fn41f_conf.h"
#include "csp.h"
#include "bits.h"
#include "stepRocker.h"


#define UART_BUFFER_SIZE 32        //!< Size of the RS485 transmit and receive buffers
#define UART_TIMEOUT_VALUE 5       //!< Timeout value (ms)

#define SET_RS485_SEND_MODE() GPIO1->SODR=BIT5    //!< Switch RS485 transceiver to send mode
#define SET_RS485_RECV_MODE() GPIO1->CODR=BIT5    //!< Switch RS485 transceiver to receive mode
#define IS_RS485_SENDING() (GPIO1->ODSR & BIT5)   //!< TRUE when transceiver is in send mode

// 0    1    2    3    4    5    6    7     8
//9.6  14.4 19.2 28.8 38.4 57.6 76.8 115.2 230.4 kBaud
//static const U32_T BaudrateTable[]={104, 69, 52, 35, 26, 17, 13, 8, 4};  //Baud rate values for 16MHz
//static const U32_T BaudrateTable[]={208, 139, 104, 69, 52, 34, 26, 17, 8};  //Baud rate values for 32MHz
static const U32_T BaudrateTable[]={260, 173, 130, 87, 65, 43, 33, 22, 11};  //!< Baud rate values for 40MHz

static volatile char UART1RxBuffer[UART_BUFFER_SIZE];    //!< Receive buffer
static volatile char UART1TxBuffer[UART_BUFFER_SIZE];    //!< Transmit buffer
static volatile int UART1RxReadPtr;                      //!< Receive buffer read index
static volatile int UART1RxWritePtr;                     //!< Receive buffer write index
static volatile int UART1TxReadPtr;                      //!< Transmit buffer read index
static volatile int UART1TxWritePtr;                     //!< Receive buffer write index
volatile U8_T UART1TimeoutFlag;                          //!< Timeout flag (gets set in the system timer interrupt)
volatile U32_T UART1TimeoutTimer;                        //!< Timeout timer (gets deceremented in the system timer interrupt)
static volatile U32_T UART1TransmitDelay;                //!< Delay between receiving and sending
volatile U32_T UART1TransmitDelayTimer;                  //!< Timer for delay between receiving and sending (gets decremented in the system timer interrupt)


/******************************************************//**
  \fn CSP_USART1Handler(void)
  \brief UART1 interrupt handler

  Interrupt handler function for the RS485 interface. It
  handles transmit buffer full and receive buffer empty
  interrupts.
**********************************************************/
void CSP_USART1Handler(void)
{
  U32_T IrqFlags;
  int i;

  //See what caused the interrupt. Looks a little bit strange,
  //but this way it works (like it is done in the Samsung example
  //code).
  IrqFlags=USART1->SR & USART1->IMSCR;

  //Receive interrupt
  if(IrqFlags & USART_RXRDY)
  {
    //Ignore RS485 echo (which occurs when RS485 is set to
    //send mode).
    if(IS_RS485_SENDING())
    {
      i=USART1->RHR;
    }
    else
    {
      //Copy received character into the receive FIFO
      i=UART1RxWritePtr+1;
      if(i==UART_BUFFER_SIZE) i=0;

      if(i!=UART1RxReadPtr)
      {
        UART1RxBuffer[UART1RxWritePtr]=USART1->RHR;
        UART1RxWritePtr=i;
      }

      //Empfangs-Timeout auf Startwert setzen
      UART1TimeoutTimer=UART_TIMEOUT_VALUE;

      //Set transmit delay time to its start value
      UART1TransmitDelayTimer=UART1TransmitDelay;
    }
  }

  //Transmitter ready interrupt
  if(IrqFlags & USART_TXRDY)
  {
    //Start sending when transmit delay time has elapsed
    if(UART1TransmitDelayTimer==0)
    {
      //Send when there is at least one character in the FIFO
      if(UART1TxWritePtr!=UART1TxReadPtr)
      {
        //Set RS485 to send mode
        SET_RS485_SEND_MODE();

        //put next character into the transmit register
        USART1->THR=UART1TxBuffer[UART1TxReadPtr++];
        if(UART1TxReadPtr==UART_BUFFER_SIZE) UART1TxReadPtr=0;
      }
      else
      {
        //Switch off the transmit interrupt and switch on the transmitter empty
        //interrupt when there are no more characters to send.
        //in the transmit FIFO.
        USART1->IMSCR=USART_RXRDY|USART_TXEMPTY;
      }
    }
  }

  //Transmitter empty interrupt
  if(IrqFlags & USART_TXEMPTY)
  {
    //The very last bit has been sent, so switch RS485 back to receive
    //mode and turn off transmitter empty interrupt.
    SET_RS485_RECV_MODE();
    USART1->IMSCR=USART_RXRDY;
  }
}


/********************************************************//**
  \fn InitRS485(U8_T Baudrate)
  \brief Initalize RS485 interface
  \param Baudrate  baud rate code (0..8)

  This function initializes the RS485 interface. The baud
  rate codes are the same as with TMCL.
************************************************************/
void InitRS485(U8_T Baudrate)
{
  NVIC_TypeDef NVICInitStruct;

  //Intialize the FIFOs
  UART1RxReadPtr=0;
  UART1RxWritePtr=0;
  UART1TxReadPtr=0;
  UART1RxWritePtr=0;

  //Configure Pins P1.03 and P1.04 as USART1 pins
  CSP_IOFunctionConfigure(GROUP1, IO_Port4, IOCONF_F1 );
  CSP_IOFunctionConfigure(GROUP1, IO_Port3, IOCONF_F1 );
  CSP_IOPullupEnable(GROUP1, IO_Port3);  //use pull-up resistor on the RX line

  //Select RS485 receive mode
  SET_RS485_RECV_MODE();

  //Configure USART1
  USART1->CEDR = USART_CLKEN;    //UART1 Clock enable
  USART1->SRR = USART_SWRST;     // software reset
  USART1->BRGR = BaudrateTable[Baudrate];  //baud rate divider
  USART1->MR = USART_CHRL_8|USART_PAR_NO|USART_NBSTOP_1;  //8N1
  USART1->CR= USART_RXEN|USART_TXEN;  //receiver enable, transmitter enable
  USART1->IMSCR=USART_RXRDY;  //receive interrupt enable

  //Configure USART1 interrupt in the NVIC
  NVICInitStruct.NVIC_IRQChannel=15;
  NVICInitStruct.NVIC_IRQChannelPreemptionPriority=3;
  NVICInitStruct.NVIC_IRQChannelSubPriority=0;
  NVICInitStruct.NVIC_IRQChannelCmd=ENABLE;
  CSP_NVICConfigInterrupt(&NVICInitStruct);
}


/****************************************************//**
  \fn WriteRS485(U8_T Byte)
  \brief Write to the RS485 interface
  \param Byte  Byte to be written

  This function puts a byte into the RS485 transmit
  buffer and starts sending if not already done.
********************************************************/
void WriteRS485(U8_T Byte)
{
  int i;

  //Put the character into the transmit FIFO
  i=UART1TxWritePtr+1;
  if(i==UART_BUFFER_SIZE) i=0;

  if(i!=UART1TxReadPtr)
  {
    UART1TxBuffer[UART1TxWritePtr]=Byte;
    UART1TxWritePtr=i;

    //Turn on transmit and receive interrupt
    USART1->IMSCR=USART_TXRDY|USART_RXRDY;
  }
}


/****************************************************//**
  \fn ReadRS485(U8_T *Byte)
  \brief Read from the RS485 interface
  \param Byte  Pointer to variable for result
  \return TRUE if a byte could be read\n
          FALSE if the receive buffer was empty

  This function tries to read a byte from the RS485 receive
  buffer.
********************************************************/
U8_T ReadRS485(U8_T *Byte)
{
  //Is there any character in the receive FIFO?
  if(UART1RxReadPtr==UART1RxWritePtr) return FALSE;

  //Take a character from the receive FIFO
  *Byte=UART1RxBuffer[UART1RxReadPtr++];
  if(UART1RxReadPtr==UART_BUFFER_SIZE)  UART1RxReadPtr=0;

  return TRUE;
}


/****************************************************//**
  \fn SetUARTTransmitDelay(U32_T Delay)
  \brief Set RS485 transmit delay
  \param Delay  Delay in ms

  This function sets the delay between receiving the last
  byte and sending the first byte. This can be necessary
  with some RS485 interfaces.
********************************************************/
void SetUARTTransmitDelay(U32_T Delay)
{
  UART1TransmitDelay=Delay;
}


/*******************************************************************************//**
  \fn CheckUARTTimeout(void)
  \brief Check and reset RS485 timeout flag
  \return TRUE if there has been a timeout (>5ms after last received byte)\n
          FALSE if there has not been a timeout since the last call of this function

  This function checks the timeout flag and then resets it.
***********************************************************************************/
UINT CheckUARTTimeout(void)
{
  if(UART1TimeoutFlag)
  {
    UART1TimeoutFlag=FALSE;
    return TRUE;
  }
  else return FALSE;
}
