################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-84545201:
	@$(MAKE) --no-print-directory -Onone -f TOOLS/subdir_rules.mk build-84545201-inproc

build-84545201-inproc: ../TOOLS/app_ble_uartlog.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_32_00_06_core/xs" --xdcpath="C:/ti/tirtos_cc13xx_cc26xx_2_20_01_08/packages;C:/ti/tirtos_cc13xx_cc26xx_2_20_01_08/products/tidrivers_cc13xx_cc26xx_2_20_01_10/packages;C:/ti/tirtos_cc13xx_cc26xx_2_20_01_08/products/bios_6_46_01_38/packages;C:/ti/tirtos_cc13xx_cc26xx_2_20_01_08/products/uia_2_00_06_52/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3 -p ti.platforms.simplelink:CC2650F128 -r release -c "C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_5.2.6" --compileOptions "-mv7M3 --code_state=16 --abi=eabi -me -O4 --opt_for_speed=0 --include_path=\"D:/Workspace/project_zero_app_cc2650launchxl\" --include_path=\"D:/Workspace/project_zero_app_cc2650launchxl/Profiles\" --include_path=\"D:/Workspace/project_zero_app_cc2650launchxl/Application\" --include_path=\"D:/Workspace/project_zero_app_cc2650launchxl/ICallBLE\" --include_path=\"D:/Workspace/project_zero_app_cc2650launchxl/Startup\" --include_path=\"D:/Workspace/project_zero_app_cc2650launchxl/Board\" --include_path=\"C:/ti/simplelink_academy_01_11_00_0000/modules/projects/support_files/Components/uart_log\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/examples/simple_peripheral/cc26xx/app\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/inc\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/icall/inc\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/profiles/roles/cc26xx\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/profiles/roles\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/profiles/dev_info\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/profiles/simple_profile/cc26xx\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/profiles/simple_profile\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/common/cc26xx\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/heapmgr\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/controller/cc26xx/inc\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/hal/src/target/_common\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/hal/src/target\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/hal/src/target/_common/cc26xx\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/hal/src/inc\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/osal/src/inc\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/services/src/sdata\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/services/src/saddr\" --include_path=\"C:/ti/simplelink/ble_sdk_2_02_01_18/src/components/icall/src/inc\" --include_path=\"C:/ti/tirtos_cc13xx_cc26xx_2_20_01_08/products/cc26xxware_2_24_02_17393\" --include_path=\"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_5.2.6/include\" -g --c99 --gcc --define=USE_ICALL --define=POWER_SAVING --define=SBP_TASK_STACK_SIZE=700 --define=GAPROLE_TASK_STACK_SIZE=520 --define=HEAPMGR_SIZE=0 --define=Display_DISABLE_ALL --define=BOARD_DISPLAY_EXCLUDE_UART --define=xBOARD_DISPLAY_EXCLUDE_LCD --define=ICALL_MAX_NUM_TASKS=3 --define=ICALL_MAX_NUM_ENTITIES=6 --define=xdc_runtime_Assert_DISABLE_ALL --define=Xxdc_runtime_Log_DISABLE_ALL --define=MAX_NUM_BLE_CONNS=1 --define=CC26XX --define=xdc_FILE=\"\"\"\" --define=UARTLOG_NUM_EVT_BUF=32 --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --printf_support=full  " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-84545201 ../TOOLS/app_ble_uartlog.cfg
configPkg/compiler.opt: build-84545201
configPkg/: build-84545201


