#include "main.h"

/**
* _printf - a function that produces output according to format
* @format: character string
*	c: char
*	s: string
*	%: special character
* Return: the total number of characters printed
*/

int print_char(int k);
int print_str(char *str);

int _printf(const char *format, ...)
{
	int items = 0;
	va_list elements;

	if (format == NULL) /* This handles the null string and prints nothing */
	{
		return (0);
	}

	va_start(elements, format);
	while (*format) /* Loop through the format string characters each */
	{
		if (*format != '%')
		{
			write(1, format, 1); /* Print the character item count */
			items++;
		}
		else
		{
			format++; /* Move to the next character */
			if (*format == '\0') /* if the format string ends with % stop */
				break;
			if (*format == '%') /* this handles %% */
			{
				write(1, format, 1); /* Prints the second % */

				items++;
			}
			else if (*format == 'c') /* if format is %c print a character */
			{
				items += print_char(va_arg(elements, int));
			}
			else if (*format == 's') /* if it is %s print a string */
			{
				items += print_str(va_arg(elements, char *));
			}
		}
		format++;
	}
	va_end(elements);
	return (items);
}

/**
* print_char - a function to print a character
* @k: the character to be printed
* Return: The number of characters printed)
*/

int print_char (int k)
{
	write(1, &k, 1);
	return (1);
}

/**
* print_str - a function to print a string
* @str: the string to be printed
* Return: the length of the string
*/

int print_str(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	write(1, str, length);

	return (length);
}
