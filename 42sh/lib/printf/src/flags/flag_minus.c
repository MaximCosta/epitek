/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_minus.c
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

void flag_minus(printf_t *pr)
{
    int nbr = 0;
    int befor = pr->c;
    int after = 0;

    while (pr->format[pr->n] == '-') {
        pr->n++;
    }
    if (!(pr->format[pr->n] >= '0' && pr->format[pr->n] <= '9'))
        error(pr);
    nbr = get_nbr(pr->format + pr->n);
    pr->n += len_unbr(nbr, "0123456789") - 1;
    do_flags(pr);
    after = pr->c;
    for (int i = 0; i < nbr - (after - befor); i++) {
        my_putchar(' ');
        pr->c++;
    }
}
