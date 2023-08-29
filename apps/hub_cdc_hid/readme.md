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

Path of the application within the repository is [usb_apps_host/apps/hub_cdc_hid](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/apps/hub_cdc_hid).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mz_ef_curiosity_2_0.X      | MPLABX | PIC32MZ2048EFM144   | [Curiosity PIC32MZ EF 2.0 Development Board](#config_15)                   |
| pic32mz_ef_sk.X                 | MPLABX | PIC32MZ2048EFH144   | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](#config_16)      |
| sam_9x75_eb.X                   | MPLABX | SAM9X75             | [SAM9X75-DDR3-EB Evaluation Board](#config_22)                             |
| sam_g55_xpro.X                  | MPLABX | ATSAMG55J19         | [SAMG55 Xplained Pro Board](#config_6)                                     |
| pic32cz_ca80_curiosity_ultra.X  | MPLABX | PIC32CZ8110CA80208  | [PIC32CZ Curiosity Development Board](#config_23)                          |
| pic32ck_gc01_curiosity_ultra.X  | MPLABX | PIC32CK2051GC01144  | [PIC32CK Curiosity Development Board](#config_24)           |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_23"></a> PIC32CZ CA80 Curiosity Development Board
- A commercially available USB Mouse is required to run this demonstration application. 
- Connect the USB Hub to the connector (J102) using a USB Type-A Female to micro-B male cable  (This cable is not included in the kit). 
- LED0 is controlled by the attached USB Mouse. 
- LED0 is also controlled by the attached USB CDC Device. 

### <a name="config_24"></a> PIC32CK Curiosity Development Board
- A commercially available USB Mouse is required to run this demonstration application.
- Connect the USB Hub to the USB Type-C connector (J202). A USB Type-C to Type-A Female adapter is required to connect the USB device to the board. (This adapter is not included in the kit) 
- LED1 is controlled by the attached USB Mouse. 
- LED1 is also controlled by the attached USB CDC Device. 

### <a name="config_22"></a> [SAM9X75-DDR3-EB Evaluation Board]()

- Powered the board with an external power supply (or use the micro AB connector).
- Setup the SD card (Note: exFAT formatted SD Cards are not supported) 
    - Download harmony MPU bootstrap loader from this [location](firmware/at91bootstrap_sam_9x75_eb.X/build/binaries/boot.bin).
    - Copy the downloaded boot loader binary (boot.bin) and generated application binary (harmony.bin) into the SD card.
    - Insert the SD card into the SDMMC connector (SDMMC0) on the board.
    - Reset the board by pressing the Push Button RESET, then START. 
- Connect an USB to serial cable to DBGU0 (to enable debug com port).
- Connect the USB Hub to the Type-A connector or to the micro AB with a specific dongle (in these case the need to be powered by the external power supply).
- LED near VDDCORE inscription on the board is controlled by the attached USB Mouse. 
- LED near VDDCORE inscription on the board is also controlled by the attached USB CDC device.

    ![SAM9X75-DDR3-EB Evaluation Board](images/sam9x75_ddr3_eb.png)



### <a name="config_6"></a> [SAMG55 Xplained Pro Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMG55-XPRO)

- Chip Erase Jumper must be open.
- Connect the USB device to the "TARGET USB" connector using a USB Type-A Female to micro-B male cable  (This cable is not included in the kit).
- LED0 on the board is controlled by the attached USB CDC device.

### <a name="config_15"></a> [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)

- Connect the USB device to the "TARGET USB" connector (J201) using a USB Type-A Female to micro-B male cable  (This cable is not included in the kit). 
- LED1 is controlled by the attached USB Mouse. 
- LED1, LED2, and LED3 are controlled by the attached USB CDC Device. 

### <a name="config_16"></a> [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320007)

- Connect the USB Hub to the Type A connector J5, which is located on the top side of the starter kit. 
- LED1 is controlled by the attached USB Mouse. 
- LED1, LED2, and LED3 are controlled by the attached USB CDC Device. 

## Running the Application

This application demonstrates the capability of the USB Host Stack to access and manage multiple USB Devices through a Hub. The demonstration application enumerates a HID mouse and CDC emulator device via an external hub. The host will demonstrate the communication from the CDC emulator device and the HID mouse. 

1. Open MPLAB X IDE the project corresponding to the selected board. Refer to the [Building the Application](#building_the_application) section for details.
1. Build the code and program the device. 
1. Connect a USB hub to the Host connector on the desired board. 
1. Connect a USB mouse to a spare port on the hub.
1. Click the mouse Left and Right buttons. This will toggle LED on the demo board. 
1. Follow the directions for setting up and running the cdc_serial_emulator USB device demonstration. Start a terminal program on the USB Host personal computer and select the Serial-to-USB Dongle as the communication port. Select the baud rate as 9600, no parity, One Stop bit, and no flow control.
1. Connect the CDC emulator device to another spare port on the hub. 
1. The LED on the USB host board will turn on as soon as the CDC device is connected. Refer to the [Configuring the Hardware](#config_title) section for details on the relevant LED.  
1. The terminal emulator program will immediately display the text "LED ON."
1. Pressing the key "1" on the terminal will cause the LED on the Host USB board to switch on.  Pressing any other key on the terminal message will cause the LED to switch off.
1. The above step can be repeated.
1. Ensure that the CDC serial emulator device is completely powered off before detaching and reattaching to the embedded CDC host. 


