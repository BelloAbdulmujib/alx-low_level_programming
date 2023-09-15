#include "main.h"
/**
 * print_most_numbers - function that prints the numbers, from 0 to 9
 * Description: prints the numbersexcluding 3 and 4
 * Return: the numbers since 0 up to 9
 */

void print_most_numbers(void)
{
	int x = 0;

	for (; x <= 9; x++)
	{
	if (x == 2 || x == 4)
	{
	continue;
	}
	else
	{
	_putchar(x + '0');
	}
	}
	_putchar('\n');
}
