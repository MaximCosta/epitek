/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_plus.c
*/

#include "my_printf.h"

static int is_in(char c, char *s)
{
    while (*s) {
        if (*s == c)
            return 1;
        s++;
    }
    return 0;
}

void flag_plus(printf_t *pr)
{
    va_list cp;

    va_copy(cp, *pr->arg);
    if (is_in(pr->format[pr->n + 1], "di") && va_arg(cp, int) >= 0) {
        my_putchar('+');
        pr->c++;
    }
    do_flags(pr);
    va_end(cp);
}
