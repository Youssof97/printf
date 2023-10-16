#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int print_char(va_list arg);
int print_int(va_list arg);
int print_string(va_list arg);
int print_number(int n);
int print_binary(int n);
int print_b(va_list args);
int print_unsigned(va_list args);
int print_oct(va_list args);
int print_S(va_list args);
int print_hex(unsigned int n, char c);
int print_hex_c(va_list args);
int print_hex_s(va_list args);
int (*get_print(char c)) (va_list arg);
int _printf(const char *format, ...);
/**
 * struct print - New typedef struct
 * @format: data type
 * @func: a pointer to a function
 */
typedef struct print
{
	char format;
	int (*func)(va_list arg);
} func_print;
#endif
