---
parent: Harmony 3 USB Host application examples
title: HID Basic Keyboard Example 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# HID Basic Keyboard Example (hid_basic_keyboard)

This application demonstrates the ability of the MPLAB Harmony USB Host HID Client Driver to support to enumerate and operate a HID keyboard device. 

## Description

This application creates a USB Host application that uses the USB Host Layer, HID Client driver and HID Keyboard Usage driver to enumerate a USB keyboard and understand keyboard press release events. The keyboard events are displayed using a terminal emulator on a personal computer.

## <a name="building_the_application"></a> Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_host/apps/hid_basic_keyboard](https://github.com/Microchip-MPLAB-Harmony/usb_apps_device/apps/cdc_com_port_single).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| sam_d21_xpro.X                  | MPLABX | ATSAMD21J18A        | [SAM D21 Xplained Pro Board](#config_2)                                    |
| sam_e70_xult.X                  | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_e70_xult_freertos.X         | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_g55_xpro.X                  | MPLABX | ATSAMG55J19         | [SAM G55 Xplained Pro Board](#config_6)                                    |
| sam_g55_xpro_freertos.X         | MPLABX | ATSAMG55J19         | [SAM G55 Xplained Pro Board](#config_6)                                    |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_2"></a> [SAM D21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)

- Jumper titled "PA03 SELECT" must be shorted between PA03 and USB_ID(positions 2 and 3)
- Use "TARGET USB" connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 on the board is controlled by the attached USB CDC device.

### <a name="config_4"></a> [SAM E70 Xplained Ultra Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320113)

- Jumper J203 must be shorted between PB08 and LED2(positions 1 and 2).
- Use "TARGET USB" J200 connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED3 on the board is controlled by the attached USB CDC device.

### <a name="config_6"></a> [SAMG55 Xplained Pro Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMG55-XPRO)

- Chip Erase Jumper must be open.
- Use TARGET USB connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 on the board is controlled by the attached USB CDC device.

## Running the Application

1. Open the project with appropriate IDE. Compile the project and program the target device.
1. Connect the serial interface on the board to a PC. On the PC, launch a terminal emulator, such as Tera Term, and select the appropriate COM port and set the serial port settings to 115200-N-1. 
1. If a USB keyboard is not connected to the Embedded USB Host, the terminal emulator window will show the Connect Keyboard prompt. 
1. Attach a USB keyboard to the Host connector of the target hardware. The message, Keyboard Connected, will appear in the terminal emulator window. Refer to the [Configuring the Hardware](#config_title) section for any converter requirements. 
1. Begin typing on the keyboard and the appropriate keys should be displayed on the serial terminal. Subsequent press and release of modifier keys (i.e., CAPS LOCK, NUM LOCK, etc.) will result in the appropriate keyboard LEDs to turning ON and OFF. 
1. Disconnecting the keyboard will result in the message, Connect Keyboard.

    ![Found New Hardware Wizard](images/hid_basic_keyboard_figure_1.png)
