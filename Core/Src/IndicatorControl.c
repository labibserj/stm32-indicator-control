/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: IndicatorControl.c
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

#include "IndicatorControl.h"
#include "rtwtypes.h"
#include <string.h>

/* Named constants for Chart: '<Root>/Chart' */
#define IndicatorControl_IN_HAZARD     ((uint8_T)1U)
#define IndicatorControl_IN_LEFT_ON    ((uint8_T)2U)
#define IndicatorControl_IN_OFF        ((uint8_T)3U)
#define IndicatorControl_IN_RIGHT_ON   ((uint8_T)4U)

/* Model step function */
void IndicatorControl_step(RT_MODEL_IndicatorControl_T *const IndicatorControl_M,
  boolean_T IndicatorControl_U_btn_left, boolean_T IndicatorControl_U_btn_right,
  boolean_T *IndicatorControl_Y_led_left, boolean_T
  *IndicatorControl_Y_led_right)
{
  DW_IndicatorControl_T *IndicatorControl_DW = IndicatorControl_M->dwork;
  uint32_T tmp;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/btn_left '
   *  Inport: '<Root>/btn_right '
   */
  switch (IndicatorControl_DW->is_c3_IndicatorControl) {
   case IndicatorControl_IN_HAZARD:
    if ((IndicatorControl_U_btn_left || IndicatorControl_U_btn_right) &&
        ((IndicatorControl_DW->hold_counter_L >= 10) ||
         (IndicatorControl_DW->hold_counter_R >= 10))) {
      IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_OFF;

      /* Outport: '<Root>/led_left ' */
      *IndicatorControl_Y_led_left = false;

      /* Outport: '<Root>/led_right ' */
      *IndicatorControl_Y_led_right = false;
      IndicatorControl_DW->hold_counter_L = 0U;
      IndicatorControl_DW->hold_counter_R = 0U;
      IndicatorControl_DW->blink_counter = 0U;
      IndicatorControl_DW->blink_state = false;
    } else {
      tmp = IndicatorControl_DW->blink_counter + 1U;
      if (IndicatorControl_DW->blink_counter + 1U > 255U) {
        tmp = 255U;
      }

      IndicatorControl_DW->blink_counter = (uint8_T)tmp;
      if (IndicatorControl_DW->blink_counter >= 3) {
        IndicatorControl_DW->blink_counter = 0U;
        IndicatorControl_DW->blink_state = !IndicatorControl_DW->blink_state;
      }

      /* Outport: '<Root>/led_left ' */
      *IndicatorControl_Y_led_left = IndicatorControl_DW->blink_state;

      /* Outport: '<Root>/led_right ' */
      *IndicatorControl_Y_led_right = IndicatorControl_DW->blink_state;
      if (IndicatorControl_U_btn_left) {
        tmp = IndicatorControl_DW->hold_counter_L + 1U;
        if (IndicatorControl_DW->hold_counter_L + 1U > 255U) {
          tmp = 255U;
        }

        IndicatorControl_DW->hold_counter_L = (uint8_T)tmp;
      } else {
        IndicatorControl_DW->hold_counter_L = 0U;
      }

      if (IndicatorControl_U_btn_right) {
        tmp = IndicatorControl_DW->hold_counter_R + 1U;
        if (IndicatorControl_DW->hold_counter_R + 1U > 255U) {
          tmp = 255U;
        }

        IndicatorControl_DW->hold_counter_R = (uint8_T)tmp;
      } else {
        IndicatorControl_DW->hold_counter_R = 0U;
      }
    }
    break;

   case IndicatorControl_IN_LEFT_ON:
    if (IndicatorControl_U_btn_right && (IndicatorControl_DW->hold_counter_R >=
         10)) {
      IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_RIGHT_ON;
      IndicatorControl_DW->blink_counter = 0U;
      IndicatorControl_DW->blink_state = true;
      IndicatorControl_DW->hold_counter_L = 0U;
      IndicatorControl_DW->hold_counter_R = 0U;
    } else if ((!IndicatorControl_U_btn_left) &&
               (IndicatorControl_DW->hold_counter_L >= 10)) {
      IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_OFF;

      /* Outport: '<Root>/led_left ' */
      *IndicatorControl_Y_led_left = false;

      /* Outport: '<Root>/led_right ' */
      *IndicatorControl_Y_led_right = false;
      IndicatorControl_DW->hold_counter_L = 0U;
      IndicatorControl_DW->hold_counter_R = 0U;
      IndicatorControl_DW->blink_counter = 0U;
      IndicatorControl_DW->blink_state = false;
    } else {
      tmp = IndicatorControl_DW->blink_counter + 1U;
      if (IndicatorControl_DW->blink_counter + 1U > 255U) {
        tmp = 255U;
      }

      IndicatorControl_DW->blink_counter = (uint8_T)tmp;
      if (IndicatorControl_DW->blink_counter >= 3) {
        IndicatorControl_DW->blink_counter = 0U;
        IndicatorControl_DW->blink_state = !IndicatorControl_DW->blink_state;
      }

      /* Outport: '<Root>/led_left ' */
      *IndicatorControl_Y_led_left = IndicatorControl_DW->blink_state;

      /* Outport: '<Root>/led_right ' */
      *IndicatorControl_Y_led_right = false;
      if (IndicatorControl_U_btn_left) {
        tmp = IndicatorControl_DW->hold_counter_L + 1U;
        if (IndicatorControl_DW->hold_counter_L + 1U > 255U) {
          tmp = 255U;
        }

        IndicatorControl_DW->hold_counter_L = (uint8_T)tmp;
      } else {
        IndicatorControl_DW->hold_counter_L = 0U;
      }

      if (IndicatorControl_U_btn_right) {
        tmp = IndicatorControl_DW->hold_counter_R + 1U;
        if (IndicatorControl_DW->hold_counter_R + 1U > 255U) {
          tmp = 255U;
        }

        IndicatorControl_DW->hold_counter_R = (uint8_T)tmp;
      } else {
        IndicatorControl_DW->hold_counter_R = 0U;
      }
    }
    break;

   case IndicatorControl_IN_OFF:
    if (IndicatorControl_U_btn_left && (!IndicatorControl_U_btn_right) &&
        (IndicatorControl_DW->hold_counter_L >= 10)) {
      IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_LEFT_ON;
      IndicatorControl_DW->blink_counter = 0U;
      IndicatorControl_DW->blink_state = true;
      IndicatorControl_DW->hold_counter_L = 0U;
      IndicatorControl_DW->hold_counter_R = 0U;
    } else if (IndicatorControl_U_btn_right && (!IndicatorControl_U_btn_left) &&
               (IndicatorControl_DW->hold_counter_R >= 10)) {
      IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_RIGHT_ON;
      IndicatorControl_DW->blink_counter = 0U;
      IndicatorControl_DW->blink_state = true;
      IndicatorControl_DW->hold_counter_L = 0U;
      IndicatorControl_DW->hold_counter_R = 0U;
    } else if (IndicatorControl_U_btn_left && IndicatorControl_U_btn_right &&
               (IndicatorControl_DW->hold_counter_L >= 10) &&
               (IndicatorControl_DW->hold_counter_R >= 10)) {
      IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_HAZARD;
      IndicatorControl_DW->blink_counter = 0U;
      IndicatorControl_DW->blink_state = true;
      IndicatorControl_DW->hold_counter_L = 0U;
      IndicatorControl_DW->hold_counter_R = 0U;
    } else {
      if (IndicatorControl_U_btn_left) {
        tmp = IndicatorControl_DW->hold_counter_L + 1U;
        if (IndicatorControl_DW->hold_counter_L + 1U > 255U) {
          tmp = 255U;
        }

        IndicatorControl_DW->hold_counter_L = (uint8_T)tmp;
      } else {
        IndicatorControl_DW->hold_counter_L = 0U;
      }

      if (IndicatorControl_U_btn_right) {
        tmp = IndicatorControl_DW->hold_counter_R + 1U;
        if (IndicatorControl_DW->hold_counter_R + 1U > 255U) {
          tmp = 255U;
        }

        IndicatorControl_DW->hold_counter_R = (uint8_T)tmp;
      } else {
        IndicatorControl_DW->hold_counter_R = 0U;
      }
    }
    break;

   default:
    /* case IN_RIGHT_ON: */
    if (IndicatorControl_U_btn_left && (IndicatorControl_DW->hold_counter_L >=
         10)) {
      IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_LEFT_ON;
      IndicatorControl_DW->blink_counter = 0U;
      IndicatorControl_DW->blink_state = true;
      IndicatorControl_DW->hold_counter_L = 0U;
      IndicatorControl_DW->hold_counter_R = 0U;
    } else if ((!IndicatorControl_U_btn_right) &&
               (IndicatorControl_DW->hold_counter_R >= 10)) {
      IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_OFF;

      /* Outport: '<Root>/led_left ' */
      *IndicatorControl_Y_led_left = false;

      /* Outport: '<Root>/led_right ' */
      *IndicatorControl_Y_led_right = false;
      IndicatorControl_DW->hold_counter_L = 0U;
      IndicatorControl_DW->hold_counter_R = 0U;
      IndicatorControl_DW->blink_counter = 0U;
      IndicatorControl_DW->blink_state = false;
    } else {
      tmp = IndicatorControl_DW->blink_counter + 1U;
      if (IndicatorControl_DW->blink_counter + 1U > 255U) {
        tmp = 255U;
      }

      IndicatorControl_DW->blink_counter = (uint8_T)tmp;
      if (IndicatorControl_DW->blink_counter >= 3) {
        IndicatorControl_DW->blink_counter = 0U;
        IndicatorControl_DW->blink_state = !IndicatorControl_DW->blink_state;
      }

      /* Outport: '<Root>/led_left ' */
      *IndicatorControl_Y_led_left = false;

      /* Outport: '<Root>/led_right ' */
      *IndicatorControl_Y_led_right = IndicatorControl_DW->blink_state;
      if (IndicatorControl_U_btn_left) {
        tmp = IndicatorControl_DW->hold_counter_L + 1U;
        if (IndicatorControl_DW->hold_counter_L + 1U > 255U) {
          tmp = 255U;
        }

        IndicatorControl_DW->hold_counter_L = (uint8_T)tmp;
      } else {
        IndicatorControl_DW->hold_counter_L = 0U;
      }

      if (IndicatorControl_U_btn_right) {
        tmp = IndicatorControl_DW->hold_counter_R + 1U;
        if (IndicatorControl_DW->hold_counter_R + 1U > 255U) {
          tmp = 255U;
        }

        IndicatorControl_DW->hold_counter_R = (uint8_T)tmp;
      } else {
        IndicatorControl_DW->hold_counter_R = 0U;
      }
    }
    break;
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void IndicatorControl_initialize(RT_MODEL_IndicatorControl_T *const
  IndicatorControl_M, boolean_T *IndicatorControl_U_btn_left, boolean_T
  *IndicatorControl_U_btn_right, boolean_T *IndicatorControl_Y_led_left,
  boolean_T *IndicatorControl_Y_led_right)
{
  DW_IndicatorControl_T *IndicatorControl_DW = IndicatorControl_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)IndicatorControl_DW, 0,
                sizeof(DW_IndicatorControl_T));

  /* external inputs */
  *IndicatorControl_U_btn_left = false;
  *IndicatorControl_U_btn_right = false;

  /* external outputs */
  *IndicatorControl_Y_led_left = false;
  *IndicatorControl_Y_led_right = false;

  /* Chart: '<Root>/Chart' */
  IndicatorControl_DW->is_c3_IndicatorControl = IndicatorControl_IN_OFF;

  /* Outport: '<Root>/led_left ' incorporates:
   *  Chart: '<Root>/Chart'
   * */
  *IndicatorControl_Y_led_left = false;

  /* Outport: '<Root>/led_right ' incorporates:
   *  Chart: '<Root>/Chart'
   * */
  *IndicatorControl_Y_led_right = false;

  /* Chart: '<Root>/Chart' */
  IndicatorControl_DW->hold_counter_L = 0U;
  IndicatorControl_DW->hold_counter_R = 0U;
  IndicatorControl_DW->blink_counter = 0U;
  IndicatorControl_DW->blink_state = false;
}

/* Model terminate function */
void IndicatorControl_terminate(RT_MODEL_IndicatorControl_T *const
  IndicatorControl_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(IndicatorControl_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
