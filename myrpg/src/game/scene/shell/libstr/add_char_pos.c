/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** add_char_pos.c
*/

#include "../../../../../include/game/rpg.h"

void str_add_char_pos(str_t *str, char c, int pos)
{
    if (pos > str->len)
        return;
    if (str->len == str->size)
        str_resize(str, str->size + 1);
    for (int i = str->len; i > pos; i--)
        str->str[i] = str->str[i - 1];
    str->str[pos] = c;
    str->len++;
}