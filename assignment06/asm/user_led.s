/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    LDR R2, =GPIOA_BASE // Load GPIO port A base address into R2
    // Load value at memory address GPIOA_BASE+GPIOA_ODR into R3.
    LDR R3,[R2, #GPIOA_ODR]

    CMP R0,#1  // Compare R0 to 1.
    ITE EQ     // The next instruction executes if Z is set (EQ), the one after
               // that executes if Z is cleared(NE).
    
    // Turn on LED1 -- set bit[5] = 1
    // R2 |= GPIOA_BIT_5
    ORREQ R3,R3,#GPIOA_BIT_5  // If EQ

    // Turn off LED1 -- set bit[5] = 0
    // R2 &= ~GPIOA_BIT_5
    BICNE R3,R3,#GPIOA_BIT_5  // If not EQ (NE)
    
    // Store value in R3 to memory address GPIOA_BASE+GPIOA_ODR.
    STR R3,[R2,#GPIOA_ODR]
    
    PUSH {LR}  // Save the return address so we can call delay.
    // We are done using R0 for its initial purpose (as the state of the LED1
    // peripheral) so we can overwrite it now.
    MOV R0,R1  // R0 = R1, i.e., R0 now has the duration to delay for.
    BL delay   // call delay function to hold the current state of the LED.
    
    POP {LR}   // Restore LR (the return address).
    BX LR      // Return to the address where this function was called.
    
    // Note: we don't care about setting R0(which would hold the return value)
    // because this function does not return anything.
    
    END
