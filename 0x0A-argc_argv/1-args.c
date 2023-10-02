#include <stdio.h>

/**
 * main - program that prints a number
 * @argc: argument num
 * @argv: argument vector
 * Return: 0 always
 */

int main(int argc, char *argv[])
{
	(void) argv;

	printf("%d\n", argc - 1);
	return (0);
}
