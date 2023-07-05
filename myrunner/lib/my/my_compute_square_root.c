/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** square roor
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int res = 0;

    if (nb < 0)
        return 0;
    while (res < nb) {
        res = i * i;
        if (res == nb)
            return i;
        else if (i > 46340)
            return 0;
        else
            i++;
    }
    return 0;
}
