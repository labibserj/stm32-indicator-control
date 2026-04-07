#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include "stm32f4xx_hal.h"

/* Function prototypes */
void UART_Driver_Init(void);
void UART_LogEvent(const char* tag);   /* event-based logging */

#endif /* UART_DRIVER_H */
