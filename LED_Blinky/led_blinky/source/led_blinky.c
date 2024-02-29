/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIO     BOARD_LED_RED_GPIO
#define BOARD_LED_GPIO_PIN BOARD_LE_RED_PIN

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint32_t g_systickCounter;

/*******************************************************************************
 * Code
 ******************************************************************************/
void SysTick_Handler(void)
{
    if (g_systickCounter != 0U)
    {
        g_systickCounter--;
    }
}

void SysTick_DelayTicks(uint32_t n)
{
    g_systickCounter = n;
    while (g_systickCounter != 0U)
    {
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Board pin init */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    /* Set systick reload value to generate 1ms interrupt */
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
        while (1)
        {
        }
    }

    while (1)
    {
        /* RGB Switch Automatically */
        SysTick_DelayTicks(1000);
        GPIO_PortToggle(GPIOD, 1 << 1);		/* LED Red */
        SysTick_DelayTicks(1000);
        GPIO_PortToggle(GPIOD, 1 << 1);		/* LED Red */
        SysTick_DelayTicks(1000);
        GPIO_PortToggle(GPIOD, 1 << 7);		/* LED Green */
        SysTick_DelayTicks(1000);
        GPIO_PortToggle(GPIOD, 1 << 7);		/* LED Green */
        SysTick_DelayTicks(1000);
        GPIO_PortToggle(GPIOE, 1 << 25);	/* LED Blue*/
        SysTick_DelayTicks(1000);
        GPIO_PortToggle(GPIOE, 1 << 25);	/* LED Blue*/

        //SysTick_DelayTicks(1000);
        //GPIO_PortClear(GPIOE, 1 << 25);

    }
}
