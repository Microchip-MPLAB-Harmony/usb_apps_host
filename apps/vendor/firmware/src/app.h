/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "usb/usb_host_generic.h"
#include "config/sam_e54_xpro/system/time/sys_time.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

#define APP_SWITCH_DEBOUNCE_TIME_MS 50
    
// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_STATE_BUS_ENABLE = 0,
    /* TODO: Define states used by the application state machine. */
    APP_STATE_WAIT_FOR_BUS_ENABLE,
    APP_STATE_WAIT_FOR_ATTACH,
    APP_STATE_CHECK_SWITCH_STATE

} APP_STATES;


typedef enum
{
    APP_SWITCH_STATE_CHECK_SWITCH_PRESS = 0,
    APP_SWITCH_STATE_WAIT_FOR_DEBOUNCE,
    APP_SWITCH_STATE_WAIT_FOR_RELEASE
    
} APP_SWITCH_STATE;

typedef enum
{
    APP_VENDOR_DRIVER_STATE_WAIT_FOR_ATTACH = 0,
    APP_VENDOR_DRIVER_STATE_SET_CONFIGURATION,
    APP_VENDOR_DRIVER_STATE_WAIT_FOR_SET_CONFIGURATION,
    APP_VENDOR_DRIVER_STATE_WAIT_FOR_INTERFACE_READY,
    APP_VENDOR_DRIVER_STATE_RUNNING,
    APP_VENDOR_DRIVER_STATE_ERROR,
    APP_VENDOR_DRIVER_STATE_ERROR_HOLDING
            

} APP_VENDOR_DRIVER_STATE;

typedef enum
{
    APP_VENDOR_DEVICE_STATE_DETACHED = 0,
    APP_VENDOR_DEVICE_STATE_ATTACHED,
    APP_VENDOR_DEVICE_STATE_READY
            
} APP_VENDOR_DEVICE_STATE;

typedef enum
{
    APP_DEVICE_SWITCH_STATUS_STATE_GET = 0,
    APP_DEVICE_SWITCH_STATUS_STATE_WAIT_GET

} APP_DEVICE_SWITCH_STATUS_STATE;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_STATES state;
    APP_SWITCH_STATE switchState;
    APP_DEVICE_SWITCH_STATUS_STATE switchStatusTaskState;
    SYS_TIME_HANDLE debounceTimer;
    uint8_t appBuffer;
    uint8_t oldSwitchStatus;
    bool switchIsPressed;

    /* TODO: Define any additional data used by the application. */

} APP_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks( void );

/********************************************
 * Application Vendor Device Driver functions
 *********************************************/

void APP_VENDOR_DRIVER_Initialize(void);

void APP_VENDOR_DRIVER_Tasks(void);

void APP_VENDOR_DRIVER_DeviceAssign
(
    USB_HOST_DEVICE_CLIENT_HANDLE deviceHandle,
    USB_HOST_DEVICE_OBJ_HANDLE deviceObjHandle,
    USB_DEVICE_DESCRIPTOR * deviceDescriptor
);

void APP_VENDOR_DRIVER_DeviceRelease (USB_HOST_DEVICE_CLIENT_HANDLE deviceHandle);

USB_HOST_DEVICE_EVENT_RESPONSE APP_VENDOR_DRIVER_DeviceEventHandler
(
    USB_HOST_DEVICE_CLIENT_HANDLE deviceHandle,
    USB_HOST_DEVICE_EVENT event,
    void * eventData,
    uintptr_t context
);

void APP_VENDOR_DRIVER_InterfaceAssign
(
    USB_HOST_DEVICE_INTERFACE_HANDLE * interfaces,
    USB_HOST_DEVICE_OBJ_HANDLE deviceObjHandle,
    size_t nInterfaces,
    uint8_t * descriptor
);

void APP_VENDOR_DRIVER_InterfaceRelease (USB_HOST_DEVICE_INTERFACE_HANDLE interfaceHandle);

USB_HOST_DEVICE_INTERFACE_EVENT_RESPONSE APP_VENDOR_DRIVER_InterfaceEventHandler
(
    USB_HOST_DEVICE_INTERFACE_HANDLE interfaceHandle,
    USB_HOST_DEVICE_INTERFACE_EVENT event,
    void * eventData,
    uintptr_t context
);

bool APP_VENDOR_DRIVER_LedToggleCommandInProgress(void);
bool APP_VENDOR_DRIVER_DeviceIsAvailable(void);
bool APP_VENDOR_DRIVER_ToggleLED(void);
bool APP_VENDOR_DRIVER_DeviceSwitchStatusGet(uint8_t * appBuffer);
bool APP_VENDOR_DRIVER_DeviceSwitchStatusGetInProgress(void);

typedef struct 
{
    uint8_t buffer[512];
    USB_HOST_DEVICE_CLIENT_HANDLE deviceHandle;
    USB_HOST_DEVICE_OBJ_HANDLE deviceObjHandle;
    USB_HOST_DEVICE_INTERFACE_HANDLE interfaceHandle;
    USB_HOST_PIPE_HANDLE bulkInPipeHandle;
    USB_HOST_PIPE_HANDLE bulkOutPipeHandle;
    USB_HOST_PIPE_HANDLE controlPipeHandle;
    APP_VENDOR_DRIVER_STATE driverState;
    APP_VENDOR_DEVICE_STATE deviceState;
    bool requestDone;
    bool interfacesProcessed;
    uint8_t ledToggleCommand;
    uint8_t switchGetCommand;
    bool switchGetCommandInProgress;
    bool switchGetCommmandErrorHadOccurred;
    bool ledToggleCommandInProgress;
    USB_HOST_RESULT result;
    bool ledToggleCommandErrorHasOccurred;
    uint8_t * appBuffer;
  
} APP_VENDOR_DRIVER_OBJ;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */

/*******************************************************************************
 End of File
 */

