/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** my_calloc.c
*/

#include <stdlib.h>

void *my_calloc(size_t size)
{
    void *ptr = malloc(size);
    size_t i = 0;

    while (i < size && ptr)
        ((char *)ptr)[i++] = 0;
    return ptr;
}
