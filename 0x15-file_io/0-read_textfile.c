#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
* read_textfile- Read text file print to STDOUT.
* @filename:textfile being read
* @letters: number of letters to be read
* Return: w-actual number of bytes read and printed
* 0 when function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
if (filename == NULL)
{
return (0);
}
FILE *file = fopen(filename, "r");
if (file == NULL)
{
return (0);
}
char buffer[letters + 1];
ssize_t bytesRead = fread(buffer, 1, letters, file);
buffer[bytesRead] = '\0';
if (ferror(file))
{
fclose(file);
return (0);
}
fclose(file);
printf("%s", buffer);
return (bytesRead);
}
