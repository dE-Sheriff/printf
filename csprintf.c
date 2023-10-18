#include "main.h"

/**
 * _printf - a function that produces output according to a format
 *@format: a character string, composed of zero or more directives
 *Return: sting
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int char_len = 0;

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
				_chckarg(&*format, char_len, arg_list);
			}
			format++;
		}
	}
	va_end(arg_list);
	return (char_len);
}
