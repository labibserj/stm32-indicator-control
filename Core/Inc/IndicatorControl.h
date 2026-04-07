/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: IndicatorControl.h
 *
 * Code generated for Simulink model 'IndicatorControl'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sun Apr  5 19:54:57 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef IndicatorControl_h_
#define IndicatorControl_h_
#ifndef IndicatorControl_COMMON_INCLUDES_
#define IndicatorControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* IndicatorControl_COMMON_INCLUDES_ */

#include "IndicatorControl_types.h"
#include <string.h>
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T blink_counter;               /* '<Root>/Chart' */
  uint8_T hold_counter_L;              /* '<Root>/Chart' */
  uint8_T hold_counter_R;              /* '<Root>/Chart' */
  uint8_T is_c3_IndicatorControl;      /* '<Root>/Chart' */
  boolean_T blink_state;               /* '<Root>/Chart' */
} DW_IndicatorControl_T;

/* Real-time Model Data Structure */
struct tag_RTM_IndicatorControl_T {
  const char_T * volatile errorStatus;
  DW_IndicatorControl_T *dwork;
};

/* Model entry point functions */
extern void IndicatorControl_initialize(RT_MODEL_IndicatorControl_T *const
  IndicatorControl_M, boolean_T *IndicatorControl_U_btn_left, boolean_T
  *IndicatorControl_U_btn_right, boolean_T *IndicatorControl_Y_led_left,
  boolean_T *IndicatorControl_Y_led_right);
extern void IndicatorControl_step(RT_MODEL_IndicatorControl_T *const
  IndicatorControl_M, boolean_T IndicatorControl_U_btn_left, boolean_T
  IndicatorControl_U_btn_right, boolean_T *IndicatorControl_Y_led_left,
  boolean_T *IndicatorControl_Y_led_right);
extern void IndicatorControl_terminate(RT_MODEL_IndicatorControl_T *const
  IndicatorControl_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IndicatorControl'
 * '<S1>'   : 'IndicatorControl/Chart'
 */
#endif                                 /* IndicatorControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
