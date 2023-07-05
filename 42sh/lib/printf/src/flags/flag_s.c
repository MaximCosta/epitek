/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_s.c
*/

#include "my_printf.h"

void flag_s(printf_t *pr)
{
    char *s = va_arg(*pr->arg, char *);
    int len = my_strlen(s);

    my_putstr(s);
    pr->n++;
    pr->c += len;
}
