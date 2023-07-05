/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** error.c
*/

#include "my_printf.h"

void error(printf_t *pr)
{
    while (pr->format[pr->n] != '%')
        pr->n--;
    flag_purcent(pr);
}
