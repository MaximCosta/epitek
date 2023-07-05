/*
** EPITECH PROJECT, 2021
** Pool Day05
** File description:
** My_is_prime
*/

static int my_square_root(int nb)
{
    int num;

    if (nb < 0) {
        return (0);
    }
    for (int i = 0; i < 46341; i++) {
        num = i * i;
        if (nb == num) {
            return (i);
        } else if (nb < num) {
            return (i);
        }
    }
    return (0);
}

int my_is_prime(int nb)
{
    int prime = 1;

    if (nb == 2) {
        return (1);
    } else if (nb < 2 || nb % 2 == 0) {
        return (0);
    }
    for (int i = my_square_root(nb); i > 1; i--) {
        if (nb % i == 0) {
            prime = 0;
            break;
        }
    }
    return (prime == 1 ? 1 : 0);
}
