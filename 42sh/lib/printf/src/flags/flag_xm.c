/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_xm.c
*/

#include "my_printf.h"

void flag_xm(printf_t *pr)
{
    unsigned int nbr = va_arg(*pr->arg, unsigned int);
    int len = len_unbr(nbr, "0123456789ABCDEF");

    my_putunbr_base(nbr, "0123456789ABCDEF");
    pr->n++;
    pr->c += len;
}
