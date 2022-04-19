#include "main.h"
#include <stdlib.h>

/**
 * print_x - Prints hexadecimal.
 *
 * @args: The number of arguments.
 *
 * Return: The specifier that is denoted by x.
 */
int print_x(va_list args)
{
	int count = 0, index, *arr;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (index = 0; index < count; index++)
	{
		arr[index] = temp % 16;
		temp /= 16;
	}

	for (index = count - 1; index >= 0; index--)
	{
		if (arr[index] > 9)
			arr[index] = arr[index] + 7;
		_putchar(arr[index] + '0');
	}

	free(arr);

	return (count);
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
	int count = 0, *arr, index;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (index = 0; index < count; index++)
	{
		arr[index] = temp % 16;
		temp /= 16;
	}

	for (index = count - 1; index >= 0; index--)
	{
		if (arr[index] > 9)
			arr[index] = arr[index] + 7;
		_putchar(arr[index] + '0');
	}

	free(arr);

	return (count);
}

/**
 * print_rev - Prints a string in reverse.
 *
 * @args: va_list with the string to print as the next element.
 *
 * Return: void.
 */
int print_rev(va_list args)
{
	char *str = va_arg(args, char *);
	int length = _strlen(str) - 1, count = 0;

	while (length >= 0)
	{
		_putchar(*(str + length));
		length--;
		count++;
	}

	return (count);
}
