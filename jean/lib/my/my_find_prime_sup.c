/*
** EPITECH PROJECT, 2021
** Pool Day05
** File description:
** My_find_prime_sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int c = nb;

    while (!my_is_prime(c) && c <= 2147483647) {
        c++;
    }
    return (c);
}
