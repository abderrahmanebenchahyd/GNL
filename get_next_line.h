#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
char *get_next_line(int fd);
int ft_find_newline(char *buffer);
void *ft_free_buffer(char **buf, char *buffer);

#endif