################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/freertos-kernel/portable/MemMang/heap_4.c 

C_DEPS += \
./freertos/freertos-kernel/portable/MemMang/heap_4.d 

OBJS += \
./freertos/freertos-kernel/portable/MemMang/heap_4.o 


# Each subdirectory must supply rules for building sources it contributes
freertos/freertos-kernel/portable/MemMang/%.o: ../freertos/freertos-kernel/portable/MemMang/%.c freertos/freertos-kernel/portable/MemMang/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKV31F512VLL12 -DCPU_MKV31F512VLL12_cm4 -DFRDM_KV31F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\source" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\drivers" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\device" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\utilities" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\component\uart" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\component\serial_manager" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\component\lists" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\CMSIS" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\freertos\freertos-kernel\include" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\FreeRTOS\freertos_hello\board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-freertos-2f-freertos-2d-kernel-2f-portable-2f-MemMang

clean-freertos-2f-freertos-2d-kernel-2f-portable-2f-MemMang:
	-$(RM) ./freertos/freertos-kernel/portable/MemMang/heap_4.d ./freertos/freertos-kernel/portable/MemMang/heap_4.o

.PHONY: clean-freertos-2f-freertos-2d-kernel-2f-portable-2f-MemMang

