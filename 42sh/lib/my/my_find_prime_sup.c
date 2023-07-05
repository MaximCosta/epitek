/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** my find prime sup
*/

int my_is_prime(int n);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb))
        return nb;
    return my_find_prime_sup(nb + 1);
}
