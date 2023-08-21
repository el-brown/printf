#include "main.h"
/**
  *_printf - function that produces output according to a format
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
        char *null = "(null)\n";
        for (i = 0; null[i] != '\0'; i++)
        {
            putchar(null[i]);
            count++;
        }
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
