/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** printf.c
*/

#include "my_printf.h"

static const flag_t flags[] = {
    {'c', &flag_c},
    {'i', &flag_i},
    {'d', &flag_i},
    {'o', &flag_o},
    {'u', &flag_u},
    {'x', &flag_x},
    {'X', &flag_xm},
    {'b', &flag_b},
    {'p', &flag_p},
    {'s', &flag_s},
    {'S', &flag_sm},
    {'+', &flag_plus},
    {'-', &flag_minus},
    {'#', &flag_hash},
    {'0', &flag_zero},
    {'%', &flag_purcent},
    {0, 0},
};

static printf_t *init_printf(char *format, va_list *arg)
{
    printf_t *pr = malloc(sizeof(printf_t));

    pr->format = format;
    pr->arg = arg;
    pr->c = 0;
    pr->n = 0;
    pr->len_f = my_strlen(format);
    return pr;
}

static int printf_end(printf_t *pr)
{
    int c = pr->c;

    free(pr);
    return c;
}

void do_flags(printf_t *pr)
{
    pr->n++;
    for (int i = 0; flags[i].c; i++)
        if (pr->format[pr->n] == flags[i].c)
            return flags[i].func(pr);
    if (pr->format[pr->n] >= '0' && pr->format[pr->n] <= '9')
        return flag_number(pr);
    error(pr);
}

int my_printf(char *format, ...)
{
    printf_t *pr = 0;
    va_list va;
    va_start(va, format);

    pr = init_printf(format, &va);
    while (pr->n < pr->len_f) {
        if (pr->format[pr->n] == '%') {
            do_flags(pr);
        } else {
            my_putchar(pr->format[pr->n]);
            pr->n++;
            pr->c++;
        }
    }
    return printf_end(pr);
}
