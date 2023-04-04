#include "lists.h"

/**
* add_nodeint - adds a new node at the beginning of a listint_t list
* @head: pointer to pointer to the head of the list
* @n: integer value to store in the new node
*
* Return: address of the new node, or NULL if it failed
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
if (!head)
return (NULL);
listint_t *new_node = malloc(sizeof(*new_node));
if (!new_node)
return (NULL);
*new_node = (listint_t){.n = n, .next = *head};
*head = new_node;
return (new_node);
}
