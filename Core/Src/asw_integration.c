#include "asw_integration.h"
#include "IndicatorControl.h"
#include "rtwtypes.h"
#include "gpio_driver.h"
#include "pwm_driver.h"
#include "uart_driver.h"

/* ---------------------------------------------------------------
 * Model instance — RT_MODEL_IndicatorControl_T holds all state
 * including dwork (blink_counter, hold_counter, blink_state etc)
 * --------------------------------------------------------------- */
static RT_MODEL_IndicatorControl_T IndicatorControl_M_;
static RT_MODEL_IndicatorControl_T *const IndicatorControl_M =
    &IndicatorControl_M_;

/* DWork memory block — linked to model instance */
static DW_IndicatorControl_T IndicatorControl_DW_;

/* Input variables — passed by value to step function */
static boolean_T btn_left_input  = false;
static boolean_T btn_right_input = false;

/* Output variables — written by step function via pointer */
static boolean_T led_left_output  = false;
static boolean_T led_right_output = false;

/* Previous output states for change detection logging */
static boolean_T prev_led_left  = false;
static boolean_T prev_led_right = false;

/* Previous hold counts for button press event logging */
static uint8_t prev_hold_L = 0;
static uint8_t prev_hold_R = 0;

/* Hazard mode state */
static uint8_t hazard_active = 0;

/* ---------------------------------------------------------------
 * ASW_Init
 * Links dwork memory to model instance
 * Calls generated initialize function with all required pointers
 * Call once in main.c before starting scheduler
 * --------------------------------------------------------------- */
void ASW_Init(void) {
    /* Link dwork block to model instance */
    IndicatorControl_M->dwork = &IndicatorControl_DW_;

    /* Call generated initialize function
     * Signature from IndicatorControl.h:
     * void IndicatorControl_initialize(
     *     RT_MODEL_IndicatorControl_T *const IndicatorControl_M,
     *     boolean_T *btn_left,
     *     boolean_T *btn_right,
     *     boolean_T *led_left,
     *     boolean_T *led_right)
     */
    IndicatorControl_initialize(
        IndicatorControl_M,
        &btn_left_input,
        &btn_right_input,
        &led_left_output,
        &led_right_output
    );
}

/* ---------------------------------------------------------------
 * ASW_RunStep
 * Called every 100ms by scheduler
 * 1. Reads button states from gpio_driver
 * 2. Calls generated step function with exact signature
 * 3. Drives PWM based on LED outputs
 * 4. Logs all state changes via UART
 * --------------------------------------------------------------- */
void ASW_RunStep(void) {

    /* --- Read button states from gpio_driver --- */
    btn_left_input  = (boolean_T)btn_left.stable_state;
    btn_right_input = (boolean_T)btn_right.stable_state;

    /* --- Call generated step function
     * Signature from IndicatorControl.h:
     * void IndicatorControl_step(
     *     RT_MODEL_IndicatorControl_T *const IndicatorControl_M,
     *     boolean_T btn_left,     <- passed by value
     *     boolean_T btn_right,    <- passed by value
     *     boolean_T *led_left,    <- written via pointer
     *     boolean_T *led_right)   <- written via pointer
     * ------------------------------------------ */
    IndicatorControl_step(
        IndicatorControl_M,
        btn_left_input,
        btn_right_input,
        &led_left_output,
        &led_right_output
    );

    /* --- Drive LEDs via PWM based on outputs --- */
    if (led_left_output) {
        PWM_SetLED(LED_LEFT, 80);    /* ON at 80% duty cycle */
    } else {
        PWM_SetLED(LED_LEFT, 0);     /* OFF */
    }

    if (led_right_output) {
        PWM_SetLED(LED_RIGHT, 80);
    } else {
        PWM_SetLED(LED_RIGHT, 0);
    }

    /* --- Log button press events (on first tick of press) --- */
    if (btn_left.hold_count == 1 && prev_hold_L == 0) {
        UART_LogEvent("LEFT_BUTTON_PRESSED");
    }
    if (btn_right.hold_count == 1 && prev_hold_R == 0) {
        UART_LogEvent("RIGHT_BUTTON_PRESSED");
    }
    prev_hold_L = btn_left.hold_count;
    prev_hold_R = btn_right.hold_count;

    /* --- Log LED state change events --- */
    if (led_left_output != prev_led_left) {
        if (led_left_output) {
            UART_LogEvent("LEFT_INDICATOR_ON");
        } else {
            UART_LogEvent("LEFT_INDICATOR_OFF");
        }
        UART_LogEvent("LEFT_LED_TOGGLE");
        prev_led_left = led_left_output;
    }

    if (led_right_output != prev_led_right) {
        if (led_right_output) {
            UART_LogEvent("RIGHT_INDICATOR_ON");
        } else {
            UART_LogEvent("RIGHT_INDICATOR_OFF");
        }
        UART_LogEvent("RIGHT_LED_TOGGLE");
        prev_led_right = led_right_output;
    }

    /* --- Hazard mode detection --- */
    if ((led_left_output == led_right_output) && (led_left_output == 1))
    {
        if (!hazard_active)
        {
            UART_LogEvent("HAZARD_ON");
            hazard_active = 1;
        }
    }
    else
    {
        if (hazard_active)
        {
            UART_LogEvent("HAZARD_OFF");
            hazard_active = 0;
        }
    }
}
