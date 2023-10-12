#include <stdio.h>

/**
 * main - a program that prints its own opcodes
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 when successful
 */

int main(int argc, char *argv[])
{
	int bytes, j;
	char *arr;

	if (argc != 2)
	{
		_putchar("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		_putchar("Error\n");
		exit(2);
	}

	arr = (char *)main;

	for (j = 0; j < bytes; j++)
	{
		if (j == bytes - 1)
		{
			_putchar("%02hhx\n", arr[j]);
			break;
		}
		_putchar("%02hhx ", arr[j]);
	}
	return (0);
}

