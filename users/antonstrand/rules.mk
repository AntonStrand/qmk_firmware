SRC += antonstrand.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
  SRC += combos.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dance.c
endif