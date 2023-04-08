#include <stdio.h>
#include "main.h"

/**
* print_binary - prints the binary equivalent of a decimal number
* @n: number to print in binary
*/

void print_binary(unsigned long int n)
{
int shift = sizeof(unsigned long int) * 8 - 1;
unsigned long int mask = 1UL << shift;
int printed = 0;
while (mask > 0)
{
if (n & mask)
{
putchar('1');
printed = 1;
}
else if (printed)
{
putchar('0');
}
mask >>= 1;
}
if (!printed)
{
putchar('0');
}
}
