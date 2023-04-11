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
if (filename == NULL)
{
return (-1);
}
mode_t file_permissions = S_IRUSR | S_IWUSR;
int flags = O_CREAT | O_WRONLY | O_TRUNC;
int fd = open(filename, flags, file_permissions);
if (fd == -1)
{
return (-1);
}
if (text_content != NULL)
{
size_t text_len = strlen(text_content);
ssize_t bytes_written = write(fd, text_content, text_len);
if (bytes_written != text_len)
{
close(fd);
return (-1);
}
}
close(fd);
return (1);
}
