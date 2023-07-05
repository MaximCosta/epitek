/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_b.c
*/

#include "my_printf.h"

void flag_b(printf_t *pr)
{
    unsigned int nbr = va_arg(*pr->arg, unsigned int);
    int len = len_unbr(nbr, "01");

    my_putunbr_base(nbr, "01");
    pr->n++;
    pr->c += len;
}
