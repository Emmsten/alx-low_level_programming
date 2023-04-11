#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>
#include <string.h>
/**
* read_textfile- Read text file print to STDOUT.
* @filename:textfile being read
* @letters: number of letters to be read
* Return: w-actual number of bytes read and printed
* 0 when function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t bytes_read, bytes_written;
char *buffer;
if (!filename)
return (0);
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buffer = malloc(sizeof(char) * letters);
if (!buffer)
{
close(fd);
return (0);
}
bytes_read = read(fd, buffer, letters);
close(fd);
if (bytes_read == -1)
{
free(buffer);
return (0);
}
bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
free(buffer);
if (bytes_written == -1 || bytes_written != bytes_read)
return (0);
return (bytes_written);
}
