#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>

#define _INT_MIN (1 << (sizeof(int) * 8 -1))

int _putchar(char c);
int _printf(const char *format, ...);
int _putint(int n);
int _putstr(char *str);
int _putbit(unsigned int n);
int _putuint(unsigned int n);
int _putoct(unsigned int n);
int _spec_handler(va_list lad, char spec);

#endif
