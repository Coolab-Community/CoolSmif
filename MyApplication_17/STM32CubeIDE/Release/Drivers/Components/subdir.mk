################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/TouchGFXProjects/4.13/MyApplication_17/Drivers/Components/ft5336/ft5336.c 

OBJS += \
./Drivers/Components/ft5336.o 

C_DEPS += \
./Drivers/Components/ft5336.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Components/ft5336.o: C:/TouchGFXProjects/4.13/MyApplication_17/Drivers/Components/ft5336/ft5336.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../TouchGFX/generated/gui_generated/include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../TouchGFX/App -I../../Middlewares/ST/touchgfx/framework/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../../TouchGFX/gui/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/images/include -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../TouchGFX/generated/fonts/include -I../../Drivers/Components/ft5336 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Components/ft5336.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

