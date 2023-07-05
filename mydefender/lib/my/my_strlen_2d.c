/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** my_strlen_2d
*/

#include <stdlib.h>

int my_strlen_2d(char **str)
{
    int i = 0;

    for (;str[i] != NULL ; i++);
    return i;
}
