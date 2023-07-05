/*
** EPITECH PROJECT, 2021
** Pool Day05
** File description:
** My_compute_power_rec
*/

#include "my_macro_abs.h"

int my_compute_power_rec(int nb, int p)
{
    int nbr;

    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    }
    nbr = my_compute_power_rec(nb, p - 1);
    if (ABS(nbr) > 2147483647 / ABS(nb)) {
        return (0);
    }
    return (nb * nbr);
}
