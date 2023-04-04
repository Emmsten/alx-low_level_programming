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
if (head == NULL || *head == NULL)
return (-1);
listint_t *prev_node = NULL;
listint_t *current_node = *head;
for (unsigned int i = 0; current_node && i < index; i++)
{
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
