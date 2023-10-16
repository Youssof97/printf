#include "main.h"
#include <stdarg.h>

/**
 * print_char - print char
 * @arg: arguments
 * Return: Nothing
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	_putchar(c);

	return (1);
}

/**
 * print_int - print an integer
 * @arg: arguments
 * Return: Nothing
 */
int print_int(va_list arg)
{
	int i = va_arg(arg, int);

	return (print_number(i));
}

/**
 * print_string - prints a ctring
 * @arg: arguments
 * Return: Nothing
 */
int print_string(va_list arg)
{
	char *s = va_arg(arg, char *);
	int i;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}

	return (i);
}


/**
 * print_S - prints a string with non printable chars
 * printed in a specific way
 * @arg: variadic list of arguments
 * Return: number of chars printed on screen
 */
int print_S(va_list arg)
{
	char *s = va_arg(arg, char *);
	int i;
	int c;
	int count = 0;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		c = s[i];
		if ((c >= 0 && c < 32) || c >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (c <= 16)
				_putchar('0');
			print_hex((unsigned int) c, 'c');
			count += 3;
		}
		else
			_putchar(s[i]);
		count++;
	}

	return (count);
}
