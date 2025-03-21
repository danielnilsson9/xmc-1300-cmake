/**
 * @file pmsm_foc_ctrap_isr.c
 * @Firmware PMSM_FOC_SL_XMC13_XMC14_V1_5
 * @Modified date: 2019-01-10
 *
 * @cond
 ****************************************
 * PMSM FOC Motor Control Library
 *
 * Copyright (c) 2015-2019, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ******************************************
 *
 * @file pmsm_foc_ctrap_isr.c
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * @endcond
 *
 */

/*********************************************************************************************************************
 * HEADER FILES
 ***************************************/

#include "pmsm_foc_error_handling.h"
#include "../ControlModules/pmsm_foc_interface.h"

/*********************************************************************************************************************
 * GLOBAL DATA
 ***************************************/

extern MotorControlType Motor; /* Motor control information */

/*********************************************************************************************************************
 * API IMPLEMENTATION
 ***************************************/

/* Trap protection interrupt, e.g.: for over-current protection, triggered by CCU8x Event2 */
void pmsm_foc_trap_protection_irq(void)
{
  pmsm_foc_disable_inverter(); /* Disable gate driver. */

  /*
   * Next PWM cycles, go to trap protection, until MCU reset / POR
   * to resume normal motor operation.
   */
  Motor.State = TRAP_PROTECTION;

  Motor.CCU8_Trap_Status = 0x01;
#if(SETTING_TARGET_SPEED == BY_UART_ONLY)
  UART_TX_String("\r\n\nCCU8 Trap!!");
#endif

} /* End of CCU80_1_IRQHandler () */


