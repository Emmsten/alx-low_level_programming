#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table with a given size
 *
 * @size: size of the hash table
 * Return: the created hash table, or NULL if function fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *table;
    hash_node_t **array;
    unsigned long int i;

    table = malloc(sizeof(hash_table_t));
    if (table == NULL)
        return (NULL);

    array = malloc(sizeof(hash_node_t *) * size);
    if (array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        array[i] = NULL;

    table->array = array;
    table->size = size;

    return (table);
}

/**
 * add_node_hash - adds a node at the beginning of a hash at a given index
 *
 * @head: head of the hash linked list
 * @key: key of the hash
 * @value: value to store
 * Return: created node
 */
hash_node_t *add_node_hash(hash_node_t **head, const char *key, const char *value)
{
    hash_node_t *new_node;

    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (NULL);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = *head;

    *head = new_node;

    return (new_node);
}

/**
 * hash_table_set - adds a hash (key, value) to a given hash table
 *
 * @ht: pointer to the hash table
 * @key: key of the hash
 * @value: value to store
 * Return: 1 if success, 0 if fails
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node;

    if (ht == NULL)
        return (0);

    if (key == NULL || *key == '\0')
        return (0);

    index = key_index((unsigned char *)key, ht->size);

    new_node = add_node_hash(&(ht->array[index]), key, value);

    if (new_node == NULL)
        return (0);

    return (1);
}

/**
 * hash_table_get - retrieves a value associated with a key
 *
 * @ht: pointer to the hash table
 * @key: key of the hash
 * Return: value of the hash.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *tmp;

    if (ht == NULL)
        return (NULL);

    if (key == NULL || *key == '\0')
        return (NULL);

    index = key_index((unsigned char *)key, ht->size);

    tmp = ht->array[index];

    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }

    return (NULL);
}

/**
 * hash_table_print - prints the keys and values of the hash table
 *
 * @ht: pointer to the hash table
 * Return: no return
 */
void hash_table_print(const hash_table_t *ht)
{
    hash_node_t *tmp;
    char *sep;

    if (ht == NULL)
        return;

    printf("{");
    sep = "";

    for (unsigned long int i = 0; i < ht->size; i++)
    {
        tmp = ht->array[i];
        while (tmp != NULL)
        {
            printf("%s'%s': '%s'", sep, tmp->key, tmp->value);
            sep = ", ";
            tmp = tmp->next;
        }
    }

    printf("}\n");
}

/**
 * hash_table_delete - deletes a hash table
 *
 * @ht: pointer to the hash table
 * Return: no return
 */
void hash_table_delete(hash_table_t *ht)
{
    hash_node_t *tmp1, *tmp2;

    if (ht == NULL)
        return;

    for (unsigned long int i = 0; i < ht->size; i++)
    {
        tmp1 = ht->array[i];
        while ((tmp2 = tmp1) != NULL)
        {
            tmp1 = tmp1->next;
            free(tmp2->key);
            free(tmp2->value);
            free(tmp2);
        }
    }

    free(ht->array);
    free(ht);
}
