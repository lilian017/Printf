#include "main.h"
#include <stdarg.h>
#include <limits.h>

/**
 * print_percent - a function that prints % sign
 * @types: arguments
 * @buffer: array that handles print
 * @flags: active flags
 * @width: gets width
 * @precision: specifies precision
 * @size: specifies size
 * Return: chars printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
