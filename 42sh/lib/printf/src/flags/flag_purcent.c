/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_purcent.c
*/

#include "my_printf.h"

void flag_purcent(printf_t *pr)
{
    my_putchar('%');
    pr->n++;
    pr->c++;
}
