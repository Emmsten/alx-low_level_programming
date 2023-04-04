#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* add_nodeint_end - Add a new node at the end of a listint_t list.
* @head: A pointer to a pointer to the head of the listint_t list.
* @n: The integer to store in the new node.
*
* Return: The address of the new element, or NULL if it failed.
*/
struct listint_s *add_nodeint_end(struct listint_s **head, const int n)
{
struct listint_s *new_node;
struct listint_s *current_node;
new_node = malloc(sizeof(struct listint_s));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = NULL;
if (*head == NULL) 
{
*head = new_node;
return (new_node);
}
current_node = *head;
while (current_node->next != NULL) 
{
current_node = current_node->next;
}
current_node->next = new_node;
return (new_node);
}
