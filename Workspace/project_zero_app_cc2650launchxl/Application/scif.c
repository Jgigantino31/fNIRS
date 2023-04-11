/// \addtogroup module_scif_driver_setup
//@{
#include "scif.h"
#include "scif_framework.h"
#undef DEVICE_FAMILY_PATH
#if defined(DEVICE_FAMILY)
    #define DEVICE_FAMILY_PATH(x) <ti/devices/DEVICE_FAMILY/x>
#elif defined(DeviceFamily_CC26X0)
    #define DEVICE_FAMILY_PATH(x) <ti/devices/cc26x0/x>
#elif defined(DeviceFamily_CC26X0R2)
    #define DEVICE_FAMILY_PATH(x) <ti/devices/cc26x0r2/x>
#elif defined(DeviceFamily_CC13X0)
    #define DEVICE_FAMILY_PATH(x) <ti/devices/cc13x0/x>
#else
    #define DEVICE_FAMILY_PATH(x) <x>
#endif
#include DEVICE_FAMILY_PATH(inc/hw_types.h)
#include DEVICE_FAMILY_PATH(inc/hw_memmap.h)
#include DEVICE_FAMILY_PATH(inc/hw_aon_event.h)
#include DEVICE_FAMILY_PATH(inc/hw_aon_rtc.h)
#include DEVICE_FAMILY_PATH(inc/hw_aon_wuc.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_sce.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_smph.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_evctl.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_aiodio.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_timer.h)
#include DEVICE_FAMILY_PATH(inc/hw_aux_wuc.h)
#include DEVICE_FAMILY_PATH(inc/hw_event.h)
#include DEVICE_FAMILY_PATH(inc/hw_ints.h)
#include DEVICE_FAMILY_PATH(inc/hw_ioc.h)
#include <string.h>
#if defined(__IAR_SYSTEMS_ICC__)
    #include <intrinsics.h>
#endif


// OSAL function prototypes
uint32_t scifOsalEnterCriticalSection(void);
void scifOsalLeaveCriticalSection(uint32_t key);




