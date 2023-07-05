/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** Return the smallest prime number
*/

int my_is_prime(int i);

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (my_is_prime(i) == 0)
        i++;
    return i;
}
