#include "main.h"
#include <stdarg.h>
#include <stdio.h>
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int i = 0, printed = 0, printed_ch = 0;
	int f, w, p, s, buff_ind = 0;
	va_list lad;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lad, format);

	while ((format && format[i]) != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				/* write(1, &format[i], 1); */
				printed_ch++;
			}
			else
			{
				print_buffer(buffer, &buff_ind);
				f = get_flags(format, &i);
				w = get_width(format, &i, list);
				p = get_precision(format, &i, list);
				s = get_size(format, &i);
				++i;
				printed = handle_print(format, &i, list, buffer, f, w, p, s);
				if (printed == -1)
					return (-1);
				printed_ch += printed;
			}
		}
		i++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(lad);
	return (printed_ch);
}
/**
 * print_buffer -prints contents of buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index to add next char, rep length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
