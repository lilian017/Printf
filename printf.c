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
int _spec_handler(va_list lad, char spec, int width, char length)
{
	int lgth = 0;

	if (spec == 'c')
		lgth += _putchar(va_arg(lad, int));
	else if (spec == 's')
	{
		char *str = va_arg(lad, char *);
		if (width == -1)
			lgth += _putstr(str);
		else
			lgth += _putstr_width(str, width);
	}
	else if (spec == 'd' || spec == 'i')
	{
		if (length == 'l')
			lgth += _putint(va_arg(lad, long int));
		else if (length == 'h')
			lgth += _putint(va_arg(lad, int));
		else
			lgth += _putint(va_arg(lad, int));
	}
	else if (spec == 'u')
	{
		if (length == 'l')
			lgth += _putuint(va_arg(lad, unsigned long int));
		else if (length == 'h')
			lgth += _putuint(va_arg(lad, unsigned int));
		else
			lgth += _putuint(va_arg(lad, unsigned int));
	}
	else if (spec == 'o')
	{
		if (length == 'l')
			lgth += _putoct(va_arg(lad, unsigned long int));
		else if (length == 'h')
			lgth += _putoct(va_arg(lad, unsigned int));
		else
			lgth += _putoct(va_arg(lad, unsigned int));
	}
	else if (spec == 'x')
	{
		if (length == 'l')
			lgth += _puthex(va_arg(lad, unsigned long int), 0);
		else if (length == 'h')
			lgth += _puthex(va_arg(lad, unsigned int), 0);
		else
			lgth += _puthex(va_arg(lad, unsigned int), 0);
	}
	else if (spec == 'X')
	{
		if (length == 'l')
			lgth += _puthex(va_arg(lad, unsigned long int), 1);
		else if (length == 'h')
			lgth += _puthex(va_arg(lad, unsigned int), 1);
		else
			lgth += _puthex(va_arg(lad, unsigned int), 1);
	}
	else
		lgth += _printf("%%%c", spec);

	return (lgth);
}
/**
 * _putstr_width - print a string with a given field width
 * @str: input string
 * @width: field width
 * Return: number of characters printed
 */
int _putstr_width(char *str, int width)
{
	int lgth = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		lgth += _putchar(*str);
		str++;
		width--;
	}

	while (width > 0)
	{
		lgth += _putchar(' ');
		width--;
	}

	return (lgth);
}
