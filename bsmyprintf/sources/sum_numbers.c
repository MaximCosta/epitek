/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-bsmyprintf-maxim.costa
** File description:
** sum_numbers
*/

#include <stdarg.h>
#include "bsprintf.h"

int sum_numbers(int n, ...)
{
    va_list va;
    int res = 0;

    va_start(va, n);
    for (int i = 0; i < n; i++)
        res += va_arg(va, int);
    va_end(va);
    return res;
}