################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
UltraSonic_Driver.lss \

FLASH_IMAGE += \
UltraSonic_Driver.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: UltraSonic_Driver.elf secondary-outputs

# Tool invocations
UltraSonic_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UltraSonic_Driver.map -mmcu=atmega32 -o "UltraSonic_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UltraSonic_Driver.lss: UltraSonic_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UltraSonic_Driver.elf  >"UltraSonic_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

UltraSonic_Driver.hex: UltraSonic_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex UltraSonic_Driver.elf  "UltraSonic_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UltraSonic_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 UltraSonic_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: UltraSonic_Driver.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -u -Uflash:w:UltraSonic_Driver.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) UltraSonic_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
