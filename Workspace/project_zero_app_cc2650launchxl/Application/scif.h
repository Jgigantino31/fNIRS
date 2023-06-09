/** \mainpage Driver Overview
  *
  * \section section_drv_info Driver Information
  * This Sensor Controller Interface driver has been generated by the Texas Instruments Sensor Controller
  * Studio tool:
  * - <b>Project name</b>:     ADC Dusk2Dawn Sensor
  * - <b>Project file</b>:     D:/Workspace/project_zero_app_cc2650launchxl/Application/ADC Dusk2Dawn Sensor.scp
  * - <b>Code prefix</b>:      -
  * - <b>Operating system</b>: TI-RTOS
  * - <b>Tool version</b>:     2.9.0.208
  * - <b>Tool patches</b>:     1, 2 and 3
  * - <b>Target chip</b>:      CC2650, package QFN32 5x5 RHB, revision -
  * - <b>Created</b>:          2023-04-14 10:20:52.491
  * - <b>Computer</b>:         JOSEPH-LAPTOP
  * - <b>User</b>:             Joseph Gigantino
  *
  * No user-provided resource definitions were used to generate this driver.
  *
  * No user-provided procedure definitions were used to generate this driver.
  *
  * Do not edit the generated source code files other than temporarily for debug purposes. Any
  * modifications will be overwritten by the Sensor Controller Studio when generating new output.
  *
  * \section section_drv_modules Driver Modules
  * The driver is divided into three modules:
  * - \ref module_scif_generic_interface, providing the API for:
  *     - Initializing and uninitializing the driver
  *     - Task control (for starting, stopping and executing Sensor Controller tasks)
  *     - Task data exchange (for producing input data to and consume output data from Sensor Controller
  *       tasks)
  * - \ref module_scif_driver_setup, containing:
  *     - The AUX RAM image (Sensor Controller code and data)
  *     - I/O mapping information
  *     - Task data structure information
  *     - Driver setup data, to be used in the driver initialization
  *     - Project-specific functionality
  * - \ref module_scif_osal, for flexible OS support:
  *     - Interfaces with the selected operating system
  *
  * It is possible to use output from multiple Sensor Controller Studio projects in one application. Only
  * one driver setup may be active at a time, but it is possible to switch between these setups. When
  * using this option, there is one instance of the \ref module_scif_generic_interface and
  * \ref module_scif_osal modules, and multiple instances of the \ref module_scif_driver_setup module.
  * This requires that:
  * - The outputs must be generated using the same version of Sensor Controller Studio
  * - The outputs must use the same operating system
  * - The outputs must use different source code prefixes (inserted into all globals of the
  *   \ref module_scif_driver_setup)
  *
  *
  * \section section_project_info Project Description
  * This is the fNIRS firmware application file adapted from the Dusk2Dawn example. All application code
  * is here but the project must be compiled in Code Composer Studio with the correct software versions.
  * 
  * Compiler version TI v5.2.6
  * TI RTOS 2.20.1.08
  *
  *
  * \subsection section_io_mapping I/O Mapping
  * Task I/O functions are mapped to the following pins:
  * - Dusk2Dawn:
  *     - <b>A: Sensor 1</b>: DIO13
  *     - <b>A: Sensor 2</b>: DIO11
  *     - <b>A: Battery Monitor</b>: DIO7
  *     - <b>I: USB Power Monitor</b>: DIO9
  *     - <b>I: Charge Controller Monitor</b>: DIO8
  *     - <b>I: High Voltage Supply Power Good Monitor</b>: DIO1
  *     - <b>O: Enable 850nm Wavelength fNIR LED</b>: DIO12
  *     - <b>O: Enable 730nm Wavelength fNIR LED</b>: DIO14
  *     - <b>O: Enable 805nm Wavelength fNIR LED</b>: DIO10
  *     - <b>O: Yellow LED</b>: DIO3
  *     - <b>O: Red LED</b>: DIO4
  *     - <b>O: Green LED</b>: DIO2
  *     - <b>O: Enable High Voltage Power Supply</b>: DIO0
  *
  *
  * \section section_task_info Task Description(s)
  * This driver supports the following task(s):
  *
  *
  * \subsection section_task_desc_dusk2dawn Dusk2Dawn
  * No description entered
  *
  */




/** \addtogroup module_scif_driver_setup Driver Setup
  *
  * \section section_driver_setup_overview Overview
  *
  * This driver setup instance has been generated for:
  * - <b>Project name</b>:     ADC Dusk2Dawn Sensor
  * - <b>Code prefix</b>:      -
  *
  * The driver setup module contains the generated output from the Sensor Controller Studio project:
  * - Location of task control and scheduling data structures in AUX RAM
  * - The AUX RAM image, and the size the image
  * - Task data structure information (location, size and buffer count)
  * - I/O pin mapping translation table
  * - Task resource initialization and uninitialization functions
  * - Hooks for run-time logging
  *
  * @{
  */
#ifndef SCIF_H
#define SCIF_H

#include <stdint.h>
#include <stdbool.h>
#include "scif_framework.h"
#include "scif_osal_tirtos.h"


/// Target chip name
#define SCIF_TARGET_CHIP_NAME_CC2650
/// Target chip package
#define SCIF_TARGET_CHIP_PACKAGE_QFN32_5X5_RHB

/// Number of tasks implemented by this driver
#define SCIF_TASK_COUNT 1

/// Dusk2Dawn: Task ID
#define SCIF_DUSK2DAWN_TASK_ID 0


