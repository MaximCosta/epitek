/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Write a function for print the number given as a parameter.
*/

#include "my_printf.h"

long long int my_put_nbr_pf(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        my_put_nbr_pf(nb / 10);
        my_putchar(nb % 10 + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
