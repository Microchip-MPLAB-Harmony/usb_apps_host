---
parent: Harmony 3 USB Host application examples
title: CDC MSD Example 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# CDC MSD Example (cdc_msd)

This application demonstrates the ability of the MPLAB Harmony USB Host Stack to support more than one device type in a USB Host Application.  

## Description

This application creates a USB Host that can recognize and enumerate a CDC USB Device and MSC USB Device

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_host/apps/cdc_msd](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/apps/cdc_msd).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mz_ef_curiosity_2_0.X      | MPLABX | PIC32MZ2048EFM144   | [Curiosity PIC32MZ EF 2.0 Development Board](#config_15)                   |
| pic32mx470_curiosity.X          | MPLABX | PIC32MX470F512H     | [PIC32MX Curiosity Development Board](#config_13)                          |
| sam_9x75_eb.X                   | MPLABX | SAM9X75             | [SAM9X75-DDR3-EB Evaluation Board](#config_22)                             |
| sam_d21_xpro.X                  | MPLABX | ATSAMD21J18A        | [SAMD21 Xplained Pro Board](#config_2)                                    |
| sam_e70_xult.X                  | MPLABX | ATSAME70Q21B        | [SAME70 Xplained Ultra Board](#config_4)                                  |
| sam_e70_xult_freertos.X         | MPLABX | ATSAME70Q21B        | [SAME70 Xplained Ultra Board](#config_4)                                  |
| pic32cz_ca80_curiosity_ultra.X  | MPLABX | PIC32CZ8110CA80208  | [PIC32CZ Curiosity Development Board](#config_23)           |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_23"></a> PIC32CZ CA80 Curiosity Development Board
- Connect the USB device to the connector (J102) using a USB Type-A Female to micro-B male cable  (This cable is not included in the kit). 
- LED0 on the board is controlled by the attached USB CDC device when a CDC device is attached. When a Mass Storage Device is attached, it indicates file write completion.


### <a name="config_15"></a> [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)

- Use the USB micro-B port J201 to connect the USB Device to the board. A USB Type-A Female to micro-B male cable will be needed to connect the device (This cable is not included in the kit).
- LED1 on the board is controlled by the attached USB CDC device when a CDC device is attached. When a Mass Storage Device is attached, it indicates file write completion.

### <a name="config_13"></a> [Curiosity PIC32MX470 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/dm320103)

- Install a jumper in the J13 header to drive the VBUS line in Host mode.
- Connect the USB device to the USB micro-AB connector J12 using a USB Type-A Female to micro-B male cable  (This cable is not included in the kit). 
- LED1 on the board is controlled by the attached USB CDC device when a CDC device is attached. When a Mass Storage Device is attached, it indicates file write completion.

### <a name="config_22"></a> [SAM9X75-DDR3-EB Evaluation Board]()

- Powered the board with an external power supply (or use the micro AB connector).
- Setup the SD card 
    - Download harmony MPU bootstrap loader from this [location](firmware/at91bootstrap_sam_9x75_eb.X/build/binaries/boot.bin).
    - Copy the downloaded boot loader binary (boot.bin) and generated application binary (harmony.bin) into the SD card.
    - Insert the SD card into the SDMMC connector (SDMMC0) on the board.
    - Reset the board by pressing the Push Button RESET, then START. 
- Connect an USB to serial cable to DBGU0 (to enable debug com port).
- Connect the USB device to the Type-A connector or to the micro AB with a specific dongle (in these case the need to be powered by the external power supply).
- LED near VDDCORE inscription on the board indicates the file write is complete. 

    ![SAM9X75-DDR3-EB Evaluation Board](images/sam9x75_ddr3_eb.png)

### <a name="config_2"></a> [SAMD21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)

- Jumper titled "PA03 SELECT" must be shorted between PA03 and USB_ID(positions 2 and 3).
- Use "TARGET USB" connector on the board to connect the USB Device to the USB Host PC. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 on the board is controlled by the attached USB CDC device when a CDC device is attached. When a Mass Storage Device is attached, it indicates file write completion.

### <a name="config_4"></a> [SAME70 Xplained Ultra Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320113)

- Jumper J203 must be shorted between PB08 and LED2(positions 1 and 2). 
- Use TARGET USB J200 connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device. 
- LED3 on the board is controlled by the attached USB CDC device when a CDC device is attached. When a Mass Storage Device is attached, it indicates file write completion. 
### <a name="config_22"></a> [Curiosity Pro PIC32CM LE00 Development Board](https://www.microchip.com/en-us/development-tool/EV80P12A)

- Powered the board by connecting an host to "DEBUG USB" (J300) connector.
- Connect the USB device to the USB Host "TARGET USB" (J200) using a USB Type-A Female to micro-B male cable (This cable is not included in the kit).
- LED0 on the board is controlled by the attached USB CDC device.

## Running the Application

This demonstration application creates a USB Host application that enumerates a CDC and a MSD Host. This application combines the functionality of the Host cdc_basic and msd_basic demonstration applications into one application. If a CDC device is connected, the demonstration application behaves like the cdc_basic host application. If a MSD device is connected, the demonstration application behaves like the msd_basic host application. 

To exercise the CDC Host capabilities, refer to local documentation from [usb_apps_host/apps/cdc_basic](..\..\apps\cdc_basic\readme.md). The documentation is also available in the github path [usb_apps_host/apps/cdc_basic](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/apps/cdc_basic).
To exercise the MSD Host capabilities, refer to local documentation from [usb_apps_host/apps/msd_basic](..\..\apps\msd_basic\readme.md). The documentation is also available in the github path [usb_apps_host/apps/msd_basic](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/apps/msd_basic).
