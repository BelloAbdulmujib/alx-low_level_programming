#include <stdio.h>

/**
 * main - my entry
 *
 * Return: always 0
 */
int main(void)
{
	char i;

	for (i = 'a' ; i <= 'z' ; i++)
		if (i != 'q' && i != 'c')
			putchar(i);
	putchar('\n');
	return (0);
}
