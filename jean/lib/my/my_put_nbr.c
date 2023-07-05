/*
** EPITECH PROJECT, 2021
** Pool Day03
** File description:
** my_put_nbr
*/

#include "my.h"

static void recursive(int nb)
{
    if (nb / 10) {
        recursive(nb / 10);
    }
    my_putchar(nb % 10 + 48);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb < -10) {
            my_put_nbr(- nb / 10);
            my_putchar('0' + (- (nb % 10)));
        } else
            my_put_nbr(-nb);
        return (0);
    }
    recursive(nb);
    return (0);
}
