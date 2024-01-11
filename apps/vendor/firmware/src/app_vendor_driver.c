/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_vendor_driver.c

  Summary:
    This file contains the source code for the vendor device USB Host driver.

  Description:
    This file contains the source code for the vendor device USB Host driver. It
    uses the USB Host Generic Driver framework to access the device. 
 *******************************************************************************/
 
 // DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "usb/usb_host_generic.h"
#include "app.h"
#include "system/console/sys_console.h"

/* Note that USB_ALIGN is required because we need the first
 * member of this structure, which the receive buffer to be 
 * aligned on required boundary */

USB_ALIGN APP_VENDOR_DRIVER_OBJ vendorDriverObj;

void APP_VENDOR_DRIVER_Initialize(void)
{
    vendorDriverObj.bulkInPipeHandle = USB_HOST_PIPE_HANDLE_INVALID;
    vendorDriverObj.bulkOutPipeHandle = USB_HOST_PIPE_HANDLE_INVALID;
    vendorDriverObj.controlPipeHandle = USB_HOST_PIPE_HANDLE_INVALID;
    vendorDriverObj.deviceHandle = USB_HOST_DEVICE_CLIENT_HANDLE_INVALID;
    vendorDriverObj.deviceObjHandle = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;
    vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_WAIT_FOR_ATTACH;
    vendorDriverObj.deviceState = APP_VENDOR_DEVICE_STATE_DETACHED;
    vendorDriverObj.interfacesProcessed = false;
    vendorDriverObj.ledToggleCommand = 0x80;
    vendorDriverObj.ledToggleCommandErrorHasOccurred = false;    
    vendorDriverObj.ledToggleCommandInProgress = false;
    vendorDriverObj.switchGetCommand = 0x81;
    vendorDriverObj.switchGetCommandInProgress = false;
    vendorDriverObj.switchGetCommmandErrorHadOccurred = false;
    SYS_CONSOLE_PRINT("APP Vendor Driver: Initialization Complete \r\n");
    
}

void APP_VENDOR_DRIVER_DeviceAssign
(
    USB_HOST_DEVICE_CLIENT_HANDLE deviceHandle,
    USB_HOST_DEVICE_OBJ_HANDLE deviceObjHandle,
    USB_DEVICE_DESCRIPTOR * deviceDescriptor
)
{
    /* The USB Host Generic Driver framework will call this function when
     * it the attached device VID PID or Class Subclass Protocol matches the
     * filter criteria. The device descriptor can be inspected further to 
     * verify  if our vendor driver will indeed support the attached device.
     * If the device cannot be supported for any reason, we can return the
     * device to USB Host by calling the USB_HOST_DeviceRelease() function. 
     * The USB Host layer will then try to assign this device to other drivers
     * in the TPL table that could handle this device.*/
    
    /* Un-comment the below line if the driver should not handle this device*/
    /* USB_HOST_DeviceRelease(deviceHandle); */
    
    /* Lets keep track of the device object and client handles. We will need
     * these to operate the device. Change the state of the device to reflect
     * the attach. This is also a good time to initialize the variables.*/
    
    vendorDriverObj.deviceState = APP_VENDOR_DEVICE_STATE_ATTACHED;
    vendorDriverObj.deviceObjHandle = deviceObjHandle;
    vendorDriverObj.deviceHandle = deviceHandle;
    vendorDriverObj.bulkInPipeHandle = USB_HOST_PIPE_HANDLE_INVALID;
    vendorDriverObj.bulkOutPipeHandle = USB_HOST_PIPE_HANDLE_INVALID;
    vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_WAIT_FOR_ATTACH;
    vendorDriverObj.interfacesProcessed = false;
    vendorDriverObj.ledToggleCommandErrorHasOccurred = false;    
    vendorDriverObj.ledToggleCommandInProgress = false;
    vendorDriverObj.switchGetCommandInProgress = false;
    vendorDriverObj.switchGetCommmandErrorHadOccurred = false;
}

