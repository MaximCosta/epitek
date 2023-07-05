/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** push_chr.c
*/

#include "../../../../../include/game/rpg.h"

void str_push_char(str_t *str, char c)
{
    str_add_char_pos(str, c, 0);
}