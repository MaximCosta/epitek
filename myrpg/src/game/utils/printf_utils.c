/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

#include "stdarg.h"

void my_putchar(char c);
void my_putstr(char const *str);

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

void print_arg_d(int number)
{
    if (number > 2147483647)
        return;
    my_putnbr(number);
}

void print_arg_s(char *str, char *str2, int i)
{
    if (str[i + 1] == 's')
        my_putstr(str2);
}

int my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == 'd')
            print_arg_d(va_arg(list, int));
        else if (str[i] == '%' && str[i + 1] == 's')
            print_arg_s(str, va_arg(list, char *), i);
        if (str[i] != '%' && str[i - 1] != '%')
            my_putchar(str[i]);
    }
    va_end(list);
    return (0);
}