/// Firmware image to be uploaded to the AUX RAM
static const uint16_t pAuxRamImage[] = {
    /*0x0000*/ 0x1408, 0x040C, 0x1408, 0x042C, 0x1408, 0x0447, 0x1408, 0x044D, 0x4436, 0x2437, 0xAEFE, 0xADB7, 0x6442, 0x7000, 0x7C6B, 0x6872, 
    /*0x0020*/ 0x0068, 0x1425, 0x6873, 0x0069, 0x1425, 0x6874, 0x006A, 0x1425, 0x786B, 0xF801, 0xFA01, 0xBEF2, 0x7870, 0x6872, 0xFD0E, 0x6874, 
    /*0x0040*/ 0xED92, 0xFD06, 0x7C70, 0x642D, 0x0450, 0x786B, 0x8F1F, 0xED8F, 0xEC01, 0xBE01, 0xADB7, 0x8DB7, 0x6630, 0x6542, 0x0000, 0x1870, 
    /*0x0060*/ 0x9D88, 0x9C01, 0xB60D, 0x1067, 0xAF19, 0xAA00, 0xB609, 0xA8FF, 0xAF39, 0xBE06, 0x0C6B, 0x8869, 0x8F08, 0xFD47, 0x9DB7, 0x086B, 
    /*0x0080*/ 0x8801, 0x8A01, 0xBEEC, 0x262F, 0xAEFE, 0x4630, 0x0450, 0x5527, 0x6642, 0x0000, 0x0C6B, 0x140B, 0x0450, 0x6742, 0x03FF, 0x0C6D, 
    /*0x00A0*/ 0x786C, 0x686D, 0xED37, 0xB605, 0x0000, 0x0C6C, 0x7C71, 0x652D, 0x0C6D, 0x786D, 0x686E, 0xFD0E, 0xF801, 0xE92B, 0xFD0E, 0xBE01, 
    /*0x00C0*/ 0x6436, 0xBDB7, 0x241A, 0xA6FE, 0xADB7, 0x641A, 0xADB7, 0x0000, 0x0085, 0x00A0, 0x0245, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 
    /*0x00E0*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x06B2, 0x0683, 0x0000, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0898, 0x0001, 0x0005, 
    /*0x0100*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x540F, 0x640F, 0x650F, 0x660F, 0x7093, 0x600E, 0x1646, 0x740F, 0x500B, 0x164C, 0x7C82, 
    /*0x0120*/ 0x0882, 0x8A00, 0xBE07, 0x70EB, 0x600A, 0x1646, 0x500B, 0x164C, 0x7C82, 0x0490, 0x440F, 0x450F, 0x460F, 0x0001, 0x0C67, 0xADB7, 
    /*0x0140*/ 0x0877, 0x1881, 0x8D29, 0xB60D, 0x0877, 0x8A00, 0xBE04, 0x0000, 0x0C81, 0x740F, 0x04B1, 0x0877, 0x8A01, 0xBE03, 0x0001, 0x0C81, 
    /*0x0160*/ 0x540F, 0x0878, 0x187F, 0x8D29, 0xB605, 0x0878, 0x8A05, 0x9602, 0x0878, 0x0C7F, 0x0884, 0x8801, 0x0C84, 0x0884, 0x8A1D, 0x9E21, 
    /*0x0180*/ 0x0000, 0x0C84, 0x7007, 0x1653, 0xF502, 0xFD47, 0xFD47, 0xFD47, 0x7041, 0x1462, 0xFB4D, 0x8609, 0x7101, 0x6431, 0x2531, 0xA6FE, 
    /*0x01A0*/ 0xFB00, 0x7078, 0xFB54, 0x7018, 0xFB4C, 0x7003, 0xFB4C, 0xFD47, 0xFB4C, 0x1465, 0x6403, 0x001F, 0x8B2C, 0xFDB1, 0x8902, 0x0C7D, 
    /*0x01C0*/ 0x1660, 0x5006, 0x164C, 0x7C7E, 0x5004, 0x164C, 0x7C83, 0x500B, 0x164C, 0x7C82, 0x701E, 0x600E, 0x1646, 0x0881, 0x8A00, 0xB601, 
    /*0x01E0*/ 0x060C, 0x0882, 0x8A01, 0xB601, 0x060B, 0x087F, 0x8A00, 0xBE02, 0x440E, 0x053B, 0x087F, 0x8A01, 0xBE0D, 0x860E, 0x0210, 0x640E, 
    /*0x0200*/ 0x1011, 0x8500, 0xFD47, 0x440E, 0x104B, 0x8500, 0xFD47, 0x88FF, 0xBEF6, 0x053B, 0x087F, 0x8A02, 0xBE0D, 0x860E, 0x0210, 0x640E, 
    /*0x0220*/ 0x1025, 0x8500, 0xFD47, 0x440E, 0x1037, 0x8500, 0xFD47, 0x88FF, 0xBEF6, 0x053B, 0x087F, 0x8A03, 0xBE0D, 0x860E, 0x0210, 0x640E, 
    /*0x0240*/ 0x1039, 0x8500, 0xFD47, 0x440E, 0x1023, 0x8500, 0xFD47, 0x88FF, 0xBEF6, 0x053B, 0x087F, 0x8A04, 0xBE0D, 0x860E, 0x0210, 0x640E, 
    /*0x0260*/ 0x104D, 0x8500, 0xFD47, 0x440E, 0x100F, 0x8500, 0xFD47, 0x88FF, 0xBEF6, 0x053B, 0x640E, 0x701E, 0x600E, 0x1646, 0x7001, 0x1653, 
    /*0x0280*/ 0xF502, 0xFD47, 0xFD47, 0xFD47, 0x7041, 0x1462, 0xFB4D, 0x8609, 0x7101, 0x6431, 0x2531, 0xA6FE, 0xFB00, 0x7078, 0xFB54, 0x7018, 
    /*0x02A0*/ 0xFB4C, 0x7003, 0xFB4C, 0xFD47, 0xFB4C, 0x1465, 0x6403, 0x001F, 0x8B2C, 0xFDB1, 0x8902, 0x0C79, 0x1660, 0x7003, 0x1653, 0xF502, 
    /*0x02C0*/ 0xFD47, 0xFD47, 0xFD47, 0x7041, 0x1462, 0xFB4D, 0x8609, 0x7101, 0x6431, 0x2531, 0xA6FE, 0xFB00, 0x7078, 0xFB54, 0x7018, 0xFB4C, 
    /*0x02E0*/ 0x7003, 0xFB4C, 0xFD47, 0xFB4C, 0x1465, 0x6403, 0x001F, 0x8B2C, 0xFDB1, 0x8902, 0x0C7A, 0x1660, 0x440E, 0x701E, 0x600E, 0x1646, 
    /*0x0300*/ 0x087F, 0x8A00, 0xBE02, 0x460E, 0x05C6, 0x087F, 0x8A01, 0xBE0D, 0x860E, 0x0210, 0x660E, 0x1011, 0x8500, 0xFD47, 0x460E, 0x104B, 
    /*0x0320*/ 0x8500, 0xFD47, 0x88FF, 0xBEF6, 0x05C6, 0x087F, 0x8A02, 0xBE0D, 0x860E, 0x0210, 0x660E, 0x1025, 0x8500, 0xFD47, 0x460E, 0x1037, 
    /*0x0340*/ 0x8500, 0xFD47, 0x88FF, 0xBEF6, 0x05C6, 0x087F, 0x8A03, 0xBE0D, 0x860E, 0x0210, 0x660E, 0x1039, 0x8500, 0xFD47, 0x460E, 0x1023, 
    /*0x0360*/ 0x8500, 0xFD47, 0x88FF, 0xBEF6, 0x05C6, 0x087F, 0x8A04, 0xBE0D, 0x860E, 0x0210, 0x660E, 0x104D, 0x8500, 0xFD47, 0x460E, 0x100F, 
    /*0x0380*/ 0x8500, 0xFD47, 0x88FF, 0xBEF6, 0x05C6, 0x660E, 0x701E, 0x600E, 0x1646, 0x7001, 0x1653, 0xF502, 0xFD47, 0xFD47, 0xFD47, 0x7041, 
    /*0x03A0*/ 0x1462, 0xFB4D, 0x8609, 0x7101, 0x6431, 0x2531, 0xA6FE, 0xFB00, 0x7078, 0xFB54, 0x7018, 0xFB4C, 0x7003, 0xFB4C, 0xFD47, 0xFB4C, 
    /*0x03C0*/ 0x1465, 0x6403, 0x001F, 0x8B2C, 0xFDB1, 0x8902, 0x0C7B, 0x1660, 0x7003, 0x1653, 0xF502, 0xFD47, 0xFD47, 0xFD47, 0x7041, 0x1462, 
    /*0x03E0*/ 0xFB4D, 0x8609, 0x7101, 0x6431, 0x2531, 0xA6FE, 0xFB00, 0x7078, 0xFB54, 0x7018, 0xFB4C, 0x7003, 0xFB4C, 0xFD47, 0xFB4C, 0x1465, 
    /*0x0400*/ 0x6403, 0x001F, 0x8B2C, 0xFDB1, 0x8902, 0x0C7C, 0x1660, 0x460E, 0x701E, 0x600E, 0x1646, 0x0614, 0x0000, 0x0C79, 0x0000, 0x0C7A, 
    /*0x0420*/ 0x0000, 0x0C7B, 0x0000, 0x0C7C, 0x0880, 0x8A00, 0xBE07, 0x087D, 0x1876, 0x8D29, 0xA602, 0x0001, 0x0C80, 0x062A, 0x0880, 0x8A01, 
    /*0x0440*/ 0xBE07, 0x087D, 0x1875, 0x8D29, 0x9E02, 0x0000, 0x0C80, 0x062A, 0x0000, 0x0C80, 0x0883, 0x8A01, 0xBE02, 0x660F, 0x0630, 0x460F, 
    /*0x0460*/ 0x087E, 0x8A00, 0xBE02, 0x650F, 0x0636, 0x450F, 0x0880, 0x8A01, 0xBE02, 0x640F, 0x063C, 0x440F, 0x70EB, 0x600A, 0x1646, 0x086C, 
    /*0x0480*/ 0x8201, 0x0C6C, 0x0001, 0x0C67, 0xADB7, 0xADB7, 0xFB0C, 0xEDA4, 0xEB09, 0x640B, 0xCDB1, 0xADB7, 0xE913, 0xEDA0, 0xF912, 0xFD0E, 
    /*0x04A0*/ 0xFD8D, 0xF001, 0xADB7, 0xF007, 0x1462, 0x86FF, 0x63F8, 0xEB51, 0x8680, 0x6000, 0xED8F, 0xEB49, 0xFD47, 0xEB49, 0x1465, 0xADB7, 
    /*0x04C0*/ 0x1462, 0x7079, 0xFB55, 0x71FB, 0xFB54, 0xFD47, 0xFB54, 0x1465, 0x4431, 0x4400, 0xADB7
};


