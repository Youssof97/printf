#include "main.h"

/**
 * print_str - prints a string
 * @args: va_list arguments
 * Return: number of string length
 */

int print_str(va_list args)
{
	int strLen = 0,
	    i;
	char *s;

	s = va_arg(args, char *);
	while (s[strLen] != '\0')
		strLen++;

	for (i = 0; i < strLen; i++)
	{
		if (s[i] >= 0 && (s[i] < 32 || s[i] >= 127))
		{
			_putchar('\\');
			_putchar('x');
			/*_putchar(strtol(s[i], NULL, 16));*/
		}
		else
			_putchar(s[i]);
	}
	return (strLen);
}
