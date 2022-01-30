---
parent: Harmony 3 USB Host application examples
title: MSD Basic Example 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# MSD Basic Example (msd_basic)

This application demonstrates the ability of the MPLAB Harmony USB Host Stack to support MSD Host Class Driver . It demonstrates the feature with an application to read / write a file to a USB Flash drive.

## Description

This application demonstrates the use of the MSD Host Class Driver to write a file to a USB Flash drive. The application uses the USB Host_layer , MSD class driver and the MPLAB Harmony File System Framework to enumerate a USB Flash drive and to write a file to it.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_host/apps/msd_basic](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/msd_basic).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| sam_a7g5_ek.X                   | MPLABX | SAMA7G54            | [SAMA7G5 EK Board](#config_21)                                             |
| sam_9x60_ek.X                   | MPLABX | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_9"></a> [SAM9X60-EK Evaluation Board](https://www.microchip.com/developmenttools/ProductDetails/DT100126)
- Setup the SD card 
    - Download harmony MPU bootstrap loader from this [location](firmware/at91bootstrap_sam_9x60_ek.X/binaries/boot.bin).
    - Copy the downloaded boot loader binary (boot.bin) and generated application binary (harmony.bin) into the SD card.
    - Insert the SD card into the SDMMC connector J4 on the board.
    - Reset the board by pressing the Push Button SW3. 
- Jumpers J20, J21, and J13 must be open.
- Jumper J2 and J3 must be shorted.
- Connect the External Power Jack (J1) to a 5V power supply. 
- Connect 2 USB devices to the USB Host on the board:
    - Stacked type-A USB (J8A)
    - Stacked type-A USB (J8B)
- LED D1 on the board indicates the file write is complete.
    ![SAM9X60-EK Evaluation Board](images/sam9x60_evk.png)

    **Note: Reset push button on SAM9X60 EK is labeled as SW3**

### <a name="config_21"></a> [SAMA7G5-EK Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/TOBEADDED)

- Powered the board with an external power supply (J1).
- Setup the SD card 
    - Download harmony MPU bootstrap loader from this [location](firmware/at91bootstrap_sam_a7g5_ek.X/build/binaries/boot.bin).
    - Copy the downloaded boot loader binary (boot.bin) and generated application binary (harmony.bin) into the SD card.
    - Insert the SD card into the SD Card Connector (J4) on the board.
    - Reset the board by pressing the Reset Button (nRST) 
- Press the "nSTART" button to activate board start-up.  
- Connect 2 USB devices to the USB Host on the board:
    - Type-A connector USBC (J9)
    - Type C Connector USBB (J8)
    - Type micro A/B connector USBA (J7)
- RGB LED turning to Green indicates the file write is complete.

## Running the Application

This application demonstrates the use of the MSD Host Class Driver to write a file to USB Flash drive. The application uses the USB Host_layer, MSD class driver and the MPLAB Harmony File System Framework to enumerate a USB Flash drive and to write a file to it.

1. Open the project with appropriate IDE. Compile the project and program the target device.
1. With the code running, attach a USB Flash drive to the Host connector on the desired starter kit containing a non empty file named file.txt
1. Attach a second empty USB Flash drive to another Host connector on the desired starter kit
1. The demonstration application will then copy the file.txt from the first USB Flash drive to the second. 
1. The LED on the selected hardware will indicate the status of the operation. 
1. The second USB Flash drive can then be attached to a USB Host personal computer to verify the demonstration application operation. 