

add_library(XMCBldcScalarHall STATIC
    "src/ControlModule/bldc_scalar_control_hall.c"
    "src/ControlModule/bldc_scalar_control_scheme.c"
    "src/ControlModule/bldc_scalar_ramp_generator.c"
    "src/Interrupts/bldc_scalar_control_loop.c"
    "src/Interrupts/bldc_scalar_ctrap_periodmatch.c"
    "src/Interrupts/bldc_scalar_hall_event.c"
    "src/Interrupts/bldc_scalar_hall_state_machine.c"
    "src/Interrupts/bldc_scalar_pattern_shadowtx.c"
    "src/Interrupts/bldc_scalar_protection_error.c"
    "src/MCUInit/ccu4.c"
    "src/MCUInit/ccu8.c"
    "src/MCUInit/gpio.c"
    "src/MCUInit/nvic.c"
    "src/MCUInit/posif.c"
    "src/MCUInit/systick.c"
    "src/MCUInit/vadc.c"
    "src/MidSys/bldc_scalar_current_motor.c"
    "src/MidSys/bldc_scalar_pwm_bc.c"
    "src/MidSys/bldc_scalar_speed_pos_hall.c"
    "src/MidSys/bldc_scalar_volt_dcbus.c"
    "src/MidSys/bldc_scalar_volt_potentiometer.c"
    "src/MidSys/bldc_scalar_volt_userdef.c"
    "src/bldc_scalar_user_interface.c"
    "src/bldc_scalar_variables_config.c"
)

target_include_directories(XMCBldcScalarHall PUBLIC include)

target_link_libraries(XMCBldcScalarHall PUBLIC XMCLib)