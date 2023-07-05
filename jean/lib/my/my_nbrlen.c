/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** my_nbrlen
*/

static int recursive(int nb)
{
    return nb ? 1 + recursive(nb / 10) : 0;
}

int my_nbrlen(int nb)
{
    int len = recursive(nb);

    if (nb == 0)
        return 1;
    return (nb < 0) ? len + 1 : len;
}
