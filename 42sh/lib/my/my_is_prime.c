/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** my is prime
*/

int my_is_prime(int n)
{
    int i = 3;

    if (n <= 1 || (n % 2 == 0 && n != 2))
        return 0;
    while (i < n / 2) {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}
