/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** create_from_str.c
*/

#include "../../../../../include/game/rpg.h"

str_t *str_create(char const *str)
{
    str_t *new_str = my_calloc(sizeof(str_t));

    if (!new_str)
        return (NULL);
    new_str->str = my_strdup((char *)str);
    if (!new_str->str) {
        free(new_str);
        return NULL;
    }
    new_str->len = my_strlen(str);
    new_str->size = new_str->len;
    return new_str;
}