// keyboard.c
#include "kernel.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

// Scancode set for US QWERTY keyboard
static char keymap[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', /* Backspace */
    '\t', /* Tab */
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter key */
    0, /* Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 
    0, /* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 
    0, /* Right shift */
    '*',
    0, /* Alt */
    ' ', /* Space bar */
    0, /* Caps lock */
    0, /* F1 key ... */
    0, /* F2 key ... */
    0, /* F3 key ... */
    0, /* F4 key ... */
    0, /* F5 key ... */
    0, /* F6 key ... */
    0, /* F7 key ... */
    0, /* F8 key ... */
    0, /* F9 key ... */
    0, /* F10 key ... */
    0, /* Num lock */
    0, /* Scroll Lock */
    0, /* Home key */
    0, /* Up Arrow */
    0, /* Page Up */
    '-',
    0, /* Left Arrow */
    0,
    0, /* Right Arrow */
    '+',
    0, /* End key */
    0, /* Down Arrow */
    0, /* Page Down */
    0, /* Insert key */
    0, /* Delete key */
    0, 0, 0, 0, /* F11 key ... */
    0, /* F12 key ... */
    0, /* All other keys are undefined */
};

char keycode_to_char(char keycode) {
    // Check if the keycode is within the valid range
    if (keycode >= sizeof(keymap) / sizeof(keymap[0])) {
        return 0;
    }
    return keymap[(int)keycode];
}

void keyboard_handler() {
    unsigned char status;
    char keycode;

    status = inb(KEYBOARD_STATUS_PORT);
    if (status & 0x01) {
        keycode = inb(KEYBOARD_DATA_PORT);
        if (keycode < 0) {
            return;
        }

        // Convert keycode to character and print it
        char ch = keycode_to_char(keycode);
        if (ch)
            print_char(ch, cursor_row, cursor_col);
    }
}
