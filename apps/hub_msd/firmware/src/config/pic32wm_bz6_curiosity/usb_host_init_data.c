 /*******************************************************************************
  USB Host Initialization File

  File Name:
    usb_host_init_data.c

  Summary:
    This file contains source code necessary to initialize USB Host Stack.

  Description:
    This file contains source code necessary to initialize USB Host Stack.
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
#include "configuration.h"
#include "definitions.h" 

/* MISRA C-2012 Rule 11.8 deviated:2 and 20.7 devaited:4 deviated below. Deviation record ID -  
    H3_USB_MISRAC_2012_R_11_8_DR_1, H3_USB_MISRAC_2012_R_20_7_DR_1 */

static const USB_HOST_TPL_ENTRY USBTPList[2] = 
{
    TPL_INTERFACE_CLASS_SUBCLASS_PROTOCOL
    (
        USB_MSD_CLASS_CODE, 
        USB_MSD_SUBCLASS_CODE_SCSI_TRANSPARENT_COMMAND_SET, 
        USB_MSD_PROTOCOL, 
        NULL,  
        USB_HOST_MSD_INTERFACE
    ),

    TPL_INTERFACE_CLASS_SUBCLASS(0x09, 0x00, NULL,  USB_HOST_HUB_INTERFACE),


};

static const USB_HOST_HCD hcdTable = 
{
    /* Index of the USB Driver used by the Host Layer */
    .drvIndex = DRV_USBFS_INDEX_0,

    /* Pointer to the USB Driver Functions. */
    .hcdInterface = DRV_USBFS_HOST_INTERFACE,

};

const USB_HOST_INIT usbHostInitData = 
{
    .nTPLEntries = 2 ,
    .tplList = (USB_HOST_TPL_ENTRY *)USBTPList,
    .hostControllerDrivers = (USB_HOST_HCD *)&hcdTable    
};
/* MISRAC 2012 deviation block end */

// </editor-fold>
