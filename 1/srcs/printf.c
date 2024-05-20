// printf.c
#include "kernel.h"
#include <stdarg.h>

void printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            if (*p == 'd') {
                int num = va_arg(args, int);
                // Convert and print integer (implement int to string conversion and printing)
            } else if (*p == 'c') {
                char ch = (char)va_arg(args, int);
                print_char(ch, cursor_row, cursor_col);
            } else if (*p == 's') {
                char *str = va_arg(args, char *);
                while (*str) {
                    print_char(*str++, cursor_row, cursor_col);
                }
            }
        } else {
            print_char(*p, cursor_row, cursor_col);
        }
    }

    va_end(args);
}

