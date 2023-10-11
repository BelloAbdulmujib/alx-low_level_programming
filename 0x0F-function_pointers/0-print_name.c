#include "function_pointers.h"

/**
 * print_name - function to print name
 * @name: name to be printed
 * @f: pointer to function
 * Return: nothing
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name)
		return;

	f(name);
}

