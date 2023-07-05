/*
** EPITECH PROJECT, 2021
** my_calloc
** File description:
** xkcd.com/378
*/

#include <stdlib.h>

void **my_calloc_2d(int type, int size)
{
    void **ptr = malloc(type * size);

    if (!ptr) return NULL;
    for (int i = 0; i < size; i++)
        ptr[i] = NULL;
    return ptr;
}
