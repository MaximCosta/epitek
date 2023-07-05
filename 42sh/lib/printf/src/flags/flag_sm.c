/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_sm.c
*/

#include "my_printf.h"

void flag_sm(printf_t *pr)
{
    char *s = va_arg(*pr->arg, char *);
    int len = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] < 32 || s[i] == 127) {
            len = len_unbr(s[i], "01234567") + 2;
            my_putstr("\\0");
            my_putunbr_base(s[i], "01234567");
            pr->c += len;
        } else {
            my_putchar(s[i]);
            pr->c++;
        }
    }
}
