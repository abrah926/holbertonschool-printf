#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format
 * @format: Format string containing the characters and the specifiers
 * 
 * Return: Number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int i, countB;
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
	i++;  // Move past '%'
	if (format[i] == 'c') 
	{
	int c = va_arg(args, int);
	putchar(c);
	countB++;
	} else if (format[i] == 's') 
	{
	char *str = va_arg(args, char *);
	if (str == NULL) 
	{
	str = "(null)";
	}
	while (*str) 
	{
	putchar(*str++);
	countB++;
	}
	} else if (format[i] == '%') 
	{
	putchar('%');
	countB++;
	    } else 
	    {
	putchar('%');
	putchar(format[i]);
	countB += 2;
	}
        } else 
	{
	putchar(format[i]);
	countB++;
	}
	}

	va_end(args);
	return countB;
}

int main() 
{
	int len;
    len = _printf("Hello %s, you have %s new messages\n", "Alice", "5");
	printf("Length: %d\n", len);
    return 0;
}

