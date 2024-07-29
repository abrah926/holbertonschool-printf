#include "main.h"
#include <limits.h>
#include <stddef.h>

/**
 * print_number - Helper function to print an integer
 * @num: The integer to print
 */
void print_number(int num)
{
    if (num / 10)
        print_number(num / 10);
    _putchar((num % 10) + '0');
}

/**
 * op_int - prints an integer
 * @args: number of arguments
 * Return: count of digits printed
 */
int op_int(va_list args)
{
    int num;
    int count = 0;
    int i;

    num = va_arg(args, int);
    if (num == INT_MIN)
    {
        char *min_int = "-2147483648";
        for (i = 0; min_int[i] != '\0'; i++)
        {
            _putchar(min_int[i]);
            count++;
        }
    }
    else
    {
        if (num < 0)
        {
            _putchar('-');
            count++;
            num = -num;
        }
        print_number(num);
        {
            int temp = num;
            int digits = 0;

            if (temp == 0)
            {
                digits = 1;
            }
            else
            {
                while (temp)
                {
                    digits++;
                    temp /= 10;
                }
            }
            count += digits;
        }
    }
    return (count);
}

/**
 * op_char - prints a character
 * @args: number of arguments
 * Return: count of characters printed
 */
int op_char(va_list args)
{
    char c = va_arg(args, int);
    _putchar(c);
    return (1);
}

/**
 * op_str - prints a string
 * @args: number of arguments
 * Return: count of characters printed
 */
int op_str(va_list args)
{
    char *str = va_arg(args, char*);
    int count = 0;

    if (str == NULL)
        str = "(null)";
    while (*str)
    {
        _putchar(*str);
        str++;
        count++;
    }
    return (count);
}

/**
 * op_percent - prints a percent sign
 * @args: number of arguments
 * Return: count of characters printed
 */
int op_percent(va_list args __attribute__((unused)))
{
    _putchar('%');
    return (1);
}
