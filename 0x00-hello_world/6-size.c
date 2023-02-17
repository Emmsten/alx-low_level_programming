#include <stdio.h>
/**
* A program that prints the size of various types on the computer it is supposed to run on	
* Return: 0 (success)
*/
int main(void)
{
 char a;
 int b;
 longint c;
 long ong int d;
 float f;
printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(a));
printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(b));
printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(c));
printf("Size of a long ong int: %lu byte(s)\n", (unsigned long)sizeof(d));
printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));
return (0);
}
