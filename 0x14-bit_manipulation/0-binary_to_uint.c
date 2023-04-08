#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* Function to convert a binary string to an unsigned integer
* Returns: 0 if the string is invalid or NULL
* Initialize the result variable
*/
unsigned int binary_to_uint(const char *b)
{
if (b == NULL) return 0;
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
return 0;
}
}
return result;
}
