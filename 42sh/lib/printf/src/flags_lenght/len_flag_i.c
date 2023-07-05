/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_i.c
*/

#include "my_printf.h"

int len_flag_i(printf_t *pr)
{
    va_list cp;
    int nbr = 0;
    int len = 0;

    va_copy(cp, *pr->arg);
    nbr = va_arg(cp, int);
    len = len_nbr(nbr, 1);
    va_end(cp);
    return len;
}
