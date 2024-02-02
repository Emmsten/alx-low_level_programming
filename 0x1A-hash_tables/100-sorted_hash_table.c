#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table with a given size
 *
 * @size: size of the sorted hash table
 * Return: the created sorted hash table, or NULL if function fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *table;
    shash_node_t **array;
    unsigned long int i;

    table = malloc(sizeof(shash_table_t));
    if (table == NULL)
        return (NULL);

    array = malloc(sizeof(shash_node_t *) * size);
    if (array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        array[i] = NULL;

    table->array = array;
    table->size = size;
    table->shead = NULL;
    table->stail = NULL;

    return (table);
}

/**
 * add_spair - adds a node in the sorted doubly linked list
 *
 * @ht: pointer to the sorted hash table
 * @key: key of the node
 * @value: value to store
 * @index: index in the array of the sorted hash table
 * Return: no return
 */
void add_spair(shash_table_t *ht, const char *key, const char *value, unsigned long int index)
{
    shash_node_t *new, *tmp1, *tmp2;
    int ret;

    new = malloc(sizeof(shash_node_t));
    if (new == NULL)
        return;

    new->key = strdup(key);
    new->value = strdup(value);
    new->next = NULL;

    tmp1 = tmp2 = ht->shead;

    while (tmp1 != NULL)
    {
        ret = strcmp(new->key, tmp1->key);
        if (ret == 0)
        {
            free(new->value);
            new->value = strdup(value);
            free(new->key);
            free(new);
            return;
        }
        else if (ret < 0)
        {
            new->sprev = tmp1->sprev;

            if (tmp1->sprev)
                tmp1->sprev->snext = new;
            else
                ht->shead = new;

            tmp1->sprev = new;
            new->snext = tmp1;

            return;
        }
        tmp2 = tmp1;
        tmp1 = tmp1->snext;
    }

    new->sprev = tmp2;
    new->snext = NULL;

    if (ht->shead)
        tmp2->snext = new;
    else
        ht->shead = new;

    ht->stail = new;
}

/**
 * shash_table_set - adds a hash (key, value) to a given sorted hash table
 *
 * @ht: pointer to the sorted hash table
 * @key: key of the hash
 * @value: value to store
 * Return: 1 if success, 0 if fails
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;

    if (ht == NULL)
        return (0);

    if (key == NULL || *key == '\0')
        return (0);

    index = key_index((unsigned char *)key, ht->size);

    add_spair(ht, key, value, index);

    return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 *
 * @ht: pointer to the sorted hash table
 * @key: key of the hash
 * Return: value of the hash.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *tmp;

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
 * shash_table_print - prints the keys and values of the sorted hash table
 *
 * @ht: pointer to the sorted hash table
 * Return: no return
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *tmp;
    char *sep;

    if (ht == NULL)
        return;

    printf("{");
    sep = "";

    tmp = ht->shead;

    while (tmp != NULL)
    {
        printf("%s'%s': '%s'", sep, tmp->key, tmp->value);
        sep = ", ";
        tmp = tmp->snext;
    }

    printf("}\n");
}

/**
 * shash_table_print_rev - prints the keys and values of the sorted hash table
 * in reverse
 *
 * @ht: pointer to the sorted hash table
 * Return: no return
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *tmp;
    char *sep;

    if (ht == NULL)
        return;

    printf("{");
    sep = "";

    tmp = ht->stail;

    while (

