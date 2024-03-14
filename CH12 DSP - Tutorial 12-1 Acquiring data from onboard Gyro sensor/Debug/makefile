################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_HOST/Target/subdir.mk
-include USB_HOST/App/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/STM32F429I-Discovery/subdir.mk
-include Drivers/BSP/Components/wm8994/subdir.mk
-include Drivers/BSP/Components/ts3510/subdir.mk
-include Drivers/BSP/Components/stmpe811/subdir.mk
-include Drivers/BSP/Components/stmpe1600/subdir.mk
-include Drivers/BSP/Components/st7789h2/subdir.mk
-include Drivers/BSP/Components/st7735/subdir.mk
-include Drivers/BSP/Components/s5k5cag/subdir.mk
-include Drivers/BSP/Components/ov5640/subdir.mk
-include Drivers/BSP/Components/ov2640/subdir.mk
-include Drivers/BSP/Components/otm8009a/subdir.mk
-include Drivers/BSP/Components/nt35510/subdir.mk
-include Drivers/BSP/Components/mfxstm32l152/subdir.mk
-include Drivers/BSP/Components/lsm303dlhc/subdir.mk
-include Drivers/BSP/Components/lsm303agr/subdir.mk
-include Drivers/BSP/Components/ls016b8uy/subdir.mk
-include Drivers/BSP/Components/lis3dsh/subdir.mk
-include Drivers/BSP/Components/lis302dl/subdir.mk
-include Drivers/BSP/Components/lan8742/subdir.mk
-include Drivers/BSP/Components/l3gd20/subdir.mk
-include Drivers/BSP/Components/ili9341/subdir.mk
-include Drivers/BSP/Components/ili9325/subdir.mk
-include Drivers/BSP/Components/i3g4250d/subdir.mk
-include Drivers/BSP/Components/ft6x06/subdir.mk
-include Drivers/BSP/Components/ft3x67/subdir.mk
-include Drivers/BSP/Components/exc7200/subdir.mk
-include Drivers/BSP/Components/dp83848/subdir.mk
-include Drivers/BSP/Components/cs43l22/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := CH12 DSP - Tutorial 12-1 Acquiring data from onboard Gyro sensor
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.elf \

MAP_FILES += \
CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.list \


# All Target
all: main-build

# Main-build Target
main-build: CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.elf secondary-outputs

# Tool invocations
CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.elf CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.map: $(OBJS) $(USER_OBJS) C:\Users\MFIBADEK\STM32CubeIDE\Embedded-systems-course-tutorials-with-ARM-Cortex-M-MCU-and-STM32CUBEIDE\CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor\STM32F429ZITX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CH12 DSP - Tutorial 12-1 Acquiring data from onboard Gyro sensor.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MFIBADEK\STM32CubeIDE\Embedded-systems-course-tutorials-with-ARM-Cortex-M-MCU-and-STM32CUBEIDE\CH12 DSP - Tutorial 12-1 Acquiring data from onboard Gyro sensor\STM32F429ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CH12 DSP - Tutorial 12-1 Acquiring data from onboard Gyro sensor.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CH12 DSP - Tutorial 12-1 Acquiring data from onboard Gyro sensor.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.elf CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.list CH12\ DSP\ -\ Tutorial\ 12-1\ Acquiring\ data\ from\ onboard\ Gyro\ sensor.map CH12\\ DSP\\ -\\ Tutorial\\ 12-1\\ Acquiring\\ data\\ from\\ onboard\\ Gyro\\ sensor.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
