/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it
** File description:
** iterative function that returns the factorial of  the number given
*/

int my_compute_factorial_it(int nb)
{
    long int res = nb;

    if (nb < 0)
        return 0;
    if (nb == 0)
        return 1;
    while (nb > 1) {
        res *= --nb;
        if (res > 2147483647)
            return 0;
    }
    return res;
}
