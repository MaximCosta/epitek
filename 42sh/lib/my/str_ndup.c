/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-evalexpr-flavio.moreno
** File description:
** str_ndup.c
*/

#include <stdlib.h>
char *my_strncpy(char *dest, char const *src, int n);

char *str_ndup(char const *str, int n)
{
    int len = n;
    char *dest = malloc(sizeof(char) * (len + 1));

    my_strncpy(dest, str, n);
    dest[len] = 0;
    return dest;
}
