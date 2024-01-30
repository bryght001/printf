#include "main.h"

/**
 * print_char - function display char
 * @c: input to displsy
 *
 * Return: char to screen
 */
int print_char(int c)
{

	return (write(1, &c, 1));
}

/**
 * print_str - Prints a string character by character
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_str(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		print_char(*str);
		count++;
		str++;
	}

	return (count);
}

/**
 * print_format - Prints a formatted string based on the specifier
 * @specifier: The format specifier
 * @ap: The va_list containing the arguments
 *
 * Return: The number of characters printed
 */
int print_format(char specifier, va_list ap)
{
	int count = 0;

	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || 'i')
		count += print_digit(va_arg(ap, int), 10);

	return (count);
}

/**
 * print_digit - print digit of number
 *
 * @n: the input number
 * @base: is 10 to get single digit form the number
 *
 * Return: every digit
 */
int print_digit(long n, int base)
{
	int count;
	char *symbols;

	symbols = "0123456789abcdef";

	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}
