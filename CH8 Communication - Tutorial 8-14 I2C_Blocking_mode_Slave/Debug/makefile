################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
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


BUILD_ARTIFACT_NAME := CH8 Communication - Tutorial 8-14 I2C_Blocking_mode_Slave
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.elf \

MAP_FILES += \
CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.list \


# All Target
all: main-build

# Main-build Target
main-build: CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.elf secondary-outputs

# Tool invocations
CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.elf CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.map: $(OBJS) $(USER_OBJS) C:\Users\MFIBADEK\STM32CubeIDE\Embedded_Education_STM32F4-DISCOVERY\CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave\STM32L476RGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CH8 Communication - Tutorial 8-14 I2C_Blocking_mode_Slave.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MFIBADEK\STM32CubeIDE\Embedded_Education_STM32F4-DISCOVERY\CH8 Communication - Tutorial 8-14 I2C_Blocking_mode_Slave\STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CH8 Communication - Tutorial 8-14 I2C_Blocking_mode_Slave.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CH8 Communication - Tutorial 8-14 I2C_Blocking_mode_Slave.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.elf CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.list CH8\ Communication\ -\ Tutorial\ 8-14\ I2C_Blocking_mode_Slave.map CH8\\ Communication\\ -\\ Tutorial\\ 8-14\\ I2C_Blocking_mode_Slave.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
