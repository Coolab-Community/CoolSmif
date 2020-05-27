################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/julien\ terrier/CoolSmif/MyApplication_17/Drivers/BSP/startup_stm32f746nghx.s 

OBJS += \
./startup_stm32f746nghx.o 


# Each subdirectory must supply rules for building sources it contributes
startup_stm32f746nghx.o: C:/Users/julien\ terrier/CoolSmif/MyApplication_17/Drivers/BSP/startup_stm32f746nghx.s
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

