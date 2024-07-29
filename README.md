
Custom printf Project


This repository contains a custom implementation of the printf function in C. The project is part of the Holberton School curriculum, aimed at deepening the understanding of variadic functions, string manipulation, and formatted output.
Description

The function _printf writes output to standard output. The function writes under the control of a format string that specifies how subsequent arguments (accessed via the variable-length argument facilities of stdarg) are converted for output.

Prototype: int _printf(const char *format, ...);

Return Value: Upon successful return, _printf returns the number of characters printed (excluding the terminating null byte used to end output to strings). If an output error is encountered, the function returns -1.
Project Structure

    Header File: main.h - Contains the structure definition and function prototypes.
    Source Files:
        functions.c - Contains various utility functions like _putchar, print_number, op_int, op_char, op_str, and op_percent.
        printf.c - Implements the core _printf function.
    Test Files: main.c - Contains example main functions to test the implementation.

Requirements

    Allowed editors: vi, vim, emacs
    All files will be compiled on Ubuntu 20.04 LTS using gcc with the options -Wall -Werror -Wextra -pedantic -std=gnu89
    All files should end with a new line
    A README.md file at the root of the project folder is mandatory
    Code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    No global variables allowed
    No more than 5 functions per file
    Allowed C standard library functions: malloc, free, exit
    Use _putchar function provided by Holberton School
    All header files should be include guarded

Usage

To compile the code, use the following command:

sh

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf

To run the compiled program, use:

sh

./printf

Functions
_printf

A custom implementation of the printf function.

Prototype: int _printf(const char *format, ...);

Description: The _printf function handles various format specifiers, including %c, %s, %d, %i, and %%. It uses helper functions to print characters, strings, integers, and percent signs.
_putchar

Writes a character to stdout.

Prototype: int _putchar(char c);
print_number

Helper function to print an integer.

Prototype: void print_number(int num);
op_int

Prints an integer.

Prototype: int op_int(va_list args);
op_char

Prints a character.

Prototype: int op_char(va_list args);
op_str

Prints a string.

Prototype: int op_str(va_list args);
op_percent

Prints a percent sign.

Prototype: int op_percent(va_list args __attribute__((unused)));
op_print

Selects the correct function to perform the operation based on the specifier.

Prototype: int (*op_print(char s))(va_list);
Header File: main.h

Contains the function prototypes and structure definitions for the project.
Authors

    @Sigidibau
    @Dark926

License

This project is licensed under the MIT License - see the LICENSE file for details.

