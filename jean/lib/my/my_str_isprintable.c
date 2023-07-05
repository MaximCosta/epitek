/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_str_isprintable
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    while (*str != '\0') {
        if (!is_printable(*str))
            return (0);
        str++;
    }
    return (1);
}
