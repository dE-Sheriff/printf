#include "main.h"

/**
 * _chckarg - checks the specifiers and do as neccessary 
 * format: the specifier
 * char_len: character printed
 * arg_list: the variadiac fun
 */

void _chckarg(const char *format, int char_len, va_list arg_list)
{
	int ch, s_len, int_d;
	char *str;

	if (*format == '%')
	{
		write(1, format, 1);
		char_len++;
	}
	else if (*format == 'c')
	{
		ch = va_arg(arg_list, int);
		write(1, &ch, 1);
		char_len++;
	}
	else if (*format == 's')
	{
		str = va_arg(arg_list, char *);
		s_len = _strlen(str);
		write(1, str, s_len);
		char_len += s_len;
	}
	else if ((*format == 'd') || (*format ==  'i'))
	{
	       	int_d = va_arg(arg_list, int);
		printf("%d", int_d);
		write(1, &int_d, 1);
		char_len += 4;
	}
}