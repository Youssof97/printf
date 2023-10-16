#include "main.h"

/**
 * print_binary - prints the binary representation of integer
 * @n: the intger to be printed as binary
 * Return: the length of the binary number
 */
int print_binary(int n)
{
	int count = 0;
	int power = 1;
	int remain;
	int i;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (1)
	{
		if (power > n)
		{
			count--;
			power /= 2;
			break;
		}
		else if (power == n)
			break;
		power *= 2;
		count++;
	}
	_putchar('1');
	remain = n - power;
	n -= remain;
	for (i = 0; i < count; i++)
	{
		n /= 2;
		if (remain >= n)
		{
			_putchar('1');
			remain -= n;
		}
		else
			_putchar('0');
	}

	return (i + 1);
}

/**
 * print_b - takes a variadic list and
 * print binary of an integer argument
 * @args: the variadic list
 * Return: the length of the binary number
 */
int print_b(va_list args)
{
	int n = va_arg(args, int);

	return (print_binary(n));
}
