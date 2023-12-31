#include <stdio.h>

/**
 * flip_bits - returns the number of bits
 * @n: first number
 * @m: second number
 *
 * Return: number of bits you would need to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int diff = n ^ m;

	while (diff > 0)
	{
		count += (diff & 1);
		diff >>= 1;
	}

	return (count);
}

