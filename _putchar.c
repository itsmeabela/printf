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
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
