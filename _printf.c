#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	va_list lad;
	int i = 0, lgth = 0;

	va_start(lad, format);
	if(!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			lgth += _putchar(format[i]);
		else
		{
			i++;
			if (!format[i])
				return (-1);
			lgth += _spec_handler(lad, format[i]);
		}
		i++;
	}
	va_end(lad);

	return (lgth);
}

/**
 * _spec_handler - the funct that handles the specifier passed to _print
 * @lad: list of arguments
 * @spec: specifier after %
 * Return: argument length
 */
int _spec_handler(va_list lad, char spec)
{
	int lgth = 0;

	if (spec == 'c')
		lgth += _putchar(va_arg(lad, int));
	else if (spec == 's')
		lgth +=_putstr(va_arg(lad, char *));
	else if (spec == 'd' || spec == 'i')
		lgth += _putint(va_arg(lad, int));
	else if (spec == 'b')
		lgth += _putbit(va_arg(lad, unsigned int));
	else if (spec == '%')
		lgth += _putchar('%');
	else if (spec == 'u')
		lgth += _putuint(va_arg(lad, unsigned int));
	else if (spec == 'o')
		lgth += _putoct(va_arg(lad, unsigned int));
	else
		lgth += _printf("%%%c", spec);
	return (lgth);
}

