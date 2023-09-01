---
parent: Harmony 3 USB Host application example
title: Vendor Example 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Vendor Example (vendor)

This application demonstrates how to interface with a USB device using the generic host client driver. The application includes a generic client driver example for a vendor-specific USB device.

## Description

This application demonstrates how to interface with a USB device using the generic host client driver. The application includes a generic client driver example for a vendor-specific USB device.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_host/apps/vendor](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/apps/vendor).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| sam_e54_xpro.X                  | MPLABX | ATSAME54P20A        | [SAME54 Xplained Pro Board](#config_3)                                    |

## <a name="config_title"></a> Configuring the Hardware


### <a name="config_3"></a> [SAM E54 Xplained Pro Board](https://www.microchip.com/developmenttools/productdetails/atsame54-xpro)

- Connect the USB device to the "TARGET USB" connector using a USB Type-A Female to micro-B male cable  (This cable is not included in the kit).
- Press the push button SW0 to toggle the LED on the USB Vendor Device. 
- The LED0 indicates the status of the push button pressed at the USB Vendor Device. 



## Running the Application

This application demonstrates the use of the Generic Host client Driver to communicate with a USB device. The application uses the USB Host layer and Generic client driver.

1. Open the project with the appropriate IDE. Compile the project and program the target device.
1. Connect the serial interface on the board to a PC. On the PC, launch a terminal emulator, such as Tera Term, and select the appropriate COM port and set the serial port settings to 115200-N-1.
1. The serial terminal emulator program will display the message "APP: Waiting for device to be available". 
1. Follow the directions for setting up and running the USB device demonstration "usb_apps_device\apps\vendor". 
1. Connect the USB Device connector of the Vendor USB Device board to the USB Host Target board. Refer to the [Configuring the Hardware](#config_title) section for any converter requirements.
1. The serial terminal emulator program will display the message "APP: Device is available".
1. Pressing the push button on the Host demo board will toggle the LED on the USB Vendor Device. The serial terminal emulator program will display the message "APP: Switch was pressed. Sending LED toggle command to the device.".
1. The LED on the Host board tracks the push button pressed status on the USB Device Vendor device. Pressing the push button on the Vendor device turns on the LED on the Host board. The serial terminal emulator program will display the message "APP: Change detected in the device switch status".
