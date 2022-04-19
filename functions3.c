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
 * get_flag - Turns on flags if _printf finds a flag modifier.
 *
 * @s: Character that holds the flag specifier.
 * @f: Pointer to the struct flags in which we turn the flags on.
 *
 * Return: 1 if a flag has been turned on, 0 othewise.
 */
int get_flag(char s, flags_t *f)
{
	int index = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			index = 1;
			break;
		case ' ':
			f->space = 1;
			index = 1;
			break;
		case '#':
			f->hash = 1;
			index = 1;
			break;
	}

	return (index);
}
