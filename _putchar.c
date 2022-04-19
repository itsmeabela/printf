#include "main.h"
#include <unistd.h>

/**
 * _putchar - Write a character.
 *
 * @c: The character to be printed.
 *
 * Return: 1(Success) -1(Fail)
 */
int _putchar(char c)
{
	static char buf[1024];
	static int index;

	if (c == -1 || index >= 1024)
	{
		write(1, &buf, index);
		index = 0;
	}

	if (c != -1)
	{
		buf[index] = c;
		index++;
	}

	return (1);
}

/**
 * _puts - Prints a string to stdout.
 *
 * @str: Pointer to the string to print.
 *
 * Return: Number of chars written.
 */
int _puts(char *str)
{
	register int index;

	for (index = 0; str[index] != '\0'; index++)
		_putchar(str[index]);

	return (index);

}
