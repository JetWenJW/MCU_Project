################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MKV31F51212.c 

C_DEPS += \
./device/system_MKV31F51212.d 

OBJS += \
./device/system_MKV31F51212.o 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKV31F512VLL12 -DCPU_MKV31F512VLL12_cm4 -DFRDM_KV31F -DFREEDOM -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\LED_Blinky\led_blinky\source" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\LED_Blinky\led_blinky\utilities" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\LED_Blinky\led_blinky\drivers" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\LED_Blinky\led_blinky\device" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\LED_Blinky\led_blinky\component\uart" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\LED_Blinky\led_blinky\component\lists" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\LED_Blinky\led_blinky\CMSIS" -I"C:\nxp\FRDM-KV31F\WorkSpace-11.8.1\FRDM-KV31\LED_Blinky\led_blinky\board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-device

clean-device:
	-$(RM) ./device/system_MKV31F51212.d ./device/system_MKV31F51212.o

.PHONY: clean-device

