#include <stdio.h>

int _printf(const char *format, ...);
/**
 * main - entry
 * Return: Always 0
 */
int main(void)
{
       	_printf("Hello, %s!\n", "World");
	return 0;
}

