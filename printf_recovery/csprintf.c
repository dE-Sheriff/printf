#include "main.h"

/**
 * _printf - a function that produces output according to a format
 *@format: a character string, composed of zero or more directives
 *Return: sting
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int char_len = 0, ch, s_len;
	char *str;

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
			}
			format++;
		}
	}
	va_end(arg_list);
	return (char_len);
}
