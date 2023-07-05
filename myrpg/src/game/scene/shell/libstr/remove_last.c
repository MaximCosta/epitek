/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** remove_last.c
*/

#include "../../../../../include/game/rpg.h"

char str_remove_last(str_t *str)
{
    char c = str->str[str->len - 1];

    str->str[--str->len] = '\0';
    return c;
}