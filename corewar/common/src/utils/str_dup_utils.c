/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/
#include "../../include/common.h"

char *my_strndup(char const *src, int n)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (n + 1));

    if (!dest)
        return 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (!dest)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}
