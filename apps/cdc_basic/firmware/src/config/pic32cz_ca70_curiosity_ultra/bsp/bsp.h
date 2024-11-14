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
#define pic32cz_ca70_curiosity_ultra
#define BSP_NAME             "pic32cz_ca70_curiosity_ultra"

/*** LED Macros for LED ***/
#define LED_Toggle() (PIOD_REGS->PIO_ODSR ^= (1UL<<23))
#define LED_On() (PIOD_REGS->PIO_CODR = (1UL<<23))
#define LED_Off() (PIOD_REGS->PIO_SODR = (1UL<<23))
/*** LED Macros for LED1 ***/
#define LED1_Toggle() (PIOD_REGS->PIO_ODSR ^= (1UL<<29))
#define LED1_On() (PIOD_REGS->PIO_CODR = (1UL<<29))
#define LED1_Off() (PIOD_REGS->PIO_SODR = (1UL<<29))
/*** SWITCH Macros for SW1 ***/
#define SW1_Get() ((PIOA_REGS->PIO_PDSR >> 9) & 0x1U)
#define SW1_STATE_PRESSED 0
#define SW1_STATE_RELEASED 1
/*** SWITCH Macros for SWITCH ***/
#define SWITCH_Get() ((PIOA_REGS->PIO_PDSR >> 1) & 0x1U)
#define SWITCH_STATE_PRESSED 0
#define SWITCH_STATE_RELEASED 1
/*** VBUS Macros for VBUS_AH ***/
#define VBUS_AH_PowerEnable() (PIOC_REGS->PIO_SODR = (1UL<<25))
#define VBUS_AH_PowerDisable() (PIOC_REGS->PIO_CODR = (1UL<<25))




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
