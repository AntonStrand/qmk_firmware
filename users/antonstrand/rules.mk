SRC += antonstrand.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
  SRC += combos.c
endif