void APP_VENDOR_DRIVER_DeviceRelease (USB_HOST_DEVICE_CLIENT_HANDLE deviceHandle)
{
    /* This function will be called first when the device is detached.
     * We will use this function to close the pipes. Because this function
     * is called from an interrupt context, it should be ensure that variables
     * that are updated here are not updated in the device tasks. */
 
    vendorDriverObj.deviceState = APP_VENDOR_DEVICE_STATE_DETACHED;
    
    /* Close any open pipes. Don't bother with control pipe. That will
     * be handled by the host layer. */
    USB_HOST_DevicePipeClose(vendorDriverObj.bulkInPipeHandle);
    USB_HOST_DevicePipeClose(vendorDriverObj.bulkOutPipeHandle);
          
}

USB_HOST_DEVICE_EVENT_RESPONSE APP_VENDOR_DRIVER_DeviceEventHandler
(
    USB_HOST_DEVICE_CLIENT_HANDLE deviceHandle,
    USB_HOST_DEVICE_EVENT event,
    void * eventData,
    uintptr_t context
)
{
    USB_HOST_DEVICE_EVENT_CONFIGURATION_SET_DATA * data = NULL;
    
    switch(event)
    {
        /* This event occurs when the host layer has configured the device. All
         * client drivers that have opened this device will receive this event. The
         * event is accompanied by the USB_HOST_DEVICE_DATA_CONFIGURATION_SET_DATA
         * type of event data that contains the result of the operation. */
        case USB_HOST_DEVICE_EVENT_CONFIGURATION_SET: 
            data = (USB_HOST_DEVICE_EVENT_CONFIGURATION_SET_DATA *)eventData;
            vendorDriverObj.requestDone = true;
            vendorDriverObj.result = data->result;
            break;

        /* This event occurs when a USB_HOST_ConfigurationDescriptorGet() function
         * has completed. This event is accompanied by the
         * USB_HOST_DEVICE_EVENT_CONFIGURATION_DESCRIPTOR_GET_COMPLETE_DATA type of
         * event data that contains the result of the transfer. */
        case USB_HOST_DEVICE_EVENT_CONFIGURATION_DESCRIPTOR_GET_COMPLETE:
            break;
    }
    
    return(USB_HOST_DEVICE_EVENT_RESPONSE_NONE);
}

