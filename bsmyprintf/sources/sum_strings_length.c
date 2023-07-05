/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-bsmyprintf-maxim.costa
** File description:
** sum_strings_length
*/

#include <stdarg.h>
#include "bsprintf.h"

static int my_strlen(char *str)
{
    return *str ? 1 + my_strlen(str + 1) : 0;
}

int sum_strings_length(int n, ...)
{
    va_list va;
    int res = 0;

    va_start(va, n);
    for (int i = 0; i < n; i++)
        res += my_strlen(va_arg(va, char *));
    va_end(va);
    return res;
}