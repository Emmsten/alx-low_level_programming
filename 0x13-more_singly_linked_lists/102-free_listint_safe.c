#include <stdlib.h>
#include "lists.h"

/**
* free_listint_safe - Frees a linked list safely
* @head: Double pointer to the head of the list
*
* Return: The size of the list that was freed
*/
size_t free_listint_safe(listint_t **head)
{
size_t count = 0;
listint_t *current, *next;
if (head == NULL || *head == NULL)
return (0);
current = *head;
*head = NULL;
while (current)
{
count++;
next = current->next;
free(current);
if (next >= current)
break;
current = next;
}
return (count);
}
