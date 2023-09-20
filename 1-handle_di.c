#include "main.h"

/**
 *int_handler - handles the d and i integer specifier
 *@specifier: specifier
 *@data: the variable argument list
 *@printed: the number of printed char
 *
 */

void int_handler(char specifier, va_list data, int *printed)
{
	int num, j = 0, start, i = 0;
	char buffer[20];

	if (specifier == 'd' || specifier == 'i')
	{
	num = va_arg(data, int);
	if (num < 0)
	{
		buffer[i] = '-';
		write(1, &buffer[j], 1);
		num = -num;
		i++;
	}
	do {
		buffer[i] = num % 10 + '0';
		num /= 10;
		i++;
	} while (num > 0);

	start = (buffer[0] == '-') ? 1 : 0;

	for (j = i - 1; j >= start; j--)
	{
		write(1, &buffer[j], 1);
		(*printed)++;
	}
	}
	buffer[i] = '\0';
}
