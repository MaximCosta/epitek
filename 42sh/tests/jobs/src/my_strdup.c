/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_strdup
*/

#include "../include/jobs.h"
#include <stdlib.h>

char *istrdup(char *src)
{
    char *result = malloc(sizeof(char) * (strlen(src) + 1));

    result[strlen(src)] = '\0';
    for (int i = 0; src[i]; i++)
        result[i] = src[i];
    return result;
}
