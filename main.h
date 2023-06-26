#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>


#define UNUSED(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_zero 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct _format -struct function
 * @type: format
 * @f: functions associated
 */
typedef struct _ format
{
	char type;
	int (*f)(va_list, char[], int, int, int, int);
}format;


int _putchar(char c);
int buffer (char);
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,va_list list, char buffer[], int flags, int width, int precision, int size);
int printf_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list tyoesm char buffer[], int flags, int width, int precision, int size);
int printf_unsigned(va_list list);


long int convert_size_number(long int n, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int _strlen(const char *);
int print(char *);
char *itoa(long int, int);


#endif
