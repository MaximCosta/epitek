/*
** EPITECH PROJECT, 2021
** my_putnbr_base
** File description:
** hey. real programmers use vim
*/

#include "my_printf.h"

long long int my_putnbr_base(long long int nbr, char const *base)
{
    if (nbr < 0) {
        my_putnbr_base(nbr * -1, base);
    }
    else if (nbr > 0) {
        int si = my_strlen(base);
        my_putnbr_base(nbr / si, base);
        my_putchar(base[nbr % si]);
    }
    return 0;
}