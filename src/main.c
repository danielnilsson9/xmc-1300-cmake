#include "Configuration/pmsm_foc_variables_scaling.h"
#include "ControlModules/pmsm_foc_interface.h"


int cbs = 0;

int main(void)
{
    /* Init MCU and motor control peripherals */
    pmsm_foc_init();

    pmsm_foc_motor_start();

    while (1)
    {
        // int speed = pmsm_foc_get_motor_speed();
    }

    return 0;
}

void pmsm_foc_secondaryloop_callback()
{ 
    pmsm_foc_set_motor_target_speed(1000);
}
