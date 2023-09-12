#include "main.h"
#include <unistd.h>

/**
 * main - function to print task 1
 * print_alphabet - Entry point
 * Return:0
 */

void print_alphabet(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;

	}
	_putchar('\n');

}
