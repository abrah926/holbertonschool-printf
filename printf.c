#include "main.h"

/**
 * printf - prints out text from a unknown number of arguments
 *
 * @format: format specifier
 * Return: Number of bytes
 *
 */

int _printf(const char *format, ...)
{
	unsigned int i, count = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{

	if (format[i] != '%')
		{
		_putchar (format[i]);
		}
	if (format[i] == '%' && format[i + 1]) == 'c'
	{
		_putchar(va_arg(args, int))
		}
	count += 1;
	}
}
	va_end(args);
	return (count);

