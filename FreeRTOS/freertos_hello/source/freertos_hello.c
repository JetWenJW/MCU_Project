/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_common.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

QueueHandle_t xLedQueue;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void ControlTask(void *pvParameters);
void CyanTask	(void *pvParameters);
void PurpleTask	(void *pvParameters);
void YellowTask	(void *pvParameters);



/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();


    xLedQueue = xQueueCreate(10, sizeof(int));

    // 创建任务
    xTaskCreate(ControlTask, 	"Producer", 	configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(YellowTask, 	"RedGreen",		configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(PurpleTask, 	"RedBlue", 		configMINIMAL_STACK_SIZE, NULL,	1, NULL);
    xTaskCreate(CyanTask, 		"GreenBlue", 	configMINIMAL_STACK_SIZE, NULL,	1, NULL);

    /* Start scheduling. */
    vTaskStartScheduler();
    for (;;)
        ;
}


void ControlTask(void *pvParameters)
{
    int ledSignal = 0;

    while (1)
    {
        ledSignal = (ledSignal + 1) % 3; // 生成新的LED信号
        // 向Queue发送信号
        xQueueSend(xLedQueue, &ledSignal, portMAX_DELAY);

        //vTaskDelay(pdMS_TO_TICKS(3000)); // 模拟生产延时
    }
}

// 新的消费者任务
void YellowTask(void *pvParameters)
{
    int receivedLedSignal;

    while (1)
    {
        if (xQueueReceive(xLedQueue, &receivedLedSignal, portMAX_DELAY) == pdTRUE)
        {
            if (receivedLedSignal == 0) // 如果收到的信号是3，点亮红色和绿色LED
            {
                vTaskDelay(pdMS_TO_TICKS(1000));
                GPIO_PortClear(GPIOD, 1 << 1); // LED Red ON
                GPIO_PortClear(GPIOD, 1 << 7); // LED Green ON
                vTaskDelay(pdMS_TO_TICKS(1000));
                GPIO_PortToggle(GPIOD, 1 << 1); // LED Red OFF
                GPIO_PortToggle(GPIOD, 1 << 7); // LED Green OFF

                PRINTF("RED_GREEN = Yellow \r\n");

            }
        }
    }
}

void PurpleTask(void *pvParameters)
{
    int receivedLedSignal;


    while (1)
    {
        if (xQueueReceive(xLedQueue, &receivedLedSignal, portMAX_DELAY) == pdTRUE)
        {
            if (receivedLedSignal == 1)
            {
                vTaskDelay(pdMS_TO_TICKS(1000));
                GPIO_PortClear(GPIOD, 1 << 1); // LED Red ON
                GPIO_PortClear(GPIOE, 1 << 25); // LED Green ON


                vTaskDelay(pdMS_TO_TICKS(1000));
                GPIO_PortToggle(GPIOD, 1 << 1); // LED Red OFF
                GPIO_PortToggle(GPIOE, 1 << 25); // LED Green OFF
                PRINTF("RED_BLUE = Purple\r\n");

            }
        }
    }
}

void CyanTask(void *pvParameters)
{
    int receivedLedSignal;


    while (1)
    {
        if (xQueueReceive(xLedQueue, &receivedLedSignal, portMAX_DELAY) == pdTRUE)
        {
            if (receivedLedSignal == 2)
            {
                vTaskDelay(pdMS_TO_TICKS(1000));
                GPIO_PortClear(GPIOE, 1 << 25); // LED Red ON
                GPIO_PortClear(GPIOD, 1 << 7); // LED Green ON

                vTaskDelay(pdMS_TO_TICKS(1000));
                GPIO_PortToggle(GPIOE, 1 << 25); // LED Red OFF
                GPIO_PortToggle(GPIOD, 1 << 7); // LED Green OFF
                PRINTF("BLUE_GREEN = Cyan\r\n");

            }
        }
    }
}
