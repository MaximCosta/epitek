/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

#include "unistd.h"
#include "stdlib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}