#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that multiply two numbers
 * @argc: numbers of argument
 * @argv: argument vector
 * Return: 0 always
 */

int main(int argc, char *argv[1])
{
	int num1, num2, mul;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		num1 = atol(argv[1]);
		num2 = atol(argv[2]);
		mul = num1 * num2;
		printf("%d\n", mul);
	}
	return (0);
}
