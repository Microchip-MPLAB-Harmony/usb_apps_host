---
parent: Harmony 3 USB Host application examples
title: CDC Basic Example 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# CDC Basic Example (cdc_basic)

This application demonstrates the ability of the MPLAB Harmony USB Host Stack CDC Client Driver to enumerate and operate a standard CDC USB Device. 

## Description

This application uses the USB Host Layer and CDC Client driver to enumerate a standard CDC USB device. The demonstration host application then operates and uses the functionality of the attached CDC Device.

## <a name="building_the_application"></a> Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_host/apps/cdc_basic](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/cdc_basic).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mz_ef_curiosity_2_0.X      | MPLABX | PIC32MZ2048EFM144    | [Curiosity PIC32MZ EF 2.0 Development Board](#config_15) |
| pic32mz_ef_sk.X                 | MPLABX | PIC32MZ2048EFH144   | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](#config_16)      |
| pic32mz_ef_sk_freertos.X        | MPLABX | PIC32MZ2048EFH144   | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](#config_16)      |
| sam_9x60_ek_iar.IAR             | IAR    | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_9x60_ek_freertos_iar.IAR    | IAR    | SAM9X60             | [SAM9X60-EK Evaluation Board](#config_9)                                   |
| sam_a5d2_xult_iar.IAR           | IAR    | ATSAMA5D27C         | [SAM A5D2 Xplained Ultra Board](#config_10)                                |
| sam_a5d2_xult_freertos_iar.IAR  | IAR    | ATSAMA5D27C         | [SAM A5D2 Xplained Ultra Board](#config_10)                                |
| sam_d21_xpro.X                  | MPLABX | ATSAMD21J18A        | [SAM D21 Xplained Pro Board](#config_2)                                    |
| sam_e54_xpro.X                  | MPLABX | ATSAME54P20A        | [SAM E54 Xplained Pro Board](#config_3)                                    |
| sam_e70_xult.X                  | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_e70_xult_freertos.X         | MPLABX | ATSAME70Q21B        | [SAM E70 Xplained Ultra Board](#config_4)                                  |
| sam_g55_xpro.X                  | MPLABX | ATSAMG55J19         | [SAM G55 Xplained Pro Board](#config_6)                                    |
| sam_g55_xpro_freertos.X         | MPLABX | ATSAMG55J19         | [SAM G55 Xplained Pro Board](#config_6)                                    |
| sam_v71_xult_freertos.X         | MPLABX | ATSAMV71Q21B        | [SAM V71 Xplained Ultra board](config_5)                                   |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_15"></a> [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)

- Use the USB micro-B port J201 to connect the USB Device to the USB Host PC.
- LED1 indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).

### <a name="config_16"></a> [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320007)

- Connect the device to the Type A connector J5, which is located on the top side of the starter kit.
- LED1 on the board is controlled by the attached USB CDC device.

### <a name="config_9"></a> [SAM9X60-EK Evaluation Board](https://www.microchip.com/developmenttools/ProductDetails/DT100126)

- Setup the SD card
    - Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/sam9x60ek/boot.bin).
    - Copy the downloaded boot loader binary (boot.bin) and generated application binary (harmony.bin)into the SD card.
    - Insert the SD card into the SDMMC connector J4 on the board.
- Connect the USB port J22 on board to the computer using a micro USB cable (to enable debug com port).
- Jumpers J20, J21 and J13 must be open.
- Jumper J2 and J3 must be shorted.
- Use USB Type A connector (J8) on the board to connect the USB Device to the USB Host.
- LED D1 indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).
- Connect J7 to a available USB Host Port to power up the board.

    ![SAM9X60-EK Evaluation Board](images/sam9x60_evk.png)

    **Note: Reset push button on SAM9X60 EK is labeled as SW3**

### <a name="config_10"></a> [SAM A5D2 Xplained Ultra Board](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT)

- Setup the SD card
    - Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/master/boot.bin).
    - Copy the downloaded boot loader binary( boot.bin) and generated application binary (harmony.bin)into the SD card.
    - Insert the SD card into the SDMMC1 slot on the board.
- Connect the Debug USB port on the board to the computer using a micro USB cable.
- Use "A5-USB-B" connector(J13 - Type A connector) on the board to connect the USB Device to the USB Host.
- RGB LED turning to Green indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).

### <a name="config_2"></a> [SAM D21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)

- Jumper titled "PA03 SELECT" must be shorted between PA03 and USB_ID(positions 2 and 3)
- Use "TARGET USB" connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED0 on the board is controlled by the attached USB CDC device.

### <a name="config_3"></a> [SAM E54 Xplained Pro Board](https://www.microchip.com/developmenttools/productdetails/atsame54-xpro)

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

### <a name="config_5"></a> [SAM V71 Xplained Ultra board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMV71-XULT)

- Jumper titled "USB VBUS" must be shorted between PC09 and LED1(positions 1 and 2)
- Use "TARGET USB" connector on the board to connect the USB Device to the USB Host. A USB micro AB to type A USB Host receptacle converter will be needed to connect the device.
- LED1 on the board is controlled by the attached USB CDC device.

## Running the Application

This application demonstrates the use of the CDC Host Client Driver to enumerate and operate a CDC USB Device. The application uses the USB Host Layer and CDC Client driver to enumerate a CDC USB device. The demonstration host application then operates and uses the functionality of the attached CDC Device.

1. Open_the project corresponding to the selected board. Refer to the [Building the Application](#building_the_application) section for details.
1. Build the code and program the device.
1. Follow the directions for setting up and running the cdc_serial_emulator USB device demonstration. Start a terminal program on the USB Host personal computer and select the Serial-to-USB Dongle as the communication port. Select the baud rate as 9600, no parity, 1 Stop bit, and no flow control.
1. Connect the USB Device connector of the CDC USB Device board to the USB Host Target board. Refer to the [Configuring the Hardware](#config_title) section for any converter requirements.
1. A prompt (LED :) will be displayed immediately on the terminal emulation program.
1. Pressing the 1 key on the USB Host keyboard will cause the LED on the Host USB board to switch on. Refer to the [Configuring the Hardware](#config_title) section for details on the relevant LED. Pressing any other key at the prompt message will cause the LED to switch off.
1. The prompt will again be displayed on the terminal emulation program, and step 7 can be repeated.
1. Ensure that the CDC serial emulator device is completely powered off before detaching and reattaching to the embedded CDC host.

In the below setup, the USB Device Board emulates a CDC USB-to-Serial Dongle. The USB Host Board (running the cdc_basic demonstration application) sends the prompt message to the CDC device. The CDC device forwards the prompt to the UART port from where it is transmitted to the PC USB Host through the USB serial interface. A key press on the PC USB Host is transmitted to the CDC device, which in turn presents the key press data to the CDC host. The cdc_basic demonstration then analyzes the key press data and switches on the respective LED.

![Block_diagram](./images/cdc_basic_figure_1.png)
