/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** add_char.c
*/

#include "../../../../../include/game/rpg.h"

void str_add_char(str_t *str, char c)
{
    if (str->len == str->size)
        str_resize(str, str->size + 1);
    str->str[str->len] = c;
    str->len++;
}