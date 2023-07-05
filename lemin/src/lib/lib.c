/*
** EPITECH PROJECT, 2022
** lemin [WSL: Ubuntu]
** File description:
** lib
*/

#include "my.h"

int my_atoi(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        if ('0' <= str[i] && str[i] <= '9')
            nb = nb * 10 + (str[i] - '0');
        else
            return (0);
    }
    return (nb);
}

void *my_calloc(int nb, int size)
{
    void *ptr = malloc(nb * size);

    if (ptr == NULL)
        return (NULL);
    for (int i = 0; i < nb * size; i++)
        ((char *)ptr)[i] = 0;
    return (ptr);
}

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] && s2[i]; i++)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    return (0);
}

int square(int nb)
{
    return (nb * nb);
}

char *my_strdup(char *str)
{
    char *new = my_calloc(2 ,my_strlen(str));

    for (int i = 0; str[i]; i++)
        new[i] = str[i];
    return (new);
}
