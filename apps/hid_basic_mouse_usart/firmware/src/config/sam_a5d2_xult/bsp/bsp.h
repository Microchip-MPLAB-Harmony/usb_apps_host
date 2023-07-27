/*******************************************************************************
  Board Support Package Header File.

  Company:
    Microchip Technology Inc.

  File Name:
    bsp.h

  Summary:
    Board Support Package Header File 

  Description:
    This file contains constants, macros, type definitions and function
    declarations 
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef BSP_H
#define BSP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "device.h"

// *****************************************************************************
// *****************************************************************************
// Section: BSP Macros
// *****************************************************************************
// *****************************************************************************
#define sam_a5d2_xult
#define BSP_NAME             "sam_a5d2_xult"

/*PIOA base address */
#define PIOA_REGS   ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[0])))
/*PIOB base address */
#define PIOB_REGS   ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[1])))
/*PIOC base address */
#define PIOC_REGS   ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[2])))
/*PIOD base address */
#define PIOD_REGS   ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[3])))

/*** LED Macros for LED1 ***/
#define LED1_Toggle() do { PIOB_REGS->PIO_MSKR = (1UL<<5); (PIOB_REGS->PIO_ODSR ^= (1UL<<5)); } while (0)
#define LED1_Get() ((PIOB_REGS->PIO_PDSR >> 5) & 0x1)
#define LED1_On() (PIOB_REGS->PIO_CODR = (1UL<<5))
#define LED1_Off() (PIOB_REGS->PIO_SODR = (1UL<<5))
/*** LED Macros for LED_RED ***/
#define LED_RED_Toggle() do { PIOB_REGS->PIO_MSKR = (1UL<<6); (PIOB_REGS->PIO_ODSR ^= (1UL<<6)); } while (0)
#define LED_RED_Get() ((PIOB_REGS->PIO_PDSR >> 6) & 0x1)
#define LED_RED_On() (PIOB_REGS->PIO_CODR = (1UL<<6))
#define LED_RED_Off() (PIOB_REGS->PIO_SODR = (1UL<<6))
/*** LED Macros for LED_BLUE ***/
#define LED_BLUE_Toggle() do { PIOB_REGS->PIO_MSKR = (1UL<<0); (PIOB_REGS->PIO_ODSR ^= (1UL<<0)); } while (0)
#define LED_BLUE_Get() ((PIOB_REGS->PIO_PDSR >> 0) & 0x1)
#define LED_BLUE_On() (PIOB_REGS->PIO_CODR = (1UL<<0))
#define LED_BLUE_Off() (PIOB_REGS->PIO_SODR = (1UL<<0))
/*** SWITCH Macros for PB_USER ***/
#define PB_USER_Get() ((PIOB_REGS->PIO_PDSR >> 9) & 0x1)
#define PB_USER_STATE_PRESSED 0
#define PB_USER_STATE_RELEASED 1
/*** VBUS Macros for VBUS_AH ***/
#define VBUS_AH_PowerEnable() (PIOB_REGS->PIO_SODR = (1UL<<10))
#define VBUS_AH_PowerDisable() (PIOB_REGS->PIO_CODR = (1UL<<10))




// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void BSP_Initialize(void)

  Summary:
    Performs the necessary actions to initialize a board

  Description:
    This function initializes the LED and Switch ports on the board.  This
    function must be called by the user before using any APIs present on this
    BSP.

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Example:
    <code>
    BSP_Initialize();
    </code>

  Remarks:
    None
*/

void BSP_Initialize(void);

#endif // BSP_H

/*******************************************************************************
 End of File
*/
