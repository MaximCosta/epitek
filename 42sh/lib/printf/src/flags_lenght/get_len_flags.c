/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** get_len_flags.c
*/

#include "my_printf.h"

static const len_flag_t flags[] = {
    {'c', &len_flag_c},
    {'i', &len_flag_i},
    {'d', &len_flag_i},
    {'o', &len_flag_o},
    {'u', &len_flag_u},
    {'x', &len_flag_x},
    {'X', &len_flag_xm},
    {'b', &len_flag_b},
    {'p', &len_flag_p},
    {'s', &len_flag_s},
    {'S', &len_flag_sm},
    {0, 0},
};

int len_flags(printf_t *pr)
{
    for (int i = 0; flags[i].c; i++)
        if (pr->format[pr->n] == flags[i].c)
            return flags[i].func(pr);
    return -1;
}
