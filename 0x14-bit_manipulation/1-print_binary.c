#include"main.h"
#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed.
 */

void print_binary(unsigned long int n)
{
	int shift, flag = 0;
	unsigned long int mask = 1UL << (sizeof(n) * 8 - 1);

	if (n == 0)
	{
		putchar('0');
		return;
	}

	for (shift = 0; shift < (sizeof(n) * 8); shift++)
	{
	if ((n & mask) >> (sizeof(n) * 8 - 1))
	{
		flag = 1;
	}

	if (flag)
	{
		putchar('0' + ((n & mask) >> (sizeof(n) * 8 - 1)));
	}

	n <<= 1;
	}
}

