# A Compact and Efficient fNIRS Design

This repository contains the information needed to fully recreate the work performed as part of my Master's Thesis at Villanova University. The thesis, titled "A Compact and Efficient fNIRS Design", was submitted to the faculty of the Department of Electrical and Computer Engineering at Villanova University in partial fulfillment of the requirements for the degree of Master of Science in Electrical Engineering in April of 2023.

## Abstract

Functional near-infrared spectroscopy (fNIRS) is a non-invasive brain imaging technique that overcomes many limitations of traditional imaging methods since the technology allows safe, portable, wearable, and cost-effective designs. fNIRS devices use the absorption characteristics of near-infrared (NIR) light by oxygenated and deoxygenated hemoglobin in the brain. Measuring the changes in reflected NIR light, an fNIRS device can provide information on the relative changes in the concentration of oxygenated and deoxygenated hemoglobin in the brain which can then be related to cognitive activations or brain health depending on the application. This thesis focused on creating a compact design in order to increase the efficiency and accessibility of fNIRS devices. It produced a fully functional, compact, modular, battery-powered, and wireless two channel fNIRS sensor. The sensor was successfully designed, manufactured, assembled, and evaluated using baseline system tests as well as real world performance tests. The results indicated that this fNIRS sensor is fully functional and capable of collecting hemodynamic signals.

## Repository Contents

The folder "Board Files" contains all of the information needed to manufacture the device including schematic diagrams, component lists, and the laid-out PCB as well as renders of the finished device. The folder "Workspace" contains the Code Composer Studio projects and other files that make up the device's software. The folder "Firmware Files" contain compiled binary files you can flash immediately without needing to install Code Composer Studio and its supporting software. The folder "Application" contains an example Android Application which can communicate with the device and was used to test the device.

## Hardware

The device schematic was designed in Altium Circuit Maker and the project can be viewed online in Altium 365. You can also view the PCB layout, bill of materials, and a 3D render online. The folder "Board Files" contains the released project files which can be used to manufacture the device.

**Circuit Maker Project** - https://workspace.circuitmaker.com/Projects/Details/JosephGigantino/fNIRS-V3 <br>
**Altium 365 Project** - https://365.altium.com/files/D22399D6-5709-4094-A18F-3D94270D79AF <br>

## Software

In order to flash the firmware to the device you must have a SimpleLink™ CC2650 wireless MCU LaunchPad™ Development Kit which are available for purchase from Texas Instruments.

**Launchpad Development Kit** - https://www.ti.com/tool/LAUNCHXL-CC2650 <br>

### Flash Pre-Compiled Binaries

If you wish to flash the device's firmware as-is you only need to install SmartRF Flash Programmer V2. Flash the three hex files in the folder "Firmware Files" in the following order: bim_extflash.hex, project_zero_stack_cc2650.hex, project_zero_app_cc2650launchxl.hex. These files are produced as a result of compiling each project in the "Workspace" folder.

### Rebuild Project from Source

If you wish to make changes to the source code you must setup the required developer environment and rebuild the project. Install the latest version of Code Composer Studio and Sensor Controller Studio. All software links are at the end of this document. Code Composer Studio should be installed to "C:\ti\ccs1210" while Sensor Controller Studio may be installed to any directory. The default is "C:\Program Files (x86)\Texas Instruments\Sensor Controller Studio". You may optionally install SmartRF Flash Programmer V2 if you wish to directly install binary (.hex) files. It can be installed to any directory with the default being "C:\Program Files (x86)\Texas Instruments\SmartRF Tools\Flash Programmer 2". <br>

The folder "Workspace" should be set as the current workspace in Code Composer Studio. The workspace must be in a directory without spaces. It contains three projects:  bim_extflash, Project Zero Stack, and Project Zero Application. Bim_extflash is a small application which produces bim_extflash.hex. This file is used to wipe the device and prepare it to accept a new flash image. Project Zero Stack is a dependency of Project Zero Application. Project Zero Stack contains include directives to the TI-RTOS and BLE-STACK which must be installed to their default locations of "C:\ti" and "C:\ti\simplelink" respectively. You must install TI-RTOS V2.20.01.08 for CC13xx/CC26xx and you must install BLE-STACK V2.2.1 in order to be able to build. You must ensure both projects use compiler version TI V5.2.6 in order to be able to build. The main project code for Project Zero Application can be found in the "project_zero.c" file. You must use Sensor Controller Studio to open the Sensor Controller Studio Project file (.scp) named "ADC Dusk2Dawn Sensor.scp" if you wish to view or edit the program running on the low power sensor core. This program communicates with the main program which you can edit in Code Composer Studio. The main program also uses the Project Zero Stack project to interface to the example Android application over Bluetooth. Both Project Zero Stack and Project Zero Application output a hex file in their respective Debug folders once compiled.  For convenience, the output of all three projects have also been placed in the "Firmware Files" folder for easy access.

**Code Composer Studio Workspace** - \Workspace <br>
**Bim_extflash Project** - \Workspace\bim_extflash <br>
**Bim_extflash Project Output** - \Workspace\bim_extflash\FlashOnly_ST\bim_extflash.hex <br>
**Project Zero Stack** - \Workspace\project_zero_stack_cc2650 <br>
**Project Zero Stack Output** - \Workspace\project_zero_stack_cc2650\Debug\project_zero_stack_cc2650.hex <br>
**Project Zero Application** - \Workspace\project_zero_app_cc2650launchxl <br>
**Project Zero Application Main C File** - \Workspace\project_zero_app_cc2650launchxl\Application\project_zero.c <br>
**Sensor Controller Studio Project** - \Workspace\project_zero_app_cc2650launchxl\Application\ADC Dusk2Dawn Sensor.scp <br>
**Project Zero Application Output** - \Workspace\project_zero_app_cc2650launchxl\Debug\project_zero_app_cc2650launchxl.hex <br>

### Software Download Links

**SmartRF Flash Programmer V2** - https://www.ti.com/tool/FLASH-PROGRAMMER <br>
**Sensor Controller Studio** - https://www.ti.com/tool/SENSOR-CONTROLLER-STUDIO <br>
**Code Composer Studio** - https://www.ti.com/tool/CCSTUDIO <br>
**TI-RTOS V2.20.01.08 for CC13xx/CC26xx** - https://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/tirtos/index.html <br>
**BLE-STACK V2.2.1** - https://www.ti.com/tool/BLE-STACK-ARCHIVE <br>

## License

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

Copyright (C) 2023 Joseph Gigantino