void APP_VENDOR_DRIVER_InterfaceAssign
(
    USB_HOST_DEVICE_INTERFACE_HANDLE * interfaces,
    USB_HOST_DEVICE_OBJ_HANDLE deviceObjHandle,
    size_t nInterfaces,
    uint8_t * descriptor
)
{
    USB_HOST_ENDPOINT_DESCRIPTOR_QUERY endpointDescriptorQuery;
    USB_ENDPOINT_DESCRIPTOR * endpointDescriptor;
    USB_INTERFACE_DESCRIPTOR * interfaceDescriptor;

    
    /* The USB Host Generic Driver Framework will call this function after the
     * the configuration has been set. The function will be called for each
     * interface descriptor or Interface Associate Descriptor in the configuration.
     * In case of IAD, nInterface will be greater than one and interfaces will
     * be an array. */
    
    /* We will use the USB Host provided endpoint descriptor query objects to
     * to get the endpoint descriptors and then open the pipes. We know that 
     * this device has only interface, so checking nInterface will be redundant
     * but we will do it anyway. */
    
    if(nInterfaces == 1)
    {
        /* We know now that this is not an IAD. Save the interface handle
         * and the interface descriptor as we will need this to open the pipe 
         * and to communicate with the device. */
        vendorDriverObj.interfaceHandle = interfaces[0];
        interfaceDescriptor = (USB_INTERFACE_DESCRIPTOR *)descriptor;
        
        /* To find the endpoint descriptor, we will use a query. We need to
         * clear the query object context before running the query. In the 
         * following query, we are looking for a Bulk IN endpoint. We will
         * query by type and direction. */
        
        USB_HOST_DeviceEndpointQueryContextClear(&endpointDescriptorQuery);
        endpointDescriptorQuery.transferType = USB_TRANSFER_TYPE_BULK;
        endpointDescriptorQuery.direction = USB_DATA_DIRECTION_DEVICE_TO_HOST;
        endpointDescriptorQuery.flags = (USB_HOST_ENDPOINT_QUERY_FLAG)(USB_HOST_ENDPOINT_QUERY_BY_TRANSFER_TYPE|USB_HOST_ENDPOINT_QUERY_BY_DIRECTION);
        endpointDescriptor = USB_HOST_DeviceEndpointDescriptorQuery(interfaceDescriptor, &endpointDescriptorQuery);

        if(endpointDescriptor != NULL)
        {
            vendorDriverObj.bulkInPipeHandle = USB_HOST_DevicePipeOpen(vendorDriverObj.interfaceHandle, endpointDescriptor->bEndpointAddress);
            if(vendorDriverObj.bulkInPipeHandle == USB_HOST_PIPE_HANDLE_INVALID)
            {
                SYS_CONSOLE_PRINT("APP Vendor Driver: Could not open Bulk IN pipe \r\n");
            }
        }
        else
        {
            SYS_CONSOLE_PRINT("APP Vendor Driver: Could not find IN Endpoint descriptor \r\n");
        }
        
        /* In this query, we are looking for the Bulk OUT endpoint. */
        USB_HOST_DeviceEndpointQueryContextClear(&endpointDescriptorQuery);
        endpointDescriptorQuery.transferType = USB_TRANSFER_TYPE_BULK;
        endpointDescriptorQuery.direction = USB_DATA_DIRECTION_HOST_TO_DEVICE;
        endpointDescriptorQuery.flags = (USB_HOST_ENDPOINT_QUERY_FLAG)(USB_HOST_ENDPOINT_QUERY_BY_TRANSFER_TYPE|USB_HOST_ENDPOINT_QUERY_BY_DIRECTION);
        endpointDescriptor = USB_HOST_DeviceEndpointDescriptorQuery(interfaceDescriptor, &endpointDescriptorQuery);

        if(endpointDescriptor != NULL)
        {
            vendorDriverObj.bulkOutPipeHandle = USB_HOST_DevicePipeOpen(vendorDriverObj.interfaceHandle, endpointDescriptor->bEndpointAddress);
            if(vendorDriverObj.bulkOutPipeHandle == USB_HOST_PIPE_HANDLE_INVALID)
            {
                SYS_CONSOLE_PRINT("APP Vendor Driver: Could not open Bulk OUT pipe \r\n");
            }
        }
        else
        {
            SYS_CONSOLE_PRINT("APP Vendor Driver: Could not find Out Endpoint Descriptor \r\n");
        }
        
        /* We will let the tasks routine know that the interfaces have been
         * processed. */
        vendorDriverObj.interfacesProcessed = true;
    }
    
}

void APP_VENDOR_DRIVER_InterfaceRelease (USB_HOST_DEVICE_INTERFACE_HANDLE interfaceHandle)
{
    /* This function will be called after the device release function is called.
     * If the device release function implements all the detach level clean up
     * the nothing needs to be done here. In a case where the drive is an interface
     * level driver, then the device release function would not be called and only
     * the interface release function would be called. */
    
}

