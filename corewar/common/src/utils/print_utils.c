/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

#include "../../include/common.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
