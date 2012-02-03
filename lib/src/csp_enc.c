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
* @file name	csp_enc.c
* @description Definitions, Macros and function declarations for ENC
*
* @history	History type - NEW/MODify/ADD/DELete
*  -------------------------------------------------------------------
* |ver type when         who                 what
* |---+---+------------+-------------------+--------------------------
* |0.0 NEW 2009.12.01.   MCU Solution Part	 Creation
*  -------------------------------------------------------------------
* @see	RealView MDK-ARM Version 4.01
*/

/*******************************************************************************
*******************************  I N C L U D E S  ******************************
*******************************************************************************/
#include "csp.h"
/*******************************************************************************
********************************  F U N C T I O N S  ***************************
*******************************************************************************/
volatile static U8_T direction;
/**
********************************************************************************
* @brief	Enable encoder block and clock setting for enc block
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @param 	enc_clksel [in] Clock selection of ENC block
* @param 	filter_clk [in] Filter Clock selection
* @todo		None
********************************************************************************
*/
void CSP_ENCEnable(CSP_ENC_T *const enc, U8_T encclksel, U8_T fileterclk)
{
	CSP_ENC_SET_CR0( enc, ENC_ENCCLKSEL(encclksel)\
						  | ENC_ENCFILTER(fileterclk)\
						  | ENC_ENCEN);
}

/**
********************************************************************************
* @brief	Disable encoder block
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCDisable(CSP_ENC_T *const enc)
{
	CSP_ENC_SET_CR0(enc,CSP_ENC_GET_CR0(enc)&(~ENC_ENCEN));
}
/**
********************************************************************************
* @brief	Enable Phase A capture
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCEnablePA(CSP_ENC_T *const enc)
{
	/* Enable Phase A Captureb */
	CSP_ENC_SET_CR1(enc, CSP_ENC_GET_CR1(enc) | ENC_PAEN);
}
/**
********************************************************************************
* @brief	Disable Phase A capture
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCDisablePA(CSP_ENC_T *const enc)
{
	/* Disable Phase A Capture */
	CSP_ENC_SET_CR1(enc, CSP_ENC_GET_CR1(enc) & ~ENC_PAEN);
}
/**
********************************************************************************
* @brief		Enable Phase B capture
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCEnablePB(CSP_ENC_T *const enc)
{
	/* Enable Phase B Capture */
	CSP_ENC_SET_CR1(enc, CSP_ENC_GET_CR1(enc) | ENC_PBEN);
}
/**
********************************************************************************
* @brief	Disable Phase B capture
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCDisablePB(CSP_ENC_T *const enc)
{
	/* Disable Phase B Capture */
	CSP_ENC_SET_CR1(enc, CSP_ENC_GET_CR1(enc) & (~ ENC_PBEN));
}
/**
********************************************************************************
* @brief	Clear Position Counter
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCClearPCounter(CSP_ENC_T *const enc)
{
	/* Clear Position Counter */
	CSP_ENC_SET_CR0(enc, CSP_ENC_GET_CR0(enc) | ENC_PCRCL);
}
/**
********************************************************************************
* @brief		Clear Speed Counter
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCClearSCounter(CSP_ENC_T *const enc)
{
	/* Clear Speed Counter */
	CSP_ENC_SET_CR0(enc, CSP_ENC_GET_CR0(enc) | ENC_SPCRCL);
}
/**
********************************************************************************
* @brief	Clear Phase A Counter
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCClearPACounter(CSP_ENC_T *const enc)
{
	/* Clear Phase A Counter */
	CSP_ENC_SET_CR1(enc, CSP_ENC_GET_CR1(enc) | ENC_PACCRCL);
}
/**
********************************************************************************
* @brief		Clear Phase B Counter
* @return	None
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
void CSP_ENCClearPBCounter(CSP_ENC_T *const enc)
{
	/* Clear Phase B Counter */
	CSP_ENC_SET_CR1(enc, CSP_ENC_GET_CR1(enc) | ENC_PBCCRCL);
}
/**
********************************************************************************
* @brief	Check the direction of encoder
* @return	direction
* @param	enc	[in] Pointer to ENC structure.
* @todo		nothing
********************************************************************************
*/
U8_T CSP_ENCDirection(CSP_ENC_T *const enc)
{
	direction=(CSP_ENC_GET_SR(enc)& ENC_DIRECTION);
	return direction;
}
