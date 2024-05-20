// kernel.h

#ifndef KERNEL_H
#define KERNEL_H

#define VIDEO_MEMORY 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

// Color codes for text on black background
#define BLACK_ON_BLACK 0x00
#define BLUE_ON_BLACK 0x01
#define GREEN_ON_BLACK 0x02
#define CYAN_ON_BLACK 0x03
#define RED_ON_BLACK 0x04
#define MAGENTA_ON_BLACK 0x05
#define BROWN_ON_BLACK 0x06
#define LIGHT_GREY_ON_BLACK 0x07
#define DARK_GREY_ON_BLACK 0x08
#define LIGHT_BLUE_ON_BLACK 0x09
#define LIGHT_GREEN_ON_BLACK 0x0A
#define LIGHT_CYAN_ON_BLACK 0x0B
#define LIGHT_RED_ON_BLACK 0x0C
#define LIGHT_MAGENTA_ON_BLACK 0x0D
#define YELLOW_ON_BLACK 0x0E
#define WHITE_ON_BLACK 0x0F

// Color codes for text on white background
#define BLACK_ON_WHITE 0xF0
#define BLUE_ON_WHITE 0xF1
#define GREEN_ON_WHITE 0xF2
#define CYAN_ON_WHITE 0xF3
#define RED_ON_WHITE 0xF4
#define MAGENTA_ON_WHITE 0xF5
#define BROWN_ON_WHITE 0xF6
#define LIGHT_GREY_ON_WHITE 0xF7
#define DARK_GREY_ON_WHITE 0xF8
#define LIGHT_BLUE_ON_WHITE 0xF9
#define LIGHT_GREEN_ON_WHITE 0xFA
#define LIGHT_CYAN_ON_WHITE 0xFB
#define LIGHT_RED_ON_WHITE 0xFC
#define LIGHT_MAGENTA_ON_WHITE 0xFD
#define YELLOW_ON_WHITE 0xFE
#define WHITE_ON_WHITE 0xFF

extern int cursor_row;
extern int cursor_col;

void clear_screen();
void scroll_screen();
void move_cursor(int row, int col);
void print_char(char character, int row, int col);
void print_colored_char(char character, int row, int col, unsigned char color);

void printf(const char *format, ...);

void keyboard_handler();
char keycode_to_char(char keycode);

void init_screens();
void switch_screen(int screen_number);
void save_current_screen();

static inline void outb(unsigned short port, unsigned char val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

#endif // KERNEL_H
