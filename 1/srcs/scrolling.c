// scrolling.c
#include "kernel.h"

#define VIDEO_MEMORY 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

int cursor_row = 0;
int cursor_col = 0;

void init_screens() {
    // Implementation for initializing screens
}

void clear_screen() {
    unsigned char *video_memory = (unsigned char *)VIDEO_MEMORY;
    for (int i = 0; i < MAX_ROWS * MAX_COLS * 2; i++) {
        video_memory[i] = ' ';
    }
    cursor_row = 0;
    cursor_col = 0;
}

void scroll_screen() {
    unsigned char *video_memory = (unsigned char *)VIDEO_MEMORY;
    for (int i = 0; i < (MAX_ROWS - 1) * MAX_COLS * 2; i++) {
        video_memory[i] = video_memory[i + MAX_COLS * 2];
    }
    for (int i = (MAX_ROWS - 1) * MAX_COLS * 2; i < MAX_ROWS * MAX_COLS * 2; i++) {
        video_memory[i] = ' ';
    }
    cursor_row = MAX_ROWS - 1;
    cursor_col = 0;
}

void move_cursor(int row, int col) {
    unsigned short position = (row * MAX_COLS) + col;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(position & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char)((position >> 8) & 0xFF));
}

void print_char(char character, int row, int col) {
    unsigned char *video_memory = (unsigned char *)VIDEO_MEMORY;
    if (row >= MAX_ROWS || col >= MAX_COLS) {
        return;
    }
    int offset = (row * MAX_COLS + col) * 2;
    video_memory[offset] = character;
    video_memory[offset + 1] = WHITE_ON_BLACK;
}

