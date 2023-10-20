#include <stddef.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;
	const list_t *current = h;

	while (current != NULL)
	{
	if (current->str == NULL)
	{
		_putchar('[');
		_putchar('0');
		_putchar(']');
		_putchar(' ');
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		_putchar('\n');
	}
	else
		{
		size_t len = current->len;
		unsigned int i;
		char *str = current->str;

		_putchar('[');

	for (i = 0; i <= len; i++)
	{
		_putchar(str[i]);
		_putchar(']');
		_putchar(' ');
	}
	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
		_putchar('\n');
	}
		}

		count++;
		current = current->next;
	}

	return (count);
}

