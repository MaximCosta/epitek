/*
** EPITECH PROJECT, 2021
** main
** File description:
** no, real programmers use cat
*/

#include "include/bistro.h"
#include "include/my.h"
#include <stdlib.h>

void get_sign(nb_info* nb, char **av)
{
    nb->val1 = av[1];
    nb->val2 = av[2];

    nb->sig1 = 1;
    if (nb->val1[0] == '-') {
        nb->sig1 = -1;
        nb->val1++;
    }
    nb->sig2 = 1;
    if (nb->val2[0] == '-') {
        nb->sig2 = -1;
        nb->val2++;
    }
}

void print_res(nb_info nb)
{
    int zero = 0;
    if (nb.sig1 == -1)
        my_putchar('-');
    for (int i = 0; nb.res[i]; i++) {
        if (zero == 0 && nb.res[i] == '0')
            continue;
        my_putchar(nb.res[i]);
        zero += 1;
    }
    if (zero == 0)
        my_putchar('0');
    my_putchar('\n');
}

int main(int ac, char **av)
{
    nb_info nb;

    get_sign(&nb, av);
    nb.len1 = my_strlen(nb.val1) - 1;
    nb.len2 = my_strlen(nb.val2) - 1;
    if (!(nb.len1 > nb.len2)) {
        if (nb.len1 < nb.len2 || my_strcmp(nb.val1, nb.val2) < 0) {
            my_strswap(&nb.val1, &nb.val2);
            my_swap(&nb.sig1, &nb.sig2);
            my_swap(&nb.len1, &nb.len2);
        }
    }
    nb.res = malloc(sizeof(char) * (my_max(nb.len1 + 1, nb.len2 + 1) + 2));
    for (int i = 0; i < my_max(nb.len1 + 1, nb.len2 + 1); i++)
        nb.res[i] = '0';
    if (nb.sig1 == nb.sig2)
        sum(nb);
    else
        neg(nb);
    print_res(nb);
}
