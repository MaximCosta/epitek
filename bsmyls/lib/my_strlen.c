/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** get len of array
*/

#include "my_printf.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        ++i;
    return i;
}
