#include "main.h"

int cs_handler(char format, va_list elements, int items);

/**
* _printf - a function that produces output according to format
* @format: character string
*	c: char
*	s: string
*	%: special character
* Return: the total number of characters printed
*/


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
			cs_handler(*format, elements, items);
		}
		format++;
	}
	va_end(elements);
	return (items);
}

/**
 *cs_handler - handles c and s
 *@format: specifier
 *@elements: variable argument
 *@items: number of character printed
 *
 */

int cs_handler(char format, va_list elements, int items)
{
if (format == 'c')
{
char c = va_arg(elements, int);
write(1, &c, 1);
items++;
}
else if (format == 's')
{
char *str = va_arg(elements, char*);
while (*str)
{
write(1, str, 1);
str++;
items++;
}
}
else if (format  == '%')
{
write(1, &format, 1);
items++;
}
return (items);
}
