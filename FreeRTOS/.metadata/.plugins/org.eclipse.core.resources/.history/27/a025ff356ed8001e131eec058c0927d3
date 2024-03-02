/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* FreeRTOS kernel includes. */
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
SemaphoreHandle_t xMutex;





/* Task priorities. */
#define hello_task_PRIORITY 		(configMAX_PRIORITIES - 1)
#define led_red_task_PRIORITY 		(configMAX_PRIORITIES - 2)
#define led_blue_task_PRIORITY 		(configMAX_PRIORITIES - 3)
#define led_green_task_PRIORITY 	(configMAX_PRIORITIES - 4)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void hello_task	(void *pvParameters);
static void LED_RED		(void *pvParameters);
static void LED_BLUE	(void *pvParameters);
static void LED_GREEN	(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */
int main(void)
{
	xMutex = xSemaphoreCreateMutex();


    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    if (xTaskCreate(hello_task, "Hello_task", configMINIMAL_STACK_SIZE + 100, NULL, hello_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(LED_RED, "led_red", configMINIMAL_STACK_SIZE + 100, NULL, led_red_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(LED_BLUE, "led_blue", configMINIMAL_STACK_SIZE + 100, NULL, led_blue_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(LED_GREEN, "led_green", configMINIMAL_STACK_SIZE + 100, NULL, led_green_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }




    vTaskStartScheduler();
    for (;;)
        ;
}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void hello_task(void *pvParameters)
{
    for (;;)
    {
    	/* Take Mutex first */
    	if (xSemaphoreTake(xMutex, portMAX_DELAY) != pdTRUE)
        {
    		PRINTF("Failed to take semaphore.\r\n");
    	}
        PRINTF("Hello world.\r\n");

        xSemaphoreGive(xMutex);
        vTaskSuspend(NULL);

    }
}


static void LED_RED(void *pvParameters)
{
    for (;;)
    {

    	 if (xSemaphoreTake(xMutex, portMAX_DELAY) != pdTRUE)
    	 {
    		 PRINTF("Failed to take semaphore.\r\n");
         }
    	vTaskDelay(pdMS_TO_TICKS(1000));
        GPIO_PortToggle(GPIOD, 1 << 1);		/* LED Red ON */

        vTaskDelay(pdMS_TO_TICKS(1000));
        GPIO_PortToggle(GPIOD, 1 << 1);		/* LED Red OFF */
        xSemaphoreGive(xMutex);

        vTaskSuspend(NULL);
    }
}


static void LED_BLUE(void *pvParameters)
{
    for (;;)
    {
    	if (xSemaphoreTake(xMutex, portMAX_DELAY) != pdTRUE)
    	{
    		PRINTF("Failed to take semaphore.\r\n");
        }
    	vTaskDelay(pdMS_TO_TICKS(1000));
        GPIO_PortToggle(GPIOE, 1 << 25);	/* LED Blue ON */

    	vTaskDelay(pdMS_TO_TICKS(1000));
        GPIO_PortToggle(GPIOE, 1 << 25);	/* LED Blue OFF */
        xSemaphoreGive(xMutex);

        vTaskSuspend(NULL);
    }
}


static void LED_GREEN(void *pvParameters)
{
    for (;;)
    {
    	if (xSemaphoreTake(xMutex, portMAX_DELAY) != pdTRUE)
    	{
    		PRINTF("Failed to take semaphore.\r\n");
    	}
    	vTaskDelay(pdMS_TO_TICKS(1000));
        GPIO_PortToggle(GPIOD, 1 << 7);		/* LED Green */

    	vTaskDelay(pdMS_TO_TICKS(1000));
        GPIO_PortToggle(GPIOD, 1 << 7);		/* LED Green */
        xSemaphoreGive(xMutex);

        vTaskSuspend(NULL);
    }
}
