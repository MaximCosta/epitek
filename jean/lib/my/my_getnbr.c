/*
** EPITECH PROJECT, 2021
** Pool Day04
** File description:
** my_getnbr
*/

#include "my.h"

static void recursive_getnbr(char const *str, int pos, int *result)
{
    int max = (pos > 0) ? 7 : 8;
    int n;

    if (is_digit(*str)) {
        n = *str - 48;
        if (!(*result == 214748364 && n > max) && !(*result > 214748364)) {
            *result = *result * 10 + n;
            recursive_getnbr(str + 1, pos, result);
        } else
            *result = 0;
    }
}

int my_getnbr(char const *str)
{
    int pos = 1;
    int result = 0;

    while (*str == '-' || *str == '+')
        if (*str++ == '-')
            pos = -pos;
    recursive_getnbr(str, pos, &result);
    return (pos * result);
}
