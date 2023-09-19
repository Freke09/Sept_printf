#include "main.h"

/**
 *int_handler - handles the d and i integer specifier
 *@num: specifier
 *
 *Return: the number of printed char
 *
 */

int int_handler(int num)
{
int j = 0, k = 0, start, i = 0;
char buffer[20];

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
k++;
}
return (k++);
}
