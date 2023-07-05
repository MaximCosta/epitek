/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_c.c
*/

#include "my_printf.h"

void flag_c(printf_t *pr)
{
    my_putchar(va_arg(*pr->arg, int));
    pr->n++;
    pr->c++;
}
