/*
** EPITECH PROJECT, 2021
** Pool Day02
** File description:
** My_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str++);
    }
    return (0);
}
