#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to the head of the listint_t list.
 * @n: The integer to be included in the new node.
 *
 * Return: If successful - The address of the new element.
 *         If failed - NULL.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *last_node = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	while (last_node->next)
		last_node = last_node->next;

	last_node->next = new_node;

	return (new_node);
}

