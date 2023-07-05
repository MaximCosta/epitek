/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-bsmyprintf-maxim.costa
** File description:
** disp_stdarg
*/

#include <stdarg.h>
#include <stdio.h>
#include "bsprintf.h"

void switch_arg(char s, int i, va_list va)
{
    switch (s[i]) {
        case 'c':
            my_putchar(va_arg(va, int));
            break;
        case 's':
            my_putstr(va_arg(va, char *));
            break;
        case 'i':
            my_put_nbr(va_arg(va, int));
            break;
    }
}

void disp_stdarg(char *s, ...)
{
    va_list va;

    va_start(va, s);
    for (int i = 0; s[i]; i++) {
        switch_arg(s, i, va);
        my_putchar('\n');
    }
    va_end(va);
}
