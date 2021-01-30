COMBO_ENABLE = yes
OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
EXTRAKEY_ENABLE = yes       # Audio control and System control
WPM_ENABLE = yes

# If you want to change the display of OLED, you need to change here
SRC += ./lib/host_led_state_reader.c \
