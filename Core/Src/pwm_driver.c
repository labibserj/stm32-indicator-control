#include "pwm_driver.h"
#include "tim.h"

/* PWM_Driver_Init
 * Starts TIM2 PWM on CH1 (PA0 = left LED) and CH2 (PA1 = right LED)
 * TIM2 settings in CubeMX:
 *   Prescaler = 89, Period = 999
 *   PWM frequency = 90MHz / (89+1) / (999+1) = 1000 Hz
 * Both LEDs start OFF (duty = 0)
 */
void PWM_Driver_Init(void) {
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);   /* PA0 — left LED  */
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);   /* PA1 — right LED */
    PWM_SetLED(LED_LEFT,  0);
    PWM_SetLED(LED_RIGHT, 0);
}

/* PWM_SetLED
 * channel     : LED_LEFT (0) or LED_RIGHT (1)
 * duty_percent: 0 = OFF, 80 = ON at 80% duty cycle
 * Uses TIM2 Period value to calculate pulse width
 */
void PWM_SetLED(uint8_t channel, uint8_t duty_percent) {
    uint32_t period = htim2.Init.Period;
    uint32_t pulse  = (period * (uint32_t)duty_percent) / 100U;

    if (channel == LED_LEFT) {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
    } else {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, pulse);
    }
}
