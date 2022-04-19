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
