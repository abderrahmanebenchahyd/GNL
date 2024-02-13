
#include "get_next_line.h"


/* 
    (get_next_line)
    1_ read from a fd and add to a string
    2_ extract from the stach to line
    3_ clean up stach
*/

char *get_next_line(int fd)
{
    char *holder;
    static char *buffer;
    int readed;
    char finale_str;
    buffer = malloc(BUFFER_SIZE + 1);
    if(read(fd, &buffer,BUFFER_SIZE) == -1 || fd < 0 || BUFFER_SIZE <= 0)
        return(ft_free_buffer(&holder,buffer,1));
    readed = 0;
    while(*buffer)
    {
        readed = read(fd,buffer,BUFFER_SIZE);
        if(readed == -1 || readed == 0)
            break ;
        buffer[readed] = '\0';
        holder = ft_strjoin(holder,buffer);
        if (ft_strchr(buffer,'\n') != -1)
            break;
    }
    free(buffer);
}
char *ft_fin_str(char *buffer,int readed)
{

}
char *ft_holder(char *buffer, int readed)
{
    char *str;
    int i;
    i = 0;
    str = malloc(readed + 1);
    while(i < readed)
    {
        str[i] = buffer[i];
        i++;
    }
}
int ft_strchr(char *buffer, char c)
{
    int i;

    i = 0;
    if(!buffer)
        return(-2);
    while(buffer[i])
    {
        if(buffer[i] == c)
            return(i);
        i++;
    }
    return(-1);
}

void    *ft_free_buffer(char **buf, char *buffer, int flag)
{
    if (flag == 1)
        free(buffer);
    free(*buf);
    *buf = NULL;
    return(NULL);
}