/// Dusk2Dawn I/O mapping: Sensor 1
#define SCIF_DUSK2DAWN_DIO_A_SEN1 13
/// Dusk2Dawn I/O mapping: Sensor 2
#define SCIF_DUSK2DAWN_DIO_A_SEN2 11
/// Dusk2Dawn I/O mapping: Battery Monitor
#define SCIF_DUSK2DAWN_DIO_A_BAT_MON 7
/// Dusk2Dawn I/O mapping: USB Power Monitor
#define SCIF_DUSK2DAWN_DIO_I_USB_MON 9
/// Dusk2Dawn I/O mapping: Charge Controller Monitor
#define SCIF_DUSK2DAWN_DIO_I_CHG_MON 8
/// Dusk2Dawn I/O mapping: High Voltage Supply Power Good Monitor
#define SCIF_DUSK2DAWN_DIO_I_PG_MON 1
/// Dusk2Dawn I/O mapping: Enable 850nm Wavelength fNIR LED
#define SCIF_DUSK2DAWN_DIO_O_EN_850 12
/// Dusk2Dawn I/O mapping: Enable 730nm Wavelength fNIR LED
#define SCIF_DUSK2DAWN_DIO_O_EN_730 14
/// Dusk2Dawn I/O mapping: Enable 805nm Wavelength fNIR LED
#define SCIF_DUSK2DAWN_DIO_O_EN_805 10
/// Dusk2Dawn I/O mapping: Yellow LED
#define SCIF_DUSK2DAWN_DIO_O_LED_Y 3
/// Dusk2Dawn I/O mapping: Red LED
#define SCIF_DUSK2DAWN_DIO_O_LED_R 4
/// Dusk2Dawn I/O mapping: Green LED
#define SCIF_DUSK2DAWN_DIO_O_LED_G 2
/// Dusk2Dawn I/O mapping: Enable High Voltage Power Supply
#define SCIF_DUSK2DAWN_DIO_O_EN_RUN 0


// All shared data structures in AUX RAM need to be packed
#pragma pack(push, 2)


/// Dusk2Dawn: Task configuration structure
typedef struct {
    uint16_t lowBatteryEnd;   ///< The value above which the battery is no longer considered low. (3.6 V => 1.8V => 1714)
    uint16_t lowBatteryStart; ///< The value below which the battery is considered low. (3.5 V => 1.75V => 1667)
} SCIF_DUSK2DAWN_CFG_T;


/// Dusk2Dawn: Task input data structure
typedef struct {
    uint16_t enableLowPowerMode; ///< Enables low power mode where the high voltage power supply and LED scanning is disabled. (0 is not enabled, 1 is enabled)
    uint16_t setDutyCycle;       ///< Sets the duty cycle of the LED during scanning. (0 is 0%, 1 is 20%, 2 is 40%, 3 is 60% , 4 is 80%, 5 is 100%)
} SCIF_DUSK2DAWN_INPUT_T;


/// Dusk2Dawn: Task output data structure
typedef struct {
    uint16_t adcValue1;        ///< Analog value read from Sensor 1 during 730 nm light period.
    uint16_t adcValue2;        ///< Analog value read from Sensor 2 during 730 nm light period.
    uint16_t adcValue3;        ///< Analog value read from Sensor 1 during 850 nm light period.
    uint16_t adcValue4;        ///< Analog value read from Sensor 2 during 850 nm light period.
    uint16_t batteryValue;     ///< Analog value read from battery voltage.
    uint16_t chargeValue;      ///< Digital value read from charge controller monitor. (0 is charging, 1 is not charging)
    uint16_t dutyCycleStatus;  ///< The current duty cycle state. (0 is 0%, 1 is 20%, 2 is 40%, 3 is 60% , 4 is 80%, 5 is 100%)
    uint16_t lowBatteryStatus; ///< Indicates if the battery is currently low or not. (0 is not low, 1 is low)
    uint16_t powerModeStatus;  ///< The current power mode state. (0 is normal, 1 is low power mode)
    uint16_t powerValue;       ///< Digital value read from power good monitor. (0 is off, 1 is on)
    uint16_t usbValue;         ///< Digital value read from USB power monitor. (0 is no USB power, 1 is USB power)
} SCIF_DUSK2DAWN_OUTPUT_T;


/// Dusk2Dawn: Task state structure
typedef struct {
    uint16_t loop; ///< Keeps track of loop count
} SCIF_DUSK2DAWN_STATE_T;


/// Sensor Controller task data (configuration, input buffer(s), output buffer(s) and internal state)
typedef struct {
    struct {
        SCIF_DUSK2DAWN_CFG_T cfg;
        SCIF_DUSK2DAWN_INPUT_T input;
        SCIF_DUSK2DAWN_OUTPUT_T output;
        SCIF_DUSK2DAWN_STATE_T state;
    } dusk2dawn;
} SCIF_TASK_DATA_T;

/// Sensor Controller task generic control (located in AUX RAM)
#define scifTaskData    (*((volatile SCIF_TASK_DATA_T*) 0x400E00EA))


// Initialized internal driver data, to be used in the call to \ref scifInit()
extern const SCIF_DATA_T scifDriverSetup;


// Restore previous struct packing setting
#pragma pack(pop)


// AUX I/O re-initialization functions
void scifReinitTaskIo(uint32_t bvTaskIds);


// RTC-based tick generation control
void scifStartRtcTicks(uint32_t tickStart, uint32_t tickPeriod);
void scifStartRtcTicksNow(uint32_t tickPeriod);
void scifStopRtcTicks(void);


#endif
//@}


// Generated by JOSEPH-LAPTOP at 2023-04-14 10:20:52.491
