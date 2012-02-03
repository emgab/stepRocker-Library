/*
  Contributed by Trinamic / OK
*/


extern unsigned long _etext;
extern unsigned long _sidata;		/* start address for the initialization values
                                   of the .data section. defined in linker script */
extern unsigned long _sdata;		/* start address for the .data section. defined
                                   in linker script */
extern unsigned long _edata;		/* end address for the .data section. defined in
                                   linker script */

extern unsigned long _sbss;			/* start address for the .bss section. defined
                                   in linker script */
extern unsigned long _ebss;			/* end address for the .bss section. defined in
                                   linker script */

extern void _estack;		/* init value for the stack pointer. defined in linker script */



/* function prototypes -------------------------------------------------------*/
void NMIHandler(void);
void HardFaultHandler(void);
void SVCHandler(void);
void PendSVCHandler(void);
void CSP_SysTickHandler(void);
void CSP_WDTHandler(void);
void CSP_FRTHandler(void);
void CSP_CMHandler(void); 
void CSP_IFCHandler(void);
void CSP_DMAHandler(void);
void CSP_ADCHandler(void);
void CSP_WSI0Handler(void);
void CSP_TC0Handler(void); 
void CSP_IMCHandler(void); 
void CSP_ENCHandler(void); 
void CSP_TC1Handler(void); 
void CSP_USART0Handler(void);
void CSP_PWM0Handler(void);
void CSP_SPI0Handler(void);
void CSP_I2C0Handler(void);
void CSP_USART1Handler(void);
void CSP_TC2Handler(void);
void CSP_USART2Handler(void);
void CSP_TC3Handler(void);
void CSP_SPI1Handler(void);
void CSP_I2C1Handler(void);
void CSP_PWM1Handler(void);
void CSP_TC4Handler(void);
void CSP_TC5Handler(void);
void CSP_TC6Handler(void);
void CSP_TC7Handler(void);
void CSP_USBHandler(void);
void CSP_CANHandler(void);
void CSP_STTHandler(void);
void CSP_GPIO0Handler(void);
void CSP_GPIO1Handler(void);
void CSP_WSIxHandler(void);

void Reset_Handler(void) __attribute__((__interrupt__));
extern int main(void);


/*******************************************************************************
*
* The minimal vector table for a Cortex M0.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
*******************************************************************************/


__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
  &_estack,            // The initial stack pointer    OK: __initial_sp
  Reset_Handler,             // The reset handler
  NMIHandler,
  HardFaultHandler,
  0,                     //MPU fault handler (Cortex-M3 only)
  0,                     //Bus fault handler (Cortex-M3 only)
  0,                     //Usage fault handler (Cortex-M3 only) 
  0, 0, 0, 0,            // reserved
  SVCHandler,
  0,                     //Debug handler (Cortex-M3 only)
  0,                     // reserverd
  PendSVCHandler,
  CSP_SysTickHandler,
  CSP_WDTHandler,			     //  0) addr 0x40 Watchdog timer             
  CSP_FRTHandler,          //  1) addr 0x44 Free running timer     
  CSP_CMHandler,           //  2) addr 0x48 Clock Manager          
  CSP_IFCHandler,          //  3) addr 0x4C Internal Flash         
  CSP_DMAHandler,          //  4) addr 0x50 DMA                    
  CSP_ADCHandler,          //  5) addr 0x54 ADC                    
  CSP_WSI0Handler,         //  6) addr 0x58 WakeupSource0 interrupt
  CSP_TC0Handler,          //  7) addr 0x5C Timer coutner 0        
  CSP_IMCHandler,          //  8) addr 0x60 IMC                    
  CSP_ENCHandler,          //  9) addr 0x64 ENC                    
  CSP_TC1Handler,          // 10) addr 0x68 Timer coutner 1        
  CSP_USART0Handler,       // 11) addr 0x6C USART0                 
  CSP_PWM0Handler,         // 12) addr 0x70 PWM0                   
  CSP_SPI0Handler,         // 13) addr 0x74 SPI0                   
  CSP_I2C0Handler,         // 14) addr 0x78 I2C0                   
  CSP_USART1Handler,       // 15) addr 0x7C USART1                 
  CSP_TC2Handler,          // 16) addr 0x80 Timer coutner 2        
  CSP_USART2Handler,       // 17) addr 0x84 USART2                 
  CSP_TC3Handler,          // 18) addr 0x88 Timer coutner 3        
  CSP_SPI1Handler,         // 19) addr 0x8C SPI1                   
  CSP_I2C1Handler,         // 20) addr 0x90 I2C1                   
  CSP_PWM1Handler,         // 21) addr 0x94 PWM1                   
  CSP_TC4Handler,          // 22) addr 0x98 Timer coutner 4        
  CSP_TC5Handler,          // 23) addr 0x9C Timer coutner 5        
  CSP_TC6Handler,          // 24) addr 0xA0 Timer coutner 6        
  CSP_TC7Handler,          // 25) addr 0xA4 Timer coutner 7        
  CSP_USBHandler,          // 26) addr 0xA8 USB                    
  CSP_CANHandler,          // 27) addr 0xAC CAN                    
  CSP_STTHandler,          // 28) addr 0xB0 Stamp timer            
  CSP_GPIO0Handler,        // 29) addr 0xB4 GPIO0                  
  CSP_GPIO1Handler,        // 30) addr 0xB8 GPIO1                  
  CSP_WSIxHandler,         // 31) addr 0xBC WakeupSourceX interrupt
  0xffffffff,
  0xffffffff
};

