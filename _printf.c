#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int count = 0;
	char c;
	va_list args;
	va_start(args, format);

	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			c = *format++;
			switch (c)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += fputs(va_arg(args, const char*), stdout);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(c);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(c);
			count++;
=======
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
>>>>>>> refs/remotes/origin/main
		}
		i++;
	}
<<<<<<< HEAD
	va_end(args);
	return count;
=======
	va_end(lad);

	return (lgth);
>>>>>>> refs/remotes/origin/main
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

