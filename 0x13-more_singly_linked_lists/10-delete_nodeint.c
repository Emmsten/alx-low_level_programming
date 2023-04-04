#include "lists.h"

/**
* delete_nodeint_at_index - Deletes the node at a given position
* in a linked list.
*
* @head: A pointer to the head of the linked list.
* @index: The index of the node to be deleted.
*
* Return: 1 if the deletion was successful, -1 otherwise.
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current_node, *prev_node;
unsigned int i;
if (head == NULL || *head == NULL)
return (-1);
current_node = *head;
prev_node = NULL;
for (i = 0; i < index; i++)
{
if (current_node == NULL)
return (-1);
prev_node = current_node;
current_node = current_node->next;
}
if (current_node == NULL)
return (-1);
if (prev_node == NULL)
*head = current_node->next;
else
prev_node->next = current_node->next;
free(current_node);
return (1);
}
