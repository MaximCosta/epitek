/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** clear.c
*/

#include "../../../../../include/game/rpg.h"

void str_clear(str_t *str)
{
    for (int i = 0; i < str->len; i++)
        str->str[i] = '\0';
    str->len = 0;
}