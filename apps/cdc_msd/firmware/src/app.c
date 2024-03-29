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

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"


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

APP_DATA USB_ALIGN appData;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************



/* This is the string that will written to the file */
USB_ALIGN uint8_t writeData[12] = "Hello World ";

/* This is the string that will written to the CDC device */
USB_ALIGN uint8_t ledon[]  = "\r\nLED ON";
USB_ALIGN uint8_t ledoff[] = "\r\nLED OFF";



/* Application MSD Task Object */
APP_MSD_DATA USB_ALIGN appMSDData;

/* Application CDC Task Object */
APP_CDC_DATA  USB_ALIGN appCDCData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    USB_HOST_EVENT_RESPONSE APP_USBHostEventHandler 
    (
        USB_HOST_EVENT event, 
        void * eventData,
        uintptr_t context
    )

  Remarks:
    The USB Host Layer uses this function to communicate events to the 
    application.
    
 */
USB_HOST_EVENT_RESPONSE APP_USBHostEventHandler 
(
    USB_HOST_EVENT event, 
    void * eventData,
    uintptr_t context
)
{
    /* The USB Host Layer uses this function to communicate events to the 
       application. In this example only the USB_HOST_EVENT_DEVICE_UNSUPPORTED
       event is handled. */

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

/*******************************************************************************
  Function:
    void APP_SYSFSEventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)

  Remarks:
    The File System (FS) uses this function to communicate events to the 
    application.
    
 */
void APP_SYSFSEventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
            appMSDData.deviceIsConnected = true;
            break;
            
        case SYS_FS_EVENT_UNMOUNT:
            appMSDData.deviceIsConnected = false;
            LED1_Off();
            break;
            
        default:
            break;
    }
}

/*******************************************************************************
  Function:
    void APP_USBHostCDCAttachEventListener(USB_HOST_CDC_OBJ cdcObj, uintptr_t context)

  Remarks:
    The CDC Host client Driver uses this function to communicate attach events to the 
    application.
    
 */
void APP_USBHostCDCAttachEventListener(USB_HOST_CDC_OBJ cdcObj, uintptr_t context)
{
    /* This function gets called when a CDC device is attached. Here, the data 
       structure of the application is modified to reflect the device's 
       attachment. */
    
    appCDCData.deviceIsAttached = true;
    appCDCData.cdcObj = cdcObj;
}

/*******************************************************************************
  Function:
    USB_HOST_CDC_EVENT_RESPONSE APP_USBHostCDCEventHandler
    (
        USB_HOST_CDC_HANDLE cdcHandle,
        USB_HOST_CDC_EVENT event,
        void * eventData,
        uintptr_t context
    )

  Remarks:
    The CDC Host client Driver uses this function to communicate all events 
    (except the device attach event) to the application.
    
 */

USB_HOST_CDC_EVENT_RESPONSE APP_USBHostCDCEventHandler
(
    USB_HOST_CDC_HANDLE cdcHandle,
    USB_HOST_CDC_EVENT event,
    void * eventData,
    uintptr_t context
)
{
    /* This function is called when a CDC Host event has occurred. A pointer to
     * this function is registered after opening the device. See the call to
     * USB_HOST_CDC_EventHandlerSet() function. */

    USB_HOST_CDC_EVENT_ACM_SET_LINE_CODING_COMPLETE_DATA * setLineCodingEventData;
    USB_HOST_CDC_EVENT_ACM_SET_CONTROL_LINE_STATE_COMPLETE_DATA * setControlLineStateEventData;
    USB_HOST_CDC_EVENT_WRITE_COMPLETE_DATA * writeCompleteEventData;
    USB_HOST_CDC_EVENT_READ_COMPLETE_DATA * readCompleteEventData;
    
    switch(event)
    {
        case USB_HOST_CDC_EVENT_ACM_SET_LINE_CODING_COMPLETE:
            
            /* This means the application requested Set Line Coding request is
             * complete. */
            setLineCodingEventData = (USB_HOST_CDC_EVENT_ACM_SET_LINE_CODING_COMPLETE_DATA *)(eventData);
            appCDCData.controlRequestDone = true;
            appCDCData.controlRequestResult = setLineCodingEventData->result;
            break;
            
        case USB_HOST_CDC_EVENT_ACM_SET_CONTROL_LINE_STATE_COMPLETE:
            
            /* This means the application requested Set Control Line State 
             * request has completed. */
            setControlLineStateEventData = (USB_HOST_CDC_EVENT_ACM_SET_CONTROL_LINE_STATE_COMPLETE_DATA *)(eventData);
            appCDCData.controlRequestDone = true;
            appCDCData.controlRequestResult = setControlLineStateEventData->result;
            break;
            
        case USB_HOST_CDC_EVENT_WRITE_COMPLETE:
            
            /* This means an application requested write has completed */
            appCDCData.writeTransferDone = true;
            writeCompleteEventData = (USB_HOST_CDC_EVENT_WRITE_COMPLETE_DATA *)(eventData);
            appCDCData.writeTransferResult = writeCompleteEventData->result;
            break;
            
        case USB_HOST_CDC_EVENT_READ_COMPLETE:
            
            /* This means an application requested write has completed */
            appCDCData.readTransferDone = true;
            readCompleteEventData = (USB_HOST_CDC_EVENT_READ_COMPLETE_DATA *)(eventData);
            appCDCData.readTransferResult = readCompleteEventData->result;
            break;
            
        case USB_HOST_CDC_EVENT_DEVICE_DETACHED:
            
            /* The device was detached */
            appCDCData.deviceWasDetached = true;
            /* Switch off LED  */
            LED1_Off();
            break;
            
        default:
            break;
    }
    
    return(USB_HOST_CDC_EVENT_RESPONE_NONE);
}
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
    APP_CDC_Initialize( &appCDCData );
    APP_MSD_Initialize ( &appMSDData);    
}

