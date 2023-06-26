#include "main.h"

/**
 * itoa - integer to ASCII
 * @n: ...
 * @base: ...
 * Return: char
 */
char *itoa(long int n, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (n < 0)
	{
		m = -n;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = array[n % base];
		n /= base;
	}
	while (n != 0);

	if (sign)
		*--ptr = sign;
	return(ptr);
}
		
