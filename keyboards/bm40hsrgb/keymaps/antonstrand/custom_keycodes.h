#include QMK_KEYBOARD_H
#pragma once

#include "keymap.h"

enum custom_keycodes {
  PIPE = SAFE_RANGE,
  COMPOSE,
  SKINNY_ARROW,
  FAT_ARROW,
  SELECT_APP,
  CK_RAPID_LEFT,
  CK_RAPID_DOWN,
  CK_RAPID_UP,
  CK_RAPID_RIGHT,
  SEND_VERSION,
  SEND_MAKE
};

#define ______ KC_TRNS

#define CK_CUT    LGUI(KC_X)
#define CK_COPY   LGUI(KC_C)
#define CK_PASTE  LGUI(KC_V)
#define CK_UNDO   LGUI(KC_Z)
#define CK_FIND   LGUI(KC_F)

#define LCTL_A    MT(MOD_LCTL, KC_A)
#define LSFT_S    MT(MOD_LSFT, KC_S)
#define LALT_D    MT(MOD_LALT, KC_D)
#define LGUI_F    MT(MOD_LGUI, KC_F)