/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** resize.c
*/

#include "../../../../../include/game/rpg.h"

void str_resize(str_t *str, int size)
{
    char *new_str = my_calloc(sizeof(char) * (size));

    if (!new_str)
        return;
    for (int i = 0; i < str->len && i < size; i++)
        new_str[i] = str->str[i];
    free(str->str);
    str->str = new_str;
    str->size = size;
}