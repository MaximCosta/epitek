/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd02-maxim.costa [WSL: Ubuntu]
** File description:
** recursive_power
*/

int recursive_power(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    return (nb * recursive_power(nb, p - 1));
}