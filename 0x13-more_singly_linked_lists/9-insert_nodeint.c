#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the head of the listint_t list.
 * @idx: The index of the list where the new node should be added.
 * @n: The integer to be included in the new node.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *tmp = *head;
	unsigned int i;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	if (!idx)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; tmp && i < idx - 1; i++)
		tmp = tmp->next;

	if (!tmp)
		return (NULL);

	new->next = tmp->next;
	tmp->next = new;

	return (new);
}

