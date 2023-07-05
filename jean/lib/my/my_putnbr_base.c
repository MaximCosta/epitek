/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_putnbr_base
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int size = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr / size != 0) {
        my_putnbr_base(nbr / my_strlen(base), base);
    }
    my_putchar(base[nbr % size]);
    return (nbr);
}
