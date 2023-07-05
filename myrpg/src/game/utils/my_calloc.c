/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** my_calloc.c
*/

#include "../../../include/game/rpg.h"
#include "stdlib.h"
#include "string.h"

void *my_calloc(size_t size)
{
    void *ptr = malloc(size);

    if (!ptr)
        return (NULL);
    memset(ptr, 0, size);
    return ptr;
}
