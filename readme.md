---
title: Harmony 3 USB Host application examples
nav_order: 1
has_children: true
has_toc: false
---
[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Harmony 3 USB Host application examples

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller and microprocessor devices.  Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 USB Host application examples.

- [Release Notes](release_notes.md)
- [MPLAB® Harmony License](mplab_harmony_license.md)

To clone or download these applications from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

# Contents Summary

| Folder     | Description                                               |
| ---        | ---                                                       |
| apps       | Contains Harmony 3 USB Host application examples |
| docs       | Contains documentation in html format for offline viewing (to be used only after cloning this repository onto a local machine). Use [github pages](https://microchip-mplab-harmony.github.io/usb_apps_host/) of this repository for viewing it online. |

## Code Examples

The following applications are provided to demonstrate the typical or interesting usage models of USB Host capabilities.

| Name                      | Description            |
| ------------------------- | ---------------------- |
| CDC Basic                 | This application uses the USB Host Layer and CDC Client driver to enumerate a standard CDC USB device. The demonstration host application then operates and uses the functionality of the attached CDC Device. |
| CDC MSD                   | This application creates a USB Host that can recognize and enumerate a CDC USB Device and MSC USB Device. |
| HID Basic Keyboard        | This application creates a USB Host application that uses the USB Host Layer, HID Client driver and HID Keyboard Usage driver to enumerate a USB keyboard and understand keyboard press release events. The keyboard events are displayed using a terminal emulator on a personal computer. |
| HID Basic Mouse USART     | This application uses the USB Host layer, HID Client driver and HID Mouse Usage driver to enumerate a USB Mouse and detect Mouse button press release events. The Mouse events are displayed using a terminal emulator on a personal computer. |
| HUB CDC HID               | This application creates a USB Host that can recognize and enumerate a CDC Emulator USB Device and a HID USB Mouse connected via an external Hub. The host will demonstrate the communication from the CDC emulator device and the HID mouse. |
| HUB MSD                   | This application uses USB Host stack and the Harmony Filesystem Service to copy a file from a source USB pen drive to a target USB pen drive. |
| MSD Basic                 | This application demonstrates the use of the MSD Host Class Driver to write a file to a USB Flash drive. The application uses the USB Host_layer , MSD class driver and the MPLAB Harmony File System Framework to enumerate a USB Flash drive and to write a file to it. |
| ROOT HUB DUAL MSD         | This application demonstrates the use of the root hub of the host.
____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/usb_apps_host.svg)](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/usb_apps_host.svg)](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/usb_apps_host.svg)](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/usb_apps_host.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/usb_apps_host.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/usb_apps_host.svg?style=social)]()


