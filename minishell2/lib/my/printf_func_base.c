/*
** EPITECH PROJECT, 2021
** my_printf [WSL: Ubuntu]
** File description:
** printf_func_base
*/

#include "my_printf.h"

void nbr_base16x_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL)
        return;
    if (str_t->hash != 0)
        my_putstr("0x");
    my_putnbr_base_pf(va_arg(ap, unsigned long long int), "0123456789abcdef");
}

void nbr_base16x_point(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL)
        return;
    my_putstr("0x");
    my_putnbr_base_pf(va_arg(ap, unsigned long long int), "0123456789abcdef");
}

void nbr_bas16mx_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL)
        return;
    if (str_t->hash != 0)
        my_putstr("0X");
    my_putnbr_base_pf(va_arg(ap, unsigned long long int), "0123456789ABCDEF");
}

void nbr_base8_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL)
        return;
    if (str_t->hash != 0)
        my_putstr("0");
    my_putnbr_base_pf(va_arg(ap, unsigned long long int), "01234567");
}

void nbr_base2_print(char *arg, va_list ap, int index, str_struct_t *str_t)
{
    if (arg == NULL || index == -1 || str_t == NULL)
        return;
    my_putnbr_base_pf(va_arg(ap, long long int), "01");
}
