#include "main.h"

/**
 * print_lowerHex - Simultaneous convert and print integer in hexadecimal.
 *
 * @num: The number to print in hexadecimal
 * @count: Pointer to counter of the number of bytes printed
 *
 * Return: void
 */

void print_lowerHex(unsigned int num, int *count)
{
	int retVal;

	if (num > 15)
		print_lowerHex(num >> 4, count);

	if (*count == -1)
		return;

	if ((num & 15) < 10)
		retVal = _putchar('0' + (num & 15));

	else
		retVal = _putchar('a' + (num & 15) % 10);

	if (retVal == -1)
		*count = -1;
	else
		*count += retVal;
}

/**
 * print_x - Prints hexadecimal.
 *
 * @args: The number of arguments.
 *
 * Return: The specifier that is denoted by x.
 */
int print_x(va_list args)
{
	int count;

	print_lowerHex(va_arg(args, int), &count);

	return (count);
}

/**
 * print_upperHex - Simultaneous convert and print integer in hexadecimal.
 *
 * @num: The number to print in hexadecimal.
 * @count: Pointer to counter of the number of bytes printed.
 *
 * Return: void
 */

void print_upperHex(unsigned int num, int *count)
{
	int retVal;

	if (num > 15)
		print_upperHex(num >> 4, count);

	if (*count == -1)
		return;

	if ((num & 15) < 10)
		retVal = _putchar('0' + (num & 15));

	else
		retVal = _putchar('A' + (num & 15) % 10);

	if (retVal == -1)
		*count = -1;
	else
		*count += retVal;
}

/**
 * print_X - Prints an integer in lowercase hexadecimal.
 *
 * @args: The number of arguments.
 *
 * Return: The specifier that is denoted by X.
 */
int print_X(va_list args)
{
	int count = 0;

	print_upperHex(va_arg(args, int), &count);

	return (count);
}
