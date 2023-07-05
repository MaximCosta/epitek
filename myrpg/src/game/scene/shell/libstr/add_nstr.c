/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** add_nstr.c
*/

#include "../../../../../include/game/rpg.h"

void str_add_nstr(str_t *str, str_t *add, size_t size)
{
    if (str->len + MIN(add->len, size) >= str->size)
        str_resize(str, str->size + MIN(add->len, size) + 1);
    for (int i = 0; i < MIN(add->len, size); i++)
        str->str[str->len + i] = add->str[i];
    str->len += MIN(add->len, size);
}

void str_add_ncstr(str_t *str, char const *cstr, size_t size)
{
    int len = my_strlen(cstr);

    if (str->len + MIN(size, len) >= str->size)
        str_resize(str, str->size + MIN(size, len) + 1);
    for (int i = 0; i < MIN(size, len); i++)
        str->str[str->len + i] = cstr[i];
    str->len += MIN(size, len);
}
