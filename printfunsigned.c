#include "main.h"
#include <stdarg.h>
#include <stdio.h>


/**
 *printf_unsigned- a function that prints an integer
 *args: argument printed
 *Return: characters printed
*/

int printf_unsigned(va_list args)
{
	unsigned int lad = va_arg(args, unsigned int);
	int n, lst, dgt, xp, i;
	lst = n % 10;
	xp = 1;
	i = 1;

	lad = lad / 10;
	n = lad;

	if (lst < 0)
	{
		_putchar('-');
		n = -n;
		lad = -lad;
		lst = - lst;
		i++;
	}
	if (n > 0)
	{
		while (n / 10 !=0)
		{
			xp = xp * 10;
			n = n /10
		}
		n = lad;
		while (xp > 0)
		{
			dgt = n / xp;
			_putchar(dgt + '0');
			n = n - (dgt * xp);
			xp = xp / 10;
			i++;
		}
	}
	_putchar(lst + '0');
	return (i);
}
