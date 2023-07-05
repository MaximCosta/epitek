/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/

#include "../../include/common.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i]  && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return dest;
}

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i])
        i++;
    return i;
}
