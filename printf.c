#include "main.h"

/**
 * _printf - A custom printf function that handles various format specifiers
 * @format: The format string containing format specifiers
 *
 * Return: The number of characters printed, or -1 on failure
 */
int _printf(const char *format, ...)
{
    va_list args;
    int (*f)(va_list);
    int i = 0, count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
            {
                _putchar('%');
                count++;
            }
            else
            {
                f = op_print(format[i]);
                if (f)
                {
                    count += f(args);
                }
                else
                {
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
                }
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
