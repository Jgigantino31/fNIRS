# A Compact and Efficient fNIRS Design - Repository

[![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa] [![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.7860585.svg)](https://doi.org/10.5281/zenodo.7860585)

This repository contains the data needed to fully recreate the work performed as part of my Master's Thesis at Villanova University. The thesis, titled "A Compact and Efficient fNIRS Design", was submitted to the faculty of the Department of Electrical and Computer Engineering at Villanova University in partial fulfillment of the requirements for the degree of Master of Science in Electrical Engineering in May 2023.

This repository is available on GitHub at [https://github.com/Jgigantino31/fNIRS](https://github.com/Jgigantino31/fNIRS). This repository is also available using a persistent URL at [https://purl.org/fnirs/repository](https://purl.org/fnirs/repository) or DOI at [10.5281/zenodo.7860585](https://doi.org/10.5281/zenodo.7860585). The corresponding thesis is available using a persistent URL at [https://purl.org/fnirs/thesis](https://purl.org/fnirs/thesis) or DOI at [10.5281/zenodo.7863734](https://doi.org/10.5281/zenodo.7863734).

## Abstract

Functional near-infrared spectroscopy (fNIRS) is a non-invasive brain imaging technique that overcomes many limitations of traditional imaging methods since the technology allows safe, portable, wearable, and cost-effective designs. fNIRS devices use the absorption characteristics of near-infrared (NIR) light by oxygenated and deoxygenated hemoglobin in the brain. Measuring the changes in reflected NIR light, an fNIRS device can provide information on the relative changes in the concentration of oxygenated and deoxygenated hemoglobin in the brain which can then be related to cognitive activations or brain health depending on the application. This thesis focused on creating a compact design in order to increase the efficiency and accessibility of fNIRS devices. It produced a fully functional, compact, modular, battery-powered, and wireless two channel fNIRS sensor. The sensor was successfully designed, manufactured, assembled, and evaluated using baseline system tests as well as real world performance tests. The results indicated that this fNIRS sensor is fully functional and capable of collecting hemodynamic signals.

## Repository Contents

The folder [Board Files](/Board%20Files) contains all of the information needed for fabrication and assembly of the device. The folder [Workspace](/Workspace) contains the Code Composer Studio projects and other files that make up the device's software. The folder [Firmware Files](/Firmware%20Files) contain compiled binary files you can flash immediately without needing to install Code Composer Studio and its supporting software. The folder [Application](/Application) contains an example Android application which can communicate with the device and was used to test the device.

## Hardware

The device was designed in Altium CircuitMaker and the project can be viewed online in Altium 365. You can also view the schematic, PCB layout, bill of materials, and a 3D render online. The folder [Board Files](/Board%20Files) contains the released project files from Altium CircuitMaker which can be used to manufacture the device.

**CircuitMaker Project** - [https://purl.org/fnirs/circuitmaker](https://purl.org/fnirs/circuitmaker) <br>
**Altium 365 Viewer** - [https://purl.org/fnirs/altium365](https://purl.org/fnirs/altium365) <br>

## Software

All of the software used by the device is available in this repository. In order to flash the firmware to the device you must have a SimpleLink™ CC2650 wireless MCU LaunchPad™ Development Kit which are available for purchase from Texas Instruments.

**Launchpad Development Kit** - [https://www.ti.com/tool/LAUNCHXL-CC2650](https://www.ti.com/tool/LAUNCHXL-CC2650) <br>

### Flash Pre-Compiled Binaries

If you wish to flash the device's firmware as-is you only need to install SmartRF Flash Programmer V2. Flash the three hex files in the folder [Firmware Files](/Firmware%20Files) in the following order: [bim_extflash.hex](/Firmware%20Files/bim_extflash.hex), [project_zero_stack_cc2650.hex](/Firmware%20Files/project_zero_stack_cc2650.hex), [project_zero_app_cc2650launchxl.hex](/Firmware%20Files/project_zero_app_cc2650launchxl.hex). These files are produced as a result of compiling each project in the [Workspace](/Workspace) folder.

### Rebuild Project from Source

If you wish to make changes to the source code you must setup the required developer environment and rebuild the project from source. Install the latest version of Code Composer Studio and Sensor Controller Studio. Code Composer Studio should be installed to "C:\ti\ccs1210" while Sensor Controller Studio may be installed to any directory. You may install SmartRF Flash Programmer V2 as well if you wish to directly install binary (.hex) files. <br>

The folder [Workspace](/Workspace) should be set as the current workspace in Code Composer Studio. The workspace must be in a directory without spaces. It contains three projects: [bim_extflash](/Workspace/bim_extflash), [Project Zero Stack](/Workspace/project_zero_stack_cc2650), and [Project Zero Application](/Workspace/project_zero_app_cc2650launchxl). [Bim_extflash](/Workspace/bim_extflash) is a small application which produces [bim_extflash.hex](/Workspace/bim_extflash/FlashOnly_ST/bim_extflash.hex). This file is used to wipe the device and prepare it to accept a new flash image. [Project Zero Stack](/Workspace/project_zero_stack_cc2650) contains include directives to the TI-RTOS and BLE-STACK which must be installed to their default locations of "C:\ti" and "C:\ti\simplelink" respectively. You must install TI-RTOS V2.20.01.08 for CC13xx/CC26xx and you must install BLE-STACK V2.2.1 in order to be able to build. You must also ensure both projects use compiler version TI V5.2.6 in order to be able to build. You must build [Project Zero Stack](/Workspace/project_zero_stack_cc2650) before attempting to build [Project Zero Application](/Workspace/project_zero_app_cc2650launchxl). The main project code for [Project Zero Application](/Workspace/project_zero_app_cc2650launchxl) can be found in [project_zero.c](/Workspace/project_zero_app_cc2650launchxl/Application/project_zero.c). You must use Sensor Controller Studio to open the Sensor Controller Studio Project file [ADC Dusk2Dawn Sensor.scp](/Workspace/project_zero_app_cc2650launchxl/Application/ADC%20Dusk2Dawn%20Sensor.scp) if you wish to view or edit the program running on the low power sensor core. Both [Project Zero Stack](/Workspace/project_zero_stack_cc2650) and [Project Zero Application](/Workspace/project_zero_app_cc2650launchxl) output a hex file in their respective Debug folders once compiled.

### Important Software Files

**Code Composer Studio Workspace Folder** - [Workspace](/Workspace) <br>

**Bim_extflash Project Folder** - [bim_extflash](/Workspace/bim_extflash) <br>
**Bim_extflash Project Output** - [bim_extflash.hex](/Workspace/bim_extflash/FlashOnly_ST/bim_extflash.hex) <br>

**Project Zero Stack Folder** - [project_zero_stack_cc2650](/Workspace/project_zero_stack_cc2650) <br>
**Project Zero Stack Output** - [project_zero_stack_cc2650.hex](/Workspace/project_zero_stack_cc2650/Debug/project_zero_stack_cc2650.hex) <br>

**Project Zero Application Folder** - [project_zero_app_cc2650launchxl](/Workspace/project_zero_app_cc2650launchxl) <br>
**Project Zero Application Main C File** - [project_zero.c](/Workspace/project_zero_app_cc2650launchxl/Application/project_zero.c) <br>
**Sensor Controller Studio Project** - [ADC Dusk2Dawn Sensor.scp](/Workspace/project_zero_app_cc2650launchxl/Application/ADC%20Dusk2Dawn%20Sensor.scp) <br>
**Project Zero Application Output** - [project_zero_app_cc2650launchxl.hex](/Workspace/project_zero_app_cc2650launchxl/Debug/project_zero_app_cc2650launchxl.hex) <br>

### Software Download Links

**SmartRF Flash Programmer V2** - [https://www.ti.com/tool/FLASH-PROGRAMMER](https://www.ti.com/tool/FLASH-PROGRAMMER) <br>
**Sensor Controller Studio** - [https://www.ti.com/tool/SENSOR-CONTROLLER-STUDIO](https://www.ti.com/tool/SENSOR-CONTROLLER-STUDIO) <br>
**Code Composer Studio** - [https://www.ti.com/tool/CCSTUDIO](https://www.ti.com/tool/CCSTUDIO) <br>
**TI-RTOS V2.20.01.08 for CC13xx/CC26xx** - [https://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/tirtos/index.html](https://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/tirtos/index.html) <br>
**BLE-STACK V2.2.1** - [https://www.ti.com/tool/BLE-STACK-ARCHIVE](https://www.ti.com/tool/BLE-STACK-ARCHIVE) <br>

## License

Copyright &copy; 2023 Joseph Gigantino

This repository is licensed under the [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
