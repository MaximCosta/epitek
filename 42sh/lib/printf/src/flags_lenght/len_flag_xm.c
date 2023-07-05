/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_xm.c
*/

#include "my_printf.h"

int len_flag_xm(printf_t *pr)
{
    va_list cp;
    unsigned int nbr = 0;
    int len = 0;

    va_copy(cp, *pr->arg);
    nbr = va_arg(cp, unsigned int);
    len = len_unbr(nbr, "0123456789abcdef");
    va_end(cp);
    return len;
}
