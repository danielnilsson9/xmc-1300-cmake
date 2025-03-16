#include "xmc_gpio.h"
#include "xmc_common.h"
#include <xmc_scu.h>

#define TICKS_PER_SECOND 1000
#define TICKS_WAIT 250

#define LED1 P1_5

void SysTick_Handler(void)
{
    //static uint32_t ticks = 0;

    //ticks++;
    //if (ticks == TICKS_WAIT)
    //{
        XMC_GPIO_ToggleOutput(LED1);
        //ticks = 0;
    //}
}

int main(void)
{
    // XMC_SCU_CLOCK_CONFIG_t clock;
    // clock.fdiv = 0;
    // clock.idiv = 1;
    // clock.pclk_src = XMC_SCU_CLOCK_PCLKSRC_DOUBLE_MCLK;
    // clock.rtc_src = XMC_SCU_CLOCK_RTCCLKSRC_DCO2;

    // XMC_SCU_CLOCK_Init(&clock);


    XMC_GPIO_CONFIG_t config;
    
    config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;
    config.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH;

    XMC_GPIO_Init(LED1, &config);

    config.output_level = XMC_GPIO_OUTPUT_LEVEL_LOW;

    /* System timer configuration */
    //SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);

    SysTick_Config(1000);

    while (1)
    {
        //XMC_DelayCycles(1000);
        //XMC_GPIO_ToggleOutput(LED1);
    }
}

void pmsm_foc_secondaryloop_callback()
{ 
    // pmsm_foc_set_motor_target_speed(1000);
}
