#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>

#define _INT_MIN (1 << (sizeof(int) * 8 - 1))

int _putchar(char c);
int _printf(const char *format, ...);
int _putint(int n);
int _putstr(char *str);
int _putbit(unsigned int n);
int _putuint(unsigned int n);
int _putoct(unsigned int n);
int _puthex(unsigned int n, int uppercase);
int _putbin(unsigned int n);
int _putstr_special(char *str);
int _putptr(void *ptr);
int _putstr_rev(char *str);
int _putstr_rot13(char *str);

#endif /* MAIN_H */
