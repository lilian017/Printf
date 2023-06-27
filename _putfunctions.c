#include "main.h"
#include <unistd.h>

/**
 * _putchar - function that writes char c
 * @c: character printed
 * Return: On success 1 or -1 for errors
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/*********FUNCTION THAT PRINTS A STRING*********/
/**
 * _putstr - a function that prints a string to std output
 * @str: - string that gets printed
 * Return: stringlength -1
 */
int _putstr(char *str)
{
	int i = 0;

	if (!str)
		i = _putstr("(null");
	else
	{
		while (str[i])
		{
			_putchar(str[i]);
			i++;
		}
	}
	return (i);
}
/********** A FUNCTION THAT PRINTS AN INTEGER**********/
/**
 * _putint - prints integers in stdout
 * @n: number that is printed
 * Return: lgth of characters printed -1
 */
int _putint(int n)
{
	int lad, lgth = 0;

	if (!n)
	{
		lgth += _putchar('0');
		return (lgth);
	}
	if (n == _INT_MIN)
	{
		lgth += _putstr("-2147483648");
		return (lgth);
	}
	if (n < 0)
	{
		lgth += _putchar('-');
		n = -n;
	}

	lad = n % 10;
	n = n / 10;
	if (n)
		lgth += _putint(n);
	lgth += _putchar(lad + '0');

	return (lgth);
}
/**********A FUNCTION THAT PRINTS A BINARY FUNCTION*******/
/**
 * _putbit - a function that prints a binary value
 * @n: unsigned number that is printed
 * Return: length of string -1
 */
int _putbit(unsigned int n)
{
	int lgth = 0;
	unsigned int lad;

	if (!n)
	{
		lgth += _putchar('0');
		return (lgth);
	}
	lad = n % 2;
	n = n / 2;
	if (n)
		lgth += _putbit(n);
	lgth += _putchar(lad + '0');

	return (lgth);
}
