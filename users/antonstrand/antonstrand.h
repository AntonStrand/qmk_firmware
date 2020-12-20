
#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "action.h"
#include "version.h"
#include "combos_config.h"
#include "tap_dance.h"

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _RAPID,
    _ADJUST,
    _NUMBER,
    _SNAKE,
    _CAMEL,
    _GAME,
    _GAME_NUMS
    //
};

#define ______ KC_TRNS

#define CK_CUT LGUI(KC_X)
#define CK_COPY LGUI(KC_C)
#define CK_PASTE LGUI(KC_V)
#define CK_UNDO LGUI(KC_Z)
#define CK_REDO S(CK_UNDO)

#define LCTL_A LCTL_T(KC_A)
#define LSFT_S LSFT_T(KC_S)
#define LALT_D LALT_T(KC_D)
#define LGUI_F LGUI_T(KC_F)

#define SFT_QUOT RSFT_T(SE_QUOT)
#define SLEEP G(A(KC_EJCT))
#define TG_CMT G(SE_SLSH)

#define TD_RAISE TD(RS_SPC_ENT)

// Define all of
enum custom_keycodes {
    NO_KEY_PRESS = (UINT16_MAX - 1),
    PIPE         = SAFE_RANGE,
    COMPOSE,
    SKINNY_ARROW,
    FAT_ARROW,
    APP,
    RAPID,
    R_LEFT,
    R_DOWN,
    R_UP,
    R_RIGHT,
    COMPILE,
    FLASH,
    CK_BASE,
    GUI_QM,
    KEYMAP_RANGE  // use "KEYMAP_RANGE" for keymap specific codes
};
void set_color(int from, int to, int r, int g, int b);
void set_pressed_key(uint16_t key, bool is_pressed);
void handle_pressed_key(void);
void tap_hold_mod(uint16_t mod, uint16_t kc, bool is_pressed);
void compile_keyboard(void);
void flash_keyboard(void);
