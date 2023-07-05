/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** my put nbr
*/

#include "my_printf.h"

int my_putnbr_base(long long int n, char const *base_tab, int minus)
{
    int base = my_strlen(base_tab);

    if (n < 0) {
        if (minus)
            my_putchar('-');
        if (n / base)
            my_putnbr_base(-(n / base), base_tab, minus);
        my_putchar(base_tab[-(n % base)]);
        return 0;
    }
    if (n / base)
        my_putnbr_base(n / base, base_tab, minus);
    my_putchar(base_tab[n % base]);
    return 0;
}

int my_putunbr_base(unsigned long long int n, char const *base_tab)
{
    int base = my_strlen(base_tab);

    if (n / base)
        my_putunbr_base(n / base, base_tab);
    my_putchar(base_tab[n % base]);
    return 0;
}

int len_nbr(long long int n, int minus)
{
    int c = 0;

    minus = n >= 0 ? 0 : minus;
    while (n) {
        n /= 10;
        c++;
    }
    return c ? c + minus : 1 + minus;
}

int len_unbr(unsigned long long int n, char *base)
{
    int b = my_strlen(base);
    int c = 0;

    while (n) {
        n /= b;
        c++;
    }
    return c ? c : 1;
}
