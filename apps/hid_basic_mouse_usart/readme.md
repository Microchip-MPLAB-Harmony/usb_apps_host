---
parent: Harmony 3 USB Host application examples
title: HID Basic Mouse USART Example 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# HID Basic Mouse USART Example (hid_basic_mouse_usart)

This application demonstrates the use of the USB HID Host Client Driver to enumerate and operate a HID USB Mouse device. 

## Description

This application uses the USB Host layer, HID Client driver and HID Mouse Usage driver to enumerate a USB Mouse and detect Mouse button press release events. The Mouse events are displayed using a terminal emulator on a personal computer.

## <a name="building_the_application"></a>Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_host/apps/hid_basic_mouse_usart](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/hid_basic_mouse_usart).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mz_ef_curiosity_2_0.X      | MPLABX | PIC32MZ2048EFM144   | [Curiosity PIC32MZ EF 2.0 Development Board](#config_15)                   |
| sam_9x60_ek_iar.IAR             | IAR    | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_9x60_ek_freertos_iar.IAR    | IAR    | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_a5d2_xult_iar.IAR           | IAR    | ATSAMA5D27C         | [SAM A5D2 Xplained Ultra Board](#config_10)                                |
| sam_a5d2_xult_freertos.IAR      | IAR    | ATSAMA5D27C         | [SAM A5D2 Xplained Ultra Board](#config_10)                                |
| sam_d21_xpro.X                  | MPLABX | ATSAMD21J18A        | [SAM D21 Xplained Pro Board](#config_2)                                    |
| sam_e70_xult.X                  | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_e70_xult_freertos.X         | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_g55_xpro.X                  | MPLABX | ATSAMG55J19         | [SAM G55 Xplained Pro Board](#config_6)                                    |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_15"></a> [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)

- Use the USB micro-B port J201 to connect the USB Device to the USB Host PC.
- LED1 indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).
- A commercially available USB Mouse will be needed. 
- The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC. 

### <a name="config_9"></a> [SAM9X60-EK Evaluation Board](https://www.microchip.com/developmenttools/ProductDetails/DT100126)

- Setup the SD card
    - Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/sam9x60ek/boot.bin).
    - Copy the downloaded boot loader binary (boot.bin) and generated application binary (harmony.bin)into the SD card.
    - Insert the SD card into the SDMMC connector J4 on the board.
- Connect the USB port J22 on board to the computer using a micro USB cable (to enable debug com port).
- Jumpers J20, J21 and J13 must be open.
- Jumper J2 and J3 must be shorted.
- Use USB Type A connector (J8) on the board to connect the USB Device to the USB Host.
- LED D1 indicates a Device Connection. (Attached device has been successfully enumerated and configured).
- Connect J7 to a available USB Host Port to power up the board.

    ![SAM9X60-EK Evaluation Board](images/sam9x60_evk.png)

    **Note: Reset push button on SAM9X60 EK is labeled as SW3**

### <a name="config_10"></a> [SAM A5D2 Xplained Ultra Board](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT)

- Setup the SD card
    - Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/master/boot.bin)
    - Copy the downloaded boot loader binary( boot.bin) and generated application binary (harmony.bin)into the SD card
    - Insert the SD card into the SDMMC1 slot on the board
- Open the jumper JP2(DEBUG_DIS) 
- Connect the Debug USB port on the board to the computer using a micro USB cable 
- Use "A5-USB-B" connector(J13 - Type A connector) on the board to connect the USB Device to the USB Host. 
- RGB LED indicates a Device Connection. (Attached device has been successfully enumerated and configured). 
- A commercially available USB Mouse will be needed. 
- The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC. 

### <a name="config_2"></a> [SAM D21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)

- Jumper titled "PA03 SELECT" must be shorted between PA03 and USB_ID(positions 2 and 3)
- Use "TARGET USB" connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 indicates a Device Connection. (Attached device has been successfully enumerated and configured). This LED is also toggled on Mouse Button press event.
- A commercially available USB Mouse will be needed. 
- The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC. 

### <a name="config_4"></a> [SAM E70 Xplained Ultra Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320113)

- Jumper J203 must be shorted between PB08 and LED2(positions 1 and 2).
- Use "TARGET USB" J200 connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED3 indicates a Device Connection. (Attached device has been successfully enumerated and configured). This LED is also toggled on Mouse Button press event.
- A commercially available USB Mouse will be needed. 
- The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC. 

### <a name="config_6"></a> [SAMG55 Xplained Pro Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMG55-XPRO)

- Chip Erase Jumper must be open.
- Use TARGET USB connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 indicates a Device Connection. (Attached device has been successfully enumerated and configured). This LED is also toggled on Mouse Button press event.
- A commercially available USB Mouse will be needed. 
- The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC. 

## Running the Application

1. Open the project with appropriate IDE. Compile the project and program the target device.
1. Launch a terminal emulator, such as Tera Term. Select the appropriate COM port and set the serial port settings to 115200-N-1. 
1. If a USB mouse is not connected to the Host connector, the serial terminal emulator window will show the "Connect Mouse" prompt. 
1. Attach a USB mouse to the Host connector of the target hardware. Refer to the [Configuring the Hardware](#config_title) section for any converter requirements. The message, "Mouse Connected", will display in the serial terminal emulator window. 
1. Begin moving the mouse and the appropriate relative coordinate changes for X,Y, and Z axes should be displayed in the serial terminal window. 
1. Click the mouse button to toggle LEDs on the board. Refer to the Configuring the Hardware section for details on the relevant LED. 
1. Disconnecting the mouse will result in the message, "Connect Mouse", to reappear on the serial console. 

    ![Found New Hardware Wizard](images/hid_basic_mouse_usart_figure_1.png)
