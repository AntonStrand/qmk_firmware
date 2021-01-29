COMBO_ENABLE = yes
OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
WPM_ENABLE = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/layer_state_reader.c \
        ./lib/keylogger.c \
        ./lib/host_led_state_reader.c \