USB_HOST_DEVICE_INTERFACE_EVENT_RESPONSE APP_VENDOR_DRIVER_InterfaceEventHandler
(
    USB_HOST_DEVICE_INTERFACE_HANDLE interfaceHandle,
    USB_HOST_DEVICE_INTERFACE_EVENT event,
    void * eventData,
    uintptr_t context
)
{
    USB_HOST_DEVICE_INTERFACE_EVENT_TRANSFER_COMPLETE_DATA * result;
    
    switch(event)
    {
        /* This event occurs when a Bulk, Isochronous or Interrupt transfer has
         * completed. This event is accompanied by the
         * USB_HOST_DEVICE_INTERFACE_EVENT_TRANSFER_COMPLETE_DATA type of event data
         * that contains the result of the transfer. */
        case USB_HOST_DEVICE_INTERFACE_EVENT_TRANSFER_COMPLETE: 
            
            /* We get the event related data by type casting the eventData parameter. */
            result = (USB_HOST_DEVICE_INTERFACE_EVENT_TRANSFER_COMPLETE_DATA *)(eventData);
            
            /* Now we can use the context parameter to check if the transfer
             * was related to the LED command. */
            
            if ((uint8_t)context == vendorDriverObj.ledToggleCommand)
            {
                if(result->result != USB_HOST_RESULT_SUCCESS)
                {
                    vendorDriverObj.ledToggleCommandErrorHasOccurred = true;
                }
                
                /* Update the flag to reflect the completion.*/
                vendorDriverObj.ledToggleCommandInProgress = false;
            }
            else if ((uint8_t)context == vendorDriverObj.switchGetCommand)
            {
                /* This is the first of the switch status get command. */
                if(result->result != USB_HOST_RESULT_SUCCESS)
                {
                    vendorDriverObj.switchGetCommmandErrorHadOccurred = true;
                }
            }
            else if((uint8_t)context == (vendorDriverObj.switchGetCommand + 1))
            {
                /* This is the second of the switch status get command. */
                if(result->result != USB_HOST_RESULT_SUCCESS)
                {
                    /* An error has occurred. */
                    vendorDriverObj.switchGetCommmandErrorHadOccurred = true;
                }
                
                /* This is the end of the switch status get command. The
                 * switch status is available in the second element of 
                 * the array. */
                *vendorDriverObj.appBuffer = vendorDriverObj.buffer[1];
                vendorDriverObj.switchGetCommandInProgress = false;
            }
            
            break;

        /* This event occurs when a alternate setting request has completed. This
         * event is accompanied by the
         * USB_HOST_DEVICE_INTERFACE_EVENT_SET_INTERFACE_COMPLETE_DATA type of event
         * data that contains the result of the transfer. */
        case USB_HOST_DEVICE_INTERFACE_EVENT_SET_INTERFACE_COMPLETE:
            break;

        /* This event occurs when a endpoint halt clear request has completed. This
         * event is accompanied by the
         * USB_HOST_DEVICE_INTERFACE_EVENT_PIPE_HALT_CLEAR_COMPLETE_DATA type of
         * event data that contains the result of the transfer. */
        case USB_HOST_DEVICE_INTERFACE_EVENT_PIPE_HALT_CLEAR_COMPLETE:
            break;
    }
    
    return(USB_HOST_DEVICE_INTERFACE_EVENT_RESPONSE_NONE);
}

