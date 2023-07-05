/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_hash.c
*/

#include "my_printf.h"

static int not_zero_next(printf_t *pr)
{
    va_list cp;

    va_copy(cp, *pr->arg);
    if (va_arg(cp, unsigned) == 0) {
        va_end(cp);
        return 0;
    }
    va_end(cp);
    return 1;
}

void flag_hash(printf_t *pr)
{
    if (not_zero_next(pr)) {
        switch (pr->format[pr->n + 1]) {
            case 'x':
                my_putstr("0x");
                pr->c += 2;
                break;
            case 'X':
                my_putstr("0X");
                pr->c += 2;
                break;
            case 'o':
                my_putstr("0x");
                pr->c++;
                break;
        }
    }
    do_flags(pr);
}
