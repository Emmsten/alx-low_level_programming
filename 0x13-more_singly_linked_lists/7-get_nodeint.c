#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* get_nodeint_at_index - Returns the nth node of a listint_t linked list
* @head: Pointer to the head node
* @index: Index of the node to return (starting at 0)
*
* Return: Pointer to the nth node, or NULL if the node does not exist.
*/
struct listint_s *get_nodeint_at_index(struct listint_s *head,
unsigned int index)
{
unsigned int i;
struct listint_s *current;
current = head;
for (i = 0; i < index && current != NULL; i++)
current = current->next;
return (current);
}
