#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/* Button structure — holds debounce and hold state */
typedef struct {
    uint8_t stable_state;   /* 1 = pressed, 0 = released */
    uint8_t stable_count;   /* debounce counter */
    uint8_t hold_count;     /* increments every 100ms while held */
} Button_t;

/* Global button instances — accessible from other modules */
extern Button_t btn_left;
extern Button_t btn_right;

/* Function prototypes */
void GPIO_Driver_Init(void);
void GPIO_SampleButtons(void);   /* call every 100ms from scheduler */

#endif /* GPIO_DRIVER_H */
