#ifndef ASW_INTEGRATION_H
#define ASW_INTEGRATION_H

/* ASW Integration Layer
 * Bridges Simulink generated IndicatorControl.c
 * with BSW drivers on Nucleo F446RE
 * Matches exact function signatures from generated code
 */

void ASW_Init(void);      /* call once in main before scheduler */
void ASW_RunStep(void);   /* called every 100ms by scheduler    */

#endif /* ASW_INTEGRATION_H */
