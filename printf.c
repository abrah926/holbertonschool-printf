#include "main.h"

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
 * printf - prints out text from a unknown number of arguments
 *
 * @format: format specifier
 * Return: Number of bytes
 *
 */

int _printf(const char *format, ...)
{
	int num;
	int i = 0;
	int count = 0;

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
            {
                num = va_arg(args, int);
                if (num < 0)
                {
                    _putchar('-');
                    count++;
                    num = -num;
                }
                print_number(num);
                {
                    int temp = num;
                    while (temp)
                    {
                        count++;
                        temp /= 10;
                    }
                }
            }
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				count += str_len;
			}
				  else
            {
                /* Handle unknown format specifiers */
                _putchar('%');
                _putchar(*format);
                count += 2;
            }
		}
		format++;
	}

	va_end(args);

	return (count);

}
