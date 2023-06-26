#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_int - funtion that prints integers
 * @types: ...
 * @buffer: ...
 * @flags: ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * Return: printed characters
 */

int printf_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);


	int i = BUFF_size - 2;
	int is_negative = 0;
	long int lad = va_arg(types, long int);
	unsigned long int n;

	lad = convert_size_number(lad, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	n = (unsigned long int)lad;

	if (n < 0)
	{
		n = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while(n > 0)
	{
		buffer[i--] = (n % 10)+ '0';
		n /= 10;
	}
	i++;
	return(write_number(is_negative, i, buffer, flags, width, precision, size));
}

