/*
** EPITECH PROJECT, 2022
** antman [WSL: Ubuntu]
** File description:
** my_intdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

int *my_intdup(int const *src, int size)
{
    int *dest;

    dest = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
    return dest;
}
