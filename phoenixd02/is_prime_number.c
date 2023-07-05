/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd02-maxim.costa [WSL: Ubuntu]
** File description:
** is_prime_number
*/

int is_prime_number(int nb)
{
    if (nb <= 1)
        return 0;
    if (nb % 2 == 0 && nb > 2)
        return 0;
    for (int i = 3; i < nb / 2; i += 2)
        if (nb % i == 0)
            return 0;
    return 1;
}