#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void);
int _printf(const char *format, ...);
void print_number(int num);
void print_unsigned(unsigned int num, int base, int uppercase);
void print_pointer(void *ptr);

#endif
