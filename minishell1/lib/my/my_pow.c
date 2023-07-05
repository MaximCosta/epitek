/*
** EPITECH PROJECT, 2021
** my_pow
** File description:
** make rec
*/

int my_pow(int nb, int power)
{
    if (power == 0)
        return 1;
    if (power < 0)
        return 0;
    return (nb * my_pow(nb, power - 1));
}
