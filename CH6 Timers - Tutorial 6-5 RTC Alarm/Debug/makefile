################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
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


BUILD_ARTIFACT_NAME := CH6 Timers - Tutorial 6-5 RTC Alarm
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.elf \

MAP_FILES += \
CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.list \


# All Target
all: main-build

# Main-build Target
main-build: CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.elf secondary-outputs

# Tool invocations
CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.elf CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.map: $(OBJS) $(USER_OBJS) C:\Users\MFIBADEK\STM32CubeIDE\Embedded_Education_STM32F4-DISCOVERY\CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm\STM32F429ZITX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CH6 Timers - Tutorial 6-5 RTC Alarm.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MFIBADEK\STM32CubeIDE\Embedded_Education_STM32F4-DISCOVERY\CH6 Timers - Tutorial 6-5 RTC Alarm\STM32F429ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CH6 Timers - Tutorial 6-5 RTC Alarm.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CH6 Timers - Tutorial 6-5 RTC Alarm.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.elf CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.list CH6\ Timers\ -\ Tutorial\ 6-5\ RTC\ Alarm.map CH6\\ Timers\\ -\\ Tutorial\\ 6-5\\ RTC\\ Alarm.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
