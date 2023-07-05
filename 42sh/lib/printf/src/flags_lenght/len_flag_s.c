/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_s.c
*/

#include "my_printf.h"

int len_flag_s(printf_t *pr)
{
    va_list cp;
    char *s = 0;
    int len = 0;

    va_copy(cp, *pr->arg);
    s = va_arg(cp, char *);
    len = my_strlen(s);
    va_end(cp);
    return len;
}
