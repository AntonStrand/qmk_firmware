#ifndef USERSPACE
#define USERSPACE

#include "combos_config.h"

#define RGB_DISABLE_WHEN_USB_SUSPENDED true

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif

#ifdef OLED_DRIVER_ENABLED
#    define OLED_FONT_H "users/antonstrand/glcdfont.c"
#endif

#define TAPPING_TERM 200

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD

#endif
