#include "main.h"

/**
 * _printf - print formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int count = 0, i;
	char c;
	char *str;

	if (format == 0)
	{
		putchar('(');
		putchar('n');
		putchar('u');
		putchar('l');
		putchar('l');
		putchar(')');
		putchar('\n');
		count += 7;
	}
	else
	{
	va_start(ptr, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(ptr, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(ptr, char *);
				if (str == NULL)
					str = "(null)";
				for (; *str != '\0'; str++)
				{
					putchar(*str);
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(ptr);
	return (count);
}
