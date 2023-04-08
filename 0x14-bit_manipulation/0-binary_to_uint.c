#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* Write a function that converts a binary number to an unsigned int.
* define unsigned int binary_to_uint(const char *b);
* where b is pointing to a string of 0 and 1 chars
* there is one or more chars in the string b that is not 0 or 1
* b is NULL
* Return: the converted number, or 0 if
*/
unsigned int binary_to_uint(const char *b)
{
if (b == NULL)
return (0);
unsigned int result = 0;
for (int i = 0; b[i] != '\0'; i++)
{
if (b[i] == '0')
{
result <<= 1;
}
else if (b[i] == '1')
{
result <<= 1;
result |= 1;
}
else
{
return (0);
}
}
return (result);
}
