/* Copyright 2020 Anton Strand base on tominabox1's default layout
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "version.h"
#include "antonstrand.h"
#include "keymap_swedish_mac.h"


#define LWR_BSP LT(_LOWER, KC_BSPC)
#define RSE_SPC LT(_RAISE, KC_SPC)

#define GUI_ESC LGUI_T(KC_ESC)
#define TG_NUM TG(_NUMBER)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Å  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Shft'|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Num  | Ctrl | Alt  | GUI  |BK/LWR|    Space    |Spc/RS| Enter|  Alt | Ctrl | GUI? |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG,
        GUI_ESC,     LCTL_A,  LSFT_S,  LALT_D,  LGUI_F,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SE_ODIA, SE_ADIA,
        KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_MINS, SFT_QUOT,
        MO(_NUMBER), KC_LCTL, KC_LALT, KC_LGUI, LWR_BSP,     KC_SPC,       RSE_SPC, KC_ENT,  KC_RALT, KC_RCTL, GUI_QM
    ),

    /* Lower (Nav)
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   "  |   '  |   |  |   &  |   ´  |   $  |   {  |   (  |  )   |  }   |   ^  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   @  |  >>  |  ->  |  |>  |  =>  |   #  |   [  |   ]  |   ;  |   :  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   +  |   -  |   *  |  /   |  =   |   %  |   \  |   <  |   >  |   _  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |     Tab     |Adjust|      |      |      |   !  |
     * `-----------------------------------------------------------------------------------'
     */

    [_LOWER] = LAYOUT_planck_mit(
          SE_TILD, SE_DQUO, SE_QUOT, SE_PIPE,      SE_AMPR, KC_EQL,    SE_DLR,  SE_LCBR, SE_LPRN, SE_RPRN, SE_RCBR, SE_CIRC,
          ______,  SE_AT,   COMPOSE, SKINNY_ARROW, PIPE,    FAT_ARROW, SE_HASH, SE_LBRC, SE_RBRC, SE_SCLN, SE_COLN, SE_GRV,
          KC_LSFT, SE_PLUS, SE_MINS, SE_ASTR,      SE_SLSH, SE_EQL,    SE_PERC, SE_BSLS, SE_LABK, SE_RABK, SE_UNDS, SE_QUOT,
          ______,  ______,  ______,  ______,       ______,        ______,       ______,  ______,  ______,  ______,  KC_EXLM
    ),

    // /* Raise (Nav)
    //  * ,-----------------------------------------------------------------------------------.
    //  * | <Tab |      |      |      |      |      |      | Undo |  Cut | Copy | Paste| Bksp |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Del  | Ctrl | Shift|  Alt | GUI  |  App |  cmt | Left | Down |  Up  | Right|   '  |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Shift|      |      |      | Rapid|      |      |      | Sc D | Sc U |      |Enter |
    //  * |------+------+------+------+------+------+------+------+------+------+------+------|
    //  * | Num  | Ctrl | Alt  | GUI  |Adjust|     Del     |      |  GUI |  Alt | Ctrl |  FN  |
    //  * `-----------------------------------------------------------------------------------'
    //  */
    [_RAISE] = LAYOUT_planck_mit(
        S(KC_TAB), _______, _______, _______, _______,    _______, CK_REDO, CK_UNDO, CK_CUT,  CK_COPY, CK_PASTE, KC_BSPC,
        KC_DEL,    KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,    APP,      TG_CMT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_BSLS,
        _______,   _______, _______, _______, MO(_RAPID), _______, _______, KC_ENT,  _______, _______, _______,  KC_ENT,
        _______,   _______, _______, _______, _______,         _______,     _______, _______, _______, _______,  _______
    ),

    [_RAPID] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, R_LEFT,  R_DOWN,  R_UP,    R_RIGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
    ),

    // /* Adjust (Lower + Raise)
    // *                      v------------------------RGB CONTROL--------------------v
    // * ,-----------------------------------------------------------------------------------.
    // * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
    // * |------+------+------+------+------+------+------+------+------+------+------+------|
    // * |      | Awake| Sleep|      |      | Game |      |      | VolD | VolU |      |      |
    // * |------+------+------+------+------+------+------+------+------+------+------+------|
    // * |      |      | Flash| Comp |      |      |      | Mute |      | Camel| Snake|      |
    // * |------+------+------+------+------+------+------+------+------+------+------+------|
    // * |      |      |      |      |      |             |      |      |      |      | Base |
    // * `-----------------------------------------------------------------------------------'
    // */
    [_ADJUST] = LAYOUT_planck_mit(
        _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI,   RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI,    RGB_VAD,    KC_DEL ,
        KC_CAPS, KC_WAKE, SLEEP,   _______, _______, TG(_GAME), _______, _______, KC_VOLD, KC_VOLU,    _______,    _______,
        _______, _______, FLASH,   COMPILE, _______, _______,   _______, KC_MUTE, _______, TG(_CAMEL), TG(_SNAKE), _______,
        _______, _______, _______, _______, _______,       _______,      _______, _______,  _______,   _______,    CK_BASE
    ),

    /* Number
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |   (  |  )   |   1  |   2  |   3  |   +  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F5  |  F6  |  F7  |  F8  |   €  |  $   |   4  |   5  |   6  |   -  |  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F9  |  F10 |  F11 |  F12 | Lock |  %   |   7  |   8  |   9  |   /  | Enter|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |   .  |   0  |   ,  |   *  |   =  |
    * `-----------------------------------------------------------------------------------'
    */
    [_NUMBER] = LAYOUT_planck_mit(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   SE_LPRN,  SE_RPRN,   KC_1,   KC_2, KC_3,    SE_PLUS, KC_BSPC,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   SE_EURO,  SE_DLR,    KC_4,   KC_5, KC_6,    SE_MINS, KC_DEL,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG_NUM,   SE_PERC,   KC_7,   KC_8, KC_9,    SE_SLSH, KC_ENT,
        _______, _______, _______, _______, _______,       _______,       KC_DOT, KC_0, KC_COMM, SE_ASTR, SE_EQL
    ),

    [_SNAKE] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      SE_UNDS,     _______, _______, _______, _______, _______
    ),

    [_CAMEL] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,   OSM(MOD_LSFT),  _______, _______, _______, _______, _______
    ),

     /* Game
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | BLTog| Ctrl | Alt  | GUI  |Space |Game numbers |Raise | Base | Left | Down |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_GAME] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT ,
        RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  MO(_GAME_NUMS),   RSE_SPC, CK_BASE, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Game numbers
    * ,-----------------------------------------------------------------------------------.
    * |      |   5  |   2  |   6  |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   1  |   4  |   3  |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   7  |   8  |   9  |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_GAME_NUMS] = LAYOUT_planck_mit(
        _______, KC_5,    KC_2,    KC_6,    _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_1,    KC_4,    KC_3,    _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
    ),

};


layer_state_t layer_state_set_user(layer_state_t state) {
    #ifdef RGBLIGHT_ENABLE
        switch (get_highest_layer(state)) {
        case _RAISE:
            rgblight_setrgb (0x00,  0x00, 0xFF);
            break;
        case _LOWER:
            rgblight_setrgb (0xFF,  0x00, 0x00);
            break;
        case _NUMBER:
            rgblight_setrgb (0x00,  0xFF, 0x00);
            break;
        case _ADJUST:
            rgblight_setrgb (0x7A,  0x00, 0xFF);
            break;
        default: //  for any other layers, or the default layer
            rgblight_setrgb (0x00,  0xFF, 0xFF);
            break;
    }
    #endif
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}