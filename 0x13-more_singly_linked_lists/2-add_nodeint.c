#include <stdlib.h>

/* Data type definition */
typedef void* listint_t;

/* add_nodeint - adds a new node at the beginning of a listint_t list
* @head: pointer to a pointer to the first element of the list
* @n: value to set for the new node
* Return: the address of the new element, or NULL if it failed
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node = malloc(sizeof(void*) * 2);
if (!new_node) {
return NULL;
}
int *n_ptr = new_node;
*n_ptr = n;
listint_t **next_ptr = new_node + 1;
*next_ptr = *head;
*head = new_node;
return new_node;
}