void APP_VENDOR_DRIVER_Tasks(void)
{
    USB_HOST_RESULT result;
    
    /* If at all the device gets detached, we should reset the state
     * machine to wait for attach. */
    if((vendorDriverObj.deviceState == APP_VENDOR_DEVICE_STATE_DETACHED)
            && (vendorDriverObj.driverState > APP_VENDOR_DRIVER_STATE_WAIT_FOR_ATTACH))
    {
        vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_WAIT_FOR_ATTACH;
        SYS_CONSOLE_PRINT("APP Vendor Driver: Device was detached. \r\n");
        SYS_CONSOLE_PRINT("APP Vendor Driver: Waiting for device attach. \r\n");
    }
    
    if(vendorDriverObj.ledToggleCommandErrorHasOccurred)
    {
        SYS_CONSOLE_PRINT("APP Vendor Driver: An error while executing the LED Toggle command. \r\n");
        vendorDriverObj.ledToggleCommandErrorHasOccurred = false;
    }
    
    if(vendorDriverObj.switchGetCommmandErrorHadOccurred)
    {
        SYS_CONSOLE_PRINT("APP Vendor Driver: An error while executing the Switch Status Get command. \r\n");
        vendorDriverObj.switchGetCommmandErrorHadOccurred = false;
    }
    
    switch(vendorDriverObj.driverState)
    {
        case APP_VENDOR_DRIVER_STATE_WAIT_FOR_ATTACH:
            
            /* In this state, we check if the device was attached. If the device
             * was attached, we can open the control pipe and move to the state
             * where we set the device configuration. */
            if(vendorDriverObj.deviceState == APP_VENDOR_DEVICE_STATE_ATTACHED)
            {
                /* We will keep things simple and will not check if the control
                 * pipe was obtained successfully. The value can be compared to
                 * USB_HOST_PIPE_HANDLE_INVALID and if so, the driver can release
                 * device. */
                vendorDriverObj.controlPipeHandle = USB_HOST_DeviceControlPipeOpen(vendorDriverObj.deviceObjHandle);
                vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_SET_CONFIGURATION;
                SYS_CONSOLE_PRINT("APP Vendor Driver: Device Attached \r\n");
            }
            break;
            
        case APP_VENDOR_DRIVER_STATE_SET_CONFIGURATION:
            
            /* In this state we will set the device configuration. There are two
             * approaches that the driver can take. The first approach is where
             * we already know which configuration to set because presumably we
             * have developed the attached device. The other approach is where
             * USB_HOST_DeviceConfigurationGet() function to get the 
             * configuration, analyze it and then set the configuration. In
             * this case, we know the index of the device configuration to be set.
             */
            
            vendorDriverObj.requestDone = false;
            result = USB_HOST_DeviceConfigurationSet(vendorDriverObj.deviceHandle, NULL, 0x0, 0);
            SYS_CONSOLE_PRINT("APP Vendor Driver: Trying to Set Configuration 1 \r\n");
            if (result == USB_HOST_RESULT_REQUEST_BUSY)
            {
                /* The device is not ready. We will stay in this state */
            }
            else if(result == USB_HOST_RESULT_SUCCESS)
            {
                /* Now we will wait for the configuration set to be complete. */
                vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_WAIT_FOR_SET_CONFIGURATION;
            }
            else
            {
                /* If the configuration set request was not successful,
                 * we cannot proceed. Lets just wait for the device to 
                 * be detached. */
                vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_ERROR;
                SYS_CONSOLE_PRINT("APP Vendor Driver: Error while trying to Set Configuration 1 \r\n");
            }
            break;
            
        case APP_VENDOR_DRIVER_STATE_WAIT_FOR_SET_CONFIGURATION:
            
            /* The requestDone flag will be set to true in the 
             * USB_HOST_DEVICE_EVENT_CONFIGURATION_SET event handling section. */
            if(vendorDriverObj.requestDone == true)
            {
                /* This means the configuration set request is complete. Now we
                 * check if the request was successful. */
                if(vendorDriverObj.result != USB_HOST_RESULT_SUCCESS)
                {
                    /* This means the configuration could not be set. We will 
                     * place the driver in an error state. */
                    SYS_CONSOLE_PRINT("APP Vendor Driver: Error while trying to Set Configuration 1 \r\n");
                    vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_ERROR;
                }
                else
                {
                    SYS_CONSOLE_PRINT("APP Vendor Driver: Set Configuration complete \r\n");
                    vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_WAIT_FOR_INTERFACE_READY;
                }
            }
            break;
            
        case APP_VENDOR_DRIVER_STATE_WAIT_FOR_INTERFACE_READY:
            
            /* The interfaces are processed and communication pipes are opened
             * in the APP_VENDOR_DRIVER_InterfaceAssign() function. In the task
             * routine we will check if the pipes were opened successfully. */
            if(vendorDriverObj.interfacesProcessed == true)
            {
                if((vendorDriverObj.bulkInPipeHandle != USB_HOST_PIPE_HANDLE_INVALID) &&
                        (vendorDriverObj.bulkOutPipeHandle != USB_HOST_PIPE_HANDLE_INVALID))
                {
                    /* This means that both the pipes were opened successfully.
                     * The device is now ready for use */
                    SYS_CONSOLE_PRINT("APP Vendor Driver: Both pipes open. Device is ready \r\n");
                    vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_RUNNING;
                }
                else
                {
                    /* This means one or both pipes could not be opened. We will
                     * place the driver in an error state. */
                    SYS_CONSOLE_PRINT("APP Vendor Driver: Could not open pipes. Driver is in error state \r\n");
                    vendorDriverObj.driverState = APP_VENDOR_DRIVER_STATE_ERROR;
                }
            }
            break;
            
        case APP_VENDOR_DRIVER_STATE_RUNNING:
            break;
            
        case APP_VENDOR_DRIVER_STATE_ERROR:
            break;
            
        case APP_VENDOR_DRIVER_STATE_ERROR_HOLDING:
            break;
            
        default:
            break;
    }
}

