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


    XMC_Delay(1000);
   

    //while(1)
    {
        
        // pmsm_foc_set_motor_target_torque(USER_IQ_REF_HIGH_LIMIT / 4);
        
        // XMC_Delay(1000);
  
        // pmsm_foc_motor_stop();
        // pmsm_foc_set_motor_target_torque(0);

        // XMC_Delay(1000);
    }

    pmsm_foc_motor_start();
    pmsm_foc_set_motor_target_torque(USER_IQ_REF_HIGH_LIMIT / 25);

    XMC_Delay(5000);
    pmsm_foc_motor_stop();


    // while(1)
    // {
    //     pmsm_foc_motor_start();
    //     for (int i = 4; i < USER_IQ_REF_HIGH_LIMIT / 16; i++)
    //     {
    //         pmsm_foc_set_motor_target_torque(i);
    //         XMC_Delay(8);
    //     }
    
    //     for (int i = USER_IQ_REF_HIGH_LIMIT / 16; i > 4; i--)
    //     {
    //         pmsm_foc_set_motor_target_torque(i);
    //         XMC_Delay(8);
    //     }
    //     pmsm_foc_motor_stop();
    // }


    while (1);

    return 0;
}

void pmsm_foc_secondaryloop_callback()
{ 
    // pmsm_foc_set_motor_target_speed(1000);
}
