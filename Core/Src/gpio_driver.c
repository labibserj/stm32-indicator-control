#include "gpio_driver.h"

/* Global button instances */
Button_t btn_left  = {0, 0, 0};
Button_t btn_right = {0, 0, 0};

/* GPIO_Driver_Init
 * GPIO pins are already configured by CubeMX generated code in main.c
 * This function resets button state on startup
 */
void GPIO_Driver_Init(void) {
    btn_left.stable_state  = 0;
    btn_left.stable_count  = 0;
    btn_left.hold_count    = 0;
    btn_right.stable_state = 0;
    btn_right.stable_count = 0;
    btn_right.hold_count   = 0;
}

/* GPIO_SampleButtons
 * Call every 100ms from scheduler
 * PB4 = left button, PB5 = right button
 * Pins are active LOW (pull-up enabled) so we invert with !
 * Debounce: signal must be stable for 2 consecutive reads (200ms)
 * Hold: hold_count increments every 100ms while button held
 *       hold_count >= 10 means held for 1 second
 */
void GPIO_SampleButtons(void) {

    /* Read raw pin states — active LOW so invert */
    uint8_t raw_L = !HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
    uint8_t raw_R = !HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);

    /* --- Debounce LEFT button --- */
    if (raw_L == btn_left.stable_state) {
        btn_left.stable_count = 0;
    } else {
        btn_left.stable_count++;
        if (btn_left.stable_count >= 2) {
            btn_left.stable_state = raw_L;
            btn_left.stable_count = 0;
        }
    }

    /* Update left hold counter */
    if (btn_left.stable_state) {
        btn_left.hold_count++;
    } else {
        btn_left.hold_count = 0;
    }

    /* --- Debounce RIGHT button --- */
    if (raw_R == btn_right.stable_state) {
        btn_right.stable_count = 0;
    } else {
        btn_right.stable_count++;
        if (btn_right.stable_count >= 2) {
            btn_right.stable_state = raw_R;
            btn_right.stable_count = 0;
        }
    }

    /* Update right hold counter */
    if (btn_right.stable_state) {
        btn_right.hold_count++;
    } else {
        btn_right.hold_count = 0;
    }
}
