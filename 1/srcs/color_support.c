// color_support.c
#include "kernel.h"

void print_colored_char(char character, int row, int col, unsigned char color) {
    unsigned char *video_memory = (unsigned char *)VIDEO_MEMORY;
    if (row >= MAX_ROWS || col >= MAX_COLS) {
        return;
    }
    int offset = (row * MAX_COLS + col) * 2;
    video_memory[offset] = character;
    video_memory[offset + 1] = color;
}

