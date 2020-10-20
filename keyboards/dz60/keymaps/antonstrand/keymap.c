#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "sendstring_swedish.h"
#define ______ KC_TRNS

/** Custom Keys */
enum custom_keycodes { CK_CUT = LGUI(KC_X), CK_COPY = LGUI(KC_C), CK_PASTE = LGUI(KC_V), CK_UNDO = LGUI(KC_Z), CK_FIND = LGUI(KC_F), CK_LCBR = LSFT(LALT(SE_8)), CK_RCBR = LSFT(LALT(SE_9)), PIPE = SAFE_RANGE, COMPOSE, SKINNY_ARROW, SELECT_APP, SELECT_WORD, CK_LEFT_5, CK_DOWN_5, CK_UP_5, CK_RIGHT_5 };

/** LAYERS */
#define BASE 0
#define ARROW 1
#define MOUSE 2
#define SYMBOL 3
#define RGB 4
#define RAPID 5

enum { TD_RCBR = 0, TD_RBRC = 1, TD_RESET = 2 };

void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        // Reset the keyboard if you tap the key more than three times
        reset_keyboard();
        reset_tap_dance(state);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {[TD_RCBR] = ACTION_TAP_DANCE_DOUBLE(CK_LCBR, CK_RCBR), [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(SE_LBRC, SE_RBRC), [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Swedish Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  +  |  ´  |   Bkspc   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  Å  |  ¨  |    '   |
     * |-----------------------------------------------------------------------------------------+
     * | SYMBOL  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ä  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  -  | RSh |  U | Del  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl |  Alt  |  Cmd  | Bkspc/MOUSE | LEAD |   ARROW/SPACE   | RAlt | RGB |  L |  D  |  R |
     * `-----------------------------------------------------------------------------------------'
     */

    LAYOUT_all(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,

               KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,

               OSL(SYMBOL), MT(MOD_LSFT, KC_A), MT(MOD_LCTL, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, SE_ODIA, SE_ADIA, KC_ENT,

               OSM(MOD_LSFT), ______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,

               KC_LCTL, KC_LALT, KC_LGUI, LT(MOUSE, KC_BSPC), KC_LEAD, LT(ARROW, KC_SPC), KC_RALT, MO(RGB), KC_LEFT, KC_DOWN, KC_RIGHT),

    /* Arrow Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |     |     |     |     |     |     |     |     |     |     |     |     |   DEL     |
     * |-----------------------------------------------------------------------------------------+
     * |       |     | Slt word | Enter | Del | Find |   | Undo | Cut | Copy | Paste |    |    |      |
     * |-----------------------------------------------------------------------------------------+
     * |         |  LSh | LCtrl | LAlt | LCmd | Slt App |  | Left | Down |  Up | Right |  |      |
     * |-----------------------------------------------------------------------------------------+
     * |           | Undo | Cut | Copy | RAPID |    | Esc | Enter |   |    |    |    |VOL+| MUTE |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |       |                                   |     |     | BRI- |VOL-| BRI+ |
     * `-----------------------------------------------------------------------------------------'
     */

    LAYOUT_all(______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_DEL,

               ______, ______, SELECT_WORD, KC_ENT, KC_DEL, CK_FIND, ______, CK_UNDO, CK_CUT, CK_COPY, CK_PASTE, ______, ______, ______,

               ______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, SELECT_APP, ______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ______, ______,

               ______, ______, CK_UNDO, CK_CUT, CK_COPY, MO(RAPID), ______, KC_ESC, KC_ENT, ______, ______, ______, ______, KC_VOLU, KC_MUTE,

               ______, ______, ______, ______, ______, ______, ______, ______, KC_BRID, KC_VOLD, KC_BRIU),

    /* Mouse Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |     |     |     |     |     |     |     |     |     |     |     |     |           |
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

    LAYOUT_all(______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, ______, KC_ACL0, KC_ACL1, KC_ACL2, ______, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, ______, ______, KC_BTN2, KC_BTN1, ______, ______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ______, ______,

               ______, ______, ______, ______, ______, ______, ______, ______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, ______, ______,

               ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ),

    /* Symbol Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |    |     |  #  |  $   |  %  |     |     |     |     |     |     |     |           |
     * |-----------------------------------------------------------------------------------------+
     * |       |  "  |  '  |  (|)  | & |  /  |     |  _  | (  |  )  |  -  |  +  |   =  |    ~    |
     * |-----------------------------------------------------------------------------------------+
     * |         |  @  |  >>  | -> | (|>) |    |    |  <  |  []  |  {}  |  >  |  *  |            |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |    |    |    |    |     |    |    |     |     |  (\)  |     |    |    |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |       |                                      |     |     |     |    |    |
     * `-----------------------------------------------------------------------------------------'
     */

    LAYOUT_all(______, ______, ______, SE_HASH, A(SE_4), SE_PERC, ______, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, SE_DQUO, SE_QUOT, A(KC_7), SE_AMPR, SE_SLSH, ______, S(SE_MINS), SE_LPRN, SE_RPRN, SE_MINS, SE_PLUS, SE_EQL, SE_TILD,

               ______, SE_AT, COMPOSE, SKINNY_ARROW, PIPE, ______, ______, KC_GRV, TD(TD_RBRC), TD(TD_RCBR), S(KC_GRV), SE_ASTR, ______,

               ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, SE_BSLS, ______, ______, ______,

               ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______),

    /* RGB Layer
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |     |     |  RESET 3  |
     * |-----------------------------------------------------------------------------------------+
     * |        | F1 |  F2 |  F3  |  F4  |    |     |     |     |     |     |      |      |      |
     * |-----------------------------------------------------------------------------------------+
     * |         |  F5 |  F6 |  F7 |  F8 |     |     |     |     |     |     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |  F9 | F10 | F11 | F12 |     |     |     |     |     |     |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |       |                                   |     |      |     |     |     |
     * `-----------------------------------------------------------------------------------------'
     */

    LAYOUT_all(______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, TD_RESET,

               ______, KC_F1, KC_F2, KC_F3, KC_F4, ______, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, KC_F5, KC_F6, KC_F7, KC_F8, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, KC_F9, KC_F10, KC_F11, KC_F12, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______),

    /* Rapid Layer
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
     * |-----------------------------------------------------------------------------------------+
     * |       |     |      |      |      |      |      |     |      |     |     |      |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |     |     |      |     |    |    | Left 5 | Down 5 |  Up 5 | Right 5 |    |   |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |    |     |    |     |      |     |      |     |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |       |                                      |     |     |     |    |    |
     * `-----------------------------------------------------------------------------------------'
     */

    LAYOUT_all(______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, ______, ______, ______, ______, ______, ______, CK_LEFT_5, CK_DOWN_5, CK_UP_5, CK_RIGHT_5, ______, ______,

               ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,

               ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ),
};

void matrix_init_user(void) { rgblight_enable(); }

LEADER_EXTERNS();

void mod_type(uint16_t modcode, uint16_t keycode) {
    register_code16(modcode);
    tap_code16(keycode);
    unregister_code16(modcode);
}

void mod2_type(uint16_t modcode1, uint16_t modcode2, uint16_t keycode) {
    register_code16(modcode1);
    register_code16(modcode2);
    tap_code16(keycode);
    unregister_code16(modcode2);
    unregister_code16(modcode1);
}

void select_word(void) {
    register_code16(KC_LALT);
    tap_code16(KC_RIGHT);
    tap_code16(KC_LEFT);
    register_code16(KC_LSFT);
    tap_code16(KC_RIGHT);
    unregister_code16(KC_LALT);
    unregister_code16(KC_LSFT);
}

void select_line(void) {
    register_code16(KC_LCMD);
    tap_code16(KC_RIGHT);
    tap_code16(KC_LEFT);
    register_code16(KC_LSFT);
    tap_code16(KC_RIGHT);
    unregister_code16(KC_LCMD);
    unregister_code16(KC_LSFT);
}

void select_full_line(void) {
    register_code16(KC_LCMD);
    tap_code16(KC_RIGHT);
    tap_code16(KC_LEFT);
    tap_code16(KC_LEFT);
    register_code16(KC_LSFT);
    tap_code16(KC_RIGHT);
    unregister_code16(KC_LCMD);
    unregister_code16(KC_LSFT);
}

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        SEQ_ONE_KEY(KC_L) { select_line(); }
        SEQ_ONE_KEY(KC_U) { tap_code16(G(KC_Z)); }
        SEQ_ONE_KEY(KC_W) { select_word(); }
        SEQ_TWO_KEYS(KC_L, KC_L) { select_full_line(); }
        SEQ_ONE_KEY(KC_O) {
            tap_code16(KC_DOWN);
            mod_type(KC_LGUI, KC_LEFT);
            tap_code16(KC_ENT);
            tap_code16(KC_UP);
        }
        SEQ_TWO_KEYS(KC_O, KC_O) {
            mod_type(KC_LGUI, KC_LEFT);
            tap_code16(KC_ENT);
            tap_code16(KC_UP);
        }

        SEQ_TWO_KEYS(KC_D, KC_D) {
            select_full_line();
            tap_code(KC_DEL);
            tap_code(KC_DEL);
            register_code16(KC_LALT);
            tap_code16(KC_RIGHT);
            unregister_code16(KC_LALT);
        }

        SEQ_TWO_KEYS(KC_W, KC_Q) {
            register_code(KC_LGUI);
            tap_code(KC_S);
            unregister_code(KC_LGUI);
        }

        leading = false;
        leader_end();
    }
#ifdef RGBLIGHT_ENABLE

    static uint8_t old_layer = 255;
    uint8_t        new_layer = biton32(layer_state);

    if (old_layer != new_layer) {
        switch (new_layer) {
            case BASE:
                rgblight_setrgb(0x00, 0x00, 0xFF);
                break;
            case SYMBOL:
                rgblight_setrgb(0x00, 0xA0, 0xFF);
                break;
            case ARROW:
                rgblight_setrgb(0xFF, 0x00, 0x00);
                break;
            case MOUSE:
                rgblight_setrgb(0xFF, 0x20, 0x00);
                break;
            case RGB:
                rgblight_setrgb(0xFF, 0x00, 0xFF);
                break;
        }

        old_layer = new_layer;
    }

#endif  // RGBLIGHT_ENABLE
}

