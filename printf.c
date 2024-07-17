#include < main.h>

/**
 * printf - prints out text from a unknown number of arguments
 *
 * @format: format specifier
 * Return: Number of bytes
 *
 */

int _printf(const char *format, ...);
{
	int i, countB;

	countB = 0

	va_list args;

	va_start (args, format);

	for (i = 0; format [i]; != '\0'; i++)
	{

	if (format [i] != '%')
	{
	putchar (format [i]);
	}
	}

}
