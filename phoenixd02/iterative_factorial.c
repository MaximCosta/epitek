/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd02-maxim.costa [WSL: Ubuntu]
** File description:
** iterative_factorial
*/

int iterative_factorial(int nb)
{
    int res = 1;

    if (nb < 0 || 12 < nb)
        return 0;
    for (int i = 1; nb > 0; i++) {
        res *= i;
        if (res < 0)
            return 0;
        nb--;
    }
    return res;
}