/*************************************************
 * Application MSD Task Initialize Function.
 *************************************************/

void APP_MSD_Initialize (APP_MSD_DATA * appMSDInitData )
{
     appMSDInitData->state = APP_MSD_STATE_WAIT_FOR_DEVICE_ATTACH;
     appMSDInitData->deviceIsConnected = false;
}


/*************************************************
 * Application CDC Task Initialize Function.
 *************************************************/

void APP_CDC_Initialize ( APP_CDC_DATA *appCDInitCData )
{
      /* Initialize the application state machine */
    
    appCDInitCData->state =  APP_CDC_STATE_WAIT_FOR_DEVICE_ATTACH;
    appCDInitCData->cdcHostLineCoding.dwDTERate     = APP_HOST_CDC_BAUDRATE_SUPPORTED;
    appCDInitCData->cdcHostLineCoding.bDataBits     = (uint8_t)APP_HOST_CDC_NO_OF_DATA_BITS;
    appCDInitCData->cdcHostLineCoding.bParityType   = (uint8_t)APP_HOST_CDC_PARITY_TYPE;
    appCDInitCData->cdcHostLineCoding.bCharFormat   = (uint8_t)APP_HOST_CDC_STOP_BITS;
    appCDInitCData->controlLineState.dtr = 0;
    appCDInitCData->controlLineState.carrier = 0;
    appCDInitCData->deviceIsAttached = false;
    appCDInitCData->deviceWasDetached = false;
    appCDInitCData->readTransferDone = false;
    appCDInitCData->writeTransferDone = false;
    appCDInitCData->controlRequestDone = false;
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    switch (appData.state)
    {
       case APP_STATE_BUS_ENABLE:
                      
           /* Set the event handler and enable the bus */
            SYS_FS_EventHandlerSet(APP_SYSFSEventHandler, (uintptr_t)1);
            USB_HOST_EventHandlerSet(APP_USBHostEventHandler, 0 );
            USB_HOST_EventHandlerSet(APP_USBHostEventHandler, (uintptr_t)NULL);
            USB_HOST_CDC_AttachEventHandlerSet(APP_USBHostCDCAttachEventListener, (uintptr_t) 0);
            USB_HOST_BusEnable(USB_HOST_BUS_ALL);
            appData.state = APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE;
            break;

     case APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE:
            if(USB_HOST_BusIsEnabled(USB_HOST_BUS_ALL))
            {
                appData.state = APP_STATE_RUN_MSD_CDC_TASKS;
            }
            break;

        case APP_STATE_RUN_MSD_CDC_TASKS:

            /* Run the Application CDC and MSD Tasks */
            APP_MSD_Tasks ();
            APP_CDC_Tasks ();

            break;

        case APP_STATE_ERROR:

            /* Some error has occurred */

            break;
        default:
            break;
    }
}


/*************************************************
 * Application MSD Tasks
 *************************************************/

