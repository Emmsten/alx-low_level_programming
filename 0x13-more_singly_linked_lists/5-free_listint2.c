#include <stdlib.h>
#include "lists.h"

/**
* free_listint2 - frees a linked list
* @head: pointer to the listint_t list to be freed
*/

void free_listint2(listint_t **head)
{
listint_t *current;
if (head == NULL)
return;
do {
current = *head;
if (current == NULL)
break;
*head = current->next;
free(current);
}
while (*head != NULL);}
*head = NULL;
}
