#include "main.h"
#include <limits.h>
#include <stdarg.h>

/**
 * print_number - Helper function to print an integer
 * @num: The integer to print
 */
void print_number(int num)
{
    if (num < 0) 
    {
        _putchar('-');
        num = -num;
    }
    if (num / 10)
        print_number(num / 10);
    _putchar((num % 10) + '0');
}

/**
 * print_unsigned - Helper function to print an unsigned integer
 * @num: The unsigned integer to print
 * @base: The base for the number (8 for octal, 10 for decimal, 16 for hex)
 * @uppercase: 1 for uppercase hex, 0 for lowercase
 */
void print_unsigned(unsigned int num, int base, int uppercase)
{
    char digits[] = "0123456789abcdef";
    char digits_upper[] = "0123456789ABCDEF";
    char buffer[50];
    int i = 0;

    if (num == 0)
    {
        buffer[i++] = '0';
    }
    else
    {
        if (uppercase)
            while (num != 0)
            {
                buffer[i++] = digits_upper[num % base];
                num /= base;
            }
        else
            while (num != 0)
            {
                buffer[i++] = digits[num % base];
                num /= base;
            }
    }

    while (i--)
        _putchar(buffer[i]);
}

/**
 * print_pointer - Helper function to print a pointer address
 * @ptr: The pointer to print
 */
void print_pointer(void *ptr)
{
    unsigned long addr;
    char digits[] = "0123456789abcdef";
    char buffer[50];
    int i = 0;

    addr = (unsigned long)ptr;
    _putchar('0');
    _putchar('x');

    if (addr == 0)
    {
        _putchar('0');
    }
    else
    {
        while (addr != 0)
        {
            buffer[i++] = digits[addr % 16];
            addr /= 16;
        }

        while (i--)
            _putchar(buffer[i]);
    }
}

/**
 * _printf - Produces output according to a format
 * @format: Format string containing the characters and the specifiers
 * 
 * Return: Number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    int i, countB, c, num;
    unsigned int u_num, o_num, x_num, X_num;
    unsigned long addr;
    char *str;
    void *ptr;
    va_list args;

    if (format == NULL)
    {
        return (-1);
    }

    countB = 0;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) 
    {
        if (format[i] == '%') 
        {
            i++;
            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                _putchar(c);
                countB++;
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL) 
                {
                    str = "(null)";
                }
                while (*str) 
                {
                    _putchar(*str++);
                    countB++;
                }
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                num = va_arg(args, int);
                if (num < 0) 
                {
                    _putchar('-');
                    countB++;
                    num = -num;
                }
                print_number(num);
                {
                    int temp = num;
                    while (temp)
                    {
                        countB++;
                        temp /= 10;
                    }
                }
            }
            else if (format[i] == 'u')
            {
                u_num = va_arg(args, unsigned int);
                print_unsigned(u_num, 10, 0);
                {
                    unsigned int temp = u_num;
                    while (temp)
                    {
                        countB++;
                        temp /= 10;
                    }
                }
            }
            else if (format[i] == 'o')
            {
                o_num = va_arg(args, unsigned int);
                print_unsigned(o_num, 8, 0);
                {
                    unsigned int temp = o_num;
                    while (temp)
                    {
                        countB++;
                        temp /= 8;
                    }
                }
            }
            else if (format[i] == 'x')
            {
                x_num = va_arg(args, unsigned int);
                print_unsigned(x_num, 16, 0);
                {
                    unsigned int temp = x_num;
                    while (temp)
                    {
                        countB++;
                        temp /= 16;
                    }
                }
            }
            else if (format[i] == 'X')
            {
                X_num = va_arg(args, unsigned int);
                print_unsigned(X_num, 16, 1);
                {
                    unsigned int temp = X_num;
                    while (temp)
                    {
                        countB++;
                        temp /= 16;
                    }
                }
            }
            else if (format[i] == 'p')
            {
                ptr = va_arg(args, void *);
                print_pointer(ptr);
                countB += 2;
                addr = (unsigned long)ptr;
                while (addr)
                {
                    countB++;
                    addr /= 16;
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%');
                countB++;
            }
            else
            {
                _putchar('%');
                _putchar(format[i]);
                countB += 2;
            }
        } 
        else 
        {
            _putchar(format[i]);
            countB++;
        }
    }

    va_end(args);
    return countB;
}

