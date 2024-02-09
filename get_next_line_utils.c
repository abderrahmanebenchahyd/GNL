#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i])
        i++;
    return(i);
}
char *ft_strjoin(char *str1, char *str2)
{
    int i;
    int j;
    char *finale_str;
    if(!str1 || !str2)
        return(NULL);
    finale_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
    if(!finale_str)
        return(NULL);
    i = 0;
    while(str1[i])
        finale_str[i++] = str2[i++];
    j = 0;
    while(str2[j])
        finale_str[i++] = str2[j++];
    finale_str[i] = '\0';
    free(str1);
    return(finale_str);
}