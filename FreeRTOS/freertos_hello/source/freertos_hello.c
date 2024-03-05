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
void Blinky_Task	(void *pvParameters);
void switch_task	(void *pvParameters);
void Control_task	(void *pvParameters);
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int ledSignal = 0;



int main(void)
{
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();


    xLedQueue = xQueueCreate(10, sizeof(int));

    xTaskCreate(Blinky_Task, 	"Blinky", 		configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(switch_task, 	"switch", 		configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(Control_task, 	"Control", 		configMINIMAL_STACK_SIZE, NULL, 1, NULL);


    /* Start scheduling. */
    vTaskStartScheduler();
    for (;;)
        ;
}


void Blinky_Task(void *pvParameters)
{

    while (1)
    {
    	ledSignal = (ledSignal + 1) % 3;
        xQueueSend(xLedQueue, &ledSignal, portMAX_DELAY);
        taskYIELD();

    }
}


void Control_task(void *pvParameters)
{

    while (1)
    {

    	ledSignal = (ledSignal + 3) % 6;
        xQueueSend(xLedQueue, &ledSignal, portMAX_DELAY);
        taskYIELD();

    }
}


void switch_task(void *pvParameters)
{

	int receivedLedSignal;

    while(1)
    {
    	if (xQueueReceive(xLedQueue, &receivedLedSignal, portMAX_DELAY) == pdTRUE)
    	{
            /* Switch LED Colour */
            switch(receivedLedSignal)
            {
                case 0:

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 1);		/* LED Red ON */

                    vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 1);		/* LED Red OFF */
                    PRINTF("RED \r\n");

                    break;
                case 1:

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 7);		/* LED Green */

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 7);		/* LED Green */
                    PRINTF("Green \r\n");

                    break;
                case 2:

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOE, 1 << 25);	/* LED Blue ON */

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOE, 1 << 25);	/* LED Blue OFF */
                    PRINTF("Blue \r\n");

                    break;

                case 3:
                    vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortClear(GPIOD, 1 << 1); // LED Red ON
                    GPIO_PortClear(GPIOD, 1 << 7); // LED Green ON

                    vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 1); // LED Red OFF
                    GPIO_PortToggle(GPIOD, 1 << 7); // LED Green OFF
                    PRINTF("RED_GREEN = Yellow \r\n");
                    break;

                case 4:
                    vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortClear(GPIOD, 1 << 1); // LED Red ON
                    GPIO_PortClear(GPIOE, 1 << 25); // LED Green ON

                    vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 1); // LED Red OFF
                    GPIO_PortToggle(GPIOE, 1 << 25); // LED Green OFF
                    PRINTF("RED_BLUE = Purple\r\n");
                    break;

                case 5:
                    vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortClear(GPIOE, 1 << 25); // LED Red ON
                    GPIO_PortClear(GPIOD, 1 << 7); // LED Green ON

                    vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOE, 1 << 25); // LED Red OFF
                    GPIO_PortToggle(GPIOD, 1 << 7); // LED Green OFF
                    PRINTF("BLUE_GREEN = Cyan\r\n");
                    break;
            }
    	}
    }
}
