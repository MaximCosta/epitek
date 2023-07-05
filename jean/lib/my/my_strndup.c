/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** my_strndup
*/

#include <stdlib.h>

char *my_strndup(char const *src, int b, int n)
{
    char *dest;
    char *begin;

    dest = malloc(sizeof(char) * (n + 1));
    begin = dest;
    for (int i = b; i > 0; i--)
        src++;
    while (n > 0 && *src) {
        *dest++ = *src++;
        n--;
    }
    *dest = '\0';
    return begin;
}
