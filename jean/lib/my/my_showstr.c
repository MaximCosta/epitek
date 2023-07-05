/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_showstr
*/

#include "my.h"

static void does_print_zero(char c)
{
    if (c < 16) {
        my_putchar('0');
    }
}

int my_showstr(char const *str)
{
    while (*str) {
        if (!is_printable(*str)) {
            my_putchar('\\');
            does_print_zero(*str);
            my_putnbr_base(*str, "0123456789abcdef");
        } else {
            my_putchar(*str);
        }
        str++;
    }
    return (0);
}
