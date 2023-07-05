/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_strdup
*/

#include "../../../include/game/rpg.h"
#include <stdlib.h>

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strdup(char *src)
{
    char *temp = malloc(sizeof(char) * (my_strlen(src) + 1));
    char *result = temp;

    while (*src)
        *temp++ = *src++;
    *temp = '\0';
    return result;
}
