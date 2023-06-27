#include "main.h"
#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list lad;

	if (format == NULL)
		return (-1);

	va_start(lad, format);

	while (*format != '\0')
	{
		buffer[buff_ind++] = *format;
		if (buff_ind == BUFF_SIZE - 1)
		{
			write(1, buffer, buff_ind);
			buff_ind = 0;
		}
		buffer[buff_ind++] = *format;
		format++;
	}
	buffer[buff_ind] = '\0';
	write(1, buffer, buff_ind);
	va_end(lad);
	return (0);
}
