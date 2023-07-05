/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_number.c
*/

#include "my_printf.h"

static int get_nbr(char const *s)
{
    int res = 0;

    while (*s >= '0' && *s <= '9') {
        res = res * 10 + *s - '0';
        s++;
    }
    return res;
}

void flag_number(printf_t *pr)
{
    int nbr = 0;
    int len = 0;

    if (!(pr->format[pr->n] >= '0' && pr->format[pr->n] <= '9'))
        return error(pr);
    nbr = get_nbr(pr->format + pr->n);
    pr->n += len_unbr(nbr, "0123456789");
    len = len_flags(pr);
    if (len == -1)
        return;
    for (int i = 0; i < nbr - len; i++) {
        my_putchar(' ');
        pr->c++;
    }
    pr->n--;
    do_flags(pr);
}
