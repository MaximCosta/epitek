/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_showmem
*/

#include "my.h"

static void put_spaces(int cpt)
{
    int step = 30 - cpt;

    step = step + (16 - cpt) / 2;
    for (int i = cpt; i < step; i++) {
        my_putchar(' ');
    }
}

static void putnbr_with_length(int nbr, int len)
{
    if (nbr == 0) {
        for (int i = 0; i < len; i++) {
            my_putchar('0');
        }
        return;
    }
    int max = my_compute_power_rec(16, len - 1);

    while (nbr < max) {
        max = max / 16;
        my_putchar('0');
    }
    my_putnbr_base(nbr, "0123456789abcdef");
}

static void hexadecimal_char(char const *str, int size)
{
    int cpt = 0;

    while (size > 0 && cpt < 16) {
        putnbr_with_length(*str, 2);
        if (cpt % 2 == 1)
            my_putchar(' ');
        str++;
        cpt++;
        size--;
    }
    if (cpt > 0) {
        put_spaces(cpt - 1);
    }
}

static void show_string(char const *str, int *size)
{
    int cpt = 0;

    while (*size > 0 && cpt < 16) {
        if (is_printable(*str)) {
            my_putchar(*str);
        } else {
            my_putchar('.');
        }
        (*size)--;
        str++;
        cpt++;
    }
    my_putchar('\n');
}

int my_showmem(char const *str, int size)
{
    int cpt = 0;

    while (size > 0) {
        putnbr_with_length(cpt, 8);
        my_putchar(':');
        my_putchar(' ');
        hexadecimal_char(str, size);
        show_string(str, &size);
        while (cpt % 16 < 15) {
            cpt++;
            str++;
        }
        cpt++;
        str++;
    }
    return (0);
}
