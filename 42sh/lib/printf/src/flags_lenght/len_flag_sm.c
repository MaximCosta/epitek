/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** flag_sm.c
*/

#include "my_printf.h"

int len_flag_sm(printf_t *pr)
{
    va_list cp;
    char *s = 0;
    int len = 0;

    va_copy(cp, *pr->arg);
    s = va_arg(cp, char *);
    for (int i = 0; s[i]; i++) {
        if (s[i] < 32 || s[i] == 127)
            len += len_unbr(s[i], "01234567") + 2;
        else
            len++;
    }
    va_end(cp);
    return len;
}
