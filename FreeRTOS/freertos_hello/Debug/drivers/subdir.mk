################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKV31F512VLL12 -DCPU_MKV31F512VLL12_cm4 -DFRDM_KV31F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\source" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\drivers" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\device" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\utilities" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\component\uart" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\component\serial_manager" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\component\lists" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\CMSIS" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\freertos\freertos-kernel\include" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_lpuart.d ./drivers/fsl_lpuart.o ./drivers/fsl_smc.d ./drivers/fsl_smc.o ./drivers/fsl_uart.d ./drivers/fsl_uart.o

.PHONY: clean-drivers

