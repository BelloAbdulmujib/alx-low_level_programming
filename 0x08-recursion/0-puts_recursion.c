#include "main.h"

/**
 * _puts_recursion - function that prints a string
 * @s: address to be printed
 * Return: always 0
 */

void _puts_recursion(char *s)
{
	int s = 0;

	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}

	else
		_putchar('\n');
}
