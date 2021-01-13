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

Path of the application within the repository is [usb_apps_host/apps/cdc_msd](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/cdc_msd).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| sam_d21_xpro.X                  | MPLABX | ATSAMD21J18A        | [SAM D21 Xplained Pro Board](#config_2)                                    |
| sam_e70_xult.X                  | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_e70_xult_freertos.X         | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_2"></a> [SAM D21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)

- Jumper titled "PA03 SELECT" must be shorted between PA03 and USB_ID(positions 2 and 3).
- Use "TARGET USB" connector on the board to connect the USB Device to the USB Host PC. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 on the board is controlled by the attached USB CDC device when a CDC device is attached. When a Mass Storage Device is attached, it indicates file write completion.

### <a name="config_4"></a> [SAM E70 Xplained Ultra Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320113)

- Jumper J203 must be shorted between PB08 and LED2(positions 1 and 2). 
- LED2 indicates a Device Connection. (Attached device has been successfully enumerated and configured). 
- Use TARGET USB J200 connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device. 
- LED3 on the board is controlled by the attached USB CDC device when a CDC device is attached. When a Mass Storage Device is attached, it indicates file write completion. 

## Running the Application

This demonstration application creates a USB Host application that enumerates a CDC and a MSD Host. This application combines the functionality of the Host cdc_basic and msd_basic demonstration applications into one application. If a CDC device is connected, the demonstration application behaves like the cdc_basic host application. If a MSD device is connected, the demonstration application behaves like the msd_basic host application. 

To exercise the CDC Host capabilities, refer to local documentation from [usb_apps_host/apps/cdc_basic](..\..\apps\cdc_basic\readme.md). The documentation is also available in the github path [usb_apps_host/apps/cdc_basic](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/cdc_basic).
To exercise the MSD Host capabilities, refer to local documentation from [usb_apps_host/apps/msd_basic](..\..\apps\msd_basic\readme.md). The documentation is also available in the github path [usb_apps_host/apps/msd_basic](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/msd_basic).
