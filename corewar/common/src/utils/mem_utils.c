/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/

#include "../../include/common.h"

void *my_calloc(size_t size)
{
    void *ptr = malloc(size);

    for (size_t i = 0; i < size; i++)
        ((char *) ptr)[i] = 0;
    return ptr;
}
