#include <stdlib.h>
#include "lists.h"

/**
* free_listint2 - Frees a listint_t linked list
* @head: A pointer to a pointer to the head node of the linked list
*/
void free_listint2(listint_t **head)
{
while (*head)
{
listint_t *temp = *head;
*head = (*head)->next;
free(temp);
}
}
