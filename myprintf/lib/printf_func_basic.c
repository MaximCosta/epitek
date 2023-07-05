/*
** EPITECH PROJECT, 2021
** my_printf [WSL: Ubuntu]
** File description:
** printf_func_basic
*/

#include "my_printf.h"

void string_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL) return;
    my_putstr(va_arg(ap, char *));
}

void string_sp_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL) return;
    my_showstr_octal(va_arg(ap, char *));
}

void char_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL) return;
    my_putchar(va_arg(ap, int));
}

void nbr_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL) return;
    long int val = 1;
    if (str_t->longs != 0)
        val = va_arg(ap, long int);
    else
        val = val * va_arg(ap, int);
    my_put_nbr(val);
}

void modulo_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL || ap == NULL) return;
    my_putchar('%');
}