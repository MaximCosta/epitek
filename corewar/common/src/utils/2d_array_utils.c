/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

#include "../../include/common.h"

void free_2d_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

int count_2d_array_size(char **array)
{
    int size = 0;

    for (int i = 0; array[i]; i++)
        size++;
    return size;
}
