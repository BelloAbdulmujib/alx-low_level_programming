#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name -  function that prints a name
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

