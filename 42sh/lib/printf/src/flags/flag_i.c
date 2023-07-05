/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_i.c
*/

#include "my_printf.h"

void flag_i(printf_t *pr)
{
    int nbr = va_arg(*pr->arg, int);
    int len = len_nbr(nbr, 1);

    my_putnbr_base(nbr, "0123456789", 1);
    pr->n++;
    pr->c += len;
}
