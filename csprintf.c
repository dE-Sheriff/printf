#include "main.h"

/**
 * print_str - prints string when format == 's'
 * @a_list: vaariadiac list
 * Return: char_len
 */

int print_str(va_list a_list)
{
	char *str;
	int s_len;

	str = va_arg(a_list, char *);
	if (str == (char *)'0')
	str = (char *)"(null)";
	s_len = _strlen(str);
	write(1, str, s_len);
	return (s_len);
}

/**
 * print_char - prints char when format == 'c'
 * @a_list: vaariadiac list
 * Return: (1)
 */

int print_char(va_list a_list)
{
	int ch;

	ch = va_arg(a_list, int);
	write(1, &ch, 1);
	return (1);
}

/**
 * _printf - a function that produces output according to a format
 *@format: a character string, composed of zero or more directives
 *Return: sting
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int char_len = 0, s_len = 0;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	if (*format)
	{
		while (*format != '\0')
		{
			if (*format != '%')
			{
				write(1, format, 1);
				char_len++;
			}
			else
			{
				format++;
				if (*format == '%')
				{
					write(1, format, 1);
					char_len++;
				}
				else if (*format == 'c')
					char_len += print_char(arg_list);
				else if (*format == 's')
				{
					s_len = print_str(arg_list);
					char_len += s_len;
				}
				else
				{
					format--;
					write(1, format, 1);
					char_len++;
				}
			}
			format++;
		}
	}
	va_end(arg_list);
	return (char_len);
}
