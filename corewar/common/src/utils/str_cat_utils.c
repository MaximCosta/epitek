/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/
#include "../../include/common.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = 0;
    return dest;
}

char *my_strcat_malloc(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    if (!dest)
        return (char *) src;
    while (dest[i]) {
        str[i] = dest[i];
        i++;
    }
    while (src[j]) {
        str[i] = src[j];
        i++;
        j++;
    }
    str[i] = 0;
    return str;
}

char *my_strcat_char_malloc(char **dest, char src)
{
    int dest_len = 0;

    if (!dest) {
        dest = malloc(sizeof(char) * 2);
        *dest[0] = src;
        *dest[1] = 0;
    }
    dest_len = my_strlen(*dest);
    *dest = (char *) realloc(*dest, sizeof(char) * (dest_len + 2));
    (*dest)[dest_len] = src;
    (*dest)[dest_len + 1] = 0;
}
