/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_zero.c
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

static int is_in(char c, char *s)
{
    while (*s) {
        if (c == *s)
            return 1;
        s++;
    }
    return 0;
}

void flag_zero(printf_t *pr)
{
    int nbr = 0;
    int len = 0;
    char c = 0;

    while (pr->format[pr->n] == '0')
        pr->n++;
    if (!(pr->format[pr->n] >= '0' && pr->format[pr->n] <= '9'))
        return error(pr);
    nbr = get_nbr(pr->format + pr->n);
    pr->n += len_unbr(nbr, "0123456789");
    c = is_in(pr->format[pr->n], "idouxXl") ? '0' : ' ';
    if (len == -1)
        return;
    for (int i = 0; i < nbr - len_flags(pr); i++) {
        my_putchar(c);
        pr->c++;
    }
    pr->n--;
    do_flags(pr);
}
