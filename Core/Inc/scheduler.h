#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/* Scheduler tick flag — set by TIM6 interrupt, cleared by Scheduler_Run */
extern volatile uint8_t scheduler_tick;

/* Function prototypes */
void Scheduler_Init(void);
void Scheduler_Run(void);    /* call in main while(1) loop */

#endif /* SCHEDULER_H */