void APP_MSD_Tasks (  )
{
    /* The application task state machine */

    switch(appMSDData.state)
    {
       case APP_MSD_STATE_WAIT_FOR_DEVICE_ATTACH:

            /* Wait for device attach. The state machine will move
             * to the next state when the attach event
             * is received.  */
            if(appMSDData.deviceIsConnected)
            {
                appMSDData.state = APP_MSD_STATE_DEVICE_CONNECTED;
            }

            break;

        case APP_MSD_STATE_DEVICE_CONNECTED:

            /* Device was connected. We can try mounting the disk */
            appMSDData.state = APP_MSD_STATE_OPEN_FILE;
            break;

        case APP_MSD_STATE_OPEN_FILE:

            /* Try opening the file for append */
            appMSDData.fileHandle = SYS_FS_FileOpen("/mnt/myDrive1/file.txt", (SYS_FS_FILE_OPEN_APPEND_PLUS));
            if(appMSDData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                appMSDData.state = APP_MSD_STATE_ERROR;

            }
            else
            {
                /* File opened successfully. Write to file */
                appMSDData.state = APP_MSD_STATE_WRITE_TO_FILE;

            }
            break;

        case APP_MSD_STATE_WRITE_TO_FILE:

            /* Try writing to the file */
            if (SYS_FS_FileWrite( appMSDData.fileHandle, (const void *) writeData, 12 ) == -1)
            {
                /* Write was not successful. Close the file
                 * and error out.*/
                SYS_FS_FileClose(appMSDData.fileHandle);
                appMSDData.state = APP_MSD_STATE_ERROR;

            }
            else
            {
                /* We are done writing. Close the file */
                appMSDData.state = APP_MSD_STATE_CLOSE_FILE;
            }

            break;

        case APP_MSD_STATE_CLOSE_FILE:

            /* Close the file */
            SYS_FS_FileClose(appMSDData.fileHandle);
            LED1_On();
            
            /* The test was successful. Lets idle. */
            appMSDData.state = APP_MSD_STATE_IDLE;
            break;

        case APP_MSD_STATE_IDLE:

            /* The application comes here when the demo has completed
             * successfully. Provide LED indication. Wait for device detach
             * and if detached, wait for attach. */

            
            if(appMSDData.deviceIsConnected == false)
            {
                appMSDData.state = APP_MSD_STATE_WAIT_FOR_DEVICE_ATTACH;
            }
            break;

        case APP_MSD_STATE_ERROR:

            /* The application comes here when the demo
             * has failed. Provide LED indication .*/

            if(SYS_FS_Unmount("/mnt/myDrive") != 0)
            {
                /* The disk could not be un mounted. Try
                 * un mounting again untill success. */

                appMSDData.state = APP_MSD_STATE_ERROR;
            }
            else
            {
                /* UnMount was successful. Wait for device attach */
                appMSDData.state =  APP_MSD_STATE_WAIT_FOR_DEVICE_ATTACH;

            }
            break;

        default:
            break;
    }
}

/**********************************************
 * Application CDC Task Routine.
 ***********************************************/

