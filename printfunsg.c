#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * printf_unsigned - prints an unsigned integer
 * @args: prints an argument
 * Return: no of characters printed
 */
int printf_unsigned(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(lst, unsigned int), 10);

	size = printf((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}
