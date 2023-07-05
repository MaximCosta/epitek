/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** add_str.c
*/

#include "../../../../../include/game/rpg.h"

void str_add_cstr(str_t *str, char const *cstr)
{
    int len = my_strlen(cstr);

    if (str->len + len >= str->size)
        str_resize(str, str->len + len + 1);
    for (int i = 0; i < len; i++)
        str->str[str->len + i] = cstr[i];
    str->len += len;
}

void str_add_str(str_t *str, str_t *add)
{
    if (str->len + add->len >= str->size)
        str_resize(str, str->size + add->len + 1);
    for (int i = 0; i < add->len; i++)
        str->str[str->len + i] = add->str[i];
    str->len += add->len;
}
