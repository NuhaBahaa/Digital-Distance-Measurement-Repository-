################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../EXT_INT_prog.c \
../Timer_prog.c \
../UltraSonic_prog.c \
../main.c 

OBJS += \
./DIO_Prog.o \
./EXT_INT_prog.o \
./Timer_prog.o \
./UltraSonic_prog.o \
./main.o 

C_DEPS += \
./DIO_Prog.d \
./EXT_INT_prog.d \
./Timer_prog.d \
./UltraSonic_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


