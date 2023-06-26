#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>


#define UNUSED(x)
#define BUFF_SIZE 1024

/**
 * struct _format -struct op
 * @type: format
 * @f: functions associated
 */
typedef struct _ format
{
	char type;
	int (*f)(va_list);
}format;


int _putchar(char c);
int buffer (char);
int _printf(const char *format, ...);
int printf_int(va_list);
int printf_unsigned(va_list list);
long int convert_size_number(long int n, int size);

int _strlen(const char *);
int print(char *);
char *itoa(long int, int);


#endif
