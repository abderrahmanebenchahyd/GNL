
#include "get_next_line.h"


/* 
    (get_next_line)
    1_ read from a fd and add to a string
    2_ extract from the stach to line
    3_ clean up stach
*/

char *get_next_line(int fd)
{
    char *buffer;
    static char *buf;
    buffer = malloc(BUFFER_SIZE + 1);
    if(read(fd, &buffer,BUFFER_SIZE) == -1 || fd < 0 || BUFFER_SIZE <= 0)
        return(ft_free_buffer(&buf,buffer,1));
}
char *read_and_add(int fd,char *buffer,int readed)
{
    static char *finale_str;
    finale_str = malloc(BUFFER_SIZE + 1);
    if(!finale_str)
        return(NULL);
    readed = 0;
    while(ft_find_newline(buffer))
    {
        readed = read(fd,buffer,BUFFER_SIZE);
        if(readed == -1 || readed == 0)
            break ;
        buffer[readed] = '\0';
        finale_str = ft_strjoin(finale_str,buffer);
    }
        free(buffer);
}
int ft_find_newline(char *buffer)
{
    int i;

    i = 0;
    if(!buffer)
        return(-1);
    while(buffer[i])
    {
        if(buffer[i] == '\n')
            return(0);
        i++;
    }
    return(1);
}

void    *ft_free_buffer(char **buf, char *buffer, int flag)
{
    if (flag == 1)
        free(buffer);
    free(*buf);
    *buf = NULL;
    return(NULL);
}