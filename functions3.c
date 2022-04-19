#include "main.h"
#include <stdlib.h>

/**
 * print_R - prints the rot13'ed string.
 *
 * @args: Arguments of strings to be encoded with rot13.
 *
 * Return: Nuumber of characters to be printed.
 */
int print_R(va_list args)
{
	char *str = va_arg(args, char *), *encoded = NULL;
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int index, count;

	encoded = malloc(sizeof(char) * (_strlen(str) + 1));

	if (!encoded || !str)
		return (-1);

	for (count = 0; str[count]; count++)
	{
		for (index = 0; index < 52; index++)
		{
			if (str[count] == alpha[index])
			{
				encoded[count] = rot13[index];

				break;
			}
		}

		if (str[count] != alpha[index])
			encoded[count] = str[count];
	}

	for (count = 0; encoded[count]; count++)
		_putchar(encoded[count]);

	free(encoded);

	return (count);
}

/**
 * print_S - prints exclusive string.
 *
 * @args: Arguments.
 *
 * Return: The length of the string.
 */
int print_S(va_list args)
{
	char *str;
	int index, len = 0, cast;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] < 32 || str[index] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len += 2;
			cast = str[index];

			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len += print_X(cast);
		}
		else
		{
			_putchar(str[index]);
			len++;
		}
	}

	return (len);
}
