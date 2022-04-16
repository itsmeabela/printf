#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int (*get_func(char x))(va_list);
int _printf(const char *format, ...);
/**
 * _printf - Produces output according to a format.
 *
 * @format: A character String.
 *
 * Return: The number of characters printed(excluding the
 *          null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	if (format != NULL)
	{
		int count = 0, index = 0;
		int (*variadic)(va_list);
		va_list args;

		va_start(args, format);
		if (format[0] == '%' && format[1] == '\0')
			return (-1);

		while (format != NULL && format[index] != '\0')
		{
			if (format[index] == '%')
			{
				if (format[index + 1] == '%')
				{
					count += _putchar(format[index]);
					index += 2;
				}
				else
				{
					variadic = get_func(format[index + 1]);

					if (variadic)
						count += variadic(args);
					else
						count = _putchar(format[index] + _putchar(format[index + 1]));
					index += 2;
				}
			}
			else
			{
				count += _putchar(format[index]);
				index++;
			}
		}
		va_end(args);
		return (count);
	}
	return (-1);
}

/**
 * get_func - Look for the specifier.
 *
 * @x: Variable to the function.
 *
 * Return: value of the function.
 */
int (*get_func(char x))(va_list)
{
	int index = 0;

	spec array[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_percent},
		{"d", print_d},
		{"i", print_i},
		{NULL, NULL}
	};

	while (array[index].valid)
	{
		if (x == array[index].valid[0])
			return (array[index].f);

		index++;
	}

	return (NULL);
}
