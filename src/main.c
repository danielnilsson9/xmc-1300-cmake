#include "Configuration/pmsm_foc_variables_scaling.h"
#include "ControlModules/pmsm_foc_interface.h"


int ticks = 0;

#define LED1 P1_5

void SysTick_Handler(void)
{
    XMC_GPIO_ToggleOutput(LED1);
}

int main(void)
{
    /* Init MCU and motor control peripherals */
    pmsm_foc_init();

    SysTick_Config(SystemCoreClock / 1000);

    XMC_GPIO_CONFIG_t config; 
    config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;
    config.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH;
    XMC_GPIO_Init(LED1, &config);

    pmsm_foc_motor_start();
    
    while (1)
    {
        // int speed = pmsm_foc_get_motor_speed();
        //ticks++;
        //if (ticks == 1000)
        //{
            //XMC_GPIO_ToggleOutput(LED1);
            //ticks = 0;
        //}
    }

    return 0;
}

void pmsm_foc_secondaryloop_callback()
{ 
    pmsm_foc_set_motor_target_speed(3000);
}
