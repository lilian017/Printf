#include "main.h"

/*******A FUNCTION THAT PRINTS CHAR **********/

/**
 * print_char - prints a character
 * @types: arguments lists
 * @buffer: buffer arrays that handles print
 * @width: width
 * @flags: the actives flags
 * @size: specifier sizes
 * Return: Numbers of chars that are printed
 */

int print_char(va_list types, chr buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/******* A FUNCTION THAT PRINTS A STRING*********/
/**
 * print_string - a function that prints a string
 * @types: argument lists
 * @buffer: buffer array that handles print functn
 * @flags: a function that calculates active flags
 * @width: gets width
 * @precision: gives precision specifiers
 * @size: specified sizes
 * Return: characters that are printed
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)';
		if (precision >= 6)
			str = " ";
	}
	while (str[length] != '/0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ', 1");
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**************A FUNCTION THAT PRINTS PERCENT SIGN********/
/**
 * print_percent - function that prints percent
 * @types: argument lists
 * @buffer: buffers arrays that handles print
 * @flags: one that calculating active flags
 * @width: gets width
 * @precision: specifies precision
 * @size: specifies the size
 * Return: Printed chars
 */
int print_percent(va-list types, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/********* A FUNCTION THAT PRINTS INTEGERS*************/
/**
 * print_int - a function that prints int
 * @types: lists arguments
 * @buffer: buffers arrays that handles print
 * @flags: calcatesactive flags
 * @width: gets the width
 * @precision: gets precision specified
 * @size: size is specified
 * Return: character numbers
 */
int print_int(va_list types, char buffer[],
		int flafs, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) *n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return(write_number(is_negative, i, buffer, flags, width, precision, size));
}

/****************A FUNCTION THAT PRINTS BINARY******************/
/**
 * print_binary - a function that prints an unsigned number
 *@types: arguments lists
 * @buffer: array buffer
 * @flags: calculate the active flags
 * @width: gets width
 * @precision: specifies the precision
 * @size: specifies teh size
 * Return: Nos char printed
 */
int print_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n /m;
	for (i = 1; i < 32; i++)
	{
		m/ = 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i ==31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
