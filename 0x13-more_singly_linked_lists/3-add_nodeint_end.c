#include "lists.h"

/**
* add_nodeint_end - adds a new node at the end of a listint_t list
* @head: pointer to pointer to the head of the list
* @n: integer value to store in the new node
*
* Return: address of the new node, or NULL if it failed
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *current;
new_node = malloc(sizeof(*new_node));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = NULL;
if (*head == NULL)
*head = new_node;
else
{
for (current = *head; current->next != NULL; current = current->next)
;
current->next = new_node;
}
return (new_node);
}
