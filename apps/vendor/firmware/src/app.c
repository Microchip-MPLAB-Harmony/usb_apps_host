/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "usb/usb_host.h"
#include "usb/usb_host_generic.h"
#include "bsp/bsp.h"
#include "system/time/sys_time.h"
#include "system/console/sys_console.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/
USB_HOST_EVENT_RESPONSE APP_USBHostEventHandler 
(
    USB_HOST_EVENT event, 
    void * eventData,
    uintptr_t context
)
{
    /* This function is called by the USB Host whenever a USB Host Layer event
     * has occurred. In this example we only handle the device unsupported event
     * */

    switch (event)
    {
        case USB_HOST_EVENT_DEVICE_UNSUPPORTED:
            
            /* The attached device is not supported for some reason */
            break;
            
        default:
            break;
                    
    }
    
    return(USB_HOST_EVENT_RESPONSE_NONE);
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/



// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_BUS_ENABLE;
    appData.switchState = APP_SWITCH_STATE_CHECK_SWITCH_PRESS;
    appData.switchStatusTaskState = APP_DEVICE_SWITCH_STATUS_STATE_GET;
    appData.switchIsPressed = false;
    appData.oldSwitchStatus = 0x1;
    
    /* This is a good place to initialize our driver*/
    APP_VENDOR_DRIVER_Initialize();

    SYS_CONSOLE_PRINT("APP: Initialization Done! \r\n");
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/**************************************************
 * This tasks routine manages the switches
 **************************************************/

void APP_SwitchTasks(void)
{
    if(!appData.switchIsPressed)
    {
        /* We will check the switch press only if the switch was not 
         * already pressed. */
        switch(appData.switchState)
        {
            case APP_SWITCH_STATE_CHECK_SWITCH_PRESS:

                /* Check if the switch was pressed. */
                if(SWITCH_Get() == SWITCH_STATE_PRESSED)
                {
                    /* The switch is pressed. Start the de-bounce timer. If the timer
                     * was not created successfully, we will not advance to the next
                     * state. */

                    if(SYS_TIME_DelayMS(APP_SWITCH_DEBOUNCE_TIME_MS, &appData.debounceTimer) == SYS_TIME_SUCCESS)
                    {
                        appData.switchState = APP_SWITCH_STATE_WAIT_FOR_DEBOUNCE;
                    }
                }
                break;

            case APP_SWITCH_STATE_WAIT_FOR_DEBOUNCE:

                /* Here we will check if the de-bounce time is complete */
                if(SYS_TIME_DelayIsComplete(appData.debounceTimer))
                {
                    /* Check if the switch is still pressed. If yes, then we
                     * have a valid switch press. */
                    if(SWITCH_Get() == SWITCH_STATE_PRESSED)
                    {
                        /* Switch press is valid*/
                        appData.switchState = APP_SWITCH_STATE_WAIT_FOR_RELEASE;
                    }
                    else
                    {
                        /* This was an invalid switch press */
                        appData.switchState = APP_SWITCH_STATE_CHECK_SWITCH_PRESS;
                    }
                }
                break;

            case APP_SWITCH_STATE_WAIT_FOR_RELEASE:
                if(SWITCH_Get() == SWITCH_STATE_RELEASED)
                {
                    appData.switchIsPressed = true;
                    appData.switchState = APP_SWITCH_STATE_CHECK_SWITCH_PRESS;
                }
                break;

            default:
                break;
        }
    }
}


bool APP_SwitchIsPressed(void)
{
    bool result = false;
    
    /* If the switch is pressed, clear the switch pressed flag and
     * then return true. */
    if(appData.switchIsPressed == true)
    {
        appData.switchIsPressed = false;
        result = true;
    }
    
    return(result);
}

void APP_DeviceSwitchStatusTasks(void)
{
    switch(appData.switchStatusTaskState)
    {
        case APP_DEVICE_SWITCH_STATUS_STATE_GET:
            
            /* In this state we initiate the device switch status command */
            if(APP_VENDOR_DRIVER_DeviceSwitchStatusGet(&appData.appBuffer) == true)
            {
                /* The command was initiated successfully. We can wait for the 
                 * command to complete. */
                appData.switchStatusTaskState = APP_DEVICE_SWITCH_STATUS_STATE_WAIT_GET;
            }
            
            break;
            
        case APP_DEVICE_SWITCH_STATUS_STATE_WAIT_GET:
            
            /* Here we check if the command has completed */
            if(!APP_VENDOR_DRIVER_DeviceSwitchStatusGetInProgress())
            {
                /* This means we have obtained the switch status. If the
                 * value if 0x0, then the switch was pressed. If it is 0x1
                 * this means the switch is not pressed. We activate the
                 * LED accordingly. The data will be available in the second
                 * byte of appBuffer */
                
                if(appData.oldSwitchStatus != appData.appBuffer)
                {
                    /* This means there is a change in the device switch status.
                     * Lets send a message to the console. */
                    SYS_CONSOLE_PRINT("APP: Change detected in the device switch status \r\n");
                    appData.oldSwitchStatus = appData.appBuffer;
                }
                
                if(appData.appBuffer == 0x0)
                {
                    LED_On();
                }
                else
                {
                    LED_Off();
                }
                
                /* We can launch the command again. */
                appData.switchStatusTaskState = APP_DEVICE_SWITCH_STATUS_STATE_GET;
            }
            
        default:
            break;
    }
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Call our Vendor Driver Tasks routine to ensure that the driver functions
     * and states are up to date.*/
    APP_VENDOR_DRIVER_Tasks();
    
    if(!APP_VENDOR_DRIVER_DeviceIsAvailable() && (appData.state > APP_STATE_WAIT_FOR_ATTACH))
    {
        /* If the device was attached but is now detached, we will reset the
         * application state to waiting for attach. */
        SYS_CONSOLE_PRINT("APP: device is not available \r\n");
        SYS_CONSOLE_PRINT("APP: Waiting for device to be available \r\n");
        appData.state = APP_STATE_WAIT_FOR_ATTACH;
    }
    
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_BUS_ENABLE:
        {
            /* First we assign the generic driver framework support functions.
             * Note that vendor driver initialize function (that we have
             * implemented) has already been invoked at this point in the 
             * APP_Initialize() function before the bus is enabled. This way our
             * driver is ready for device attach. We then register the USB Host 
             * Event Handler and then enabled the USB Host. */
            
            USB_HOST_GENERIC_Register(APP_VENDOR_DRIVER_DeviceAssign, APP_VENDOR_DRIVER_DeviceRelease,
                    APP_VENDOR_DRIVER_InterfaceAssign, APP_VENDOR_DRIVER_InterfaceRelease,
                    APP_VENDOR_DRIVER_DeviceEventHandler, APP_VENDOR_DRIVER_InterfaceEventHandler);
            USB_HOST_EventHandlerSet(APP_USBHostEventHandler, (uintptr_t)0);
            SYS_CONSOLE_PRINT("APP: Enabling USB Host Bus \r\n");
            USB_HOST_BusEnable(USB_HOST_BUS_ALL);
            appData.state = APP_STATE_WAIT_FOR_BUS_ENABLE;
            break;
        }
        
        case APP_STATE_WAIT_FOR_BUS_ENABLE:
            if(USB_HOST_BusIsEnabled(USB_HOST_BUS_ALL) == true)
            {
                SYS_CONSOLE_PRINT("APP: USB Host Bus is enabled. \r\n");
                SYS_CONSOLE_PRINT("APP: Waiting for device to be available \r\n");
                appData.state = APP_STATE_WAIT_FOR_ATTACH;
            }
            break;

        case APP_STATE_WAIT_FOR_ATTACH:
            
            /* Check if the device is attached and available */
            if (APP_VENDOR_DRIVER_DeviceIsAvailable())
            {
                /* This means device is available. We can start interacting 
                 * with the board. If a switch is pressed on the host,
                 * we can toggle the LED on the device. If the switch on the
                 * device is pressed, then we toggle the LED on the host. */
                SYS_CONSOLE_PRINT("APP: Device is available \r\n");
                appData.state = APP_STATE_CHECK_SWITCH_STATE;
            }
            break;
        
        case APP_STATE_CHECK_SWITCH_STATE:
    
            APP_SwitchTasks();
            APP_DeviceSwitchStatusTasks();
            if(APP_SwitchIsPressed() && !APP_VENDOR_DRIVER_LedToggleCommandInProgress())
            {
                /* This means the switch is pressed and no LED Toggle command is
                 * in progress. Send the command to the device */
                SYS_CONSOLE_PRINT("APP: Switch was pressed. Sending LED toggle command to the device. \r\n");
                APP_VENDOR_DRIVER_ToggleLED();
            }
            
 
            break;
        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
