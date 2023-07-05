/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** remove_pos.c
*/

#include "../../../../../include/game/rpg.h"

void str_remove_char_pos(str_t *str, int pos)
{
    if (pos < 0 || pos >= str->len)
        return;
    for (int i = pos; i < str->len; i++)
        str->str[i] = str->str[i + 1];
    str->str[--str->len] = '\0';
}