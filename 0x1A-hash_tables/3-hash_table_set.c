#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key. Cannot be an empty string
 * @value: The value associated with the key. Must be duplicated
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    index = key_index((unsigned char *)key, ht->size);

    new_node = set_pair(key, value);
    if (new_node == NULL)
        return (0);

    if (ht->array[index] != NULL)
        new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
