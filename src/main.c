#include "xmc_gpio.h"
#include "xmc_common.h"

#define TICKS_PER_SECOND 1000
#define TICKS_WAIT 5000

#define LED1 P1_5

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
