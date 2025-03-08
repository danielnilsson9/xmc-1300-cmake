/*
 * Copyright (C) 2015 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with
 * Infineon's microcontrollers.
 * This file can be freely distributed within development tools that are
 * supporting such microcontrollers.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

/**
 * @file
 * @date 01 Aug, 2015
 * @version 0.1.0
 *
 * @brief XMC1300 Boot kit blinky GPIO demo example
 *
 * The blinky example flashes the leds of the board with a periodic rate.
 * LED1 is connected to P0.6
 *
 * History <br>
 *
 * Version 1.0.0 Initial <br>
 *
 */

#include "xmc_gpio.h"
#include "xmc_common.h"

#define TICKS_PER_SECOND 1000
#define TICKS_WAIT 500

#define LED1 P0_6

void SysTick_Handler(void)
{
    static uint32_t ticks = 0;

    ticks++;
    if (ticks == TICKS_WAIT)
    {
        XMC_GPIO_ToggleOutput(LED1);
        ticks = 0;
    }
}

int main(void)
{
    XMC_GPIO_CONFIG_t config;

    config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;
    config.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH;

    XMC_GPIO_Init(LED1, &config);

    config.output_level = XMC_GPIO_OUTPUT_LEVEL_LOW;

    /* System timer configuration */
    SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);

    while (1)
    {
        XMC_DelayCycles(200);
    }
}
