/*
** EPITECH PROJECT, 2021
** Pool Day05
** File description:
** My_compute_power_it
*/

#include "my_macro_abs.h"

int my_compute_power_it(int nb, int p)
{
    int result = nb;
    int error = 0;

    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    }
    for (int i = 1; i < p; i++) {
        if (ABS(result) > 2147483647 / ABS(nb)) {
            error = 1;
            break;
        }
        result *= nb;
    }
    return (error == 0 ? result : 0);
}
