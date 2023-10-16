#include "main.h"

/**
 * print_unsigned - prints unsigned integer
 * @args: va_list of arguments
 * Return: Number of counted printed
 */

int print_unsigned(va_list args)
{
	unsigned int n;
	int length = 0,
	    i = 1;

	n = va_arg(args, unsigned int);

	for (; n / i > 9;)
		i = i * 10;

	for (; i > 0; i = i / 10)
	{
		length += _putchar('0' + (n / i));
		n = n % i;
	}
	return (length);
}

/**
 * print_oct - prints integer in its octal base
 * @args: va_list of arguments
 * Return: Number of octals
 */

int print_oct(va_list args)
{
	unsigned int n = va_arg(args, unsigned int),
		     temp;
	char *oct;
	int i, j = 0,
	    printedC = 0;
	if (n == 0)
		return (_putchar('0'));
	for (temp = n; temp != 0; j++)
		temp = temp / 8; /* convert it into oct */
	oct = malloc(j);

	for (i = j - 1; i >= 0; i--)
	{
		oct[i] = n % 8 + '0';
		n = n / 8;
	}

	for (i = 0; i < j && oct[i] == '0'; i++)
		continue;
	for (; i < j; i++)
	{
		_putchar(oct[i]);
		printedC++;
	}
	free(oct);
	return (printedC);
}

/**
 * print_hex - prints a hex number from a decimal
 * @intg: the decimal number to be printed as hex
 * @c: the case of the printed hex
 * Return: number of chars printed on the screen
 */
int print_hex(unsigned int intg, char c)
{
	char hex[100];
	int i = 0,
		printedC = 0,
		j = 0, k;

	if (intg == 0)
	{
		_putchar('0');
		return (1);
	}

	while (intg != 0)
	{
		j = intg % 16;
		if (j < 10)
			hex[i] = j + 48;
		else
		{
			if (c == 'c')
				hex[i] = j + 55;
			else
				hex[i] = j + 87;
		}
		i++;
		intg = intg / 16;
	}
	hex[i] = '\0';

	for (k = i - 1; k >= 0; k--)
	{
		_putchar(hex[k]);
		printedC++;
	}

	return (printedC++);
}

/**
 * print_hex_c - prints the hex in capital letters
 * @args: va_list of arguments
 * Return: Number of hexas
 */
int print_hex_c(va_list args)
{
	unsigned int intg = va_arg(args, unsigned int);

	return (print_hex(intg, 'c'));
}

/**
 * print_hex_s - prints the hex in capital letters
 * @args: va_list of arguments
 * Return: Number of hexas
 */
int print_hex_s(va_list args)
{
	unsigned int intg = va_arg(args, unsigned int);

	return (print_hex(intg, 's'));
}
