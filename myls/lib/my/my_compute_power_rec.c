/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** make rec
*/

int my_compute_power_rec(int nb, int power)
{
    if (power == 0)
        return 1;
    if (power < 0)
        return 0;
    return (nb * my_compute_power_rec(nb, power - 1));
}
