#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

char *create_buffer(char *file);
voidclose_file(intfd);
/**
* create_buffer-Allocates 1024 bytes for a buffer.
* @file: The name of the file buffer is storing chars for.
7*
* Return: A pointer to the newly-allocated buffer.
*/

void print_error_exit(int code, const char *error_msg)
{
dprintf(STDERR_FILENO, "Error: %s\n", error_msg);
exit(code);
}
void copy_file(const char *file_from, const char *file_to)
{
int fd_from, fd_to;
ssize_t read_bytes, write_bytes;
char buffer[BUFFER_SIZE];
fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
{
print_error_exit(98, strerror(errno));
}
fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
| S_IWUSR | S_IRGRP | S_IROTH);
if (fd_to == -1)
{
print_error_exit(99, strerror(errno));
}
while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
write_bytes = write(fd_to, buffer, read_bytes);
if (write_bytes == -1 || write_bytes != read_bytes)
{
print_error_exit(99, strerror(errno));
}
}
if (read_bytes == -1)
{
print_error_exit(98, strerror(errno));
}
if (close(fd_from) == -1)
{
print_error_exit(100, strerror(errno));
}
if (close(fd_to) == -1)
{
print_error_exit(100, strerror(errno));
}
}
int main(int argc, char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
exit(97);

copy_file(argv[1], argv[2]);
return (0);
}
