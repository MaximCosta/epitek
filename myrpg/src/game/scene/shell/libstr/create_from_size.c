/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** create_from_size.c
*/

#include "../../../../../include/game/rpg.h"

str_t *str_create_size(int size)
{
    str_t *new_str = my_calloc(sizeof(str_t));

    size = size > 0 ? size : 1;
    if (!new_str)
        return (NULL);
    new_str->str = my_calloc(sizeof(char) * size);
    if (!new_str->str && size != 0) {
        free(new_str);
        return NULL;
    }
    new_str->len = 0;
    new_str->size = size;
    return new_str;
}
