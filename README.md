# fNIRS

## Information

The folder "Board Files" contains all of the information needed to manufacture the device including schematic diagrams, component lists, and the laid out PCB as well as renders of the finished device. The folder "Workspace" contains the Code Composer Studio projects and other files that make up the device's software. The folder "Firmware Files" contain compiled binary files you can flash immediately without neededing to install Code Composer Studio and its supporting software. The folder "Application" contains an example Android Application which can communicate with the device and was used to test the device.

## Project Setup

### Flash Pre-Compiled Binaries

If you wish to flash the device's firmware as is you only need to install SmartRF Flash Programmer V2. Flash the three hex files in the folder "Firmware Files" in the following order: bim_extflash.hex, project_zero_stack_cc2650.hex, project_zero_app_cc2650launchxl.hex. For more detailed instructions see Chapter 4 System Micro-Controller.

### Rebuild Project From Source

If you wish to make changes to the source code you must setup the required developer environment and rebuild the project. Install the latest version of Code Composer Studio and Sensor Controller Studio. All software links are at the end of this document. Code Composer Studio should be installed to "C:\ti\ccs1210" while Sensor Controller Studio may installed to any directory. The deafult is "C:\Program Files (x86)\Texas Instruments\Sensor Controller Studio". You may optionally install SmartRF Flash Programmer V2 if you wish to directly install binary (.hex) files. It can be installed to any directory with the default being "C:\Program Files (x86)\Texas Instruments\SmartRF Tools\Flash Programmer 2". <br>

The folder Workspace should be set as the current workspace in Code Composer Studio. The workspace must be in a directory without spaces. It contains two projects, Project Zero Stack and Project Zero Application. Project Zero Stack is a dependency of Project Zero Application. Project Zero Stack contains include directives to the TI-RTOS and BLE-STACK which must be installed to "C:/ti" and "C:/ti/simplelink" respectively. You must install TI-RTOS V2.20.01.08 for CC13xx/CC26xx and you must install BLE-STACK V2.2.1 in order to be able to build. The main project code for Project Zero Application can be found in the "project_zero.c" file. You must use Sensor Controller Studio to open the Sensor Controler Studio Project file (.scp) named "ADC Dusk2Dawn Sensor.scp" if you wish to view or edit the program running on the low power sensor core. This program communicates with the main program which you can edit in Code Composer Studio. The main program also uses the Project Zero Stack project to interface to the example Android application over Bluetooth. For a more detailed explanation, please see Chapter 4 System Micro-Controller.

**Code Composer Studio Workspace** - \Workspace <br>
**Project Zero Stack** - \Workspace\project_zero_stack_cc2650 <br>
**Project Zero Application** - \Workspace\project_zero_app_cc2650launchxl <br>
**Project Zero Main C File** - \Workspace\project_zero_app_cc2650launchxl\Application\project_zero.c <br>
**Sensor Controller Studio Project** - \Workspace\project_zero_app_cc2650launchxl\Application\ADC Dusk2Dawn Sensor.scp <br>

### Software Download Links

**SmartRF Flash Programmer V2** - https://www.ti.com/tool/FLASH-PROGRAMMER <br>
**Sensor Controller Studio** - https://www.ti.com/tool/SENSOR-CONTROLLER-STUDIO <br>
**Code Composer Studio** - https://www.ti.com/tool/CCSTUDIO <br>
**TI-RTOS V2.20.01.08 for CC13xx/CC26xx** - https://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/tirtos/index.html <br>
**BLE-STACK V2.2.1** - https://www.ti.com/tool/BLE-STACK-ARCHIVE <br>
