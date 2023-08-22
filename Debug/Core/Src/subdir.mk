################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/GPIO.c \
../Core/Src/LED.c \
../Core/Src/SysClock.c \
../Core/Src/UART.c \
../Core/Src/adc.c \
../Core/Src/adc_demo.c \
../Core/Src/commandHandler.c \
../Core/Src/commands.c \
../Core/Src/converter.c \
../Core/Src/dac.c \
../Core/Src/demo.c \
../Core/Src/inputHandler.c \
../Core/Src/main.c \
../Core/Src/printf.c \
../Core/Src/songParser.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c \
../Core/Src/tone.c 

OBJS += \
./Core/Src/GPIO.o \
./Core/Src/LED.o \
./Core/Src/SysClock.o \
./Core/Src/UART.o \
./Core/Src/adc.o \
./Core/Src/adc_demo.o \
./Core/Src/commandHandler.o \
./Core/Src/commands.o \
./Core/Src/converter.o \
./Core/Src/dac.o \
./Core/Src/demo.o \
./Core/Src/inputHandler.o \
./Core/Src/main.o \
./Core/Src/printf.o \
./Core/Src/songParser.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o \
./Core/Src/tone.o 

C_DEPS += \
./Core/Src/GPIO.d \
./Core/Src/LED.d \
./Core/Src/SysClock.d \
./Core/Src/UART.d \
./Core/Src/adc.d \
./Core/Src/adc_demo.d \
./Core/Src/commandHandler.d \
./Core/Src/commands.d \
./Core/Src/converter.d \
./Core/Src/dac.d \
./Core/Src/demo.d \
./Core/Src/inputHandler.d \
./Core/Src/main.d \
./Core/Src/printf.d \
./Core/Src/songParser.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d \
./Core/Src/tone.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/GPIO.d ./Core/Src/GPIO.o ./Core/Src/GPIO.su ./Core/Src/LED.d ./Core/Src/LED.o ./Core/Src/LED.su ./Core/Src/SysClock.d ./Core/Src/SysClock.o ./Core/Src/SysClock.su ./Core/Src/UART.d ./Core/Src/UART.o ./Core/Src/UART.su ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/adc_demo.d ./Core/Src/adc_demo.o ./Core/Src/adc_demo.su ./Core/Src/commandHandler.d ./Core/Src/commandHandler.o ./Core/Src/commandHandler.su ./Core/Src/commands.d ./Core/Src/commands.o ./Core/Src/commands.su ./Core/Src/converter.d ./Core/Src/converter.o ./Core/Src/converter.su ./Core/Src/dac.d ./Core/Src/dac.o ./Core/Src/dac.su ./Core/Src/demo.d ./Core/Src/demo.o ./Core/Src/demo.su ./Core/Src/inputHandler.d ./Core/Src/inputHandler.o ./Core/Src/inputHandler.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/printf.d ./Core/Src/printf.o ./Core/Src/printf.su ./Core/Src/songParser.d ./Core/Src/songParser.o ./Core/Src/songParser.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su ./Core/Src/tone.d ./Core/Src/tone.o ./Core/Src/tone.su

.PHONY: clean-Core-2f-Src

