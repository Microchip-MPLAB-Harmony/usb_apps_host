---
parent: Harmony 3 USB Host application examples
title: HUB CDC HID Example 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# HUB CDC HID Example (hub_cdc_hid)

This application demonstrates the ability of the MPLAB Harmony USB Host Stack to access and manage multiple USB Devices through a Hub.

## Description

This application creates a USB Host that can recognize and enumerate a CDC Emulator USB Device and a HID USB Mouse connected via an external Hub. The host will demonstrate the communication from the CDC emulator device and the HID mouse.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_host/apps/hub_cdc_hid](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/hub_cdc_hid).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mz_ef_curiosity_2_0.X      | MPLABX | PIC32MZ2048EFM144   | [Curiosity PIC32MZ EF 2.0 Development Board](#config_15)                   |
| pic32mz_ef_sk.X                 | MPLABX | PIC32MZ2048EFH144   | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](#config_16)      |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_15"></a> [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)

- Connect the USB device to the "TARGET USB" connector (J201) using a USB Type-A Female to micro-B male cable  (This cable is not included in the kit). 
- LED1 is controlled by the attched USB Mouse. 
- LED1, LED2, and LED3 are controlled by the attched USB CDC Device. 


### <a name="config_16"></a> [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320007)

- Connect the USB Hub to the Type A connector J5, which is located on the top side of the starter kit. 
- LED1 is controlled by the attched USB Mouse. 
- LED1, LED2, and LED3 are controlled by the attched USB CDC Device. 

## Running the Application

This application demonstrates the capability of the USB Host Stack to access and manage multiple USB Devices through a Hub. The demonstration application enumerates a HID mouse and CDC emulator device via an external hub. The host will demonstrate the communication from the CDC emulator device and the HID mouse. 

Open the project in MPLAB X IDE and select the desired project configuration. 

1. Build the code and program the device. 
2. Connect a hub to the Host connector on the desired board. 
3. Connect a mouse to a spare port on the hub. 
4. Connect the CDC emulator device to another spare port on the hub. Follow the directions for setting up and running the cdc_serial_emulator USB device demonstration. On the personal computer, open a serial terminal and set the serial Baudrate to 9600. 
5. At the prompt, (LED:), enter 1, 2, or 3 to toggle the corresponding LEDs on the starter kit. 
6. Click the mouse Left and Right buttons. This will toggle LED on the demo board.


