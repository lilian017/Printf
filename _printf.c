#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int i = 0;
	char d;
	va_list lad;
	va_start(lad, format);

	while ((d == *format++) != '\0')
	{
		if (d == '%')
		{
			d = *format++;
			switch (d)
			{
				case 'c':
					putchar(va_arg(lad, int));
					i++;
					break;
				case 's':
					i += fputs(va_arg(lad, const char), stdout);
					break;
				case '%':
					putchar("%");
					i++;
					break;
				default:
					putchar('%');
					putchar(d);
					i += 2;
					break;
			}
		}
		else
		{
			putchar(c);
			i++;
		}
	}
	va_end(lad);
	return (i);
}
