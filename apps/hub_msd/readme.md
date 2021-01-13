---
parent: Harmony 3 USB Host application examples
title: HUB MSD Example 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# HUB MSD Example (hub_msd)

This application demonstrates the ability of the MPLAB Harmony USB Host Stack to interact with more than one USB Mass Storage Device through a Hub. 

## Description

This application uses USB Host stack and the Harmony Filesystem Service to copy a file from a source USB pen drive to a target USB pen drive.

## <a name="building_the_application"></a> Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_host/apps/hub_msd](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/hub_msd).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mz_ef_sk.X                 | MPLABX | PIC32MZ2048EFH144   | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](#config_16)      |
| sam_9x60_ek_iar.IAR             | IAR    | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_9x60_ek_freertos_iar.IAR    | IAR    | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_a5d2_xult_iar.IAR           | IAR    | ATSAMA5D27C         | [SAM A5D2 Xplained Ultra Board](#config_10)                                |
| sam_a5d2_xult_freertos.IAR      | IAR    | ATSAMA5D27C         | [SAM A5D2 Xplained Ultra Board](#config_10)                                |
| sam_d21_xpro.X                  | MPLABX | ATSAMD21J18A        | [SAM D21 Xplained Pro Board](#config_2)                                    |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_16"></a> [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320007)

- Connect the USB Hub to the Type A connector J5, which is located on the top side of the starter kit. 
- LED1 on the demonstration board will illuminate to indicate completion of the file transfer. 

### <a name="config_9"></a> [SAM9X60-EK Evaluation Board](https://www.microchip.com/developmenttools/ProductDetails/DT100126)

- Setup the SD card
    - Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/sam9x60ek/boot.bin).
    - Copy the downloaded boot loader binary (boot.bin) and generated application binary (harmony.bin)into the SD card.
    - Insert the SD card into the SDMMC connector J4 on the board.
- Connect the USB port J22 on board to the computer using a micro USB cable (to enable debug com port).
- Jumpers J20, J21 and J13 must be open.
- Jumper J2 and J3 must be shorted.
- Use USB Type A connector (J8) on the board to connect the USB Device to the USB Host.
- LED D1 on the demonstration board will illuminate to indicate completion of the file transfer. 
- Connect J7 to a available USB Host Port to power up the board.

    ![SAM9X60-EK Evaluation Board](images/sam9x60_evk.png)

    **Note: Reset push button on SAM9X60 EK is labeled as SW3**

### <a name="config_10"></a> [SAM A5D2 Xplained Ultra Board](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT)

- Setup the SD card
    - Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/master/boot.bin)
    - Copy the downloaded boot loader binary( boot.bin) and generated application binary (harmony.bin)into the SD card
    - Insert the SD card into the SDMMC1 slot on the board
- Connect the Debug USB port on the board to the computer using a micro USB cable
- Use "A5-USB-B" connector(J13 - Type A connector) on the board to connect the USB Device to the USB Host.
- LED D1 on the demonstration board will illuminate to indicate completion of the file transfer

### <a name="config_2"></a> [SAM D21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)

- Connect the Debug USB port on the board to the computer using a micro USB cable 
- Jumper titled "PA03 SELECT" must be shorted between PA03 and USB_ID(positions 2 and 3) 
- Use "TARGET USB" connector on the board to connect the USB Device to the the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device. 
- LED0 on the demonstration board will illuminate to indicate completion of the file transfer. 

## Running the Application

This application demonstrates the capability of the USB Host Stack to access and manage multiple USB Devices through a Hub. The demonstration application copies a file from one USB pen drive (i.e.,a USB Flash storage device) to another USB pen drive, where these pen drives are attached to a hub. 

1. Open the project in the MPLAB X IDE or IAR. Refer to [Building the Application](#building_the_application) section for available demo projects. 
1. Build the code and program the device. 
1. Connect a hub to the Host connector on the desired board. 
1. Connect a USB Pen drive containing an arbitrary file named "file.txt" to a spare port on the hub. 
1. Connect another USB pen drive to another spare port on the hub. 
1. The application will copy the file "file.txt" from the drive containing this file to the other drive. The copied file will be renamed as "newfile.txt". LED on the demonstration board will illuminate to indicate completion of the file transfer. 
1. Disconnect the drives and confirm demonstration success by inserting them into a personal computer and verifying the file transfer completed as expected. 
1. The demonstration application will always be in state where it waits for two pen drives to be connected to the hub and at least one of these pen drives contains a file named "file.txt".

