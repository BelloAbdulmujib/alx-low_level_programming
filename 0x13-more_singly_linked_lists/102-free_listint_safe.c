#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The size of the list that was free’d.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (count);

	current = *h;
	while (current != NULL)
	{
		count++;
		next = current->next;
		free(current);
		current = next;
		if (next >= current)
			break;
	}
	*h = NULL;

	return (count);
}

