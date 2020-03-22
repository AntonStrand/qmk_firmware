#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#define ______ KC_TRNS

/** Custom Keys */
enum custom_keycodes {
  CK_CUT = LGUI(KC_X),
  CK_COPY = LGUI(KC_C),
  CK_PASTE = LGUI(KC_V),
  CK_UNDO = LGUI(KC_Z),
  CK_FIND = LGUI(KC_F),
};

/** LAYERS */
#define SWE 1
#define ARROW 2
#define MOUSE 3
#define RGB 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | LAY1    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | SWE |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Alt  |  Cmd  | Bkspc/MOUSE | Spc |   ARROW/SPACE   | RAlt | RGB |  L |  D  |  R |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_all(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, SE_MINS, SE_EQL, ______, KC_BSPC,

      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, SE_LBRC, SE_RBRC, SE_BSLS,

      LT(MOUSE, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,

      KC_LSFT, ______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, TG(SWE),

      KC_LCTL, KC_LALT, KC_LGUI, LT(MOUSE, KC_BSPC), KC_SPC, LT(ARROW, KC_SPC), KC_RALT, TG(RGB), KC_LEFT, KC_DOWN, KC_RIGHT
      ),

  /* Swedish Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  +  |  ´  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  Å  |  ¨  |    '   |
   * |-----------------------------------------------------------------------------------------+
   * | LAY1    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ä  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  -  | RSh |  U | Base |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Alt  |  Cmd  | Bkspc/MOUSE | ARROW/Spc |   SPACE   | RAlt | RGB |  L |  D  |  R |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_all(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,

      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,

      LT(MOUSE, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,

      KC_LSFT, ______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, ______,

      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______
      ),

  /* Arrow Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   DEL     |
   * |-----------------------------------------------------------------------------------------+
   * |       |     |     | Enter | Del | Find |   | Undo | Cut | Copy | Paste |    |    |      |
   * |-----------------------------------------------------------------------------------------+
   * |         |  LSh | LCtrl | LAlt | LCmd |   |   | Left | Down |  Up | Right |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |           | Undo | Cut | Copy | Paste | Esc | Enter |   |   |    |    |     |VOL+| MUTE |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |     | BRI- |VOL-| BRI+ |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_all(
      KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, ______, KC_DEL,

      ______, ______, KC_ESC, KC_ENT, KC_DEL, CK_FIND, ______, CK_UNDO, CK_CUT, CK_COPY, CK_PASTE, ______, ______, ______,

      ______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, ______, ______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ______, ______, 

      ______, ______, CK_UNDO, CK_CUT, CK_COPY, CK_PASTE, ______, KC_ESC, KC_ENT, ______, ______, ______, ______, KC_VOLU, KC_MUTE,

      ______, ______, ______, ______, ______, ______, ______, ______, KC_BRID, KC_VOLD, KC_BRIU
      ),


  /* Mouse Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   DEL     |
   * |-----------------------------------------------------------------------------------------+
   * |       |     | Spd 1 | Spd 2 | Spd 3 |     |     |     |     |     |     |      |        | 
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     | RBtn | LBtn |    |    | Left | Down |  Up | Right |    |          |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |   |   |   |   |   | Scrl L | Scrl U | Scrl D | Scrl R |     |    |    |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                      |     |     |     |    |    |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_all(
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  ______, ______, ______, ______, ______,

      ______, ______, KC_ACL0, KC_ACL1, KC_ACL2, ______, ______, ______, ______, ______, ______, ______, ______, ______,

      ______, ______, ______, KC_BTN2, KC_BTN1, ______, ______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ______, ______,

      ______, ______, ______, ______, ______, ______, ______, ______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, ______, ______,

      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ),


  /* RGB Layer
   * ,-----------------------------------------------------------------------------------------.
   * | RESET |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  RESET  |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |      |      |      |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL+ | BL- |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_all(
      RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, ______, RESET,

      ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______, ______, ______, ______, ______,

      ______, BL_TOGG, BL_STEP, BL_INC, BL_DEC, ______, ______, ______, ______, ______, ______, ______, ______,

      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,

      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______
      ),
};


	// [SWE] = LAYOUT(
  //   KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
  //   KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, SE_ARNG, OSL(ENG), KC_BSLS,
  //   KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SE_ODIA, SE_ADIA, KC_ENT,
  //   KC_LSFT, SE_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
  //   KC_LCTL, KC_LALT, KC_LGUI, LT(MOUSE, KC_BSPC), TT(ARROW), KC_SPC, KC_RALT, TT(MOUSE), KC_LEFT, KC_DOWN, KC_RGHT),
  
	// [ENG] = LAYOUT(
	// 	KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
	// 	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
	// 	KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
	// 	KC_LSFT, SE_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
	// 	_______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
  // ),

  // [ARROW] = LAYOUT(
  //   KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
  //   KC_NO, KC_NO, KC_NO, KC_NO, KC_FIND, KC_NO, KC_COPY, KC_UNDO, KC_NO, KC_NO, KC_PSTE, KC_NO, KC_NO, KC_NO,
  //   KC_NO, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO,
  //   KC_NO, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRIU, KC_MUTE,
  //   _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_BRID, KC_VOLU),

  // [MOUSE] = LAYOUT(
  //   KC_NO, TG(SWE), TG(ENG), TG(ARROW), TG(MOUSE), TG(RGB), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_R, KC_NO,
  //   KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_MS_U, KC_NO, KC_NO,
  //   KC_NO, KC_NO, KC_ACL2, KC_ACL1, KC_ACL0, KC_WH_D, KC_WH_U, KC_NO, KC_NO, KC_MS_D, KC_BTN1, KC_MS_U, KC_BTN2,
  //   _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R),

	// [RGB] = LAYOUT(
	// 	KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_DEL,
	// 	_______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,
	// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	// 	_______, _______, _______, _______, BL_DEC, BL_TOGG, BL_INC, BL_STEP, _______, _______, _______, _______, _______, _______,
	// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
