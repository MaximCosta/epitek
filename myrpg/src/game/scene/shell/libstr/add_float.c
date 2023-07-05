/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** add_float.c
*/

#include "../../../../../include/game/rpg.h"

void str_add_float(str_t *str, float nbr, int precision)
{
    str_add_nbr(str, (int)nbr);
    if (str->len + precision + (precision > 0) > str->size)
        str_resize(str, str->len + precision + (precision > 0));
    if (precision)
        str_add_char(str, '.');
    nbr = ABS(nbr);
    for (int i = 0; i < precision; i++) {
        nbr = nbr * 10 - (int) nbr * 10;
        str_add_nbr(str, (int) nbr);
    }
}