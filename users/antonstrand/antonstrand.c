#include "antonstrand.h"
#include "keymap_swedish_mac.h"
#include "sendstring_swedish_mac.h"
#include "config.h"

static uint16_t pressed_key = NO_KEY_PRESS;

static uint16_t space_cadet_timer[1] = {0};

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

/**
 * Hold modifier until is_pressed is false. The key is tapped once when is_presses becomes true.
 */
void tap_hold_mod(uint16_t mod, uint16_t kc, bool is_pressed) {
    if (is_pressed) {
        register_code16(mod);
        tap_code16(kc);
    } else {
        unregister_code16(mod);
    }
}

void clear_keyboard_mods(void) {
    clear_mods();
    clear_oneshot_mods();
}

/**
 * Macro to compile the keyboard.
 */
void compile_keyboard(void) {
    clear_keyboard_mods();
    SEND_STRING("qmk compile -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
}

/**
 * Macro to flash the keyboard.
 */
void flash_keyboard(void) {
    clear_keyboard_mods();
    SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
    reset_keyboard();
}

void matrix_scan_user(void) {
    // Repeat key presses while hold down
    repeat_pressed_key();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PIPE:
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            break;
        case COMPOSE:
            if (record->event.pressed) {
                SEND_STRING(">>");
            }
            break;
        case SKINNY_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case FAT_ARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case APP:
            tap_hold_mod(KC_LCMD, KC_TAB, record->event.pressed);
            break;
        case R_LEFT:
            set_pressed_key(R_LEFT, record->event.pressed);
            break;
        case R_UP:
            set_pressed_key(R_UP, record->event.pressed);
            break;
        case R_RIGHT:
            set_pressed_key(R_RIGHT, record->event.pressed);
            break;
        case R_DOWN:
            set_pressed_key(R_DOWN, record->event.pressed);
            break;
        case COMPILE:
            if (record->event.pressed) {
                compile_keyboard();
            }
            break;
        case FLASH:
            if (record->event.pressed) {
                flash_keyboard();
            }
            break;
        case CK_BASE:
            if (record->event.pressed) {
                layer_move(_QWERTY);
            }
            break;

        case GUI_QM:
            if (record->event.pressed) {
                space_cadet_timer[0] = timer_read();
                register_code16(KC_LGUI);
            } else {
                unregister_code16(KC_LGUI);
                if (timer_elapsed(space_cadet_timer[0]) < TAPPING_TERM) {
                    tap_code16(SE_QUES);
                }
            }
            break;
    }

    return true;
};