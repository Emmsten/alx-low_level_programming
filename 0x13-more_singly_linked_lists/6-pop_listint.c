#include "lists.h"

/**
* pop_listint - deletes the head node of a linked list
* @head: pointer to pointer to the head node
*
* Return: the data (n) of the head node that was deleted,
* or 0 if the list is empty
*/

int pop_listint(listint_t **head)
{
if (!head || !*head)
return (0);
count = (*head)->n;
listint_t *temp = (*head)->next;
free(*head);
*head = temp;
return (count);
}
