
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
SemaphoreHandle_t xSemaphore = NULL;
volatile int ledColor = 0; // 0: Red, 1: Green, 2: Blue

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void consumerTask(void *pvParameters);
void producerTask(void *pvParameters);

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

    xSemaphore = xSemaphoreCreateBinary();
    xTaskCreate(producerTask, "Producer", 1000, NULL, 1, NULL);
    xTaskCreate(consumerTask, "Consumer", 1000, NULL, 1, NULL);


    /* Start scheduling. */
    vTaskStartScheduler();
    for (;;)
        ;
}


void producerTask(void *pvParameters)
{
    while(1)
    {
        /* Produce Item next color LED ON*/
        ledColor = (ledColor + 1) % 3; /* Color of LED  */

        /*Informed Poducer */
        xSemaphoreGive(xSemaphore);/* Semaphore Give */
        vTaskDelay(pdMS_TO_TICKS(1000)); //
    }
}

void consumerTask(void *pvParameters)
{
    while(1)
    {
        if(xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE)/* Semaphore Take */
        {
            /* Switch LED Colour */
            switch(ledColor)
            {
                case 0:

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 1);		/* LED Red ON */

                    vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 1);		/* LED Red OFF */
                    break;
                case 1:

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 7);		/* LED Green */

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOD, 1 << 7);		/* LED Green */
                    break;
                case 2:

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOE, 1 << 25);	/* LED Blue ON */

                	vTaskDelay(pdMS_TO_TICKS(1000));
                    GPIO_PortToggle(GPIOE, 1 << 25);	/* LED Blue OFF */
                    break;
            }
        }
    }
}
