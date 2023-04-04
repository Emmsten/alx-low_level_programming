#include "lists.h"

/**
* get_nodeint_at_index - Returns the nth node of a listint_t linked list.
* @head: Pointer to the head of the linked list.
* @index: Index of the node to be returned, starting at 0.
*
* Return: Pointer to the nth node of the linked list, 
* or NULL if the node does not exist.
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
for (unsigned int i = 0; head != NULL && i < index; i++, head = head->next);
return (head);
}
