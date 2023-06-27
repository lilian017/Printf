#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);
int _putstr(char *str);
int _putint(int n);
int _putbit(unsigned int n);
int _putuint(unsigned int n);
int _putoct(unsigned int n);
int _printf(const char *format, ...);
int _spec_handler(va_list lad, char spec);

/**
 * _printf - a function that prints on stdout
 * @format: printed string
 * Return: string lgth
 */

int _printf(const char *format, ...)
{
	va_list lad;
	int i = 0, lgth = 0;

	va_start(lad, format);
	if (!format)
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
 * _spec_handler - funct that handles specifier
 * @lad: argument lists
 * @spec: specifier
 * Return: argument length
 */
int _spec_handler (va_list lad, char spec)
{
	int lgth = 0;

	if (spec == 'c')
		lgth += _putchar(va_arg(lad, int));
	else if (spec == 's')
		lgth += _putstr(va_arg(lad, char *));
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
	else if (spec == 'x' || spec == 'X')
		lgth += _puthex(va_arg(lad, int), spec);

	else
		lgth += _printf("%%%c", spec);
	return (lgth);
}
