#include "main.h"

/**
 * print_number - prints any integer using onley _putchar function
 * @n: the integer to be printed
 * Return: the number of digits and - sign printed on screen
 */

int print_number(int n)
{
	unsigned int i;
	int j = 0;

	if (n < 0)
	{
		_putchar('-');
		i = -n;
		j++;
	}
	else
	{
		i = n;
	}

	if (i < 10)
	{
		_putchar(i + '0');
	}
	else
	{
		j += print_number(i / 10);
		_putchar(i % 10 + '0');
	}

	return (j + 1);
}
