#include "main.h"
#include <stdio.h>

/**
 * _printf - prints a formmated string like original printf
 * @format: the formmated string to be printed
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int r = 0;
	int (*print)(va_list);

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				r = -1;
				break;
			}
			print = get_print(format[++i]);
			if (print == NULL)
			{
				_putchar('%');
				if (format[i] != '%')
				{
					_putchar(format[i]);
					r++;
				}
			}
			else
				r += print(args) - 1;
		}
		else
			_putchar(format[i]);

		i++;
		r++;
	}
	va_end(args);
	return (r);
}
