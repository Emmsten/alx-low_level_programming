#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

/**
* create_file-Createsafile.
* @filename: A pointer to the name of the file to create.
* @text_content: A pointer to a string to write to the file.
*
* Return: If the function fails--1.
* Otherwise-1.
*/
int create_file(const char *filename, char *text_content)
{
int fd;
int len = 0;
int w;
if (filename == 0)
{
return (-1);
}
if (text_content != 0)
{
while (text_content[len])
{
len++;
}
}
fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
if (fd == -1)
{
return (-1);
}
w = write(fd, text_content, len);
if (w == -1)
{
close(fd);
return (-1);
}
close(fd);
return (1);
}
