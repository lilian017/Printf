# include "main.h"
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
