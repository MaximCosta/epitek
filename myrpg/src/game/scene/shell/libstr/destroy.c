/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** destroy.c
*/

#include "../../../../../include/game/rpg.h"

void str_destroy(str_t *str)
{
    free(str->str);
    free(str);
}
