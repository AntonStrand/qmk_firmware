
#pragma once

#include "quantum.h"
#include "oled_driver.h"

bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);

// __attribute__((weak)) void render_corne_logo(void);
// __attribute__((weak)) void render_qmk_logo(void);
// __attribute__((weak)) void render_mod_status(void);
// __attribute__((weak)) void render_active_layer(void);
// __attribute__((weak)) void matrix_scan_kb(void);
// __attribute__((weak)) void render_led_state(void);
// __attribute__((weak)) void render_wpm(void);
// __attribute__((weak)) void write_empty_line(void);
// __attribute__((weak)) void render_layer_icon(void);
// __attribute__((weak)) void render_logo(void);
// __attribute__((weak)) void render_main(void);
// __attribute__((weak)) void oled_task_user(void);