void APP_CDC_Tasks( )
{
    USB_HOST_CDC_RESULT result;
  
    
    if(appCDCData.deviceWasDetached)
   {
       /* This means the device is not attached. Reset the application state */
       
       appCDCData.state = APP_CDC_STATE_WAIT_FOR_DEVICE_ATTACH;
       appCDCData.readTransferDone = false;
       appCDCData.writeTransferDone = false;
       appCDCData.controlRequestDone = false;
       appCDCData.deviceWasDetached = false;
   }

    switch (appCDCData.state)
    {
         case APP_CDC_STATE_WAIT_FOR_DEVICE_ATTACH:
            
             /* In this state the application is waiting for the device to be
             * attached */
            if(appCDCData.deviceIsAttached)
            {
                /* A device is attached. We can open this device */
                appCDCData.state = APP_CDC_STATE_OPEN_DEVICE;
                appCDCData.deviceIsAttached = false;
            }
            break;
            
        case APP_CDC_STATE_OPEN_DEVICE:
            
            /* In this state the application opens the attached device */
            appCDCData.cdcHostHandle = USB_HOST_CDC_Open(appCDCData.cdcObj);
            if(appCDCData.cdcHostHandle != USB_HOST_CDC_HANDLE_INVALID)
            {
                /* The driver was opened successfully. Set the event handler
                 * and then go to the next state. */
                USB_HOST_CDC_EventHandlerSet(appCDCData.cdcHostHandle, APP_USBHostCDCEventHandler, (uintptr_t)0);
                appCDCData.state = APP_CDC_STATE_SET_LINE_CODING;
            }
            break;
            
        case APP_CDC_STATE_SET_LINE_CODING:
            
            /* Here we set the Line coding. The control request done flag will
             * be set to true when the control request has completed. */
            
            appCDCData.controlRequestDone = false;
            result = USB_HOST_CDC_ACM_LineCodingSet(appCDCData.cdcHostHandle, NULL, &appCDCData.cdcHostLineCoding);
            
            if(result == USB_HOST_CDC_RESULT_SUCCESS)
            {
                /* We wait for the set line coding to complete */
                appCDCData.state = APP_CDC_STATE_WAIT_FOR_SET_LINE_CODING;
            }
                            
            break;
            
        case APP_CDC_STATE_WAIT_FOR_SET_LINE_CODING:
            
            if(appCDCData.controlRequestDone)
            {
                if(appCDCData.controlRequestResult != USB_HOST_CDC_RESULT_SUCCESS)
                {
                    /* The control request was not successful. */
                    appCDCData.state = APP_STATE_ERROR;
                }
                else
                {
                    /* Next we set the Control Line State */
                    appCDCData.state = APP_CDC_STATE_SEND_SET_CONTROL_LINE_STATE;
                }
            }
            break;
            
        case APP_CDC_STATE_SEND_SET_CONTROL_LINE_STATE:
            
            /* Here we set the control line state */
            appCDCData.controlRequestDone = false;
            result = USB_HOST_CDC_ACM_ControlLineStateSet(appCDCData.cdcHostHandle, NULL, 
                    &appCDCData.controlLineState);
            
            if(result == USB_HOST_CDC_RESULT_SUCCESS)
            {
                /* We wait for the set line coding to complete */
                appCDCData.state = APP_CDC_STATE_WAIT_FOR_SET_CONTROL_LINE_STATE;
            }
            
            break;
            
        case APP_CDC_STATE_WAIT_FOR_SET_CONTROL_LINE_STATE:
            
            /* Here we wait for the control line state set request to complete */
            if(appCDCData.controlRequestDone)
            {
                if(appCDCData.controlRequestResult != USB_HOST_CDC_RESULT_SUCCESS)
                {
                    /* The control request was not successful. */
                    appCDCData.state = APP_CDC_STATE_ERROR;
                }
                else
                {
                    /* Turn ON LED to indicate the device is attached and ready 
                       for data transfer. */
                    LED1_On();

                    /* Now, the application will send an "LED ON" message to the
                       CDC Device. Fill the buffer here. */
                    appCDCData.cdcWriteSize = sizeof(ledon);
                    appCDCData.cdcWriteData = ledon;
                    appCDCData.state = APP_CDC_STATE_SEND_PROMPT_TO_DEVICE;
                }
            }
            
            break;
            
        case APP_CDC_STATE_SEND_PROMPT_TO_DEVICE:
            
            /* The prompt is sent to the device here. The write transfer done
             * flag is updated in the event handler. */
            
            appCDCData.writeTransferDone = false;
            result = USB_HOST_CDC_Write(appCDCData.cdcHostHandle, NULL, ( void *) appCDCData.cdcWriteData, appCDCData.cdcWriteSize);
            
            if(result == USB_HOST_CDC_RESULT_SUCCESS)
            {
                appCDCData.state = APP_CDC_STATE_WAIT_FOR_PROMPT_SEND_COMPLETE;
            }
            break;
            
        case APP_CDC_STATE_WAIT_FOR_PROMPT_SEND_COMPLETE:
            
            /* Here we check if the write transfer is done */
            if(appCDCData.writeTransferDone)
            {
                if(appCDCData.writeTransferResult == USB_HOST_CDC_RESULT_SUCCESS)
                {
                    /* Now to get data from the device */
                    appCDCData.state = APP_CDC_STATE_GET_DATA_FROM_DEVICE;
                }
                else
                {
                    /* Try sending the prompt again. */
                    appCDCData.state = APP_CDC_STATE_SEND_PROMPT_TO_DEVICE;
                }
            }
            
            break;
            
        case APP_CDC_STATE_GET_DATA_FROM_DEVICE:
            
            /* Here we request data from the device */
            appCDCData.readTransferDone = false;
            result = USB_HOST_CDC_Read(appCDCData.cdcHostHandle, NULL, appCDCData.inDataArray, 1);
            if(result == USB_HOST_CDC_RESULT_SUCCESS)
            {
                appCDCData.state = APP_CDC_STATE_WAIT_FOR_DATA_FROM_DEVICE;
            }
            break;
           
        case APP_CDC_STATE_WAIT_FOR_DATA_FROM_DEVICE:
            
            /* Wait for data from device. If the data has arrived, then toggle
             * the LED. */
            if(appCDCData.readTransferDone)
            {
                if(appCDCData.readTransferResult == USB_HOST_CDC_RESULT_SUCCESS)
                {
                   if ( appCDCData.inDataArray[0] == '1')
                    {
                        /* Switch on LED 1 */

                        LED1_On();
                        /* Fill the buffer. */
                        appCDCData.cdcWriteSize = sizeof(ledon);
                        appCDCData.cdcWriteData = ledon;

                    }
                    else 
                    {
                        /* Switch on LED 2 */
                        LED1_Off();
                        /* Fill the buffer. */
                        appCDCData.cdcWriteSize = sizeof(ledoff);
                        appCDCData.cdcWriteData = ledoff;

                    }
                    /* Send the prompt to the device and wait
                     * for data again */
                    appCDCData.state = APP_CDC_STATE_SEND_PROMPT_TO_DEVICE;
                }
            }
            
        case APP_CDC_STATE_ERROR:
            /* An error has occurred */
            break;
            
        default:
            break;
    }
}

/*******************************************************************************
 End of File
 */

