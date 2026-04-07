#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/* LED channel identifiers */
#define LED_LEFT    0
#define LED_RIGHT   1

/* Function prototypes */
void PWM_Driver_Init(void);
void PWM_SetLED(uint8_t channel, uint8_t duty_percent);

#endif /* PWM_DRIVER_H */