/*******************************************************************************
* Function Name  : Reset_Handler
* Description    : This is the code that gets called when the processor first
*                  starts execution following a reset event. Only the absolutely
*                  necessary set is performed, after which the application
*                  supplied main() routine is called. 
* Input          :
* Output         :
* Return         :
*******************************************************************************/
void Reset_Handler(void)
{
    unsigned long *pulSrc, *pulDest;

    //
    // Copy the data segment initializers from flash to SRAM.
    //
    pulSrc = &_sidata;
    for(pulDest = &_sdata; pulDest < &_edata; )
    {
        *(pulDest++) = *(pulSrc++);
    }

    //
    // Zero fill the bss segment.
    //
    for(pulDest = &_sbss; pulDest < &_ebss; )
    {
        *(pulDest++) = 0;
    }

    //
    // Call the application's entry point.
    //
    main();
}


/*******************************************************************************
  Empty interrupt handler functions. They are declared as weak so that they
  can be overridden by own interrupt handler functions.
*******************************************************************************/
void NMIHandler(void)
{
}

void HardFaultHandler(void)
{
	for(;;);
}

void SVCHandler(void)
{
}

void PendSVCHandler(void)
{
}

void __attribute__ ((weak)) CSP_SysTickHandler(void)
{
}

void __attribute__ ((weak)) CSP_WDTHandler(void)
{
}

void __attribute__ ((weak)) CSP_FRTHandler(void)
{
}

void __attribute__ ((weak)) CSP_CMHandler(void)
{
}

void __attribute__ ((weak)) CSP_IFCHandler(void)
{
}

void __attribute__ ((weak)) CSP_DMAHandler(void)
{
}

void __attribute__ ((weak)) CSP_ADCHandler(void)
{
}

void __attribute__ ((weak)) CSP_WSI0Handler(void)
{
}

void __attribute__ ((weak)) CSP_TC0Handler(void)
{
}

void __attribute__ ((weak)) CSP_IMCHandler(void)
{
}

void __attribute__ ((weak)) CSP_ENCHandler(void)
{
}

void __attribute__ ((weak)) CSP_TC1Handler(void)
{
}

void __attribute__ ((weak)) CSP_USART0Handler(void)
{
}

void __attribute__ ((weak)) CSP_PWM0Handler(void)
{
}

void __attribute__ ((weak)) CSP_SPI0Handler(void)
{
}

void __attribute__ ((weak)) CSP_I2C0Handler(void)
{
}

void __attribute__ ((weak)) CSP_USART1Handler(void)
{
}

void __attribute__ ((weak)) CSP_TC2Handler(void)
{
}

void __attribute__ ((weak)) CSP_USART2Handler(void)
{
}

void __attribute__ ((weak)) CSP_TC3Handler(void)
{
}

void __attribute__ ((weak)) CSP_SPI1Handler(void)
{
}

void __attribute__ ((weak)) CSP_I2C1Handler(void)
{
}

void __attribute__ ((weak)) CSP_PWM1Handler(void)
{
}

void __attribute__ ((weak)) CSP_TC4Handler(void)
{
}

void __attribute__ ((weak)) CSP_TC5Handler(void)
{
}

void __attribute__ ((weak)) CSP_TC6Handler(void)
{
}

void __attribute__ ((weak)) CSP_TC7Handler(void)
{
}

void __attribute__ ((weak)) CSP_USBHandler(void)
{
}

void __attribute__ ((weak)) CSP_CANHandler(void)
{
}

void __attribute__ ((weak)) CSP_STTHandler(void)
{
}

void __attribute__ ((weak)) CSP_GPIO0Handler(void)
{
}

void __attribute__ ((weak)) CSP_GPIO1Handler(void)
{
}

void __attribute__ ((weak)) CSP_WSIxHandler(void)
{
}
