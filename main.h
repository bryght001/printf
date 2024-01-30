#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int print_str(char *str);
int _printf(const char *format, ...);
int print_char(int c);
int print_digit(long n, int base);
int print_format(char specifier, va_list ap);

#endif