void repeat_tap(uint16_t times, uint16_t keycode) {
    int i;
    for (i = 0; i < times; i++) {
        tap_code16(keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PIPE:
            if (record->event.pressed) {
                // |>
                tap_code16(A(KC_7));
                tap_code16(S(KC_GRV));
            }
            break;
        case COMPOSE:
            if (record->event.pressed) {
                // >>
                tap_code16(S(KC_GRV));
                tap_code16(S(KC_GRV));
            }
            break;
        case SKINNY_ARROW:
            if (record->event.pressed) {
                // ->
                SEND_STRING("-");
                tap_code16(S(KC_GRV));
            }
            break;
        case SELECT_APP:
            if (record->event.pressed) {
                register_code16(KC_LCMD);
                tap_code16(KC_TAB);
            } else {
                unregister_code16(KC_LCMD);
            }
            break;
        case SELECT_WORD:
            if (record->event.pressed) {
                select_word();
            }
            break;
        case CK_LEFT_5:
            if (record->event.pressed) {
                repeat_tap(5, KC_LEFT);
            }
            break;
        case CK_UP_5:
            if (record->event.pressed) {
                repeat_tap(5, KC_UP);
            }
            break;
        case CK_RIGHT_5:
            if (record->event.pressed) {
                repeat_tap(5, KC_RIGHT);
            }
            break;
        case CK_DOWN_5:
            if (record->event.pressed) {
                repeat_tap(5, KC_DOWN);
            }
            break;
    }
    return true;
};
