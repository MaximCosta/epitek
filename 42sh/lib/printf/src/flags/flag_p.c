/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_p.c
*/

#include "my_printf.h"

void flag_p(printf_t *pr)
{
    unsigned long int n = va_arg(*pr->arg, unsigned long int);
    int len = 0;

    if (!n) {
        my_putstr("(nil)");
        len += 5;
    } else {
        my_putstr("0x");
        my_putunbr_base(n, "0123456789abcdef");
        len += len_unbr(n, "0123456789abcdef") + 2;
    }
    pr->c += len;
    pr->n++;
}
