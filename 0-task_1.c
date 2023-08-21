#include "main.h"
/**
  *_printf - print whatever it takes as argument
  *Return: int
  *@format: argument
  */
int _printf(const char *format, ...)
{
	va_list ptr;
	int count = 0, i;
	char c;
	char *str;

	if (format == 0)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		_putchar('\n');
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
					for (i = 0; str[i] != '\0'; i++)
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
			format++;
		}
	}
	va_end(ptr);
	return (count);
}