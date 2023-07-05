/*
** EPITECH PROJECT, 2021
** Pool Day05
** File description:
** My_compute_square_root
*/

int my_compute_square_root(int nb)
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
            return (0);
        }
    }
    return (0);
}
