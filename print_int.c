#include "main.h"

/**
 * printf_int - prints a number in base 10
 * @list: nos to print base 10
 * Return: Length nos in decimals
 */

int print_integer(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, int), 10);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}
