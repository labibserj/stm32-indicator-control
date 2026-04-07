/*
 * rt_defines.h
 * Standard Simulink Coder runtime definitions for ARM Cortex-M
 * Compatible with R2025a generated code
 */

#ifndef RT_DEFINES_H
#define RT_DEFINES_H

#include "rtwtypes.h"

/* Real-time model error status */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)  ((rtm)->errorStatus = (val))
#endif

/* Boolean true/false */
#ifndef TRUE
#define TRUE   (1U)
#endif

#ifndef FALSE
#define FALSE  (0U)
#endif

/* Infinity and NaN are not used in this project
 * but defined to avoid compile errors if referenced */
#ifndef rtInf
#define rtInf   ((real_T)(1.0 / 0.0))
#endif

#ifndef rtMinusInf
#define rtMinusInf  ((real_T)(-1.0 / 0.0))
#endif

#ifndef rtNaN
#define rtNaN   ((real_T)(0.0 / 0.0))
#endif

#endif /* RT_DEFINES_H */
