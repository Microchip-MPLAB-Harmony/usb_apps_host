# HID Basic Keyboard Example \(hid\_basic\_keyboard\)

This application demonstrates the ability of the MPLAB Harmony USB Host HID Client Driver to<br /> support to enumerate and operate a HID keyboard device.

## **Description**

This application creates a USB Host application that uses the USB Host Layer, HID Client<br /> driver and HID Keyboard Usage driver to enumerate a USB keyboard and understand keyboard<br /> press release events. The keyboard events are displayed using a terminal emulator on a<br /> personal computer.

## **Downloading and building the application**

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to<br /> clone this repository or download as zip file. This content can also be downloaded using<br /> content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb\_apps\_host/apps/hid\_basic\_keyboard](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/apps/hid_basic_keyboard).

Following table gives the details of project configurations, target device used,<br /> hardware and its IDE. Open the project using the respective IDE and build it.

|Project Name|IDE|Target Device|Hardware / Configuration|
|------------|---|-------------|------------------------|
|pic32cm\_le00\_curiosity\_pro.X|MPLABX|PIC32CM5164LE00100|PIC32CM Lx Curiosity Pro Board|
|pic32mz\_ef\_curiosity\_2\_0.X|MPLABX|PIC32MZ2048EFM144|Curiosity PIC32MZ EF 2.0 Development Board|
|sam\_9x60\_ek.X|MPLABX|SAM9X60|SAM9X60-EK Evaluation Board|
|sam\_9x60\_ek\_freertos.X|MPLABX|SAM9X60|SAM9X60-EK Evaluation Board|
|sam\_9x75\_eb.X|MPLABX|SAM9X75|SAM9X75-DDR3-EB Evaluation Board|
|sam\_9x60\_curiosity.X|MPLABX|SAM9X60|SAM9X60 Curiosity Development Board|
|sam\_9x60\_curiosity\_freertos.X|MPLABX|SAM9X60|SAM9X60 Curiosity Development Board|
|sam\_a5d2\_xult.X|MPLABX|ATSAMA5D27C|SAMA5D2 Xplained Ultra Board|
|sam\_a5d2\_xult\_freertos.X|MPLABX|ATSAMA5D27C|SAMA5D2 Xplained Ultra Board|
|sam\_a5d27\_som1\_ek.X|MPLABX|ATSAMA5D27C|SAMA5D27 SOM1 Kit1|
|sam\_a5d27\_som1\_ek\_freertos.X|MPLABX|ATSAMA5D27C|SAMA5D27 SOM1 Kit1|
|sam\_a5d27\_wlsom1\_ek1.X|MPLABX|ATSAMA5D27C|ATSAMA5D27 WLSOM1 EK1|
|sam\_a5d27\_wlsom1\_ek1\_freertos.X|MPLABX|ATSAMA5D27C|ATSAMA5D27 WLSOM1 EK1|
|sam\_a7g5\_ek.X|MPLABX|SAMA7G54|SAMA7G5 EK Board|
|sam\_d21\_xpro.X|MPLABX|ATSAMD21J18A|SAMD21 Xplained Pro Board|
|sam\_e54\_xpro.X|MPLABX|ATSAME54P20A|SAME54 Xplained Pro Board|
|sam\_e70\_xult.X|MPLABX|ATSAME70Q21B|SAME70 Xplained Ultra Board|
|sam\_e70\_xult\_freertos.X|MPLABX|ATSAME70Q21B|SAME70 Xplained Ultra Board|
|sam\_g55\_xpro.X|MPLABX|ATSAMG55J19|SAMG55 Xplained Pro Board|
|sam\_g55\_xpro\_freertos.X|MPLABX|ATSAMG55J19|SAMG55 Xplained Pro Board|
|pic32cz\_ca80\_curiosity\_ultra.X|MPLABX|PIC32CZ8110CA80208|PIC32CZ Curiosity Development Board|
|pic32ck\_gc01\_curiosity\_ultra\_freertos.X|MPLABX|PIC32CK2051GC01144|PIC32CK GC Curiosity Ultra Development Board|
|pic32cx\_sg41\_curiosity\_ultra.X|MPLABX|PIC32CX1025SG41128|PIC32CX SG41 Curiosity Ultra Evaluation Board|
|sam\_a5d29\_curiosity.X|MPLABX|ATSAMA5D29|SAMA5D29 Curiosity Development Board|
|sam\_9x75\_curiosity.X|MPLABX|SAM9X75D2G|SAM9X75-Curiosity Development Board|
|sam\_a7d65\_curiosity.X|MPLABX|SAMA7D65|SAMA7D65 Curiosity Development Board|
|wbz653\_curiosity.X|MPLABX|WBZ653|WBZ653 Curiosity Board|

