#include "lists.h"

/**
 * sum_dlistint - return the sum of all elements in a dlistint list
 * @head: pointer to head of dlistint list
 * Return: sum of all elements, or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *tmp = head;

	while (tmp)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}

	return (sum);
}
