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
| pic32mk_gp_db.X                 | MPLABX | PIC32MK1024GPE100   | [PIC32MK General Purpose (GP) Development Board](#config_12)               |
| pic32mk_gp_db_freertos.X        | MPLABX | PIC32MK1024GPE100   | [PIC32MK General Purpose (GP) Development Board](#config_12)               |
| pic32mx470_curiosity.X          | MPLABX | PIC32MX470F512H     | [PIC32MX Curiosity Development Board](#config_13)                          |
| pic32mx470_curiosity_freertos.X | MPLABX | PIC32MX470F512H     | [PIC32MX Curiosity Development Board](#config_13)                          |
| pic32mz_das_sk.X                | MPLABX | PIC32MZ2064DAS169   | [PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit](#config_14) |
| pic32mz_ef_curiosity_2.X        | MPLABX | PIC32MZ2048EFM144   | [Curiosity PIC32MZ EF 2.0 Development Board](#config_15)                   |
| pic32mz_ef_sk.X                 | MPLABX | PIC32MZ2048EFH144   | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](#config_16)      |
| pic32mz_ef_sk_freertos.X        | MPLABX | PIC32MZ2048EFH144   | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](#config_16)      |
| pic32mz_w1_curiosity.X          | MPLABX | PIC32MZ1025W104132  | [Curiosity PIC32MZ W1 Development Board](#config_17)                       |
| sam_9x60_ek.X                   | MPLABX | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_9x60_ek_iar.IAR             | IAR    | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_9x60_ek_freertos_iar.IAR    | IAR    | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_a5d2_xult_iar.IAR           | IAR    | ATSAMA5D27C         | [SAM A5D2 Xplained Ultra Board](#config_10)                                |
| sam_a5d2_xult_freertos_iar.IAR  | IAR    | ATSAMA5D27C         | [SAM A5D2 Xplained Ultra Board](#config_10)                                |
| sam_d21_xpro.X                  | MPLABX | ATSAMD21J18A        | [SAM D21 Xplained Pro Board](#config_2)                                    |
| sam_d21_xpro_iar.IAR            | IAR    | ATSAMD21J18A        | [SAM D21 Xplained Pro Board](#config_2)                                    |
| sam_e54_xpro.X                  | MPLABX | ATSAME54P20A        | [SAM E54 Xplained Pro Board](#config_3)                                    |
| sam_e54_xpro_iar.IAR            | IAR    | ATSAME54P20A        | [SAM E54 Xplained Pro Board](#config_3)                                    |
| sam_e70_xult.X                  | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_e70_xult_freertos.X         | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_e70_xult_iar.IAR            | IAR    | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_g55_xpro.X                  | MPLABX | ATSAMG55J19         | [SAM G55 Xplained Pro Board](#config_6)                                    |
| sam_g55_xpro_freertos.X         | MPLABX | ATSAMG55J19         | [SAM G55 Xplained Pro Board](#config_6)                                    |
| sam_l21_xpro.X                  | MPLABX | ATSAML21J18B        | [SAM L21 Xplained Pro Board](#config_7)                                    |
| sam_v71_xult_freertos.X         | MPLABX | ATSAMV71Q21B        | [SAM V71 Xplained Ultra board](#config_5)                                   |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_12"></a> [PIC32MK General Purpose (GP) Development Board](https://www.microchip.com/developmenttools/ProductDetails/dm320106)

- Connect the device to the Type A connector J5, which is located on the top side of the starter kit.
- LED1 indicates the file write is complete.

### <a name="config_13"></a> [PIC32MX Curiosity Development Board](https://www.microchip.com/Developmenttools/ProductDetails/dm320103)

- Connect the device to theUSB micro-B port J12, which is located on the top side of the starter kit.
- LED1 indicates the file write is complete.

### <a name="config_14"></a> [PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320010-C)

- Connect the device to the Type A connector J7, which is located on the top side of the starter kit.
- LED1 indicates the file write is complete.

### <a name="config_15"></a> [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)

- Use "TARGET USB" connector (J201) on the board to connect the USB Device to the the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED1 indicates the file write is complete.

### <a name="config_16"></a> [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320007)

- Connect the device to the Type A connector J5, which is located on the top side of the starter kit.
- LED1 indicates the file write is complete.

### <a name="config_17"></a> [Curiosity PIC32MZ W1 Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320104)

- Jumper J205 must be shorted.
- Connect the device to the Type A connector J204.
- The LED D204 indicates the file write is complete.

    ![Curiosity PIC32MZ W1 Development board](images/usb_apps_host_figure_1.png)

### <a name="config_9"></a> [SAM9X60-EK Evaluation Board](https://www.microchip.com/developmenttools/ProductDetails/DT100126)

- Setup the SD card 
    - Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/sam9x60ek/boot.bin).
    - Copy the downloaded boot loader binary (boot.bin) and generated application binary (harmony.bin)into the SD card.
    - Insert the SD card into the SDMMC connector J4 on the board.
- Connect the USB port J22 on board to the computer using a micro USB cable (to enable debug com port).
- Jumpers J20, J21 and J13 must be open.
- Jumper J2 and J3 must be shorted.
- Use USB Type A connector (J8) on the board to connect the USB Device to the USB Host.
- LED D1 indicates indicates the file write is complete. 

    ![SAM9X60-EK Evaluation Board](images/sam9x60_evk.png)

    **Note:** Reset push button on SAM9X60 EK is labeled as SW3

### <a name="config_10"></a> [SAM A5D2 Xplained Ultra Board](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT)

- Setup the SD card 
    - Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/master/boot.bin).
    - Copy the downloaded boot loader binary( boot.bin) and generated application binary (harmony.bin)into the SD card.
    - Insert the SD card into the SDMMC1 slot on the board.
- Connect the Debug USB port on the board to the computer using a micro USB cable.
- Use "A5-USB-B" connector(J13 - Type A connector) on the board to connect the USB Device to the the USB Host.
- RGB LED turning to Green indicates the file write is complete.

### <a name="config_2"></a> [SAM D21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)

- Jumper titled "PA03 SELECT" must be shorted between PA03 and USB_ID(positions 2 and 3).
- Use "TARGET USB" connector on the board to connect the USB Device to the the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 indicates the file write is complete.

### <a name="config_3"></a> [SAM E54 Xplained Pro Board](https://www.microchip.com/developmenttools/productdetails/atsame54-xpro)

- Use "TARGET USB" connector on the board to connect the USB Device to the the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 indicates the file write is complete.

### <a name="config_4"></a> [SAM E70 Xplained Ultra Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320113)

- Jumper J203 must be shorted between PB08 and LED2(positions 1 and 2).
- Use TARGET USB J200 connector on the board to connect the USB Device to the the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED3 indicates the file write is complete.

### <a name="config_6"></a> [SAMG55 Xplained Pro Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMG55-XPRO)

- Chip Erase Jumper must be open.
- Use TARGET USB connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 indicates the file write is complete.

### <a name="config_7"></a> [SAM L21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAML21-XPRO-B)

- Use "TARGET USB" connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 indicates the file write is complete.

### <a name="config_5"></a> [SAM V71 Xplained Ultra Board](https://www.microchip.com/developmenttools/ProductDetails/atsamv71-xult)

- Jumper titled "USB VBUS" must be shorted between PC09 and LED1(positions 1 and 2) 
- Use TARGET USB connector on the board to connect the USB Device to the the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device. 
- LED0 indicates the file write is complete. 

## Running the Application

This application demonstrates the use of the MSD Host Class Driver to write a file to USB Flash drive. The application uses the USB Host_layer, MSD class driver and the MPLAB Harmony File System Framework to enumerate a USB Flash drive and to write a file to it.

1. Open the project with appropriate IDE. Compile the project and program the target device.
1. With the code running, attach a USB Flash drive to the Host connector on the desired starter kit. 
1. The demonstration application will then create a file named file.txt. It will then write the text "Hello World" to this file, and then close the file. 
1. The LED on the selected hardware will indicate the status of the operation. Refer to the Configuring the Hardware instruction for details. 
1. The USB Flash drive can then be attached to a USB Host personal computer to verify the demonstration application operation. 
1. Steps 3 through 6 can be repeated. 
1. If the USB Flash drive already contains a file with the name file.txt, the demonstration application will append the text "Hello World" to the end of the file contents.