## **Configuring the Hardware**

[**PIC32CZ CA80 Curiosity Development Board**](https://www.microchip.com/en-us/development-tool/ea61x20a)

-   A commercially available USB Keyboard is required to run this demonstration application.
-   Connect the USB Keyboard to the connector \(J102\) using a USB Type-A Female to micro-B male cable \(This cable is not included in the kit\).
-   The demonstration uses the PKOB4 Serial Interface to transfer messages on a PC.
-   LED0 indicates a Device Connection. \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

**[PIC32CX SG41 Curiosity Ultra Evaluation Board](https://www.microchip.com/en-us/development-tool/ev06x38a)**

-   A commercially available USB Keyboard is required to run this demonstration application.
-   Connect the USB Keyboard to the connector \(J200\) using a USB Type-A Female to micro-B male cable \(This cable is not included in the kit\).
-   The demonstration uses the PKOB4 Serial Interface to transfer messages on a PC.
-   LED2 indicates a Device Connection. \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

[**PIC32CK GC Curiosity Ultra Development Board**](https://www.microchip.com/en-us/development-tool/ea23j82a)

-   An external power supply \(6.5V to 14V\) must be connected through the J200 connector.
-   A commercially available USB Keyboard is required to run this demonstration application.
-   Connect the USB Keyboard to the USB Type-C connector \(J202\). A USB Type-C to Type-A Female adapter is required to connect the USB device to the board \(This cable is not included in the kit\).
-   The demonstration uses the PKOB4 Serial Interface to transfer messages on a PC.
-   LED1 indicates a Device Connection. \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

**[SAM9X75-DDR3-EB Evaluation Board](https://file+.vscode-resource.vscode-cdn.net/c%3A/H3_USB_APPS/usb_apps_host/apps/hid_basic_keyboard/readme.md)**

-   Powered the board with an external power supply \(or use the micro AB<br /> connector\).

-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)

    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_9x7_binaries/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the SDMMC connector \(SDMMC0\) on the board.
    -   Reset the board by pressing the Push Button RESET, then START.
-   Connect an USB to serial cable to DBGU0 \(to enable debug com port\).

-   Connect the USB device to the Type-A connector or to the micro AB with a<br /> specific dongle \(in these case the need to be powered by the external power<br /> supply\).

-   LED near VDDCORE inscription on the board is controlled by the attached USB<br /> CDC device.![](GUID-9267B813-42FC-4A89-A2CE-DF5AE7535C9C-low.png)**[SAMD21 Xplained Pro Board](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)**

    -   A commercially available USB Keyboard is required to run this demonstration application.
    -   Jumper titled "PA03 SELECT" must be shorted between PA03 and USB\_ID \(positions 2 and 3\)
    -   Use "TARGET USB" connector on the board to connect the USB Keyboard to the USB Host. A USB Type-A Female to micro-B male cable will be needed to connect the device \(This cable is not included in the kit\).
    -   The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC.
    -   LED0 indicates a Device Connection. \(Attached device has been successfully enumerated and configured\).
    -   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

        **Note:** Note: An unexpected behavior<br /> may be observed if the attached USB device draws an excess amount of current<br /> from the board and the Vdd voltage drops below 2.7 volts. The demo has the wait<br /> states \(NVM\_CTRLB <RWS\[3:0\]\>\) value set to '1'.

    **[SAME54 Xplained Pro Board](https://www.microchip.com/developmenttools/productdetails/atsame54-xpro)**

    -   A commercially available USB Keyboard is required to run this demonstration application.
    -   Use "TARGET USB" connector on the board to connect the USB Keyboard to the USB Host. A USB Type-A Female to micro-B male cable will be needed to connect the device \(This cable is not included in the kit\).
    -   The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC.
    -   LED0 indicates a Device Connection. \(Attached device has been successfully enumerated and configured\).
    -   The LED on the keyboard toggles on Keyboard "CapsLock" press event.
    **[SAME70 Xplained Ultra Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320113)**

    -   A commercially available USB Keyboard is required to run this demonstration application.
    -   Jumper J203 must be shorted between PB08 and LED2 \(positions 1 and 2\).
    -   Use "TARGET USB" J200 connector on the board to connect the USB Keyboard to the USB Host. A USB Type-A Female to micro-B male cable will be needed to connect the device \(This cable is not included in the kit\).
    -   The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC.
    -   LED3 indicates a Device Connection. \(Attached device has been successfully enumerated and configured\).
    -   The LED on the keyboard toggles on Keyboard "CapsLock" press event.
    **[SAMG55 Xplained Pro Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMG55-XPRO)**

    -   A commercially available USB Keyboard is required to run this demonstration application.
    -   Chip Erase Jumper must be open.
    -   Use TARGET USB connector on the board to connect the USB keyboard to the USB Host. A USB Type-A Female to micro-B male cable will be needed to connect the device \(This cable is not included in the kit\).
    -   The demonstration uses the EDBG Serial Interface to transfer demonstration application messages on a PC.
    -   LED0 indicates a Device Connection. \(Attached device has been successfully enumerated and configured\).
    -   The LED on the keyboard toggles on Keyboard "CapsLock" press event.
    **[SAM9X60-EK Evaluation Board](https://www.microchip.com/developmenttools/ProductDetails/DT100126)**

    -   A commercially available USB Keyboard is required to run this<br /> demonstration application.

    -   Setup the SD card \(Note: exFAT formatted SD Cards are not<br /> supported\)

        -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_9x60_binaries/boot.bin).
        -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
        -   Insert the SD card into the SDMMC connector J4 on the board.
        -   Reset the board by pressing the Push Button SW3.
    -   Jumpers J20, J21, and J13 must be open.

    -   Jumper J2 and J3 must be shorted.

    -   Connect the USB Micro-B port \(J22\) on board to the computer using a<br /> micro USB cable \(to enable debug com port\).

    -   Connect the USB Micro-B Connector \(J7\) on the board to the computer<br /> using a micro USB cable to power up the board.

    -   Connect the USB device to the Type-A connector \(J8\).

    -   LED D1 indicates a Device Connection \(Attached device has been<br /> successfully enumerated and configured\).

    -   The LED on the keyboard toggles on Keyboard "CapsLock" press<br /> event.

        ![](GUID-3A80F4CD-C8CC-459A-9F5A-5A6F94198D38-low.png)Note: Reset push button on SAM9X60 EK is labeled as SW3


**[SAM9X60-Curiosity Board](https://www.microchip.com/en-us/development-tool/EV40E67A)**

-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)

    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/c%3A/H3_USB_APPS/usb_apps_host/deps/at91bootstrap_sam_9x60_binaries/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the SDMMC0 connector J3 on the board.
    -   Reset the board by pressing the Push Button RESET.
-   Jumper J4 must be shorted.

-   Connect the USB Micro-B Connector \(J1\) on the board to the computer using a<br /> micro USB cable.

-   Connect the USB device to the Type-A connector \(J10\).

-   LED D1 indicates a Device Connection \(Attached device has been successfully<br /> enumerated and configured\).

-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

    ![](GUID-183BD41F-3C32-42CE-AB01-34E971650003-low.png)


**[SAMA5D2 Xplained Ultra Board](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT)**

-   A commercially available USB Keyboard is required to run this demonstration application.
-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)
    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_a5d2_binaries/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the SDMMC1 slot on the board.
    -   Reset the board by pressing the Push Button BP3.
-   Connect the EDBG USB Micro-B port J14 on the board to the computer using a micro USB cable.
-   Connect the USB device to the USB Type-A connector "A5-USB-B" \(J13\).
-   The demonstration uses the EDBG USB Micro-B port J14 to transfer demonstration application messages on a PC.
-   RGB LED indicates a Device Connection \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

**[Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)**

-   A commercially available USB Keyboard is required to run this demonstration application.
-   Connect the USB Keyboard to the "TARGET USB" connector \(J201\) using a USB Type-A Female to micro-B male cable \(This cable is not included in the kit\).
-   The demonstration uses the PKOB4 Serial Interface to transfer messages on a PC.
-   LED1 indicates a Device Connection \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

**[SAMA5D27 SOM1 Kit1](https://www.microchip.com/developmenttools/ProductDetails/atsama5d27-som1-ek1)**

-   A commercially available USB Keyboard is required to run this demonstration<br /> application.

-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)

    -   Jumper J9 must be removed to have the JTAG-CDC enable.
    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_a5d27_som1_binaries/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the SDMMC0 slot \(J12\) on the board.
    -   Reset the board by pressing the Push Button PB1.
-   Connect the USB Micro-AB port \(J10\) on the board to the computer using a<br /> micro USB cable.

-   Connect the USB device to the USB-B Type-C connector \(J19\) on the board.

-   The demonstration uses the USB Micro-AB port \(J10\) to transfer demonstration<br /> application messages on a PC.

-   RGB LED indicates a Device Connection \(Attached device has been successfully enumerated<br /> and configured\).

-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

    ![](GUID-051542DD-8594-494A-8DEE-85CD889BBFE1-low.png)


**[ATSAMA5D27-WLSOM1 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320117)**

-   A commercially available USB Keyboard is required to run this demonstration application.
-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)
    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_a5d27_wlsom1_binaries/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the SDMMC0 Card Connector \(J9\) on the board.
    -   Reset the board by pressing the Reset Button \(SW2\)
-   Connect the USB-A Micro-AB connector \(J10\) on the board to the computer using a micro USB cable.
-   Press the "START\_SOM" button to activate board start-up.
-   Connect the USB device to the USB Type-A connector \(J11\) on the board.
-   The demonstration uses the Debug UART port \(J26\) to transfer demonstration application messages on a PC. A USB/Serial converter is required to connect the J26 to a PC \(The USB/Serial converter is not included in the kit\).
-   RGB LED indicates a Device Connection \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.![](GUID-065D0C05-E337-490E-8BB3-5589BB265C10-low.png)

**[SAMA7G5-EK Evaluation Kit](https://www.microchip.com/en-us/development-tool/EV21H18A)**

-   A commercially available USB Keyboard is required to run this demonstration application.
-   Powered the board with an external power supply \(J1\).
-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)
    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_a7g5_binaries/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the SD Card Connector \(J4\) on the board.
    -   Reset the board by pressing the Reset Button \(nRST\)
-   Press the "nSTART" button to activate board start-up.
-   Connect the USB device to the USB Host Type-A connector \(J9\) on the board. Alternatively, the USB Device could be connected to the Type-C connector \(J8\) or micro A/B connector \(J7\).
-   The demonstration uses the Debug UART port \(J24\) to transfer demonstration application messages on a PC.
-   RGB LED indicates a Device Connection \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

**[Curiosity Pro PIC32CM LE00 Development Board](https://www.microchip.com/en-us/development-tool/EV80P12A)**

-   Power the board by connecting an host to "DEBUG USB" \(J300\) connector.
-   Connect the USB device to the USB Host "TARGET USB" \(J200\) using a USB Type-A Female to micro-B male cable \(This cable is not included in the kit\).
-   LED0 indicates a Device Connection \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

**[SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/ev07r15a)**

-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)
    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_a5d29_binaries/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the μSD-CARD connector J6 on the board.\(This connector is present on the bottom face of the board\)
    -   Reset the board by pressing the Push Button RESET.
-   Press the "START" button to activate board start-up.
-   Connect the USB device to the USB\_B Type-A connector \(J11\) on the board.
-   RGB LED \(D5\) on the board indicates a Device Connection \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

![](GUID-345F639A-F2A9-4837-AEEE-B39FEC261EE4-low.png)

**SAM9X75-Curiosity Development Board**

-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)
    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_9x75_curiosity_binaries/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the μSD-CARD connector \(J14\) on the board.\(This connector is present on the bottom face of the board\)
    -   Reset the board by pressing the Push Button RESET.
-   Press the "START" button to activate board start-up.
-   Connect the USB device to the USB\_B Type-A connector \(J15\) or USB\_C Type-A connector \(J16\) on the board.
-   RGB LED \(LD1\) on the board indicates a Device Connection \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.
-   The demonstration uses the UART DEBUG port \(J35\) to transfer demonstration application messages on a PC. A USB/Serial converter is required to connect the J35 to a PC \(The USB/Serial converter is not included in the kit\).

![](GUID-C71AB60D-8800-4B73-8AFA-E74521ED5D7C-low.png)

**[SAMA7D65 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/ea89c15a#Overview)**

-   Setup the SD card \(Note: exFAT formatted SD Cards are not supported\)
    -   Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/tree/master/deps/at91bootstrap_sam_a7d65_curiosity/boot.bin).
    -   Copy the downloaded boot loader binary \(boot.bin\) and generated application binary \(harmony.bin\) into the SD card.
    -   Insert the SD card into the SD-CARD connector \(J10\) on the board.
    -   Reset the board by pressing the Push Button RESET.

-   Press the "START" button to activate board start-up.
-   Connect the USB device to the USB\_B Type-A connector \(J23\) or USB\_C Type-A connector \(J24\) on the board.
-   RGB LED on the board indicates a Device Connection \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.
-   The demonstration uses the UART DEBUG port \(J35\) to transfer demonstration application messages on a PC. A USB/Serial converter is required to connect the J35 to a PC \(The USB/Serial converter is not included in the kit\).

![](GUID-6DEE5CBA-AB4F-43D8-AF25-C502A75A4621-low.jpg)

**WBZ653 Curiosity Board**

-   Jumper J102 must be shorted between 5V and VBUS.
-   J104 must be connected between VBUSON and EN \(Positions 2 and 3\).
-   A commercially available USB Keyboard is required to run this demonstration application.
-   Connect the USB Keyboard to the USB Type-C connector TARGET USB \(J103\). A USB Type-C to Type-A Female adapter is required to connect the USB device to the board \(This cable is not included in the kit\).
-   The demonstration uses the PKOB4 \(DBG USB J100\) Serial Interface to transfer messages on a PC.
-   RGB\_LED \(D800\) indicates a Device Connection. \(Attached device has been successfully enumerated and configured\).
-   The LED on the keyboard toggles on Keyboard "CapsLock" press event.

## **Running the Application**

<br />

1.  Open the project with appropriate IDE. Compile the project and program the<br /> target device.

2.  Connect the serial interface on the board to a PC. On the PC, launch a<br /> terminal emulator, such as Tera Term, and select the appropriate COM port and set the<br /> serial port settings to 115200-N-1.

3.  If a USB keyboard is not connected to the Embedded USB Host, the terminal<br /> emulator window will show the Connect Keyboard prompt.

4.  Attach a USB keyboard to the Host connector of the target hardware. The<br /> message, Keyboard Connected, will appear in the terminal emulator window. Refer to the<br /> Configuring the Hardware section for any converter requirements.

5.  Begin typing on the keyboard and the appropriate keys should be displayed<br /> on the serial terminal. Subsequent press and release of modifier keys \(i.e., CAPS<br /> LOCK, NUM LOCK, etc.\) will result in the appropriate keyboard LEDs to turning ON and<br /> OFF.

6.  Disconnecting the keyboard will result in the message, Connect<br /> Keyboard.![](GUID-85C56AF2-530C-4150-8762-7F1851C4F854-low.png)


<br />

**Parent topic:**[Harmony 3 USB Host application examples](GUID-4BEB4580-5653-4314-ABDE-36EF2BAAF53B.md)

