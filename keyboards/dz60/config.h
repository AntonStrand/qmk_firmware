<<<<<<< HEAD
#ifndef CONFIG_H
#    define CONFIG_H
=======
#pragma once
>>>>>>> master

#    include "config_common.h"

/* Leader timeout in milliseconds */
#    define LEADER_TIMEOUT 450
#    define LEADER_PER_KEY_TIMING 400

#    define ONESHOT_TAP_TOGGLE 5 /* Tapping this number of times holds the key until tapped once again. */
#    define ONESHOT_TIMEOUT 5000 /* Time (in ms) before the one shot key is released */

// #    define TAPPING_TERM 100
#    define PERMISSION_HOLD

/* USB Device descriptor parameter */
<<<<<<< HEAD
#    define VENDOR_ID 0x445A  // "DZ"
#    define PRODUCT_ID 0x2260
#    define DEVICE_VER 0x0001
#    define MANUFACTURER KBDFans
#    define PRODUCT DZ60
#    define DESCRIPTION DZ60 Keyboard
=======
#define VENDOR_ID       0x445A  // "DZ"
#define PRODUCT_ID      0x2260
#define DEVICE_VER      0x0001
#define MANUFACTURER    KBDFans
#define PRODUCT         DZ60
>>>>>>> master

/* key matrix size */
#    define MATRIX_ROWS 5
#    define MATRIX_COLS 15

<<<<<<< HEAD
/* key matrix pins */
#    define MATRIX_ROW_PINS \
        { D0, D1, D2, D3, D5 }
#    define MATRIX_COL_PINS \
        { F0, F1, E6, C7, C6, B7, D4, B1, B0, B5, B4, D7, D6, B3, F4 }
#    define UNUSED_PINS

/* COL2ROW or ROW2COL */
#    define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#    define BACKLIGHT_PIN B6
#    ifdef BACKLIGHT_PIN
#        define BACKLIGHT_LEVELS 5
#    endif
/* Set 0 if debouncing isn't needed */
#    define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#    define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#    define LOCKING_RESYNC_ENABLE
#    define RGB_DI_PIN E2
#    ifdef RGB_DI_PIN
#        define RGBLIGHT_ANIMATIONS
#        define RGBLED_NUM 16
#        define RGBLIGHT_HUE_STEP 8
#        define RGBLIGHT_SAT_STEP 8
#        define RGBLIGHT_VAL_STEP 8
#        define RGBLIGHT_SLEEP
#    endif
#endif
=======
/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { D0, D1, D2, D3, D5 }
#define MATRIX_COL_PINS { F0, F1, E6, C7, C6, B7, D4, B1, B0, B5, B4, D7, D6, B3, F4 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN B6
#define BACKLIGHT_LEVELS 5

#define RGB_DI_PIN E2
#ifdef RGB_DI_PIN
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM 16
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_SLEEP
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
>>>>>>> master

/* VIA related config */
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2
