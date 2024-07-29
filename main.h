#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* Function prototypes */
int _putchar(char c);
int _printf(const char *format, ...);
int (*op_print(char s))(va_list);
int op_char(va_list args);
int op_str(va_list args);
int op_int(va_list args);
int op_percent(va_list args);
void print_number(int num);

typedef struct specifier
{
    char spec;
    int (*func)(va_list);
} specifier_t;

#endif
