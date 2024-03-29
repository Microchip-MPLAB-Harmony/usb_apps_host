/********************************************************************************
  USB HOST HID Mouse Driver Interface Definition

  Company:
    Microchip Technology Inc.

  File Name:
    usb_host_hid_mouse.h

  Summary:
    USB Host HID Mouse Driver Definition Header

  Description:
    This header file contains the function prototypes and definitions of the
    data types and constants that make up the interface between HID Mouse driver
    and top level application.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
#ifndef USB_HOST_HID_MOUSE_H_
#define USB_HOST_HID_MOUSE_H_


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "usb/usb_host_hid.h"
#include "usb/src/usb_external_dependencies.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END  

// *****************************************************************************
// *****************************************************************************
// Section: USB HID Mouse Driver Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* USB Host HID Mouse Driver Result Minimum Constant

  Summary:
    USB Host HID mouse driver result minimum constant.

  Description:
    This constant identifies the minimum value of the USB Host HID mouse driver 
    and is used in the USB_HOST_HID_MOUSE_RESULT enumeration.

  Remarks:
    None.
*/
#define USB_HOST_HID_MOUSE_RESULT_MIN -50


// *****************************************************************************
/* USB HOST HID Mouse Driver Events

  Summary:
    Defines the possible USB HOST HID mouse driver events.

  Description:
    This enumeration lists the possible mouse events that the mouse driver can
    provide to the application. Some of these events have event data associated 
    with them.
 */

typedef enum
{
    /* Mouse has been attached */
    USB_HOST_HID_MOUSE_EVENT_ATTACH = 0,
    /* Mouse has been detached */
    USB_HOST_HID_MOUSE_EVENT_DETACH,
    /* Mouse IN Report data available */
    USB_HOST_HID_MOUSE_EVENT_REPORT_RECEIVED

} USB_HOST_HID_MOUSE_EVENT;


// *****************************************************************************
/* USB Host HID MOUSE Result

  Summary:
    USB Host HID mouse driver results.

  Description:
    This enumeration defines the possible returns values of USB Host HID mouse
    driver API. A function may only return some of the values in this 
    enumeration. Refer to function description for details on which values will
    be returned.

  Remarks:
    None.
*/

typedef enum
{    
    /* An unknown failure occurred */
    USB_HOST_HID_MOUSE_RESULT_FAILURE = USB_HOST_HID_MOUSE_RESULT_MIN,
    
    /* Invalid or NULL parameter passed */
    USB_HOST_HID_MOUSE_RESULT_INVALID_PARAMETER,
    
    /* Indicates that the operation succeeded or the request was accepted and
       will be processed. */
    USB_HOST_HID_MOUSE_RESULT_SUCCESS = 0

} USB_HOST_HID_MOUSE_RESULT;


// *****************************************************************************
/* USB HOST HID Mouse Driver Instance Handle

  Summary:
    USB HOST HID mouse driver instance handle.

  Description:
    This defines a USB Host HID mouse driver handle.

  Remarks:
    None.
*/

typedef uintptr_t USB_HOST_HID_MOUSE_HANDLE;

#define USB_HOST_HID_MOUSE_HANDLE_INVALID ((USB_HOST_HID_MOUSE_HANDLE)(-1))


// *****************************************************************************
/* USB Host HID Mouse Data Object

  Summary:
    Defines the USB Host HID mouse data object.

  Description:
    This structure defines the USB Host HID mouse data object.

  Remarks:
    None.
*/

typedef struct
{
    /* Button state for the buttons. USB_HOST_HID_MOUSE_BUTTONS_NUMBER is
       system configurable option. The actual number of buttons in the mouse
       needs to be <= USB_HOST_HID_MOUSE_BUTTONS_NUMBER
     */
    USB_HID_BUTTON_STATE buttonState[USB_HOST_HID_MOUSE_BUTTONS_NUMBER];
    USB_HID_BUTTON_ID buttonID [USB_HOST_HID_MOUSE_BUTTONS_NUMBER];
    /* X - Coordinate displacement */
    int16_t xMovement; /* Applicable for 2D Mouse */
    /* Y - Coordinate displacement */
    int16_t yMovement; /* Applicable for 2D Mouse */
    /* Z - Coordinate displacement */
    int16_t zMovement;/* Applicable only for 3D Mouse */
    
} USB_HOST_HID_MOUSE_DATA;


// *****************************************************************************
/* USB HOST Mouse Driver Event Handler Function Pointer Type.

  Summary:
    USB HOST mouse driver event handler function pointer type.

  Description:
    This defines the USB HOST HID mouse driver event handler function
    pointer type. Application must register a function of this type to
    receive HID mouse events. Registration should happen before USB BUS is
    enabled by the application.

*/
typedef void (*USB_HOST_HID_MOUSE_EVENT_HANDLER)
(
    /* Unique Handle passed to the caller. This will be unique
       for each Mouse interface attached
     */
    USB_HOST_HID_MOUSE_HANDLE handle,
    /* Associated event type */
    USB_HOST_HID_MOUSE_EVENT event,
    /* Associated event data. For USB_HOST_HID_MOUSE_EVENT_ATTACH
       and USB_HOST_HID_MOUSE_EVENT_DETACH this will be NULL.
       For USB_HOST_HID_MOUSE_EVENT_REPORT_RECEIVED event, this
       will be USB_HOST_HID_MOUSE_DATA data type
     */
    void *pData
);


// *****************************************************************************
// *****************************************************************************
// Section: MOUSE Driver Function Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

void USB_HOST_HID_MOUSE_Task(USB_HOST_HID_OBJ_HANDLE handle);
void USB_HOST_HID_MOUSE_EventHandler
(
    USB_HOST_HID_OBJ_HANDLE handle,
    USB_HOST_HID_EVENT event,
    void * eventData
);


// *****************************************************************************
/* Function:
    USB_HOST_HID_MOUSE_RESULT USB_HOST_HID_MOUSE_EventHandlerSet
    (
        USB_HOST_HID_MOUSE_EVENT_HANDLER appMouseEventHandler
    );

  Summary:
    This function registers application callback function with the mouse driver.

  Description:
    This function registers application callback function with the mouse driver.
    Any subsequent mouse events is passed to the application by calling the
    registered application function.
    The function prototype should be of the USB_HOST_HID_MOUSE_EVENT_HANDLER type.
    
  Precondition:
    This function should be called before the USB bus is enabled.

  Parameters:
    appMouseEventHandler  - Function pointer to the application function.

  Returns:
    Returns data structure of USB_HOST_HID_MOUSE_RESULT type.
      USB_HOST_HID_MOUSE_RESULT_INVALID_PARAMETER: Invalid Parameter
      USB_HOST_HID_MOUSE_RESULT_FAILURE: On failure
      USB_HOST_HID_MOUSE_RESULT_SUCCESS: On success

  Remarks:
    This function should be called before the USB bus is enabled.
*/
USB_HOST_HID_MOUSE_RESULT USB_HOST_HID_MOUSE_EventHandlerSet
(
    USB_HOST_HID_MOUSE_EVENT_HANDLER appMouseEventHandler
);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}

#endif
//DOM-IGNORE-END

#endif
