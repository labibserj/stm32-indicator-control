#include "scheduler.h"
#include "gpio_driver.h"
#include "asw_integration.h"

/* Tick flag set by TIM6 interrupt every 100ms */
volatile uint8_t scheduler_tick = 0;

/* Task structure */
typedef struct {
    void     (*task_fn)(void);   /* function pointer */
    uint8_t  period;             /* period in 100ms ticks */
    uint8_t  counter;            /* current tick count */
} Task_t;

/* Task table
 * Add new tasks here as needed
 * period = 1 means runs every 100ms
 * period = 3 means runs every 300ms
 */
static Task_t task_table[] = {
    { GPIO_SampleButtons,  1,  0 },   /* 100ms — read buttons    */
    { ASW_RunStep,         1,  0 },   /* 100ms — run state machine*/
};

#define TASK_COUNT  (sizeof(task_table) / sizeof(Task_t))

/* Scheduler_Init
 * TIM6 must be started before calling this
 * Call after all driver inits in main.c
 */
void Scheduler_Init(void) {
    uint8_t i;
    for (i = 0; i < TASK_COUNT; i++) {
        task_table[i].counter = 0;
    }
    scheduler_tick = 0;
}

/* Scheduler_Run
 * Call this in main while(1) loop — NOT from interrupt
 * Checks tick flag set by TIM6 ISR
 * Dispatches tasks whose period counter has elapsed
 * Non-blocking — returns immediately if no tick pending
 */
void Scheduler_Run(void) {
    uint8_t i;

    if (scheduler_tick == 0) {
        return;   /* no tick yet */
    }
    scheduler_tick = 0;   /* clear flag */

    for (i = 0; i < TASK_COUNT; i++) {
        task_table[i].counter++;
        if (task_table[i].counter >= task_table[i].period) {
            task_table[i].counter = 0;
            task_table[i].task_fn();   /* call the task */
        }
    }
}
