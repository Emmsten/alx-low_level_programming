#include "lists.h"
/**
* sum_listint - Computes the sum of all the integers in a linked list.
*
* @head: A pointer to the head of the linked list.
*
* Return: The sum of all the integers in the linked list.
*         If the list is empty, returns 0.
*/
int sum_listint(listint_t *head)
{
int sum = 0;
while (head != NULL)
{
sum += head->n;
head = head->next;
}
return (sum);
}
