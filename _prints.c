#include "main.h"
#inlcude <stdarg.h>

/**
 * print_s - Prints a string.
 *
 * @args: String argument.
 *
 * Return: Number of characters.
 */
int print_s(va_list args)
{
        int index = 0, count = 0;
        char *str;

        str = va_arg(args, char*);

        if (str == NULL)
                str = "(null)";

        while (str[index] != '\0')
        {
                _putchar(str[index]);
                index++;
                count++;
        }

        return (count);
}

