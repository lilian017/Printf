#include "main.h"
/**
 * _putuint - function that prints unsigned decimal
 * @n: printed number
 * Return: length of printed strength -1
 */
int _putuint(unsigned int n)
{
	int lgth = 0;
	unsigned int lad;

	if (!n)
	{
		lgth += _putchar('0');
		return (lgth);
	}
	lad = n % 10;
	n = n / 10;
	if (n)
		lgth += _putint(n);
	lgth += _putchar(lad + '0');

	return (lgth);
}
/**
 * _putoct - a function that prints octal stout
 * @n: printed numbers
 * Return: length of printed string -1
 */
int _putoct(unsigned int n)
{
	int lgth = 0;
	unsigned int lad;

	if (n < 8)
	{
		lgth += _putint(n);
		return (lgth);
	}
	lad = n % 8;
	n = n / 8;
	if (n)
		lgth += _putoct(n);
	lgth += _putchar(lad + '0');

	return (lgth);
}
/**
 * _puthex - function that prints hexadecimal std output
 * @n: printed numbers
 * @alpha: characters in a hexadecimal value
 * Return: length of the printed string
 */

int _puthex(unsigned  int n, char alpha)
{
	int lgth = 0;
	unsigned int lad;

	if (n < 10)
		return (_putchar(n + '0'));
	if (n < 16)
	{
		if (alpha == 'x')
			return (_putchar(n + 87));
		return (_putchar(n + 55));
	}
	lad = n % 16;
	n = n / 16;
	if (n)
		lgth += _puthex(n, alpha);
	lgth += _puthex(lad, alpha);

	return (lgth);
}
