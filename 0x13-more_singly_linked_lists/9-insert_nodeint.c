#include <stdio.h>
#include "lists.h"

/**
* insert_nodeint_at_index - Inserts a new node at a given position
* in a linked list.
*
* @head: A pointer to the head of the linked list.
* @idx: The index where the new node should be inserted.
* @n: The value to be stored in the new node.
*
* Return: A pointer to the new node, or NULL if it failed.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *current_node;
unsigned int i;
if (head == NULL)
return (NULL);
if (idx == 0)
return (add_nodeint(head, n));
current_node = *head;
for (i = 0; i < idx - 1; i++)
if (current_node == NULL || current_node->next == NULL)
return (NULL);
current_node = current_node->next;
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = current_node->next;
current_node->next = new_node;
return (new_node);
}

