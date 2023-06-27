#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
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
		}
	}
	va_end(args);
	return count;
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
