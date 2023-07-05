/*
** EPITECH PROJECT, 2022
** dante [WSL: Ubuntu]
** File description:
** calloc
*/

#include "my.h"

void *my_calloc(int nb, int size)
{
    void *ptr = malloc(nb * size);
    for (int i = 0; i < nb * size; i++)
        ((char *) ptr)[i] = 0;
    return ptr;
}

void **my_calloc2d(int nb, int size)
{
    void **ptr = malloc(size * nb);
    for (int i = 0; i < nb; i++)
        ptr[i] = NULL;
    return ptr;
}