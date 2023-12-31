#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _strlen(char *s);
int _putchar(char c);
void _chckarg(const char *format, int char_len, va_list arg_list);
int print_int(va_list a_list);

#endif /* MAIN_H */
