################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv8/tools/compiler/ti-cgt-arm_5.2.6

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Application/baseloaderentry_ti.obj" \
"./Application/bim_main.obj" \
"./Application/bls_bsp.obj" \
"./Application/ccfg_app_ble.obj" \
"./Application/startup_ccs.obj" \
"./ExternalFlash/ext_flash.obj" \
"./SPI/bsp_spi.obj" \
"C:/ti/simplelink/ble_sdk_2_02_01_18/src/common/cc26xx/ccs/cc26xx_bim_ext_flash.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-ldriverlib.lib \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include Application/subdir_vars.mk
-include ExternalFlash/subdir_vars.mk
-include SPI/subdir_vars.mk
-include TOOLS/subdir_vars.mk
-include Application/subdir_rules.mk
-include ExternalFlash/subdir_rules.mk
-include SPI/subdir_rules.mk
-include TOOLS/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
bim_extflash.out \

EXE_OUTPUTS__QUOTED += \
"bim_extflash.out" \

BIN_OUTPUTS += \
bim_extflash.hex \

BIN_OUTPUTS__QUOTED += \
"bim_extflash.hex" \


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "bim_extflash.out"

# Tool invocations
bim_extflash.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --c99 --define=BOOT_LOADER --define=CC2650ST_0120 --define=DEBUG --define=ccs --define=xNO_COPY --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on -z -m"bim_extflash.map" --stack_size=256 --heap_size=0 -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_5.2.6/lib" -i"C:/ti/tirtos_cc13xx_cc26xx_2_20_01_08/products/cc26xxware_2_24_02_17393/driverlib/bin/ccs/" -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_5.2.6/include" --reread_libs --define=KEEP_INTVECS=1 --diag_wrap=off --display_error_number --warn_sections --xml_link_info="bim_extflash_linkInfo.xml" --retain=BaseLoader_start --retain=LoadEntry --rom_model -o "bim_extflash.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

bim_extflash.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_5.2.6/bin/armhex" --memwidth=8 --romwidth=8 --intel -o "bim_extflash.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Application\baseloaderentry_ti.obj" "Application\bim_main.obj" "Application\bls_bsp.obj" "Application\ccfg_app_ble.obj" "Application\startup_ccs.obj" "ExternalFlash\ext_flash.obj" "SPI\bsp_spi.obj" 
	-$(RM) "Application\bim_main.d" "Application\bls_bsp.d" "Application\ccfg_app_ble.d" "Application\startup_ccs.d" "ExternalFlash\ext_flash.d" "SPI\bsp_SPI.d" 
	-$(RM) "Application\baseloaderentry_ti.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_5.2.6/bin/armhex"  -order MS --memwidth=8 --romwidth=8 --intel -o "bim_extflash.hex" "bim_extflash"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

