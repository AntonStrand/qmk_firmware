#include "antonstrand.h"

static uint16_t pressed_key = NO_KEY_PRESS;

void set_pressed_key(uint16_t key, bool is_pressed) {
    if (is_pressed) {
        pressed_key = key;
    } else {
        pressed_key = NO_KEY_PRESS;
    }
}

/**
 * Use in matrix_scan_user or a timer to be able to quickly repeat key presses.
 */
void repeat_pressed_key(void) {
    switch (pressed_key) {
        case R_LEFT:
            tap_code16(KC_LEFT);
            break;
        case R_UP:
            tap_code16(KC_UP);
            break;
        case R_RIGHT:
            tap_code16(KC_RIGHT);
            break;
        case R_DOWN:
            tap_code16(KC_DOWN);
            break;
    }
}