bool APP_VENDOR_DRIVER_DeviceIsAvailable(void)
{
    /* This function will return true if the device is ready to operated*/
    bool result = false;
    
    if((vendorDriverObj.driverState == APP_VENDOR_DRIVER_STATE_RUNNING)
            && (vendorDriverObj.deviceState == APP_VENDOR_DEVICE_STATE_ATTACHED))
    {
        result = true;
    }
    
    return(result);
}

bool APP_VENDOR_DRIVER_ToggleLED(void)
{
    /* This will function will toggle the LED on device. The toggle LED
     * command value is 0x80. The function will use the USB_HOST_DeviceTransfer()
     * function to write data to the device. */
    
    USB_HOST_TRANSFER_HANDLE tempTransferHandle;
    bool result = true;
    
    /* Note how we specify the command value as the context in the device transfer
     * function. This will allow us to easily identify the source transfer
     * in the transfer done event. The ledToggleCommandDone flag will be updated
     * in the event.*/
    
    if(vendorDriverObj.ledToggleCommandInProgress == false)
    {
        /* We will process the command only if the command is not already in
         * progress. */
        
        vendorDriverObj.ledToggleCommandInProgress = true;
        
        if(USB_HOST_DeviceTransfer(vendorDriverObj.bulkOutPipeHandle, &tempTransferHandle, 
            &vendorDriverObj.ledToggleCommand, 1, (uintptr_t)(vendorDriverObj.ledToggleCommand)) != USB_HOST_RESULT_SUCCESS)
        {
            /* This means the transfer could not be scheduled for some reason.*/
            vendorDriverObj.ledToggleCommandInProgress = false;
            result = false;
        }
    }
    
    return(result);
}

bool APP_VENDOR_DRIVER_LedToggleCommandInProgress(void)
{
    /* Return the current LED Toggle Command Progress. */
    return(vendorDriverObj.ledToggleCommandInProgress);
}

bool APP_VENDOR_DRIVER_DeviceSwitchStatusGet(uint8_t * appBuffer)
{
    USB_HOST_TRANSFER_HANDLE tempTransferHandle;
    bool result = false;

    /* The switch status get operation required two transfers to be scheduled. 
     * We can use the queuing feature of the host layer to queue transactions.*/
    if(vendorDriverObj.switchGetCommandInProgress == false)
    {
        vendorDriverObj.switchGetCommandInProgress = true;
        vendorDriverObj.appBuffer = appBuffer;
        
        /* The context value of the first command is the actual command */
        if(USB_HOST_DeviceTransfer(vendorDriverObj.bulkOutPipeHandle, &tempTransferHandle, 
            &vendorDriverObj.switchGetCommand, 1, (uintptr_t)(vendorDriverObj.switchGetCommand)) == USB_HOST_RESULT_SUCCESS)
        {
            /* The context value of the second command is the actual command + 1*/
            if(USB_HOST_DeviceTransfer(vendorDriverObj.bulkInPipeHandle, &tempTransferHandle, 
                vendorDriverObj.buffer, 512, (uintptr_t)(vendorDriverObj.switchGetCommand + 1)) == USB_HOST_RESULT_SUCCESS)
            {
                result = true;
            }
        }
        
        if(result == false)
        {
            /* If either of the command could not be transferred, then
             * command is not in progress */
            vendorDriverObj.switchGetCommandInProgress = false;
        }
    }

    return(result);
    
}

bool APP_VENDOR_DRIVER_DeviceSwitchStatusGetInProgress(void)
{
    /* Return the status of the switch get command */
    return(vendorDriverObj.switchGetCommandInProgress);
}