/// Look-up table that converts from AUX I/O index to MCU IOCFG offset
static const uint8_t pAuxIoIndexToMcuIocfgOffsetLut[] = {
    56, 52, 48, 44, 36, 40, 32, 28, 16, 12, 8, 4, 0, 0, 0, 0
};


/** \brief Look-up table of data structure information for each task
  *
  * There is one entry per data structure (\c cfg, \c input, \c output and \c state) per task:
  * - [31:20] Data structure size (number of 16-bit words)
  * - [19:12] Buffer count (when 2+, first data structure is preceded by buffering control variables)
  * - [11:0] Address of the first data structure
  */
static const uint32_t pScifTaskDataStructInfoLut[] = {
//  cfg         input       output      state       
    0x002010EA, 0x002010EE, 0x00B010F2, 0x00101108  // Dusk2Dawn
};




// No run-time logging task data structure signatures needed in this project




// No task-specific initialization functions




// No task-specific uninitialization functions




/** \brief Initilializes task resource hardware dependencies
  *
  * This function is called by the internal driver initialization function, \ref scifInit().
  */
static void scifTaskResourceInit(void) {
    scifInitIo(1, AUXIOMODE_ANALOG, -1, 0);
    scifInitIo(3, AUXIOMODE_ANALOG, -1, 0);
    scifInitIo(7, AUXIOMODE_ANALOG, -1, 0);
    scifInitIo(4, AUXIOMODE_INPUT, -1, 0);
    scifInitIo(6, AUXIOMODE_INPUT, -1, 0);
    scifInitIo(11, AUXIOMODE_INPUT, -1, 0);
    scifInitIo(2, AUXIOMODE_OUTPUT | (0 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 0);
    scifInitIo(0, AUXIOMODE_OUTPUT | (0 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 0);
    scifInitIo(5, AUXIOMODE_OUTPUT | (0 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 0);
    scifInitIo(9, AUXIOMODE_OUTPUT | (2 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 0);
    scifInitIo(8, AUXIOMODE_OUTPUT | (2 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 0);
    scifInitIo(10, AUXIOMODE_OUTPUT | (2 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 0);
    scifInitIo(12, AUXIOMODE_OUTPUT | (0 << BI_AUXIOMODE_OUTPUT_DRIVE_STRENGTH), -1, 0);
} // scifTaskResourceInit




/** \brief Uninitilializes task resource hardware dependencies
  *
  * This function is called by the internal driver uninitialization function, \ref scifUninit().
  */
static void scifTaskResourceUninit(void) {
    scifUninitIo(1, -1);
    scifUninitIo(3, -1);
    scifUninitIo(7, -1);
    scifUninitIo(4, -1);
    scifUninitIo(6, -1);
    scifUninitIo(11, -1);
    scifUninitIo(2, -1);
    scifUninitIo(0, -1);
    scifUninitIo(5, -1);
    scifUninitIo(9, -1);
    scifUninitIo(8, -1);
    scifUninitIo(10, -1);
    scifUninitIo(12, -1);
} // scifTaskResourceUninit




/** \brief Re-initializes I/O pins used by the specified tasks
  *
  * It is possible to stop a Sensor Controller task and let the System CPU borrow and operate its I/O
  * pins. For example, the Sensor Controller can operate an SPI interface in one application state while
  * the System CPU with SSI operates the SPI interface in another application state.
  *
  * This function must be called before \ref scifExecuteTasksOnceNbl() or \ref scifStartTasksNbl() if
  * I/O pins belonging to Sensor Controller tasks have been borrowed System CPU peripherals.
  *
  * \param[in]      bvTaskIds
  *     Bit-vector of task IDs for the task I/Os to be re-initialized
  */
void scifReinitTaskIo(uint32_t bvTaskIds) {
    if (bvTaskIds & (1 << SCIF_DUSK2DAWN_TASK_ID)) {
        scifReinitIo(1, -1, 0);
        scifReinitIo(3, -1, 0);
        scifReinitIo(7, -1, 0);
        scifReinitIo(4, -1, 0);
        scifReinitIo(6, -1, 0);
        scifReinitIo(11, -1, 0);
        scifReinitIo(2, -1, 0);
        scifReinitIo(0, -1, 0);
        scifReinitIo(5, -1, 0);
        scifReinitIo(9, -1, 2);
        scifReinitIo(8, -1, 2);
        scifReinitIo(10, -1, 2);
        scifReinitIo(12, -1, 0);
    }
} // scifReinitTaskIo




/// Driver setup data, to be used in the call to \ref scifInit()
const SCIF_DATA_T scifDriverSetup = {
    (volatile SCIF_INT_DATA_T*) 0x400E00D6,
    (volatile SCIF_TASK_CTRL_T*) 0x400E00E0,
    (volatile uint16_t*) 0x400E00CE,
    0x0000,
    sizeof(pAuxRamImage),
    pAuxRamImage,
    pScifTaskDataStructInfoLut,
    pAuxIoIndexToMcuIocfgOffsetLut,
    scifTaskResourceInit,
    scifTaskResourceUninit,
    (volatile uint16_t*) NULL,
    (volatile uint16_t*) NULL,
    NULL
};




/** \brief Starts or modifies RTC-based task scheduling tick generation
  *
  * RTC-based tick generation will wake up the Sensor Controller first at the specified value of the RTC
  * and then periodically at the specified interval. The application must call this function after
  * calling \ref scifInit().
  *
  * The application must ensure that:
  * - \a tickStart is not in the past (prefer using \ref scifStartRtcTicksNow() to avoid this)
  * - \a tickPeriod is not too short. RTC ticks will be skipped silently if the Sensor Controller does
  *   not complete its tasks within a single tick interval.
  *
  * \param[in]      tickStart
  *     RTC value when the first tick is generated:
  *     - Bits 31:16 = seconds
  *     - Bits 15:0 = 1/65536 of a second
  * \param[in]      tickPeriod
  *     Interval at which subsequent ticks are generated:
  *     - Bits 31:16 = seconds
  *     - Bits 15:0 = 1/65536 of a second
  */
void scifStartRtcTicks(uint32_t tickStart, uint32_t tickPeriod) {
    HWREG(AON_RTC_BASE + AON_RTC_O_CH2CMP) = tickStart;
    HWREG(AON_RTC_BASE + AON_RTC_O_CH2CMPINC) = tickPeriod;
    HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) |= AON_RTC_CHCTL_CH2_EN_M | AON_RTC_CHCTL_CH2_CONT_EN_M;
    HWREG(AON_EVENT_BASE + AON_EVENT_O_AUXWUSEL) =
        (HWREG(AON_EVENT_BASE + AON_EVENT_O_AUXWUSEL) & ~AON_EVENT_AUXWUSEL_WU0_EV_M) |
        (AON_EVENT_AUXWUSEL_WU0_EV_RTC_CH2);
} // scifStartRtcTicks




/** \brief Starts or modifies RTC-based task scheduling tick generation
  *
  * RTC-based tick generation will wake up the Sensor Controller first after approximately 128 us and
  * then periodically at the specified interval. The application must call this function after calling
  * \ref scifInit().
  *
  * The application must ensure that \a tickPeriod is not too short. RTC ticks will be skipped silently
  * if the Sensor Controller does not complete its tasks within a single tick interval.
  *
  * \param[in]      tickPeriod
  *     Interval at which subsequent ticks are generated:
  *     - Bits 31:16 = seconds
  *     - Bits 15:0 = 1/65536 of a second
  */
void scifStartRtcTicksNow(uint32_t tickPeriod) {
    uint32_t key, sec, subsec;
    key = scifOsalEnterCriticalSection();
    sec = HWREG(AON_RTC_BASE + AON_RTC_O_SEC);
    subsec = HWREG(AON_RTC_BASE + AON_RTC_O_SUBSEC);
    scifStartRtcTicks(((sec << 16) | (subsec >> 16)) + 8, tickPeriod);
    scifOsalLeaveCriticalSection(key);
} // scifStartRtcTicksNow




/** \brief Stops RTC-based task scheduling tick generation
  *
  * The application must call this function before calling \ref scifUninit().
  */
void scifStopRtcTicks(void) {
    HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) &= ~(AON_RTC_CHCTL_CH2_EN_M | AON_RTC_CHCTL_CH2_CONT_EN_M);
    HWREG(AON_EVENT_BASE + AON_EVENT_O_AUXWUSEL) =
        (HWREG(AON_EVENT_BASE + AON_EVENT_O_AUXWUSEL) & ~AON_EVENT_AUXWUSEL_WU0_EV_M) |
        (AON_EVENT_AUXWUSEL_WU0_EV_NONE);
    HWREG(AON_RTC_BASE + AON_RTC_O_SYNC);
} // scifStopRtcTicks


//@}


// Generated by JOSEPH-LAPTOP at 2023-04-11 17:18:57.178
