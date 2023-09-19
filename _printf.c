#include "main.h"

void cs_handler(char specifier, va_list data, int *printed);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int printed = 0;
	va_list data;

	if (format == NULL)
	{
		return (0);

	va_start(data, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			cs_handler(*format, data, &printed);
			int_handler(*format, data, &printed);
			binary_handler(*format, data, &printed);
		}
		else
		{
			write(1, format, 1);
			printed++;
		}
		format++;
	}

	va_end(data);
	return (printed);
}

/**
 *cs_handler - handles c and s
 *@specifier: specifier
 *@data: variable argument
 *@printed: number of character printed
 *
 */

void cs_handler(char specifier, va_list data, int *printed)
{
	if (specifier == 'c')
	{
		char c = va_arg(data, int);

		write(1, &c, 1);
		printed++;
	}
	else if (specifier == 's')
	{
		char *str = va_arg(data, char*);

		while (*str)
		{
			write(1, str, 1);
			str++;
			printed++;
		}
	}

	else if (specifier == '%')
	{
		write(1, "%", 1);
		printed++;
	}
}

