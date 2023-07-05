/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec
** File description:
** iterative fac
*/

int my_compute_factorial_rec(int nb)
{
    long int res = nb;

    if (nb < 0 || nb > 12)
        return 0;
    if (nb == 0)
        return 1;

    res *= my_compute_factorial_rec(nb - 1);
    if (res > 2147483647)
        return 0;
    return res;
}
