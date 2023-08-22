#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int count = 0, i;
	char c;
	char *str;
	
	if (format == NULL)
	{
		char *null_str = "(null)\n";
		for (count = 0; null_str[count] != '\0'; count++)
		{
			putchar(null_str[count]);
		}
		return (count);
	}
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
				{
					str = "(null)";
				}
				for (i = 0; *str != '\0'; str++)
				{
					putchar(str[i]);
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
