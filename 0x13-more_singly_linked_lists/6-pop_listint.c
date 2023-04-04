#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* pop_listint - Deletes the head node of a listint_t linked list
* @head: Pointer to a pointer to the head node
*
* Return: The data (n) of the head node that was deleted, or 0 if the linked
*         list is empty.
*/
int pop_listint(struct listint_s **head)
{
struct listint_s *current;
int data;
if (*head == NULL)
return (0);
current = *head;
*head = current->next;
data = current->n;
free(current);
return (data);
}
