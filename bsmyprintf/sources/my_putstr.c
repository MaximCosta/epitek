/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** write one by one char of string
*/

#include "bsprintf.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
