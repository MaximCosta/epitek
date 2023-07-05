/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** Firt malloc
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; i < my_strlen(src); i++) {
        dest[i] = src[i];
    }
    dest[++i] = '\0';
    return dest;
}
