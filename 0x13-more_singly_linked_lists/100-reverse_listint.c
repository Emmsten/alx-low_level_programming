#include "lists.h"
#include <stdio.h>
/**
* reverse_listint - Reverses a singly linked list.
* @head: A pointer to a pointer to the head of the list.
*
* Return: A pointer to the first node of the reversed list.
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL;
listint_t *current = *head;
while (current != NULL)
{
listint_t *next = current->next;
current->next = prev;
prev = current;
current = next;
}
*head = prev;
return (*head);
}
