#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
/**
 * struct specifier - struct specifier.
 *
 * @valid: The valid character.
 * @f: The functions associated.
 */

typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;

int _putchar(char c);
int (*get_func(char x))(va_list args);
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int print_percent(va_list args);
int print_b(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_x(va_list args);
int print_X(va_list args);

#endif
