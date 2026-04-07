#include "uart_driver.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>

/* UART_Driver_Init
 * USART2 is already initialized by CubeMX in usart.c
 * On Nucleo F446RE, USART2 (PA2/PA3) is connected to
 * the ST-Link USB bridge — no external TTL converter needed
 * Open PuTTY on STLink COM port at 115200 baud to see logs
 */
void UART_Driver_Init(void) {
    UART_LogEvent("SYSTEM_INIT");
}

/* UART_LogEvent
 * Sends a timestamped log message over USART2
 * Format: [timestamp ms] EVENT_NAME
 * Example: [1000 ms] LEFT_INDICATOR_ON
 * Blocking transmit with 100ms timeout
 */
void UART_LogEvent(const char* tag) {
    char buf[80];
    uint32_t timestamp = HAL_GetTick();
    snprintf(buf, sizeof(buf), "[%lu ms] %s\r\n", timestamp, tag);
    HAL_UART_Transmit(&huart2,
                      (uint8_t*)buf,
                      (uint16_t)strlen(buf),
                      100);
}
