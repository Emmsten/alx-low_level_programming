#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete node at index of a `dlistint_t` LL
 * @head: double pointer to head of LL
 * @index: index position to remove from LL
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int count = 0;

	if (!head || !(*head))
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current)
	{
		if (count == index)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			free(current);
			return (1);
		}
		current = current->next;
		count++;
	}

	return (-1);
}
