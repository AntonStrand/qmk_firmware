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
#include "keymap_swedish_mac.h"
#include "custom_keycodes.h"

enum layers {
  _SWE,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMBER
};

#define LWR_BSP LT(_LOWER, KC_BSPC)
#define RSE_ENT LT(_RAISE, KC_ENT)

#define NUM_ESC LT(_NUMBER, KC_ESC)
#define TG_NUM TG(_NUMBER)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Å  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Shft '|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Num  | Ctrl | Alt  | GUI  |BK/LWR|    Space    |Ent/RS|  GUI |  Alt | Ctrl | FN ? |
     * `-----------------------------------------------------------------------------------'
     */
    [_SWE] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG,
        NUM_ESC, LCTL_A,  LSFT_S,  LALT_D,  LGUI_F,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SE_ODIA, SE_ADIA,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_ENT,
        RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, LWR_BSP,     KC_SPC,       RSE_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
        RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, LWR_BSP,     KC_SPC,       RSE_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Lower (Nav)
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   "  |   '  |   |  |   &  |   ´  |   $  |   {  |   (  |  )   |  }   |   ^  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |   @  |  >>  |  ->  |  |>  |  =>  |   #  |   [  |   ]  |   ;  |   :  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   +  |   -  |   *  |  /   |  =   |   %  |   \  |   <  |   >  |   _  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Num  | Ctrl | Alt  | GUI  |      |     Tab     |Adjust|  GUI |  Alt | Ctrl |   !  |
     * `-----------------------------------------------------------------------------------'
     */

    [_LOWER] = LAYOUT_planck_mit(
          SE_TILD, SE_DQUO, SE_QUOT, SE_PIPE,      SE_AMPR, KC_EQL,    SE_DLR,  SE_LCBR, SE_LPRN, SE_RPRN, SE_RCBR, SE_CIRC,
          KC_DEL,  SE_AT,   COMPOSE, SKINNY_ARROW, PIPE,    FAT_ARROW, SE_HASH, SE_LBRC, SE_RBRC, SE_SCLN, SE_COLN, SE_GRV,
          KC_LSFT, SE_PLUS, SE_MINS, SE_ASTR,      SE_SLSH, SE_EQL,    SE_PERC, SE_BSLS, SE_LABK, SE_RABK, SE_UNDS, SE_QUOT,
          ______,  ______,  ______,  ______,       ______,        ______,       ______,  ______,  ______,  ______,  KC_EXLM
    ),

    /* Raise (Nav)
     * ,-----------------------------------------------------------------------------------.
     * | <Tab |      |      |      |      |      |      | Undo |  Cut | Copy | Paste|   ?  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  | Shift| Ctrl | Alt  | GUI  |  App |      | Left | Down |  Up  | Right|   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|      |      |      | Rapid|      |      |      | Sc D | Sc U |      |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Num  | Ctrl | Alt  | GUI  |Adjust|     Del     |      |  GUI |  Alt | Ctrl |  FN  |
     * `-----------------------------------------------------------------------------------'
     */
    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_planck_mit(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* Adjust (Lower + Raise)
    *                      v------------------------RGB CONTROL--------------------v
    * ,-----------------------------------------------------------------------------------.
    * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT_planck_mit(
        _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
    ),

    /* Number
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |   (  |  )   |   +  |   1  |   2  |   3  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F5  |  F6  |  F7  |  F8  |   €  |  $   |   -  |   4  |   5  |   6  |  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F9  |  F10 |  F11 |  F12 | Lock |  %   |   /  |   7  |   8  |   9  | Enter|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |   *  |   .  |   0  |   ,  |   =  |
    * `-----------------------------------------------------------------------------------'
    */
    [_NUMBER] = LAYOUT_planck_mit(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   SE_LPRN,  SE_RPRN, SE_PLUS,    KC_1, KC_2, KC_3,    KC_BSPC,
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   SE_EURO,  SE_DLR,  SE_MINS,    KC_4, KC_5, KC_6,    KC_DEL,
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG_NUM,   SE_PERC, SE_SLSH,    KC_7, KC_8, KC_9,    KC_ENT,
      _______, _______, _______, _______, _______,      _______,      SE_ASTR,  KC_DOT, KC_0, KC_COMM, SE_EQL
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
