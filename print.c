#include "main.h"
/**
 * _printf - similar to printf
 * @format: constant format
 * Return: len of format
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += print_format(*(++format), ap);
		}
		else
		{
			count += write(1, format, 1);
		}
		++format;
	}
	va_end(ap);
	return (count);
}
