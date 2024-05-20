// kernel.c
#include "kernel.h"

void kmain(void) {
    // Clear the screen
    clear_screen();

    // Print "42" to demonstrate basic screen output
    print_char('4', cursor_row, cursor_col++);
    print_char('2', cursor_row, cursor_col++);

    // Print a new line for better formatting
    cursor_row++;
    cursor_col = 0;

    // Initialize screens (if implementing multiple screens)
    init_screens();

    // Print text in various colors on black background
    print_colored_char('H', cursor_row, cursor_col++, BLUE_ON_BLACK);
    print_colored_char('e', cursor_row, cursor_col++, GREEN_ON_BLACK);
    print_colored_char('l', cursor_row, cursor_col++, CYAN_ON_BLACK);
    print_colored_char('l', cursor_row, cursor_col++, RED_ON_BLACK);
    print_colored_char('o', cursor_row, cursor_col++, MAGENTA_ON_BLACK);
    print_colored_char(',', cursor_row, cursor_col++, BROWN_ON_BLACK);
    print_colored_char(' ', cursor_row, cursor_col++, LIGHT_GREY_ON_BLACK);
    print_colored_char('W', cursor_row, cursor_col++, LIGHT_BLUE_ON_BLACK);
    print_colored_char('o', cursor_row, cursor_col++, LIGHT_GREEN_ON_BLACK);
    print_colored_char('r', cursor_row, cursor_col++, LIGHT_CYAN_ON_BLACK);
    print_colored_char('l', cursor_row, cursor_col++, LIGHT_RED_ON_BLACK);
    print_colored_char('d', cursor_row, cursor_col++, LIGHT_MAGENTA_ON_BLACK);
    print_colored_char('!', cursor_row, cursor_col++, YELLOW_ON_BLACK);

    // Print a new line for better formatting
    cursor_row++;
    cursor_col = 0;

    // Print text in various colors on white background
    print_colored_char('K', cursor_row, cursor_col++, BLUE_ON_WHITE);
    print_colored_char('F', cursor_row, cursor_col++, GREEN_ON_WHITE);
    print_colored_char('S', cursor_row, cursor_col++, CYAN_ON_WHITE);
    print_colored_char(' ', cursor_row, cursor_col++, RED_ON_WHITE);
    print_colored_char('P', cursor_row, cursor_col++, MAGENTA_ON_WHITE);
    print_colored_char('R', cursor_row, cursor_col++, BROWN_ON_WHITE);
    print_colored_char('O', cursor_row, cursor_col++, LIGHT_GREY_ON_WHITE);
    print_colored_char('J', cursor_row, cursor_col++, LIGHT_BLUE_ON_WHITE);
    print_colored_char('E', cursor_row, cursor_col++, LIGHT_GREEN_ON_WHITE);
    print_colored_char('C', cursor_row, cursor_col++, LIGHT_CYAN_ON_WHITE);
    print_colored_char('T', cursor_row, cursor_col++, LIGHT_RED_ON_WHITE);
    print_colored_char('S', cursor_row, cursor_col++, LIGHT_MAGENTA_ON_WHITE);
    print_colored_char('!', cursor_row, cursor_col++, YELLOW_ON_WHITE);

    // Print a new line for better formatting
    cursor_row++;
    cursor_col = 0;

    // Demonstrate printf function
    printf("Welcome to my kernel!\n");

    // Enter an infinite loop to keep the kernel running
    while (1) {
        // Poll for keyboard input
        keyboard_handler();
    }
}
