/*
** EPITECH PROJECT, 2021
** Pool Day08
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;
    char *begin;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    begin = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return begin;
}
