#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * main - checks printfint
 * Return: 0
 */

int main()
{
	int number = 2345;
	int printed_chars = printf_int(number);
	printf("%d\n", printed_chars);

	return 0;
}
