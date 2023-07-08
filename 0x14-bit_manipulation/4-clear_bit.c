#include "main.h"
#include <stddef.h>
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the unsigned long int number
 * @index: index of the bit to set to 0, starting from 0
 *
 * Return: 1 if the operation is successful, or -1 if an error occurs (e.g.,
 * the index is out of range)
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index >= 64)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}

