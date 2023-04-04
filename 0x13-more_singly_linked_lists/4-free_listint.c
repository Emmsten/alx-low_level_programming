#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
* free_listint - Frees a listint_t list.
* @head: A pointer to the head of the list to be freed.
*/
void free_listint(struct listint_s *head)
{
struct listint_s *current_node;
while (head != NULL)
{
current_node = head;
head = head->next;
free(current_node);
}
}
