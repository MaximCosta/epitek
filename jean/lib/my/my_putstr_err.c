/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** my_putstr_err
*/

#include "my.h"

int my_putstr_err(char const *str, int err)
{
    while (*str != '\0') {
        my_putchar_err(*str++);
    }
    return (err);
}
