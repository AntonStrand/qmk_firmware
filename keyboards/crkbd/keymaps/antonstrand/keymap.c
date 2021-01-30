/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "version.h"
#include "antonstrand.h"
#include "keymap_swedish_mac.h"
#include "rgblight_list.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  SE_ARNG,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,  LCTL_A,  LSFT_S,  LALT_D,  LGUI_F,    KC_G,                         KC_H,    RG_J,    RA_K,    RS_L, RC_ODIA, SE_ADIA,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, SE_MINS,SFT_QUOT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          NUMBER ,  LOWER , KC_BSPC,    KC_SPC ,  RAISE ,  KC_ENT \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SE_TILD, SE_DQUO, SE_QUOT, SE_PIPE, SE_AMPR,  KC_EQL,                       SE_DLR, SE_LCBR, SE_LPRN, SE_RPRN, SE_RCBR, SE_CIRC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SE_EQL,  SE_AT, COMPOSE,SKINNY_ARROW,PIPE,FAT_ARROW,                      SE_HASH, SE_LBRC, SE_RBRC, SE_SCLN, SE_COLN,  SE_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, SE_PLUS, SE_MINS, SE_ASTR, SE_SLSH,  SE_EQL,                      SE_PERC, SE_BSLS, SE_LABK, SE_RABK, SE_UNDS, SE_QUOT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,    SE_QUES,   RAISE, KC_EXLM \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    S(KC_TAB), _______, _______, _______, _______, _______,                      CK_REDO, CK_UNDO, CK_CUT, CK_COPY, CK_PASTE, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,     APP,                       TG_CMT, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,   RAPID, _______,                      _______,  KC_ENT, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAPID] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______,  R_LEFT,  R_DOWN,    R_UP, R_RIGHT, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_WAKE,   SLEEP, _______, _______, _______,                      _______, _______, KC_VOLD, KC_VOLU, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______,   FLASH, COMPILE, _______, _______,                      _______, KC_MUTE, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMBER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   SE_LPRN,                      SE_RPRN,    KC_1,    KC_2,    KC_3, SE_PLUS, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   SE_EURO,                       SE_DLR,    KC_4,    KC_5,    KC_6, SE_MINS,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_F9,   KC_F10,  KC_F11,  KC_F12,   TG_NUM,                      SE_PERC,    KC_7,    KC_8,    KC_9, SE_SLSH,  KC_ENT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_RGUI,    KC_0,  SE_EQL \
                                      //`--------------------------'  `--------------------------'
  )
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

void matrix_init_user(void) {
// SSD1306 OLED init
#ifdef OLED_DRIVER_ENABLE
    oled_init(!has_usb());  // turns on the display
#endif
}

// SSD1306 OLED
#ifdef OLED_DRIVER_ENABLE
static uint16_t oled_timer = 0;
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_corne_logo(void) {
    static const char PROGMEM font_logo[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(font_logo, false);
};

void render_qmk_logo(void) {
    static const char PROGMEM font_qmk_logo[16] = {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
    oled_write_P(font_qmk_logo, false);
};

void render_mod_status(void) {
#    ifdef NO_ACTION_ONESHOT
    uint8_t modifiers = get_mods();
#    else
    uint8_t modifiers = get_mods() | get_oneshot_mods();
#    endif
    oled_write_P(PSTR(">"), false);
    (modifiers & MOD_MASK_CTRL) ? oled_write_P(PSTR("C"), false) : oled_write_P(PSTR("_"), false);
    (modifiers & MOD_MASK_SHIFT) ? oled_write_P(PSTR("S"), false) : oled_write_P(PSTR("_"), false);
    (modifiers & MOD_MASK_ALT) ? oled_write_P(PSTR("A"), false) : oled_write_P(PSTR("_"), false);
    (modifiers & MOD_MASK_GUI) ? oled_write_P(PSTR("G"), false) : oled_write_P(PSTR("_"), false);
}

static void render_active_layer(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwert"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Setup"), false);
            break;
        case _NUMBER:
            oled_write_ln_P(PSTR("Nums "), false);
            break;
        case _RAPID:
            oled_write_ln_P(PSTR("Rapid"), false);
            break;
        default:
            oled_write_P(PSTR("Undfd"), false);
    }
}

void matrix_scan_kb(void) {
    oled_task();
    repeat_pressed_key();
}

void render_led_state(void) {
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.num_lock ? PSTR("NUM") : PSTR(""), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAPS") : PSTR(""), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCRL") : PSTR(""), false);
}

char wpm_str[11];
void render_wpm(void) {
    sprintf(wpm_str, "WPM:\n  %03d", get_current_wpm());
    oled_write(wpm_str, false);
}

void write_empty_line(void) { oled_write_ln("", false); }

void render_layer_icon(void) {
    static const char PROGMEM font_layer[4][6] = {
        {0x85, 0x86, 0x87, 0x88, 0x89, 0},
        {0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0},
        {0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0},
        {0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0},
    };
    uint8_t layer = 0;
    if (layer_state_is(_ADJUST)) {
        layer = 3;
    } else if (layer_state_is(_RAISE)) {
        layer = 2;
    } else if (layer_state_is(_LOWER)) {
        layer = 1;
    }
    oled_write_P(font_layer[layer], false);
};

void render_logo(void) {
    switch (get_highest_layer(layer_state)) {
        case _ADJUST:
            render_qmk_logo();
            break;
        default:
            render_corne_logo();
    }
}

void render_main(void) {
    render_logo();
    write_empty_line();

    render_active_layer();
    render_layer_icon();

    render_led_state();

    oled_write_P(PSTR("Anton"), false);
    write_empty_line();

    render_wpm();
    write_empty_line();

    render_mod_status();
}

void oled_task_user(void) {
    if (timer_elapsed(oled_timer) > 10000) {
        oled_off();
        return;
    } else {
        oled_on();
    }
    if (is_master) {
        render_main();
    }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer = timer_read();
    }
    return process_record_user(keycode, record);
}

#endif  // SSD1306OLED
