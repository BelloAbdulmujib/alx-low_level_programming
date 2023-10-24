 #include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a linked list, even if it
 * has a loop
 *
 * @head: head of list to print
 *
 * Return: number of nodes printed
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head, *next = NULL;

	while (current != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *) current, current->n);
		next = current->next;
		if (next >= current)
		{
			printf("-> [%p] %d\n", (void *) next, next->n);
			break;
		}
		current = next;
	}
	return (count);
}

